/******************************************************************************
 * Copyright 2020-2021 The Firmament-Autopilot Authors. All Rights Reserved.
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
#include <firmament.h>
#include <string.h>

#include "dfs_elm.h"
#include "dfs_fs.h"
#include "dfs_romfs.h"
#include "module/file_manager/file_manager.h"
#ifdef RT_USING_DFS
#ifdef RT_USING_FAL
#ifdef BSP_USING_ON_CHIP_FLASH
#include "dfs_file.h"
#include "fal.h"
#endif /* RT_USING_DFS */
#endif /* RT_USING_FAL */
#endif /* BSP_USING_ON_CHIP_FLASH */

#define MAX_LOG_SESSION_NUM 40
#define LOG_SESSION_FILE    "/log/session_id"

static int cws_id; /* current work session id */

static const char* rfs_folder[] = {
    "/sys",
    "/usr",
    "/log",
    "/mnt",
    NULL /* NULL indicate the end */
};

/**
 * Read log session id from /log/session_id.
 * 
 * @return FMT Errors.
 */
static int read_log_session_id(void)
{
    char id_buffer[5] = { 0 };
    struct stat sta;
    int id = -1;
    int fd = -1;

    /* if file existed, read it */
    if (stat(LOG_SESSION_FILE, &sta) == 0) {
        int i;
        fd = open(LOG_SESSION_FILE, O_WRONLY);
        if (fd < 0) {
            return -1;
        }
        /* read session id from file */
        int rb = read(fd, id_buffer, sizeof(id_buffer) - 1);
        /* check if it's a valid number */
        for (i = 0; i < rb; i++) {
            /* session id starts from 1 */
            if (id_buffer[i] < '0' || id_buffer[i] > '9' || id_buffer[0] == '0') {
                /* illegal session id */
                close(fd);
                return -1;
            }
        }

        id = atoi(id_buffer);
        close(fd);
    }

    return id;
}

/**
 * Update log session id into /log/session_id.
 * 
 * @return FMT Errors.
 */
static fmt_err_t update_log_session(void)
{
    int fd;

    /* read current log session id */
    cws_id = read_log_session_id();
    if (cws_id < 0) {
        cws_id = 0;
    }

    /* increment session id */
    cws_id = (cws_id % MAX_LOG_SESSION_NUM) + 1;
    /* open or create the log session id file */
    fd = open(LOG_SESSION_FILE, O_TRUNC | O_CREAT | O_RDWR);
    if (fd < 0) {
        console_printf("fail to create log session id file! err:%ld\n", rt_get_errno());
        return FMT_ERROR;
    }
    fm_fprintf(fd, "%d", cws_id);
    close(fd);

    return FMT_EOK;
}

/**
 * Create working log session folder.
 * 
 * @return FMT Errors.
 */
static fmt_err_t create_log_session(void)
{
    char path[50];
    struct stat sta;
    /* get log session full path */
    sprintf(path, "/log/session_%d", cws_id);

    if (stat(path, &sta) == 0) {
        /* delete existed folder */
        if (fm_deldir(path) < 0) {
            console_printf("fail to delete %s\n", path);
            return FMT_ERROR;
        }
    }
    /* create log session */
    if (mkdir(path, 0x777) < 0) {
        console_printf("fail to create %s, errno:%ld\n", path, rt_get_errno());
        return FMT_ERROR;
    }

    return FMT_EOK;
}

/**
 * Create rootfs folders if not existed.
 * 
 * @return FMT Errors.
 */
static fmt_err_t create_rootfs(void)
{
    struct stat buf;
    int i = 0;

    /* clear mnt directory */
    fm_deldir("/mnt");

    /* create rootfs folder structure */
    while (1) {
        if (rfs_folder[i] != NULL) {
            if (stat(rfs_folder[i], &buf) < 0) {
                if (mkdir(rfs_folder[i], 0x777) < 0) {
                    console_printf("fail to create %s, errno:%ld\n", rfs_folder[i], rt_get_errno());
                    return FMT_ERROR;
                }
            }
            i++;
        } else {
            break;
        }
    }

    /* update and create log session */
    if (update_log_session() == FMT_EOK) {
        if (create_log_session() != FMT_EOK) {
            return FMT_ERROR;
        }
    } else {
        return FMT_ERROR;
    }

    return FMT_EOK;
}

/**
 * Get the current log session path.
 * 
 * @param path store the full path of current log session
 * @return FMT Errors.
 */
fmt_err_t current_log_session(char* path)
{
    if (cws_id > 0) {
        /* get log session full path */
        sprintf(path, "/log/session_%d", cws_id);
        return FMT_EOK;
    } else {
        return FMT_ERROR;
    }
}

const char *param_info = "# FMT System Configuration File\n"
                         "\n"
                         "# The target should match with BSP's target name\n"
                         "target = \"BL616\"\n"
                         "\n"
                         "# Pilot CMD Configuration\n"
                         "[pilot-cmd]\n"
                         "    # channel mapping for [yaw, throttle, roll, pitch]\n"
                         "    stick-channel = [4,3,1,2]\n"
                         "\n"
                         "    [pilot-cmd.device]\n"
                         "    type = \"rc\"\n"
                         "    name = \"rc\"\n"
                         "    protocol = \"auto\"           # auto/sbus/ppm\n"
                         "    channel-num = 8             # max supported channel: sbus:16, ppm:8\n"
                         "    sample-time = 0.05          # sample time in second (-1 for inherit)\n"
                         "    range = [1000,2000]\n"
                         "\n"
                         "    [[pilot-cmd.mode]]\n"
                         "    mode = 5                    # Position mode\n"
                         "    channel = 5\n"
                         "    range = [1000,1300]\n"
                         "\n"
                         "    [[pilot-cmd.mode]]\n"
                         "    mode = 4                    # Altitude mode\n"
                         "    channel = 5\n"
                         "    range = [1400,1600]\n"
                         "\n"
                         "    [[pilot-cmd.mode]]\n"
                         "    mode = 3                    # Stabilize mode\n"
                         "    channel = 5\n"
                         "    range = [1700,2000]\n"
                         "\n"
                         "    [[pilot-cmd.command]]\n"
                         "    type = 1                    # 1:event | 2:status\n"
                         "    cmd = 1002                  # FMS_Cmd_Disarm\n"
                         "    channel = 6\n"
                         "    range = [1800,2000]\n"
                         "\n"
                         "# Actuator Configuration\n"
                         "[actuator]\n"
                         "    [[actuator.devices]]\n"
                         "    protocol = \"pwm\"\n"
                         "    name = \"main_out\"\n"
                         "    freq = 400                  # pwm frequency in Hz\n"
                         "\n"
                         "    [[actuator.mappings]]\n"
                         "    from = \"rc_channels\"\n"
                         "    to = \"main_out\"\n"
                         "    chan-map = [[1,2,3,4],[1,2,3,4]]\n"
                         "\n";

/**
 * Initialize the file system.
 * 
 * @return FMT Errors.
 */
fmt_err_t file_manager_init(const struct dfs_mount_tbl* mnt_table)
{
    struct stat sta;

    if (dfs_init() != 0) {
        printf("dfs init fail!\n");
        return FMT_ERROR;
    }
    if (elm_init() != 0) {
        printf("fatfs init fail!\n");
        return FMT_ERROR;
    }

#ifdef RT_USING_DFS_ROMFS
    /* init romfs */
    if (dfs_romfs_init() != 0) {
        printf("romfs init fail!\n");
        return FMT_ERROR;
    }
#endif

    if (mnt_table[0].device_name == NULL) {
        /* empty mount table, just return */
        return FMT_EOK;
    }

    if (strcmp("/", mnt_table[0].path) == 0) {
        /* mount root directory */
        struct rt_device *rootfs = RT_NULL;

        //将flash中filesystem分区抽象为块设备
        rootfs = fal_blk_device_create("filesystem");
        if(rootfs == RT_NULL){
            return -RT_ERROR;
        }

        //将elm fat文件系统挂载到块设备上
        if (dfs_mount(mnt_table[0].device_name,
                      mnt_table[0].path,
                      mnt_table[0].filesystemtype,
                      mnt_table[0].rwflag,
                      mnt_table[0].data) == 0) {
            rt_kprintf("file system initialization done!\n");
        } else {
            if(dfs_mkfs(mnt_table[0].filesystemtype, mnt_table[0].device_name) == 0)
            {
                if (dfs_mount(mnt_table[0].device_name,
                      mnt_table[0].path,
                      mnt_table[0].filesystemtype,
                      mnt_table[0].rwflag,
                      mnt_table[0].data) == 0) {
                    rt_kprintf("file system initialization done!\n");
                } else {
                    rt_kprintf("file system initialization failed!\n");
                }
            } else {
                    rt_kprintf("file system format failed!\n");
            }
        }

        /* create rootfs */
        FMT_TRY(create_rootfs());

    } else {
        printf("fail, you should mount / first!\n");
        return FMT_ERROR;
    }

    /* mount other devices */
    for (int i = 1;; i++) {
        if (mnt_table[i].path == NULL) {
            break;
        }
        /* if path doesn't exit, create it */
        if (stat(mnt_table[i].path, &sta) < 0) {
            if (mkdir(mnt_table[i].path, 0x777) < 0) {
                printf("fail to create %s, errno:%ld\n", mnt_table[i].path, rt_get_errno());
                return FMT_ERROR;
            }
        }

        if (dfs_mount(mnt_table[i].device_name,
                      mnt_table[i].path,
                      mnt_table[i].filesystemtype,
                      mnt_table[i].rwflag,
                      mnt_table[i].data)
            < 0) {
            printf("Fail to mount %s at %s!\n",
                   mnt_table[i].device_name,
                   mnt_table[i].path);
            /* delete the failed mount path */
            fm_deldir(mnt_table[i].path);
        }
    }

    FILE* fp = fopen("/sys/sysconfig.toml", "r");
    if(!fp){
        int fd = creat("/sys/sysconfig.toml", 0x777);
        int len = write(fd, param_info, strlen(param_info));
        printf("write param %d,%d\n",len, strlen(param_info));
        close(fd);
    }else{
        printf("exist /sys/sysconfig.toml.\n");
        fclose(fp);
    }
    return FMT_EOK;
}