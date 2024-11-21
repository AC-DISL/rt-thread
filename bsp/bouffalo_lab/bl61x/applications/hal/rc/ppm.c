/******************************************************************************
 * Copyright 2022 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include <string.h>

#include "hal/rc/ppm.h"

/* 16-bit timer */
#define GET_GAP(x, y) (x > y ? (x - y) : (0xFFFF - y + x))
#define RC_CHANNELS_NUM 8
#define MV_COUNT 25
int raw_rc_value[RC_CHANNELS_NUM][MV_COUNT] = {0};

int Mv_Ag(int channel, int count, int data)
{
    int rc_value = data;
    for (int m = count - 1; m > 0; m--)
    {
        raw_rc_value[channel][count - m - 1] = raw_rc_value[channel][count - m];
    }
    raw_rc_value[channel][count - 1] = rc_value;

    rc_value = 0;
    int MovCount = 0;
    for (int n = 0; n < count; n++)
    {
        if (raw_rc_value[channel][n] != 0)
        {
            MovCount++;
            rc_value += raw_rc_value[channel][n];
        }
    }
    rc_value = rc_value / MovCount;

    return rc_value; // 返回滑动平均值
}

/**
 * @brief update ppm decoder status
 * 
 * @param decoder ppm decoder
 * @param ic_val input capture value
 */
void ppm_update(ppm_decoder_t* decoder, uint32_t ic_val)
{
    static uint16_t temp_val[MAX_PPM_CHANNEL];
    uint16_t gap;

    gap = GET_GAP(ic_val, decoder->last_ic);

    if (gap > decoder->freq_hz / 1000 * 0.9f && gap < decoder->freq_hz / 1000 * 2.1f) {
        /* valid ppm signal should between 1ms to 2ms */
        if (decoder->chan_id < MAX_PPM_CHANNEL) {
            temp_val[decoder->chan_id] = gap;
            decoder->chan_id++;
        }
    } else {
        /* sync signal */
        if (decoder->chan_id >= 1 && decoder->chan_id <= MAX_PPM_CHANNEL) {
            /* get total channel count */
            decoder->total_chan = decoder->chan_id;
        }

        /* if user is reading ppm data while we got a new frame, just drop this frame */
        if (decoder->total_chan && decoder->chan_id == decoder->total_chan && !decoder->ppm_reading) {
            /* reveived all channel data */
            for (uint8_t i = 0; i < decoder->total_chan; i++) {
                decoder->ppm_val[i] = decoder->scale_us * temp_val[i];

                if (decoder->ppm_val[i] < 1000) {
                    decoder->ppm_val[i] = 1000;
                } else if (decoder->ppm_val[i] > 2000) {
                    decoder->ppm_val[i] = 2000;
                }

                if(i < 8) {
                    decoder->ppm_val[i] = Mv_Ag(i, MV_COUNT, decoder->ppm_val[i]);
                }
                
            }

            decoder->ppm_recvd = 1;
        }

        decoder->chan_id = 0;
    }

    /* update last capture value */
    decoder->last_ic = ic_val;
}

/**
 * @brief initialize ppm decoder
 * 
 * @param decoder ppm decoder
 * @param freq_hz decoder timer frequency in Hz
 * @return rt_err_t RT_EOK for success
 */
rt_err_t ppm_decoder_init(ppm_decoder_t* decoder, uint32_t freq_hz)
{
    decoder->chan_id = 0;
    decoder->total_chan = 0;
    decoder->last_ic = 0;
    decoder->ppm_recvd = 0;
    decoder->ppm_reading = 0;
    decoder->freq_hz = freq_hz;
    decoder->scale_us = 1000000.0f / freq_hz;

    memset(decoder->ppm_val, 0, sizeof(decoder->ppm_val));

    return RT_EOK;
}
