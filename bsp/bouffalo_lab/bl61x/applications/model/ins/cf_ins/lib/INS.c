/*
 * File: INS.c
 *
 * Code generated for Simulink model 'INS'.
 *
 * Model version                  : 13.0
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Sat Nov  2 09:17:44 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: RISC-V->RV32I
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "INS.h"
#include "rtwtypes.h"
#include <math.h>
#include "csi_math.h"
#include <string.h>
#include "zero_crossing_types.h"
#include <float.h>
#include <compiler/compiler_ld.h>
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */

/* Exported block parameters */
struct_LUgYRyhx9o9m0bdOsmtFn INS_PARAM = {
  2.5F,
  0.4F,
  4.5F,
  0.25F,
  1.0F,
  1.0F,
  0.2F,
  0.05F,
  0.3F,
  0U,
  0.25F,
  0.02F,
  0.01F,
  2.0F,
  1.0F,
  150U,
  100U,
  2.0F,
  1.0F,
  5U,
  0.0F,
  2.0F,
  1.0F,
  0.2F,
  10U,
  2.0F,
  1.0F,
  0.2F,
  5U,
  5.0F,
  2.0F,
  0.2F,
  50U,
  2U,
  0.0F,
  1U
} ;                                    /* Variable: INS_PARAM
                                        * Referenced by:
                                        *   '<S462>/Gain1'
                                        *   '<S131>/Constant1'
                                        *   '<S423>/Constant1'
                                        *   '<S423>/Gain2'
                                        *   '<S424>/Constant7'
                                        *   '<S424>/Gain3'
                                        *   '<S69>/Gain1'
                                        *   '<S72>/Gain3'
                                        *   '<S75>/Gain'
                                        *   '<S76>/Gain'
                                        *   '<S76>/Gain1'
                                        *   '<S214>/Gain'
                                        *   '<S214>/Gain2'
                                        *   '<S214>/Gain3'
                                        *   '<S215>/pos_delay'
                                        *   '<S223>/Gain'
                                        *   '<S223>/Gain2'
                                        *   '<S223>/Gain3'
                                        *   '<S224>/pos_delay'
                                        *   '<S224>/vel_delay'
                                        *   '<S233>/Gain'
                                        *   '<S233>/Gain2'
                                        *   '<S234>/Delay'
                                        *   '<S254>/Gain'
                                        *   '<S254>/Gain1'
                                        *   '<S254>/Gain2'
                                        *   '<S255>/delay'
                                        *   '<S263>/Gain'
                                        *   '<S263>/Gain1'
                                        *   '<S263>/Gain2'
                                        *   '<S264>/delay'
                                        *   '<S272>/Gain'
                                        *   '<S272>/Gain1'
                                        *   '<S272>/Gain2'
                                        *   '<S273>/pos_delay'
                                        *   '<S273>/vel_delay'
                                        *   '<S281>/Gain'
                                        *   '<S281>/Gain1'
                                        *   '<S281>/Gain2'
                                        *   '<S282>/delay'
                                        *   '<S328>/Constant'
                                        *   '<S328>/Constant2'
                                        *   '<S287>/Constant2'
                                        */

struct_i6HyuFQRjfkj8sSCv2bg5D INS_EXPORT = {
  4U,

  { 67, 70, 32, 73, 78, 83, 32, 118, 49, 46, 48, 46, 48, 0 }
} ;                                    /* Variable: INS_EXPORT
                                        * Referenced by:
                                        *   '<S4>/Constant'
                                        *   '<S399>/Constant'
                                        *   '<S411>/Constant'
                                        *   '<S437>/Constant'
                                        *   '<S445>/Constant'
                                        *   '<S463>/Constant'
                                        *   '<S473>/Constant'
                                        *   '<S11>/Constant'
                                        *   '<S12>/Constant'
                                        *   '<S13>/Constant'
                                        *   '<S14>/Constant'
                                        *   '<S15>/Constant'
                                        *   '<S16>/Constant'
                                        *   '<S17>/Constant'
                                        *   '<S422>/Constant'
                                        *   '<S99>/Constant1'
                                        *   '<S350>/Constant'
                                        *   '<S351>/Constant'
                                        *   '<S362>/Constant'
                                        *   '<S363>/Constant'
                                        *   '<S364>/Constant'
                                        */

/* Block parameters (default storage) */
Parameters_INS_T INS_P = {
  {
    0.004,
    9.8055F,

    { 60.6688499F, 63.1136093F, 61.9571686F, 58.5107918F, 53.9825211F,
      48.8148804F, 43.2272797F, 37.9078407F, 34.1241F, 32.8304787F, 33.9999084F,
      37.2338F, 42.2268791F, 48.3138885F, 53.9158897F, 57.2580109F, 57.8856F,
      60.04245F, 61.7999496F, 60.0581F, 56.2311287F, 51.54179F, 46.4250603F,
      41.1212692F, 36.3227692F, 33.2118912F, 32.5332794F, 34.0471611F,
      37.3293915F, 42.246109F, 48.2871819F, 53.8394814F, 57.0920105F,
      57.7239685F, 59.2624512F, 60.314F, 58.0622902F, 53.9296608F, 49.110981F,
      44.0556412F, 39.0556602F, 34.8108597F, 32.3865395F, 32.343071F,
      34.3287888F, 37.9020615F, 42.9333916F, 48.8902283F, 54.1666F, 57.0963F,
      57.5895386F, 58.3503799F, 58.6792908F, 55.9897194F, 51.6387596F,
      46.7298393F, 41.7255783F, 37.0196609F, 33.3552399F, 31.6662102F,
      32.3189316F, 34.8861198F, 38.9211082F, 44.1993408F, 50.0266304F,
      54.8299294F, 57.2408F, 57.4788208F, 57.3273582F, 56.9035416F, 53.8143883F,
      49.3266411F, 44.3983116F, 39.4714317F, 35.0624F, 32.0025291F, 31.1179695F,
      32.5729713F, 35.8210793F, 40.3716F, 45.8926392F, 51.5137215F, 55.7101402F,
      57.4770088F, 57.3836098F, 56.2152901F, 54.987751F, 51.4757309F,
      46.8875389F, 42.0354309F, 37.2897797F, 33.2398682F, 30.8035908F,
      30.7420692F, 33.0564F, 37.0471382F, 42.1026917F, 47.7855F, 53.1201286F,
      56.6581802F, 57.7437401F, 57.2923393F, 55.03825F, 52.9404488F, 48.9163399F,
      44.1882286F, 39.496521F, 35.1065407F, 31.5591698F, 29.77808F, 30.4949799F,
      33.6304092F, 38.3542404F, 43.8760414F, 49.6316719F, 54.6226616F,
      57.5236206F, 57.9748383F, 57.1917381F, 53.822979F, 50.7914505F,
      46.1322517F, 41.1598816F, 36.6611519F, 32.7988701F, 29.9308491F,
      28.8718204F, 30.32831F, 34.19133F, 39.550621F, 45.4551697F, 51.2053F,
      55.8290596F, 58.1714516F, 58.1068916F, 57.0691185F, 52.5992203F,
      48.5984192F, 43.2062683F, 37.8717499F, 33.5220108F, 30.2470798F,
      28.1678391F, 27.9196F, 30.1113892F, 34.5684F, 40.3826485F, 46.5514717F,
      52.2567482F, 56.5575F, 58.4858894F, 58.0859795F, 56.9144F, 51.3993F,
      46.4421F, 40.3025894F, 34.547039F, 30.2575F, 27.4956608F, 26.1988106F,
      26.7910194F, 29.6486797F, 34.4864502F, 40.5179214F, 46.8266106F,
      52.5147209F, 56.6392784F, 58.3791504F, 57.875679F, 56.7213402F,
      50.2558784F, 44.4099693F, 37.62146F, 31.5135899F, 27.2581291F, 24.9102097F,
      24.2886906F, 25.5767403F, 28.8667908F, 33.8025513F, 39.7895889F,
      46.0994682F, 51.8271217F, 55.9901314F, 57.8185081F, 57.4648705F,
      56.4902802F, 49.1997185F, 42.57724F, 35.3339F, 29.0936298F, 25.0088406F,
      23.0613403F, 22.9270802F, 24.5634F, 27.9123802F, 32.6535797F, 38.3665695F,
      44.5343208F, 50.3232689F, 54.7006683F, 56.8559608F, 56.8737F, 56.2281F,
      48.2592697F, 40.9926605F, 33.524189F, 27.4585304F, 23.8101292F,
      22.3264198F, 22.4728699F, 24.0649509F, 27.0742607F, 31.3636799F,
      36.6731491F, 42.6149712F, 48.4230499F, 53.0473595F, 55.6300392F,
      56.1536789F, 55.9474F, 47.4595909F, 39.67593F, 32.1695595F, 26.5328407F,
      23.5364799F, 22.5513496F, 22.8670197F, 24.2535191F, 26.7092609F, 30.3699F,
      35.23452F, 40.9257507F, 46.6428719F, 51.3816795F, 54.3264084F, 55.3779488F,
      55.6673393F, 46.8229904F, 38.6292F, 31.17342F, 26.0458908F, 23.731F,
      23.2198105F, 23.7449F, 25.0779209F, 27.0727406F, 30.0517807F, 34.4248F,
      39.8271484F, 45.3229218F, 49.9803391F, 53.1202087F, 54.6265106F, 55.41008F,
      46.3701401F, 37.856369F, 30.4379F, 25.7118893F, 23.9623108F, 23.9457703F,
      24.8520699F, 26.3540192F, 28.07197F, 30.42383F, 34.2626305F, 39.3300896F,
      44.5348396F, 48.9756813F, 52.1386719F, 53.9745712F, 55.1987915F, 46.1204F,
      37.3793297F, 29.9332905F, 25.3900604F, 24.0330906F, 24.6195107F,
      26.1449604F, 27.9149895F, 29.3943501F, 31.2168598F, 34.5874214F,
      39.3349609F, 44.2456512F, 48.4057884F, 51.4557686F, 53.4830093F,
      55.0553894F, 46.0917816F, 37.2448502F, 29.72896F, 25.1364403F, 23.9364891F,
      25.1510906F, 27.4533596F, 29.5271F, 30.7618294F, 32.1979485F, 35.2950897F,
      39.8154907F, 44.4367485F, 48.2638893F, 51.1002693F, 53.1952705F,
      54.9979897F, 46.2990417F, 37.5177307F, 29.9768505F, 25.1834908F, 23.8245F,
      25.4074497F, 28.3906803F, 30.8085804F, 31.9389F, 33.205349F, 36.2473F,
      40.6632F, 45.0166512F, 48.4885292F, 51.0664F, 53.1387596F, 55.0398903F,
      46.7511F, 38.2631493F, 30.85853F, 25.8815708F, 24.0939503F, 25.5383797F,
      28.7855701F, 31.4756F, 32.7162F, 34.0644608F, 37.2147713F, 41.6298294F,
      45.7915497F, 48.9735413F, 51.3314896F, 53.3283882F, 55.1878319F, 47.44804F,
      39.5251808F, 32.5166512F, 27.5721607F, 25.3377705F, 26.16325F, 29.0192299F,
      31.6294098F, 33.0449486F, 34.7081604F, 38.1154594F, 42.5916901F,
      46.6388092F, 49.6521187F, 51.8841515F, 53.7698517F, 55.4411F, 48.3783493F,
      41.3098793F, 34.99897F, 30.4203606F, 28.0098896F, 28.0544796F, 29.9036694F,
      31.8600807F, 33.2503319F, 35.3214188F, 39.08535F, 43.6334801F, 47.5973816F,
      50.54813F, 52.7364082F, 54.4578209F, 55.7903519F, 49.5174217F, 43.5770683F,
      38.2391205F, 34.3330383F, 32.1117897F, 31.5786591F, 32.20224F, 33.0197601F,
      33.9549484F, 36.1782188F, 40.1831512F, 44.7884789F, 48.7397118F,
      51.7291794F, 53.9053612F, 55.3693199F, 56.2177086F, 50.8273F, 46.24123F,
      42.0747795F, 39.0112915F, 37.2069397F, 36.3978882F, 35.9685097F,
      35.4701118F, 35.477581F, 37.3330803F, 41.2869F, 45.9653091F, 50.0739708F,
      53.2238F, 55.369F, 56.4536285F, 56.6971092F, 52.2585411F, 49.1803398F,
      46.2837486F, 44.0661697F, 42.6629906F, 41.6962891F, 40.4416885F, 38.6933F,
      37.5363197F, 38.6625099F, 42.3569298F, 47.1515198F, 51.5779305F,
      54.9728203F, 57.0323F, 57.6269302F, 57.1959801F, 53.7530708F, 52.2467918F,
      50.6192894F, 49.126091F, 47.9187088F, 46.6905F, 44.7241707F, 41.9129F,
      39.6623383F, 40.03F, 43.4514618F, 48.3972397F, 53.1817207F, 56.8117905F,
      58.7214F, 58.7770615F, 57.6783295F, 55.2478218F, 55.2797089F, 54.8312798F,
      53.8861389F, 52.6146812F, 50.9185F, 48.2532387F, 44.5917816F, 41.4765205F,
      41.2253418F, 44.4608383F, 49.5864716F, 54.6858215F, 58.4801292F,
      60.2103386F, 59.779541F, 58.1086884F, 56.6799F, 58.1193F, 58.677021F,
      58.0862198F, 56.5232391F, 54.1281395F, 50.6552887F, 46.2659798F,
      42.5672607F, 41.9474716F, 45.1312F, 50.4559784F, 55.7945595F, 59.6797485F,
      61.2728806F, 60.5214119F, 58.4570389F, 57.9907494F, 60.620491F, 61.934761F,
      61.4903412F, 59.4637718F, 56.1816101F, 51.7399406F, 46.6526489F,
      42.6542282F, 41.9919586F, 45.2595406F, 50.7410316F, 56.2129288F,
      60.1520195F, 61.737751F, 60.9253387F, 58.7026482F, 59.1301613F,
      62.6677208F, 64.4334793F, 63.9225388F, 61.3523102F, 57.19067F, 51.8279915F,
      46.1409798F, 41.9927711F, 41.3919106F, 44.6956406F, 50.1936607F,
      55.7020302F, 59.7392616F, 61.5330391F, 60.9662704F, 58.8369408F,
      60.0598106F, 64.1874237F, 66.0832214F, 65.3220062F, 62.250061F, 57.464241F,
      51.5262604F, 45.4629517F, 41.1138115F, 40.3063698F, 43.3432884F,
      48.6538582F, 54.1679916F, 58.4471092F, 60.7108498F, 60.6774483F,
      58.8635406F, 60.7546082F, 65.152771F, 66.8857117F, 65.7488708F,
      62.2935104F, 57.2024307F, 51.054039F, 44.818119F, 40.1843681F, 38.8794289F,
      41.3375702F, 46.2735786F, 51.8004303F, 56.4865112F, 59.4405594F,
      60.1399689F, 58.7971916F, 61.2030716F, 65.5802612F, 66.9189682F, 65.33918F,
      61.6124306F, 56.4158516F, 50.2304F, 43.9236908F, 39.0599213F, 37.2652206F,
      39.0765F, 43.5435905F, 49.0624886F, 54.2272186F, 57.9635391F, 59.4627113F,
      58.66F, 61.4053612F, 65.5193787F, 66.3063583F, 64.2539597F, 60.3182487F,
      55.1038704F, 48.9593887F, 42.6758194F, 37.7462082F, 35.6767807F, 36.9895F,
      41.008091F, 46.4677887F, 52.0577316F, 56.5215187F, 58.7569199F,
      58.4774513F, 61.3719597F, 65.0383682F, 65.1877213F, 62.6528397F, 58.52145F,
      53.3208618F, 47.3027496F, 41.19347F, 36.4136505F, 34.3309784F, 35.3677101F,
      39.0226517F, 44.3670082F, 50.2589111F, 55.2993202F, 58.1154785F,
      58.274559F, 61.119381F, 64.2127838F, 63.698391F, 60.6903191F, 56.3554802F,
      51.1674194F, 45.3414307F, 39.5673599F, 35.1857109F, 33.3773117F,
      34.3724213F, 37.75737F, 42.9317513F, 48.984169F, 54.4105301F, 57.6034317F,
      58.0721283F, 60.6688499F, 63.1136093F, 61.9571686F, 58.5107918F,
      53.9825211F, 48.8148804F, 43.2272797F, 37.9078407F, 34.1241F, 32.8304787F,
      33.9999084F, 37.2338F, 42.2268791F, 48.3138885F, 53.9158897F, 57.2580109F,
      57.8856F },

    { 129.47F, 85.74F, 47.95F, 31.19F, 22.49F, 16.95F, 13.27F, 11.01F, 9.8F,
      9.04F, 8.04F, 6.39F, 4.43F, 2.87F, 1.89F, 0.82F, -2.32F, 117.22F, 77.74F,
      46.6F, 31.43F, 23.03F, 17.45F, 13.54F, 10.99F, 9.62F, 9.1F, 8.9F, 8.5F,
      7.8F, 7.16F, 6.81F, 6.22F, 3.0F, 106.08F, 71.32F, 45.05F, 31.15F, 23.11F,
      17.66F, 13.69F, 10.92F, 9.35F, 8.9F, 9.28F, 10.0F, 10.63F, 11.06F, 11.42F,
      11.38F, 7.93F, 95.9F, 65.84F, 43.54F, 30.68F, 22.9F, 17.63F, 13.76F,
      10.96F, 9.35F, 9.04F, 9.84F, 11.3F, 12.87F, 14.23F, 15.37F, 15.95F, 11.92F,
      86.49F, 60.89F, 42.13F, 30.3F, 22.59F, 17.34F, 13.56F, 10.85F, 9.33F,
      9.23F, 10.36F, 12.23F, 14.3F, 16.32F, 18.23F, 19.43F, 14.1F, 77.66F,
      56.14F, 40.72F, 30.13F, 22.43F, 16.92F, 13.06F, 10.41F, 8.99F, 9.0F,
      10.29F, 12.32F, 14.56F, 16.91F, 19.4F, 21.05F, 12.85F, 69.27F, 51.34F,
      39.0F, 29.96F, 22.49F, 16.6F, 12.48F, 9.82F, 8.45F, 8.36F, 9.46F, 11.29F,
      13.35F, 15.59F, 18.13F, 19.48F, 5.26F, 61.17F, 46.27F, 36.55F, 29.27F,
      22.45F, 16.43F, 12.06F, 9.33F, 7.84F, 7.34F, 7.77F, 8.9F, 10.31F, 11.84F,
      13.4F, 12.7F, -11.34F, 53.29F, 40.83F, 33.06F, 27.34F, 21.49F, 15.73F,
      11.24F, 8.29F, 6.4F, 5.21F, 4.67F, 4.75F, 5.09F, 5.26F, 4.59F, -0.63F,
      -31.16F, 45.55F, 34.99F, 28.39F, 23.59F, 18.49F, 13.05F, 8.46F, 5.18F,
      2.88F, 1.11F, -0.23F, -1.16F, -1.98F, -3.4F, -6.84F, -16.66F, -43.36F,
      37.91F, 28.86F, 22.67F, 17.84F, 12.7F, 7.22F, 2.52F, -0.81F, -3.03F,
      -4.72F, -6.22F, -7.61F, -9.16F, -11.68F, -16.85F, -27.98F, -47.21F, 30.36F,
      22.59F, 16.3F, 10.57F, 4.49F, -1.41F, -5.93F, -8.65F, -10.05F, -10.91F,
      -11.73F, -12.73F, -14.24F, -17.04F, -22.55F, -32.64F, -46.06F, 22.85F,
      16.36F, 9.86F, 2.87F, -4.49F, -10.64F, -14.43F, -16.0F, -16.16F, -15.74F,
      -15.26F, -15.22F, -16.18F, -18.8F, -24.01F, -32.58F, -42.16F, 15.38F,
      10.3F, 3.93F, -3.97F, -12.12F, -17.93F, -20.64F, -20.9F, -19.68F, -17.83F,
      -16.01F, -14.96F, -15.38F, -17.74F, -22.51F, -29.71F, -36.69F, 7.89F,
      4.43F, -1.18F, -9.07F, -17.2F, -22.31F, -23.86F, -22.61F, -19.85F, -16.82F,
      -14.24F, -12.74F, -12.85F, -14.94F, -19.22F, -25.22F, -30.28F, 0.34F,
      -1.36F, -5.56F, -12.4F, -19.92F, -24.42F, -24.67F, -21.47F, -17.13F,
      -13.44F, -10.85F, -9.45F, -9.48F, -11.25F, -14.92F, -19.8F, -23.3F, -7.34F,
      -7.29F, -9.74F, -14.73F, -21.07F, -24.99F, -23.63F, -18.27F, -12.78F,
      -9.01F, -6.79F, -5.7F, -5.73F, -7.17F, -10.17F, -13.88F, -15.96F, -15.18F,
      -13.59F, -14.42F, -17.22F, -21.47F, -23.92F, -20.57F, -13.85F, -8.29F,
      -4.9F, -3.03F, -2.14F, -2.11F, -3.15F, -5.32F, -7.72F, -8.41F, -23.24F,
      -20.43F, -20.09F, -21.03F, -22.35F, -21.47F, -15.69F, -9.0F, -4.51F,
      -1.89F, -0.34F, 0.56F, 0.85F, 0.41F, -0.66F, -1.53F, -0.76F, -31.54F,
      -27.84F, -26.86F, -26.68F, -25.38F, -19.97F, -10.98F, -4.6F, -1.39F, 0.32F,
      1.46F, 2.34F, 2.98F, 3.34F, 3.68F, 4.58F, 6.88F, -40.09F, -35.71F, -34.41F,
      -33.68F, -30.76F, -21.75F, -9.14F, -1.8F, 1.02F, 2.21F, 2.96F, 3.69F,
      4.55F, 5.77F, 7.67F, 10.49F, 14.44F, -48.87F, -43.87F, -42.21F, -40.93F,
      -36.84F, -25.91F, -11.0F, -1.84F, 1.76F, 3.12F, 3.84F, 4.56F, 5.73F, 7.84F,
      11.32F, 16.05F, 21.81F, -57.89F, -52.13F, -49.75F, -47.46F, -41.94F,
      -29.96F, -14.7F, -4.45F, 0.26F, 2.27F, 3.37F, 4.49F, 6.31F, 9.49F, 14.47F,
      21.06F, 28.85F, -67.15F, -60.38F, -56.69F, -52.66F, -45.12F, -32.1F,
      -17.48F, -7.38F, -2.13F, 0.43F, 1.99F, 3.65F, 6.27F, 10.5F, 16.79F, 25.16F,
      35.38F, -76.67F, -68.54F, -62.8F, -56.15F, -45.85F, -31.52F, -17.81F,
      -8.68F, -3.64F, -0.95F, 0.82F, 2.78F, 5.83F, 10.64F, 17.76F, 27.79F, 41.1F,
      -86.5F, -76.64F, -67.97F, -57.6F, -43.82F, -28.28F, -15.84F, -8.22F,
      -3.99F, -1.57F, 0.15F, 2.08F, 5.0F, 9.61F, 16.78F, 28.09F, 45.46F, -96.72F,
      -84.8F, -72.09F, -56.58F, -38.84F, -22.85F, -12.25F, -6.45F, -3.43F,
      -1.68F, -0.33F, 1.23F, 3.52F, 7.14F, 13.25F, 24.77F, 47.46F, -107.43F,
      -93.29F, -74.93F, -52.32F, -30.96F, -15.92F, -7.54F, -3.57F, -1.91F,
      -1.19F, -0.66F, 0.08F, 1.24F, 3.18F, 6.99F, 16.58F, 45.09F, -118.77F,
      -102.54F, -75.92F, -43.75F, -21.13F, -8.92F, -3.01F, -0.67F, -0.2F, -0.56F,
      -1.08F, -1.49F, -1.78F, -1.87F, -1.04F, 4.2F, 34.68F, -130.89F, -113.42F,
      -73.34F, -30.29F, -11.32F, -3.43F, -0.14F, 0.78F, 0.36F, -0.75F, -2.13F,
      -3.61F, -5.23F, -7.04F, -8.63F, -7.88F, 14.29F, -143.9F, -127.72F, -61.4F,
      -13.68F, -2.91F, 0.49F, 1.41F, 1.11F, 0.07F, -1.5F, -3.46F, -5.71F, -8.23F,
      -10.97F, -13.69F, -15.41F, -5.73F, -157.84F, -149.27F, -20.81F, 2.05F,
      4.1F, 3.94F, 3.15F, 2.05F, 0.6F, -1.33F, -3.78F, -6.64F, -9.66F, -12.67F,
      -15.54F, -18.02F, -15.73F, -172.57F, 176.83F, 27.13F, 14.12F, 10.06F,
      7.49F, 5.65F, 4.14F, 2.52F, 0.36F, -2.48F, -5.76F, -9.04F, -12.0F, -14.61F,
      -17.11F, -18.04F, 172.29F, 138.71F, 43.23F, 22.28F, 14.98F, 10.9F, 8.33F,
      6.57F, 4.97F, 2.89F, 0.03F, -3.36F, -6.67F, -9.47F, -11.75F, -14.01F,
      -16.3F, 157.26F, 112.47F, 47.83F, 27.29F, 18.72F, 13.78F, 10.7F, 8.76F,
      7.31F, 5.59F, 3.08F, -0.08F, -3.24F, -5.8F, -7.71F, -9.63F, -12.48F,
      142.86F, 96.47F, 48.65F, 30.01F, 21.17F, 15.83F, 12.42F, 10.36F, 9.09F,
      7.87F, 6.01F, 3.41F, 0.63F, -1.55F, -3.04F, -4.57F, -7.62F, 129.47F,
      85.74F, 47.95F, 31.19F, 22.49F, 16.95F, 13.27F, 11.01F, 9.8F, 9.04F, 8.04F,
      6.39F, 4.43F, 2.87F, 1.89F, 0.82F, -2.32F },

    { -78.32F, -80.9F, -77.5F, -71.61F, -64.4F, -55.01F, -42.22F, -25.27F,
      -5.16F, 14.71F, 31.05F, 43.37F, 53.09F, 61.88F, 70.58F, 78.83F, 85.96F,
      -77.55F, -79.07F, -75.48F, -69.67F, -62.42F, -52.87F, -39.76F, -22.29F,
      -1.69F, 18.2F, 34.01F, 45.48F, 54.34F, 62.58F, 71.01F, 79.09F, 86.05F,
      -76.63F, -77.24F, -73.55F, -67.78F, -60.45F, -50.73F, -37.42F, -19.76F,
      0.89F, 20.62F, 36.14F, 47.27F, 55.81F, 63.74F, 71.88F, 79.66F, 86.28F,
      -75.6F, -75.39F, -71.65F, -65.94F, -58.48F, -48.51F, -34.98F, -17.28F,
      3.17F, 22.54F, 37.81F, 48.88F, 57.44F, 65.29F, 73.15F, 80.49F, 86.63F,
      -74.48F, -73.48F, -69.68F, -64.09F, -56.54F, -46.26F, -32.43F, -14.67F,
      5.55F, 24.56F, 39.59F, 50.65F, 59.31F, 67.16F, 74.71F, 81.53F, 87.09F,
      -73.33F, -71.51F, -67.54F, -62.1F, -54.59F, -44.09F, -29.96F, -12.08F,
      7.95F, 26.67F, 41.57F, 52.65F, 61.39F, 69.2F, 76.45F, 82.72F, 87.59F,
      -72.15F, -69.47F, -65.16F, -59.81F, -52.52F, -42.03F, -27.69F, -9.67F,
      10.22F, 28.72F, 43.56F, 54.72F, 63.52F, 71.25F, 78.19F, 83.92F, 88.06F,
      -71.0F, -67.41F, -62.55F, -57.1F, -50.07F, -39.77F, -25.28F, -7.0F, 12.83F,
      31.01F, 45.61F, 56.71F, 65.49F, 73.08F, 79.73F, 84.97F, 88.31F, -69.9F,
      -65.44F, -59.86F, -54.05F, -47.07F, -36.82F, -22.02F, -3.36F, 16.26F,
      33.68F, 47.59F, 58.35F, 66.97F, 74.37F, 80.75F, 85.57F, 88.18F, -68.89F,
      -63.66F, -57.37F, -51.04F, -43.81F, -33.3F, -18.06F, 0.72F, 19.64F, 35.87F,
      48.8F, 59.05F, 67.48F, 74.74F, 80.91F, 85.44F, 87.69F, -67.99F, -62.2F,
      -55.46F, -48.77F, -41.31F, -30.64F, -15.4F, 2.91F, 20.92F, 36.17F, 48.37F,
      58.27F, 66.65F, 73.95F, 80.13F, 84.62F, 87.02F, -67.22F, -61.13F, -54.42F,
      -47.99F, -40.97F, -30.96F, -16.69F, 0.68F, 18.26F, 33.51F, 45.81F, 55.91F,
      64.62F, 72.25F, 78.7F, 83.45F, 86.29F, -66.58F, -60.48F, -54.37F, -49.08F,
      -43.5F, -35.21F, -22.85F, -6.71F, 11.04F, 27.46F, 41.11F, 52.35F, 61.92F,
      70.16F, 77.03F, 82.19F, 85.57F, -66.09F, -60.18F, -55.14F, -51.69F,
      -48.17F, -42.02F, -31.99F, -17.58F, 0.23F, 18.6F, 34.89F, 48.29F, 59.19F,
      68.16F, 75.46F, 81.01F, 84.92F, -65.73F, -60.1F, -56.32F, -54.93F, -53.46F,
      -49.2F, -41.34F, -28.93F, -11.51F, 8.9F, 28.43F, 44.48F, 56.9F, 66.57F,
      74.18F, 80.01F, 84.34F, -65.49F, -60.13F, -57.45F, -57.9F, -58.26F,
      -55.54F, -49.29F, -38.3F, -21.14F, 0.89F, 23.14F, 41.5F, 55.25F, 65.48F,
      73.27F, 79.23F, 83.87F, -65.38F, -60.19F, -58.21F, -60.03F, -62.1F,
      -60.84F, -55.5F, -44.75F, -27.11F, -3.9F, 19.99F, 39.77F, 54.36F, 64.92F,
      72.74F, 78.68F, 83.51F, -65.4F, -60.26F, -58.51F, -61.05F, -64.69F, -65.0F,
      -60.06F, -48.52F, -29.72F, -5.46F, 19.21F, 39.46F, 54.29F, 64.87F, 72.54F,
      78.36F, 83.27F, -65.55F, -60.4F, -58.47F, -60.96F, -65.61F, -67.43F,
      -62.7F, -50.16F, -30.15F, -5.02F, 19.99F, 40.22F, 54.89F, 65.22F, 72.61F,
      78.24F, 83.16F, -65.86F, -60.73F, -58.41F, -60.14F, -64.77F, -67.53F,
      -63.05F, -49.9F, -29.26F, -3.73F, 21.35F, 41.4F, 55.79F, 65.79F, 72.87F,
      78.31F, 83.18F, -66.34F, -61.34F, -58.67F, -59.33F, -62.86F, -65.5F,
      -61.08F, -47.67F, -26.83F, -1.44F, 23.2F, 42.79F, 56.77F, 66.43F, 73.25F,
      78.54F, 83.33F, -66.99F, -62.33F, -59.55F, -59.31F, -61.25F, -62.6F,
      -57.62F, -43.83F, -22.82F, 2.14F, 25.82F, 44.47F, 57.81F, 67.08F, 73.72F,
      78.94F, 83.6F, -67.82F, -63.72F, -61.17F, -60.51F, -61.11F, -60.61F,
      -54.38F, -40.02F, -18.78F, 5.77F, 28.45F, 46.12F, 58.78F, 67.74F, 74.32F,
      79.52F, 84.01F, -68.81F, -65.51F, -63.47F, -62.83F, -62.64F, -60.52F,
      -52.91F, -37.98F, -16.6F, 7.73F, 29.92F, 47.11F, 59.5F, 68.4F, 75.07F,
      80.3F, 84.53F, -69.94F, -67.63F, -66.3F, -65.89F, -65.24F, -61.9F, -53.14F,
      -37.71F, -16.24F, 8.09F, 30.23F, 47.43F, 59.94F, 69.06F, 75.97F, 81.24F,
      85.17F, -71.18F, -70.02F, -69.47F, -69.27F, -68.13F, -63.74F, -54.06F,
      -38.24F, -16.65F, 7.8F, 30.09F, 47.47F, 60.26F, 69.75F, 76.97F, 82.31F,
      85.89F, -72.49F, -72.58F, -72.82F, -72.64F, -70.71F, -65.25F, -54.9F,
      -38.94F, -17.39F, 7.2F, 29.79F, 47.46F, 60.56F, 70.39F, 77.91F, 83.36F,
      86.66F, -73.83F, -75.23F, -76.23F, -75.74F, -72.59F, -65.94F, -55.04F,
      -39.1F, -17.82F, 6.68F, 29.47F, 47.41F, 60.75F, 70.81F, 78.54F, 84.18F,
      87.41F, -75.13F, -77.9F, -79.6F, -78.31F, -73.53F, -65.61F, -54.07F,
      -38.04F, -17.09F, 6.93F, 29.43F, 47.3F, 60.67F, 70.78F, 78.6F, 84.47F,
      88.02F, -76.35F, -80.5F, -82.82F, -80.03F, -73.57F, -64.6F, -52.51F,
      -36.34F, -15.72F, 7.55F, 29.35F, 46.86F, 60.07F, 70.09F, 77.94F, 84.07F,
      88.29F, -77.43F, -82.9F, -85.67F, -80.66F, -73.05F, -63.59F, -51.36F,
      -35.4F, -15.35F, 7.17F, 28.41F, 45.63F, 58.71F, 68.71F, 76.67F, 83.16F,
      88.09F, -78.29F, -84.9F, -87.34F, -80.24F, -72.25F, -62.79F, -50.82F,
      -35.38F, -16.06F, 5.75F, 26.58F, 43.66F, 56.74F, 66.84F, 75.07F, 82.03F,
      87.62F, -78.89F, -86.01F, -86.37F, -79.08F, -71.21F, -61.92F, -50.17F,
      -35.06F, -16.31F, 4.76F, 24.95F, 41.67F, 54.66F, 64.91F, 73.47F, 80.91F,
      87.09F, -79.19F, -85.72F, -84.19F, -77.47F, -69.88F, -60.72F, -48.95F,
      -33.78F, -15.19F, 5.23F, 24.48F, 40.43F, 53.04F, 63.27F, 72.11F, 79.96F,
      86.61F, -79.18F, -84.41F, -81.87F, -75.59F, -68.24F, -59.11F, -47.14F,
      -31.59F, -12.77F, 7.24F, 25.46F, 40.34F, 52.22F, 62.19F, 71.14F, 79.28F,
      86.25F, -78.87F, -82.7F, -79.63F, -73.61F, -66.37F, -57.15F, -44.8F,
      -28.6F, -9.2F, 10.64F, 27.84F, 41.43F, 52.28F, 61.73F, 70.62F, 78.89F,
      86.03F, -78.32F, -80.9F, -77.5F, -71.61F, -64.4F, -55.01F, -42.22F,
      -25.27F, -5.16F, 14.71F, 31.05F, 43.37F, 53.09F, 61.88F, 70.58F, 78.83F,
      85.96F }
  },
  10.0,
  1000,
  98.055F,
  -98.055F,
  3.14159274F,
  0.15F,
  3.14159274F,
  1.0F,
  0.01F,
  0.2F,
  5.0F,
  0.5F,
  38.3972435F,
  -38.3972435F,
  9.3055F,
  30000.0F,
  -30000.0F,
  4.0F,
  110000.0F,
  70.0F,
  20.0F,
  0.0F,
  30000.0F,
  -20.0F,
  -20.0F,
  1000.0F,
  100.0F,
  1000.0F,
  1000.0F,
  1000.0F,
  200.0F,
  100.0F,
  1000.0F,
  1000.0F,
  1000.0F,
  1000.0F,
  100.0F,
  10.3055F,
  1U,
  2U,
  8U,
  10000U,
  50U,
  50U,
  200U,
  500U,
  5000U,
  20U,
  1U,
  200U,
  500U,
  100U,
  1000U,
  100U,
  100U,
  200U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  3U,
  0U,
  2U,
  2U,
  90U,
  50U,
  0U,
  1.0E+8,
  1.0E-6,
  1.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  1.0,
  1.0,
  1.0,
  1.0,
  1.0,
  2.0,
  6.378137E+6,
  0.0033528106647474805,
  0,
  10000,
  0,

  { 8, 18 },

  { 16, 36 },
  0,
  1099511628,
  1099511628,
  1099511628,
  1099511628,
  2012227627,
  2012227627,
  0.0F,
  0.0F,
  1.0F,
  0.0F,
  1.0E+6F,
  0.0F,
  2.0F,
  1.0F,
  0.0F,
  1.0E+6F,
  0.0F,
  0.2F,
  0.1F,
  1.0F,
  0.0F,
  0.3F,
  0.2F,
  1.0F,
  0.0F,
  1.0E+6F,
  0.0F,
  1.0F,
  0.0F,
  1.0E+6F,
  0.0F,
  1.0F,
  0.0F,
  1.0E+6F,
  0.0F,
  1.0F,
  0.0F,
  1.0E+6F,
  0.0F,
  1.0F,
  0.0F,
  1.0E+6F,
  0.0F,
  2.0F,
  1.0F,
  -1.0F,
  1.0F,
  1.0F,
  -1.0F,
  1.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  -1.0F,
  1.0F,
  1.0F,
  0.0F,
  0.004F,
  0.0F,
  0.004F,
  20.0F,
  100.0F,
  6.28318548F,
  6.28318548F,
  0.0F,
  0.0F,
  0.004F,
  0.2F,
  0.1F,
  1.0F,
  0.0F,
  0.0F,

  { 0.0F, 0.0F, -9.8055F },
  0.0F,
  0.0F,
  -0.2F,
  0.2F,
  0.5F,
  -0.5F,
  0.0F,
  0.0F,
  0.17453292F,
  1.57079637F,
  -1.57079637F,
  0.0001F,
  0.0F,
  0.004F,
  0.0F,
  3947.8418F,
  88.8442383F,
  0.0F,

  { 0.0F, 0.0F, 1.0F },

  { 0.0F, 0.0F },
  -1.0F,
  0.0F,
  0.004F,
  0.0F,
  0.004F,
  0.0F,
  986.960449F,
  44.4221191F,
  0.0F,
  0.004F,
  0.00174532924F,
  -0.00174532924F,
  0.004F,
  0.0F,
  986.960449F,
  44.4221191F,
  0.0F,
  0.004F,
  0.0F,
  0.785398185F,
  -0.785398185F,
  0.5F,
  0.004F,
  2.0F,
  2.0F,
  2.0F,
  2.0F,
  2.0F,
  2.0F,
  0.0F,
  0.0F,
  1.0F,
  0.5F,
  2.0F,
  0.5F,

  { 0.0F, 1.0F },
  1.0F,
  0.5F,
  1.0F,
  1.0F,
  1.0F,
  0.5F,

  { 0.0F, 1.0F },
  1.0F,
  0.5F,
  1.0F,
  1.0F,
  1.0F,
  0.5F,

  { 0.0F, 1.0F },
  1.0F,
  0.5F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,

  { 1.0F, 0.0F, 0.0F },
  1.0F,
  0.0F,
  0.0F,
  0.0F,
  -1.0F,
  -1.0F,
  0.0F,
  0.0F,
  1.0F,
  1.0F,
  1.0F,

  { 1.0F, 0.0F, 0.0F, 0.0F },
  -1.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.004F,
  0.004F,
  1.0F,
  0.0F,
  0.004F,
  0.01F,
  0.003F,
  0.0F,
  1.0F,
  4.0F,
  2.0F,
  20.0F,
  0.0F,
  0.0F,
  0.0F,
  0.004F,
  0.75F,
  0.0F,

  { 0.0F, 0.0F },
  0.0F,
  0.004F,

  { 0.0F, 0.0F },
  0.0F,
  0.0F,
  0.004F,

  { 0.0F, 0.0F },
  1.0F,
  -1.0F,
  0.0F,
  0.0F,
  0.0F,
  0.004F,
  0.5F,
  -0.5F,
  1.0F,
  -1.0F,
  0.0F,
  0.0F,
  0.0F,
  0.004F,
  -0.75F,
  0.0F,
  0.0F,
  0.0F,
  0.004F,
  1.0F,
  -1.0F,
  0.0F,
  0.0F,
  0.0F,
  1000.0F,
  0.0F,
  0.0F,
  0.004F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  -1.0F,
  0.0F,
  0.004F,
  0.0F,
  0.0F,
  0.0F,

  { 0.0F, 0.0F },
  0.004F,
  0.0F,
  0.7F,
  0.4F,
  1.0F,
  0.0F,
  0.7F,
  0.6F,
  1.0F,
  0.0F,
  0.0F,
  0.004F,
  0.0F,
  0.004F,
  986.960449F,
  44.4221191F,
  0.0F,
  -1.0F,
  1.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  -1.0F,
  0.0F,
  1.0F,
  0.0F,
  1.0E+6F,
  0.0F,
  1.0F,
  0.0F,
  1.0E+6F,
  0.0F,
  1.0F,
  0.0F,
  1.0E+6F,
  0.0F,
  1.0F,
  0.0F,
  1.0E+6F,
  0.0F,
  1.0F,
  0.0F,
  1.0E+6F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  1.225F,
  2.0F,
  999.0F,
  0.1F,
  0.0F,
  0.0F,
  0.001F,
  101.325F,
  0.1902612F,
  288.15F,
  -0.0065F,
  -1.0F,
  0.0F,
  1.0F,
  0.0F,
  0.004F,
  0.0F,
  1.0F,
  0.0F,
  0.004F,
  0.004F,
  0.0F,
  39.4784164F,
  8.88442421F,
  0.004F,
  0.0F,
  39.4784164F,
  8.88442421F,
  0.5F,
  1.0F,
  1.0F,
  0.0F,
  0.0F,
  0.0F,
  -0.0174532924F,
  -1.0F,
  0.0F,
  1.0F,
  0.0F,
  100.0F,
  0.0174532924F,
  1.0F,
  2.0F,
  1.0F,
  0.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  0.0F,
  0.0F,
  0.004F,
  0.0F,
  0.004F,
  986.960449F,
  44.4221191F,
  0.3F,
  0.2F,
  1.0F,
  0.0F,
  0.0F,
  -1.0F,
  0.004F,
  -0.5F,
  0.004F,
  188.49556F,
  62.831852F,
  0.0F,
  3.0F,
  0.0F,
  1.0F,
  0.0F,
  0.0F,
  0.0F,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  2147483648U,
  2147483648U,
  2199023256U,
  2199023256U,
  0U,
  1U,
  0U,
  0U,
  4294967295U,
  0U,
  0U,
  0U,
  10000U,
  0U,
  0U,
  10000U,
  0U,
  0U,
  1U,
  0U,
  100U,
  0U,
  0U,
  1U,
  0U,
  10000U,
  1U,
  0U,
  0U,
  10000U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  9999U,
  0U,
  32768U,
  32768U,
  32768U,
  32768U,
  32768U,
  32768U,
  32768U,
  50U,
  0U,
  0U,
  0U,
  0U,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  true,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  0,
  1,
  0,
  1,
  0,
  1,
  0,
  1,
  0,
  128U,
  128U,
  128U,
  128U,
  128U,
  1U,
  1U,
  0U,
  0U,
  1U,
  0U,
  1U,
  0U,
  1U,
  0U,
  1U,
  0U,
  1U,
  0U,
  0U,
  1U,

  /* Start of '<S294>/Rf_Velocity' */
  {
    0.0F
  }
  ,

  /* End of '<S294>/Rf_Velocity' */

  /* Start of '<S294>/Baro_Velocity' */
  {
    0.0F
  }
  /* End of '<S294>/Baro_Velocity' */
};

/* Block signals (default storage) */
BlockIO_INS_T INS_B;

/* Block states (default storage) */
D_Work_INS_T INS_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_INS_T INS_PrevZCSigState;

/* External inputs (root inport signals with default storage) */
ExternalInputs_INS_T INS_U;

/* External outputs (root outports fed by signals with default storage) */
ExternalOutputs_INS_T INS_Y;

/* Real-time model */
static RT_MODEL_INS_T INS_M_;
RT_MODEL_INS_T *const INS_M = &INS_M_;
static void INS_Baro_Velocity(boolean_T rtu_TF_Data, real32_T *rty_vel_D_mPs,
  rtP_Baro_Velocity_INS_T *localP);
const INS_Out_Bus INS_rtZINS_Out_Bus = { 0U,/* timestamp */
  0.0F,                                /* phi */
  0.0F,                                /* theta */
  0.0F,                                /* psi */

  { 0.0F, 0.0F, 0.0F, 0.0F },          /* quat */
  0.0F,                                /* p */
  0.0F,                                /* q */
  0.0F,                                /* r */
  0.0F,                                /* ax */
  0.0F,                                /* ay */
  0.0F,                                /* az */
  0.0F,                                /* vn */
  0.0F,                                /* ve */
  0.0F,                                /* vd */
  0.0F,                                /* airspeed */
  0.0,                                 /* lat */
  0.0,                                 /* lon */
  0.0,                                 /* alt */
  0.0,                                 /* lat_0 */
  0.0,                                 /* lon_0 */
  0.0,                                 /* alt_0 */
  0.0,                                 /* dx_dlat */
  0.0,                                 /* dy_dlon */
  0.0F,                                /* x_R */
  0.0F,                                /* y_R */
  0.0F,                                /* h_R */
  0.0F,                                /* h_AGL */
  0U,                                  /* flag */
  0U                                   /* status */
};

/*
 * Output and update for enable system:
 *    '<S294>/Baro_Velocity'
 *    '<S294>/Rf_Velocity'
 */
static void INS_Baro_Velocity(boolean_T rtu_TF_Data, real32_T *rty_vel_D_mPs,
  rtP_Baro_Velocity_INS_T *localP)
{
  /* Outputs for Enabled SubSystem: '<S294>/Baro_Velocity' incorporates:
   *  EnablePort: '<S299>/Enable'
   */
  if (rtu_TF_Data) {
    /* SignalConversion generated from: '<S299>/vel_D_mPs' incorporates:
     *  Constant: '<S299>/Constant'
     */
    *rty_vel_D_mPs = localP->Constant_Value;
  }

  /* End of Outputs for SubSystem: '<S294>/Baro_Velocity' */
}

/* Model step function */
void ATTR_TCM_SECTION INS_step(void)
{
  real_T rtb_DataTypeConversion1;
  real_T rtb_DataTypeConversion2;
  real_T rtb_Scalefactor1;
  real_T rtb_Scalefactor2;
  real_T rtb_Scalefactor3;
  real_T rtb_Switch1_idx_1;
  real_T rtb_Switch4_c_idx_0;
  real_T rtb_Switch4_c_idx_1;
  real_T rtb_ff;
  int32_T rtb_Compare_he_tmp;
  int32_T rtb_MathFunction1_tmp;
  int32_T rtb_Saturation1_j_idx_0;
  int32_T rtb_Saturation1_j_idx_1;
  real32_T rtb_M_BO_c[9];
  real32_T rtb_M_OC[9];
  real32_T rtb_VectorConcatenate_c2[9];
  real32_T rtb_VectorConcatenate_g[9];
  real32_T rtb_Sum_g0[6];
  real32_T rtb_Switch_dh[6];
  real32_T tmp[6];
  real32_T rtb_Gauss_to_uT[3];
  real32_T rtb_MathFunction[3];
  real32_T rtb_MathFunction_j[3];
  real32_T rtb_Multiply_me[3];
  real32_T rtb_Product8[3];
  real32_T rtb_Reshape_k[3];
  real32_T rtb_VectorConcatenate1[3];
  real32_T rtb_ba_mPs2[3];
  real32_T Constant_Value_b;
  real32_T rtb_DataTypeConversion_l_idx_0;
  real32_T rtb_DiscreteTimeIntegrator1_p_i;
  real32_T rtb_DiscreteTimeIntegrator_bq;
  real32_T rtb_DiscreteTimeIntegrator_eh;
  real32_T rtb_DiscreteTimeIntegrator_g;
  real32_T rtb_DiscreteTimeIntegrator_nt;
  real32_T rtb_Divide1;
  real32_T rtb_Gain1_k;
  real32_T rtb_Gain1_n_idx_0;
  real32_T rtb_Gain1_n_idx_1;
  real32_T rtb_Gain1_n_idx_2;
  real32_T rtb_Gain2_a;
  real32_T rtb_Gain_ca_idx_0;
  real32_T rtb_Gain_ca_idx_1;
  real32_T rtb_Gain_ca_idx_2;
  real32_T rtb_Gain_ok;
  real32_T rtb_MathFunction1;
  real32_T rtb_Memory_m_idx_0;
  real32_T rtb_Memory_m_idx_1;
  real32_T rtb_Relay;
  real32_T rtb_Saturation_a;
  real32_T rtb_Sum2_by;
  real32_T rtb_Sum2_m;
  real32_T rtb_Switch_dy_idx_1;
  real32_T rtb_Switch_dy_idx_2;
  real32_T rtb_Switch_kj_0;
  real32_T rtb_Switch_kj_idx_0;
  real32_T rtb_Switch_kj_idx_1;
  real32_T rtb_Switch_kj_idx_2;
  real32_T rtb_VectorConcatenate_idx_0;
  real32_T rtb_VectorConcatenate_idx_1;
  real32_T rtb_mag_valid;
  real32_T u0;
  real32_T u0_0;
  uint32_T rtb_Saturation_mp;
  uint32_T rtb_Sum1;
  uint32_T rtb_Sum1_o;
  uint16_T rtb_Multiply_cb;
  uint16_T rtb_Multiply_gs;
  uint16_T rtb_Multiply_jy;
  uint16_T rtb_Multiply_o;
  int8_T rtb_DataTypeConversion1_m;
  int8_T rtb_DataTypeConversion2_h;
  int8_T rtb_DataTypeConversion_k_tmp;
  int8_T u0_1;
  uint8_T rtb_Switch_pt;
  uint8_T rtb_Uk1_m2;
  boolean_T rtb_Compare_a2;
  boolean_T rtb_Compare_ai;
  boolean_T rtb_Compare_ay;
  boolean_T rtb_Compare_c5;
  boolean_T rtb_Compare_ce;
  boolean_T rtb_Compare_cio;
  boolean_T rtb_Compare_cj;
  boolean_T rtb_Compare_d;
  boolean_T rtb_Compare_d3;
  boolean_T rtb_Compare_e0;
  boolean_T rtb_Compare_eh1;
  boolean_T rtb_Compare_fc;
  boolean_T rtb_Compare_fg;
  boolean_T rtb_Compare_fo;
  boolean_T rtb_Compare_g;
  boolean_T rtb_Compare_ir;
  boolean_T rtb_Compare_j;
  boolean_T rtb_Compare_n1;
  boolean_T rtb_Compare_o;
  boolean_T rtb_Compare_od;
  boolean_T rtb_FixPtRelationalOperator_cn;
  boolean_T rtb_FixPtRelationalOperator_fr;
  boolean_T rtb_FixPtRelationalOperator_nc;
  boolean_T rtb_FixPtRelationalOperator_p;
  boolean_T rtb_LogicalOperator1_ao;
  boolean_T rtb_LogicalOperator1_cc;
  boolean_T rtb_LogicalOperator1_f1;
  boolean_T rtb_LogicalOperator1_nd;
  boolean_T rtb_LogicalOperator1_ng;
  boolean_T rtb_LogicalOperator2_g;
  boolean_T rtb_LogicalOperator3;
  boolean_T rtb_LogicalOperator5;
  boolean_T rtb_LogicalOperator5_i;
  boolean_T rtb_Switch_g3;
  boolean_T rtb_WGS84_pos_valid;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
  /* Outputs for Atomic SubSystem: '<S3>/Baro_PreProcess' */
  /* Product: '<S397>/Divide' incorporates:
   *  Constant: '<S397>/p1'
   *  Gain: '<S397>/Gain1'
   *  Inport: '<Root>/Barometer'
   */
  rtb_DiscreteTimeIntegrator_g = INS_P.Gain1_Gain_a * INS_U.Barometer.pressure /
    INS_P.p1_Value;

  /* Math: '<S397>/Power' incorporates:
   *  Constant: '<S397>/aR_g'
   */
  if ((rtb_DiscreteTimeIntegrator_g < 0.0F) && (INS_P.aR_g_Value > floorf
       (INS_P.aR_g_Value))) {
    rtb_Gain1_n_idx_0 = -powf(-rtb_DiscreteTimeIntegrator_g, INS_P.aR_g_Value);
  } else {
    rtb_Gain1_n_idx_0 = powf(rtb_DiscreteTimeIntegrator_g, INS_P.aR_g_Value);
  }

  /* Product: '<S397>/Divide1' incorporates:
   *  Constant: '<S397>/T1'
   *  Constant: '<S397>/a'
   *  Math: '<S397>/Power'
   *  Product: '<S397>/Multiply'
   *  Sum: '<S397>/Subtract'
   */
  rtb_Divide1 = (rtb_Gain1_n_idx_0 * INS_P.T1_Value - INS_P.T1_Value) /
    INS_P.a_Value;

  /* DiscreteIntegrator: '<S399>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/Barometer'
   *  RelationalOperator: '<S406>/FixPt Relational Operator'
   *  UnitDelay: '<S406>/Delay Input1'
   */
  if (INS_U.Barometer.timestamp != INS_DWork.DelayInput1_DSTATE_c) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_nm =
      INS_P.DiscreteTimeIntegrator_IC_iu;

    /* Switch: '<S407>/Switch' incorporates:
     *  Constant: '<S407>/Constant1'
     *  DiscreteIntegrator: '<S399>/Discrete-Time Integrator'
     */
    rtb_Switch_pt = INS_P.Constant1_Value_bj;
  } else {
    /* Switch: '<S407>/Switch' incorporates:
     *  Delay: '<S407>/Delay'
     */
    rtb_Switch_pt = INS_DWork.Delay_DSTATE_i1;
  }

  /* Logic: '<S399>/Logical Operator1' incorporates:
   *  Constant: '<S405>/Constant'
   *  Constant: '<S408>/Lower Limit'
   *  Constant: '<S408>/Upper Limit'
   *  Constant: '<S409>/Lower Limit'
   *  Constant: '<S409>/Upper Limit'
   *  DiscreteIntegrator: '<S399>/Discrete-Time Integrator'
   *  Inport: '<Root>/Barometer'
   *  Logic: '<S399>/Logical Operator'
   *  Logic: '<S408>/AND'
   *  Logic: '<S409>/AND'
   *  RelationalOperator: '<S405>/Compare'
   *  RelationalOperator: '<S408>/Lower Test'
   *  RelationalOperator: '<S408>/Upper Test'
   *  RelationalOperator: '<S409>/Lower Test'
   *  RelationalOperator: '<S409>/Upper Test'
   */
  rtb_WGS84_pos_valid = ((INS_P.Sensor_Valid_min_pressure <
    INS_U.Barometer.pressure) && (INS_U.Barometer.pressure <
    INS_P.Sensor_Valid_max_pressure) && ((INS_P.Sensor_Valid_min_temp <
    INS_U.Barometer.temperature) && (INS_U.Barometer.temperature <
    INS_P.Sensor_Valid_max_temp)) && (INS_DWork.DiscreteTimeIntegrator_DSTAT_nm <
    INS_P.Sensor_Valid_timeout) && (rtb_Switch_pt != 0));

  /* Sum: '<S401>/Sum1' incorporates:
   *  Inport: '<Root>/Barometer'
   *  Logic: '<S401>/Logical Operator5'
   *  RelationalOperator: '<S403>/FixPt Relational Operator'
   *  UnitDelay: '<S403>/Delay Input1'
   */
  rtb_Saturation1_j_idx_1 = ((INS_U.Barometer.timestamp !=
    INS_DWork.DelayInput1_DSTATE_g) && rtb_WGS84_pos_valid);

  /* Saturate: '<S401>/Saturation' incorporates:
   *  Delay: '<S401>/Delay'
   */
  if (INS_DWork.Delay_DSTATE_fy > INS_P.Saturation_UpperSat_f) {
    rtb_Sum1_o = INS_P.Saturation_UpperSat_f;
  } else if (INS_DWork.Delay_DSTATE_fy < INS_P.Saturation_LowerSat_pw) {
    rtb_Sum1_o = INS_P.Saturation_LowerSat_pw;
  } else {
    rtb_Sum1_o = INS_DWork.Delay_DSTATE_fy;
  }

  /* Sum: '<S401>/Sum1' incorporates:
   *  Saturate: '<S401>/Saturation'
   */
  rtb_Sum1 = (uint32_T)rtb_Saturation1_j_idx_1 + rtb_Sum1_o;
  if (rtb_Sum1 < (uint32_T)rtb_Saturation1_j_idx_1) {
    rtb_Sum1 = MAX_uint32_T;
  }

  /* Logic: '<S398>/Logical Operator' incorporates:
   *  Constant: '<S402>/Constant'
   *  RelationalOperator: '<S402>/Compare'
   *  Sum: '<S401>/Sum1'
   */
  rtb_FixPtRelationalOperator_cn = ((rtb_Sum1 > INS_P.CompareToConstant_const_nb)
    && rtb_WGS84_pos_valid);

  /* Outputs for Enabled SubSystem: '<S398>/Reference_Height' incorporates:
   *  EnablePort: '<S400>/Enable'
   */
  /* Logic: '<S404>/AND' incorporates:
   *  Constant: '<S404>/Lower Limit'
   *  Constant: '<S404>/Upper Limit'
   *  RelationalOperator: '<S404>/Lower Test'
   *  RelationalOperator: '<S404>/Upper Test'
   *  Sum: '<S401>/Sum1'
   */
  if ((INS_P.IntervalTest3_lowlimit < rtb_Sum1) && (rtb_Sum1 <
       INS_P.IntervalTest3_uplimit)) {
    if (!INS_DWork.Reference_Height_MODE) {
      /* InitializeConditions for Delay: '<S400>/Delay' */
      INS_DWork.Delay_DSTATE_d = INS_P.Delay_InitialCondition_p;

      /* InitializeConditions for Delay: '<S400>/Delay1' */
      INS_DWork.Delay1_DSTATE_i = INS_P.Delay1_InitialCondition_k;
      INS_DWork.Reference_Height_MODE = true;
    }

    /* Sum: '<S400>/Sum2' incorporates:
     *  Delay: '<S400>/Delay'
     */
    rtb_Sum2_by = rtb_Divide1 + INS_DWork.Delay_DSTATE_d;

    /* Sum: '<S400>/Sum1' incorporates:
     *  Constant: '<S400>/Constant1'
     *  Delay: '<S400>/Delay1'
     */
    rtb_Saturation_mp = INS_P.Constant1_Value_f + INS_DWork.Delay1_DSTATE_i;
    if (rtb_Saturation_mp < INS_P.Constant1_Value_f) {
      rtb_Saturation_mp = MAX_uint32_T;
    }

    /* Saturate: '<S400>/Saturation1' incorporates:
     *  Sum: '<S400>/Sum1'
     */
    if (rtb_Saturation_mp > INS_P.Saturation1_UpperSat_n) {
      rtb_Sum1_o = INS_P.Saturation1_UpperSat_n;
    } else if (rtb_Saturation_mp < INS_P.Saturation1_LowerSat_m) {
      rtb_Sum1_o = INS_P.Saturation1_LowerSat_m;
    } else {
      rtb_Sum1_o = rtb_Saturation_mp;
    }

    /* Product: '<S400>/Divide' incorporates:
     *  Saturate: '<S400>/Saturation1'
     */
    INS_B.Divide = rtb_Sum2_by / (real32_T)rtb_Sum1_o;

    /* Update for Delay: '<S400>/Delay' */
    INS_DWork.Delay_DSTATE_d = rtb_Sum2_by;

    /* Update for Delay: '<S400>/Delay1' incorporates:
     *  Sum: '<S400>/Sum1'
     */
    INS_DWork.Delay1_DSTATE_i = rtb_Saturation_mp;
  } else {
    INS_DWork.Reference_Height_MODE = false;
  }

  /* End of Logic: '<S404>/AND' */
  /* End of Outputs for SubSystem: '<S398>/Reference_Height' */

  /* Switch: '<S398>/Switch' */
  if (rtb_FixPtRelationalOperator_cn) {
    rtb_Gain1_n_idx_0 = INS_B.Divide;
  } else {
    rtb_Gain1_n_idx_0 = rtb_Divide1;
  }

  /* Sum: '<S398>/Sum2' incorporates:
   *  Switch: '<S398>/Switch'
   */
  rtb_Sum2_m = rtb_Divide1 - rtb_Gain1_n_idx_0;

  /* Update for UnitDelay: '<S403>/Delay Input1' incorporates:
   *  Inport: '<Root>/Barometer'
   */
  INS_DWork.DelayInput1_DSTATE_g = INS_U.Barometer.timestamp;

  /* Update for UnitDelay: '<S406>/Delay Input1' incorporates:
   *  Inport: '<Root>/Barometer'
   */
  INS_DWork.DelayInput1_DSTATE_c = INS_U.Barometer.timestamp;

  /* Update for DiscreteIntegrator: '<S399>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S399>/Constant'
   */
  if (INS_EXPORT.period < 4.2949673E+9F) {
    rtb_Sum1_o = (uint32_T)(real32_T)INS_EXPORT.period;
  } else {
    rtb_Sum1_o = MAX_uint32_T;
  }

  rtb_Saturation_mp = INS_DWork.DiscreteTimeIntegrator_DSTAT_nm + rtb_Sum1_o;
  if (rtb_Saturation_mp < INS_DWork.DiscreteTimeIntegrator_DSTAT_nm) {
    rtb_Saturation_mp = MAX_uint32_T;
  }

  INS_DWork.DiscreteTimeIntegrator_DSTAT_nm = rtb_Saturation_mp;

  /* End of Update for DiscreteIntegrator: '<S399>/Discrete-Time Integrator' */

  /* Update for Delay: '<S407>/Delay' */
  INS_DWork.Delay_DSTATE_i1 = rtb_Switch_pt;

  /* Update for Delay: '<S401>/Delay' incorporates:
   *  Sum: '<S401>/Sum1'
   */
  INS_DWork.Delay_DSTATE_fy = rtb_Sum1;

  /* End of Outputs for SubSystem: '<S3>/Baro_PreProcess' */

  /* Outputs for Atomic SubSystem: '<S3>/ExternalPos_Process' */
  /* DiscreteIntegrator: '<S411>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/External_Pos'
   *  RelationalOperator: '<S413>/FixPt Relational Operator'
   *  UnitDelay: '<S413>/Delay Input1'
   */
  if (INS_U.External_Pos.timestamp != INS_DWork.DelayInput1_DSTATE_b) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_nj =
      INS_P.DiscreteTimeIntegrator_IC_jj;

    /* Switch: '<S414>/Switch' incorporates:
     *  Constant: '<S414>/Constant1'
     *  DiscreteIntegrator: '<S411>/Discrete-Time Integrator'
     */
    rtb_Switch_pt = INS_P.Constant1_Value_ns;
  } else {
    /* Switch: '<S414>/Switch' incorporates:
     *  Delay: '<S414>/Delay'
     */
    rtb_Switch_pt = INS_DWork.Delay_DSTATE_g;
  }

  /* Logic: '<S411>/Logical Operator1' incorporates:
   *  Constant: '<S412>/Constant'
   *  DiscreteIntegrator: '<S411>/Discrete-Time Integrator'
   *  RelationalOperator: '<S412>/Compare'
   */
  rtb_WGS84_pos_valid = ((INS_DWork.DiscreteTimeIntegrator_DSTAT_nj <
    INS_P.Sensor_Valid_timeout_e) && (rtb_Switch_pt != 0));

  /* Logic: '<S411>/Logical Operator2' incorporates:
   *  Inport: '<Root>/External_Pos'
   *  S-Function (sfix_bitop): '<S411>/xy valid'
   */
  rtb_LogicalOperator2_g = (rtb_WGS84_pos_valid &&
    ((INS_U.External_Pos.field_valid & INS_P.xyvalid_BitMask) != 0U));

  /* Logic: '<S411>/Logical Operator3' incorporates:
   *  Inport: '<Root>/External_Pos'
   *  S-Function (sfix_bitop): '<S411>/height valid'
   */
  rtb_LogicalOperator3 = (rtb_WGS84_pos_valid &&
    ((INS_U.External_Pos.field_valid & INS_P.heightvalid_BitMask) != 0U));

  /* Logic: '<S411>/Logical Operator5' incorporates:
   *  Inport: '<Root>/External_Pos'
   *  S-Function (sfix_bitop): '<S411>/heading valid'
   */
  rtb_LogicalOperator5 = (rtb_WGS84_pos_valid &&
    ((INS_U.External_Pos.field_valid & INS_P.headingvalid_BitMask) != 0U));

  /* Update for UnitDelay: '<S413>/Delay Input1' incorporates:
   *  Inport: '<Root>/External_Pos'
   */
  INS_DWork.DelayInput1_DSTATE_b = INS_U.External_Pos.timestamp;

  /* Update for DiscreteIntegrator: '<S411>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S411>/Constant'
   */
  if (INS_EXPORT.period < 4.2949673E+9F) {
    rtb_Sum1_o = (uint32_T)(real32_T)INS_EXPORT.period;
  } else {
    rtb_Sum1_o = MAX_uint32_T;
  }

  rtb_Sum1 = INS_DWork.DiscreteTimeIntegrator_DSTAT_nj + rtb_Sum1_o;
  if (rtb_Sum1 < INS_DWork.DiscreteTimeIntegrator_DSTAT_nj) {
    rtb_Sum1 = MAX_uint32_T;
  }

  INS_DWork.DiscreteTimeIntegrator_DSTAT_nj = rtb_Sum1;

  /* End of Update for DiscreteIntegrator: '<S411>/Discrete-Time Integrator' */

  /* Update for Delay: '<S414>/Delay' */
  INS_DWork.Delay_DSTATE_g = rtb_Switch_pt;

  /* End of Outputs for SubSystem: '<S3>/ExternalPos_Process' */

  /* Outputs for Atomic SubSystem: '<S3>/GPS_PreProcess' */
  /* RelationalOperator: '<S429>/Compare' incorporates:
   *  Constant: '<S429>/Constant'
   *  UnitDelay: '<S428>/Unit Delay'
   */
  rtb_WGS84_pos_valid = (INS_DWork.UnitDelay_DSTATE >= INS_P.valid_samples_const);

  /* RelationalOperator: '<S427>/Compare' incorporates:
   *  Constant: '<S427>/Constant'
   *  Inport: '<Root>/GPS_uBlox'
   */
  rtb_Switch_pt = (uint8_T)(INS_U.GPS_uBlox.fixType >=
    INS_P.CompareToConstant1_const_n);

  /* DiscreteIntegrator: '<S422>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/GPS_uBlox'
   *  RelationalOperator: '<S431>/FixPt Relational Operator'
   *  UnitDelay: '<S431>/Delay Input1'
   */
  if (INS_U.GPS_uBlox.timestamp != INS_DWork.DelayInput1_DSTATE_i) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_i =
      INS_P.DiscreteTimeIntegrator_IC_p;
  }

  /* RelationalOperator: '<S430>/Compare' incorporates:
   *  Constant: '<S430>/Constant'
   *  DiscreteIntegrator: '<S422>/Discrete-Time Integrator'
   */
  rtb_FixPtRelationalOperator_nc = (INS_DWork.DiscreteTimeIntegrator_DSTATE_i <
    INS_P.CompareToConstant4_const_e);

  /* Sum: '<S421>/Sum1' incorporates:
   *  Logic: '<S421>/Logical Operator1'
   */
  rtb_Uk1_m2 = (uint8_T)((uint32_T)(rtb_WGS84_pos_valid && (rtb_Switch_pt != 0) &&
    rtb_FixPtRelationalOperator_nc) + rtb_WGS84_pos_valid);

  /* RelationalOperator: '<S415>/Compare' incorporates:
   *  Constant: '<S415>/Constant'
   */
  rtb_Compare_c5 = (rtb_Uk1_m2 > INS_P.CompareToConstant_const_i);

  /* RelationalOperator: '<S416>/Compare' incorporates:
   *  Constant: '<S416>/Constant'
   */
  rtb_Compare_cio = (rtb_Uk1_m2 == INS_P.CompareToConstant1_const_la);

  /* Gain: '<S417>/Gain' incorporates:
   *  Inport: '<Root>/GPS_uBlox'
   */
  rtb_Gain_ok = (real32_T)INS_P.Gain_Gain * 9.09494702E-13F * (real32_T)
    INS_U.GPS_uBlox.velN;

  /* Gain: '<S417>/Gain1' incorporates:
   *  Inport: '<Root>/GPS_uBlox'
   */
  rtb_Gain1_k = (real32_T)INS_P.Gain1_Gain * 9.09494702E-13F * (real32_T)
    INS_U.GPS_uBlox.velE;

  /* Gain: '<S417>/Gain2' incorporates:
   *  Inport: '<Root>/GPS_uBlox'
   */
  rtb_Gain2_a = (real32_T)INS_P.Gain2_Gain * 9.09494702E-13F * (real32_T)
    INS_U.GPS_uBlox.velD;

  /* Gain: '<S417>/Scalefactor1' incorporates:
   *  Inport: '<Root>/GPS_uBlox'
   */
  rtb_Scalefactor1 = (real_T)INS_P.Scalefactor1_Gain * 8.6736173798840355E-19 *
    (real_T)INS_U.GPS_uBlox.lat;

  /* Gain: '<S417>/Scalefactor2' incorporates:
   *  Inport: '<Root>/GPS_uBlox'
   */
  rtb_Scalefactor2 = (real_T)INS_P.Scalefactor2_Gain * 8.6736173798840355E-19 *
    (real_T)INS_U.GPS_uBlox.lon;

  /* Gain: '<S417>/Scalefactor3' incorporates:
   *  Inport: '<Root>/GPS_uBlox'
   */
  rtb_Scalefactor3 = (real_T)INS_P.Scalefactor3_Gain * 9.0949470177292824E-13 *
    (real_T)INS_U.GPS_uBlox.height;

  /* RelationalOperator: '<S420>/Compare' incorporates:
   *  Constant: '<S420>/Constant'
   */
  rtb_WGS84_pos_valid = (rtb_Uk1_m2 == INS_P.CompareToConstant2_const_bv);

  /* Gain: '<S423>/Gain2' incorporates:
   *  Constant: '<S423>/Constant1'
   *  Gain: '<S423>/Gain1'
   *  Inport: '<Root>/GPS_uBlox'
   *  Sum: '<S423>/Sum1'
   */
  rtb_DiscreteTimeIntegrator_g = (INS_PARAM.GPS_HOR_Q_BIAS - (real32_T)
    INS_P.Gain1_Gain_po * 4.54747351E-13F * (real32_T)INS_U.GPS_uBlox.hAcc) *
    INS_PARAM.GPS_HOR_Q_SCALE;

  /* Saturate: '<S423>/Saturation1' */
  if (rtb_DiscreteTimeIntegrator_g > INS_P.Saturation1_UpperSat_m) {
    rtb_DiscreteTimeIntegrator_g = INS_P.Saturation1_UpperSat_m;
  } else if (rtb_DiscreteTimeIntegrator_g < INS_P.Saturation1_LowerSat_d) {
    rtb_DiscreteTimeIntegrator_g = INS_P.Saturation1_LowerSat_d;
  }

  /* End of Saturate: '<S423>/Saturation1' */

  /* DiscreteIntegrator: '<S432>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S432>/Constant'
   */
  if (INS_DWork.DiscreteTimeIntegrator1_IC_LO_j != 0) {
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_g = rtb_DiscreteTimeIntegrator_g;
  }

  if ((INS_P.Constant_Value_n5 != 0.0F) ||
      (INS_DWork.DiscreteTimeIntegrator1_PrevR_l != 0)) {
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_g = rtb_DiscreteTimeIntegrator_g;
  }

  /* Product: '<S418>/Product' incorporates:
   *  DiscreteIntegrator: '<S432>/Discrete-Time Integrator1'
   */
  rtb_Divide1 = rtb_WGS84_pos_valid ? rtb_FixPtRelationalOperator_nc ?
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_g : 0.0F : 0.0F;

  /* Gain: '<S424>/Gain3' incorporates:
   *  Constant: '<S424>/Constant7'
   *  Gain: '<S424>/Gain5'
   *  Inport: '<Root>/GPS_uBlox'
   *  Sum: '<S424>/Sum'
   */
  rtb_Saturation_a = (INS_PARAM.GPS_VEL_Q_BIAS - (real32_T)INS_P.Gain5_Gain *
                      4.54747351E-13F * (real32_T)INS_U.GPS_uBlox.sAcc) *
    INS_PARAM.GPS_VEL_Q_SCALE;

  /* Saturate: '<S424>/Saturation' */
  if (rtb_Saturation_a > INS_P.Saturation_UpperSat_l) {
    rtb_Saturation_a = INS_P.Saturation_UpperSat_l;
  } else if (rtb_Saturation_a < INS_P.Saturation_LowerSat_ku) {
    rtb_Saturation_a = INS_P.Saturation_LowerSat_ku;
  }

  /* End of Saturate: '<S424>/Saturation' */

  /* DiscreteIntegrator: '<S433>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S433>/Constant'
   */
  if (INS_DWork.DiscreteTimeIntegrator1_IC_LO_e != 0) {
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_m = rtb_Saturation_a;
  }

  if ((INS_P.Constant_Value_k != 0.0F) ||
      (INS_DWork.DiscreteTimeIntegrator1_PrevR_j != 0)) {
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_m = rtb_Saturation_a;
  }

  /* Product: '<S418>/Product2' incorporates:
   *  DiscreteIntegrator: '<S433>/Discrete-Time Integrator1'
   */
  rtb_Sum2_by = rtb_WGS84_pos_valid ? rtb_FixPtRelationalOperator_nc ?
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_m : 0.0F : 0.0F;

  /* DiscreteIntegrator: '<S432>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S432>/Constant'
   */
  if ((INS_P.Constant_Value_n5 != 0.0F) ||
      (INS_DWork.DiscreteTimeIntegrator_PrevRe_a != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k =
      INS_P.DiscreteTimeIntegrator_IC_d;
  }

  /* Gain: '<S432>/Gain' incorporates:
   *  DiscreteIntegrator: '<S432>/Discrete-Time Integrator1'
   *  Sum: '<S432>/Sum'
   */
  rtb_DiscreteTimeIntegrator_g = (rtb_DiscreteTimeIntegrator_g -
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_g) * INS_P.Gain_Gain_j2;

  /* DiscreteIntegrator: '<S433>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S433>/Constant'
   */
  if ((INS_P.Constant_Value_k != 0.0F) ||
      (INS_DWork.DiscreteTimeIntegrator_PrevRe_j != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_l =
      INS_P.DiscreteTimeIntegrator_IC_f;
  }

  /* Gain: '<S433>/Gain' incorporates:
   *  DiscreteIntegrator: '<S433>/Discrete-Time Integrator1'
   *  Sum: '<S433>/Sum'
   */
  rtb_Saturation_a = (rtb_Saturation_a -
                      INS_DWork.DiscreteTimeIntegrator1_DSTAT_m) *
    INS_P.Gain_Gain_gh;

  /* Outputs for Triggered SubSystem: '<S391>/WGS84_Model' incorporates:
   *  TriggerPort: '<S419>/Trigger'
   */
  if (rtb_Compare_c5 && (INS_PrevZCSigState.WGS84_Model_Trig_ZCE != POS_ZCSIG))
  {
    /* DataTypeConversion: '<S419>/Data Type Conversion' */
    INS_B.DataTypeConversion = rtb_Scalefactor2;

    /* DataTypeConversion: '<S419>/Data Type Conversion1' */
    INS_B.DataTypeConversion1 = rtb_Scalefactor1;

    /* Product: '<S435>/Multiply3' incorporates:
     *  Constant: '<S435>/Constant2'
     *  Constant: '<S435>/f'
     *  Sum: '<S435>/Sum'
     */
    rtb_ff = (INS_P.Constant2_Value - INS_P.f_Value) * INS_P.f_Value;

    /* Trigonometry: '<S435>/Sin' */
    rtb_DataTypeConversion1 = sin(INS_B.DataTypeConversion1);

    /* Product: '<S435>/Multiply' incorporates:
     *  Math: '<S435>/Square1'
     *  Product: '<S435>/Multiply1'
     */
    rtb_DataTypeConversion1 = rtb_DataTypeConversion1 * rtb_DataTypeConversion1 *
      rtb_ff;

    /* Product: '<S435>/Divide' incorporates:
     *  Constant: '<S435>/Constant'
     *  Constant: '<S435>/R'
     *  Product: '<S435>/Multiply'
     *  Sqrt: '<S435>/Sqrt'
     *  Sum: '<S435>/Sum1'
     */
    rtb_DataTypeConversion2 = INS_P.R_Value / sqrt(INS_P.Constant_Value_n -
      rtb_DataTypeConversion1);

    /* Product: '<S435>/Multiply2' incorporates:
     *  Trigonometry: '<S435>/Cos'
     */
    INS_B.Multiply2 = rtb_DataTypeConversion2 * cos(INS_B.DataTypeConversion1);

    /* Product: '<S435>/Product3' incorporates:
     *  Constant: '<S435>/Constant1'
     *  Sum: '<S435>/Sum2'
     *  Sum: '<S435>/Sum4'
     */
    INS_B.Rm = 1.0 / (INS_P.Constant1_Value - rtb_DataTypeConversion1) *
      (INS_P.Constant1_Value - rtb_ff) * rtb_DataTypeConversion2;
  }

  INS_PrevZCSigState.WGS84_Model_Trig_ZCE = rtb_Compare_c5;

  /* End of Outputs for SubSystem: '<S391>/WGS84_Model' */

  /* Sum: '<S428>/Sum' incorporates:
   *  Constant: '<S426>/Constant'
   *  Inport: '<Root>/GPS_uBlox'
   *  Logic: '<S421>/Logical Operator'
   *  RelationalOperator: '<S426>/Compare'
   *  UnitDelay: '<S428>/Unit Delay'
   */
  rtb_Saturation1_j_idx_1 = ((INS_U.GPS_uBlox.hAcc <
    INS_P.CompareToConstant_const_d) && (rtb_Switch_pt != 0) &&
    rtb_FixPtRelationalOperator_nc) + INS_DWork.UnitDelay_DSTATE;

  /* Saturate: '<S428>/Saturation' */
  if (rtb_Saturation1_j_idx_1 > INS_P.Saturation_UpperSat_a) {
    /* Update for UnitDelay: '<S428>/Unit Delay' */
    INS_DWork.UnitDelay_DSTATE = INS_P.Saturation_UpperSat_a;
  } else if (rtb_Saturation1_j_idx_1 < INS_P.Saturation_LowerSat_f) {
    /* Update for UnitDelay: '<S428>/Unit Delay' */
    INS_DWork.UnitDelay_DSTATE = INS_P.Saturation_LowerSat_f;
  } else {
    /* Update for UnitDelay: '<S428>/Unit Delay' */
    INS_DWork.UnitDelay_DSTATE = rtb_Saturation1_j_idx_1;
  }

  /* End of Saturate: '<S428>/Saturation' */

  /* Update for UnitDelay: '<S431>/Delay Input1' incorporates:
   *  Inport: '<Root>/GPS_uBlox'
   */
  INS_DWork.DelayInput1_DSTATE_i = INS_U.GPS_uBlox.timestamp;

  /* Update for DiscreteIntegrator: '<S422>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S422>/Constant'
   */
  if (INS_EXPORT.period < 4.2949673E+9F) {
    rtb_Sum1_o = (uint32_T)(real32_T)INS_EXPORT.period;
  } else {
    rtb_Sum1_o = MAX_uint32_T;
  }

  rtb_Sum1 = INS_DWork.DiscreteTimeIntegrator_DSTATE_i + rtb_Sum1_o;
  if (rtb_Sum1 < INS_DWork.DiscreteTimeIntegrator_DSTATE_i) {
    rtb_Sum1 = MAX_uint32_T;
  }

  INS_DWork.DiscreteTimeIntegrator_DSTATE_i = rtb_Sum1;

  /* End of Update for DiscreteIntegrator: '<S422>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S432>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S432>/Constant'
   *  DiscreteIntegrator: '<S432>/Discrete-Time Integrator'
   */
  INS_DWork.DiscreteTimeIntegrator1_IC_LO_j = 0U;
  INS_DWork.DiscreteTimeIntegrator1_DSTAT_g +=
    INS_P.DiscreteTimeIntegrator1_gainv_b *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k;
  if (INS_P.Constant_Value_n5 > 0.0F) {
    INS_DWork.DiscreteTimeIntegrator1_PrevR_l = 1;
  } else if (INS_P.Constant_Value_n5 < 0.0F) {
    INS_DWork.DiscreteTimeIntegrator1_PrevR_l = -1;
  } else if (INS_P.Constant_Value_n5 == 0.0F) {
    INS_DWork.DiscreteTimeIntegrator1_PrevR_l = 0;
  } else {
    INS_DWork.DiscreteTimeIntegrator1_PrevR_l = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S432>/Discrete-Time Integrator1' */

  /* Update for DiscreteIntegrator: '<S433>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S433>/Constant'
   *  DiscreteIntegrator: '<S433>/Discrete-Time Integrator'
   */
  INS_DWork.DiscreteTimeIntegrator1_IC_LO_e = 0U;
  INS_DWork.DiscreteTimeIntegrator1_DSTAT_m +=
    INS_P.DiscreteTimeIntegrator1_gainv_e *
    INS_DWork.DiscreteTimeIntegrator_DSTATE_l;
  if (INS_P.Constant_Value_k > 0.0F) {
    INS_DWork.DiscreteTimeIntegrator1_PrevR_j = 1;
  } else if (INS_P.Constant_Value_k < 0.0F) {
    INS_DWork.DiscreteTimeIntegrator1_PrevR_j = -1;
  } else if (INS_P.Constant_Value_k == 0.0F) {
    INS_DWork.DiscreteTimeIntegrator1_PrevR_j = 0;
  } else {
    INS_DWork.DiscreteTimeIntegrator1_PrevR_j = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S433>/Discrete-Time Integrator1' */

  /* Update for DiscreteIntegrator: '<S432>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S432>/Constant'
   *  Gain: '<S432>/Gain1'
   *  Sum: '<S432>/Sum2'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_k += (rtb_DiscreteTimeIntegrator_g -
    INS_P.Gain1_Gain_kf * INS_DWork.DiscreteTimeIntegrator_DSTATE_k) *
    INS_P.DiscreteTimeIntegrator_gainva_g;
  if (INS_P.Constant_Value_n5 > 0.0F) {
    INS_DWork.DiscreteTimeIntegrator_PrevRe_a = 1;
  } else if (INS_P.Constant_Value_n5 < 0.0F) {
    INS_DWork.DiscreteTimeIntegrator_PrevRe_a = -1;
  } else if (INS_P.Constant_Value_n5 == 0.0F) {
    INS_DWork.DiscreteTimeIntegrator_PrevRe_a = 0;
  } else {
    INS_DWork.DiscreteTimeIntegrator_PrevRe_a = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S432>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S433>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S433>/Constant'
   *  Gain: '<S433>/Gain1'
   *  Sum: '<S433>/Sum2'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_l += (rtb_Saturation_a -
    INS_P.Gain1_Gain_cj * INS_DWork.DiscreteTimeIntegrator_DSTATE_l) *
    INS_P.DiscreteTimeIntegrator_gainv_mf;
  if (INS_P.Constant_Value_k > 0.0F) {
    INS_DWork.DiscreteTimeIntegrator_PrevRe_j = 1;
  } else if (INS_P.Constant_Value_k < 0.0F) {
    INS_DWork.DiscreteTimeIntegrator_PrevRe_j = -1;
  } else if (INS_P.Constant_Value_k == 0.0F) {
    INS_DWork.DiscreteTimeIntegrator_PrevRe_j = 0;
  } else {
    INS_DWork.DiscreteTimeIntegrator_PrevRe_j = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S433>/Discrete-Time Integrator' */
  /* End of Outputs for SubSystem: '<S3>/GPS_PreProcess' */

  /* Outputs for Atomic SubSystem: '<S3>/IMU_PreProcess' */
  /* SignalConversion generated from: '<S436>/Bus Selector1' incorporates:
   *  Inport: '<Root>/IMU'
   */
  rtb_VectorConcatenate1[0] = INS_U.IMU.acc_x;

  /* SignalConversion generated from: '<S436>/Bus Selector1' incorporates:
   *  Inport: '<Root>/IMU'
   */
  rtb_VectorConcatenate1[1] = INS_U.IMU.acc_y;

  /* SignalConversion generated from: '<S436>/Bus Selector1' incorporates:
   *  Inport: '<Root>/IMU'
   */
  rtb_VectorConcatenate1[2] = INS_U.IMU.acc_z;

  /* DiscreteIntegrator: '<S437>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/IMU'
   *  RelationalOperator: '<S439>/FixPt Relational Operator'
   *  UnitDelay: '<S439>/Delay Input1'
   */
  if (INS_U.IMU.timestamp != INS_DWork.DelayInput1_DSTATE_h) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_lp =
      INS_P.DiscreteTimeIntegrator_IC_ba;

    /* Switch: '<S440>/Switch' incorporates:
     *  Constant: '<S440>/Constant1'
     *  DiscreteIntegrator: '<S437>/Discrete-Time Integrator'
     */
    rtb_Switch_pt = INS_P.Constant1_Value_no;
  } else {
    /* Switch: '<S440>/Switch' incorporates:
     *  Delay: '<S440>/Delay'
     */
    rtb_Switch_pt = INS_DWork.Delay_DSTATE_bw;
  }

  /* Update for UnitDelay: '<S439>/Delay Input1' incorporates:
   *  Inport: '<Root>/IMU'
   */
  INS_DWork.DelayInput1_DSTATE_h = INS_U.IMU.timestamp;

  /* Update for Delay: '<S440>/Delay' */
  INS_DWork.Delay_DSTATE_bw = rtb_Switch_pt;

  /* End of Outputs for SubSystem: '<S3>/IMU_PreProcess' */

  /* Outputs for Atomic SubSystem: '<S3>/MAG_PreProcess' */
  /* Gain: '<S393>/Gauss_to_uT' incorporates:
   *  Inport: '<Root>/MAG'
   *  SignalConversion generated from: '<S443>/Vector Concatenate2'
   * */
  rtb_Gauss_to_uT[0] = INS_P.Gauss_to_uT_Gain * INS_U.MAG.mag_x;
  rtb_Gauss_to_uT[1] = INS_P.Gauss_to_uT_Gain * INS_U.MAG.mag_y;
  rtb_Gauss_to_uT[2] = INS_P.Gauss_to_uT_Gain * INS_U.MAG.mag_z;

  /* End of Outputs for SubSystem: '<S3>/MAG_PreProcess' */

  /* Outputs for Atomic SubSystem: '<S3>/IMU_PreProcess' */
  /* Logic: '<S437>/Logical Operator4' incorporates:
   *  Constant: '<S438>/Constant'
   *  Constant: '<S441>/Lower Limit'
   *  Constant: '<S441>/Upper Limit'
   *  Constant: '<S442>/Lower Limit'
   *  Constant: '<S442>/Upper Limit'
   *  DiscreteIntegrator: '<S437>/Discrete-Time Integrator'
   *  Inport: '<Root>/IMU'
   *  Logic: '<S437>/Logical Operator'
   *  Logic: '<S437>/Logical Operator1'
   *  Logic: '<S437>/Logical Operator2'
   *  Logic: '<S441>/AND'
   *  Logic: '<S442>/AND'
   *  RelationalOperator: '<S438>/Compare'
   *  RelationalOperator: '<S441>/Lower Test'
   *  RelationalOperator: '<S441>/Upper Test'
   *  RelationalOperator: '<S442>/Lower Test'
   *  RelationalOperator: '<S442>/Upper Test'
   *  SignalConversion generated from: '<S436>/Bus Selector1'
   * */
  rtb_FixPtRelationalOperator_nc = ((INS_P.Sensor_Valid_gyr_min <
    INS_U.IMU.gyr_x) && (INS_U.IMU.gyr_x < INS_P.Sensor_Valid_gyr_max) &&
    ((INS_P.Sensor_Valid_gyr_min < INS_U.IMU.gyr_y) && (INS_U.IMU.gyr_y <
    INS_P.Sensor_Valid_gyr_max)) && ((INS_P.Sensor_Valid_gyr_min <
    INS_U.IMU.gyr_z) && (INS_U.IMU.gyr_z < INS_P.Sensor_Valid_gyr_max)) &&
    ((INS_P.Sensor_Valid_acc_min < INS_U.IMU.acc_x) && (INS_U.IMU.acc_x <
    INS_P.Sensor_Valid_acc_max) && ((INS_P.Sensor_Valid_acc_min <
    INS_U.IMU.acc_y) && (INS_U.IMU.acc_y < INS_P.Sensor_Valid_acc_max)) &&
     ((INS_P.Sensor_Valid_acc_min < INS_U.IMU.acc_z) && (INS_U.IMU.acc_z <
    INS_P.Sensor_Valid_acc_max))) && (INS_DWork.DiscreteTimeIntegrator_DSTAT_lp <
    INS_P.Sensor_Valid_timeout_a) && (rtb_Switch_pt != 0));

  /* Update for DiscreteIntegrator: '<S437>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S437>/Constant'
   */
  if (INS_EXPORT.period < 4.2949673E+9F) {
    rtb_Sum1_o = (uint32_T)(real32_T)INS_EXPORT.period;
  } else {
    rtb_Sum1_o = MAX_uint32_T;
  }

  rtb_Sum1 = INS_DWork.DiscreteTimeIntegrator_DSTAT_lp + rtb_Sum1_o;
  if (rtb_Sum1 < INS_DWork.DiscreteTimeIntegrator_DSTAT_lp) {
    rtb_Sum1 = MAX_uint32_T;
  }

  INS_DWork.DiscreteTimeIntegrator_DSTAT_lp = rtb_Sum1;

  /* End of Update for DiscreteIntegrator: '<S437>/Discrete-Time Integrator' */
  /* End of Outputs for SubSystem: '<S3>/IMU_PreProcess' */

  /* Outputs for Atomic SubSystem: '<S3>/MAG_PreProcess' */
  /* Gain: '<S448>/rad_to_index' incorporates:
   *  SignalConversion generated from: '<S448>/rad_to_index'
   */
  rtb_ff = 57.295779513082323 / INS_P.WMM_LUT_resolution;
  rtb_DataTypeConversion1 = fmod(floor(rtb_ff * INS_B.DataTypeConversion1),
    4.294967296E+9);

  /* Sum: '<S448>/Add' incorporates:
   *  Constant: '<S448>/offset'
   *  Gain: '<S448>/rad_to_index'
   */
  rtb_Saturation1_j_idx_0 = (rtb_DataTypeConversion1 < 0.0 ? -(int32_T)(uint32_T)
    -rtb_DataTypeConversion1 : (int32_T)(uint32_T)rtb_DataTypeConversion1) +
    INS_P.offset_Value[0];

  /* Saturate: '<S448>/Saturation1' */
  if (rtb_Saturation1_j_idx_0 > INS_P.Saturation1_UpperSat[0]) {
    rtb_Saturation1_j_idx_0 = INS_P.Saturation1_UpperSat[0];
  } else if (rtb_Saturation1_j_idx_0 < INS_P.Saturation1_LowerSat) {
    rtb_Saturation1_j_idx_0 = INS_P.Saturation1_LowerSat;
  }

  /* Gain: '<S448>/rad_to_index' incorporates:
   *  SignalConversion generated from: '<S448>/rad_to_index'
   */
  rtb_DataTypeConversion1 = fmod(floor(rtb_ff * INS_B.DataTypeConversion),
    4.294967296E+9);

  /* Sum: '<S448>/Add' incorporates:
   *  Constant: '<S448>/offset'
   *  Gain: '<S448>/rad_to_index'
   */
  rtb_Saturation1_j_idx_1 = (rtb_DataTypeConversion1 < 0.0 ? -(int32_T)(uint32_T)
    -rtb_DataTypeConversion1 : (int32_T)(uint32_T)rtb_DataTypeConversion1) +
    INS_P.offset_Value[1];

  /* Saturate: '<S448>/Saturation1' */
  if (rtb_Saturation1_j_idx_1 > INS_P.Saturation1_UpperSat[1]) {
    rtb_Saturation1_j_idx_1 = INS_P.Saturation1_UpperSat[1];
  } else if (rtb_Saturation1_j_idx_1 < INS_P.Saturation1_LowerSat) {
    rtb_Saturation1_j_idx_1 = INS_P.Saturation1_LowerSat;
  }

  /* LookupNDDirect: '<S448>/Inclination_Lookup_Table'
   *
   * About '<S448>/Inclination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   *   */
  if (rtb_Saturation1_j_idx_1 > 36) {
    /* LookupNDDirect: '<S448>/Magnitude_Lookup_Table' incorporates:
     *  LookupNDDirect: '<S448>/Declination_Lookup_Table'
     *
     * About '<S448>/Magnitude_Lookup_Table':
     *  2-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     *   *
     * About '<S448>/Declination_Lookup_Table':
     *  2-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     *   */
    rtb_Saturation1_j_idx_1 = 36;
  } else if (rtb_Saturation1_j_idx_1 < 0) {
    /* LookupNDDirect: '<S448>/Magnitude_Lookup_Table' incorporates:
     *  LookupNDDirect: '<S448>/Declination_Lookup_Table'
     *
     * About '<S448>/Magnitude_Lookup_Table':
     *  2-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     *   *
     * About '<S448>/Declination_Lookup_Table':
     *  2-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     *   */
    rtb_Saturation1_j_idx_1 = 0;
  }

  if (rtb_Saturation1_j_idx_0 > 16) {
    /* LookupNDDirect: '<S448>/Magnitude_Lookup_Table' incorporates:
     *  LookupNDDirect: '<S448>/Declination_Lookup_Table'
     *
     * About '<S448>/Magnitude_Lookup_Table':
     *  2-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     *   *
     * About '<S448>/Declination_Lookup_Table':
     *  2-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     *   */
    rtb_Saturation1_j_idx_0 = 16;
  } else if (rtb_Saturation1_j_idx_0 < 0) {
    /* LookupNDDirect: '<S448>/Magnitude_Lookup_Table' incorporates:
     *  LookupNDDirect: '<S448>/Declination_Lookup_Table'
     *
     * About '<S448>/Magnitude_Lookup_Table':
     *  2-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     *   *
     * About '<S448>/Declination_Lookup_Table':
     *  2-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     *   */
    rtb_Saturation1_j_idx_0 = 0;
  }

  /* Switch: '<S447>/Switch3' incorporates:
   *  Concatenate: '<S455>/Vector Concatenate'
   *  Constant: '<S455>/Constant'
   *  Constant: '<S455>/Constant1'
   *  Constant: '<S455>/Constant2'
   *  Constant: '<S455>/Constant3'
   *  Constant: '<S455>/Constant4'
   *  Delay generated from: '<Root>/Delay'
   *  Product: '<S447>/Product6'
   *  Product: '<S447>/Product7'
   */
  if (rtb_Compare_cio) {
    /* LookupNDDirect: '<S448>/Magnitude_Lookup_Table' incorporates:
     *  LookupNDDirect: '<S448>/Declination_Lookup_Table'
     *
     * About '<S448>/Magnitude_Lookup_Table':
     *  2-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     *   *
     * About '<S448>/Declination_Lookup_Table':
     *  2-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     *   */
    rtb_MathFunction1_tmp = rtb_Saturation1_j_idx_1 * 17 +
      rtb_Saturation1_j_idx_0;

    /* MinMax: '<S457>/MinMax' incorporates:
     *  Constant: '<S457>/Constant1'
     *  LookupNDDirect: '<S448>/Magnitude_Lookup_Table'
     *
     * About '<S448>/Magnitude_Lookup_Table':
     *  2-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     *   */
    rtb_MathFunction1 = fmaxf(INS_P.Constant1_Value_l1,
      INS_P.INS_CONST.wmm_mag[rtb_MathFunction1_tmp]);
    rtb_VectorConcatenate_g[8] = INS_P.Constant_Value_a1;
    rtb_VectorConcatenate_g[7] = INS_P.Constant1_Value_i;
    rtb_VectorConcatenate_g[6] = INS_P.Constant2_Value_mb;
    rtb_VectorConcatenate_g[5] = INS_P.Constant4_Value_cj;

    /* Gain: '<S447>/Gain' incorporates:
     *  Constant: '<S455>/Constant'
     *  Constant: '<S455>/Constant1'
     *  Constant: '<S455>/Constant2'
     *  Constant: '<S455>/Constant4'
     *  LookupNDDirect: '<S448>/Declination_Lookup_Table'
     *
     * About '<S448>/Declination_Lookup_Table':
     *  2-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     *   */
    rtb_Switch_kj_idx_1 = INS_P.INS_CONST.wmm_dec[rtb_MathFunction1_tmp] *
      INS_P.Gain_Gain_gg;

    /* Trigonometry: '<S455>/Trigonometric Function3' incorporates:
     *  Trigonometry: '<S455>/Trigonometric Function1'
     */
    rtb_Switch_kj_idx_0 = csi_cos_f32(rtb_Switch_kj_idx_1);
    rtb_VectorConcatenate_g[4] = rtb_Switch_kj_idx_0;

    /* Trigonometry: '<S455>/Trigonometric Function2' incorporates:
     *  Trigonometry: '<S455>/Trigonometric Function'
     */
    rtb_Switch_kj_idx_1 = csi_sin_f32(rtb_Switch_kj_idx_1);

    /* Gain: '<S455>/Gain' incorporates:
     *  Trigonometry: '<S455>/Trigonometric Function2'
     */
    rtb_VectorConcatenate_g[3] = INS_P.Gain_Gain_bo * rtb_Switch_kj_idx_1;
    rtb_VectorConcatenate_g[2] = INS_P.Constant3_Value_f;

    /* Trigonometry: '<S455>/Trigonometric Function' incorporates:
     *  Constant: '<S455>/Constant3'
     */
    rtb_VectorConcatenate_g[1] = rtb_Switch_kj_idx_1;

    /* Trigonometry: '<S455>/Trigonometric Function1' */
    rtb_VectorConcatenate_g[0] = rtb_Switch_kj_idx_0;

    /* Product: '<S457>/Divide1' incorporates:
     *  Gain: '<S393>/Gauss_to_uT'
     */
    rtb_Saturation_a = rtb_Gauss_to_uT[0] / rtb_MathFunction1;
    rtb_Relay = rtb_Gauss_to_uT[1] / rtb_MathFunction1;
    rtb_MathFunction1 = rtb_Gauss_to_uT[2] / rtb_MathFunction1;

    /* Product: '<S447>/Product5' incorporates:
     *  Delay generated from: '<Root>/Delay'
     */
    for (rtb_MathFunction1_tmp = 0; rtb_MathFunction1_tmp < 3;
         rtb_MathFunction1_tmp++) {
      rtb_MathFunction[rtb_MathFunction1_tmp] =
        (INS_DWork.Delay_9_DSTATE[rtb_MathFunction1_tmp + 3] * rtb_Relay +
         INS_DWork.Delay_9_DSTATE[rtb_MathFunction1_tmp] * rtb_Saturation_a) +
        INS_DWork.Delay_9_DSTATE[rtb_MathFunction1_tmp + 6] * rtb_MathFunction1;
    }

    /* End of Product: '<S447>/Product5' */

    /* Product: '<S447>/Product6' */
    rtb_Gain1_n_idx_0 = rtb_MathFunction[1];
    rtb_Relay = rtb_MathFunction[0];
    rtb_Switch_kj_idx_0 = rtb_MathFunction[2];
    for (rtb_MathFunction1_tmp = 0; rtb_MathFunction1_tmp < 3;
         rtb_MathFunction1_tmp++) {
      rtb_MathFunction[rtb_MathFunction1_tmp] =
        (rtb_VectorConcatenate_g[rtb_MathFunction1_tmp + 3] * rtb_Gain1_n_idx_0
         + rtb_VectorConcatenate_g[rtb_MathFunction1_tmp] * rtb_Relay) +
        rtb_VectorConcatenate_g[rtb_MathFunction1_tmp + 6] * rtb_Switch_kj_idx_0;
    }
  } else {
    /* Sum: '<S456>/Sum of Elements' incorporates:
     *  Gain: '<S393>/Gauss_to_uT'
     *  Math: '<S456>/Math Function'
     */
    rtb_MathFunction1 = (rtb_Gauss_to_uT[0] * rtb_Gauss_to_uT[0] +
                         rtb_Gauss_to_uT[1] * rtb_Gauss_to_uT[1]) +
      rtb_Gauss_to_uT[2] * rtb_Gauss_to_uT[2];

    /* Math: '<S456>/Math Function1'
     *
     * About '<S456>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_MathFunction1 < 0.0F) {
      rtb_MathFunction1 = -sqrtf(fabsf(rtb_MathFunction1));
    } else {
      rtb_MathFunction1 = sqrtf(rtb_MathFunction1);
    }

    /* End of Math: '<S456>/Math Function1' */

    /* Switch: '<S456>/Switch' incorporates:
     *  Constant: '<S456>/Constant'
     *  Product: '<S456>/Product'
     */
    if (rtb_MathFunction1 > INS_P.Switch_Threshold_b) {
      rtb_Switch_kj_idx_0 = rtb_Gauss_to_uT[0];
      rtb_Switch_kj_idx_1 = rtb_Gauss_to_uT[1];
      rtb_Switch_kj_idx_2 = rtb_Gauss_to_uT[2];
      rtb_DiscreteTimeIntegrator_g = rtb_MathFunction1;
    } else {
      rtb_Switch_kj_idx_0 = 0.0F;
      rtb_Switch_kj_idx_1 = 0.0F;
      rtb_Switch_kj_idx_2 = 0.0F;
      rtb_DiscreteTimeIntegrator_g = INS_P.Constant_Value_hy;
    }

    /* End of Switch: '<S456>/Switch' */

    /* Product: '<S456>/Divide' */
    rtb_Switch_kj_idx_0 /= rtb_DiscreteTimeIntegrator_g;
    rtb_Switch_kj_idx_1 /= rtb_DiscreteTimeIntegrator_g;
    rtb_Switch_kj_idx_2 /= rtb_DiscreteTimeIntegrator_g;
    for (rtb_MathFunction1_tmp = 0; rtb_MathFunction1_tmp < 3;
         rtb_MathFunction1_tmp++) {
      rtb_MathFunction[rtb_MathFunction1_tmp] =
        (INS_DWork.Delay_9_DSTATE[rtb_MathFunction1_tmp + 3] *
         rtb_Switch_kj_idx_1 + INS_DWork.Delay_9_DSTATE[rtb_MathFunction1_tmp] *
         rtb_Switch_kj_idx_0) + INS_DWork.Delay_9_DSTATE[rtb_MathFunction1_tmp +
        6] * rtb_Switch_kj_idx_2;
    }
  }

  /* End of Switch: '<S447>/Switch3' */

  /* Sum: '<S453>/Sum of Elements' incorporates:
   *  Math: '<S453>/Square'
   *  Sum: '<S454>/Sum of Elements'
   */
  rtb_MathFunction1 = rtb_MathFunction[0] * rtb_MathFunction[0] +
    rtb_MathFunction[1] * rtb_MathFunction[1];

  /* Sum: '<S450>/Sum3' incorporates:
   *  Abs: '<S450>/Abs1'
   *  Constant: '<S450>/Constant2'
   *  Gain: '<S450>/Gain1'
   *  Gain: '<S450>/gain'
   *  LookupNDDirect: '<S448>/Inclination_Lookup_Table'
   *  Sqrt: '<S453>/Sqrt'
   *  Sum: '<S450>/Subtract'
   *  Sum: '<S453>/Sum of Elements'
   *  Trigonometry: '<S450>/Trigonometric Function'
   *
   * About '<S448>/Inclination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   *   */
  rtb_DiscreteTimeIntegrator_g = INS_P.Constant2_Value_h - fabsf
    (INS_P.INS_CONST.wmm_inc[rtb_Saturation1_j_idx_1 * 17 +
     rtb_Saturation1_j_idx_0] * INS_P.Gain1_Gain_o - atan2f(rtb_MathFunction[2],
      sqrtf(rtb_MathFunction1))) * INS_P.gain_Gain_g;

  /* Sum: '<S451>/Sum' incorporates:
   *  Abs: '<S451>/Abs'
   *  Constant: '<S451>/Constant1'
   *  Constant: '<S451>/Nominal_Magnitude'
   *  Gain: '<S451>/gain'
   *  Math: '<S454>/Square'
   *  Sqrt: '<S454>/Sqrt'
   *  Sum: '<S451>/Subtract'
   *  Sum: '<S454>/Sum of Elements'
   */
  u0 = INS_P.Constant1_Value_c - fabsf(INS_P.Nominal_Magnitude_Value - sqrtf
    (rtb_MathFunction[2] * rtb_MathFunction[2] + rtb_MathFunction1)) *
    INS_P.gain_Gain_m;

  /* Saturate: '<S450>/Saturation' */
  if (rtb_DiscreteTimeIntegrator_g > INS_P.Saturation_UpperSat_g) {
    rtb_DiscreteTimeIntegrator_g = INS_P.Saturation_UpperSat_g;
  } else if (rtb_DiscreteTimeIntegrator_g < INS_P.Saturation_LowerSat_a) {
    rtb_DiscreteTimeIntegrator_g = INS_P.Saturation_LowerSat_a;
  }

  /* Saturate: '<S451>/Saturation' */
  if (u0 > INS_P.Saturation_UpperSat_gv) {
    u0 = INS_P.Saturation_UpperSat_gv;
  } else if (u0 < INS_P.Saturation_LowerSat_p) {
    u0 = INS_P.Saturation_LowerSat_p;
  }

  /* MinMax: '<S449>/MinMax' incorporates:
   *  Saturate: '<S450>/Saturation'
   *  Saturate: '<S451>/Saturation'
   */
  rtb_Saturation_a = fminf(rtb_DiscreteTimeIntegrator_g, u0);

  /* DiscreteIntegrator: '<S452>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S452>/Constant'
   */
  if ((INS_P.Constant_Value_fn != 0.0F) ||
      (INS_DWork.DiscreteTimeIntegrator_PrevRe_k != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE = INS_P.DiscreteTimeIntegrator_IC_mb;
  }

  rtb_DiscreteTimeIntegrator_eh = INS_DWork.DiscreteTimeIntegrator_DSTATE;

  /* DiscreteIntegrator: '<S452>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S452>/Constant'
   */
  if (INS_DWork.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    INS_DWork.DiscreteTimeIntegrator1_DSTATE = rtb_Saturation_a;
  }

  if ((INS_P.Constant_Value_fn != 0.0F) ||
      (INS_DWork.DiscreteTimeIntegrator1_PrevRes != 0)) {
    INS_DWork.DiscreteTimeIntegrator1_DSTATE = rtb_Saturation_a;
  }

  /* DiscreteIntegrator: '<S445>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/MAG'
   *  RelationalOperator: '<S459>/FixPt Relational Operator'
   *  UnitDelay: '<S459>/Delay Input1'
   */
  if (INS_U.MAG.timestamp != INS_DWork.DelayInput1_DSTATE_n) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_lg =
      INS_P.DiscreteTimeIntegrator_IC_k;

    /* Switch: '<S460>/Switch' incorporates:
     *  Constant: '<S460>/Constant1'
     *  DiscreteIntegrator: '<S445>/Discrete-Time Integrator'
     */
    rtb_Uk1_m2 = INS_P.Constant1_Value_ev;
  } else {
    /* Switch: '<S460>/Switch' incorporates:
     *  Delay: '<S460>/Delay'
     */
    rtb_Uk1_m2 = INS_DWork.Delay_DSTATE_fp;
  }

  /* Product: '<S446>/Multiply' incorporates:
   *  Constant: '<S446>/default_mag_quality'
   *  Constant: '<S458>/Constant'
   *  Constant: '<S461>/Lower Limit'
   *  Constant: '<S461>/Upper Limit'
   *  DiscreteIntegrator: '<S445>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S452>/Discrete-Time Integrator1'
   *  Inport: '<Root>/MAG'
   *  Logic: '<S445>/Logical Operator1'
   *  Logic: '<S445>/Logical Operator4'
   *  Logic: '<S461>/AND'
   *  RelationalOperator: '<S458>/Compare'
   *  RelationalOperator: '<S461>/Lower Test'
   *  RelationalOperator: '<S461>/Upper Test'
   *  SignalConversion generated from: '<S443>/Vector Concatenate2'
   *  Switch: '<S446>/Switch'
   * */
  rtb_MathFunction1 = (INS_P.Sensor_Valid_mag_min < INS_U.MAG.mag_x) &&
    (INS_U.MAG.mag_x < INS_P.Sensor_Valid_mag_max) &&
    ((INS_P.Sensor_Valid_mag_min < INS_U.MAG.mag_y) && (INS_U.MAG.mag_y <
      INS_P.Sensor_Valid_mag_max)) && ((INS_P.Sensor_Valid_mag_min <
    INS_U.MAG.mag_z) && (INS_U.MAG.mag_z < INS_P.Sensor_Valid_mag_max)) &&
    (INS_DWork.DiscreteTimeIntegrator_DSTAT_lg < INS_P.Sensor_Valid_timeout_b) &&
    (rtb_Uk1_m2 != 0) ? rtb_Compare_cio ?
    INS_DWork.DiscreteTimeIntegrator1_DSTATE : INS_P.default_mag_quality_Value :
    0.0F;

  /* Product: '<S447>/Product8' incorporates:
   *  Delay generated from: '<Root>/Delay'
   *  Math: '<S447>/Math Function2'
   */
  rtb_Switch_kj_idx_0 = rtb_MathFunction[1];
  rtb_Relay = rtb_MathFunction[0];
  rtb_mag_valid = rtb_MathFunction[2];
  for (rtb_MathFunction1_tmp = 0; rtb_MathFunction1_tmp < 3;
       rtb_MathFunction1_tmp++) {
    rtb_Product8[rtb_MathFunction1_tmp] = (INS_DWork.Delay_9_DSTATE[3 *
      rtb_MathFunction1_tmp + 1] * rtb_Switch_kj_idx_0 +
      INS_DWork.Delay_9_DSTATE[3 * rtb_MathFunction1_tmp] * rtb_Relay) +
      INS_DWork.Delay_9_DSTATE[3 * rtb_MathFunction1_tmp + 2] * rtb_mag_valid;
  }

  /* End of Product: '<S447>/Product8' */

  /* Relay: '<S393>/Relay1' */
  INS_DWork.Relay1_Mode = ((rtb_MathFunction1 >= INS_P.Relay1_OnVal_k) ||
    ((rtb_MathFunction1 > INS_P.Relay1_OffVal_b) && INS_DWork.Relay1_Mode));
  if (INS_DWork.Relay1_Mode) {
    rtb_mag_valid = INS_P.Relay1_YOn_m;
  } else {
    rtb_mag_valid = INS_P.Relay1_YOff_i;
  }

  /* End of Relay: '<S393>/Relay1' */

  /* Update for DiscreteIntegrator: '<S452>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S452>/Constant'
   *  DiscreteIntegrator: '<S452>/Discrete-Time Integrator1'
   *  Gain: '<S452>/Gain'
   *  Gain: '<S452>/Gain1'
   *  Sum: '<S452>/Sum'
   *  Sum: '<S452>/Sum2'
   * */
  INS_DWork.DiscreteTimeIntegrator_DSTATE += ((rtb_Saturation_a -
    INS_DWork.DiscreteTimeIntegrator1_DSTATE) * INS_P.Gain_Gain_cw -
    INS_P.Gain1_Gain_bn * INS_DWork.DiscreteTimeIntegrator_DSTATE) *
    INS_P.DiscreteTimeIntegrator_gainv_bm;
  if (INS_P.Constant_Value_fn > 0.0F) {
    INS_DWork.DiscreteTimeIntegrator_PrevRe_k = 1;
    INS_DWork.DiscreteTimeIntegrator1_PrevRes = 1;
  } else if (INS_P.Constant_Value_fn < 0.0F) {
    INS_DWork.DiscreteTimeIntegrator_PrevRe_k = -1;
    INS_DWork.DiscreteTimeIntegrator1_PrevRes = -1;
  } else if (INS_P.Constant_Value_fn == 0.0F) {
    INS_DWork.DiscreteTimeIntegrator_PrevRe_k = 0;
    INS_DWork.DiscreteTimeIntegrator1_PrevRes = 0;
  } else {
    INS_DWork.DiscreteTimeIntegrator_PrevRe_k = 2;
    INS_DWork.DiscreteTimeIntegrator1_PrevRes = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S452>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S452>/Discrete-Time Integrator1' */
  INS_DWork.DiscreteTimeIntegrator1_IC_LOAD = 0U;
  INS_DWork.DiscreteTimeIntegrator1_DSTATE +=
    INS_P.DiscreteTimeIntegrator1_gainv_m * rtb_DiscreteTimeIntegrator_eh;

  /* Update for UnitDelay: '<S459>/Delay Input1' incorporates:
   *  Inport: '<Root>/MAG'
   */
  INS_DWork.DelayInput1_DSTATE_n = INS_U.MAG.timestamp;

  /* Update for DiscreteIntegrator: '<S445>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S445>/Constant'
   */
  if (INS_EXPORT.period < 4.2949673E+9F) {
    rtb_Sum1_o = (uint32_T)(real32_T)INS_EXPORT.period;
  } else {
    rtb_Sum1_o = MAX_uint32_T;
  }

  rtb_Sum1 = INS_DWork.DiscreteTimeIntegrator_DSTAT_lg + rtb_Sum1_o;
  if (rtb_Sum1 < INS_DWork.DiscreteTimeIntegrator_DSTAT_lg) {
    rtb_Sum1 = MAX_uint32_T;
  }

  INS_DWork.DiscreteTimeIntegrator_DSTAT_lg = rtb_Sum1;

  /* End of Update for DiscreteIntegrator: '<S445>/Discrete-Time Integrator' */

  /* Update for Delay: '<S460>/Delay' */
  INS_DWork.Delay_DSTATE_fp = rtb_Uk1_m2;

  /* End of Outputs for SubSystem: '<S3>/MAG_PreProcess' */

  /* Outputs for Atomic SubSystem: '<S3>/Rangefinder_PreProcess' */
  /* DiscreteIntegrator: '<S473>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/Rangefinder'
   *  RelationalOperator: '<S477>/FixPt Relational Operator'
   *  UnitDelay: '<S477>/Delay Input1'
   */
  if (INS_U.Rangefinder.timestamp != INS_DWork.DelayInput1_DSTATE) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_e3 =
      INS_P.DiscreteTimeIntegrator_IC_f4;

    /* Switch: '<S478>/Switch' incorporates:
     *  Constant: '<S478>/Constant1'
     *  DiscreteIntegrator: '<S473>/Discrete-Time Integrator'
     */
    rtb_DiscreteTimeIntegrator_g = INS_P.Constant1_Value_h;
  } else {
    /* Switch: '<S478>/Switch' incorporates:
     *  Delay: '<S478>/Delay'
     */
    rtb_DiscreteTimeIntegrator_g = INS_DWork.Delay_DSTATE_j;
  }

  /* Relay: '<S473>/Relay' incorporates:
   *  Inport: '<Root>/Rangefinder'
   */
  INS_DWork.Relay_Mode = ((INS_U.Rangefinder.distance >=
    INS_P.Sensor_Valid_max_alt) || ((INS_U.Rangefinder.distance >
    INS_P.Relay_OffVal_b) && INS_DWork.Relay_Mode));
  if (INS_DWork.Relay_Mode) {
    rtb_Gain1_n_idx_0 = INS_P.Relay_YOn_e;
  } else {
    rtb_Gain1_n_idx_0 = INS_P.Relay_YOff_c;
  }

  /* RelationalOperator: '<S481>/Compare' incorporates:
   *  Constant: '<S476>/Constant'
   *  Constant: '<S479>/Lower Limit'
   *  Constant: '<S479>/Upper Limit'
   *  Constant: '<S481>/Constant'
   *  DiscreteIntegrator: '<S473>/Discrete-Time Integrator'
   *  Inport: '<Root>/Rangefinder'
   *  Logic: '<S473>/Logical Operator1'
   *  Logic: '<S479>/AND'
   *  RelationalOperator: '<S476>/Compare'
   *  RelationalOperator: '<S479>/Lower Test'
   *  RelationalOperator: '<S479>/Upper Test'
   *  Relay: '<S473>/Relay'
   */
  rtb_Compare_ai = (((INS_P.Sensor_Valid_min_alt < INS_U.Rangefinder.distance) &&
                     (INS_U.Rangefinder.distance < INS_P.Sensor_Valid_max_alt) &&
                     (rtb_Gain1_n_idx_0 != 0.0F) &&
                     (INS_DWork.DiscreteTimeIntegrator_DSTAT_e3 <
                      INS_P.Sensor_Valid_timeout_p) &&
                     (rtb_DiscreteTimeIntegrator_g != 0.0F)) > (int32_T)
                    INS_P.Constant_Value_pa);

  /* DiscreteIntegrator: '<S474>/Discrete-Time Integrator' */
  if ((!rtb_Compare_ai) && (INS_DWork.DiscreteTimeIntegrator_PrevRese == 1)) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_cv =
      INS_P.DiscreteTimeIntegrator_IC_n1;
  }

  /* RelationalOperator: '<S480>/Compare' incorporates:
   *  Constant: '<S480>/Constant'
   *  DiscreteIntegrator: '<S474>/Discrete-Time Integrator'
   */
  rtb_Compare_c5 = (INS_DWork.DiscreteTimeIntegrator_DSTAT_cv >=
                    INS_P.CompareToConstant_const_m);

  /* Product: '<S475>/Multiply' incorporates:
   *  Delay generated from: '<Root>/Delay'
   *  Inport: '<Root>/Rangefinder'
   *  Trigonometry: '<S475>/Cos'
   *  Trigonometry: '<S475>/Cos1'
   */
  rtb_Saturation_a = INS_U.Rangefinder.distance * csi_cos_f32
    (INS_DWork.Delay_3_DSTATE) * csi_cos_f32(INS_DWork.Delay_4_DSTATE);

  /* Update for UnitDelay: '<S477>/Delay Input1' incorporates:
   *  Inport: '<Root>/Rangefinder'
   */
  INS_DWork.DelayInput1_DSTATE = INS_U.Rangefinder.timestamp;

  /* Update for DiscreteIntegrator: '<S473>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S473>/Constant'
   */
  if (INS_EXPORT.period < 4.2949673E+9F) {
    rtb_Sum1_o = (uint32_T)(real32_T)INS_EXPORT.period;
  } else {
    rtb_Sum1_o = MAX_uint32_T;
  }

  rtb_Sum1 = INS_DWork.DiscreteTimeIntegrator_DSTAT_e3 + rtb_Sum1_o;
  if (rtb_Sum1 < INS_DWork.DiscreteTimeIntegrator_DSTAT_e3) {
    rtb_Sum1 = MAX_uint32_T;
  }

  INS_DWork.DiscreteTimeIntegrator_DSTAT_e3 = rtb_Sum1;

  /* End of Update for DiscreteIntegrator: '<S473>/Discrete-Time Integrator' */

  /* Update for Delay: '<S478>/Delay' */
  INS_DWork.Delay_DSTATE_j = rtb_DiscreteTimeIntegrator_g;

  /* Update for DiscreteIntegrator: '<S474>/Discrete-Time Integrator' */
  INS_DWork.DiscreteTimeIntegrator_DSTAT_cv += rtb_Compare_ai;
  if (INS_DWork.DiscreteTimeIntegrator_DSTAT_cv >
      INS_P.DiscreteTimeIntegrator_UpperS_l) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_cv =
      INS_P.DiscreteTimeIntegrator_UpperS_l;
  } else if (INS_DWork.DiscreteTimeIntegrator_DSTAT_cv <
             INS_P.DiscreteTimeIntegrator_Lower_bq) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_cv =
      INS_P.DiscreteTimeIntegrator_Lower_bq;
  }

  INS_DWork.DiscreteTimeIntegrator_PrevRese = (int8_T)rtb_Compare_ai;

  /* End of Update for DiscreteIntegrator: '<S474>/Discrete-Time Integrator' */
  /* End of Outputs for SubSystem: '<S3>/Rangefinder_PreProcess' */

  /* Outputs for Atomic SubSystem: '<S3>/OpticalFlow_PreProcess' */
  /* Gain: '<S462>/Gain' incorporates:
   *  Inport: '<Root>/IMU'
   */
  rtb_DiscreteTimeIntegrator_eh = INS_P.Gain_Gain_gn * INS_U.IMU.gyr_x;

  /* DiscreteIntegrator: '<S466>/Discrete-Time Integrator5' incorporates:
   *  Inport: '<Root>/IMU'
   */
  if (INS_DWork.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    INS_DWork.DiscreteTimeIntegrator5_DSTATE[0] = INS_U.IMU.gyr_y;
    INS_DWork.DiscreteTimeIntegrator5_DSTATE[1] = rtb_DiscreteTimeIntegrator_eh;
  }

  /* DeadZone: '<S464>/Dead Zone' incorporates:
   *  DiscreteIntegrator: '<S466>/Discrete-Time Integrator5'
   */
  if (INS_DWork.DiscreteTimeIntegrator5_DSTATE[0] > INS_P.DeadZone_dz) {
    rtb_Memory_m_idx_0 = INS_DWork.DiscreteTimeIntegrator5_DSTATE[0] -
      INS_P.DeadZone_dz;
  } else if (INS_DWork.DiscreteTimeIntegrator5_DSTATE[0] >= INS_P.DeadZone_Start)
  {
    rtb_Memory_m_idx_0 = 0.0F;
  } else {
    rtb_Memory_m_idx_0 = INS_DWork.DiscreteTimeIntegrator5_DSTATE[0] -
      INS_P.DeadZone_Start;
  }

  if (INS_DWork.DiscreteTimeIntegrator5_DSTATE[1] > INS_P.DeadZone_dz) {
    rtb_Memory_m_idx_1 = INS_DWork.DiscreteTimeIntegrator5_DSTATE[1] -
      INS_P.DeadZone_dz;
  } else if (INS_DWork.DiscreteTimeIntegrator5_DSTATE[1] >= INS_P.DeadZone_Start)
  {
    rtb_Memory_m_idx_1 = 0.0F;
  } else {
    rtb_Memory_m_idx_1 = INS_DWork.DiscreteTimeIntegrator5_DSTATE[1] -
      INS_P.DeadZone_Start;
  }

  /* End of DeadZone: '<S464>/Dead Zone' */

  /* DiscreteIntegrator: '<S465>/Discrete-Time Integrator5' incorporates:
   *  Inport: '<Root>/Optical_Flow'
   */
  if (INS_DWork.DiscreteTimeIntegrator5_IC_LO_o != 0) {
    INS_DWork.DiscreteTimeIntegrator5_DSTAT_c[0] = INS_U.Optical_Flow.vx;
    INS_DWork.DiscreteTimeIntegrator5_DSTAT_c[1] = INS_U.Optical_Flow.vy;
  }

  /* Signum: '<S464>/Sign' incorporates:
   *  DiscreteIntegrator: '<S465>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S466>/Discrete-Time Integrator5'
   */
  if (INS_DWork.DiscreteTimeIntegrator5_DSTATE[0] < 0.0F) {
    rtb_MathFunction1_tmp = -1;
  } else {
    rtb_MathFunction1_tmp = (INS_DWork.DiscreteTimeIntegrator5_DSTATE[0] > 0.0F);
  }

  /* Product: '<S462>/Multiply' incorporates:
   *  Constant: '<S467>/Constant'
   *  DiscreteIntegrator: '<S465>/Discrete-Time Integrator5'
   *  Gain: '<S462>/Gain1'
   *  Gain: '<S464>/Gain'
   *  Product: '<S464>/Multiply'
   *  RelationalOperator: '<S467>/Compare'
   *  Signum: '<S464>/Sign'
   *  Sum: '<S462>/Sum'
   *  Sum: '<S464>/Sum'
   */
  rtb_Memory_m_idx_0 = rtb_Compare_c5 ?
    (INS_DWork.DiscreteTimeIntegrator5_DSTAT_c[0] - ((rtb_Memory_m_idx_0 !=
       INS_P.Constant_Value_eu ? INS_P.DeadZone_dz * (real32_T)
       rtb_MathFunction1_tmp : 0.0F) + rtb_Memory_m_idx_0) *
     INS_PARAM.OPF_FIX_GAIN) * rtb_Saturation_a : 0.0F;

  /* Signum: '<S464>/Sign' incorporates:
   *  DiscreteIntegrator: '<S465>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S466>/Discrete-Time Integrator5'
   */
  if (INS_DWork.DiscreteTimeIntegrator5_DSTATE[1] < 0.0F) {
    rtb_MathFunction1_tmp = -1;
  } else {
    rtb_MathFunction1_tmp = (INS_DWork.DiscreteTimeIntegrator5_DSTATE[1] > 0.0F);
  }

  /* Product: '<S462>/Multiply' incorporates:
   *  Constant: '<S467>/Constant'
   *  DiscreteIntegrator: '<S465>/Discrete-Time Integrator5'
   *  Gain: '<S462>/Gain1'
   *  Gain: '<S464>/Gain'
   *  Product: '<S464>/Multiply'
   *  RelationalOperator: '<S467>/Compare'
   *  Signum: '<S464>/Sign'
   *  Sum: '<S462>/Sum'
   *  Sum: '<S464>/Sum'
   */
  rtb_Memory_m_idx_1 = rtb_Compare_c5 ?
    (INS_DWork.DiscreteTimeIntegrator5_DSTAT_c[1] - ((rtb_Memory_m_idx_1 !=
       INS_P.Constant_Value_eu ? INS_P.DeadZone_dz * (real32_T)
       rtb_MathFunction1_tmp : 0.0F) + rtb_Memory_m_idx_1) *
     INS_PARAM.OPF_FIX_GAIN) * rtb_Saturation_a : 0.0F;

  /* DiscreteIntegrator: '<S463>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/Optical_Flow'
   *  RelationalOperator: '<S469>/FixPt Relational Operator'
   *  UnitDelay: '<S469>/Delay Input1'
   */
  if (INS_U.Optical_Flow.timestamp != INS_DWork.DelayInput1_DSTATE_k) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_g =
      INS_P.DiscreteTimeIntegrator_IC_n;

    /* Switch: '<S470>/Switch' incorporates:
     *  Constant: '<S470>/Constant1'
     *  DiscreteIntegrator: '<S463>/Discrete-Time Integrator'
     */
    rtb_Switch_g3 = (INS_P.Constant1_Value_o0 != 0);
  } else {
    /* Switch: '<S470>/Switch' incorporates:
     *  Delay: '<S470>/Delay'
     */
    rtb_Switch_g3 = INS_DWork.Delay_DSTATE_c;
  }

  /* Relay: '<S463>/Relay' incorporates:
   *  Inport: '<Root>/Optical_Flow'
   */
  INS_DWork.Relay_Mode_n = ((INS_U.Optical_Flow.quality >= INS_P.Relay_OnVal_f) ||
    ((INS_U.Optical_Flow.quality > INS_P.Relay_OffVal_k) &&
     INS_DWork.Relay_Mode_n));
  if (INS_DWork.Relay_Mode_n) {
    rtb_Switch_pt = INS_P.Sensor_Valid_q_high;
  } else {
    rtb_Switch_pt = INS_P.Sensor_Valid_q_low;
  }

  /* Logic: '<S463>/Logical Operator1' incorporates:
   *  Constant: '<S468>/Constant'
   *  Constant: '<S471>/Lower Limit'
   *  Constant: '<S471>/Upper Limit'
   *  Constant: '<S472>/Lower Limit'
   *  Constant: '<S472>/Upper Limit'
   *  DiscreteIntegrator: '<S463>/Discrete-Time Integrator'
   *  Inport: '<Root>/Optical_Flow'
   *  Logic: '<S463>/Logical Operator'
   *  Logic: '<S471>/AND'
   *  Logic: '<S472>/AND'
   *  RelationalOperator: '<S468>/Compare'
   *  RelationalOperator: '<S471>/Lower Test'
   *  RelationalOperator: '<S471>/Upper Test'
   *  RelationalOperator: '<S472>/Lower Test'
   *  RelationalOperator: '<S472>/Upper Test'
   *  Relay: '<S463>/Relay'
   */
  rtb_Compare_ai = ((INS_P.Sensor_Valid_min_vel < INS_U.Optical_Flow.vx) &&
                    (INS_U.Optical_Flow.vx < INS_P.Sensor_Valid_max_vel) &&
                    ((INS_P.Sensor_Valid_min_vel < INS_U.Optical_Flow.vy) &&
                     (INS_U.Optical_Flow.vy < INS_P.Sensor_Valid_max_vel)) &&
                    (rtb_Switch_pt != 0) &&
                    (INS_DWork.DiscreteTimeIntegrator_DSTATE_g <
                     INS_P.Sensor_Valid_timeout_ai) && rtb_Switch_g3 &&
                    rtb_Compare_c5);

  /* Update for DiscreteIntegrator: '<S466>/Discrete-Time Integrator5' */
  INS_DWork.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  rtb_Gain1_n_idx_0 = INS_DWork.DiscreteTimeIntegrator5_DSTATE[0];

  /* Sum: '<S466>/Sum5' incorporates:
   *  DiscreteIntegrator: '<S466>/Discrete-Time Integrator5'
   */
  rtb_Relay = INS_DWork.DiscreteTimeIntegrator5_DSTATE[0];

  /* Update for DiscreteIntegrator: '<S466>/Discrete-Time Integrator5' incorporates:
   *  Sum: '<S466>/Sum5'
   */
  rtb_Switch_kj_idx_0 = INS_DWork.DiscreteTimeIntegrator5_DSTATE[1];

  /* Sum: '<S466>/Sum5' incorporates:
   *  DiscreteIntegrator: '<S466>/Discrete-Time Integrator5'
   */
  rtb_Switch_kj_idx_1 = INS_DWork.DiscreteTimeIntegrator5_DSTATE[1];

  /* Update for DiscreteIntegrator: '<S466>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S466>/Gain'
   *  Inport: '<Root>/IMU'
   *  Sum: '<S466>/Sum5'
   */
  INS_DWork.DiscreteTimeIntegrator5_DSTATE[0] = (INS_U.IMU.gyr_y - rtb_Relay) *
    INS_P.Gain_Gain_ft * INS_P.DiscreteTimeIntegrator5_gainv_j +
    rtb_Gain1_n_idx_0;
  INS_DWork.DiscreteTimeIntegrator5_DSTATE[1] = (rtb_DiscreteTimeIntegrator_eh -
    rtb_Switch_kj_idx_1) * INS_P.Gain_Gain_ft *
    INS_P.DiscreteTimeIntegrator5_gainv_j + rtb_Switch_kj_idx_0;

  /* Update for DiscreteIntegrator: '<S465>/Discrete-Time Integrator5' */
  INS_DWork.DiscreteTimeIntegrator5_IC_LO_o = 0U;
  rtb_Gain1_n_idx_0 = INS_DWork.DiscreteTimeIntegrator5_DSTAT_c[0];

  /* Sum: '<S465>/Sum5' incorporates:
   *  DiscreteIntegrator: '<S465>/Discrete-Time Integrator5'
   */
  rtb_Relay = INS_DWork.DiscreteTimeIntegrator5_DSTAT_c[0];

  /* Update for DiscreteIntegrator: '<S465>/Discrete-Time Integrator5' incorporates:
   *  Sum: '<S465>/Sum5'
   */
  rtb_Switch_kj_idx_0 = INS_DWork.DiscreteTimeIntegrator5_DSTAT_c[1];

  /* Sum: '<S465>/Sum5' incorporates:
   *  DiscreteIntegrator: '<S465>/Discrete-Time Integrator5'
   */
  rtb_Switch_kj_idx_1 = INS_DWork.DiscreteTimeIntegrator5_DSTAT_c[1];

  /* Update for DiscreteIntegrator: '<S465>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S465>/Gain'
   *  Inport: '<Root>/Optical_Flow'
   *  Sum: '<S465>/Sum5'
   */
  INS_DWork.DiscreteTimeIntegrator5_DSTAT_c[0] = (INS_U.Optical_Flow.vx -
    rtb_Relay) * INS_P.Gain_Gain_ca * INS_P.DiscreteTimeIntegrator5_gainv_c +
    rtb_Gain1_n_idx_0;
  INS_DWork.DiscreteTimeIntegrator5_DSTAT_c[1] = (INS_U.Optical_Flow.vy -
    rtb_Switch_kj_idx_1) * INS_P.Gain_Gain_ca *
    INS_P.DiscreteTimeIntegrator5_gainv_c + rtb_Switch_kj_idx_0;

  /* Update for UnitDelay: '<S469>/Delay Input1' incorporates:
   *  Inport: '<Root>/Optical_Flow'
   */
  INS_DWork.DelayInput1_DSTATE_k = INS_U.Optical_Flow.timestamp;

  /* Update for DiscreteIntegrator: '<S463>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S463>/Constant'
   */
  if (INS_EXPORT.period < 4.2949673E+9F) {
    rtb_Sum1_o = (uint32_T)(real32_T)INS_EXPORT.period;
  } else {
    rtb_Sum1_o = MAX_uint32_T;
  }

  rtb_Sum1 = INS_DWork.DiscreteTimeIntegrator_DSTATE_g + rtb_Sum1_o;
  if (rtb_Sum1 < INS_DWork.DiscreteTimeIntegrator_DSTATE_g) {
    rtb_Sum1 = MAX_uint32_T;
  }

  INS_DWork.DiscreteTimeIntegrator_DSTATE_g = rtb_Sum1;

  /* End of Update for DiscreteIntegrator: '<S463>/Discrete-Time Integrator' */

  /* Update for Delay: '<S470>/Delay' */
  INS_DWork.Delay_DSTATE_c = rtb_Switch_g3;

  /* End of Outputs for SubSystem: '<S3>/OpticalFlow_PreProcess' */

  /* Outputs for Atomic SubSystem: '<Root>/Data_Fusion' */
  /* Outputs for Atomic SubSystem: '<S55>/AHRS' */
  /* Outputs for Atomic SubSystem: '<S57>/Correct' */
  /* Outputs for Atomic SubSystem: '<S55>/RF_Data_PreProcess' */
  /* Outputs for Atomic SubSystem: '<S3>/IMU_PreProcess' */
  /* Math: '<S139>/Square' incorporates:
   *  Inport: '<Root>/IMU'
   *  Math: '<S113>/Square'
   *  SignalConversion generated from: '<S436>/Bus Selector1'
   * */
  rtb_Gauss_to_uT[0] = INS_U.IMU.acc_x * INS_U.IMU.acc_x;
  rtb_Gauss_to_uT[1] = INS_U.IMU.acc_y * INS_U.IMU.acc_y;
  rtb_Gauss_to_uT[2] = INS_U.IMU.acc_z * INS_U.IMU.acc_z;

  /* End of Outputs for SubSystem: '<S3>/IMU_PreProcess' */
  /* End of Outputs for SubSystem: '<S57>/Correct' */
  /* End of Outputs for SubSystem: '<S55>/AHRS' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */

  /* Sqrt: '<S139>/Sqrt' incorporates:
   *  Math: '<S139>/Square'
   *  Sum: '<S139>/Sum of Elements'
   */
  rtb_DiscreteTimeIntegrator_nt = sqrtf((rtb_Gauss_to_uT[0] + rtb_Gauss_to_uT[1])
    + rtb_Gauss_to_uT[2]);

  /* Sum: '<S141>/Add' incorporates:
   *  Constant: '<S138>/Lower Limit'
   *  Constant: '<S138>/Upper Limit'
   *  DataTypeConversion: '<S141>/Data Type Conversion'
   *  Delay: '<S141>/Delay'
   *  Logic: '<S129>/Logical Operator1'
   *  Logic: '<S138>/AND'
   *  RelationalOperator: '<S138>/Lower Test'
   *  RelationalOperator: '<S138>/Upper Test'
   */
  rtb_Sum1 = (uint32_T)(rtb_FixPtRelationalOperator_nc &&
                        ((INS_P.IntervalTest_lowlimit <=
    rtb_DiscreteTimeIntegrator_nt) && (rtb_DiscreteTimeIntegrator_nt <=
    INS_P.IntervalTest_uplimit))) + INS_DWork.Delay_DSTATE_i;

  /* Saturate: '<S141>/Saturation' */
  if (rtb_Sum1 > INS_P.Saturation_UpperSat_k5) {
    rtb_Sum1 = INS_P.Saturation_UpperSat_k5;
  } else if (rtb_Sum1 < INS_P.Saturation_LowerSat_hb) {
    rtb_Sum1 = INS_P.Saturation_LowerSat_hb;
  }

  /* End of Saturate: '<S141>/Saturation' */

  /* RelationalOperator: '<S143>/Compare' incorporates:
   *  Constant: '<S143>/Constant'
   *  Constant: '<S147>/Constant'
   *  RelationalOperator: '<S147>/Compare'
   */
  rtb_Compare_o = ((rtb_Sum1 > INS_P.valid_samples_const_k) > (int32_T)
                   INS_P.Constant_Value_af);

  /* Sum: '<S142>/Add' incorporates:
   *  Constant: '<S133>/Constant'
   *  Constant: '<S134>/Constant'
   *  DataTypeConversion: '<S142>/Data Type Conversion'
   *  Delay: '<S142>/Delay'
   *  Logic: '<S129>/Logical Operator3'
   *  Math: '<S140>/Square'
   *  RelationalOperator: '<S133>/Compare'
   *  RelationalOperator: '<S134>/Compare'
   *  Sqrt: '<S140>/Sqrt'
   *  Sum: '<S140>/Sum of Elements'
   */
  rtb_Sum1_o = (uint32_T)((rtb_MathFunction1 >= INS_P.CompareToConstant1_const) &&
    (sqrtf((rtb_Product8[0] * rtb_Product8[0] + rtb_Product8[1] * rtb_Product8[1])
           + rtb_Product8[2] * rtb_Product8[2]) >
     INS_P.CompareToConstant_const_p)) + INS_DWork.Delay_DSTATE_ly;

  /* Saturate: '<S142>/Saturation' */
  if (rtb_Sum1_o > INS_P.Saturation_UpperSat_az) {
    rtb_Sum1_o = INS_P.Saturation_UpperSat_az;
  } else if (rtb_Sum1_o < INS_P.Saturation_LowerSat_d) {
    rtb_Sum1_o = INS_P.Saturation_LowerSat_d;
  }

  /* End of Saturate: '<S142>/Saturation' */

  /* RelationalOperator: '<S148>/Compare' incorporates:
   *  Constant: '<S148>/Constant'
   */
  rtb_WGS84_pos_valid = (rtb_Sum1_o > INS_P.valid_samples_const_g);

  /* RelationalOperator: '<S144>/Compare' incorporates:
   *  Constant: '<S144>/Constant'
   *  Logic: '<S129>/Logical Operator4'
   */
  rtb_Compare_fo = ((rtb_WGS84_pos_valid || rtb_LogicalOperator5) > (int32_T)
                    INS_P.Constant_Value_bf);

  /* Sum: '<S137>/Add' incorporates:
   *  DataTypeConversion: '<S137>/Data Type Conversion'
   *  Delay: '<S137>/Delay'
   */
  rtb_Saturation_mp = rtb_Compare_cio + INS_DWork.Delay_DSTATE_n;

  /* Saturate: '<S137>/Saturation' */
  if (rtb_Saturation_mp > INS_P.Saturation_UpperSat_p) {
    rtb_Saturation_mp = INS_P.Saturation_UpperSat_p;
  } else if (rtb_Saturation_mp < INS_P.Saturation_LowerSat_mo) {
    rtb_Saturation_mp = INS_P.Saturation_LowerSat_mo;
  }

  /* End of Saturate: '<S137>/Saturation' */

  /* RelationalOperator: '<S146>/Compare' incorporates:
   *  Constant: '<S146>/Constant'
   */
  rtb_Compare_ir = (rtb_Saturation_mp > INS_P.Constant_Value_m);

  /* DiscreteIntegrator: '<S191>/Discrete-Time Integrator5' incorporates:
   *  Inport: '<Root>/IMU'
   *  SignalConversion generated from: '<S436>/Bus Selector1'
   * */
  if (INS_DWork.DiscreteTimeIntegrator5_IC_LO_p != 0) {
    /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
    /* Outputs for Atomic SubSystem: '<S3>/IMU_PreProcess' */
    INS_DWork.DiscreteTimeIntegrator5_DSTAT_o[0] = INS_U.IMU.gyr_x;
    INS_DWork.DiscreteTimeIntegrator5_DSTAT_o[1] = INS_U.IMU.gyr_y;

    /* End of Outputs for SubSystem: '<S3>/IMU_PreProcess' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */
  }

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
  /* Outputs for Atomic SubSystem: '<S3>/IMU_PreProcess' */
  /* Sum: '<S188>/Subtract' incorporates:
   *  DiscreteIntegrator: '<S191>/Discrete-Time Integrator5'
   *  Inport: '<Root>/IMU'
   *  SignalConversion generated from: '<S436>/Bus Selector1'
   *  Sum: '<S191>/Sum5'
   */
  rtb_DiscreteTimeIntegrator1_p_i = INS_U.IMU.gyr_x -
    INS_DWork.DiscreteTimeIntegrator5_DSTAT_o[0];

  /* End of Outputs for SubSystem: '<S3>/IMU_PreProcess' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */
  /* End of Outputs for SubSystem: '<S55>/RF_Data_PreProcess' */
  /* End of Outputs for SubSystem: '<Root>/Data_Fusion' */
  rtb_DataTypeConversion_l_idx_0 = rtb_DiscreteTimeIntegrator1_p_i;

  /* Outputs for Atomic SubSystem: '<Root>/Data_Fusion' */
  /* Outputs for Atomic SubSystem: '<S55>/RF_Data_PreProcess' */
  /* Abs: '<S132>/Abs' incorporates:
   *  Sum: '<S188>/Subtract'
   *  Sum: '<S191>/Sum5'
   */
  rtb_Switch_kj_idx_0 = fabsf(rtb_DiscreteTimeIntegrator1_p_i);

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
  /* Outputs for Atomic SubSystem: '<S3>/IMU_PreProcess' */
  /* Sum: '<S188>/Subtract' incorporates:
   *  DiscreteIntegrator: '<S191>/Discrete-Time Integrator5'
   *  Inport: '<Root>/IMU'
   *  SignalConversion generated from: '<S436>/Bus Selector1'
   *  Sum: '<S191>/Sum5'
   */
  rtb_DiscreteTimeIntegrator1_p_i = INS_U.IMU.gyr_y -
    INS_DWork.DiscreteTimeIntegrator5_DSTAT_o[1];

  /* End of Outputs for SubSystem: '<S3>/IMU_PreProcess' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */

  /* MinMax: '<S132>/MinMax1' incorporates:
   *  Abs: '<S132>/Abs'
   *  Sum: '<S188>/Subtract'
   *  Sum: '<S191>/Sum5'
   */
  rtb_DiscreteTimeIntegrator_nt = fmaxf(rtb_Switch_kj_idx_0, fabsf
    (rtb_DiscreteTimeIntegrator1_p_i));

  /* DiscreteIntegrator: '<S189>/Discrete-Time Integrator5' incorporates:
   *  MinMax: '<S132>/MinMax1'
   */
  if (INS_DWork.DiscreteTimeIntegrator5_IC_LO_n != 0) {
    INS_DWork.DiscreteTimeIntegrator5_DSTAT_m = rtb_DiscreteTimeIntegrator_nt;
  }

  /* Saturate: '<S132>/Saturation2' */
  if (INS_DWork.DiscreteTimeIntegrator5_DSTAT_m > INS_P.Saturation2_UpperSat_i)
  {
    rtb_DiscreteTimeIntegrator_eh = INS_P.Saturation2_UpperSat_i;
  } else if (INS_DWork.DiscreteTimeIntegrator5_DSTAT_m <
             INS_P.Saturation2_LowerSat_g) {
    rtb_DiscreteTimeIntegrator_eh = INS_P.Saturation2_LowerSat_g;
  } else {
    rtb_DiscreteTimeIntegrator_eh = INS_DWork.DiscreteTimeIntegrator5_DSTAT_m;
  }

  /* End of Saturate: '<S132>/Saturation2' */

  /* DiscreteIntegrator: '<S190>/Discrete-Time Integrator5' */
  if (INS_DWork.DiscreteTimeIntegrator5_IC_L_ns != 0) {
    INS_DWork.DiscreteTimeIntegrator5_DSTA_ow = rtb_DiscreteTimeIntegrator_eh;
  }

  /* Relay: '<S132>/Relay' incorporates:
   *  DiscreteIntegrator: '<S190>/Discrete-Time Integrator5'
   */
  INS_DWork.Relay_Mode_n5 = ((INS_DWork.DiscreteTimeIntegrator5_DSTA_ow >=
    INS_P.Relay_OnVal_g) || ((INS_DWork.DiscreteTimeIntegrator5_DSTA_ow >
    INS_P.Relay_OffVal_f) && INS_DWork.Relay_Mode_n5));
  if (INS_DWork.Relay_Mode_n5) {
    rtb_Relay = INS_P.Relay_YOn_k;
  } else {
    rtb_Relay = INS_P.Relay_YOff_f;
  }

  /* End of Relay: '<S132>/Relay' */

  /* Logic: '<S129>/Logical Operator2' incorporates:
   *  Logic: '<S129>/Logical Operator'
   *  Logic: '<S137>/Logical Operator'
   *  RelationalOperator: '<S136>/FixPt Relational Operator'
   *  RelationalOperator: '<S145>/FixPt Relational Operator'
   *  UnitDelay: '<S136>/Delay Input1'
   *  UnitDelay: '<S145>/Delay Input1'
   */
  rtb_Switch_g3 = (((int32_T)rtb_Compare_fo > (int32_T)
                    INS_DWork.DelayInput1_DSTATE_nk) || (rtb_WGS84_pos_valid &&
    (((int32_T)rtb_Compare_ir > (int32_T)INS_DWork.DelayInput1_DSTATE_mm) &&
     (rtb_Relay != 0.0F))));

  /* Logic: '<S129>/Logical Operator5' incorporates:
   *  RelationalOperator: '<S135>/FixPt Relational Operator'
   *  UnitDelay: '<S135>/Delay Input1'
   */
  rtb_LogicalOperator5_i = (((int32_T)rtb_Compare_o > (int32_T)
    INS_DWork.DelayInput1_DSTATE_pr) || rtb_Switch_g3);

  /* Outputs for Enabled SubSystem: '<S58>/Initial_Attitude' incorporates:
   *  EnablePort: '<S130>/Enable'
   */
  if (rtb_LogicalOperator5_i) {
    /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
    /* Outputs for Atomic SubSystem: '<S3>/IMU_PreProcess' */
    /* Gain: '<S130>/Gain' incorporates:
     *  Inport: '<Root>/IMU'
     *  SignalConversion generated from: '<S436>/Bus Selector1'
     * */
    rtb_Gain_ca_idx_0 = INS_P.Gain_Gain_d * INS_U.IMU.acc_x;
    rtb_Gain_ca_idx_1 = INS_P.Gain_Gain_d * INS_U.IMU.acc_y;
    rtb_Gain_ca_idx_2 = INS_P.Gain_Gain_d * INS_U.IMU.acc_z;

    /* End of Outputs for SubSystem: '<S3>/IMU_PreProcess' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */

    /* Switch: '<S152>/Switch' incorporates:
     *  Constant: '<S187>/Constant'
     *  Constant: '<S187>/Constant1'
     *  Constant: '<S187>/Constant2'
     *  Constant: '<S187>/Constant3'
     *  Constant: '<S187>/Constant4'
     *  Product: '<S186>/Divide'
     *  Product: '<S237>/Multiply'
     */
    if (rtb_LogicalOperator5) {
      rtb_VectorConcatenate_g[8] = INS_P.Constant_Value_d0;
      rtb_VectorConcatenate_g[7] = INS_P.Constant1_Value_k;
      rtb_VectorConcatenate_g[6] = INS_P.Constant2_Value_dw;
      rtb_VectorConcatenate_g[5] = INS_P.Constant4_Value_c;

      /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
      /* Outputs for Atomic SubSystem: '<S3>/ExternalPos_Process' */
      /* Gain: '<S185>/Gain' incorporates:
       *  Constant: '<S187>/Constant'
       *  Constant: '<S187>/Constant1'
       *  Constant: '<S187>/Constant2'
       *  Constant: '<S187>/Constant4'
       *  Inport: '<Root>/External_Pos'
       *  SignalConversion generated from: '<S390>/ExternalPos_Data'
       */
      rtb_DiscreteTimeIntegrator_g = INS_P.Gain_Gain_pj * INS_U.External_Pos.psi;

      /* End of Outputs for SubSystem: '<S3>/ExternalPos_Process' */
      /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */

      /* Trigonometry: '<S187>/Trigonometric Function3' incorporates:
       *  Trigonometry: '<S187>/Trigonometric Function1'
       */
      rtb_Switch_kj_idx_0 = csi_cos_f32(rtb_DiscreteTimeIntegrator_g);
      rtb_VectorConcatenate_g[4] = rtb_Switch_kj_idx_0;

      /* Trigonometry: '<S187>/Trigonometric Function2' incorporates:
       *  Trigonometry: '<S187>/Trigonometric Function'
       */
      rtb_Switch_kj_idx_1 = csi_sin_f32(rtb_DiscreteTimeIntegrator_g);

      /* Gain: '<S187>/Gain' incorporates:
       *  Trigonometry: '<S187>/Trigonometric Function2'
       */
      rtb_VectorConcatenate_g[3] = INS_P.Gain_Gain_ok * rtb_Switch_kj_idx_1;
      rtb_VectorConcatenate_g[2] = INS_P.Constant3_Value_b;

      /* Trigonometry: '<S187>/Trigonometric Function' incorporates:
       *  Constant: '<S187>/Constant3'
       */
      rtb_VectorConcatenate_g[1] = rtb_Switch_kj_idx_1;

      /* Trigonometry: '<S187>/Trigonometric Function1' */
      rtb_VectorConcatenate_g[0] = rtb_Switch_kj_idx_0;

      /* Product: '<S152>/Multiply' incorporates:
       *  Concatenate: '<S187>/Vector Concatenate'
       *  Constant: '<S152>/Constant'
       */
      rtb_Switch_kj_idx_1 = INS_P.Constant_Value_b[1];
      rtb_Switch_kj_idx_2 = INS_P.Constant_Value_b[0];
      Constant_Value_b = INS_P.Constant_Value_b[2];
      for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 3;
           rtb_Saturation1_j_idx_1++) {
        rtb_Switch_kj_idx_0 = (rtb_VectorConcatenate_g[rtb_Saturation1_j_idx_1 +
          3] * rtb_Switch_kj_idx_1 +
          rtb_VectorConcatenate_g[rtb_Saturation1_j_idx_1] * rtb_Switch_kj_idx_2)
          + rtb_VectorConcatenate_g[rtb_Saturation1_j_idx_1 + 6] *
          Constant_Value_b;

        /* Product: '<S152>/Multiply' incorporates:
         *  Concatenate: '<S187>/Vector Concatenate'
         */
        rtb_MathFunction[rtb_Saturation1_j_idx_1] = rtb_Switch_kj_idx_0;

        /* Math: '<S186>/Math Function' incorporates:
         *  Product: '<S152>/Multiply'
         */
        rtb_MathFunction_j[rtb_Saturation1_j_idx_1] = rtb_Switch_kj_idx_0 *
          rtb_Switch_kj_idx_0;
      }

      /* End of Product: '<S152>/Multiply' */

      /* Sum: '<S186>/Sum of Elements' incorporates:
       *  Math: '<S186>/Math Function'
       */
      rtb_DiscreteTimeIntegrator_g = (rtb_MathFunction_j[0] +
        rtb_MathFunction_j[1]) + rtb_MathFunction_j[2];

      /* Math: '<S186>/Math Function1'
       *
       * About '<S186>/Math Function1':
       *  Operator: sqrt
       */
      if (rtb_DiscreteTimeIntegrator_g < 0.0F) {
        rtb_DiscreteTimeIntegrator_g = -sqrtf(fabsf(rtb_DiscreteTimeIntegrator_g));
      } else {
        rtb_DiscreteTimeIntegrator_g = sqrtf(rtb_DiscreteTimeIntegrator_g);
      }

      /* End of Math: '<S186>/Math Function1' */

      /* Switch: '<S186>/Switch' incorporates:
       *  Constant: '<S186>/Constant'
       *  Product: '<S186>/Product'
       */
      if (rtb_DiscreteTimeIntegrator_g > INS_P.Switch_Threshold_e) {
        rtb_Switch_kj_idx_0 = rtb_MathFunction[0];
        rtb_Switch_kj_idx_1 = rtb_MathFunction[1];
        rtb_Switch_kj_idx_2 = rtb_MathFunction[2];
      } else {
        rtb_Switch_kj_idx_0 = 0.0F;
        rtb_Switch_kj_idx_1 = 0.0F;
        rtb_Switch_kj_idx_2 = 0.0F;
        rtb_DiscreteTimeIntegrator_g = INS_P.Constant_Value_d1;
      }

      /* End of Switch: '<S186>/Switch' */
      rtb_MathFunction[0] = rtb_Switch_kj_idx_0 / rtb_DiscreteTimeIntegrator_g;
      rtb_MathFunction[1] = rtb_Switch_kj_idx_1 / rtb_DiscreteTimeIntegrator_g;
      rtb_MathFunction[2] = rtb_Switch_kj_idx_2 / rtb_DiscreteTimeIntegrator_g;
    } else {
      rtb_MathFunction[0] = rtb_Product8[0];
      rtb_MathFunction[1] = rtb_Product8[1];
      rtb_MathFunction[2] = rtb_Product8[2];
    }

    /* End of Switch: '<S152>/Switch' */

    /* Sum: '<S149>/Sum' incorporates:
     *  Product: '<S156>/Multiply'
     *  Product: '<S156>/Multiply1'
     *  Product: '<S156>/Multiply2'
     *  Product: '<S157>/Multiply3'
     *  Product: '<S157>/Multiply4'
     *  Product: '<S157>/Multiply5'
     */
    rtb_Reshape_k[0] = rtb_Gain_ca_idx_1 * rtb_MathFunction[2] -
      rtb_MathFunction[1] * rtb_Gain_ca_idx_2;
    rtb_Reshape_k[1] = rtb_MathFunction[0] * rtb_Gain_ca_idx_2 -
      rtb_Gain_ca_idx_0 * rtb_MathFunction[2];
    rtb_Reshape_k[2] = rtb_Gain_ca_idx_0 * rtb_MathFunction[1] -
      rtb_MathFunction[0] * rtb_Gain_ca_idx_1;

    /* Sum: '<S150>/Sum' incorporates:
     *  Product: '<S158>/Multiply'
     *  Product: '<S159>/Multiply3'
     */
    rtb_Switch_kj_idx_2 = rtb_Reshape_k[1] * rtb_Gain_ca_idx_2 -
      rtb_Gain_ca_idx_1 * rtb_Reshape_k[2];
    rtb_Gain1_n_idx_0 = rtb_Switch_kj_idx_2;

    /* Math: '<S153>/Math Function' */
    rtb_MathFunction_j[0] = rtb_Switch_kj_idx_2 * rtb_Switch_kj_idx_2;

    /* Sum: '<S150>/Sum' incorporates:
     *  Product: '<S158>/Multiply1'
     *  Product: '<S159>/Multiply4'
     */
    rtb_Switch_kj_idx_2 = rtb_Gain_ca_idx_0 * rtb_Reshape_k[2] - rtb_Reshape_k[0]
      * rtb_Gain_ca_idx_2;
    rtb_Gain1_n_idx_1 = rtb_Switch_kj_idx_2;

    /* Math: '<S153>/Math Function' */
    rtb_MathFunction_j[1] = rtb_Switch_kj_idx_2 * rtb_Switch_kj_idx_2;

    /* Sum: '<S150>/Sum' incorporates:
     *  Product: '<S158>/Multiply2'
     *  Product: '<S159>/Multiply5'
     */
    rtb_Switch_kj_idx_2 = rtb_Reshape_k[0] * rtb_Gain_ca_idx_1 -
      rtb_Gain_ca_idx_0 * rtb_Reshape_k[1];

    /* Sum: '<S153>/Sum of Elements' incorporates:
     *  Math: '<S153>/Math Function'
     */
    rtb_DiscreteTimeIntegrator_bq = (rtb_MathFunction_j[0] + rtb_MathFunction_j
      [1]) + rtb_Switch_kj_idx_2 * rtb_Switch_kj_idx_2;

    /* Math: '<S153>/Math Function1'
     *
     * About '<S153>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_DiscreteTimeIntegrator_bq < 0.0F) {
      rtb_DiscreteTimeIntegrator_bq = -sqrtf(fabsf(rtb_DiscreteTimeIntegrator_bq));
    } else {
      rtb_DiscreteTimeIntegrator_bq = sqrtf(rtb_DiscreteTimeIntegrator_bq);
    }

    /* End of Math: '<S153>/Math Function1' */

    /* Switch: '<S153>/Switch' incorporates:
     *  Constant: '<S153>/Constant'
     *  Product: '<S153>/Product'
     */
    if (rtb_DiscreteTimeIntegrator_bq > INS_P.Switch_Threshold_a) {
      rtb_Switch_kj_idx_0 = rtb_Gain1_n_idx_0;
      rtb_Switch_kj_idx_1 = rtb_Gain1_n_idx_1;
      rtb_DiscreteTimeIntegrator_g = rtb_DiscreteTimeIntegrator_bq;
    } else {
      rtb_Switch_kj_idx_0 = 0.0F;
      rtb_Switch_kj_idx_1 = 0.0F;
      rtb_Switch_kj_idx_2 = 0.0F;
      rtb_DiscreteTimeIntegrator_g = INS_P.Constant_Value_h1;
    }

    /* End of Switch: '<S153>/Switch' */

    /* Product: '<S153>/Divide' */
    rtb_VectorConcatenate_g[0] = rtb_Switch_kj_idx_0 /
      rtb_DiscreteTimeIntegrator_g;
    rtb_VectorConcatenate_g[1] = rtb_Switch_kj_idx_1 /
      rtb_DiscreteTimeIntegrator_g;
    rtb_VectorConcatenate_g[2] = rtb_Switch_kj_idx_2 /
      rtb_DiscreteTimeIntegrator_g;

    /* Sum: '<S154>/Sum of Elements' incorporates:
     *  Math: '<S154>/Math Function'
     */
    rtb_DiscreteTimeIntegrator_bq = (rtb_Reshape_k[0] * rtb_Reshape_k[0] +
      rtb_Reshape_k[1] * rtb_Reshape_k[1]) + rtb_Reshape_k[2] * rtb_Reshape_k[2];

    /* Math: '<S154>/Math Function1'
     *
     * About '<S154>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_DiscreteTimeIntegrator_bq < 0.0F) {
      rtb_DiscreteTimeIntegrator_bq = -sqrtf(fabsf(rtb_DiscreteTimeIntegrator_bq));
    } else {
      rtb_DiscreteTimeIntegrator_bq = sqrtf(rtb_DiscreteTimeIntegrator_bq);
    }

    /* End of Math: '<S154>/Math Function1' */

    /* Switch: '<S154>/Switch' incorporates:
     *  Constant: '<S154>/Constant'
     *  Product: '<S154>/Product'
     */
    if (rtb_DiscreteTimeIntegrator_bq > INS_P.Switch_Threshold_f) {
      rtb_Switch_kj_idx_0 = rtb_Reshape_k[0];
      rtb_Switch_kj_idx_1 = rtb_Reshape_k[1];
      rtb_Switch_kj_idx_2 = rtb_Reshape_k[2];
      rtb_DiscreteTimeIntegrator_g = rtb_DiscreteTimeIntegrator_bq;
    } else {
      rtb_Switch_kj_idx_0 = 0.0F;
      rtb_Switch_kj_idx_1 = 0.0F;
      rtb_Switch_kj_idx_2 = 0.0F;
      rtb_DiscreteTimeIntegrator_g = INS_P.Constant_Value_aee;
    }

    /* End of Switch: '<S154>/Switch' */

    /* Product: '<S154>/Divide' */
    rtb_VectorConcatenate_g[3] = rtb_Switch_kj_idx_0 /
      rtb_DiscreteTimeIntegrator_g;
    rtb_VectorConcatenate_g[4] = rtb_Switch_kj_idx_1 /
      rtb_DiscreteTimeIntegrator_g;
    rtb_VectorConcatenate_g[5] = rtb_Switch_kj_idx_2 /
      rtb_DiscreteTimeIntegrator_g;

    /* Sum: '<S155>/Sum of Elements' incorporates:
     *  Gain: '<S130>/Gain'
     *  Math: '<S155>/Math Function'
     */
    rtb_DiscreteTimeIntegrator_bq = (rtb_Gain_ca_idx_0 * rtb_Gain_ca_idx_0 +
      rtb_Gain_ca_idx_1 * rtb_Gain_ca_idx_1) + rtb_Gain_ca_idx_2 *
      rtb_Gain_ca_idx_2;

    /* Math: '<S155>/Math Function1'
     *
     * About '<S155>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_DiscreteTimeIntegrator_bq < 0.0F) {
      rtb_DiscreteTimeIntegrator_bq = -sqrtf(fabsf(rtb_DiscreteTimeIntegrator_bq));
    } else {
      rtb_DiscreteTimeIntegrator_bq = sqrtf(rtb_DiscreteTimeIntegrator_bq);
    }

    /* End of Math: '<S155>/Math Function1' */

    /* Switch: '<S155>/Switch' incorporates:
     *  Constant: '<S155>/Constant'
     *  Product: '<S155>/Product'
     *  Sum: '<S114>/Sum'
     */
    if (rtb_DiscreteTimeIntegrator_bq > INS_P.Switch_Threshold_mm) {
      rtb_Switch_kj_idx_0 = rtb_Gain_ca_idx_0;
      rtb_Switch_kj_idx_1 = rtb_Gain_ca_idx_1;
      rtb_Switch_kj_idx_2 = rtb_Gain_ca_idx_2;
      rtb_DiscreteTimeIntegrator_g = rtb_DiscreteTimeIntegrator_bq;
    } else {
      rtb_Switch_kj_idx_0 = 0.0F;
      rtb_Switch_kj_idx_1 = 0.0F;
      rtb_Switch_kj_idx_2 = 0.0F;
      rtb_DiscreteTimeIntegrator_g = INS_P.Constant_Value_hp;
    }

    /* End of Switch: '<S155>/Switch' */

    /* Product: '<S155>/Divide' */
    rtb_VectorConcatenate_g[6] = rtb_Switch_kj_idx_0 /
      rtb_DiscreteTimeIntegrator_g;
    rtb_VectorConcatenate_g[7] = rtb_Switch_kj_idx_1 /
      rtb_DiscreteTimeIntegrator_g;
    rtb_VectorConcatenate_g[8] = rtb_Switch_kj_idx_2 /
      rtb_DiscreteTimeIntegrator_g;

    /* Sum: '<S160>/Add' */
    rtb_DiscreteTimeIntegrator_g = (rtb_VectorConcatenate_g[0] +
      rtb_VectorConcatenate_g[4]) + rtb_VectorConcatenate_g[8];

    /* If: '<S151>/If' incorporates:
     *  If: '<S161>/Find Maximum Diagonal Value'
     */
    if (rtb_DiscreteTimeIntegrator_g > 0.0F) {
      /* Outputs for IfAction SubSystem: '<S151>/Positive Trace' incorporates:
       *  ActionPort: '<S162>/Action Port'
       */
      /* Sqrt: '<S162>/sqrt' incorporates:
       *  Constant: '<S162>/Constant'
       *  Sum: '<S162>/Sum'
       */
      rtb_DiscreteTimeIntegrator_g = sqrtf(rtb_DiscreteTimeIntegrator_g +
        INS_P.Constant_Value_c0);

      /* Gain: '<S162>/Gain' incorporates:
       *  Merge: '<S151>/Merge'
       */
      INS_B.Merge_l[0] = INS_P.Gain_Gain_eu * rtb_DiscreteTimeIntegrator_g;

      /* Gain: '<S162>/Gain1' */
      rtb_DiscreteTimeIntegrator_g *= INS_P.Gain1_Gain_h;

      /* Product: '<S162>/Product' incorporates:
       *  Merge: '<S151>/Merge'
       *  Sum: '<S182>/Add'
       *  Sum: '<S183>/Add'
       *  Sum: '<S184>/Add'
       */
      INS_B.Merge_l[1] = (rtb_VectorConcatenate_g[7] - rtb_VectorConcatenate_g[5])
        / rtb_DiscreteTimeIntegrator_g;
      INS_B.Merge_l[2] = (rtb_VectorConcatenate_g[2] - rtb_VectorConcatenate_g[6])
        / rtb_DiscreteTimeIntegrator_g;
      INS_B.Merge_l[3] = (rtb_VectorConcatenate_g[3] - rtb_VectorConcatenate_g[1])
        / rtb_DiscreteTimeIntegrator_g;

      /* End of Outputs for SubSystem: '<S151>/Positive Trace' */

      /* Outputs for IfAction SubSystem: '<S151>/Negative Trace' incorporates:
       *  ActionPort: '<S161>/Action Port'
       */
    } else if ((rtb_VectorConcatenate_g[4] > rtb_VectorConcatenate_g[0]) &&
               (rtb_VectorConcatenate_g[4] > rtb_VectorConcatenate_g[8])) {
      /* Outputs for IfAction SubSystem: '<S161>/Maximum Value at DCM(2,2)' incorporates:
       *  ActionPort: '<S164>/Action Port'
       */
      /* If: '<S161>/Find Maximum Diagonal Value' incorporates:
       *  Constant: '<S175>/Constant1'
       *  Constant: '<S175>/Constant2'
       *  Constant: '<S176>/Constant'
       *  Gain: '<S164>/Gain'
       *  Gain: '<S164>/Gain1'
       *  Gain: '<S164>/Gain3'
       *  Gain: '<S164>/Gain4'
       *  Merge: '<S151>/Merge'
       *  Product: '<S164>/Product'
       *  Product: '<S175>/Product'
       *  Sqrt: '<S164>/sqrt'
       *  Sum: '<S172>/Add'
       *  Sum: '<S173>/Add'
       *  Sum: '<S174>/Add'
       *  Sum: '<S176>/Add'
       *  Switch: '<S175>/Switch'
       */
      rtb_DiscreteTimeIntegrator_g = sqrtf(((rtb_VectorConcatenate_g[4] -
        rtb_VectorConcatenate_g[0]) - rtb_VectorConcatenate_g[8]) +
        INS_P.Constant_Value_ae);
      INS_B.Merge_l[2] = INS_P.Gain_Gain_k * rtb_DiscreteTimeIntegrator_g;
      if (rtb_DiscreteTimeIntegrator_g != 0.0F) {
        rtb_Switch_kj_idx_0 = INS_P.Constant1_Value_e;
      } else {
        rtb_Switch_kj_idx_0 = INS_P.Constant2_Value_az[0];
        rtb_DiscreteTimeIntegrator_g = INS_P.Constant2_Value_az[1];
      }

      rtb_DiscreteTimeIntegrator_g = rtb_Switch_kj_idx_0 /
        rtb_DiscreteTimeIntegrator_g;
      INS_B.Merge_l[1] = (rtb_VectorConcatenate_g[1] + rtb_VectorConcatenate_g[3])
        * rtb_DiscreteTimeIntegrator_g * INS_P.Gain1_Gain_g4;
      INS_B.Merge_l[3] = (rtb_VectorConcatenate_g[5] + rtb_VectorConcatenate_g[7])
        * rtb_DiscreteTimeIntegrator_g * INS_P.Gain3_Gain;
      INS_B.Merge_l[0] = (rtb_VectorConcatenate_g[2] - rtb_VectorConcatenate_g[6])
        * rtb_DiscreteTimeIntegrator_g * INS_P.Gain4_Gain;

      /* End of Outputs for SubSystem: '<S161>/Maximum Value at DCM(2,2)' */
    } else if (rtb_VectorConcatenate_g[8] > rtb_VectorConcatenate_g[0]) {
      /* Outputs for IfAction SubSystem: '<S161>/Maximum Value at DCM(3,3)' incorporates:
       *  ActionPort: '<S165>/Action Port'
       */
      /* If: '<S161>/Find Maximum Diagonal Value' incorporates:
       *  Constant: '<S180>/Constant1'
       *  Constant: '<S180>/Constant2'
       *  Constant: '<S181>/Constant'
       *  Gain: '<S165>/Gain'
       *  Gain: '<S165>/Gain1'
       *  Gain: '<S165>/Gain2'
       *  Gain: '<S165>/Gain3'
       *  Merge: '<S151>/Merge'
       *  Product: '<S165>/Product'
       *  Product: '<S180>/Product'
       *  Sqrt: '<S165>/sqrt'
       *  Sum: '<S177>/Add'
       *  Sum: '<S178>/Add'
       *  Sum: '<S179>/Add'
       *  Sum: '<S181>/Add'
       *  Switch: '<S180>/Switch'
       */
      rtb_DiscreteTimeIntegrator_g = sqrtf(((rtb_VectorConcatenate_g[8] -
        rtb_VectorConcatenate_g[0]) - rtb_VectorConcatenate_g[4]) +
        INS_P.Constant_Value_f2);
      INS_B.Merge_l[3] = INS_P.Gain_Gain_l * rtb_DiscreteTimeIntegrator_g;
      if (rtb_DiscreteTimeIntegrator_g != 0.0F) {
        rtb_Switch_kj_idx_0 = INS_P.Constant1_Value_l;
      } else {
        rtb_Switch_kj_idx_0 = INS_P.Constant2_Value_o[0];
        rtb_DiscreteTimeIntegrator_g = INS_P.Constant2_Value_o[1];
      }

      rtb_DiscreteTimeIntegrator_g = rtb_Switch_kj_idx_0 /
        rtb_DiscreteTimeIntegrator_g;
      INS_B.Merge_l[1] = (rtb_VectorConcatenate_g[2] + rtb_VectorConcatenate_g[6])
        * rtb_DiscreteTimeIntegrator_g * INS_P.Gain1_Gain_m;
      INS_B.Merge_l[2] = (rtb_VectorConcatenate_g[5] + rtb_VectorConcatenate_g[7])
        * rtb_DiscreteTimeIntegrator_g * INS_P.Gain2_Gain_o;
      INS_B.Merge_l[0] = (rtb_VectorConcatenate_g[3] - rtb_VectorConcatenate_g[1])
        * rtb_DiscreteTimeIntegrator_g * INS_P.Gain3_Gain_e;

      /* End of Outputs for SubSystem: '<S161>/Maximum Value at DCM(3,3)' */
    } else {
      /* Outputs for IfAction SubSystem: '<S161>/Maximum Value at DCM(1,1)' incorporates:
       *  ActionPort: '<S163>/Action Port'
       */
      /* If: '<S161>/Find Maximum Diagonal Value' incorporates:
       *  Constant: '<S170>/Constant1'
       *  Constant: '<S170>/Constant2'
       *  Constant: '<S171>/Constant'
       *  Gain: '<S163>/Gain'
       *  Gain: '<S163>/Gain1'
       *  Gain: '<S163>/Gain2'
       *  Gain: '<S163>/Gain3'
       *  Merge: '<S151>/Merge'
       *  Product: '<S163>/Product'
       *  Product: '<S170>/Product'
       *  Sqrt: '<S163>/sqrt'
       *  Sum: '<S167>/Add'
       *  Sum: '<S168>/Add'
       *  Sum: '<S169>/Add'
       *  Sum: '<S171>/Add'
       *  Switch: '<S170>/Switch'
       */
      rtb_DiscreteTimeIntegrator_g = sqrtf(((rtb_VectorConcatenate_g[0] -
        rtb_VectorConcatenate_g[4]) - rtb_VectorConcatenate_g[8]) +
        INS_P.Constant_Value_hd);
      INS_B.Merge_l[1] = INS_P.Gain_Gain_g * rtb_DiscreteTimeIntegrator_g;
      if (rtb_DiscreteTimeIntegrator_g != 0.0F) {
        rtb_Switch_kj_idx_0 = INS_P.Constant1_Value_a;
      } else {
        rtb_Switch_kj_idx_0 = INS_P.Constant2_Value_m[0];
        rtb_DiscreteTimeIntegrator_g = INS_P.Constant2_Value_m[1];
      }

      rtb_DiscreteTimeIntegrator_g = rtb_Switch_kj_idx_0 /
        rtb_DiscreteTimeIntegrator_g;
      INS_B.Merge_l[2] = (rtb_VectorConcatenate_g[1] + rtb_VectorConcatenate_g[3])
        * rtb_DiscreteTimeIntegrator_g * INS_P.Gain1_Gain_ig;
      INS_B.Merge_l[3] = (rtb_VectorConcatenate_g[2] + rtb_VectorConcatenate_g[6])
        * rtb_DiscreteTimeIntegrator_g * INS_P.Gain2_Gain_mx;
      INS_B.Merge_l[0] = (rtb_VectorConcatenate_g[7] - rtb_VectorConcatenate_g[5])
        * rtb_DiscreteTimeIntegrator_g * INS_P.Gain3_Gain_ea;

      /* End of Outputs for SubSystem: '<S161>/Maximum Value at DCM(1,1)' */

      /* End of Outputs for SubSystem: '<S151>/Negative Trace' */
    }

    /* End of If: '<S151>/If' */

    /* SignalConversion generated from: '<S130>/quat_0' */
    INS_B.OutportBufferForquat_0[0] = INS_B.Merge_l[0];
    INS_B.OutportBufferForquat_0[1] = INS_B.Merge_l[1];
    INS_B.OutportBufferForquat_0[2] = INS_B.Merge_l[2];
    INS_B.OutportBufferForquat_0[3] = INS_B.Merge_l[3];
  }

  /* End of Outputs for SubSystem: '<S58>/Initial_Attitude' */

  /* Logic: '<S131>/Logical Operator5' incorporates:
   *  Constant: '<S131>/Constant1'
   *  Logic: '<S131>/Logical Operator3'
   *  Logic: '<S131>/Logical Operator4'
   */
  rtb_WGS84_pos_valid = ((!rtb_LogicalOperator5) && (rtb_mag_valid != 0.0F) &&
    ((INS_PARAM.MAG_AIR_EN != 0) || (rtb_Relay != 0.0F)));

  /* Update for UnitDelay: '<S135>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_pr = rtb_Compare_o;

  /* Update for Delay: '<S141>/Delay' */
  INS_DWork.Delay_DSTATE_i = rtb_Sum1;

  /* Update for UnitDelay: '<S136>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_nk = rtb_Compare_fo;

  /* Update for Delay: '<S142>/Delay' */
  INS_DWork.Delay_DSTATE_ly = rtb_Sum1_o;

  /* Update for Delay: '<S137>/Delay' */
  INS_DWork.Delay_DSTATE_n = rtb_Saturation_mp;

  /* Update for UnitDelay: '<S145>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_mm = rtb_Compare_ir;

  /* Update for DiscreteIntegrator: '<S191>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S191>/Gain'
   *  Sum: '<S191>/Sum5'
   */
  INS_DWork.DiscreteTimeIntegrator5_IC_LO_p = 0U;
  INS_DWork.DiscreteTimeIntegrator5_DSTAT_o[0] += INS_P.Gain_Gain_fr *
    rtb_DataTypeConversion_l_idx_0 * INS_P.DiscreteTimeIntegrator5_gainval;
  INS_DWork.DiscreteTimeIntegrator5_DSTAT_o[1] += INS_P.Gain_Gain_fr *
    rtb_DiscreteTimeIntegrator1_p_i * INS_P.DiscreteTimeIntegrator5_gainval;

  /* Update for DiscreteIntegrator: '<S189>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S189>/Gain'
   *  MinMax: '<S132>/MinMax1'
   *  Sum: '<S189>/Sum5'
   */
  INS_DWork.DiscreteTimeIntegrator5_IC_LO_n = 0U;
  INS_DWork.DiscreteTimeIntegrator5_DSTAT_m += (rtb_DiscreteTimeIntegrator_nt -
    INS_DWork.DiscreteTimeIntegrator5_DSTAT_m) * INS_P.Gain_Gain_je *
    INS_P.DiscreteTimeIntegrator5_gainv_n;

  /* Update for DiscreteIntegrator: '<S190>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S190>/Gain'
   *  Sum: '<S190>/Sum5'
   */
  INS_DWork.DiscreteTimeIntegrator5_IC_L_ns = 0U;
  INS_DWork.DiscreteTimeIntegrator5_DSTA_ow += (rtb_DiscreteTimeIntegrator_eh -
    INS_DWork.DiscreteTimeIntegrator5_DSTA_ow) * INS_P.Gain_Gain_h *
    INS_P.DiscreteTimeIntegrator5_gainv_m;

  /* End of Outputs for SubSystem: '<S55>/RF_Data_PreProcess' */

  /* Outputs for Atomic SubSystem: '<S55>/AHRS' */
  /* Outputs for Atomic SubSystem: '<S57>/Update' */
  /* Delay: '<S114>/Delay1' */
  if (INS_DWork.icLoad_o2) {
    INS_DWork.Delay1_DSTATE_e[0] = INS_B.OutportBufferForquat_0[0];
    INS_DWork.Delay1_DSTATE_e[1] = INS_B.OutportBufferForquat_0[1];
    INS_DWork.Delay1_DSTATE_e[2] = INS_B.OutportBufferForquat_0[2];
    INS_DWork.Delay1_DSTATE_e[3] = INS_B.OutportBufferForquat_0[3];
  }

  /* Outputs for Atomic SubSystem: '<S57>/Bus_Constructor' */
  /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
  /* Outputs for Atomic SubSystem: '<S3>/IMU_PreProcess' */
  /* Sum: '<S115>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S115>/Discrete-Time Integrator2'
   *  Inport: '<Root>/IMU'
   *  SignalConversion generated from: '<S436>/Bus Selector1'
   *  Sum: '<S59>/Sum'
   */
  Constant_Value_b = INS_DWork.DiscreteTimeIntegrator2_DSTATE[0] +
    INS_U.IMU.gyr_x;

  /* End of Outputs for SubSystem: '<S3>/IMU_PreProcess' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */
  /* End of Outputs for SubSystem: '<S57>/Bus_Constructor' */
  /* End of Outputs for SubSystem: '<S57>/Update' */
  /* End of Outputs for SubSystem: '<S55>/AHRS' */
  /* End of Outputs for SubSystem: '<Root>/Data_Fusion' */
  rtb_VectorConcatenate_idx_0 = Constant_Value_b;

  /* Outputs for Atomic SubSystem: '<Root>/Data_Fusion' */
  /* Outputs for Atomic SubSystem: '<S55>/AHRS' */
  /* Outputs for Atomic SubSystem: '<S57>/Update' */
  /* Sum: '<S61>/Sum2' incorporates:
   *  Delay: '<S57>/Delay1'
   *  Gain: '<S69>/Gain1'
   *  Sum: '<S115>/Sum1'
   */
  rtb_Gain1_n_idx_0 = INS_DWork.Delay1_DSTATE_h[0] + Constant_Value_b;

  /* Outputs for Atomic SubSystem: '<S57>/Bus_Constructor' */
  /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
  /* Outputs for Atomic SubSystem: '<S3>/IMU_PreProcess' */
  /* Sum: '<S115>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S115>/Discrete-Time Integrator2'
   *  Inport: '<Root>/IMU'
   *  SignalConversion generated from: '<S436>/Bus Selector1'
   *  Sum: '<S59>/Sum'
   */
  Constant_Value_b = INS_DWork.DiscreteTimeIntegrator2_DSTATE[1] +
    INS_U.IMU.gyr_y;

  /* End of Outputs for SubSystem: '<S3>/IMU_PreProcess' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */
  /* End of Outputs for SubSystem: '<S57>/Bus_Constructor' */
  /* End of Outputs for SubSystem: '<S57>/Update' */
  /* End of Outputs for SubSystem: '<S55>/AHRS' */
  /* End of Outputs for SubSystem: '<Root>/Data_Fusion' */
  rtb_VectorConcatenate_idx_1 = Constant_Value_b;

  /* Outputs for Atomic SubSystem: '<Root>/Data_Fusion' */
  /* Outputs for Atomic SubSystem: '<S55>/AHRS' */
  /* Outputs for Atomic SubSystem: '<S57>/Update' */
  /* Sum: '<S61>/Sum2' incorporates:
   *  Delay: '<S57>/Delay1'
   *  Gain: '<S69>/Gain1'
   *  Sum: '<S115>/Sum1'
   */
  rtb_Gain1_n_idx_1 = INS_DWork.Delay1_DSTATE_h[1] + Constant_Value_b;

  /* Outputs for Atomic SubSystem: '<S57>/Bus_Constructor' */
  /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
  /* Outputs for Atomic SubSystem: '<S3>/IMU_PreProcess' */
  /* Sum: '<S115>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S115>/Discrete-Time Integrator2'
   *  Inport: '<Root>/IMU'
   *  SignalConversion generated from: '<S436>/Bus Selector1'
   *  Sum: '<S59>/Sum'
   */
  Constant_Value_b = INS_DWork.DiscreteTimeIntegrator2_DSTATE[2] +
    INS_U.IMU.gyr_z;

  /* End of Outputs for SubSystem: '<S3>/IMU_PreProcess' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */
  /* End of Outputs for SubSystem: '<S57>/Bus_Constructor' */

  /* Sum: '<S61>/Sum2' incorporates:
   *  Delay: '<S57>/Delay1'
   *  Gain: '<S69>/Gain1'
   *  Sum: '<S115>/Sum1'
   */
  rtb_Gain1_n_idx_2 = INS_DWork.Delay1_DSTATE_h[2] + Constant_Value_b;

  /* Sum: '<S114>/Sum' incorporates:
   *  Constant: '<S114>/Constant'
   *  Delay: '<S114>/Delay1'
   *  Gain: '<S114>/Gain1'
   *  Gain: '<S114>/dT'
   *  Product: '<S119>/Multiply'
   *  Product: '<S119>/Multiply1'
   *  Product: '<S119>/Multiply2'
   *  Product: '<S119>/Multiply3'
   *  Product: '<S120>/Multiply'
   *  Product: '<S120>/Multiply1'
   *  Product: '<S120>/Multiply2'
   *  Product: '<S120>/Multiply3'
   *  Product: '<S121>/Multiply'
   *  Product: '<S121>/Multiply1'
   *  Product: '<S121>/Multiply2'
   *  Product: '<S121>/Multiply3'
   *  Product: '<S122>/Multiply'
   *  Product: '<S122>/Multiply1'
   *  Product: '<S122>/Multiply2'
   *  Product: '<S122>/Multiply3'
   *  Sum: '<S119>/Add'
   *  Sum: '<S120>/Add'
   *  Sum: '<S121>/Add'
   *  Sum: '<S122>/Add'
   */
  rtb_Switch_kj_idx_0 = (((INS_DWork.Delay1_DSTATE_e[0] * INS_P.Constant_Value_p
    - rtb_Gain1_n_idx_0 * INS_DWork.Delay1_DSTATE_e[1]) - rtb_Gain1_n_idx_1 *
    INS_DWork.Delay1_DSTATE_e[2]) - rtb_Gain1_n_idx_2 *
    INS_DWork.Delay1_DSTATE_e[3]) * INS_P.Gain1_Gain_e * INS_P.dT_Gain +
    INS_DWork.Delay1_DSTATE_e[0];
  rtb_Switch_kj_idx_1 = (((INS_DWork.Delay1_DSTATE_e[1] * INS_P.Constant_Value_p
    + INS_DWork.Delay1_DSTATE_e[0] * rtb_Gain1_n_idx_0) +
    INS_DWork.Delay1_DSTATE_e[2] * rtb_Gain1_n_idx_2) - rtb_Gain1_n_idx_1 *
    INS_DWork.Delay1_DSTATE_e[3]) * INS_P.Gain1_Gain_e * INS_P.dT_Gain +
    INS_DWork.Delay1_DSTATE_e[1];
  rtb_Switch_kj_idx_2 = (((INS_DWork.Delay1_DSTATE_e[2] * INS_P.Constant_Value_p
    + INS_DWork.Delay1_DSTATE_e[0] * rtb_Gain1_n_idx_1) + rtb_Gain1_n_idx_0 *
    INS_DWork.Delay1_DSTATE_e[3]) - INS_DWork.Delay1_DSTATE_e[1] *
    rtb_Gain1_n_idx_2) * INS_P.Gain1_Gain_e * INS_P.dT_Gain +
    INS_DWork.Delay1_DSTATE_e[2];
  rtb_DiscreteTimeIntegrator_g = (((INS_DWork.Delay1_DSTATE_e[3] *
    INS_P.Constant_Value_p + INS_DWork.Delay1_DSTATE_e[0] * rtb_Gain1_n_idx_2) +
    INS_DWork.Delay1_DSTATE_e[1] * rtb_Gain1_n_idx_1) - rtb_Gain1_n_idx_0 *
    INS_DWork.Delay1_DSTATE_e[2]) * INS_P.Gain1_Gain_e * INS_P.dT_Gain +
    INS_DWork.Delay1_DSTATE_e[3];

  /* Sqrt: '<S123>/Sqrt' incorporates:
   *  Math: '<S123>/Square'
   *  Sum: '<S123>/Sum of Elements'
   */
  rtb_DiscreteTimeIntegrator_nt = sqrtf(((rtb_Switch_kj_idx_0 *
    rtb_Switch_kj_idx_0 + rtb_Switch_kj_idx_1 * rtb_Switch_kj_idx_1) +
    rtb_Switch_kj_idx_2 * rtb_Switch_kj_idx_2) + rtb_DiscreteTimeIntegrator_g *
    rtb_DiscreteTimeIntegrator_g);

  /* Product: '<S117>/Divide' */
  rtb_Switch_kj_0 = rtb_Switch_kj_idx_0 / rtb_DiscreteTimeIntegrator_nt;
  rtb_Switch_kj_idx_0 = rtb_Switch_kj_0;

  /* Outputs for Atomic SubSystem: '<S57>/Bus_Constructor' */
  /* Math: '<S128>/Square' incorporates:
   *  Math: '<S66>/Square'
   */
  rtb_Gain_ca_idx_1 = rtb_Switch_kj_0 * rtb_Switch_kj_0;

  /* End of Outputs for SubSystem: '<S57>/Bus_Constructor' */

  /* Product: '<S117>/Divide' */
  rtb_Switch_kj_0 = rtb_Switch_kj_idx_1 / rtb_DiscreteTimeIntegrator_nt;
  rtb_Switch_kj_idx_1 = rtb_Switch_kj_0;

  /* Outputs for Atomic SubSystem: '<S57>/Bus_Constructor' */
  /* Math: '<S128>/Square' incorporates:
   *  Math: '<S66>/Square'
   */
  rtb_Gain_ca_idx_2 = rtb_Switch_kj_0 * rtb_Switch_kj_0;

  /* End of Outputs for SubSystem: '<S57>/Bus_Constructor' */

  /* Product: '<S117>/Divide' */
  rtb_Switch_kj_0 = rtb_Switch_kj_idx_2 / rtb_DiscreteTimeIntegrator_nt;
  rtb_Switch_kj_idx_2 = rtb_Switch_kj_0;

  /* Outputs for Atomic SubSystem: '<S57>/Bus_Constructor' */
  /* Math: '<S128>/Square' incorporates:
   *  Math: '<S66>/Square'
   */
  rtb_DiscreteTimeIntegrator_eh = rtb_Switch_kj_0 * rtb_Switch_kj_0;

  /* End of Outputs for SubSystem: '<S57>/Bus_Constructor' */

  /* Product: '<S117>/Divide' */
  rtb_Switch_kj_0 = rtb_DiscreteTimeIntegrator_g / rtb_DiscreteTimeIntegrator_nt;

  /* Outputs for Atomic SubSystem: '<S57>/Bus_Constructor' */
  /* Sqrt: '<S128>/Sqrt' incorporates:
   *  Math: '<S128>/Square'
   *  Sqrt: '<S66>/Sqrt'
   *  Sum: '<S128>/Sum of Elements'
   */
  rtb_Gain_ca_idx_2 = sqrtf(((rtb_Gain_ca_idx_1 + rtb_Gain_ca_idx_2) +
    rtb_DiscreteTimeIntegrator_eh) + rtb_Switch_kj_0 * rtb_Switch_kj_0);

  /* Product: '<S124>/Divide' incorporates:
   *  Product: '<S117>/Divide'
   *  Product: '<S65>/Divide'
   *  Sqrt: '<S128>/Sqrt'
   */
  rtb_Gain_ca_idx_1 = rtb_Switch_kj_idx_0 / rtb_Gain_ca_idx_2;
  rtb_DiscreteTimeIntegrator_bq = rtb_Switch_kj_idx_1 / rtb_Gain_ca_idx_2;
  rtb_DiscreteTimeIntegrator1_p_i = rtb_Switch_kj_idx_2 / rtb_Gain_ca_idx_2;
  rtb_Gain1_n_idx_2 = rtb_Switch_kj_0 / rtb_Gain_ca_idx_2;

  /* End of Outputs for SubSystem: '<S57>/Bus_Constructor' */

  /* Math: '<S125>/Square' incorporates:
   *  Math: '<S126>/Square'
   *  Math: '<S127>/Square'
   *  Product: '<S124>/Divide'
   */
  rtb_DataTypeConversion_l_idx_0 = rtb_Gain_ca_idx_1 * rtb_Gain_ca_idx_1;

  /* Outputs for Atomic SubSystem: '<S57>/Bus_Constructor' */
  /* Math: '<S125>/Square2' incorporates:
   *  Math: '<S126>/Square2'
   *  Math: '<S127>/Square2'
   *  Math: '<S64>/Square1'
   *  Product: '<S124>/Divide'
   */
  rtb_Gain_ca_idx_0 = rtb_DiscreteTimeIntegrator1_p_i *
    rtb_DiscreteTimeIntegrator1_p_i;

  /* End of Outputs for SubSystem: '<S57>/Bus_Constructor' */

  /* Math: '<S125>/Square1' incorporates:
   *  Math: '<S126>/Square1'
   *  Math: '<S127>/Square1'
   *  Product: '<S124>/Divide'
   */
  rtb_DiscreteTimeIntegrator_g = rtb_DiscreteTimeIntegrator_bq *
    rtb_DiscreteTimeIntegrator_bq;

  /* Math: '<S125>/Square3' incorporates:
   *  Math: '<S126>/Square3'
   *  Math: '<S127>/Square3'
   *  Product: '<S124>/Divide'
   */
  rtb_Gain1_n_idx_0 = rtb_Gain1_n_idx_2 * rtb_Gain1_n_idx_2;

  /* Outputs for Atomic SubSystem: '<S57>/Bus_Constructor' */
  /* Sum: '<S125>/Add1' incorporates:
   *  Math: '<S125>/Square2'
   *  Math: '<S125>/Square3'
   *  Sum: '<S64>/Add3'
   */
  rtb_Gain_ca_idx_2 = rtb_Gain_ca_idx_0 + rtb_Gain1_n_idx_0;

  /* End of Outputs for SubSystem: '<S57>/Bus_Constructor' */

  /* Sum: '<S125>/Subtract' incorporates:
   *  Math: '<S125>/Square'
   *  Math: '<S125>/Square1'
   *  Sum: '<S125>/Add'
   *  Sum: '<S125>/Add1'
   */
  rtb_M_OC[0] = (rtb_DataTypeConversion_l_idx_0 + rtb_DiscreteTimeIntegrator_g)
    - rtb_Gain_ca_idx_2;

  /* Product: '<S125>/Multiply' incorporates:
   *  Product: '<S124>/Divide'
   *  Product: '<S126>/Multiply'
   */
  rtb_DiscreteTimeIntegrator_eh = rtb_DiscreteTimeIntegrator_bq *
    rtb_DiscreteTimeIntegrator1_p_i;

  /* Product: '<S125>/Multiply1' incorporates:
   *  Product: '<S124>/Divide'
   *  Product: '<S126>/Multiply1'
   */
  rtb_DiscreteTimeIntegrator_nt = rtb_Gain_ca_idx_1 * rtb_Gain1_n_idx_2;

  /* Gain: '<S125>/Gain' incorporates:
   *  Product: '<S125>/Multiply'
   *  Product: '<S125>/Multiply1'
   *  Sum: '<S125>/Subtract1'
   */
  rtb_M_OC[1] = (rtb_DiscreteTimeIntegrator_eh - rtb_DiscreteTimeIntegrator_nt) *
    INS_P.Gain_Gain_e;

  /* Outputs for Atomic SubSystem: '<S57>/Bus_Constructor' */
  /* Product: '<S125>/Multiply2' incorporates:
   *  Product: '<S124>/Divide'
   *  Product: '<S127>/Multiply'
   *  Product: '<S64>/Multiply5'
   */
  rtb_Gain1_n_idx_1 = rtb_DiscreteTimeIntegrator_bq * rtb_Gain1_n_idx_2;

  /* Product: '<S125>/Multiply3' incorporates:
   *  Product: '<S124>/Divide'
   *  Product: '<S127>/Multiply1'
   *  Product: '<S64>/Multiply4'
   */
  u0 = rtb_Gain_ca_idx_1 * rtb_DiscreteTimeIntegrator1_p_i;

  /* End of Outputs for SubSystem: '<S57>/Bus_Constructor' */

  /* Gain: '<S125>/Gain1' incorporates:
   *  Product: '<S125>/Multiply2'
   *  Product: '<S125>/Multiply3'
   *  Sum: '<S125>/Add2'
   */
  rtb_M_OC[2] = (rtb_Gain1_n_idx_1 + u0) * INS_P.Gain1_Gain_pl;

  /* Outputs for Atomic SubSystem: '<S57>/Bus_Constructor' */
  /* Sum: '<S126>/Add3' incorporates:
   *  Sum: '<S64>/Add2'
   */
  rtb_DiscreteTimeIntegrator_eh += rtb_DiscreteTimeIntegrator_nt;

  /* End of Outputs for SubSystem: '<S57>/Bus_Constructor' */

  /* Gain: '<S126>/Gain' incorporates:
   *  Sum: '<S126>/Add3'
   */
  rtb_M_OC[3] = rtb_DiscreteTimeIntegrator_eh * INS_P.Gain_Gain_j;

  /* Sum: '<S126>/Subtract' incorporates:
   *  Sum: '<S126>/Add'
   *  Sum: '<S126>/Add1'
   */
  rtb_M_OC[4] = (rtb_DataTypeConversion_l_idx_0 + rtb_Gain_ca_idx_0) -
    (rtb_DiscreteTimeIntegrator_g + rtb_Gain1_n_idx_0);

  /* Product: '<S126>/Multiply2' incorporates:
   *  Product: '<S124>/Divide'
   *  Product: '<S127>/Multiply2'
   */
  rtb_DiscreteTimeIntegrator_nt = rtb_DiscreteTimeIntegrator1_p_i *
    rtb_Gain1_n_idx_2;

  /* Product: '<S126>/Multiply3' incorporates:
   *  Product: '<S124>/Divide'
   *  Product: '<S127>/Multiply3'
   */
  rtb_Gain_ca_idx_1 *= rtb_DiscreteTimeIntegrator_bq;

  /* Gain: '<S126>/Gain1' incorporates:
   *  Product: '<S126>/Multiply2'
   *  Product: '<S126>/Multiply3'
   *  Sum: '<S126>/Subtract1'
   */
  rtb_M_OC[5] = (rtb_DiscreteTimeIntegrator_nt - rtb_Gain_ca_idx_1) *
    INS_P.Gain1_Gain_b;

  /* Gain: '<S127>/Gain' incorporates:
   *  Sum: '<S127>/Subtract2'
   */
  rtb_M_OC[6] = (rtb_Gain1_n_idx_1 - u0) * INS_P.Gain_Gain_o;

  /* Outputs for Atomic SubSystem: '<S57>/Bus_Constructor' */
  /* Sum: '<S127>/Add2' incorporates:
   *  Sum: '<S64>/Add'
   */
  rtb_DiscreteTimeIntegrator_nt += rtb_Gain_ca_idx_1;

  /* End of Outputs for SubSystem: '<S57>/Bus_Constructor' */

  /* Gain: '<S127>/Gain1' incorporates:
   *  Sum: '<S127>/Add2'
   */
  rtb_M_OC[7] = rtb_DiscreteTimeIntegrator_nt * INS_P.Gain1_Gain_f;

  /* Outputs for Atomic SubSystem: '<S57>/Bus_Constructor' */
  /* Sum: '<S127>/Add1' incorporates:
   *  Sum: '<S64>/Add1'
   */
  rtb_Gain_ca_idx_0 += rtb_DiscreteTimeIntegrator_g;

  /* End of Outputs for SubSystem: '<S57>/Bus_Constructor' */

  /* Sum: '<S127>/Subtract' incorporates:
   *  Sum: '<S127>/Add'
   *  Sum: '<S127>/Add1'
   */
  rtb_M_OC[8] = (rtb_DataTypeConversion_l_idx_0 + rtb_Gain1_n_idx_0) -
    rtb_Gain_ca_idx_0;

  /* Math: '<S114>/Transpose' incorporates:
   *  Math: '<S324>/Transpose'
   */
  for (rtb_MathFunction1_tmp = 0; rtb_MathFunction1_tmp < 3;
       rtb_MathFunction1_tmp++) {
    rtb_VectorConcatenate_g[3 * rtb_MathFunction1_tmp] =
      rtb_M_OC[rtb_MathFunction1_tmp];
    rtb_VectorConcatenate_g[3 * rtb_MathFunction1_tmp + 1] =
      rtb_M_OC[rtb_MathFunction1_tmp + 3];
    rtb_VectorConcatenate_g[3 * rtb_MathFunction1_tmp + 2] =
      rtb_M_OC[rtb_MathFunction1_tmp + 6];
  }

  /* End of Math: '<S114>/Transpose' */
  /* End of Outputs for SubSystem: '<S57>/Update' */

  /* Outputs for Atomic SubSystem: '<S57>/Bus_Constructor' */
  /* Product: '<S64>/Multiply6' incorporates:
   *  Constant: '<S64>/Constant'
   *  Sum: '<S64>/Subtract'
   */
  rtb_DiscreteTimeIntegrator_g = (u0 - rtb_Gain1_n_idx_1) *
    INS_P.Constant_Value_c;

  /* Saturate: '<S64>/Saturation' */
  if (rtb_DiscreteTimeIntegrator_g > INS_P.Saturation_UpperSat_h) {
    rtb_DiscreteTimeIntegrator_g = INS_P.Saturation_UpperSat_h;
  } else if (rtb_DiscreteTimeIntegrator_g < INS_P.Saturation_LowerSat_m) {
    rtb_DiscreteTimeIntegrator_g = INS_P.Saturation_LowerSat_m;
  }

  /* End of Saturate: '<S64>/Saturation' */

  /* Trigonometry: '<S64>/Asin' */
  if (rtb_DiscreteTimeIntegrator_g > 1.0F) {
    rtb_DiscreteTimeIntegrator_g = 1.0F;
  } else if (rtb_DiscreteTimeIntegrator_g < -1.0F) {
    rtb_DiscreteTimeIntegrator_g = -1.0F;
  }

  rtb_Gain_ca_idx_1 = asinf(rtb_DiscreteTimeIntegrator_g);

  /* End of Trigonometry: '<S64>/Asin' */

  /* Trigonometry: '<S64>/Atan1' incorporates:
   *  Constant: '<S64>/Constant'
   *  Constant: '<S64>/Constant1'
   *  Product: '<S64>/Multiply10'
   *  Product: '<S64>/Multiply9'
   *  Sum: '<S64>/Subtract1'
   */
  rtb_Gain_ca_idx_2 = atan2f(rtb_DiscreteTimeIntegrator_eh *
    INS_P.Constant_Value_c, INS_P.Constant1_Value_o - rtb_Gain_ca_idx_2 *
    INS_P.Constant_Value_c);

  /* Trigonometry: '<S64>/Atan2' incorporates:
   *  Constant: '<S64>/Constant'
   *  Constant: '<S64>/Constant2'
   *  Product: '<S64>/Multiply'
   *  Product: '<S64>/Multiply3'
   *  Sum: '<S64>/Subtract2'
   */
  rtb_Gain_ca_idx_0 = atan2f(rtb_DiscreteTimeIntegrator_nt *
    INS_P.Constant_Value_c, INS_P.Constant2_Value_d - rtb_Gain_ca_idx_0 *
    INS_P.Constant_Value_c);

  /* Gain: '<S63>/Gain' */
  rtb_DiscreteTimeIntegrator_nt = INS_P.Gain_Gain_f * rtb_Gain_ca_idx_2;

  /* Constant: '<S67>/Constant' */
  rtb_VectorConcatenate_c2[8] = INS_P.Constant_Value_j1;

  /* Constant: '<S67>/Constant1' */
  rtb_VectorConcatenate_c2[7] = INS_P.Constant1_Value_j;

  /* Constant: '<S67>/Constant2' */
  rtb_VectorConcatenate_c2[6] = INS_P.Constant2_Value_a;

  /* Constant: '<S67>/Constant3' */
  rtb_VectorConcatenate_c2[2] = INS_P.Constant3_Value;

  /* Constant: '<S67>/Constant4' */
  rtb_VectorConcatenate_c2[5] = INS_P.Constant4_Value;

  /* Trigonometry: '<S67>/Trigonometric Function2' incorporates:
   *  Trigonometry: '<S67>/Trigonometric Function'
   */
  rtb_DiscreteTimeIntegrator_bq = csi_sin_f32(rtb_DiscreteTimeIntegrator_nt);

  /* Gain: '<S67>/Gain' incorporates:
   *  Trigonometry: '<S67>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_c2[3] = INS_P.Gain_Gain_n *
    rtb_DiscreteTimeIntegrator_bq;

  /* Trigonometry: '<S67>/Trigonometric Function' */
  rtb_VectorConcatenate_c2[1] = rtb_DiscreteTimeIntegrator_bq;

  /* Trigonometry: '<S67>/Trigonometric Function1' incorporates:
   *  Trigonometry: '<S67>/Trigonometric Function3'
   */
  rtb_DiscreteTimeIntegrator_bq = csi_cos_f32(rtb_DiscreteTimeIntegrator_nt);
  rtb_VectorConcatenate_c2[0] = rtb_DiscreteTimeIntegrator_bq;

  /* Trigonometry: '<S67>/Trigonometric Function3' */
  rtb_VectorConcatenate_c2[4] = rtb_DiscreteTimeIntegrator_bq;

  /* Outputs for Atomic SubSystem: '<S57>/Correct' */
  for (rtb_MathFunction1_tmp = 0; rtb_MathFunction1_tmp < 3;
       rtb_MathFunction1_tmp++) {
    /* Math: '<S59>/Math Function' incorporates:
     *  Math: '<S114>/Transpose'
     */
    rtb_DiscreteTimeIntegrator_nt =
      rtb_VectorConcatenate_g[rtb_MathFunction1_tmp];
    rtb_M_BO_c[3 * rtb_MathFunction1_tmp] = rtb_DiscreteTimeIntegrator_nt;

    /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
    /* Outputs for Atomic SubSystem: '<S3>/IMU_PreProcess' */
    /* Product: '<S87>/Multiply' incorporates:
     *  Inport: '<Root>/IMU'
     *  SignalConversion generated from: '<S436>/Bus Selector1'
     */
    rtb_DiscreteTimeIntegrator_eh = rtb_DiscreteTimeIntegrator_nt *
      INS_U.IMU.acc_x;

    /* End of Outputs for SubSystem: '<S3>/IMU_PreProcess' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */

    /* Math: '<S59>/Math Function' incorporates:
     *  Math: '<S114>/Transpose'
     */
    rtb_DiscreteTimeIntegrator_nt =
      rtb_VectorConcatenate_g[rtb_MathFunction1_tmp + 3];
    rtb_M_BO_c[3 * rtb_MathFunction1_tmp + 1] = rtb_DiscreteTimeIntegrator_nt;

    /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
    /* Outputs for Atomic SubSystem: '<S3>/IMU_PreProcess' */
    /* Product: '<S87>/Multiply' incorporates:
     *  Inport: '<Root>/IMU'
     *  SignalConversion generated from: '<S436>/Bus Selector1'
     */
    rtb_DiscreteTimeIntegrator_eh += rtb_DiscreteTimeIntegrator_nt *
      INS_U.IMU.acc_y;

    /* End of Outputs for SubSystem: '<S3>/IMU_PreProcess' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */

    /* Math: '<S59>/Math Function' incorporates:
     *  Math: '<S114>/Transpose'
     */
    rtb_DiscreteTimeIntegrator_nt =
      rtb_VectorConcatenate_g[rtb_MathFunction1_tmp + 6];
    rtb_M_BO_c[3 * rtb_MathFunction1_tmp + 2] = rtb_DiscreteTimeIntegrator_nt;

    /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
    /* Outputs for Atomic SubSystem: '<S3>/IMU_PreProcess' */
    /* Product: '<S87>/Multiply' incorporates:
     *  Inport: '<Root>/IMU'
     *  SignalConversion generated from: '<S436>/Bus Selector1'
     */
    rtb_MathFunction_j[rtb_MathFunction1_tmp] = rtb_DiscreteTimeIntegrator_nt *
      INS_U.IMU.acc_z + rtb_DiscreteTimeIntegrator_eh;

    /* End of Outputs for SubSystem: '<S3>/IMU_PreProcess' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */
  }

  /* End of Outputs for SubSystem: '<S57>/Bus_Constructor' */

  /* DiscreteIntegrator: '<S89>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S89>/Constant'
   *  Product: '<S87>/Multiply'
   */
  if (INS_DWork.DiscreteTimeIntegrator1_IC_LO_i != 0) {
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_o[0] = rtb_MathFunction_j[0];
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_o[1] = rtb_MathFunction_j[1];
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_o[2] = rtb_MathFunction_j[2];
  }

  if ((INS_P.Constant_Value_g3 != 0.0F) ||
      (INS_DWork.DiscreteTimeIntegrator1_PrevR_p != 0)) {
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_o[0] = rtb_MathFunction_j[0];
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_o[1] = rtb_MathFunction_j[1];
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_o[2] = rtb_MathFunction_j[2];
  }

  rtb_DiscreteTimeIntegrator_eh = INS_DWork.DiscreteTimeIntegrator1_DSTAT_o[0];
  rtb_DiscreteTimeIntegrator1_p_i = INS_DWork.DiscreteTimeIntegrator1_DSTAT_o[1];
  rtb_DataTypeConversion_l_idx_0 = INS_DWork.DiscreteTimeIntegrator1_DSTAT_o[2];

  /* Relay: '<S93>/Relay' */
  INS_DWork.Relay_Mode_nf = ((rtb_Sum2_by >= INS_P.Relay_OnVal_j) ||
    ((rtb_Sum2_by > INS_P.Relay_OffVal_i) && INS_DWork.Relay_Mode_nf));
  if (INS_DWork.Relay_Mode_nf) {
    rtb_Gain1_n_idx_0 = INS_P.Relay_YOn_m;
  } else {
    rtb_Gain1_n_idx_0 = INS_P.Relay_YOff_n;
  }

  /* Logic: '<S93>/Logical Operator1' incorporates:
   *  Relay: '<S93>/Relay'
   */
  rtb_Compare_o = (rtb_Compare_cio && (rtb_Gain1_n_idx_0 != 0.0F));

  /* Product: '<S87>/Multiply2' incorporates:
   *  Constant: '<S87>/GPS_Delay'
   */
  rtb_DiscreteTimeIntegrator_nt = rtb_Compare_o ? (real32_T)
    INS_P.GPS_Delay_Value : 0.0F;

  /* Delay: '<S87>/Delay' incorporates:
   *  DiscreteIntegrator: '<S89>/Discrete-Time Integrator1'
   */
  if (rtb_DiscreteTimeIntegrator_nt < 1.0F) {
    rtb_Reshape_k[0] = INS_DWork.DiscreteTimeIntegrator1_DSTAT_o[0];
    rtb_Reshape_k[1] = INS_DWork.DiscreteTimeIntegrator1_DSTAT_o[1];
    rtb_Reshape_k[2] = INS_DWork.DiscreteTimeIntegrator1_DSTAT_o[2];
  } else {
    if (rtb_DiscreteTimeIntegrator_nt > 200.0F) {
      rtb_MathFunction1_tmp = 200;
    } else {
      rtb_MathFunction1_tmp = (int32_T)fmodf(rtb_DiscreteTimeIntegrator_nt,
        4.2949673E+9F);
    }

    rtb_Saturation1_j_idx_1 = (int32_T)(200U - (uint32_T)rtb_MathFunction1_tmp) *
      3;
    rtb_Reshape_k[0] = INS_DWork.Delay_DSTATE_lv[rtb_Saturation1_j_idx_1];
    rtb_Reshape_k[1] = INS_DWork.Delay_DSTATE_lv[rtb_Saturation1_j_idx_1 + 1];
    rtb_Reshape_k[2] = INS_DWork.Delay_DSTATE_lv[rtb_Saturation1_j_idx_1 + 2];
  }

  /* End of Delay: '<S87>/Delay' */

  /* RelationalOperator: '<S91>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S91>/Delay Input1'
   */
  rtb_Compare_fo = ((int32_T)rtb_Compare_o > (int32_T)
                    INS_DWork.DelayInput1_DSTATE_ff);

  /* Outputs for Enabled SubSystem: '<S88>/GPS_Meas_Acc' incorporates:
   *  EnablePort: '<S92>/Enable'
   */
  if (rtb_Compare_o) {
    if (!INS_DWork.GPS_Meas_Acc_MODE) {
      /* InitializeConditions for DiscreteIntegrator: '<S92>/Integrator' */
      INS_DWork.Integrator_DSTATE[0] = INS_P.Integrator_IC;
      INS_DWork.Integrator_DSTATE[1] = INS_P.Integrator_IC;
      INS_DWork.Integrator_DSTATE[2] = INS_P.Integrator_IC;
      INS_DWork.Integrator_PrevResetState = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S92>/Integrator1' */
      INS_DWork.Integrator1_PrevResetState = 0;
      INS_DWork.Integrator1_IC_LOADING = 1U;
      INS_DWork.GPS_Meas_Acc_MODE = true;
    }

    /* DiscreteIntegrator: '<S92>/Integrator' */
    if (rtb_Compare_fo || (INS_DWork.Integrator_PrevResetState != 0)) {
      INS_DWork.Integrator_DSTATE[0] = INS_P.Integrator_IC;
      INS_DWork.Integrator_DSTATE[1] = INS_P.Integrator_IC;
      INS_DWork.Integrator_DSTATE[2] = INS_P.Integrator_IC;
    }

    /* DiscreteIntegrator: '<S92>/Integrator' */
    INS_B.Integrator[0] = INS_DWork.Integrator_DSTATE[0];
    INS_B.Integrator[1] = INS_DWork.Integrator_DSTATE[1];
    INS_B.Integrator[2] = INS_DWork.Integrator_DSTATE[2];

    /* DiscreteIntegrator: '<S92>/Integrator1' */
    if (INS_DWork.Integrator1_IC_LOADING != 0) {
      INS_DWork.Integrator1_DSTATE[0] = rtb_Gain_ok;
      INS_DWork.Integrator1_DSTATE[1] = rtb_Gain1_k;
      INS_DWork.Integrator1_DSTATE[2] = rtb_Gain2_a;
    }

    if (rtb_Compare_fo || (INS_DWork.Integrator1_PrevResetState != 0)) {
      INS_DWork.Integrator1_DSTATE[0] = rtb_Gain_ok;
      INS_DWork.Integrator1_DSTATE[1] = rtb_Gain1_k;
      INS_DWork.Integrator1_DSTATE[2] = rtb_Gain2_a;
    }

    /* Sum: '<S92>/Sum1' incorporates:
     *  DiscreteIntegrator: '<S92>/Integrator1'
     */
    rtb_Multiply_me[0] = rtb_Gain_ok - INS_DWork.Integrator1_DSTATE[0];
    rtb_Multiply_me[1] = rtb_Gain1_k - INS_DWork.Integrator1_DSTATE[1];
    rtb_Multiply_me[2] = rtb_Gain2_a - INS_DWork.Integrator1_DSTATE[2];

    /* Update for DiscreteIntegrator: '<S92>/Integrator' */
    INS_DWork.Integrator_PrevResetState = (int8_T)rtb_Compare_fo;

    /* Update for DiscreteIntegrator: '<S92>/Integrator1' */
    INS_DWork.Integrator1_IC_LOADING = 0U;

    /* Update for DiscreteIntegrator: '<S92>/Integrator' incorporates:
     *  Gain: '<S92>/gain1'
     */
    INS_DWork.Integrator_DSTATE[0] += INS_P.gain1_Gain * rtb_Multiply_me[0] *
      INS_P.Integrator_gainval;

    /* Update for DiscreteIntegrator: '<S92>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S92>/Integrator'
     *  Gain: '<S92>/gain'
     *  Gain: '<S92>/gain1'
     *  Sum: '<S92>/Sum'
     */
    INS_DWork.Integrator1_DSTATE[0] += (INS_P.gain_Gain * rtb_Multiply_me[0] +
      INS_B.Integrator[0]) * INS_P.Integrator1_gainval;

    /* Update for DiscreteIntegrator: '<S92>/Integrator' incorporates:
     *  Gain: '<S92>/gain1'
     */
    INS_DWork.Integrator_DSTATE[1] += INS_P.gain1_Gain * rtb_Multiply_me[1] *
      INS_P.Integrator_gainval;

    /* Update for DiscreteIntegrator: '<S92>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S92>/Integrator'
     *  Gain: '<S92>/gain'
     *  Gain: '<S92>/gain1'
     *  Sum: '<S92>/Sum'
     */
    INS_DWork.Integrator1_DSTATE[1] += (INS_P.gain_Gain * rtb_Multiply_me[1] +
      INS_B.Integrator[1]) * INS_P.Integrator1_gainval;

    /* Update for DiscreteIntegrator: '<S92>/Integrator' incorporates:
     *  Gain: '<S92>/gain1'
     */
    INS_DWork.Integrator_DSTATE[2] += INS_P.gain1_Gain * rtb_Multiply_me[2] *
      INS_P.Integrator_gainval;

    /* Update for DiscreteIntegrator: '<S92>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S92>/Integrator'
     *  Gain: '<S92>/gain'
     *  Gain: '<S92>/gain1'
     *  Sum: '<S92>/Sum'
     */
    INS_DWork.Integrator1_DSTATE[2] += (INS_P.gain_Gain * rtb_Multiply_me[2] +
      INS_B.Integrator[2]) * INS_P.Integrator1_gainval;
    INS_DWork.Integrator1_PrevResetState = (int8_T)rtb_Compare_fo;
  } else {
    INS_DWork.GPS_Meas_Acc_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S88>/GPS_Meas_Acc' */

  /* Sum: '<S74>/Sum2' incorporates:
   *  Constant: '<S74>/gravity'
   *  Product: '<S74>/Multiply'
   */
  rtb_Multiply_me[0] = INS_P.gravity_Value[0] + (rtb_Compare_o ?
    INS_B.Integrator[0] : 0.0F);
  rtb_Multiply_me[1] = INS_P.gravity_Value[1] + (rtb_Compare_o ?
    INS_B.Integrator[1] : 0.0F);
  rtb_Multiply_me[2] = INS_P.gravity_Value[2] + (rtb_Compare_o ?
    INS_B.Integrator[2] : 0.0F);

  /* Gain: '<S75>/Gain1' */
  rtb_DiscreteTimeIntegrator_nt = INS_P.Gain1_Gain_l * rtb_Multiply_me[2];

  /* Gain: '<S75>/Gain2' */
  rtb_DiscreteTimeIntegrator_bq = INS_P.Gain2_Gain_i * rtb_Reshape_k[2];

  /* Sum: '<S77>/Sum' incorporates:
   *  Product: '<S78>/Multiply'
   *  Product: '<S79>/Multiply3'
   */
  rtb_Gain1_n_idx_0 = rtb_Reshape_k[1] * rtb_DiscreteTimeIntegrator_nt -
    rtb_DiscreteTimeIntegrator_bq * rtb_Multiply_me[1];

  /* DeadZone: '<S75>/Dead Zone2' */
  if (rtb_Gain1_n_idx_0 > INS_P.DeadZone2_End) {
    rtb_Gain1_n_idx_0 -= INS_P.DeadZone2_End;
  } else if (rtb_Gain1_n_idx_0 >= INS_P.DeadZone2_Start) {
    rtb_Gain1_n_idx_0 = 0.0F;
  } else {
    rtb_Gain1_n_idx_0 -= INS_P.DeadZone2_Start;
  }

  /* Gain: '<S75>/Gain' incorporates:
   *  DeadZone: '<S75>/Dead Zone2'
   */
  rtb_DiscreteTimeIntegrator_g = INS_PARAM.HEADING_GAIN * rtb_Gain1_n_idx_0;

  /* Sum: '<S77>/Sum' incorporates:
   *  Product: '<S78>/Multiply1'
   *  Product: '<S79>/Multiply4'
   */
  rtb_Gain1_n_idx_0 = rtb_DiscreteTimeIntegrator_bq * rtb_Multiply_me[0] -
    rtb_Reshape_k[0] * rtb_DiscreteTimeIntegrator_nt;

  /* DeadZone: '<S75>/Dead Zone2' */
  if (rtb_Gain1_n_idx_0 > INS_P.DeadZone2_End) {
    rtb_Gain1_n_idx_0 -= INS_P.DeadZone2_End;
  } else if (rtb_Gain1_n_idx_0 >= INS_P.DeadZone2_Start) {
    rtb_Gain1_n_idx_0 = 0.0F;
  } else {
    rtb_Gain1_n_idx_0 -= INS_P.DeadZone2_Start;
  }

  /* Gain: '<S75>/Gain' incorporates:
   *  DeadZone: '<S75>/Dead Zone2'
   */
  u0 = INS_PARAM.HEADING_GAIN * rtb_Gain1_n_idx_0;

  /* Sum: '<S77>/Sum' incorporates:
   *  Product: '<S78>/Multiply2'
   *  Product: '<S79>/Multiply5'
   */
  rtb_Gain1_n_idx_0 = rtb_Reshape_k[0] * rtb_Multiply_me[1] - rtb_Multiply_me[0]
    * rtb_Reshape_k[1];

  /* DeadZone: '<S75>/Dead Zone2' */
  if (rtb_Gain1_n_idx_0 > INS_P.DeadZone2_End) {
    rtb_Gain1_n_idx_0 -= INS_P.DeadZone2_End;
  } else if (rtb_Gain1_n_idx_0 >= INS_P.DeadZone2_Start) {
    rtb_Gain1_n_idx_0 = 0.0F;
  } else {
    rtb_Gain1_n_idx_0 -= INS_P.DeadZone2_Start;
  }

  /* Gain: '<S75>/Gain' incorporates:
   *  DeadZone: '<S75>/Dead Zone2'
   */
  u0_0 = INS_PARAM.HEADING_GAIN * rtb_Gain1_n_idx_0;

  /* Sum: '<S82>/Sum of Elements' incorporates:
   *  Delay: '<S87>/Delay'
   *  Math: '<S82>/Math Function'
   */
  rtb_DiscreteTimeIntegrator_nt = (rtb_Reshape_k[0] * rtb_Reshape_k[0] +
    rtb_Reshape_k[1] * rtb_Reshape_k[1]) + rtb_Reshape_k[2] * rtb_Reshape_k[2];

  /* Math: '<S82>/Math Function1'
   *
   * About '<S82>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_DiscreteTimeIntegrator_nt < 0.0F) {
    rtb_DiscreteTimeIntegrator_nt = -sqrtf(fabsf(rtb_DiscreteTimeIntegrator_nt));
  } else {
    rtb_DiscreteTimeIntegrator_nt = sqrtf(rtb_DiscreteTimeIntegrator_nt);
  }

  /* End of Math: '<S82>/Math Function1' */

  /* Switch: '<S82>/Switch' incorporates:
   *  Constant: '<S82>/Constant'
   *  Product: '<S82>/Product'
   *  Switch: '<S83>/Switch'
   */
  if (rtb_DiscreteTimeIntegrator_nt > INS_P.Switch_Threshold) {
    rtb_DiscreteTimeIntegrator_bq = rtb_Reshape_k[0];
    rtb_Switch_dy_idx_1 = rtb_Reshape_k[1];
    rtb_Switch_dy_idx_2 = rtb_Reshape_k[2];
  } else {
    rtb_DiscreteTimeIntegrator_bq = 0.0F;
    rtb_Switch_dy_idx_1 = 0.0F;
    rtb_Switch_dy_idx_2 = 0.0F;
    rtb_DiscreteTimeIntegrator_nt = INS_P.Constant_Value_a;
  }

  /* End of Switch: '<S82>/Switch' */

  /* Product: '<S82>/Divide' incorporates:
   *  Gain: '<S69>/Gain1'
   */
  rtb_Gain1_n_idx_0 = rtb_DiscreteTimeIntegrator_bq /
    rtb_DiscreteTimeIntegrator_nt;
  rtb_Gain1_n_idx_1 = rtb_Switch_dy_idx_1 / rtb_DiscreteTimeIntegrator_nt;
  rtb_Gain1_n_idx_2 = rtb_Switch_dy_idx_2 / rtb_DiscreteTimeIntegrator_nt;

  /* Sum: '<S83>/Sum of Elements' incorporates:
   *  Math: '<S83>/Math Function'
   *  Sum: '<S74>/Sum2'
   */
  rtb_DiscreteTimeIntegrator_nt = (rtb_Multiply_me[0] * rtb_Multiply_me[0] +
    rtb_Multiply_me[1] * rtb_Multiply_me[1]) + rtb_Multiply_me[2] *
    rtb_Multiply_me[2];

  /* Math: '<S83>/Math Function1'
   *
   * About '<S83>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_DiscreteTimeIntegrator_nt < 0.0F) {
    rtb_DiscreteTimeIntegrator_nt = -sqrtf(fabsf(rtb_DiscreteTimeIntegrator_nt));
  } else {
    rtb_DiscreteTimeIntegrator_nt = sqrtf(rtb_DiscreteTimeIntegrator_nt);
  }

  /* End of Math: '<S83>/Math Function1' */

  /* Switch: '<S83>/Switch' incorporates:
   *  Constant: '<S83>/Constant'
   *  Product: '<S83>/Product'
   */
  if (rtb_DiscreteTimeIntegrator_nt > INS_P.Switch_Threshold_m) {
    rtb_DiscreteTimeIntegrator_bq = rtb_Multiply_me[0];
    rtb_Switch_dy_idx_1 = rtb_Multiply_me[1];
    rtb_Switch_dy_idx_2 = rtb_Multiply_me[2];
  } else {
    rtb_DiscreteTimeIntegrator_bq = 0.0F;
    rtb_Switch_dy_idx_1 = 0.0F;
    rtb_Switch_dy_idx_2 = 0.0F;
    rtb_DiscreteTimeIntegrator_nt = INS_P.Constant_Value_jy;
  }

  /* End of Switch: '<S83>/Switch' */

  /* Product: '<S83>/Divide' incorporates:
   *  Reshape: '<S291>/Reshape'
   */
  rtb_Reshape_k[0] = rtb_DiscreteTimeIntegrator_bq /
    rtb_DiscreteTimeIntegrator_nt;
  rtb_Reshape_k[1] = rtb_Switch_dy_idx_1 / rtb_DiscreteTimeIntegrator_nt;
  rtb_Reshape_k[2] = rtb_Switch_dy_idx_2 / rtb_DiscreteTimeIntegrator_nt;

  /* Product: '<S84>/Multiply2' */
  rtb_Multiply_me[2] = rtb_Gain1_n_idx_0 * rtb_Reshape_k[1];

  /* Product: '<S85>/Multiply4' */
  rtb_ba_mPs2[1] = rtb_Gain1_n_idx_0 * rtb_Reshape_k[2];

  /* Product: '<S85>/Multiply5' */
  rtb_ba_mPs2[2] = rtb_Reshape_k[0] * rtb_Gain1_n_idx_1;

  /* Sum: '<S80>/Sum' incorporates:
   *  Product: '<S84>/Multiply'
   *  Product: '<S85>/Multiply3'
   */
  rtb_Switch_dy_idx_1 = rtb_Gain1_n_idx_1 * rtb_Reshape_k[2] - rtb_Reshape_k[1] *
    rtb_Gain1_n_idx_2;
  rtb_Multiply_me[0] = rtb_Switch_dy_idx_1;

  /* Math: '<S86>/Square' */
  rtb_Gain1_n_idx_0 = rtb_Switch_dy_idx_1 * rtb_Switch_dy_idx_1;

  /* Sum: '<S80>/Sum' incorporates:
   *  Product: '<S84>/Multiply1'
   */
  rtb_Switch_dy_idx_1 = rtb_Reshape_k[0] * rtb_Gain1_n_idx_2 - rtb_ba_mPs2[1];
  rtb_Multiply_me[1] = rtb_Switch_dy_idx_1;

  /* Math: '<S86>/Square' */
  rtb_Gain1_n_idx_1 = rtb_Switch_dy_idx_1 * rtb_Switch_dy_idx_1;

  /* Sum: '<S80>/Sum' */
  rtb_Switch_dy_idx_1 = rtb_Multiply_me[2] - rtb_ba_mPs2[2];

  /* Sqrt: '<S86>/Sqrt' incorporates:
   *  Math: '<S86>/Square'
   *  Sum: '<S86>/Sum of Elements'
   */
  rtb_DiscreteTimeIntegrator_nt = sqrtf((rtb_Gain1_n_idx_0 + rtb_Gain1_n_idx_1)
    + rtb_Switch_dy_idx_1 * rtb_Switch_dy_idx_1);

  /* Product: '<S81>/Divide1' incorporates:
   *  Constant: '<S81>/max'
   */
  rtb_DiscreteTimeIntegrator_bq = rtb_DiscreteTimeIntegrator_nt /
    INS_P.max_Value;

  /* Saturate: '<S81>/Saturation' */
  if (rtb_DiscreteTimeIntegrator_bq > INS_P.Saturation_UpperSat_e) {
    rtb_DiscreteTimeIntegrator_bq = INS_P.Saturation_UpperSat_e;
  } else if (rtb_DiscreteTimeIntegrator_bq < INS_P.Saturation_LowerSat_fo) {
    rtb_DiscreteTimeIntegrator_bq = INS_P.Saturation_LowerSat_fo;
  }

  /* Product: '<S81>/Divide2' incorporates:
   *  Constant: '<S81>/max'
   *  Saturate: '<S81>/Saturation'
   *  Trigonometry: '<S81>/Trigonometric Function'
   */
  rtb_DiscreteTimeIntegrator_bq = csi_sin_f32(rtb_DiscreteTimeIntegrator_bq) *
    INS_P.max_Value;

  /* MinMax: '<S81>/MinMax' incorporates:
   *  Constant: '<S81>/Constant1'
   */
  rtb_DiscreteTimeIntegrator_nt = fmaxf(rtb_DiscreteTimeIntegrator_nt,
    INS_P.Constant1_Value_n);

  /* Product: '<S81>/Divide' */
  rtb_Multiply_me[0] = rtb_Multiply_me[0] * rtb_DiscreteTimeIntegrator_bq /
    rtb_DiscreteTimeIntegrator_nt;
  rtb_Multiply_me[1] = rtb_Multiply_me[1] * rtb_DiscreteTimeIntegrator_bq /
    rtb_DiscreteTimeIntegrator_nt;

  /* Saturate: '<S75>/Saturation' */
  if (rtb_DiscreteTimeIntegrator_g > INS_P.Saturation_UpperSat_k) {
    rtb_DiscreteTimeIntegrator_g = INS_P.Saturation_UpperSat_k;
  } else if (rtb_DiscreteTimeIntegrator_g < INS_P.Saturation_LowerSat_k) {
    rtb_DiscreteTimeIntegrator_g = INS_P.Saturation_LowerSat_k;
  }

  /* Sum: '<S73>/Sum' incorporates:
   *  Gain: '<S76>/Gain'
   *  Product: '<S75>/Multiply'
   *  Saturate: '<S75>/Saturation'
   */
  rtb_MathFunction[0] = INS_PARAM.ATT_GAIN * rtb_Multiply_me[0] + (rtb_Compare_o
    ? rtb_DiscreteTimeIntegrator_g : 0.0F);

  /* Saturate: '<S75>/Saturation' */
  if (u0 > INS_P.Saturation_UpperSat_k) {
    u0 = INS_P.Saturation_UpperSat_k;
  } else if (u0 < INS_P.Saturation_LowerSat_k) {
    u0 = INS_P.Saturation_LowerSat_k;
  }

  /* Sum: '<S73>/Sum' incorporates:
   *  Gain: '<S76>/Gain1'
   *  Product: '<S75>/Multiply'
   *  Saturate: '<S75>/Saturation'
   */
  rtb_MathFunction[1] = INS_PARAM.ATT_GAIN * rtb_Multiply_me[1] + (rtb_Compare_o
    ? u0 : 0.0F);

  /* Saturate: '<S75>/Saturation' */
  if (u0_0 > INS_P.Saturation_UpperSat_k) {
    u0_0 = INS_P.Saturation_UpperSat_k;
  } else if (u0_0 < INS_P.Saturation_LowerSat_k) {
    u0_0 = INS_P.Saturation_LowerSat_k;
  }

  /* Sum: '<S73>/Sum' incorporates:
   *  Gain: '<S76>/Gain2'
   *  Product: '<S75>/Multiply'
   *  Product: '<S81>/Divide'
   *  Saturate: '<S75>/Saturation'
   *  Sum: '<S80>/Sum'
   */
  rtb_MathFunction[2] = rtb_Switch_dy_idx_1 * rtb_DiscreteTimeIntegrator_bq /
    rtb_DiscreteTimeIntegrator_nt * INS_P.Gain2_Gain_m + (rtb_Compare_o ? u0_0 :
    0.0F);

  /* DiscreteIntegrator: '<S89>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S89>/Constant'
   */
  if ((INS_P.Constant_Value_g3 != 0.0F) ||
      (INS_DWork.DiscreteTimeIntegrator_PrevRe_f != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_lq[0] =
      INS_P.DiscreteTimeIntegrator_IC_a;
    INS_DWork.DiscreteTimeIntegrator_DSTAT_lq[1] =
      INS_P.DiscreteTimeIntegrator_IC_a;
    INS_DWork.DiscreteTimeIntegrator_DSTAT_lq[2] =
      INS_P.DiscreteTimeIntegrator_IC_a;
  }

  /* Gain: '<S89>/Gain' incorporates:
   *  DiscreteIntegrator: '<S89>/Discrete-Time Integrator1'
   *  Product: '<S87>/Multiply'
   *  Sum: '<S89>/Sum'
   */
  rtb_MathFunction_j[0] = (rtb_MathFunction_j[0] -
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_o[0]) * INS_P.Gain_Gain_p;
  rtb_MathFunction_j[1] = (rtb_MathFunction_j[1] -
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_o[1]) * INS_P.Gain_Gain_p;
  rtb_MathFunction_j[2] = (rtb_MathFunction_j[2] -
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_o[2]) * INS_P.Gain_Gain_p;

  /* Switch: '<S94>/Switch' incorporates:
   *  Delay: '<S94>/Delay'
   *  Inport: '<Root>/External_Pos'
   *  RelationalOperator: '<S97>/FixPt Relational Operator'
   *  SignalConversion generated from: '<S390>/ExternalPos_Data'
   *  Sum: '<S96>/Sum'
   *  UnitDelay: '<S97>/Delay Input1'
   */
  if ((int32_T)rtb_LogicalOperator5 > (int32_T)INS_DWork.DelayInput1_DSTATE_ii)
  {
    /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
    /* Outputs for Atomic SubSystem: '<S3>/ExternalPos_Process' */
    rtb_DiscreteTimeIntegrator_bq = rtb_Gain_ca_idx_2 - INS_U.External_Pos.psi;

    /* End of Outputs for SubSystem: '<S3>/ExternalPos_Process' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */
  } else {
    rtb_DiscreteTimeIntegrator_bq = INS_DWork.Delay_DSTATE_b3;
  }

  /* End of Switch: '<S94>/Switch' */

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
  /* Outputs for Atomic SubSystem: '<S3>/ExternalPos_Process' */
  /* Sum: '<S71>/Sum' incorporates:
   *  Inport: '<Root>/External_Pos'
   *  SignalConversion generated from: '<S390>/ExternalPos_Data'
   */
  rtb_DiscreteTimeIntegrator_nt = (rtb_DiscreteTimeIntegrator_bq +
    INS_U.External_Pos.psi) - rtb_Gain_ca_idx_2;

  /* End of Outputs for SubSystem: '<S3>/ExternalPos_Process' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */

  /* Abs: '<S95>/Abs' */
  rtb_DiscreteTimeIntegrator_g = fabsf(rtb_DiscreteTimeIntegrator_nt);

  /* Switch: '<S95>/Switch' incorporates:
   *  Constant: '<S95>/Constant'
   *  Constant: '<S98>/Constant'
   *  Product: '<S95>/Multiply'
   *  RelationalOperator: '<S98>/Compare'
   *  Signum: '<S95>/Sign'
   *  Sum: '<S95>/Subtract'
   */
  if (rtb_DiscreteTimeIntegrator_g > INS_P.CompareToConstant_const) {
    /* Signum: '<S95>/Sign' */
    if (rtb_DiscreteTimeIntegrator_nt < 0.0F) {
      rtb_MathFunction1_tmp = -1;
    } else {
      rtb_MathFunction1_tmp = (rtb_DiscreteTimeIntegrator_nt > 0.0F);
    }

    rtb_DiscreteTimeIntegrator_nt = (rtb_DiscreteTimeIntegrator_g -
      INS_P.Constant_Value_g) * (real32_T)rtb_MathFunction1_tmp;
  }

  /* End of Switch: '<S95>/Switch' */

  /* Product: '<S107>/MX Product1' */
  rtb_DiscreteTimeIntegrator_g = rtb_Product8[1];
  rtb_Gain1_n_idx_0 = rtb_Product8[0];
  rtb_Gain1_n_idx_1 = rtb_Product8[2];
  for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 3;
       rtb_Saturation1_j_idx_1++) {
    /* Product: '<S71>/Multiply' incorporates:
     *  Gain: '<S71>/Gain'
     */
    rtb_Multiply_me[rtb_Saturation1_j_idx_1] = rtb_LogicalOperator5 ?
      INS_P.Gain_Gain_m[rtb_Saturation1_j_idx_1] * rtb_DiscreteTimeIntegrator_nt
      : 0.0F;

    /* Outputs for Atomic SubSystem: '<S57>/Bus_Constructor' */
    /* Product: '<S107>/MX Product1' incorporates:
     *  Math: '<S114>/Transpose'
     *  SignalConversion generated from: '<S59>/Rotation_Data'
     */
    rtb_ba_mPs2[rtb_Saturation1_j_idx_1] =
      (rtb_VectorConcatenate_g[rtb_Saturation1_j_idx_1 + 3] *
       rtb_DiscreteTimeIntegrator_g +
       rtb_VectorConcatenate_g[rtb_Saturation1_j_idx_1] * rtb_Gain1_n_idx_0) +
      rtb_VectorConcatenate_g[rtb_Saturation1_j_idx_1 + 6] * rtb_Gain1_n_idx_1;

    /* End of Outputs for SubSystem: '<S57>/Bus_Constructor' */
  }

  /* Sum: '<S107>/Add' incorporates:
   *  Gain: '<S107>/Gain'
   *  Trigonometry: '<S107>/Atan2'
   */
  rtb_DiscreteTimeIntegrator_nt = atan2f(INS_P.Gain_Gain_pq * rtb_ba_mPs2[1],
    rtb_ba_mPs2[0]) + rtb_Gain_ca_idx_2;

  /* DiscreteIntegrator: '<S105>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S105>/Constant'
   *  Sum: '<S59>/Sum'
   */
  if (INS_DWork.DiscreteTimeIntegrator1_IC_LO_m != 0) {
    /* Outputs for Atomic SubSystem: '<S57>/Bus_Constructor' */
    INS_DWork.DiscreteTimeIntegrator1_DSTA_m3[0] = rtb_VectorConcatenate_idx_0;
    INS_DWork.DiscreteTimeIntegrator1_DSTA_m3[1] = rtb_VectorConcatenate_idx_1;
    INS_DWork.DiscreteTimeIntegrator1_DSTA_m3[2] = Constant_Value_b;

    /* End of Outputs for SubSystem: '<S57>/Bus_Constructor' */
  }

  if ((INS_P.Constant_Value_f != 0.0F) ||
      (INS_DWork.DiscreteTimeIntegrator1_PrevR_m != 0)) {
    /* Outputs for Atomic SubSystem: '<S57>/Bus_Constructor' */
    INS_DWork.DiscreteTimeIntegrator1_DSTA_m3[0] = rtb_VectorConcatenate_idx_0;
    INS_DWork.DiscreteTimeIntegrator1_DSTA_m3[1] = rtb_VectorConcatenate_idx_1;
    INS_DWork.DiscreteTimeIntegrator1_DSTA_m3[2] = Constant_Value_b;

    /* End of Outputs for SubSystem: '<S57>/Bus_Constructor' */
  }

  /* Logic: '<S99>/Logical Operator3' incorporates:
   *  Abs: '<S99>/Abs'
   *  Abs: '<S99>/Abs1'
   *  Constant: '<S102>/Constant'
   *  Constant: '<S104>/Constant'
   *  DiscreteIntegrator: '<S105>/Discrete-Time Integrator1'
   *  Logic: '<S99>/Logical Operator'
   *  Logic: '<S99>/Logical Operator1'
   *  RelationalOperator: '<S102>/Compare'
   *  RelationalOperator: '<S104>/Compare'
   */
  rtb_Compare_fo = ((fabsf(rtb_MathFunction[2]) > INS_P.Constant_Value_d) ||
                    rtb_WGS84_pos_valid || ((fabsf
    (INS_DWork.DiscreteTimeIntegrator1_DSTA_m3[0]) >
    INS_P.CompareToConstant_const_g) || (fabsf
    (INS_DWork.DiscreteTimeIntegrator1_DSTA_m3[1]) >
    INS_P.CompareToConstant_const_g) || (fabsf
    (INS_DWork.DiscreteTimeIntegrator1_DSTA_m3[2]) >
    INS_P.CompareToConstant_const_g)) || (rtb_mag_valid == 0.0F) ||
                    rtb_LogicalOperator5);

  /* DiscreteIntegrator: '<S99>/Discrete-Time Integrator' */
  if (rtb_Compare_fo || (INS_DWork.DiscreteTimeIntegrator_PrevRe_n != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_d =
      INS_P.DiscreteTimeIntegrator_IC_io;
  }

  /* Logic: '<S72>/Logical Operator' incorporates:
   *  Constant: '<S103>/Constant'
   *  DiscreteIntegrator: '<S99>/Discrete-Time Integrator'
   *  RelationalOperator: '<S103>/Compare'
   */
  rtb_Compare_ir = ((INS_DWork.DiscreteTimeIntegrator_DSTATE_d >=
                     INS_P.CompareToConstant4_const) || rtb_WGS84_pos_valid);

  /* Switch: '<S106>/Switch' incorporates:
   *  Delay: '<S106>/Delay'
   *  Logic: '<S106>/Logical Operator'
   *  RelationalOperator: '<S109>/FixPt Relational Operator'
   *  Sum: '<S108>/Sum'
   *  UnitDelay: '<S109>/Delay Input1'
   */
  if (((int32_T)rtb_Compare_ir > (int32_T)INS_DWork.DelayInput1_DSTATE_d2) ||
      rtb_LogicalOperator5_i) {
    rtb_mag_valid = rtb_Gain_ca_idx_2 - rtb_DiscreteTimeIntegrator_nt;
  } else {
    rtb_mag_valid = INS_DWork.Delay_DSTATE_lt;
  }

  /* End of Switch: '<S106>/Switch' */

  /* Sum: '<S72>/Sum' incorporates:
   *  Sum: '<S100>/Sum'
   */
  rtb_DiscreteTimeIntegrator_nt = (rtb_DiscreteTimeIntegrator_nt + rtb_mag_valid)
    - rtb_Gain_ca_idx_2;

  /* Abs: '<S101>/Abs' */
  rtb_DiscreteTimeIntegrator_g = fabsf(rtb_DiscreteTimeIntegrator_nt);

  /* Switch: '<S101>/Switch' incorporates:
   *  Constant: '<S101>/Constant'
   *  Constant: '<S110>/Constant'
   *  Product: '<S101>/Multiply'
   *  RelationalOperator: '<S110>/Compare'
   *  Signum: '<S101>/Sign'
   *  Sum: '<S101>/Subtract'
   */
  if (rtb_DiscreteTimeIntegrator_g > INS_P.CompareToConstant_const_h) {
    /* Signum: '<S101>/Sign' */
    if (rtb_DiscreteTimeIntegrator_nt < 0.0F) {
      rtb_MathFunction1_tmp = -1;
    } else {
      rtb_MathFunction1_tmp = (rtb_DiscreteTimeIntegrator_nt > 0.0F);
    }

    rtb_DiscreteTimeIntegrator_nt = (rtb_DiscreteTimeIntegrator_g -
      INS_P.Constant_Value_ny) * (real32_T)rtb_MathFunction1_tmp;
  }

  /* End of Switch: '<S101>/Switch' */

  /* Gain: '<S72>/Gain3' */
  rtb_DiscreteTimeIntegrator_nt *= INS_PARAM.MAG_GAIN;

  /* DiscreteIntegrator: '<S105>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S105>/Constant'
   */
  if ((INS_P.Constant_Value_f != 0.0F) ||
      (INS_DWork.DiscreteTimeIntegrator_PrevRe_e != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_hs[0] =
      INS_P.DiscreteTimeIntegrator_IC_el;
    INS_DWork.DiscreteTimeIntegrator_DSTAT_hs[1] =
      INS_P.DiscreteTimeIntegrator_IC_el;
    INS_DWork.DiscreteTimeIntegrator_DSTAT_hs[2] =
      INS_P.DiscreteTimeIntegrator_IC_el;
  }

  /* Outputs for Atomic SubSystem: '<S57>/Bus_Constructor' */
  /* Gain: '<S105>/Gain' incorporates:
   *  DiscreteIntegrator: '<S105>/Discrete-Time Integrator1'
   *  Sum: '<S105>/Sum'
   *  Sum: '<S59>/Sum'
   */
  rtb_Product8[0] = (rtb_VectorConcatenate_idx_0 -
                     INS_DWork.DiscreteTimeIntegrator1_DSTA_m3[0]) *
    INS_P.Gain_Gain_pl;
  rtb_Product8[1] = (rtb_VectorConcatenate_idx_1 -
                     INS_DWork.DiscreteTimeIntegrator1_DSTA_m3[1]) *
    INS_P.Gain_Gain_pl;
  rtb_Product8[2] = (Constant_Value_b -
                     INS_DWork.DiscreteTimeIntegrator1_DSTA_m3[2]) *
    INS_P.Gain_Gain_pl;

  /* End of Outputs for SubSystem: '<S57>/Bus_Constructor' */

  /* Product: '<S72>/Multiply' incorporates:
   *  Constant: '<S72>/Constant'
   *  Sum: '<S68>/Sum'
   *  Sum: '<S68>/Sum1'
   */
  rtb_DiscreteTimeIntegrator_g = ((rtb_Compare_ir ? INS_P.Constant_Value_as[0] :
    0.0F) + rtb_Multiply_me[0]) + rtb_MathFunction[0];
  rtb_Gain1_n_idx_0 = ((rtb_Compare_ir ? INS_P.Constant_Value_as[1] : 0.0F) +
                       rtb_Multiply_me[1]) + rtb_MathFunction[1];
  rtb_Gain1_n_idx_1 = ((rtb_Compare_ir ? rtb_DiscreteTimeIntegrator_nt : 0.0F) +
                       rtb_Multiply_me[2]) + rtb_MathFunction[2];

  /* Sum: '<S113>/Sum of Elements' */
  rtb_DiscreteTimeIntegrator_nt = -0.0F;
  for (rtb_MathFunction1_tmp = 0; rtb_MathFunction1_tmp < 3;
       rtb_MathFunction1_tmp++) {
    /* Product: '<S68>/Multiply' incorporates:
     *  Math: '<S59>/Math Function'
     */
    rtb_Reshape_k[rtb_MathFunction1_tmp] = (rtb_M_BO_c[rtb_MathFunction1_tmp + 3]
      * rtb_Gain1_n_idx_0 + rtb_M_BO_c[rtb_MathFunction1_tmp] *
      rtb_DiscreteTimeIntegrator_g) + rtb_M_BO_c[rtb_MathFunction1_tmp + 6] *
      rtb_Gain1_n_idx_1;

    /* Sum: '<S113>/Sum of Elements' incorporates:
     *  Math: '<S113>/Square'
     */
    rtb_DiscreteTimeIntegrator_nt += rtb_Gauss_to_uT[rtb_MathFunction1_tmp];
  }

  /* RelationalOperator: '<S111>/Compare' incorporates:
   *  Abs: '<S69>/Abs'
   *  Constant: '<S111>/Constant'
   *  Constant: '<S69>/Constant'
   *  Sqrt: '<S113>/Sqrt'
   *  Sum: '<S69>/Subtract'
   */
  rtb_WGS84_pos_valid = (fabsf(sqrtf(rtb_DiscreteTimeIntegrator_nt) -
    INS_P.INS_CONST.g) <= INS_P.CompareToConstant_const_n);

  /* Product: '<S69>/MX Product1' incorporates:
   *  DataTypeConversion: '<S69>/Data Type Conversion'
   */
  rtb_MathFunction[0] = rtb_Reshape_k[0] * (real32_T)rtb_WGS84_pos_valid;
  rtb_MathFunction[1] = rtb_Reshape_k[1] * (real32_T)rtb_WGS84_pos_valid;
  rtb_MathFunction[2] = rtb_Reshape_k[2] * (real32_T)rtb_WGS84_pos_valid;

  /* DiscreteIntegrator: '<S112>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S112>/Constant'
   */
  if (INS_DWork.DiscreteTimeIntegrator1_IC_LO_l != 0) {
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_b[0] = rtb_MathFunction[0];
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_b[1] = rtb_MathFunction[1];
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_b[2] = rtb_MathFunction[2];
  }

  if ((INS_P.Constant_Value_no != 0.0F) ||
      (INS_DWork.DiscreteTimeIntegrator1_PrevR_o != 0)) {
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_b[0] = rtb_MathFunction[0];
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_b[1] = rtb_MathFunction[1];
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_b[2] = rtb_MathFunction[2];
  }

  /* Gain: '<S69>/Gain1' incorporates:
   *  DiscreteIntegrator: '<S112>/Discrete-Time Integrator1'
   */
  rtb_Gain1_n_idx_0 = INS_PARAM.BIAS_G_GAIN *
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_b[0];
  rtb_Gain1_n_idx_1 = INS_PARAM.BIAS_G_GAIN *
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_b[1];
  rtb_Gain1_n_idx_2 = INS_PARAM.BIAS_G_GAIN *
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_b[2];

  /* DiscreteIntegrator: '<S112>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S112>/Constant'
   */
  if ((INS_P.Constant_Value_no != 0.0F) ||
      (INS_DWork.DiscreteTimeIntegrator_PrevR_nh != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_ce[0] =
      INS_P.DiscreteTimeIntegrator_IC_m;
    INS_DWork.DiscreteTimeIntegrator_DSTAT_ce[1] =
      INS_P.DiscreteTimeIntegrator_IC_m;
    INS_DWork.DiscreteTimeIntegrator_DSTAT_ce[2] =
      INS_P.DiscreteTimeIntegrator_IC_m;
  }

  /* Update for DiscreteIntegrator: '<S89>/Discrete-Time Integrator1' */
  INS_DWork.DiscreteTimeIntegrator1_IC_LO_i = 0U;

  /* Gain: '<S112>/Gain' incorporates:
   *  DiscreteIntegrator: '<S112>/Discrete-Time Integrator1'
   *  Sum: '<S112>/Sum'
   */
  rtb_MathFunction[0] = (rtb_MathFunction[0] -
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_b[0]) * INS_P.Gain_Gain_i;

  /* Update for DiscreteIntegrator: '<S89>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S89>/Discrete-Time Integrator'
   */
  INS_DWork.DiscreteTimeIntegrator1_DSTAT_o[0] +=
    INS_P.DiscreteTimeIntegrator1_gainval *
    INS_DWork.DiscreteTimeIntegrator_DSTAT_lq[0];

  /* Gain: '<S112>/Gain' incorporates:
   *  DiscreteIntegrator: '<S112>/Discrete-Time Integrator1'
   *  Sum: '<S112>/Sum'
   */
  rtb_MathFunction[1] = (rtb_MathFunction[1] -
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_b[1]) * INS_P.Gain_Gain_i;

  /* Update for DiscreteIntegrator: '<S89>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S89>/Discrete-Time Integrator'
   */
  INS_DWork.DiscreteTimeIntegrator1_DSTAT_o[1] +=
    INS_P.DiscreteTimeIntegrator1_gainval *
    INS_DWork.DiscreteTimeIntegrator_DSTAT_lq[1];

  /* Gain: '<S112>/Gain' incorporates:
   *  DiscreteIntegrator: '<S112>/Discrete-Time Integrator1'
   *  Sum: '<S112>/Sum'
   */
  rtb_MathFunction[2] = (rtb_MathFunction[2] -
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_b[2]) * INS_P.Gain_Gain_i;

  /* Update for DiscreteIntegrator: '<S89>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S89>/Constant'
   *  DiscreteIntegrator: '<S89>/Discrete-Time Integrator'
   */
  INS_DWork.DiscreteTimeIntegrator1_DSTAT_o[2] +=
    INS_P.DiscreteTimeIntegrator1_gainval *
    INS_DWork.DiscreteTimeIntegrator_DSTAT_lq[2];
  if (INS_P.Constant_Value_g3 > 0.0F) {
    INS_DWork.DiscreteTimeIntegrator1_PrevR_p = 1;
  } else if (INS_P.Constant_Value_g3 < 0.0F) {
    INS_DWork.DiscreteTimeIntegrator1_PrevR_p = -1;
  } else if (INS_P.Constant_Value_g3 == 0.0F) {
    INS_DWork.DiscreteTimeIntegrator1_PrevR_p = 0;
  } else {
    INS_DWork.DiscreteTimeIntegrator1_PrevR_p = 2;
  }

  /* Update for Delay: '<S87>/Delay' */
  for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 199;
       rtb_Saturation1_j_idx_1++) {
    rtb_MathFunction1_tmp = (rtb_Saturation1_j_idx_1 + 1) * 3;
    INS_DWork.Delay_DSTATE_lv[rtb_Saturation1_j_idx_1 * 3] =
      INS_DWork.Delay_DSTATE_lv[rtb_MathFunction1_tmp];
    INS_DWork.Delay_DSTATE_lv[rtb_Saturation1_j_idx_1 * 3 + 1] =
      INS_DWork.Delay_DSTATE_lv[rtb_MathFunction1_tmp + 1];
    INS_DWork.Delay_DSTATE_lv[rtb_Saturation1_j_idx_1 * 3 + 2] =
      INS_DWork.Delay_DSTATE_lv[rtb_MathFunction1_tmp + 2];
  }

  /* Update for UnitDelay: '<S91>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_ff = rtb_Compare_o;

  /* Update for DiscreteIntegrator: '<S89>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S89>/Constant'
   */
  if (INS_P.Constant_Value_g3 > 0.0F) {
    INS_DWork.DiscreteTimeIntegrator_PrevRe_f = 1;
  } else if (INS_P.Constant_Value_g3 < 0.0F) {
    INS_DWork.DiscreteTimeIntegrator_PrevRe_f = -1;
  } else if (INS_P.Constant_Value_g3 == 0.0F) {
    INS_DWork.DiscreteTimeIntegrator_PrevRe_f = 0;
  } else {
    INS_DWork.DiscreteTimeIntegrator_PrevRe_f = 2;
  }

  /* Update for Delay: '<S94>/Delay' */
  INS_DWork.Delay_DSTATE_b3 = rtb_DiscreteTimeIntegrator_bq;

  /* Update for UnitDelay: '<S97>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_ii = rtb_LogicalOperator5;

  /* Update for DiscreteIntegrator: '<S105>/Discrete-Time Integrator1' */
  INS_DWork.DiscreteTimeIntegrator1_IC_LO_m = 0U;

  /* Update for Delay: '<S87>/Delay' incorporates:
   *  DiscreteIntegrator: '<S89>/Discrete-Time Integrator1'
   */
  INS_DWork.Delay_DSTATE_lv[597] = rtb_DiscreteTimeIntegrator_eh;

  /* Update for DiscreteIntegrator: '<S89>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S89>/Gain'
   *  Gain: '<S89>/Gain1'
   *  Sum: '<S89>/Sum2'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTAT_lq[0] += (rtb_MathFunction_j[0] -
    INS_P.Gain1_Gain_p * INS_DWork.DiscreteTimeIntegrator_DSTAT_lq[0]) *
    INS_P.DiscreteTimeIntegrator_gainva_n;

  /* Update for DiscreteIntegrator: '<S105>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S105>/Discrete-Time Integrator'
   */
  INS_DWork.DiscreteTimeIntegrator1_DSTA_m3[0] +=
    INS_P.DiscreteTimeIntegrator1_gainv_a *
    INS_DWork.DiscreteTimeIntegrator_DSTAT_hs[0];

  /* Update for Delay: '<S87>/Delay' incorporates:
   *  DiscreteIntegrator: '<S89>/Discrete-Time Integrator1'
   */
  INS_DWork.Delay_DSTATE_lv[598] = rtb_DiscreteTimeIntegrator1_p_i;

  /* Update for DiscreteIntegrator: '<S89>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S89>/Gain'
   *  Gain: '<S89>/Gain1'
   *  Sum: '<S89>/Sum2'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTAT_lq[1] += (rtb_MathFunction_j[1] -
    INS_P.Gain1_Gain_p * INS_DWork.DiscreteTimeIntegrator_DSTAT_lq[1]) *
    INS_P.DiscreteTimeIntegrator_gainva_n;

  /* Update for DiscreteIntegrator: '<S105>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S105>/Discrete-Time Integrator'
   */
  INS_DWork.DiscreteTimeIntegrator1_DSTA_m3[1] +=
    INS_P.DiscreteTimeIntegrator1_gainv_a *
    INS_DWork.DiscreteTimeIntegrator_DSTAT_hs[1];

  /* Update for Delay: '<S87>/Delay' incorporates:
   *  DiscreteIntegrator: '<S89>/Discrete-Time Integrator1'
   */
  INS_DWork.Delay_DSTATE_lv[599] = rtb_DataTypeConversion_l_idx_0;

  /* Update for DiscreteIntegrator: '<S89>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S89>/Gain'
   *  Gain: '<S89>/Gain1'
   *  Sum: '<S89>/Sum2'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTAT_lq[2] += (rtb_MathFunction_j[2] -
    INS_P.Gain1_Gain_p * INS_DWork.DiscreteTimeIntegrator_DSTAT_lq[2]) *
    INS_P.DiscreteTimeIntegrator_gainva_n;

  /* Update for DiscreteIntegrator: '<S105>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S105>/Constant'
   *  DiscreteIntegrator: '<S105>/Discrete-Time Integrator'
   */
  INS_DWork.DiscreteTimeIntegrator1_DSTA_m3[2] +=
    INS_P.DiscreteTimeIntegrator1_gainv_a *
    INS_DWork.DiscreteTimeIntegrator_DSTAT_hs[2];
  if (INS_P.Constant_Value_f > 0.0F) {
    INS_DWork.DiscreteTimeIntegrator1_PrevR_m = 1;
  } else if (INS_P.Constant_Value_f < 0.0F) {
    INS_DWork.DiscreteTimeIntegrator1_PrevR_m = -1;
  } else if (INS_P.Constant_Value_f == 0.0F) {
    INS_DWork.DiscreteTimeIntegrator1_PrevR_m = 0;
  } else {
    INS_DWork.DiscreteTimeIntegrator1_PrevR_m = 2;
  }

  /* Update for DiscreteIntegrator: '<S99>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S99>/Constant1'
   */
  if (INS_EXPORT.period < 4.2949673E+9F) {
    rtb_Sum1_o = (uint32_T)(real32_T)INS_EXPORT.period;
  } else {
    rtb_Sum1_o = MAX_uint32_T;
  }

  rtb_Sum1 = INS_DWork.DiscreteTimeIntegrator_DSTATE_d + rtb_Sum1_o;
  if (rtb_Sum1 < INS_DWork.DiscreteTimeIntegrator_DSTATE_d) {
    rtb_Sum1 = MAX_uint32_T;
  }

  INS_DWork.DiscreteTimeIntegrator_DSTATE_d = rtb_Sum1;
  if (INS_DWork.DiscreteTimeIntegrator_DSTATE_d >
      INS_P.DiscreteTimeIntegrator_UpperS_c) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_d =
      INS_P.DiscreteTimeIntegrator_UpperS_c;
  } else if (INS_DWork.DiscreteTimeIntegrator_DSTATE_d <
             INS_P.DiscreteTimeIntegrator_LowerS_m) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_d =
      INS_P.DiscreteTimeIntegrator_LowerS_m;
  }

  INS_DWork.DiscreteTimeIntegrator_PrevRe_n = (int8_T)rtb_Compare_fo;

  /* End of Update for DiscreteIntegrator: '<S99>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S109>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_d2 = rtb_Compare_ir;

  /* Update for Delay: '<S106>/Delay' */
  INS_DWork.Delay_DSTATE_lt = rtb_mag_valid;

  /* Update for DiscreteIntegrator: '<S105>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S105>/Constant'
   */
  if (INS_P.Constant_Value_f > 0.0F) {
    INS_DWork.DiscreteTimeIntegrator_PrevRe_e = 1;
  } else if (INS_P.Constant_Value_f < 0.0F) {
    INS_DWork.DiscreteTimeIntegrator_PrevRe_e = -1;
  } else if (INS_P.Constant_Value_f == 0.0F) {
    INS_DWork.DiscreteTimeIntegrator_PrevRe_e = 0;
  } else {
    INS_DWork.DiscreteTimeIntegrator_PrevRe_e = 2;
  }

  /* Update for DiscreteIntegrator: '<S112>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S112>/Constant'
   *  DiscreteIntegrator: '<S112>/Discrete-Time Integrator'
   */
  INS_DWork.DiscreteTimeIntegrator1_IC_LO_l = 0U;
  if (INS_P.Constant_Value_no > 0.0F) {
    INS_DWork.DiscreteTimeIntegrator1_PrevR_o = 1;
    INS_DWork.DiscreteTimeIntegrator_PrevR_nh = 1;
  } else if (INS_P.Constant_Value_no < 0.0F) {
    INS_DWork.DiscreteTimeIntegrator1_PrevR_o = -1;
    INS_DWork.DiscreteTimeIntegrator_PrevR_nh = -1;
  } else if (INS_P.Constant_Value_no == 0.0F) {
    INS_DWork.DiscreteTimeIntegrator1_PrevR_o = 0;
    INS_DWork.DiscreteTimeIntegrator_PrevR_nh = 0;
  } else {
    INS_DWork.DiscreteTimeIntegrator1_PrevR_o = 2;
    INS_DWork.DiscreteTimeIntegrator_PrevR_nh = 2;
  }

  /* Update for DiscreteIntegrator: '<S105>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S105>/Gain'
   *  Gain: '<S105>/Gain1'
   *  Sum: '<S105>/Sum2'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTAT_hs[0] += (rtb_Product8[0] -
    INS_P.Gain1_Gain_g * INS_DWork.DiscreteTimeIntegrator_DSTAT_hs[0]) *
    INS_P.DiscreteTimeIntegrator_gainva_h;

  /* Update for DiscreteIntegrator: '<S112>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S112>/Discrete-Time Integrator'
   */
  INS_DWork.DiscreteTimeIntegrator1_DSTAT_b[0] +=
    INS_P.DiscreteTimeIntegrator1_gainv_j *
    INS_DWork.DiscreteTimeIntegrator_DSTAT_ce[0];

  /* Update for DiscreteIntegrator: '<S112>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S112>/Discrete-Time Integrator1'
   *  Gain: '<S112>/Gain1'
   *  Sum: '<S112>/Sum2'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTAT_ce[0] += (rtb_MathFunction[0] -
    INS_P.Gain1_Gain_i * INS_DWork.DiscreteTimeIntegrator_DSTAT_ce[0]) *
    INS_P.DiscreteTimeIntegrator_gainv_kw;

  /* End of Outputs for SubSystem: '<S57>/Correct' */

  /* Update for Delay: '<S57>/Delay1' */
  INS_DWork.Delay1_DSTATE_h[0] = rtb_Reshape_k[0];

  /* Outputs for Atomic SubSystem: '<S57>/Correct' */
  /* Update for DiscreteIntegrator: '<S105>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S105>/Gain'
   *  Gain: '<S105>/Gain1'
   *  Sum: '<S105>/Sum2'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTAT_hs[1] += (rtb_Product8[1] -
    INS_P.Gain1_Gain_g * INS_DWork.DiscreteTimeIntegrator_DSTAT_hs[1]) *
    INS_P.DiscreteTimeIntegrator_gainva_h;

  /* Update for DiscreteIntegrator: '<S112>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S112>/Discrete-Time Integrator'
   */
  INS_DWork.DiscreteTimeIntegrator1_DSTAT_b[1] +=
    INS_P.DiscreteTimeIntegrator1_gainv_j *
    INS_DWork.DiscreteTimeIntegrator_DSTAT_ce[1];

  /* Update for DiscreteIntegrator: '<S112>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S112>/Discrete-Time Integrator1'
   *  Gain: '<S112>/Gain1'
   *  Sum: '<S112>/Sum2'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTAT_ce[1] += (rtb_MathFunction[1] -
    INS_P.Gain1_Gain_i * INS_DWork.DiscreteTimeIntegrator_DSTAT_ce[1]) *
    INS_P.DiscreteTimeIntegrator_gainv_kw;

  /* End of Outputs for SubSystem: '<S57>/Correct' */

  /* Update for Delay: '<S57>/Delay1' */
  INS_DWork.Delay1_DSTATE_h[1] = rtb_Reshape_k[1];

  /* Outputs for Atomic SubSystem: '<S57>/Correct' */
  /* Update for DiscreteIntegrator: '<S105>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S105>/Gain'
   *  Gain: '<S105>/Gain1'
   *  Sum: '<S105>/Sum2'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTAT_hs[2] += (rtb_Product8[2] -
    INS_P.Gain1_Gain_g * INS_DWork.DiscreteTimeIntegrator_DSTAT_hs[2]) *
    INS_P.DiscreteTimeIntegrator_gainva_h;

  /* Update for DiscreteIntegrator: '<S112>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S112>/Discrete-Time Integrator'
   */
  INS_DWork.DiscreteTimeIntegrator1_DSTAT_b[2] +=
    INS_P.DiscreteTimeIntegrator1_gainv_j *
    INS_DWork.DiscreteTimeIntegrator_DSTAT_ce[2];

  /* Update for DiscreteIntegrator: '<S112>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S112>/Discrete-Time Integrator1'
   *  Gain: '<S112>/Gain1'
   *  Sum: '<S112>/Sum2'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTAT_ce[2] += (rtb_MathFunction[2] -
    INS_P.Gain1_Gain_i * INS_DWork.DiscreteTimeIntegrator_DSTAT_ce[2]) *
    INS_P.DiscreteTimeIntegrator_gainv_kw;

  /* End of Outputs for SubSystem: '<S57>/Correct' */

  /* Update for Delay: '<S57>/Delay1' */
  INS_DWork.Delay1_DSTATE_h[2] = rtb_Reshape_k[2];

  /* Update for Atomic SubSystem: '<S57>/Update' */
  /* Update for Delay: '<S114>/Delay1' */
  INS_DWork.icLoad_o2 = false;

  /* End of Update for SubSystem: '<S57>/Update' */

  /* Outputs for Atomic SubSystem: '<S57>/Update' */
  /* Switch: '<S114>/Switch' */
  if (rtb_LogicalOperator5_i) {
    /* Update for Atomic SubSystem: '<S57>/Update' */
    /* Update for Delay: '<S114>/Delay1' */
    INS_DWork.Delay1_DSTATE_e[0] = INS_B.OutportBufferForquat_0[0];
    INS_DWork.Delay1_DSTATE_e[1] = INS_B.OutportBufferForquat_0[1];
    INS_DWork.Delay1_DSTATE_e[2] = INS_B.OutportBufferForquat_0[2];
    INS_DWork.Delay1_DSTATE_e[3] = INS_B.OutportBufferForquat_0[3];

    /* End of Update for SubSystem: '<S57>/Update' */
  } else {
    /* Update for Atomic SubSystem: '<S57>/Update' */
    /* Update for Delay: '<S114>/Delay1' incorporates:
     *  Product: '<S117>/Divide'
     */
    INS_DWork.Delay1_DSTATE_e[0] = rtb_Switch_kj_idx_0;
    INS_DWork.Delay1_DSTATE_e[1] = rtb_Switch_kj_idx_1;
    INS_DWork.Delay1_DSTATE_e[2] = rtb_Switch_kj_idx_2;
    INS_DWork.Delay1_DSTATE_e[3] = rtb_Switch_kj_0;

    /* End of Update for SubSystem: '<S57>/Update' */
  }

  /* End of Switch: '<S114>/Switch' */
  /* End of Outputs for SubSystem: '<S57>/Update' */

  /* Update for Atomic SubSystem: '<S57>/Update' */
  /* Update for DiscreteIntegrator: '<S115>/Discrete-Time Integrator2' incorporates:
   *  Delay: '<S57>/Delay2'
   */
  rtb_mag_valid = INS_P.DiscreteTimeIntegrator2_gainval *
    INS_DWork.Delay2_DSTATE[0] + INS_DWork.DiscreteTimeIntegrator2_DSTATE[0];
  INS_DWork.DiscreteTimeIntegrator2_DSTATE[0] = rtb_mag_valid;
  if (rtb_mag_valid > INS_P.DiscreteTimeIntegrator2_UpperSa) {
    INS_DWork.DiscreteTimeIntegrator2_DSTATE[0] =
      INS_P.DiscreteTimeIntegrator2_UpperSa;
  } else if (rtb_mag_valid < INS_P.DiscreteTimeIntegrator2_LowerSa) {
    INS_DWork.DiscreteTimeIntegrator2_DSTATE[0] =
      INS_P.DiscreteTimeIntegrator2_LowerSa;
  }

  /* End of Update for SubSystem: '<S57>/Update' */

  /* Outputs for Atomic SubSystem: '<S57>/Correct' */
  /* Saturate: '<S69>/Saturation2' */
  if (rtb_Gain1_n_idx_0 > INS_P.Saturation2_UpperSat) {
    /* Update for Delay: '<S57>/Delay2' */
    INS_DWork.Delay2_DSTATE[0] = INS_P.Saturation2_UpperSat;
  } else if (rtb_Gain1_n_idx_0 < INS_P.Saturation2_LowerSat) {
    /* Update for Delay: '<S57>/Delay2' */
    INS_DWork.Delay2_DSTATE[0] = INS_P.Saturation2_LowerSat;
  } else {
    /* Update for Delay: '<S57>/Delay2' */
    INS_DWork.Delay2_DSTATE[0] = rtb_Gain1_n_idx_0;
  }

  /* End of Outputs for SubSystem: '<S57>/Correct' */

  /* Update for Atomic SubSystem: '<S57>/Update' */
  /* Update for DiscreteIntegrator: '<S115>/Discrete-Time Integrator2' incorporates:
   *  Delay: '<S57>/Delay2'
   */
  rtb_mag_valid = INS_P.DiscreteTimeIntegrator2_gainval *
    INS_DWork.Delay2_DSTATE[1] + INS_DWork.DiscreteTimeIntegrator2_DSTATE[1];
  INS_DWork.DiscreteTimeIntegrator2_DSTATE[1] = rtb_mag_valid;
  if (rtb_mag_valid > INS_P.DiscreteTimeIntegrator2_UpperSa) {
    INS_DWork.DiscreteTimeIntegrator2_DSTATE[1] =
      INS_P.DiscreteTimeIntegrator2_UpperSa;
  } else if (rtb_mag_valid < INS_P.DiscreteTimeIntegrator2_LowerSa) {
    INS_DWork.DiscreteTimeIntegrator2_DSTATE[1] =
      INS_P.DiscreteTimeIntegrator2_LowerSa;
  }

  /* End of Update for SubSystem: '<S57>/Update' */

  /* Outputs for Atomic SubSystem: '<S57>/Correct' */
  /* Saturate: '<S69>/Saturation2' */
  if (rtb_Gain1_n_idx_1 > INS_P.Saturation2_UpperSat) {
    /* Update for Delay: '<S57>/Delay2' */
    INS_DWork.Delay2_DSTATE[1] = INS_P.Saturation2_UpperSat;
  } else if (rtb_Gain1_n_idx_1 < INS_P.Saturation2_LowerSat) {
    /* Update for Delay: '<S57>/Delay2' */
    INS_DWork.Delay2_DSTATE[1] = INS_P.Saturation2_LowerSat;
  } else {
    /* Update for Delay: '<S57>/Delay2' */
    INS_DWork.Delay2_DSTATE[1] = rtb_Gain1_n_idx_1;
  }

  /* End of Outputs for SubSystem: '<S57>/Correct' */

  /* Update for Atomic SubSystem: '<S57>/Update' */
  /* Update for DiscreteIntegrator: '<S115>/Discrete-Time Integrator2' incorporates:
   *  Delay: '<S57>/Delay2'
   */
  rtb_mag_valid = INS_P.DiscreteTimeIntegrator2_gainval *
    INS_DWork.Delay2_DSTATE[2] + INS_DWork.DiscreteTimeIntegrator2_DSTATE[2];
  INS_DWork.DiscreteTimeIntegrator2_DSTATE[2] = rtb_mag_valid;
  if (rtb_mag_valid > INS_P.DiscreteTimeIntegrator2_UpperSa) {
    INS_DWork.DiscreteTimeIntegrator2_DSTATE[2] =
      INS_P.DiscreteTimeIntegrator2_UpperSa;
  } else if (rtb_mag_valid < INS_P.DiscreteTimeIntegrator2_LowerSa) {
    INS_DWork.DiscreteTimeIntegrator2_DSTATE[2] =
      INS_P.DiscreteTimeIntegrator2_LowerSa;
  }

  /* End of Update for SubSystem: '<S57>/Update' */

  /* Outputs for Atomic SubSystem: '<S57>/Correct' */
  /* Saturate: '<S69>/Saturation2' */
  if (rtb_Gain1_n_idx_2 > INS_P.Saturation2_UpperSat) {
    /* Update for Delay: '<S57>/Delay2' */
    INS_DWork.Delay2_DSTATE[2] = INS_P.Saturation2_UpperSat;
  } else if (rtb_Gain1_n_idx_2 < INS_P.Saturation2_LowerSat) {
    /* Update for Delay: '<S57>/Delay2' */
    INS_DWork.Delay2_DSTATE[2] = INS_P.Saturation2_LowerSat;
  } else {
    /* Update for Delay: '<S57>/Delay2' */
    INS_DWork.Delay2_DSTATE[2] = rtb_Gain1_n_idx_2;
  }

  /* End of Outputs for SubSystem: '<S57>/Correct' */
  /* End of Outputs for SubSystem: '<S55>/AHRS' */

  /* Outputs for Atomic SubSystem: '<S56>/TF_Data_PreProcess' */
  /* DataTypeConversion: '<S307>/Data Type Conversion4' incorporates:
   *  Constant: '<S312>/Constant'
   *  RelationalOperator: '<S312>/Compare'
   *  SignalConversion generated from: '<S337>/Signal Copy'
   */
  rtb_DataTypeConversion1_m = (int8_T)((int32_T)rtb_LogicalOperator2_g >
    (int32_T)INS_P.Constant_Value_br);

  /* Relay: '<S338>/Relay' */
  INS_DWork.Relay_Mode_n2 = ((rtb_Sum2_by >= INS_P.Relay_OnVal_l) ||
    ((rtb_Sum2_by > INS_P.Relay_OffVal_p) && INS_DWork.Relay_Mode_n2));
  if (INS_DWork.Relay_Mode_n2) {
    rtb_DiscreteTimeIntegrator_g = INS_P.Relay_YOn_b;
  } else {
    rtb_DiscreteTimeIntegrator_g = INS_P.Relay_YOff_d;
  }

  /* End of Relay: '<S338>/Relay' */

  /* Relay: '<S338>/Relay1' */
  INS_DWork.Relay1_Mode_g = ((rtb_Divide1 >= INS_P.Relay1_OnVal_b) ||
    ((rtb_Divide1 > INS_P.Relay1_OffVal_n) && INS_DWork.Relay1_Mode_g));
  if (INS_DWork.Relay1_Mode_g) {
    rtb_DiscreteTimeIntegrator_eh = INS_P.Relay1_YOn;
  } else {
    rtb_DiscreteTimeIntegrator_eh = INS_P.Relay1_YOff;
  }

  /* End of Relay: '<S338>/Relay1' */

  /* DataTypeConversion: '<S307>/Data Type Conversion2' incorporates:
   *  DataTypeConversion: '<S308>/Data Type Conversion'
   *  Logic: '<S307>/Logical Operator'
   *  SignalConversion generated from: '<S338>/Signal Copy'
   */
  rtb_DataTypeConversion_k_tmp = (int8_T)(rtb_Compare_cio &&
    (rtb_DiscreteTimeIntegrator_g != 0.0F) && (rtb_DiscreteTimeIntegrator_eh !=
    0.0F));

  /* Saturate: '<S307>/Saturation1' incorporates:
   *  DataTypeConversion: '<S307>/Data Type Conversion2'
   *  Sum: '<S307>/Subtract2'
   */
  u0_1 = (int8_T)(rtb_DataTypeConversion_k_tmp - rtb_DataTypeConversion1_m);
  if (u0_1 > INS_P.Saturation1_UpperSat_d) {
    u0_1 = INS_P.Saturation1_UpperSat_d;
  } else if (u0_1 < INS_P.Saturation1_LowerSat_p) {
    u0_1 = INS_P.Saturation1_LowerSat_p;
  }

  /* RelationalOperator: '<S310>/Compare' incorporates:
   *  Constant: '<S310>/Constant'
   *  Saturate: '<S307>/Saturation1'
   */
  rtb_LogicalOperator5_i = (u0_1 > INS_P.Constant_Value_ej5);

  /* Saturate: '<S307>/Saturation' incorporates:
   *  Constant: '<S309>/Constant'
   *  DataTypeConversion: '<S307>/Data Type Conversion2'
   *  RelationalOperator: '<S309>/Compare'
   *  SignalConversion generated from: '<S339>/Signal Copy'
   *  Sum: '<S307>/Subtract1'
   */
  u0_1 = (int8_T)((((int32_T)rtb_Compare_ai > (int32_T)INS_P.Constant_Value_jz)
                   - rtb_DataTypeConversion1_m) - rtb_DataTypeConversion_k_tmp);
  if (u0_1 > INS_P.Saturation_UpperSat_m) {
    u0_1 = INS_P.Saturation_UpperSat_m;
  } else if (u0_1 < INS_P.Saturation_LowerSat_h5) {
    u0_1 = INS_P.Saturation_LowerSat_h5;
  }

  /* RelationalOperator: '<S311>/Compare' incorporates:
   *  Constant: '<S311>/Constant'
   *  Saturate: '<S307>/Saturation'
   */
  rtb_Compare_o = (u0_1 > INS_P.Constant_Value_m2k);

  /* RelationalOperator: '<S313>/Compare' incorporates:
   *  Constant: '<S313>/Constant'
   */
  rtb_Compare_fo = (rtb_DataTypeConversion1_m > INS_P.Constant_Value_bze);

  /* DataTypeConversion: '<S308>/Data Type Conversion3' incorporates:
   *  Constant: '<S318>/Constant'
   *  RelationalOperator: '<S318>/Compare'
   *  SignalConversion generated from: '<S337>/Signal Copy1'
   */
  rtb_DataTypeConversion1_m = (int8_T)((int32_T)rtb_LogicalOperator3 > (int32_T)
    INS_P.Constant_Value_bz);

  /* DataTypeConversion: '<S308>/Data Type Conversion2' incorporates:
   *  Constant: '<S315>/Constant'
   *  RelationalOperator: '<S315>/Compare'
   *  SignalConversion generated from: '<S340>/Signal Copy'
   */
  rtb_DataTypeConversion2_h = (int8_T)((int32_T)rtb_Compare_c5 > (int32_T)
    INS_P.Constant_Value_ha);

  /* Saturate: '<S308>/Saturation2' incorporates:
   *  Sum: '<S308>/Subtract2'
   */
  u0_1 = (int8_T)(rtb_DataTypeConversion2_h - rtb_DataTypeConversion1_m);
  if (u0_1 > INS_P.Saturation2_UpperSat_l) {
    u0_1 = INS_P.Saturation2_UpperSat_l;
  } else if (u0_1 < INS_P.Saturation2_LowerSat_i) {
    u0_1 = INS_P.Saturation2_LowerSat_i;
  }

  /* RelationalOperator: '<S316>/Compare' incorporates:
   *  Constant: '<S316>/Constant'
   *  Saturate: '<S308>/Saturation2'
   */
  rtb_Compare_ir = (u0_1 > INS_P.Constant_Value_c1);

  /* Saturate: '<S308>/Saturation' incorporates:
   *  Sum: '<S308>/Subtract1'
   */
  u0_1 = (int8_T)((rtb_DataTypeConversion_k_tmp - rtb_DataTypeConversion1_m) -
                  rtb_DataTypeConversion2_h);
  if (u0_1 > INS_P.Saturation_UpperSat_gx) {
    u0_1 = INS_P.Saturation_UpperSat_gx;
  } else if (u0_1 < INS_P.Saturation_LowerSat_co) {
    u0_1 = INS_P.Saturation_LowerSat_co;
  }

  /* RelationalOperator: '<S317>/Compare' incorporates:
   *  Constant: '<S317>/Constant'
   *  Saturate: '<S308>/Saturation'
   */
  rtb_Compare_ay = (u0_1 > INS_P.Constant_Value_lc);

  /* Saturate: '<S308>/Saturation1' incorporates:
   *  Constant: '<S314>/Constant'
   *  RelationalOperator: '<S314>/Compare'
   *  SignalConversion generated from: '<S336>/Signal Copy'
   *  Sum: '<S308>/Subtract'
   */
  u0_1 = (int8_T)(((((int32_T)rtb_FixPtRelationalOperator_cn > (int32_T)
                     INS_P.Constant_Value_pf) - rtb_DataTypeConversion1_m) -
                   rtb_DataTypeConversion2_h) - rtb_DataTypeConversion_k_tmp);
  if (u0_1 > INS_P.Saturation1_UpperSat_ig) {
    u0_1 = INS_P.Saturation1_UpperSat_ig;
  } else if (u0_1 < INS_P.Saturation1_LowerSat_g) {
    u0_1 = INS_P.Saturation1_LowerSat_g;
  }

  /* RelationalOperator: '<S319>/Compare' incorporates:
   *  Constant: '<S319>/Constant'
   *  Saturate: '<S308>/Saturation1'
   */
  rtb_Compare_fg = (u0_1 > INS_P.Constant_Value_ktj);

  /* RelationalOperator: '<S320>/Compare' incorporates:
   *  Constant: '<S320>/Constant'
   */
  rtb_Compare_n1 = (rtb_DataTypeConversion1_m > INS_P.Constant_Value_ew);

  /* DiscreteIntegrator: '<S326>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S326>/Constant'
   */
  if ((INS_P.Constant_Value_oi != 0.0F) ||
      (INS_DWork.DiscreteTimeIntegrator_PrevRe_h != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_f =
      INS_P.DiscreteTimeIntegrator_IC_c;
  }

  rtb_DiscreteTimeIntegrator_nt = INS_DWork.DiscreteTimeIntegrator_DSTATE_f;

  /* DiscreteIntegrator: '<S326>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S326>/Constant'
   *  SignalConversion generated from: '<S321>/Signal Copy1'
   */
  if (INS_DWork.DiscreteTimeIntegrator1_IC_LO_k != 0) {
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_h = rtb_Sum2_m;
  }

  if ((INS_P.Constant_Value_oi != 0.0F) ||
      (INS_DWork.DiscreteTimeIntegrator1_PrevR_d != 0)) {
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_h = rtb_Sum2_m;
  }

  rtb_mag_valid = INS_DWork.DiscreteTimeIntegrator1_DSTAT_h;

  /* Outputs for Atomic SubSystem: '<S55>/AHRS' */
  /* Outputs for Atomic SubSystem: '<S57>/Bus_Constructor' */
  /* Switch: '<S329>/Switch' incorporates:
   *  Constant: '<S329>/Constant1'
   *  Delay: '<S329>/Delay'
   *  RelationalOperator: '<S332>/FixPt Relational Operator'
   *  SignalConversion generated from: '<S59>/Signal Conversion5'
   *  UnitDelay: '<S332>/Delay Input1'
   */
  if ((int32_T)rtb_Switch_g3 < (int32_T)INS_DWork.DelayInput1_DSTATE_ic) {
    rtb_Switch_pt = INS_P.Constant1_Value_cq;
  } else {
    rtb_Switch_pt = INS_DWork.Delay_DSTATE_n2;
  }

  /* End of Switch: '<S329>/Switch' */
  /* End of Outputs for SubSystem: '<S57>/Bus_Constructor' */
  /* End of Outputs for SubSystem: '<S55>/AHRS' */

  /* Switch: '<S334>/Switch' incorporates:
   *  Constant: '<S334>/Constant1'
   *  Delay: '<S334>/Delay'
   *  Logic: '<S328>/Logical Operator'
   *  Logic: '<S328>/Logical Operator1'
   */
  if ((rtb_LogicalOperator2_g || rtb_LogicalOperator3) && (rtb_Switch_pt != 0))
  {
    rtb_Uk1_m2 = INS_P.Constant1_Value_cj;
  } else {
    rtb_Uk1_m2 = INS_DWork.Delay_DSTATE_e;
  }

  /* End of Switch: '<S334>/Switch' */

  /* Switch: '<S330>/Switch' incorporates:
   *  Delay: '<S330>/Delay'
   *  RelationalOperator: '<S333>/FixPt Relational Operator'
   *  UnitDelay: '<S333>/Delay Input1'
   */
  if (rtb_Uk1_m2 > INS_DWork.DelayInput1_DSTATE_cz) {
    rtb_DiscreteTimeIntegrator_eh = rtb_Gain_ca_idx_2;
  } else {
    rtb_DiscreteTimeIntegrator_eh = INS_DWork.Delay_DSTATE_a;
  }

  /* End of Switch: '<S330>/Switch' */

  /* MultiPortSwitch: '<S328>/Multiport Switch' incorporates:
   *  Constant: '<S328>/Constant'
   *  Constant: '<S328>/Constant1'
   *  Constant: '<S328>/Constant2'
   */
  switch (INS_PARAM.EXTPOS_ORIEN_MODE) {
   case 1:
    rtb_DiscreteTimeIntegrator_g = INS_PARAM.EXTPOS_ORIEN;
    break;

   case 2:
    rtb_DiscreteTimeIntegrator_g = rtb_DiscreteTimeIntegrator_eh;
    break;

   default:
    rtb_DiscreteTimeIntegrator_g = INS_P.Constant1_Value_bw;
    break;
  }

  /* End of MultiPortSwitch: '<S328>/Multiport Switch' */

  /* Gain: '<S331>/Gain' */
  rtb_DiscreteTimeIntegrator_g *= INS_P.Gain_Gain_c;

  /* Constant: '<S335>/Constant' */
  rtb_M_OC[8] = INS_P.Constant_Value_hc;

  /* Constant: '<S335>/Constant1' */
  rtb_M_OC[7] = INS_P.Constant1_Value_p;

  /* Constant: '<S335>/Constant2' */
  rtb_M_OC[6] = INS_P.Constant2_Value_e;

  /* Constant: '<S335>/Constant3' */
  rtb_M_OC[2] = INS_P.Constant3_Value_n;

  /* Constant: '<S335>/Constant4' */
  rtb_M_OC[5] = INS_P.Constant4_Value_m;

  /* Trigonometry: '<S335>/Trigonometric Function2' incorporates:
   *  Trigonometry: '<S335>/Trigonometric Function'
   */
  rtb_DiscreteTimeIntegrator_bq = csi_sin_f32(rtb_DiscreteTimeIntegrator_g);

  /* Gain: '<S335>/Gain' incorporates:
   *  Trigonometry: '<S335>/Trigonometric Function2'
   */
  rtb_M_OC[3] = INS_P.Gain_Gain_b2 * rtb_DiscreteTimeIntegrator_bq;

  /* Trigonometry: '<S335>/Trigonometric Function' */
  rtb_M_OC[1] = rtb_DiscreteTimeIntegrator_bq;

  /* Trigonometry: '<S335>/Trigonometric Function1' incorporates:
   *  Trigonometry: '<S335>/Trigonometric Function3'
   */
  rtb_DiscreteTimeIntegrator_bq = csi_cos_f32(rtb_DiscreteTimeIntegrator_g);
  rtb_M_OC[0] = rtb_DiscreteTimeIntegrator_bq;

  /* Trigonometry: '<S335>/Trigonometric Function3' */
  rtb_M_OC[4] = rtb_DiscreteTimeIntegrator_bq;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
  /* Outputs for Atomic SubSystem: '<S3>/ExternalPos_Process' */
  /* Product: '<S327>/Multiply' incorporates:
   *  Gain: '<S410>/Gain'
   *  Inport: '<Root>/External_Pos'
   */
  rtb_DiscreteTimeIntegrator_bq = INS_P.Gain_Gain_ge * INS_U.External_Pos.z;

  /* End of Outputs for SubSystem: '<S3>/ExternalPos_Process' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */
  for (rtb_MathFunction1_tmp = 0; rtb_MathFunction1_tmp < 3;
       rtb_MathFunction1_tmp++) {
    /* Math: '<S328>/Transpose' incorporates:
     *  Math: '<S324>/Transpose'
     *  Product: '<S324>/Multiply'
     */
    rtb_Saturation1_j_idx_1 = 3 * rtb_MathFunction1_tmp + 1;
    rtb_Saturation1_j_idx_0 = 3 * rtb_MathFunction1_tmp + 2;

    /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
    /* Outputs for Atomic SubSystem: '<S3>/ExternalPos_Process' */
    /* Product: '<S327>/Multiply' incorporates:
     *  Math: '<S324>/Transpose'
     *  Math: '<S328>/Transpose'
     *  SignalConversion generated from: '<S390>/ExternalPos_Data'
     */
    rtb_Gauss_to_uT[rtb_MathFunction1_tmp] = (rtb_M_OC[3 * rtb_MathFunction1_tmp]
      * INS_U.External_Pos.x + rtb_M_OC[rtb_Saturation1_j_idx_1] *
      INS_U.External_Pos.y) + rtb_M_OC[rtb_Saturation1_j_idx_0] *
      rtb_DiscreteTimeIntegrator_bq;

    /* End of Outputs for SubSystem: '<S3>/ExternalPos_Process' */

    /* Outputs for Atomic SubSystem: '<S3>/OpticalFlow_PreProcess' */
    /* Product: '<S324>/Multiply' incorporates:
     *  Concatenate: '<S67>/Vector Concatenate'
     *  Constant: '<S324>/Constant'
     *  Math: '<S324>/Transpose'
     *  Product: '<S462>/Multiply'
     */
    rtb_Product8[rtb_MathFunction1_tmp] = (rtb_VectorConcatenate_c2[3 *
      rtb_MathFunction1_tmp] * rtb_Memory_m_idx_0 +
      rtb_VectorConcatenate_c2[rtb_Saturation1_j_idx_1] * rtb_Memory_m_idx_1) +
      rtb_VectorConcatenate_c2[rtb_Saturation1_j_idx_0] *
      INS_P.Constant_Value_gd;

    /* End of Outputs for SubSystem: '<S3>/OpticalFlow_PreProcess' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */
  }

  /* End of Product: '<S327>/Multiply' */

  /* Logic: '<S348>/Logical Operator' */
  rtb_WGS84_pos_valid = (rtb_LogicalOperator5_i || rtb_Compare_o ||
    rtb_Compare_fo);

  /* RelationalOperator: '<S358>/Compare' incorporates:
   *  Constant: '<S358>/Constant'
   */
  rtb_LogicalOperator2_g = ((int32_T)rtb_WGS84_pos_valid > (int32_T)
    INS_P.CompareToConstant1_const_i);

  /* DiscreteIntegrator: '<S351>/Discrete-Time Integrator' */
  if (rtb_LogicalOperator2_g || (INS_DWork.DiscreteTimeIntegrator_PrevR_ky != 0))
  {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_b =
      INS_P.DiscreteTimeIntegrator_IC_g;
  }

  /* RelationalOperator: '<S361>/Compare' incorporates:
   *  Constant: '<S359>/Constant'
   *  Constant: '<S361>/Constant'
   *  RelationalOperator: '<S359>/Compare'
   */
  rtb_LogicalOperator3 = (((int32_T)rtb_WGS84_pos_valid > (int32_T)
    INS_P.CompareToConstant2_const_j) > (int32_T)INS_P.Constant_Value_dc);

  /* Logic: '<S351>/Logical Operator1' incorporates:
   *  Delay: '<S351>/Delay'
   *  RelationalOperator: '<S360>/FixPt Relational Operator'
   *  UnitDelay: '<S360>/Delay Input1'
   */
  rtb_LogicalOperator1_cc = (((int32_T)rtb_LogicalOperator3 > (int32_T)
    INS_DWork.DelayInput1_DSTATE_hg) || INS_DWork.Delay_DSTATE_kh);

  /* Product: '<S351>/Multiply' incorporates:
   *  Constant: '<S357>/Constant'
   *  DiscreteIntegrator: '<S351>/Discrete-Time Integrator'
   *  Logic: '<S351>/Logical Operator'
   *  RelationalOperator: '<S357>/Compare'
   */
  rtb_Multiply_jy = (uint16_T)(INS_DWork.DiscreteTimeIntegrator_DSTATE_b <
    INS_P.valid_hold1_time_out ? (int32_T)rtb_LogicalOperator1_cc : 0);

  /* RelationalOperator: '<S346>/Compare' incorporates:
   *  Constant: '<S346>/Constant'
   */
  rtb_Compare_ce = (rtb_Multiply_jy > INS_P.Constant_Value_gn);

  /* RelationalOperator: '<S344>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S344>/Delay Input1'
   */
  rtb_FixPtRelationalOperator_p = ((int32_T)rtb_Compare_ce > (int32_T)
    INS_DWork.DelayInput1_DSTATE_o);

  /* Logic: '<S349>/Logical Operator' */
  rtb_WGS84_pos_valid = (rtb_Compare_ay || rtb_Compare_fg || rtb_Compare_n1 ||
    rtb_Compare_ir);

  /* RelationalOperator: '<S371>/Compare' incorporates:
   *  Constant: '<S371>/Constant'
   */
  rtb_Compare_od = ((int32_T)rtb_WGS84_pos_valid > (int32_T)
                    INS_P.CompareToConstant1_const_a);

  /* DiscreteIntegrator: '<S363>/Discrete-Time Integrator' */
  if (rtb_Compare_od || (INS_DWork.DiscreteTimeIntegrator_PrevRe_l != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_c =
      INS_P.DiscreteTimeIntegrator_IC_lb;
  }

  /* RelationalOperator: '<S374>/Compare' incorporates:
   *  Constant: '<S372>/Constant'
   *  Constant: '<S374>/Constant'
   *  RelationalOperator: '<S372>/Compare'
   */
  rtb_WGS84_pos_valid = (((int32_T)rtb_WGS84_pos_valid > (int32_T)
    INS_P.CompareToConstant2_const_d) > (int32_T)INS_P.Constant_Value_jo);

  /* Logic: '<S363>/Logical Operator1' incorporates:
   *  Delay: '<S363>/Delay'
   *  RelationalOperator: '<S373>/FixPt Relational Operator'
   *  UnitDelay: '<S373>/Delay Input1'
   */
  rtb_LogicalOperator1_ao = (((int32_T)rtb_WGS84_pos_valid > (int32_T)
    INS_DWork.DelayInput1_DSTATE_p) || INS_DWork.Delay_DSTATE_k4);

  /* Product: '<S363>/Multiply' incorporates:
   *  Constant: '<S370>/Constant'
   *  DiscreteIntegrator: '<S363>/Discrete-Time Integrator'
   *  Logic: '<S363>/Logical Operator'
   *  RelationalOperator: '<S370>/Compare'
   */
  rtb_Multiply_o = (uint16_T)(INS_DWork.DiscreteTimeIntegrator_DSTATE_c <
    INS_P.valid_hold1_time_out_m ? (int32_T)rtb_LogicalOperator1_ao : 0);

  /* RelationalOperator: '<S347>/Compare' incorporates:
   *  Constant: '<S347>/Constant'
   */
  rtb_Compare_d = (rtb_Multiply_o > INS_P.Constant_Value_bt);

  /* RelationalOperator: '<S345>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S345>/Delay Input1'
   */
  rtb_FixPtRelationalOperator_fr = ((int32_T)rtb_Compare_d > (int32_T)
    INS_DWork.DelayInput1_DSTATE_j);

  /* RelationalOperator: '<S353>/Compare' incorporates:
   *  Constant: '<S353>/Constant'
   */
  rtb_Compare_fc = ((int32_T)rtb_LogicalOperator5_i > (int32_T)
                    INS_P.CompareToConstant1_const_h);

  /* DiscreteIntegrator: '<S350>/Discrete-Time Integrator' */
  if (rtb_Compare_fc || (INS_DWork.DiscreteTimeIntegrator_PrevRe_d != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_n =
      INS_P.DiscreteTimeIntegrator_IC_b;
  }

  /* RelationalOperator: '<S356>/Compare' incorporates:
   *  Constant: '<S354>/Constant'
   *  Constant: '<S356>/Constant'
   *  RelationalOperator: '<S354>/Compare'
   */
  rtb_Compare_g = (((int32_T)rtb_LogicalOperator5_i > (int32_T)
                    INS_P.CompareToConstant2_const_a) > (int32_T)
                   INS_P.Constant_Value_nm);

  /* Logic: '<S350>/Logical Operator1' incorporates:
   *  Delay: '<S350>/Delay'
   *  RelationalOperator: '<S355>/FixPt Relational Operator'
   *  UnitDelay: '<S355>/Delay Input1'
   */
  rtb_LogicalOperator1_ng = (((int32_T)rtb_Compare_g > (int32_T)
    INS_DWork.DelayInput1_DSTATE_kh) || INS_DWork.Delay_DSTATE_ng);

  /* Product: '<S350>/Multiply' incorporates:
   *  Constant: '<S352>/Constant'
   *  DiscreteIntegrator: '<S350>/Discrete-Time Integrator'
   *  Logic: '<S350>/Logical Operator'
   *  RelationalOperator: '<S352>/Compare'
   */
  rtb_Multiply_cb = (uint16_T)(INS_DWork.DiscreteTimeIntegrator_DSTATE_n <
    INS_P.valid_hold_time_out ? (int32_T)rtb_LogicalOperator1_ng : 0);

  /* RelationalOperator: '<S366>/Compare' incorporates:
   *  Constant: '<S366>/Constant'
   */
  rtb_Compare_j = ((int32_T)rtb_Compare_ay > (int32_T)
                   INS_P.CompareToConstant1_const_hv);

  /* DiscreteIntegrator: '<S362>/Discrete-Time Integrator' */
  if (rtb_Compare_j || (INS_DWork.DiscreteTimeIntegrator_PrevRe_b != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_h =
      INS_P.DiscreteTimeIntegrator_IC_h;
  }

  /* RelationalOperator: '<S369>/Compare' incorporates:
   *  Constant: '<S367>/Constant'
   *  Constant: '<S369>/Constant'
   *  RelationalOperator: '<S367>/Compare'
   */
  rtb_Compare_eh1 = (((int32_T)rtb_Compare_ay > (int32_T)
                      INS_P.CompareToConstant2_const_dj) > (int32_T)
                     INS_P.Constant_Value_ej);

  /* Logic: '<S362>/Logical Operator1' incorporates:
   *  Delay: '<S362>/Delay'
   *  RelationalOperator: '<S368>/FixPt Relational Operator'
   *  UnitDelay: '<S368>/Delay Input1'
   */
  rtb_LogicalOperator1_nd = (((int32_T)rtb_Compare_eh1 > (int32_T)
    INS_DWork.DelayInput1_DSTATE_ch) || INS_DWork.Delay_DSTATE_c1);

  /* RelationalOperator: '<S376>/Compare' incorporates:
   *  Constant: '<S376>/Constant'
   */
  rtb_Compare_d3 = ((int32_T)rtb_Compare_ir > (int32_T)
                    INS_P.CompareToConstant1_const_l);

  /* DiscreteIntegrator: '<S364>/Discrete-Time Integrator' */
  if (rtb_Compare_d3 || (INS_DWork.DiscreteTimeIntegrator_PrevR_kt != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_k3 =
      INS_P.DiscreteTimeIntegrator_IC_ms;
  }

  /* RelationalOperator: '<S379>/Compare' incorporates:
   *  Constant: '<S377>/Constant'
   *  Constant: '<S379>/Constant'
   *  RelationalOperator: '<S377>/Compare'
   */
  rtb_Compare_a2 = (((int32_T)rtb_Compare_ir > (int32_T)
                     INS_P.CompareToConstant2_const_h) > (int32_T)
                    INS_P.Constant_Value_i);

  /* Logic: '<S364>/Logical Operator1' incorporates:
   *  Delay: '<S364>/Delay'
   *  RelationalOperator: '<S378>/FixPt Relational Operator'
   *  UnitDelay: '<S378>/Delay Input1'
   */
  rtb_LogicalOperator1_f1 = (((int32_T)rtb_Compare_a2 > (int32_T)
    INS_DWork.DelayInput1_DSTATE_jx) || INS_DWork.Delay_DSTATE_n2o);

  /* Product: '<S364>/Multiply' incorporates:
   *  Constant: '<S375>/Constant'
   *  DiscreteIntegrator: '<S364>/Discrete-Time Integrator'
   *  Logic: '<S364>/Logical Operator'
   *  RelationalOperator: '<S375>/Compare'
   */
  rtb_Multiply_gs = (uint16_T)(INS_DWork.DiscreteTimeIntegrator_DSTAT_k3 <
    INS_P.valid_hold2_time_out ? (int32_T)rtb_LogicalOperator1_f1 : 0);

  /* RelationalOperator: '<S385>/Compare' incorporates:
   *  Constant: '<S365>/Constant'
   *  Constant: '<S385>/Constant'
   *  DiscreteIntegrator: '<S362>/Discrete-Time Integrator'
   *  Logic: '<S362>/Logical Operator'
   *  Product: '<S362>/Multiply'
   *  RelationalOperator: '<S365>/Compare'
   */
  rtb_Compare_e0 = ((INS_DWork.DiscreteTimeIntegrator_DSTATE_h <
                     INS_P.valid_hold_time_out_d ? (int32_T)
                     rtb_LogicalOperator1_nd : 0) > INS_P.Constant_Value_m3);

  /* Switch: '<S382>/Switch4' incorporates:
   *  Delay: '<S382>/Delay1'
   *  Delay generated from: '<S56>/Delay'
   *  RelationalOperator: '<S384>/FixPt Relational Operator'
   *  SignalConversion generated from: '<S323>/Signal Copy5'
   *  Sum: '<S382>/Sum'
   *  UnitDelay: '<S384>/Delay Input1'
   */
  if ((int32_T)rtb_Compare_e0 > (int32_T)INS_DWork.DelayInput1_DSTATE_dp) {
    rtb_ff = rtb_Scalefactor3 - INS_DWork.Delay_6_DSTATE;
  } else {
    rtb_ff = INS_DWork.Delay1_DSTATE;
  }

  /* End of Switch: '<S382>/Switch4' */

  /* RelationalOperator: '<S387>/Compare' incorporates:
   *  Constant: '<S387>/Constant'
   */
  rtb_Compare_cj = (rtb_Multiply_cb > INS_P.Constant_Value_pti);

  /* Switch: '<S383>/Switch1' incorporates:
   *  Delay: '<S383>/Delay'
   *  Delay: '<S383>/Delay1'
   *  Delay generated from: '<S56>/Delay'
   *  Product: '<S383>/Divide'
   *  RelationalOperator: '<S386>/FixPt Relational Operator'
   *  SignalConversion generated from: '<S323>/Signal Copy1'
   *  SignalConversion generated from: '<S323>/Signal Copy3'
   *  SignalConversion generated from: '<S323>/Signal Copy4'
   *  SignalConversion generated from: '<S323>/Signal Copy'
   *  Sum: '<S383>/Sum'
   *  Switch: '<S383>/Switch4'
   *  UnitDelay: '<S386>/Delay Input1'
   */
  if ((int32_T)rtb_Compare_cj > (int32_T)INS_DWork.DelayInput1_DSTATE_mw) {
    rtb_DataTypeConversion2 = INS_B.Rm;
    rtb_Switch1_idx_1 = INS_B.Multiply2;
    rtb_Switch4_c_idx_0 = rtb_Scalefactor1 - INS_DWork.Delay_4_DSTATE_k /
      INS_B.Rm;
    rtb_Switch4_c_idx_1 = rtb_Scalefactor2 - INS_DWork.Delay_5_DSTATE /
      INS_B.Multiply2;
  } else {
    rtb_DataTypeConversion2 = INS_DWork.Delay1_DSTATE_o[0];
    rtb_Switch1_idx_1 = INS_DWork.Delay1_DSTATE_o[1];
    rtb_Switch4_c_idx_0 = INS_DWork.Delay_DSTATE[0];
    rtb_Switch4_c_idx_1 = INS_DWork.Delay_DSTATE[1];
  }

  /* End of Switch: '<S383>/Switch1' */

  /* Update for DiscreteIntegrator: '<S326>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S326>/Constant'
   *  DiscreteIntegrator: '<S326>/Discrete-Time Integrator1'
   *  Gain: '<S326>/Gain'
   *  Gain: '<S326>/Gain1'
   *  SignalConversion generated from: '<S321>/Signal Copy1'
   *  Sum: '<S326>/Sum'
   *  Sum: '<S326>/Sum2'
   * */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_f += ((rtb_Sum2_m -
    INS_DWork.DiscreteTimeIntegrator1_DSTAT_h) * INS_P.Gain_Gain_b -
    INS_P.Gain1_Gain_c * INS_DWork.DiscreteTimeIntegrator_DSTATE_f) *
    INS_P.DiscreteTimeIntegrator_gainva_b;
  if (INS_P.Constant_Value_oi > 0.0F) {
    INS_DWork.DiscreteTimeIntegrator_PrevRe_h = 1;
    INS_DWork.DiscreteTimeIntegrator1_PrevR_d = 1;
  } else if (INS_P.Constant_Value_oi < 0.0F) {
    INS_DWork.DiscreteTimeIntegrator_PrevRe_h = -1;
    INS_DWork.DiscreteTimeIntegrator1_PrevR_d = -1;
  } else if (INS_P.Constant_Value_oi == 0.0F) {
    INS_DWork.DiscreteTimeIntegrator_PrevRe_h = 0;
    INS_DWork.DiscreteTimeIntegrator1_PrevR_d = 0;
  } else {
    INS_DWork.DiscreteTimeIntegrator_PrevRe_h = 2;
    INS_DWork.DiscreteTimeIntegrator1_PrevR_d = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S326>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S326>/Discrete-Time Integrator1' */
  INS_DWork.DiscreteTimeIntegrator1_IC_LO_k = 0U;
  INS_DWork.DiscreteTimeIntegrator1_DSTAT_h +=
    INS_P.DiscreteTimeIntegrator1_gainv_d * rtb_DiscreteTimeIntegrator_nt;

  /* Update for Delay: '<S329>/Delay' */
  INS_DWork.Delay_DSTATE_n2 = rtb_Switch_pt;

  /* Outputs for Atomic SubSystem: '<S55>/AHRS' */
  /* Outputs for Atomic SubSystem: '<S57>/Bus_Constructor' */
  /* Update for UnitDelay: '<S332>/Delay Input1' incorporates:
   *  SignalConversion generated from: '<S59>/Signal Conversion5'
   */
  INS_DWork.DelayInput1_DSTATE_ic = rtb_Switch_g3;

  /* End of Outputs for SubSystem: '<S57>/Bus_Constructor' */
  /* End of Outputs for SubSystem: '<S55>/AHRS' */

  /* Update for Delay: '<S330>/Delay' */
  INS_DWork.Delay_DSTATE_a = rtb_DiscreteTimeIntegrator_eh;

  /* Update for UnitDelay: '<S333>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_cz = rtb_Uk1_m2;

  /* Update for Delay: '<S334>/Delay' */
  INS_DWork.Delay_DSTATE_e = rtb_Uk1_m2;

  /* Update for UnitDelay: '<S344>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_o = rtb_Compare_ce;

  /* Update for DiscreteIntegrator: '<S351>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S351>/Constant'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_b +=
    INS_P.DiscreteTimeIntegrator_gainv_bt * (real32_T)INS_EXPORT.period;
  if (INS_DWork.DiscreteTimeIntegrator_DSTATE_b >
      INS_P.DiscreteTimeIntegrator_UpperS_p) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_b =
      INS_P.DiscreteTimeIntegrator_UpperS_p;
  } else if (INS_DWork.DiscreteTimeIntegrator_DSTATE_b <
             INS_P.DiscreteTimeIntegrator_LowerS_p) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_b =
      INS_P.DiscreteTimeIntegrator_LowerS_p;
  }

  INS_DWork.DiscreteTimeIntegrator_PrevR_ky = (int8_T)rtb_LogicalOperator2_g;

  /* End of Update for DiscreteIntegrator: '<S351>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S360>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_hg = rtb_LogicalOperator3;

  /* Update for Delay: '<S351>/Delay' */
  INS_DWork.Delay_DSTATE_kh = rtb_LogicalOperator1_cc;

  /* Update for UnitDelay: '<S345>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_j = rtb_Compare_d;

  /* Update for DiscreteIntegrator: '<S363>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S363>/Constant'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_c +=
    INS_P.DiscreteTimeIntegrator_gainva_j * (real32_T)INS_EXPORT.period;
  if (INS_DWork.DiscreteTimeIntegrator_DSTATE_c >
      INS_P.DiscreteTimeIntegrator_UpperS_j) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_c =
      INS_P.DiscreteTimeIntegrator_UpperS_j;
  } else if (INS_DWork.DiscreteTimeIntegrator_DSTATE_c <
             INS_P.DiscreteTimeIntegrator_Lower_f2) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_c =
      INS_P.DiscreteTimeIntegrator_Lower_f2;
  }

  INS_DWork.DiscreteTimeIntegrator_PrevRe_l = (int8_T)rtb_Compare_od;

  /* End of Update for DiscreteIntegrator: '<S363>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S373>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_p = rtb_WGS84_pos_valid;

  /* Update for Delay: '<S363>/Delay' */
  INS_DWork.Delay_DSTATE_k4 = rtb_LogicalOperator1_ao;

  /* Update for DiscreteIntegrator: '<S350>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S350>/Constant'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_n +=
    INS_P.DiscreteTimeIntegrator_gainv_iy * (real32_T)INS_EXPORT.period;
  if (INS_DWork.DiscreteTimeIntegrator_DSTATE_n >
      INS_P.DiscreteTimeIntegrator_Upper_jm) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_n =
      INS_P.DiscreteTimeIntegrator_Upper_jm;
  } else if (INS_DWork.DiscreteTimeIntegrator_DSTATE_n <
             INS_P.DiscreteTimeIntegrator_LowerS_d) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_n =
      INS_P.DiscreteTimeIntegrator_LowerS_d;
  }

  INS_DWork.DiscreteTimeIntegrator_PrevRe_d = (int8_T)rtb_Compare_fc;

  /* End of Update for DiscreteIntegrator: '<S350>/Discrete-Time Integrator' */

  /* Update for Delay: '<S350>/Delay' */
  INS_DWork.Delay_DSTATE_ng = rtb_LogicalOperator1_ng;

  /* Update for UnitDelay: '<S355>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_kh = rtb_Compare_g;

  /* Update for DiscreteIntegrator: '<S362>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S362>/Constant'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_h +=
    INS_P.DiscreteTimeIntegrator_gainva_a * (real32_T)INS_EXPORT.period;
  if (INS_DWork.DiscreteTimeIntegrator_DSTATE_h >
      INS_P.DiscreteTimeIntegrator_Upper_fv) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_h =
      INS_P.DiscreteTimeIntegrator_Upper_fv;
  } else if (INS_DWork.DiscreteTimeIntegrator_DSTATE_h <
             INS_P.DiscreteTimeIntegrator_LowerS_b) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_h =
      INS_P.DiscreteTimeIntegrator_LowerS_b;
  }

  INS_DWork.DiscreteTimeIntegrator_PrevRe_b = (int8_T)rtb_Compare_j;

  /* End of Update for DiscreteIntegrator: '<S362>/Discrete-Time Integrator' */

  /* Update for Delay: '<S362>/Delay' */
  INS_DWork.Delay_DSTATE_c1 = rtb_LogicalOperator1_nd;

  /* Update for UnitDelay: '<S368>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_ch = rtb_Compare_eh1;

  /* Update for DiscreteIntegrator: '<S364>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S364>/Constant'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTAT_k3 +=
    INS_P.DiscreteTimeIntegrator_gainv_jp * (real32_T)INS_EXPORT.period;
  if (INS_DWork.DiscreteTimeIntegrator_DSTAT_k3 >
      INS_P.DiscreteTimeIntegrator_UpperS_e) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_k3 =
      INS_P.DiscreteTimeIntegrator_UpperS_e;
  } else if (INS_DWork.DiscreteTimeIntegrator_DSTAT_k3 <
             INS_P.DiscreteTimeIntegrator_Lower_no) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_k3 =
      INS_P.DiscreteTimeIntegrator_Lower_no;
  }

  INS_DWork.DiscreteTimeIntegrator_PrevR_kt = (int8_T)rtb_Compare_d3;

  /* End of Update for DiscreteIntegrator: '<S364>/Discrete-Time Integrator' */

  /* Update for Delay: '<S364>/Delay' */
  INS_DWork.Delay_DSTATE_n2o = rtb_LogicalOperator1_f1;

  /* Update for UnitDelay: '<S378>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_jx = rtb_Compare_a2;

  /* Update for Delay: '<S382>/Delay1' */
  INS_DWork.Delay1_DSTATE = rtb_ff;

  /* Update for UnitDelay: '<S384>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_dp = rtb_Compare_e0;

  /* Update for Delay: '<S383>/Delay' */
  INS_DWork.Delay_DSTATE[0] = rtb_Switch4_c_idx_0;

  /* Update for Delay: '<S383>/Delay1' */
  INS_DWork.Delay1_DSTATE_o[0] = rtb_DataTypeConversion2;

  /* Update for Delay: '<S383>/Delay' */
  INS_DWork.Delay_DSTATE[1] = rtb_Switch4_c_idx_1;

  /* Update for Delay: '<S383>/Delay1' */
  INS_DWork.Delay1_DSTATE_o[1] = rtb_Switch1_idx_1;

  /* Update for UnitDelay: '<S386>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_mw = rtb_Compare_cj;

  /* End of Outputs for SubSystem: '<S56>/TF_Data_PreProcess' */

  /* Outputs for Atomic SubSystem: '<S56>/CF' */
  /* Outputs for Enabled SubSystem: '<S293>/GPS_Reference_Height' incorporates:
   *  EnablePort: '<S297>/Enable'
   */
  if (rtb_Compare_ay) {
    /* Outputs for Atomic SubSystem: '<S56>/TF_Data_PreProcess' */
    /* Merge: '<S293>/Merge' incorporates:
     *  DataTypeConversion: '<S297>/Data Type Conversion'
     *  SignalConversion generated from: '<S323>/Signal Copy5'
     *  Sum: '<S297>/Sum'
     */
    INS_B.Merge = (real32_T)(rtb_Scalefactor3 - rtb_ff);

    /* End of Outputs for SubSystem: '<S56>/TF_Data_PreProcess' */
  }

  /* End of Outputs for SubSystem: '<S293>/GPS_Reference_Height' */

  /* Outputs for Enabled SubSystem: '<S293>/Baro_Reference_Height' incorporates:
   *  EnablePort: '<S295>/Enable'
   */
  if (rtb_Compare_fg) {
    /* Outputs for Atomic SubSystem: '<S56>/TF_Data_PreProcess' */
    /* Merge: '<S293>/Merge' incorporates:
     *  DataTypeConversion: '<S295>/Data Type Conversion'
     *  SignalConversion generated from: '<S321>/Signal Copy1'
     */
    INS_B.Merge = rtb_Sum2_m;

    /* End of Outputs for SubSystem: '<S56>/TF_Data_PreProcess' */
  }

  /* End of Outputs for SubSystem: '<S293>/Baro_Reference_Height' */

  /* Outputs for Enabled SubSystem: '<S293>/Rf_Reference_Height' incorporates:
   *  EnablePort: '<S298>/Enable'
   */
  if (rtb_Compare_ir) {
    /* Outputs for Atomic SubSystem: '<S56>/TF_Data_PreProcess' */
    /* Merge: '<S293>/Merge' incorporates:
     *  DataTypeConversion: '<S298>/Data Type Conversion'
     *  SignalConversion generated from: '<S325>/Signal Copy1'
     */
    INS_B.Merge = rtb_Saturation_a;

    /* End of Outputs for SubSystem: '<S56>/TF_Data_PreProcess' */
  }

  /* End of Outputs for SubSystem: '<S293>/Rf_Reference_Height' */

  /* Outputs for Enabled SubSystem: '<S293>/External_Pos_Height' incorporates:
   *  EnablePort: '<S296>/Enable'
   */
  if (rtb_Compare_n1) {
    /* Merge: '<S293>/Merge' incorporates:
     *  DataTypeConversion: '<S296>/Data Type Conversion'
     */
    INS_B.Merge = rtb_Gauss_to_uT[2];
  }

  /* End of Outputs for SubSystem: '<S293>/External_Pos_Height' */

  /* Outputs for Enabled SubSystem: '<S294>/GPS_Velocity' incorporates:
   *  EnablePort: '<S300>/Enable'
   */
  if (rtb_Compare_fg) {
    /* Outputs for Atomic SubSystem: '<S56>/TF_Data_PreProcess' */
    /* Merge: '<S294>/Merge' incorporates:
     *  DataTypeConversion: '<S300>/Data Type Conversion'
     *  SignalConversion generated from: '<S323>/Signal Copy8'
     */
    INS_B.Merge_e = rtb_Gain2_a;

    /* End of Outputs for SubSystem: '<S56>/TF_Data_PreProcess' */
  }

  /* End of Outputs for SubSystem: '<S294>/GPS_Velocity' */

  /* Outputs for Enabled SubSystem: '<S294>/Baro_Velocity' */
  INS_Baro_Velocity(rtb_Compare_fg, &INS_B.Merge_e, &INS_P.Baro_Velocity);

  /* End of Outputs for SubSystem: '<S294>/Baro_Velocity' */

  /* Outputs for Enabled SubSystem: '<S294>/Rf_Velocity' */
  INS_Baro_Velocity(rtb_Compare_fg, &INS_B.Merge_e, &INS_P.Rf_Velocity);

  /* End of Outputs for SubSystem: '<S294>/Rf_Velocity' */

  /* Switch: '<S290>/Switch' incorporates:
   *  Constant: '<S292>/Constant'
   *  Delay: '<S290>/Delay'
   *  Product: '<S237>/Multiply'
   */
  if (rtb_FixPtRelationalOperator_fr) {
    rtb_MathFunction[0] = INS_B.Merge;
    rtb_MathFunction[1] = INS_B.Merge_e;
    rtb_MathFunction[2] = INS_P.Constant_Value_e;
  } else {
    rtb_MathFunction[0] = INS_DWork.Delay_DSTATE_b[0];
    rtb_MathFunction[1] = INS_DWork.Delay_DSTATE_b[1];
    rtb_MathFunction[2] = INS_DWork.Delay_DSTATE_b[2];
  }

  /* End of Switch: '<S290>/Switch' */

  /* Product: '<S291>/Multiply' incorporates:
   *  Inport: '<Root>/IMU'
   *  Math: '<S114>/Transpose'
   *  SignalConversion generated from: '<S436>/Bus Selector1'
   *  SignalConversion generated from: '<S59>/Rotation_Data'
   * */
  for (rtb_MathFunction1_tmp = 0; rtb_MathFunction1_tmp < 3;
       rtb_MathFunction1_tmp++) {
    /* Outputs for Atomic SubSystem: '<S55>/AHRS' */
    /* Outputs for Atomic SubSystem: '<S57>/Bus_Constructor' */
    /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
    /* Outputs for Atomic SubSystem: '<S3>/IMU_PreProcess' */
    rtb_MathFunction_j[rtb_MathFunction1_tmp] =
      (rtb_VectorConcatenate_g[rtb_MathFunction1_tmp + 3] * INS_U.IMU.acc_y +
       rtb_VectorConcatenate_g[rtb_MathFunction1_tmp] * INS_U.IMU.acc_x) +
      rtb_VectorConcatenate_g[rtb_MathFunction1_tmp + 6] * INS_U.IMU.acc_z;

    /* End of Outputs for SubSystem: '<S3>/IMU_PreProcess' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */
    /* End of Outputs for SubSystem: '<S57>/Bus_Constructor' */
    /* End of Outputs for SubSystem: '<S55>/AHRS' */
  }

  /* Sum: '<S291>/Sum' incorporates:
   *  Constant: '<S291>/Constant'
   *  Constant: '<S291>/Constant1'
   *  Gain: '<S291>/Gain'
   *  Gain: '<S291>/Gain1'
   *  Product: '<S237>/Multiply'
   *  Product: '<S291>/Multiply'
   *  Sum: '<S291>/Add'
   */
  rtb_Gain1_n_idx_0 = INS_P.Gain1_Gain_k * rtb_MathFunction[1] *
    INS_P.Gain_Gain_mr + rtb_MathFunction[0];
  rtb_Gain1_n_idx_1 = ((rtb_MathFunction_j[2] - rtb_MathFunction[2]) +
                       INS_P.INS_CONST.g) * INS_P.Gain_Gain_mr +
    rtb_MathFunction[1];
  rtb_Gain1_n_idx_2 = INS_P.Gain_Gain_mr * INS_P.Constant_Value_nn +
    rtb_MathFunction[2];

  /* Outputs for Enabled SubSystem: '<S247>/Baro_Correct' incorporates:
   *  EnablePort: '<S251>/Enable'
   */
  if (rtb_Compare_fg) {
    if (!INS_DWork.Baro_Correct_MODE) {
      /* InitializeConditions for UnitDelay: '<S252>/Delay Input1' */
      INS_DWork.DelayInput1_DSTATE_lg = INS_P.DetectChange_vinit_m;

      /* InitializeConditions for Delay: '<S253>/Delay' */
      INS_DWork.Delay_DSTATE_dr[0] = INS_P.Delay_InitialCondition_j;
      INS_DWork.Delay_DSTATE_dr[1] = INS_P.Delay_InitialCondition_j;
      INS_DWork.Delay_DSTATE_dr[2] = INS_P.Delay_InitialCondition_j;

      /* InitializeConditions for Delay: '<S255>/x_delay' */
      INS_DWork.icLoad_a = true;

      /* InitializeConditions for UnitDelay: '<S259>/Delay Input1' */
      INS_DWork.DelayInput1_DSTATE_f = INS_P.DetectIncrease_vinit_c;

      /* InitializeConditions for Delay: '<S257>/Delay' */
      INS_DWork.Delay_DSTATE_h = INS_P.Delay_InitialCondition_mk;
      INS_DWork.Baro_Correct_MODE = true;
    }

    /* Delay: '<S255>/x_delay' */
    INS_DWork.icLoad_a = ((rtb_FixPtRelationalOperator_fr &&
      (INS_PrevZCSigState.x_delay_Reset_ZCE_l != POS_ZCSIG)) ||
                          INS_DWork.icLoad_a);
    INS_PrevZCSigState.x_delay_Reset_ZCE_l = rtb_FixPtRelationalOperator_fr;
    if (INS_DWork.icLoad_a) {
      for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 500;
           rtb_Saturation1_j_idx_1++) {
        INS_DWork.x_delay_DSTATE_b[rtb_Saturation1_j_idx_1] = rtb_Gain1_n_idx_0;
      }
    }

    /* RelationalOperator: '<S259>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S259>/Delay Input1'
     */
    rtb_WGS84_pos_valid = !INS_DWork.DelayInput1_DSTATE_f;

    /* Switch: '<S257>/Switch' incorporates:
     *  Delay: '<S257>/Delay'
     *  Sum: '<S258>/Sum'
     */
    if (rtb_WGS84_pos_valid) {
      rtb_mag_valid = rtb_Gain1_n_idx_0 - rtb_mag_valid;
    } else {
      rtb_mag_valid = INS_DWork.Delay_DSTATE_h;
    }

    /* End of Switch: '<S257>/Switch' */

    /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
    /* Outputs for Atomic SubSystem: '<S3>/Baro_PreProcess' */
    /* Logic: '<S251>/Logical Operator' incorporates:
     *  Inport: '<Root>/Barometer'
     *  RelationalOperator: '<S252>/FixPt Relational Operator'
     *  SignalConversion generated from: '<S389>/Baro_Data'
     *  UnitDelay: '<S252>/Delay Input1'
     */
    rtb_WGS84_pos_valid = (rtb_WGS84_pos_valid || (INS_U.Barometer.timestamp !=
      INS_DWork.DelayInput1_DSTATE_lg));

    /* End of Outputs for SubSystem: '<S3>/Baro_PreProcess' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */

    /* Switch: '<S253>/Switch' incorporates:
     *  Delay: '<S253>/Delay'
     *  Gain: '<S254>/Gain'
     *  Gain: '<S254>/Gain1'
     *  Gain: '<S254>/Gain2'
     */
    if (rtb_WGS84_pos_valid) {
      /* Outputs for Atomic SubSystem: '<S56>/TF_Data_PreProcess' */
      /* Sum: '<S251>/Sum' incorporates:
       *  Delay: '<S255>/x_delay'
       *  SignalConversion generated from: '<S321>/Signal Copy1'
       *  Sum: '<S256>/Sum1'
       */
      rtb_Sum2_m = (rtb_Sum2_m + rtb_mag_valid) - rtb_Gain1_n_idx_0;

      /* End of Outputs for SubSystem: '<S56>/TF_Data_PreProcess' */

      /* Saturate: '<S254>/Saturation' */
      if (rtb_Sum2_m > INS_P.Saturation_UpperSat_b) {
        rtb_Sum2_m = INS_P.Saturation_UpperSat_b;
      } else if (rtb_Sum2_m < INS_P.Saturation_LowerSat_c) {
        rtb_Sum2_m = INS_P.Saturation_LowerSat_c;
      }

      /* End of Saturate: '<S254>/Saturation' */
      rtb_MathFunction[0] = INS_PARAM.BARO_H_GAIN * rtb_Sum2_m;
      rtb_MathFunction[1] = -INS_PARAM.BARO_VZ_GAIN * rtb_Sum2_m;
      rtb_MathFunction[2] = INS_PARAM.BARO_BIAS_AZ_GAIN * rtb_Sum2_m;
    } else {
      rtb_MathFunction[0] = INS_DWork.Delay_DSTATE_dr[0];
      rtb_MathFunction[1] = INS_DWork.Delay_DSTATE_dr[1];
      rtb_MathFunction[2] = INS_DWork.Delay_DSTATE_dr[2];
    }

    /* End of Switch: '<S253>/Switch' */

    /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
    /* Outputs for Atomic SubSystem: '<S3>/Baro_PreProcess' */
    /* Update for UnitDelay: '<S252>/Delay Input1' incorporates:
     *  Inport: '<Root>/Barometer'
     *  SignalConversion generated from: '<S389>/Baro_Data'
     */
    INS_DWork.DelayInput1_DSTATE_lg = INS_U.Barometer.timestamp;

    /* End of Outputs for SubSystem: '<S3>/Baro_PreProcess' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */

    /* Sum: '<S251>/Sum1' incorporates:
     *  Gain: '<S253>/Gain'
     *  Sum: '<S291>/Sum'
     */
    INS_B.Sum1_pu[0] = INS_P.Gain_Gain_pln * rtb_MathFunction[0] +
      rtb_Gain1_n_idx_0;

    /* Update for Delay: '<S253>/Delay' incorporates:
     *  Gain: '<S253>/Gain'
     */
    INS_DWork.Delay_DSTATE_dr[0] = rtb_MathFunction[0];

    /* Sum: '<S251>/Sum1' incorporates:
     *  Gain: '<S253>/Gain'
     *  Sum: '<S291>/Sum'
     */
    INS_B.Sum1_pu[1] = INS_P.Gain_Gain_pln * rtb_MathFunction[1] +
      rtb_Gain1_n_idx_1;

    /* Update for Delay: '<S253>/Delay' incorporates:
     *  Gain: '<S253>/Gain'
     */
    INS_DWork.Delay_DSTATE_dr[1] = rtb_MathFunction[1];

    /* Sum: '<S251>/Sum1' incorporates:
     *  Gain: '<S253>/Gain'
     *  Sum: '<S291>/Sum'
     */
    INS_B.Sum1_pu[2] = INS_P.Gain_Gain_pln * rtb_MathFunction[2] +
      rtb_Gain1_n_idx_2;

    /* Update for Delay: '<S253>/Delay' incorporates:
     *  Gain: '<S253>/Gain'
     */
    INS_DWork.Delay_DSTATE_dr[2] = rtb_MathFunction[2];

    /* Saturate: '<S251>/Saturation' */
    if (INS_B.Sum1_pu[2] > INS_P.Saturation_UpperSat_as) {
      /* Saturate: '<S251>/Saturation' */
      INS_B.Saturation = INS_P.Saturation_UpperSat_as;
    } else if (INS_B.Sum1_pu[2] < INS_P.Saturation_LowerSat_e) {
      /* Saturate: '<S251>/Saturation' */
      INS_B.Saturation = INS_P.Saturation_LowerSat_e;
    } else {
      /* Saturate: '<S251>/Saturation' */
      INS_B.Saturation = INS_B.Sum1_pu[2];
    }

    /* End of Saturate: '<S251>/Saturation' */

    /* Update for Delay: '<S255>/x_delay' */
    INS_DWork.icLoad_a = false;
    for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 499;
         rtb_Saturation1_j_idx_1++) {
      INS_DWork.x_delay_DSTATE_b[rtb_Saturation1_j_idx_1] =
        INS_DWork.x_delay_DSTATE_b[rtb_Saturation1_j_idx_1 + 1];
    }

    INS_DWork.x_delay_DSTATE_b[499] = rtb_Gain1_n_idx_0;

    /* End of Update for Delay: '<S255>/x_delay' */

    /* Update for UnitDelay: '<S259>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_f = true;

    /* Update for Delay: '<S257>/Delay' */
    INS_DWork.Delay_DSTATE_h = rtb_mag_valid;

    /* Switch: '<S247>/Switch' */
    rtb_MathFunction[0] = INS_B.Sum1_pu[0];
    rtb_MathFunction[1] = INS_B.Sum1_pu[1];
    rtb_MathFunction[2] = INS_B.Saturation;
  } else {
    INS_DWork.Baro_Correct_MODE = false;

    /* Switch: '<S247>/Switch' incorporates:
     *  Sum: '<S291>/Sum'
     */
    rtb_MathFunction[0] = rtb_Gain1_n_idx_0;
    rtb_MathFunction[1] = rtb_Gain1_n_idx_1;
    rtb_MathFunction[2] = rtb_Gain1_n_idx_2;
  }

  /* End of Outputs for SubSystem: '<S247>/Baro_Correct' */

  /* Outputs for Enabled SubSystem: '<S249>/GPS_Correct' incorporates:
   *  EnablePort: '<S269>/Enable'
   */
  if (rtb_Compare_ay) {
    if (!INS_DWork.GPS_Correct_MODE) {
      /* InitializeConditions for UnitDelay: '<S270>/Delay Input1' */
      INS_DWork.DelayInput1_DSTATE_d = INS_P.DetectChange_vinit_h;

      /* InitializeConditions for Delay: '<S273>/h_delay' */
      INS_DWork.icLoad_o = true;

      /* InitializeConditions for Delay: '<S273>/vd_delay' */
      INS_DWork.icLoad_f = true;

      /* InitializeConditions for UnitDelay: '<S277>/Delay Input1' */
      INS_DWork.DelayInput1_DSTATE_ib = INS_P.DetectIncrease_vinit_ji;

      /* InitializeConditions for Memory: '<S275>/Memory' */
      INS_DWork.Memory_PreviousInput_b = INS_P.Memory_InitialCondition_p;

      /* InitializeConditions for Memory: '<S271>/Memory' */
      INS_DWork.Memory_PreviousInput_e[0] = INS_P.Memory_InitialCondition_c;
      INS_DWork.Memory_PreviousInput_e[1] = INS_P.Memory_InitialCondition_c;
      INS_DWork.Memory_PreviousInput_e[2] = INS_P.Memory_InitialCondition_c;
      INS_DWork.GPS_Correct_MODE = true;
    }

    /* Delay: '<S273>/h_delay' */
    INS_DWork.icLoad_o = ((rtb_FixPtRelationalOperator_fr &&
      (INS_PrevZCSigState.h_delay_Reset_ZCE_m != POS_ZCSIG)) ||
                          INS_DWork.icLoad_o);
    INS_PrevZCSigState.h_delay_Reset_ZCE_m = rtb_FixPtRelationalOperator_fr;

    /* Delay: '<S273>/vd_delay' incorporates:
     *  Delay: '<S273>/h_delay'
     */
    INS_DWork.icLoad_f = ((rtb_FixPtRelationalOperator_fr &&
      (INS_PrevZCSigState.vd_delay_Reset_ZCE != POS_ZCSIG)) ||
                          INS_DWork.icLoad_f);
    INS_PrevZCSigState.vd_delay_Reset_ZCE = rtb_FixPtRelationalOperator_fr;
    for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 500;
         rtb_Saturation1_j_idx_1++) {
      /* Delay: '<S273>/h_delay' */
      if (INS_DWork.icLoad_o) {
        INS_DWork.h_delay_DSTATE_l[rtb_Saturation1_j_idx_1] = rtb_MathFunction[0];
      }

      /* Delay: '<S273>/vd_delay' */
      if (INS_DWork.icLoad_f) {
        INS_DWork.vd_delay_DSTATE[rtb_Saturation1_j_idx_1] = rtb_MathFunction[1];
      }
    }

    /* Outputs for Atomic SubSystem: '<S56>/TF_Data_PreProcess' */
    /* DataTypeConversion: '<S274>/Data Type Conversion' incorporates:
     *  SignalConversion generated from: '<S323>/Signal Copy5'
     *  Sum: '<S274>/Sum'
     */
    rtb_DiscreteTimeIntegrator_g = (real32_T)(rtb_Scalefactor3 - rtb_ff);

    /* End of Outputs for SubSystem: '<S56>/TF_Data_PreProcess' */

    /* RelationalOperator: '<S277>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S277>/Delay Input1'
     */
    rtb_WGS84_pos_valid = !INS_DWork.DelayInput1_DSTATE_ib;

    /* Switch: '<S275>/Switch' incorporates:
     *  Memory: '<S275>/Memory'
     *  Sum: '<S276>/Sum'
     */
    if (rtb_WGS84_pos_valid) {
      rtb_Sum2_m = rtb_MathFunction[0] - rtb_DiscreteTimeIntegrator_g;
    } else {
      rtb_Sum2_m = INS_DWork.Memory_PreviousInput_b;
    }

    /* End of Switch: '<S275>/Switch' */

    /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
    /* Outputs for Atomic SubSystem: '<S3>/Baro_PreProcess' */
    /* Logic: '<S269>/Logical Operator' incorporates:
     *  Inport: '<Root>/Barometer'
     *  RelationalOperator: '<S270>/FixPt Relational Operator'
     *  SignalConversion generated from: '<S389>/Baro_Data'
     *  UnitDelay: '<S270>/Delay Input1'
     */
    rtb_WGS84_pos_valid = (rtb_WGS84_pos_valid || (INS_U.Barometer.timestamp !=
      INS_DWork.DelayInput1_DSTATE_d));

    /* End of Outputs for SubSystem: '<S3>/Baro_PreProcess' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */

    /* Switch: '<S271>/Switch' incorporates:
     *  Gain: '<S272>/Gain'
     *  Gain: '<S272>/Gain2'
     *  Gain: '<S272>/Gain4'
     *  Memory: '<S271>/Memory'
     *  Sum: '<S272>/Sum'
     */
    if (rtb_WGS84_pos_valid) {
      /* Outputs for Atomic SubSystem: '<S56>/TF_Data_PreProcess' */
      /* Sum: '<S269>/Sum' incorporates:
       *  Delay: '<S273>/vd_delay'
       *  SignalConversion generated from: '<S323>/Signal Copy8'
       */
      rtb_Memory_m_idx_1 = rtb_Gain2_a - rtb_MathFunction[1];

      /* End of Outputs for SubSystem: '<S56>/TF_Data_PreProcess' */

      /* Gain: '<S272>/Gain1' incorporates:
       *  Delay: '<S273>/h_delay'
       *  Sum: '<S269>/Sum'
       *  Sum: '<S274>/Sum1'
       */
      rtb_Gain2_a = ((rtb_DiscreteTimeIntegrator_g + rtb_Sum2_m) -
                     rtb_MathFunction[0]) * INS_PARAM.GPS_ALT_GAIN;
      rtb_Gain1_n_idx_0 = rtb_Gain2_a;
      rtb_Gain1_n_idx_1 = INS_P.Gain4_Gain_b * rtb_Gain2_a +
        INS_PARAM.GPS_VEL_GAIN * rtb_Memory_m_idx_1;
      rtb_Gain1_n_idx_2 = -INS_PARAM.GPS_BIAS_A_GAIN * rtb_Memory_m_idx_1;
    } else {
      rtb_Gain1_n_idx_0 = INS_DWork.Memory_PreviousInput_e[0];
      rtb_Gain1_n_idx_1 = INS_DWork.Memory_PreviousInput_e[1];
      rtb_Gain1_n_idx_2 = INS_DWork.Memory_PreviousInput_e[2];
    }

    /* End of Switch: '<S271>/Switch' */

    /* Sum: '<S269>/Sum1' incorporates:
     *  Gain: '<S271>/Gain3'
     *  Switch: '<S247>/Switch'
     */
    INS_B.Sum1_p[0] = INS_P.Gain3_Gain_k * rtb_Gain1_n_idx_0 + rtb_MathFunction
      [0];
    INS_B.Sum1_p[1] = INS_P.Gain3_Gain_k * rtb_Gain1_n_idx_1 + rtb_MathFunction
      [1];
    INS_B.Sum1_p[2] = INS_P.Gain3_Gain_k * rtb_Gain1_n_idx_2 + rtb_MathFunction
      [2];

    /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
    /* Outputs for Atomic SubSystem: '<S3>/Baro_PreProcess' */
    /* Update for UnitDelay: '<S270>/Delay Input1' incorporates:
     *  Inport: '<Root>/Barometer'
     *  SignalConversion generated from: '<S389>/Baro_Data'
     */
    INS_DWork.DelayInput1_DSTATE_d = INS_U.Barometer.timestamp;

    /* End of Outputs for SubSystem: '<S3>/Baro_PreProcess' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */

    /* Update for Delay: '<S273>/h_delay' */
    INS_DWork.icLoad_o = false;

    /* Update for Delay: '<S273>/vd_delay' */
    INS_DWork.icLoad_f = false;
    for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 499;
         rtb_Saturation1_j_idx_1++) {
      /* Update for Delay: '<S273>/h_delay' */
      INS_DWork.h_delay_DSTATE_l[rtb_Saturation1_j_idx_1] =
        INS_DWork.h_delay_DSTATE_l[rtb_Saturation1_j_idx_1 + 1];

      /* Update for Delay: '<S273>/vd_delay' */
      INS_DWork.vd_delay_DSTATE[rtb_Saturation1_j_idx_1] =
        INS_DWork.vd_delay_DSTATE[rtb_Saturation1_j_idx_1 + 1];
    }

    /* Update for Delay: '<S273>/h_delay' */
    INS_DWork.h_delay_DSTATE_l[499] = rtb_MathFunction[0];

    /* Update for Delay: '<S273>/vd_delay' */
    INS_DWork.vd_delay_DSTATE[499] = rtb_MathFunction[1];

    /* Update for UnitDelay: '<S277>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_ib = true;

    /* Update for Memory: '<S275>/Memory' */
    INS_DWork.Memory_PreviousInput_b = rtb_Sum2_m;

    /* Update for Memory: '<S271>/Memory' */
    INS_DWork.Memory_PreviousInput_e[0] = rtb_Gain1_n_idx_0;
    INS_DWork.Memory_PreviousInput_e[1] = rtb_Gain1_n_idx_1;
    INS_DWork.Memory_PreviousInput_e[2] = rtb_Gain1_n_idx_2;

    /* Switch: '<S249>/Switch' incorporates:
     *  Sum: '<S269>/Sum1'
     */
    rtb_MathFunction[0] = INS_B.Sum1_p[0];
    rtb_MathFunction[1] = INS_B.Sum1_p[1];
    rtb_MathFunction[2] = INS_B.Sum1_p[2];
  } else {
    INS_DWork.GPS_Correct_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S249>/GPS_Correct' */

  /* Outputs for Enabled SubSystem: '<S250>/Rangefinder_Correct' incorporates:
   *  EnablePort: '<S278>/Enable'
   */
  if (rtb_Compare_ir) {
    if (!INS_DWork.Rangefinder_Correct_MODE) {
      /* InitializeConditions for UnitDelay: '<S279>/Delay Input1' */
      INS_DWork.DelayInput1_DSTATE_l = INS_P.DetectChange_vinit_g;

      /* InitializeConditions for Delay: '<S282>/h_delay' */
      INS_DWork.icLoad = true;

      /* InitializeConditions for UnitDelay: '<S286>/Delay Input1' */
      INS_DWork.DelayInput1_DSTATE_oe = INS_P.DetectIncrease_vinit_a;

      /* InitializeConditions for Delay: '<S287>/Delay' */
      INS_DWork.Delay_DSTATE_f = INS_P.Delay_InitialCondition_dc;

      /* InitializeConditions for Delay: '<S287>/Delay1' */
      INS_DWork.icLoad_b = true;

      /* InitializeConditions for UnitDelay: '<S289>/Delay Input1' */
      INS_DWork.DelayInput1_DSTATE_m = INS_P.DetectIncrease_vinit;

      /* InitializeConditions for Delay: '<S287>/Delay2' */
      INS_DWork.Delay2_DSTATE_o = INS_P.Delay2_InitialCondition_o;

      /* InitializeConditions for Memory: '<S284>/Memory' */
      INS_DWork.Memory_PreviousInput = INS_P.Memory_InitialCondition_g;

      /* InitializeConditions for Memory: '<S280>/Memory' */
      INS_DWork.Memory_PreviousInput_f[0] = INS_P.Memory_InitialCondition_h;
      INS_DWork.Memory_PreviousInput_f[1] = INS_P.Memory_InitialCondition_h;
      INS_DWork.Memory_PreviousInput_f[2] = INS_P.Memory_InitialCondition_h;
      INS_DWork.Rangefinder_Correct_MODE = true;
    }

    /* Delay: '<S282>/h_delay' */
    INS_DWork.icLoad = ((rtb_FixPtRelationalOperator_fr &&
                         (INS_PrevZCSigState.h_delay_Reset_ZCE != POS_ZCSIG)) ||
                        INS_DWork.icLoad);
    INS_PrevZCSigState.h_delay_Reset_ZCE = rtb_FixPtRelationalOperator_fr;
    if (INS_DWork.icLoad) {
      for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 500;
           rtb_Saturation1_j_idx_1++) {
        INS_DWork.h_delay_DSTATE[rtb_Saturation1_j_idx_1] = rtb_MathFunction[0];
      }
    }

    /* Delay: '<S287>/Delay1' incorporates:
     *  Inport: '<Root>/Rangefinder'
     *  SignalConversion generated from: '<S395>/Rangefinder_Data'
     */
    if (INS_DWork.icLoad_b) {
      /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
      /* Outputs for Atomic SubSystem: '<S3>/Rangefinder_PreProcess' */
      INS_DWork.Delay1_DSTATE_p = INS_U.Rangefinder.timestamp;

      /* End of Outputs for SubSystem: '<S3>/Rangefinder_PreProcess' */
      /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */
    }

    /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
    /* Outputs for Atomic SubSystem: '<S3>/Rangefinder_PreProcess' */
    /* Switch: '<S287>/Switch' incorporates:
     *  Delay: '<S287>/Delay1'
     *  Delay: '<S287>/Delay2'
     *  Inport: '<Root>/Rangefinder'
     *  RelationalOperator: '<S289>/FixPt Relational Operator'
     *  SignalConversion generated from: '<S395>/Rangefinder_Data'
     *  Sum: '<S287>/Sum1'
     *  UnitDelay: '<S289>/Delay Input1'
     */
    if (INS_U.Rangefinder.timestamp > INS_DWork.DelayInput1_DSTATE_m) {
      rtb_Sum1 = INS_U.Rangefinder.timestamp - INS_DWork.Delay1_DSTATE_p;
    } else {
      rtb_Sum1 = INS_DWork.Delay2_DSTATE_o;
    }

    /* End of Switch: '<S287>/Switch' */
    /* End of Outputs for SubSystem: '<S3>/Rangefinder_PreProcess' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */

    /* Switch: '<S287>/Switch1' incorporates:
     *  Constant: '<S287>/Constant'
     */
    if (rtb_Sum1 > INS_P.Switch1_Threshold) {
      rtb_Sum1_o = rtb_Sum1;
    } else {
      rtb_Sum1_o = INS_P.Constant_Value_kt;
    }

    /* Outputs for Atomic SubSystem: '<S56>/TF_Data_PreProcess' */
    /* Logic: '<S284>/Logical Operator' incorporates:
     *  Abs: '<S287>/Abs'
     *  Constant: '<S287>/Constant1'
     *  Constant: '<S287>/Constant2'
     *  Constant: '<S288>/Constant'
     *  Delay: '<S287>/Delay'
     *  Logic: '<S287>/Logical Operator'
     *  Product: '<S287>/Divide'
     *  Product: '<S287>/Multiply'
     *  Product: '<S287>/Multiply1'
     *  RelationalOperator: '<S288>/Compare'
     *  SignalConversion generated from: '<S325>/Signal Copy1'
     *  Sum: '<S287>/Sum'
     *  Switch: '<S287>/Switch1'
     *  UnitDelay: '<S286>/Delay Input1'
     */
    rtb_WGS84_pos_valid = ((!INS_DWork.DelayInput1_DSTATE_oe) || ((fabsf
      ((rtb_Saturation_a - INS_DWork.Delay_DSTATE_f) * (INS_P.Constant1_Value_b /
      (real32_T)rtb_Sum1_o)) > INS_P.CompareToConstant_const_hd ?
      INS_PARAM.TERRAIN_TRACK == 0 : 0) != 0));

    /* End of Outputs for SubSystem: '<S56>/TF_Data_PreProcess' */

    /* Switch: '<S284>/Switch' */
    if (rtb_WGS84_pos_valid) {
      /* Outputs for Atomic SubSystem: '<S56>/TF_Data_PreProcess' */
      /* Switch: '<S284>/Switch' incorporates:
       *  SignalConversion generated from: '<S325>/Signal Copy1'
       *  Sum: '<S285>/Sum'
       */
      INS_B.rf_height_bias = rtb_MathFunction[0] - rtb_Saturation_a;

      /* End of Outputs for SubSystem: '<S56>/TF_Data_PreProcess' */
    } else {
      /* Switch: '<S284>/Switch' incorporates:
       *  Memory: '<S284>/Memory'
       */
      INS_B.rf_height_bias = INS_DWork.Memory_PreviousInput;
    }

    /* End of Switch: '<S284>/Switch' */

    /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
    /* Outputs for Atomic SubSystem: '<S3>/Rangefinder_PreProcess' */
    /* Logic: '<S278>/Logical Operator' incorporates:
     *  Inport: '<Root>/Rangefinder'
     *  RelationalOperator: '<S279>/FixPt Relational Operator'
     *  SignalConversion generated from: '<S395>/Rangefinder_Data'
     *  UnitDelay: '<S279>/Delay Input1'
     */
    rtb_WGS84_pos_valid = (rtb_WGS84_pos_valid || (INS_U.Rangefinder.timestamp
      != INS_DWork.DelayInput1_DSTATE_l));

    /* End of Outputs for SubSystem: '<S3>/Rangefinder_PreProcess' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */

    /* Switch: '<S280>/Switch' incorporates:
     *  Gain: '<S281>/Gain'
     *  Gain: '<S281>/Gain1'
     *  Gain: '<S281>/Gain2'
     *  Memory: '<S280>/Memory'
     */
    if (rtb_WGS84_pos_valid) {
      /* Outputs for Atomic SubSystem: '<S56>/TF_Data_PreProcess' */
      /* Sum: '<S278>/Sum' incorporates:
       *  Delay: '<S282>/h_delay'
       *  SignalConversion generated from: '<S325>/Signal Copy1'
       *  Sum: '<S283>/Sum1'
       */
      rtb_Gain2_a = (rtb_Saturation_a + INS_B.rf_height_bias) -
        rtb_MathFunction[0];

      /* End of Outputs for SubSystem: '<S56>/TF_Data_PreProcess' */

      /* Saturate: '<S281>/Saturation' */
      if (rtb_Gain2_a > INS_P.Saturation_UpperSat_i) {
        rtb_Gain2_a = INS_P.Saturation_UpperSat_i;
      } else if (rtb_Gain2_a < INS_P.Saturation_LowerSat_h) {
        rtb_Gain2_a = INS_P.Saturation_LowerSat_h;
      }

      /* End of Saturate: '<S281>/Saturation' */
      rtb_Gain1_n_idx_0 = INS_PARAM.RF_H_GAIN * rtb_Gain2_a;
      rtb_Gain1_n_idx_1 = -INS_PARAM.RF_VZ_GAIN * rtb_Gain2_a;
      rtb_Gain1_n_idx_2 = INS_PARAM.RF_BIAS_AZ_GAIN * rtb_Gain2_a;
    } else {
      rtb_Gain1_n_idx_0 = INS_DWork.Memory_PreviousInput_f[0];
      rtb_Gain1_n_idx_1 = INS_DWork.Memory_PreviousInput_f[1];
      rtb_Gain1_n_idx_2 = INS_DWork.Memory_PreviousInput_f[2];
    }

    /* End of Switch: '<S280>/Switch' */

    /* Sum: '<S278>/Sum1' incorporates:
     *  Gain: '<S280>/Gain3'
     *  Switch: '<S249>/Switch'
     */
    INS_B.Sum1[0] = INS_P.Gain3_Gain_j * rtb_Gain1_n_idx_0 + rtb_MathFunction[0];
    INS_B.Sum1[1] = INS_P.Gain3_Gain_j * rtb_Gain1_n_idx_1 + rtb_MathFunction[1];
    INS_B.Sum1[2] = INS_P.Gain3_Gain_j * rtb_Gain1_n_idx_2 + rtb_MathFunction[2];

    /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
    /* Outputs for Atomic SubSystem: '<S3>/Rangefinder_PreProcess' */
    /* Update for UnitDelay: '<S279>/Delay Input1' incorporates:
     *  Inport: '<Root>/Rangefinder'
     *  SignalConversion generated from: '<S395>/Rangefinder_Data'
     */
    INS_DWork.DelayInput1_DSTATE_l = INS_U.Rangefinder.timestamp;

    /* End of Outputs for SubSystem: '<S3>/Rangefinder_PreProcess' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */

    /* Update for Delay: '<S282>/h_delay' */
    INS_DWork.icLoad = false;
    for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 499;
         rtb_Saturation1_j_idx_1++) {
      INS_DWork.h_delay_DSTATE[rtb_Saturation1_j_idx_1] =
        INS_DWork.h_delay_DSTATE[rtb_Saturation1_j_idx_1 + 1];
    }

    INS_DWork.h_delay_DSTATE[499] = rtb_MathFunction[0];

    /* End of Update for Delay: '<S282>/h_delay' */

    /* Update for UnitDelay: '<S286>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_oe = true;

    /* Outputs for Atomic SubSystem: '<S56>/TF_Data_PreProcess' */
    /* Update for Delay: '<S287>/Delay' incorporates:
     *  SignalConversion generated from: '<S325>/Signal Copy1'
     */
    INS_DWork.Delay_DSTATE_f = rtb_Saturation_a;

    /* End of Outputs for SubSystem: '<S56>/TF_Data_PreProcess' */

    /* Update for Delay: '<S287>/Delay1' incorporates:
     *  Inport: '<Root>/Rangefinder'
     *  SignalConversion generated from: '<S395>/Rangefinder_Data'
     */
    INS_DWork.icLoad_b = false;

    /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
    /* Outputs for Atomic SubSystem: '<S3>/Rangefinder_PreProcess' */
    INS_DWork.Delay1_DSTATE_p = INS_U.Rangefinder.timestamp;

    /* Update for UnitDelay: '<S289>/Delay Input1' incorporates:
     *  Inport: '<Root>/Rangefinder'
     *  SignalConversion generated from: '<S395>/Rangefinder_Data'
     */
    INS_DWork.DelayInput1_DSTATE_m = INS_U.Rangefinder.timestamp;

    /* End of Outputs for SubSystem: '<S3>/Rangefinder_PreProcess' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */

    /* Update for Delay: '<S287>/Delay2' */
    INS_DWork.Delay2_DSTATE_o = rtb_Sum1;

    /* Update for Memory: '<S284>/Memory' */
    INS_DWork.Memory_PreviousInput = INS_B.rf_height_bias;

    /* Update for Memory: '<S280>/Memory' */
    INS_DWork.Memory_PreviousInput_f[0] = rtb_Gain1_n_idx_0;
    INS_DWork.Memory_PreviousInput_f[1] = rtb_Gain1_n_idx_1;
    INS_DWork.Memory_PreviousInput_f[2] = rtb_Gain1_n_idx_2;

    /* Switch: '<S250>/Switch' incorporates:
     *  Sum: '<S278>/Sum1'
     */
    rtb_MathFunction[0] = INS_B.Sum1[0];
    rtb_MathFunction[1] = INS_B.Sum1[1];
    rtb_MathFunction[2] = INS_B.Sum1[2];
  } else {
    INS_DWork.Rangefinder_Correct_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S250>/Rangefinder_Correct' */

  /* Outputs for Enabled SubSystem: '<S248>/ExternalPos_Correct' incorporates:
   *  EnablePort: '<S260>/Enable'
   */
  if (rtb_Compare_n1) {
    if (!INS_DWork.ExternalPos_Correct_MODE) {
      /* InitializeConditions for UnitDelay: '<S261>/Delay Input1' */
      INS_DWork.DelayInput1_DSTATE_a = INS_P.DetectChange_vinit_j;

      /* InitializeConditions for Delay: '<S262>/Delay' */
      INS_DWork.Delay_DSTATE_p[0] = INS_P.Delay_InitialCondition_ms;
      INS_DWork.Delay_DSTATE_p[1] = INS_P.Delay_InitialCondition_ms;
      INS_DWork.Delay_DSTATE_p[2] = INS_P.Delay_InitialCondition_ms;

      /* InitializeConditions for Delay: '<S264>/x_delay' */
      INS_DWork.icLoad_p = true;

      /* InitializeConditions for UnitDelay: '<S268>/Delay Input1' */
      INS_DWork.DelayInput1_DSTATE_a4 = INS_P.DetectIncrease_vinit_j;

      /* InitializeConditions for Delay: '<S266>/Delay' */
      INS_DWork.Delay_DSTATE_m = INS_P.Delay_InitialCondition_d2;
      INS_DWork.ExternalPos_Correct_MODE = true;
    }

    /* Delay: '<S264>/x_delay' */
    INS_DWork.icLoad_p = ((rtb_FixPtRelationalOperator_fr &&
      (INS_PrevZCSigState.x_delay_Reset_ZCE != POS_ZCSIG)) || INS_DWork.icLoad_p);
    INS_PrevZCSigState.x_delay_Reset_ZCE = rtb_FixPtRelationalOperator_fr;
    if (INS_DWork.icLoad_p) {
      for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 500;
           rtb_Saturation1_j_idx_1++) {
        INS_DWork.x_delay_DSTATE[rtb_Saturation1_j_idx_1] = rtb_MathFunction[0];
      }
    }

    /* RelationalOperator: '<S268>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S268>/Delay Input1'
     */
    rtb_WGS84_pos_valid = !INS_DWork.DelayInput1_DSTATE_a4;

    /* Switch: '<S266>/Switch' incorporates:
     *  Delay: '<S266>/Delay'
     *  Sum: '<S267>/Sum'
     */
    if (rtb_WGS84_pos_valid) {
      rtb_Gain2_a = rtb_MathFunction[0] - rtb_Gauss_to_uT[2];
    } else {
      rtb_Gain2_a = INS_DWork.Delay_DSTATE_m;
    }

    /* End of Switch: '<S266>/Switch' */

    /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
    /* Outputs for Atomic SubSystem: '<S3>/ExternalPos_Process' */
    /* Logic: '<S260>/Logical Operator' incorporates:
     *  Inport: '<Root>/External_Pos'
     *  RelationalOperator: '<S261>/FixPt Relational Operator'
     *  SignalConversion generated from: '<S390>/Signal Copy'
     *  UnitDelay: '<S261>/Delay Input1'
     */
    rtb_WGS84_pos_valid = (rtb_WGS84_pos_valid || (INS_U.External_Pos.timestamp
      != INS_DWork.DelayInput1_DSTATE_a));

    /* End of Outputs for SubSystem: '<S3>/ExternalPos_Process' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */

    /* Switch: '<S262>/Switch' incorporates:
     *  Delay: '<S262>/Delay'
     *  Gain: '<S263>/Gain'
     *  Gain: '<S263>/Gain1'
     *  Gain: '<S263>/Gain2'
     */
    if (rtb_WGS84_pos_valid) {
      /* Sum: '<S260>/Sum' incorporates:
       *  Delay: '<S264>/x_delay'
       *  Sum: '<S265>/Sum1'
       */
      rtb_Sum2_m = (rtb_Gauss_to_uT[2] + rtb_Gain2_a) - rtb_MathFunction[0];

      /* Saturate: '<S263>/Saturation' */
      if (rtb_Sum2_m > INS_P.Saturation_UpperSat_hz) {
        rtb_Sum2_m = INS_P.Saturation_UpperSat_hz;
      } else if (rtb_Sum2_m < INS_P.Saturation_LowerSat_n) {
        rtb_Sum2_m = INS_P.Saturation_LowerSat_n;
      }

      /* End of Saturate: '<S263>/Saturation' */
      rtb_Gain1_n_idx_0 = INS_PARAM.EXTPOS_POS_GAIN * rtb_Sum2_m;
      rtb_Gain1_n_idx_1 = -INS_PARAM.EXTPOS_VEL_GAIN * rtb_Sum2_m;
      rtb_Gain1_n_idx_2 = INS_PARAM.EXTPOS_BIAS_A_GAIN * rtb_Sum2_m;
    } else {
      rtb_Gain1_n_idx_0 = INS_DWork.Delay_DSTATE_p[0];
      rtb_Gain1_n_idx_1 = INS_DWork.Delay_DSTATE_p[1];
      rtb_Gain1_n_idx_2 = INS_DWork.Delay_DSTATE_p[2];
    }

    /* End of Switch: '<S262>/Switch' */

    /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
    /* Outputs for Atomic SubSystem: '<S3>/ExternalPos_Process' */
    /* Update for UnitDelay: '<S261>/Delay Input1' incorporates:
     *  Inport: '<Root>/External_Pos'
     *  SignalConversion generated from: '<S390>/Signal Copy'
     */
    INS_DWork.DelayInput1_DSTATE_a = INS_U.External_Pos.timestamp;

    /* End of Outputs for SubSystem: '<S3>/ExternalPos_Process' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */

    /* Sum: '<S260>/Sum1' incorporates:
     *  Gain: '<S262>/Gain'
     *  Switch: '<S250>/Switch'
     */
    INS_B.Sum1_c[0] = INS_P.Gain_Gain_ov * rtb_Gain1_n_idx_0 + rtb_MathFunction
      [0];

    /* Update for Delay: '<S262>/Delay' incorporates:
     *  Gain: '<S262>/Gain'
     */
    INS_DWork.Delay_DSTATE_p[0] = rtb_Gain1_n_idx_0;

    /* Sum: '<S260>/Sum1' incorporates:
     *  Gain: '<S262>/Gain'
     *  Switch: '<S250>/Switch'
     */
    INS_B.Sum1_c[1] = INS_P.Gain_Gain_ov * rtb_Gain1_n_idx_1 + rtb_MathFunction
      [1];

    /* Update for Delay: '<S262>/Delay' incorporates:
     *  Gain: '<S262>/Gain'
     */
    INS_DWork.Delay_DSTATE_p[1] = rtb_Gain1_n_idx_1;

    /* Sum: '<S260>/Sum1' incorporates:
     *  Gain: '<S262>/Gain'
     *  Switch: '<S250>/Switch'
     */
    INS_B.Sum1_c[2] = INS_P.Gain_Gain_ov * rtb_Gain1_n_idx_2 + rtb_MathFunction
      [2];

    /* Update for Delay: '<S262>/Delay' incorporates:
     *  Gain: '<S262>/Gain'
     */
    INS_DWork.Delay_DSTATE_p[2] = rtb_Gain1_n_idx_2;

    /* Update for Delay: '<S264>/x_delay' */
    INS_DWork.icLoad_p = false;
    for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 499;
         rtb_Saturation1_j_idx_1++) {
      INS_DWork.x_delay_DSTATE[rtb_Saturation1_j_idx_1] =
        INS_DWork.x_delay_DSTATE[rtb_Saturation1_j_idx_1 + 1];
    }

    INS_DWork.x_delay_DSTATE[499] = rtb_MathFunction[0];

    /* End of Update for Delay: '<S264>/x_delay' */

    /* Update for UnitDelay: '<S268>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_a4 = true;

    /* Update for Delay: '<S266>/Delay' */
    INS_DWork.Delay_DSTATE_m = rtb_Gain2_a;

    /* Switch: '<S248>/Switch' incorporates:
     *  Sum: '<S260>/Sum1'
     */
    rtb_MathFunction[0] = INS_B.Sum1_c[0];
    rtb_MathFunction[1] = INS_B.Sum1_c[1];
    rtb_MathFunction[2] = INS_B.Sum1_c[2];
  } else {
    INS_DWork.ExternalPos_Correct_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S248>/ExternalPos_Correct' */

  /* Outputs for Enabled SubSystem: '<S240>/GPS_Vel_Init' incorporates:
   *  EnablePort: '<S243>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S239>/GPS_Pos_Init' incorporates:
   *  EnablePort: '<S242>/Enable'
   */
  if (rtb_LogicalOperator5_i) {
    /* Outputs for Atomic SubSystem: '<S56>/TF_Data_PreProcess' */
    /* Merge: '<S239>/Merge' incorporates:
     *  DataTypeConversion: '<S242>/Data Type Conversion'
     *  Product: '<S242>/Multiply'
     *  SignalConversion generated from: '<S323>/Signal Copy3'
     *  SignalConversion generated from: '<S323>/Signal Copy4'
     *  Sum: '<S242>/Sum'
     */
    INS_B.Merge_g[0] = (real32_T)((rtb_Scalefactor1 - rtb_Switch4_c_idx_0) *
      rtb_DataTypeConversion2);
    INS_B.Merge_g[1] = (real32_T)((rtb_Scalefactor2 - rtb_Switch4_c_idx_1) *
      rtb_Switch1_idx_1);

    /* Merge: '<S240>/Merge' incorporates:
     *  Reshape: '<S243>/Reshape'
     *  SignalConversion generated from: '<S323>/Signal Copy6'
     *  SignalConversion generated from: '<S323>/Signal Copy7'
     */
    INS_B.Merge_n[0] = rtb_Gain_ok;
    INS_B.Merge_n[1] = rtb_Gain1_k;

    /* End of Outputs for SubSystem: '<S56>/TF_Data_PreProcess' */
  }

  /* End of Outputs for SubSystem: '<S239>/GPS_Pos_Init' */
  /* End of Outputs for SubSystem: '<S240>/GPS_Vel_Init' */

  /* Outputs for Enabled SubSystem: '<S239>/External_Pos_Init' incorporates:
   *  EnablePort: '<S241>/Enable'
   */
  if (rtb_Compare_fo) {
    /* Merge: '<S239>/Merge' incorporates:
     *  DataTypeConversion: '<S241>/Data Type Conversion'
     */
    INS_B.Merge_g[0] = rtb_Gauss_to_uT[0];
    INS_B.Merge_g[1] = rtb_Gauss_to_uT[1];
  }

  /* End of Outputs for SubSystem: '<S239>/External_Pos_Init' */

  /* Outputs for Enabled SubSystem: '<S240>/OptFlow_Vel_Init' incorporates:
   *  EnablePort: '<S244>/Enable'
   */
  if (rtb_Compare_o) {
    /* Merge: '<S240>/Merge' incorporates:
     *  Reshape: '<S244>/Reshape'
     */
    INS_B.Merge_n[0] = rtb_Product8[0];
    INS_B.Merge_n[1] = rtb_Product8[1];
  }

  /* End of Outputs for SubSystem: '<S240>/OptFlow_Vel_Init' */

  /* Switch: '<S236>/Switch' incorporates:
   *  Constant: '<S238>/Constant'
   *  Delay: '<S236>/Delay'
   */
  if (rtb_FixPtRelationalOperator_p) {
    rtb_Switch_dh[0] = INS_B.Merge_g[0];
    rtb_Switch_dh[2] = INS_B.Merge_n[0];
    rtb_Switch_dh[4] = INS_P.Constant_Value_bj[0];
    rtb_Switch_dh[1] = INS_B.Merge_g[1];
    rtb_Switch_dh[3] = INS_B.Merge_n[1];
    rtb_Switch_dh[5] = INS_P.Constant_Value_bj[1];
  } else {
    rtb_Switch_dh[0] = INS_DWork.Delay_DSTATE_l[0];
    rtb_Switch_dh[2] = INS_DWork.Delay_DSTATE_l[2];
    rtb_Switch_dh[4] = INS_DWork.Delay_DSTATE_l[4];
    rtb_Switch_dh[1] = INS_DWork.Delay_DSTATE_l[1];
    rtb_Switch_dh[3] = INS_DWork.Delay_DSTATE_l[3];
    rtb_Switch_dh[5] = INS_DWork.Delay_DSTATE_l[5];
  }

  /* End of Switch: '<S236>/Switch' */

  /* Product: '<S237>/Multiply' incorporates:
   *  Inport: '<Root>/IMU'
   *  Math: '<S114>/Transpose'
   *  SignalConversion generated from: '<S436>/Bus Selector1'
   *  SignalConversion generated from: '<S59>/Rotation_Data'
   * */
  for (rtb_MathFunction1_tmp = 0; rtb_MathFunction1_tmp < 3;
       rtb_MathFunction1_tmp++) {
    /* Outputs for Atomic SubSystem: '<S55>/AHRS' */
    /* Outputs for Atomic SubSystem: '<S57>/Bus_Constructor' */
    /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
    /* Outputs for Atomic SubSystem: '<S3>/IMU_PreProcess' */
    rtb_MathFunction_j[rtb_MathFunction1_tmp] =
      (rtb_VectorConcatenate_g[rtb_MathFunction1_tmp + 3] * INS_U.IMU.acc_y +
       rtb_VectorConcatenate_g[rtb_MathFunction1_tmp] * INS_U.IMU.acc_x) +
      rtb_VectorConcatenate_g[rtb_MathFunction1_tmp + 6] * INS_U.IMU.acc_z;

    /* End of Outputs for SubSystem: '<S3>/IMU_PreProcess' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */
    /* End of Outputs for SubSystem: '<S57>/Bus_Constructor' */
    /* End of Outputs for SubSystem: '<S55>/AHRS' */
  }

  /* End of Product: '<S237>/Multiply' */

  /* Gain: '<S237>/Gain' incorporates:
   *  Constant: '<S237>/Constant'
   *  Reshape: '<S237>/Reshape'
   *  Sum: '<S237>/Add'
   */
  tmp[0] = INS_P.Gain_Gain_ic * rtb_Switch_dh[2];
  tmp[2] = (rtb_MathFunction_j[0] - rtb_Switch_dh[4]) * INS_P.Gain_Gain_ic;
  tmp[4] = INS_P.Gain_Gain_ic * INS_P.Constant_Value_l[0];
  tmp[1] = INS_P.Gain_Gain_ic * rtb_Switch_dh[3];
  tmp[3] = (rtb_MathFunction_j[1] - rtb_Switch_dh[5]) * INS_P.Gain_Gain_ic;
  tmp[5] = INS_P.Gain_Gain_ic * INS_P.Constant_Value_l[1];

  /* Sum: '<S237>/Sum' incorporates:
   *  Switch: '<S236>/Switch'
   */
  for (rtb_MathFunction1_tmp = 0; rtb_MathFunction1_tmp < 6;
       rtb_MathFunction1_tmp++) {
    rtb_Sum_g0[rtb_MathFunction1_tmp] = rtb_Switch_dh[rtb_MathFunction1_tmp] +
      tmp[rtb_MathFunction1_tmp];
  }

  /* End of Sum: '<S237>/Sum' */

  /* Outputs for Enabled SubSystem: '<S210>/OptFlow_Correct' incorporates:
   *  EnablePort: '<S230>/Enable'
   */
  /* Switch: '<S210>/Switch' */
  if (rtb_Compare_o) {
    if (!INS_DWork.OptFlow_Correct_MODE) {
      /* InitializeConditions for UnitDelay: '<S231>/Delay Input1' */
      INS_DWork.DelayInput1_DSTATE_ml = INS_P.DetectChange_vinit_l;

      /* InitializeConditions for Delay: '<S234>/vn_delay' */
      INS_DWork.icLoad_h = true;

      /* InitializeConditions for Delay: '<S234>/ve_delay' */
      INS_DWork.icLoad_j = true;

      /* InitializeConditions for Memory: '<S232>/Memory' */
      for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 6;
           rtb_Saturation1_j_idx_1++) {
        INS_DWork.Memory_PreviousInput_n[rtb_Saturation1_j_idx_1] =
          INS_P.Memory_InitialCondition_i;
      }

      /* End of InitializeConditions for Memory: '<S232>/Memory' */
      INS_DWork.OptFlow_Correct_MODE = true;
    }

    /* Delay: '<S234>/vn_delay' */
    INS_DWork.icLoad_h = ((rtb_FixPtRelationalOperator_p &&
      (INS_PrevZCSigState.vn_delay_Reset_ZCE != POS_ZCSIG)) ||
                          INS_DWork.icLoad_h);
    INS_PrevZCSigState.vn_delay_Reset_ZCE = rtb_FixPtRelationalOperator_p;

    /* Delay: '<S234>/ve_delay' incorporates:
     *  Delay: '<S234>/vn_delay'
     */
    INS_DWork.icLoad_j = ((rtb_FixPtRelationalOperator_p &&
      (INS_PrevZCSigState.ve_delay_Reset_ZCE != POS_ZCSIG)) ||
                          INS_DWork.icLoad_j);
    INS_PrevZCSigState.ve_delay_Reset_ZCE = rtb_FixPtRelationalOperator_p;
    for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 500;
         rtb_Saturation1_j_idx_1++) {
      /* Delay: '<S234>/vn_delay' */
      if (INS_DWork.icLoad_h) {
        INS_DWork.vn_delay_DSTATE[rtb_Saturation1_j_idx_1] = rtb_Sum_g0[2];
      }

      /* Delay: '<S234>/ve_delay' */
      if (INS_DWork.icLoad_j) {
        INS_DWork.ve_delay_DSTATE[rtb_Saturation1_j_idx_1] = rtb_Sum_g0[3];
      }
    }

    /* Delay: '<S234>/ve_delay' */
    if (rtb_Sum_g0[2] < 1.0F) {
      rtb_Sum2_m = rtb_Sum_g0[3];
    } else {
      if (rtb_Sum_g0[2] > 500.0F) {
        rtb_MathFunction1_tmp = 500;
      } else {
        rtb_MathFunction1_tmp = (int32_T)(uint32_T)fmodf(truncf(rtb_Sum_g0[2]),
          4.2949673E+9F);
      }

      rtb_Sum2_m = INS_DWork.ve_delay_DSTATE[500U - (uint32_T)
        rtb_MathFunction1_tmp];
    }

    /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
    /* Outputs for Atomic SubSystem: '<S3>/OpticalFlow_PreProcess' */
    /* Switch: '<S232>/Switch' incorporates:
     *  Constant: '<S233>/Constant'
     *  Gain: '<S233>/Gain'
     *  Gain: '<S233>/Gain2'
     *  Inport: '<Root>/Optical_Flow'
     *  Memory: '<S232>/Memory'
     *  RelationalOperator: '<S231>/FixPt Relational Operator'
     *  Reshape: '<S233>/Reshape'
     *  SignalConversion generated from: '<S394>/OpticalFlow_Data'
     *  UnitDelay: '<S231>/Delay Input1'
     */
    if (INS_U.Optical_Flow.timestamp != INS_DWork.DelayInput1_DSTATE_ml) {
      /* Sum: '<S230>/Sum' incorporates:
       *  Delay: '<S234>/vn_delay'
       *  Gain: '<S233>/Gain'
       *  Reshape: '<S234>/Reshape'
       */
      rtb_Memory_m_idx_0 = rtb_Product8[0] - rtb_Sum_g0[2];
      rtb_Memory_m_idx_1 = rtb_Product8[1] - rtb_Sum2_m;
      rtb_Switch_dh[0] = INS_P.Constant_Value_o[0];
      rtb_Switch_dh[2] = INS_PARAM.OPF_VEL_GAIN * rtb_Memory_m_idx_0;
      rtb_Switch_dh[4] = -INS_PARAM.OPF_BIAS_A_GAIN * rtb_Memory_m_idx_0;
      rtb_Switch_dh[1] = INS_P.Constant_Value_o[1];
      rtb_Switch_dh[3] = INS_PARAM.OPF_VEL_GAIN * rtb_Memory_m_idx_1;
      rtb_Switch_dh[5] = -INS_PARAM.OPF_BIAS_A_GAIN * rtb_Memory_m_idx_1;
    } else {
      for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 6;
           rtb_Saturation1_j_idx_1++) {
        rtb_Switch_dh[rtb_Saturation1_j_idx_1] =
          INS_DWork.Memory_PreviousInput_n[rtb_Saturation1_j_idx_1];
      }
    }

    /* End of Switch: '<S232>/Switch' */
    /* End of Outputs for SubSystem: '<S3>/OpticalFlow_PreProcess' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */
    for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 6;
         rtb_Saturation1_j_idx_1++) {
      /* Sum: '<S230>/Sum1' incorporates:
       *  Gain: '<S232>/Gain3'
       *  Sum: '<S237>/Sum'
       *  Switch: '<S232>/Switch'
       */
      INS_B.Sum1_f[rtb_Saturation1_j_idx_1] = INS_P.Gain3_Gain_p *
        rtb_Switch_dh[rtb_Saturation1_j_idx_1] +
        rtb_Sum_g0[rtb_Saturation1_j_idx_1];
    }

    /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
    /* Outputs for Atomic SubSystem: '<S3>/OpticalFlow_PreProcess' */
    /* Update for UnitDelay: '<S231>/Delay Input1' incorporates:
     *  Inport: '<Root>/Optical_Flow'
     *  SignalConversion generated from: '<S394>/OpticalFlow_Data'
     */
    INS_DWork.DelayInput1_DSTATE_ml = INS_U.Optical_Flow.timestamp;

    /* End of Outputs for SubSystem: '<S3>/OpticalFlow_PreProcess' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */

    /* Update for Delay: '<S234>/vn_delay' */
    INS_DWork.icLoad_h = false;

    /* Update for Delay: '<S234>/ve_delay' */
    INS_DWork.icLoad_j = false;
    for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 499;
         rtb_Saturation1_j_idx_1++) {
      /* Update for Delay: '<S234>/vn_delay' */
      INS_DWork.vn_delay_DSTATE[rtb_Saturation1_j_idx_1] =
        INS_DWork.vn_delay_DSTATE[rtb_Saturation1_j_idx_1 + 1];

      /* Update for Delay: '<S234>/ve_delay' */
      INS_DWork.ve_delay_DSTATE[rtb_Saturation1_j_idx_1] =
        INS_DWork.ve_delay_DSTATE[rtb_Saturation1_j_idx_1 + 1];
    }

    /* Update for Delay: '<S234>/vn_delay' */
    INS_DWork.vn_delay_DSTATE[499] = rtb_Sum_g0[2];

    /* Update for Delay: '<S234>/ve_delay' */
    INS_DWork.ve_delay_DSTATE[499] = rtb_Sum_g0[3];

    /* Update for Memory: '<S232>/Memory' incorporates:
     *  Sum: '<S230>/Sum1'
     *  Switch: '<S210>/Switch'
     *  Switch: '<S232>/Switch'
     */
    for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 6;
         rtb_Saturation1_j_idx_1++) {
      INS_DWork.Memory_PreviousInput_n[rtb_Saturation1_j_idx_1] =
        rtb_Switch_dh[rtb_Saturation1_j_idx_1];
      rtb_Sum_g0[rtb_Saturation1_j_idx_1] = INS_B.Sum1_f[rtb_Saturation1_j_idx_1];
    }

    /* End of Update for Memory: '<S232>/Memory' */
  } else {
    INS_DWork.OptFlow_Correct_MODE = false;
  }

  /* End of Switch: '<S210>/Switch' */
  /* End of Outputs for SubSystem: '<S210>/OptFlow_Correct' */

  /* Outputs for Enabled SubSystem: '<S209>/GPS_Correct' incorporates:
   *  EnablePort: '<S220>/Enable'
   */
  /* Switch: '<S209>/Switch' */
  if (rtb_LogicalOperator5_i) {
    if (!INS_DWork.GPS_Correct_MODE_o) {
      /* InitializeConditions for UnitDelay: '<S221>/Delay Input1' */
      INS_DWork.DelayInput1_DSTATE_d0 = INS_P.DetectChange_vinit_i;

      /* InitializeConditions for Delay: '<S224>/x_delay' */
      INS_DWork.icLoad_op = true;

      /* InitializeConditions for Delay: '<S224>/x_delay1' */
      INS_DWork.icLoad_i = true;

      /* InitializeConditions for Delay: '<S224>/vn_delay' */
      INS_DWork.icLoad_m = true;

      /* InitializeConditions for Delay: '<S224>/vn_delay1' */
      INS_DWork.icLoad_jp = true;

      /* InitializeConditions for UnitDelay: '<S229>/Delay Input1' */
      INS_DWork.DelayInput1_DSTATE_gn = INS_P.DetectIncrease_vinit_p;

      /* InitializeConditions for Memory: '<S227>/Memory' */
      INS_DWork.Memory_PreviousInput_d[0] = INS_P.Memory_InitialCondition_l[0];
      INS_DWork.Memory_PreviousInput_d[1] = INS_P.Memory_InitialCondition_l[1];

      /* InitializeConditions for Memory: '<S222>/Memory' */
      for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 6;
           rtb_Saturation1_j_idx_1++) {
        INS_DWork.Memory_PreviousInput_h[rtb_Saturation1_j_idx_1] =
          INS_P.Memory_InitialCondition_o;
      }

      /* End of InitializeConditions for Memory: '<S222>/Memory' */
      INS_DWork.GPS_Correct_MODE_o = true;
    }

    /* Delay: '<S224>/x_delay' */
    INS_DWork.icLoad_op = ((rtb_FixPtRelationalOperator_p &&
      (INS_PrevZCSigState.x_delay_Reset_ZCE_b != POS_ZCSIG)) ||
      INS_DWork.icLoad_op);
    INS_PrevZCSigState.x_delay_Reset_ZCE_b = rtb_FixPtRelationalOperator_p;
    if (INS_DWork.icLoad_op) {
      for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 500;
           rtb_Saturation1_j_idx_1++) {
        INS_DWork.x_delay_DSTATE_k[rtb_Saturation1_j_idx_1] = rtb_Sum_g0[0];
      }
    }

    /* Delay: '<S224>/x_delay1' incorporates:
     *  Delay: '<S224>/x_delay'
     */
    INS_DWork.icLoad_i = ((rtb_FixPtRelationalOperator_p &&
      (INS_PrevZCSigState.x_delay1_Reset_ZCE != POS_ZCSIG)) ||
                          INS_DWork.icLoad_i);
    INS_PrevZCSigState.x_delay1_Reset_ZCE = rtb_FixPtRelationalOperator_p;
    if (INS_DWork.icLoad_i) {
      for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 100;
           rtb_Saturation1_j_idx_1++) {
        INS_DWork.x_delay1_DSTATE[rtb_Saturation1_j_idx_1] = rtb_Sum_g0[1];
      }
    }

    /* Delay: '<S224>/vn_delay' incorporates:
     *  Delay: '<S224>/x_delay'
     */
    INS_DWork.icLoad_m = ((rtb_FixPtRelationalOperator_p &&
      (INS_PrevZCSigState.vn_delay_Reset_ZCE_p != POS_ZCSIG)) ||
                          INS_DWork.icLoad_m);
    INS_PrevZCSigState.vn_delay_Reset_ZCE_p = rtb_FixPtRelationalOperator_p;

    /* Delay: '<S224>/vn_delay1' incorporates:
     *  Delay: '<S224>/x_delay'
     */
    INS_DWork.icLoad_jp = ((rtb_FixPtRelationalOperator_p &&
      (INS_PrevZCSigState.vn_delay1_Reset_ZCE != POS_ZCSIG)) ||
      INS_DWork.icLoad_jp);
    INS_PrevZCSigState.vn_delay1_Reset_ZCE = rtb_FixPtRelationalOperator_p;
    for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 500;
         rtb_Saturation1_j_idx_1++) {
      /* Delay: '<S224>/vn_delay' */
      if (INS_DWork.icLoad_m) {
        INS_DWork.vn_delay_DSTATE_n[rtb_Saturation1_j_idx_1] = rtb_Sum_g0[2];
      }

      /* Delay: '<S224>/vn_delay1' */
      if (INS_DWork.icLoad_jp) {
        INS_DWork.vn_delay1_DSTATE[rtb_Saturation1_j_idx_1] = rtb_Sum_g0[3];
      }
    }

    /* Outputs for Atomic SubSystem: '<S56>/TF_Data_PreProcess' */
    /* DataTypeConversion: '<S225>/Data Type Conversion' incorporates:
     *  Product: '<S225>/Multiply'
     *  SignalConversion generated from: '<S323>/Signal Copy3'
     *  SignalConversion generated from: '<S323>/Signal Copy4'
     *  Sum: '<S225>/Sum'
     */
    rtb_DataTypeConversion_l_idx_0 = (real32_T)((rtb_Scalefactor1 -
      rtb_Switch4_c_idx_0) * rtb_DataTypeConversion2);
    rtb_Sum2_m = (real32_T)((rtb_Scalefactor2 - rtb_Switch4_c_idx_1) *
      rtb_Switch1_idx_1);

    /* End of Outputs for SubSystem: '<S56>/TF_Data_PreProcess' */

    /* RelationalOperator: '<S229>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S229>/Delay Input1'
     */
    rtb_WGS84_pos_valid = !INS_DWork.DelayInput1_DSTATE_gn;

    /* Switch: '<S227>/Switch' incorporates:
     *  Memory: '<S227>/Memory'
     *  Sum: '<S228>/Sum'
     */
    if (rtb_WGS84_pos_valid) {
      rtb_Memory_m_idx_0 = rtb_Sum_g0[0] - rtb_DataTypeConversion_l_idx_0;
      rtb_Memory_m_idx_1 = rtb_Sum_g0[1] - rtb_Sum2_m;
    } else {
      rtb_Memory_m_idx_0 = INS_DWork.Memory_PreviousInput_d[0];
      rtb_Memory_m_idx_1 = INS_DWork.Memory_PreviousInput_d[1];
    }

    /* End of Switch: '<S227>/Switch' */

    /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
    /* Outputs for Atomic SubSystem: '<S3>/GPS_PreProcess' */
    /* Switch: '<S222>/Switch' incorporates:
     *  Gain: '<S223>/Gain'
     *  Gain: '<S223>/Gain1'
     *  Gain: '<S223>/Gain2'
     *  Gain: '<S223>/Gain3'
     *  Inport: '<Root>/GPS_uBlox'
     *  Logic: '<S220>/Logical Operator'
     *  Memory: '<S222>/Memory'
     *  RelationalOperator: '<S221>/FixPt Relational Operator'
     *  Reshape: '<S223>/Reshape'
     *  SignalConversion generated from: '<S391>/GPS_Data'
     *  Sum: '<S223>/Sum'
     *  UnitDelay: '<S221>/Delay Input1'
     */
    if (rtb_WGS84_pos_valid || (INS_U.GPS_uBlox.timestamp !=
         INS_DWork.DelayInput1_DSTATE_d0)) {
      /* Outputs for Atomic SubSystem: '<S56>/TF_Data_PreProcess' */
      /* Sum: '<S220>/Sum' incorporates:
       *  Delay: '<S224>/vn_delay'
       *  Delay: '<S224>/vn_delay1'
       *  SignalConversion generated from: '<S323>/Signal Copy6'
       *  SignalConversion generated from: '<S323>/Signal Copy7'
       */
      rtb_DiscreteTimeIntegrator_eh = rtb_Gain_ok - rtb_Sum_g0[2];
      rtb_Gain_ok = rtb_Gain1_k - rtb_Sum_g0[3];

      /* End of Outputs for SubSystem: '<S56>/TF_Data_PreProcess' */

      /* Gain: '<S223>/Gain3' incorporates:
       *  Delay: '<S224>/x_delay'
       *  Sum: '<S220>/Sum'
       *  Sum: '<S226>/Sum1'
       *  Switch: '<S227>/Switch'
       */
      rtb_DiscreteTimeIntegrator1_p_i = ((rtb_DataTypeConversion_l_idx_0 +
        rtb_Memory_m_idx_0) - rtb_Sum_g0[0]) * INS_PARAM.GPS_POS_GAIN;
      rtb_Switch_dh[0] = rtb_DiscreteTimeIntegrator1_p_i;
      rtb_Switch_dh[2] = INS_P.Gain1_Gain_j * rtb_DiscreteTimeIntegrator1_p_i +
        INS_PARAM.GPS_VEL_GAIN * rtb_DiscreteTimeIntegrator_eh;
      rtb_Switch_dh[4] = -INS_PARAM.GPS_BIAS_A_GAIN *
        rtb_DiscreteTimeIntegrator_eh;

      /* Gain: '<S223>/Gain3' incorporates:
       *  Delay: '<S224>/x_delay1'
       *  Gain: '<S223>/Gain'
       *  Gain: '<S223>/Gain1'
       *  Gain: '<S223>/Gain2'
       *  Reshape: '<S223>/Reshape'
       *  Sum: '<S220>/Sum'
       *  Sum: '<S223>/Sum'
       *  Sum: '<S226>/Sum1'
       *  Switch: '<S222>/Switch'
       *  Switch: '<S227>/Switch'
       */
      rtb_DiscreteTimeIntegrator1_p_i = ((rtb_Sum2_m + rtb_Memory_m_idx_1) -
        rtb_Sum_g0[1]) * INS_PARAM.GPS_POS_GAIN;
      rtb_Switch_dh[1] = rtb_DiscreteTimeIntegrator1_p_i;
      rtb_Switch_dh[3] = INS_P.Gain1_Gain_j * rtb_DiscreteTimeIntegrator1_p_i +
        INS_PARAM.GPS_VEL_GAIN * rtb_Gain_ok;
      rtb_Switch_dh[5] = -INS_PARAM.GPS_BIAS_A_GAIN * rtb_Gain_ok;
    } else {
      for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 6;
           rtb_Saturation1_j_idx_1++) {
        rtb_Switch_dh[rtb_Saturation1_j_idx_1] =
          INS_DWork.Memory_PreviousInput_h[rtb_Saturation1_j_idx_1];
      }
    }

    /* End of Switch: '<S222>/Switch' */
    /* End of Outputs for SubSystem: '<S3>/GPS_PreProcess' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */
    for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 6;
         rtb_Saturation1_j_idx_1++) {
      /* Sum: '<S220>/Sum1' incorporates:
       *  Gain: '<S222>/Gain3'
       *  Switch: '<S210>/Switch'
       *  Switch: '<S222>/Switch'
       */
      INS_B.Sum1_o[rtb_Saturation1_j_idx_1] = INS_P.Gain3_Gain_o *
        rtb_Switch_dh[rtb_Saturation1_j_idx_1] +
        rtb_Sum_g0[rtb_Saturation1_j_idx_1];
    }

    /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
    /* Outputs for Atomic SubSystem: '<S3>/GPS_PreProcess' */
    /* Update for UnitDelay: '<S221>/Delay Input1' incorporates:
     *  Inport: '<Root>/GPS_uBlox'
     *  SignalConversion generated from: '<S391>/GPS_Data'
     */
    INS_DWork.DelayInput1_DSTATE_d0 = INS_U.GPS_uBlox.timestamp;

    /* End of Outputs for SubSystem: '<S3>/GPS_PreProcess' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */

    /* Update for Delay: '<S224>/x_delay' */
    INS_DWork.icLoad_op = false;
    for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 499;
         rtb_Saturation1_j_idx_1++) {
      INS_DWork.x_delay_DSTATE_k[rtb_Saturation1_j_idx_1] =
        INS_DWork.x_delay_DSTATE_k[rtb_Saturation1_j_idx_1 + 1];
    }

    INS_DWork.x_delay_DSTATE_k[499] = rtb_Sum_g0[0];

    /* End of Update for Delay: '<S224>/x_delay' */

    /* Update for Delay: '<S224>/x_delay1' */
    INS_DWork.icLoad_i = false;
    for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 99;
         rtb_Saturation1_j_idx_1++) {
      INS_DWork.x_delay1_DSTATE[rtb_Saturation1_j_idx_1] =
        INS_DWork.x_delay1_DSTATE[rtb_Saturation1_j_idx_1 + 1];
    }

    INS_DWork.x_delay1_DSTATE[99] = rtb_Sum_g0[1];

    /* End of Update for Delay: '<S224>/x_delay1' */

    /* Update for Delay: '<S224>/vn_delay' */
    INS_DWork.icLoad_m = false;

    /* Update for Delay: '<S224>/vn_delay1' */
    INS_DWork.icLoad_jp = false;
    for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 499;
         rtb_Saturation1_j_idx_1++) {
      /* Update for Delay: '<S224>/vn_delay' */
      INS_DWork.vn_delay_DSTATE_n[rtb_Saturation1_j_idx_1] =
        INS_DWork.vn_delay_DSTATE_n[rtb_Saturation1_j_idx_1 + 1];

      /* Update for Delay: '<S224>/vn_delay1' */
      INS_DWork.vn_delay1_DSTATE[rtb_Saturation1_j_idx_1] =
        INS_DWork.vn_delay1_DSTATE[rtb_Saturation1_j_idx_1 + 1];
    }

    /* Update for Delay: '<S224>/vn_delay' */
    INS_DWork.vn_delay_DSTATE_n[499] = rtb_Sum_g0[2];

    /* Update for Delay: '<S224>/vn_delay1' */
    INS_DWork.vn_delay1_DSTATE[499] = rtb_Sum_g0[3];

    /* Update for UnitDelay: '<S229>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_gn = true;

    /* Update for Memory: '<S227>/Memory' incorporates:
     *  Switch: '<S227>/Switch'
     */
    INS_DWork.Memory_PreviousInput_d[0] = rtb_Memory_m_idx_0;
    INS_DWork.Memory_PreviousInput_d[1] = rtb_Memory_m_idx_1;

    /* Update for Memory: '<S222>/Memory' incorporates:
     *  Sum: '<S220>/Sum1'
     *  Switch: '<S209>/Switch'
     *  Switch: '<S222>/Switch'
     */
    for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 6;
         rtb_Saturation1_j_idx_1++) {
      INS_DWork.Memory_PreviousInput_h[rtb_Saturation1_j_idx_1] =
        rtb_Switch_dh[rtb_Saturation1_j_idx_1];
      rtb_Sum_g0[rtb_Saturation1_j_idx_1] = INS_B.Sum1_o[rtb_Saturation1_j_idx_1];
    }

    /* End of Update for Memory: '<S222>/Memory' */
  } else {
    INS_DWork.GPS_Correct_MODE_o = false;
  }

  /* End of Switch: '<S209>/Switch' */
  /* End of Outputs for SubSystem: '<S209>/GPS_Correct' */

  /* Outputs for Enabled SubSystem: '<S208>/ExternalPos_Correct' incorporates:
   *  EnablePort: '<S211>/Enable'
   */
  /* Switch: '<S208>/Switch' */
  if (rtb_Compare_fo) {
    if (!INS_DWork.ExternalPos_Correct_MODE_k) {
      /* InitializeConditions for UnitDelay: '<S212>/Delay Input1' */
      INS_DWork.DelayInput1_DSTATE_no = INS_P.DetectChange_vinit;

      /* InitializeConditions for Delay: '<S215>/x_delay' */
      INS_DWork.icLoad_hw = true;

      /* InitializeConditions for Delay: '<S215>/y_delay' */
      INS_DWork.icLoad_od = true;

      /* InitializeConditions for UnitDelay: '<S219>/Delay Input1' */
      INS_DWork.DelayInput1_DSTATE_dp5 = INS_P.DetectIncrease_vinit_m;

      /* InitializeConditions for Delay: '<S217>/Delay' */
      INS_DWork.Delay_DSTATE_k[0] = INS_P.Delay_InitialCondition_e;
      INS_DWork.Delay_DSTATE_k[1] = INS_P.Delay_InitialCondition_e;

      /* InitializeConditions for Memory: '<S213>/Memory' */
      for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 6;
           rtb_Saturation1_j_idx_1++) {
        INS_DWork.Memory_PreviousInput_m[rtb_Saturation1_j_idx_1] =
          INS_P.Memory_InitialCondition;
      }

      /* End of InitializeConditions for Memory: '<S213>/Memory' */
      INS_DWork.ExternalPos_Correct_MODE_k = true;
    }

    /* Delay: '<S215>/x_delay' */
    INS_DWork.icLoad_hw = ((rtb_FixPtRelationalOperator_p &&
      (INS_PrevZCSigState.x_delay_Reset_ZCE_lr != POS_ZCSIG)) ||
      INS_DWork.icLoad_hw);
    INS_PrevZCSigState.x_delay_Reset_ZCE_lr = rtb_FixPtRelationalOperator_p;

    /* Delay: '<S215>/y_delay' incorporates:
     *  Delay: '<S215>/x_delay'
     */
    INS_DWork.icLoad_od = ((rtb_FixPtRelationalOperator_p &&
      (INS_PrevZCSigState.y_delay_Reset_ZCE != POS_ZCSIG)) ||
      INS_DWork.icLoad_od);
    INS_PrevZCSigState.y_delay_Reset_ZCE = rtb_FixPtRelationalOperator_p;
    for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 500;
         rtb_Saturation1_j_idx_1++) {
      /* Delay: '<S215>/x_delay' */
      if (INS_DWork.icLoad_hw) {
        INS_DWork.x_delay_DSTATE_l[rtb_Saturation1_j_idx_1] = rtb_Sum_g0[0];
      }

      /* Delay: '<S215>/y_delay' */
      if (INS_DWork.icLoad_od) {
        INS_DWork.y_delay_DSTATE[rtb_Saturation1_j_idx_1] = rtb_Sum_g0[1];
      }
    }

    /* RelationalOperator: '<S219>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S219>/Delay Input1'
     */
    rtb_WGS84_pos_valid = !INS_DWork.DelayInput1_DSTATE_dp5;

    /* Switch: '<S217>/Switch' incorporates:
     *  Delay: '<S217>/Delay'
     *  Sum: '<S218>/Sum'
     */
    if (rtb_WGS84_pos_valid) {
      rtb_Memory_m_idx_0 = rtb_Sum_g0[0] - rtb_Gauss_to_uT[0];
      rtb_Memory_m_idx_1 = rtb_Sum_g0[1] - rtb_Gauss_to_uT[1];
    } else {
      rtb_Memory_m_idx_0 = INS_DWork.Delay_DSTATE_k[0];
      rtb_Memory_m_idx_1 = INS_DWork.Delay_DSTATE_k[1];
    }

    /* End of Switch: '<S217>/Switch' */

    /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
    /* Outputs for Atomic SubSystem: '<S3>/ExternalPos_Process' */
    /* Switch: '<S213>/Switch' incorporates:
     *  Gain: '<S214>/Gain'
     *  Gain: '<S214>/Gain2'
     *  Gain: '<S214>/Gain3'
     *  Inport: '<Root>/External_Pos'
     *  Logic: '<S211>/Logical Operator'
     *  Memory: '<S213>/Memory'
     *  RelationalOperator: '<S212>/FixPt Relational Operator'
     *  SignalConversion generated from: '<S390>/Signal Copy'
     *  UnitDelay: '<S212>/Delay Input1'
     */
    if (rtb_WGS84_pos_valid || (INS_U.External_Pos.timestamp !=
         INS_DWork.DelayInput1_DSTATE_no)) {
      /* Sum: '<S211>/Sum' incorporates:
       *  Delay: '<S215>/x_delay'
       *  Delay: '<S215>/y_delay'
       *  Gain: '<S214>/Gain3'
       *  Sum: '<S216>/Sum1'
       *  Switch: '<S217>/Switch'
       */
      rtb_DataTypeConversion_l_idx_0 = (rtb_Gauss_to_uT[0] + rtb_Memory_m_idx_0)
        - rtb_Sum_g0[0];
      rtb_Sum2_m = (rtb_Gauss_to_uT[1] + rtb_Memory_m_idx_1) - rtb_Sum_g0[1];
      rtb_Switch_dh[0] = INS_PARAM.EXTPOS_POS_GAIN *
        rtb_DataTypeConversion_l_idx_0;
      rtb_Switch_dh[2] = INS_PARAM.EXTPOS_VEL_GAIN *
        rtb_DataTypeConversion_l_idx_0;
      rtb_Switch_dh[4] = -INS_PARAM.EXTPOS_BIAS_A_GAIN *
        rtb_DataTypeConversion_l_idx_0;
      rtb_Switch_dh[1] = INS_PARAM.EXTPOS_POS_GAIN * rtb_Sum2_m;
      rtb_Switch_dh[3] = INS_PARAM.EXTPOS_VEL_GAIN * rtb_Sum2_m;
      rtb_Switch_dh[5] = -INS_PARAM.EXTPOS_BIAS_A_GAIN * rtb_Sum2_m;
    } else {
      for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 6;
           rtb_Saturation1_j_idx_1++) {
        rtb_Switch_dh[rtb_Saturation1_j_idx_1] =
          INS_DWork.Memory_PreviousInput_m[rtb_Saturation1_j_idx_1];
      }
    }

    /* End of Switch: '<S213>/Switch' */
    /* End of Outputs for SubSystem: '<S3>/ExternalPos_Process' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */
    for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 6;
         rtb_Saturation1_j_idx_1++) {
      /* Sum: '<S211>/Sum1' incorporates:
       *  Gain: '<S213>/Gain3'
       *  Switch: '<S209>/Switch'
       *  Switch: '<S213>/Switch'
       */
      INS_B.Sum1_b[rtb_Saturation1_j_idx_1] = INS_P.Gain3_Gain_ev *
        rtb_Switch_dh[rtb_Saturation1_j_idx_1] +
        rtb_Sum_g0[rtb_Saturation1_j_idx_1];
    }

    /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
    /* Outputs for Atomic SubSystem: '<S3>/ExternalPos_Process' */
    /* Update for UnitDelay: '<S212>/Delay Input1' incorporates:
     *  Inport: '<Root>/External_Pos'
     *  SignalConversion generated from: '<S390>/Signal Copy'
     */
    INS_DWork.DelayInput1_DSTATE_no = INS_U.External_Pos.timestamp;

    /* End of Outputs for SubSystem: '<S3>/ExternalPos_Process' */
    /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */

    /* Update for Delay: '<S215>/x_delay' */
    INS_DWork.icLoad_hw = false;

    /* Update for Delay: '<S215>/y_delay' */
    INS_DWork.icLoad_od = false;
    for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 499;
         rtb_Saturation1_j_idx_1++) {
      /* Update for Delay: '<S215>/x_delay' */
      INS_DWork.x_delay_DSTATE_l[rtb_Saturation1_j_idx_1] =
        INS_DWork.x_delay_DSTATE_l[rtb_Saturation1_j_idx_1 + 1];

      /* Update for Delay: '<S215>/y_delay' */
      INS_DWork.y_delay_DSTATE[rtb_Saturation1_j_idx_1] =
        INS_DWork.y_delay_DSTATE[rtb_Saturation1_j_idx_1 + 1];
    }

    /* Update for Delay: '<S215>/x_delay' */
    INS_DWork.x_delay_DSTATE_l[499] = rtb_Sum_g0[0];

    /* Update for Delay: '<S215>/y_delay' */
    INS_DWork.y_delay_DSTATE[499] = rtb_Sum_g0[1];

    /* Update for UnitDelay: '<S219>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_dp5 = true;

    /* Update for Delay: '<S217>/Delay' incorporates:
     *  Switch: '<S217>/Switch'
     */
    INS_DWork.Delay_DSTATE_k[0] = rtb_Memory_m_idx_0;
    INS_DWork.Delay_DSTATE_k[1] = rtb_Memory_m_idx_1;

    /* Update for Memory: '<S213>/Memory' incorporates:
     *  Sum: '<S211>/Sum1'
     *  Switch: '<S208>/Switch'
     *  Switch: '<S213>/Switch'
     */
    for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 6;
         rtb_Saturation1_j_idx_1++) {
      INS_DWork.Memory_PreviousInput_m[rtb_Saturation1_j_idx_1] =
        rtb_Switch_dh[rtb_Saturation1_j_idx_1];
      rtb_Sum_g0[rtb_Saturation1_j_idx_1] = INS_B.Sum1_b[rtb_Saturation1_j_idx_1];
    }

    /* End of Update for Memory: '<S213>/Memory' */
  } else {
    INS_DWork.ExternalPos_Correct_MODE_k = false;
  }

  /* End of Switch: '<S208>/Switch' */
  /* End of Outputs for SubSystem: '<S208>/ExternalPos_Correct' */

  /* Signum: '<S205>/Sign' */
  if (rtb_DataTypeConversion2 < 0.0) {
    rtb_Saturation1_j_idx_1 = -1;
  } else {
    rtb_Saturation1_j_idx_1 = (rtb_DataTypeConversion2 > 0.0);
  }

  /* Abs: '<S205>/Abs' incorporates:
   *  Signum: '<S205>/Sign'
   */
  rtb_Scalefactor1 = fabs(rtb_DataTypeConversion2);

  /* Saturate: '<S205>/Saturation' */
  if (rtb_Scalefactor1 > INS_P.Saturation_UpperSat) {
    rtb_Scalefactor1 = INS_P.Saturation_UpperSat;
  } else if (rtb_Scalefactor1 < INS_P.Saturation_LowerSat) {
    rtb_Scalefactor1 = INS_P.Saturation_LowerSat;
  }

  /* Switch: '<S205>/Switch' incorporates:
   *  Constant: '<S205>/Constant'
   */
  if (rtb_Saturation1_j_idx_1 != 0) {
    rtb_DataTypeConversion1 = rtb_Saturation1_j_idx_1;
  } else {
    rtb_DataTypeConversion1 = INS_P.Constant_Value;
  }

  /* Outputs for Atomic SubSystem: '<S56>/TF_Data_PreProcess' */
  /* BusCreator generated from: '<Root>/INS_Out' incorporates:
   *  DataTypeConversion: '<S202>/Data Type Conversion2'
   *  DataTypeConversion: '<S203>/Data Type Conversion'
   *  Outport: '<Root>/INS_Out'
   *  Product: '<S202>/Multiply'
   *  Product: '<S204>/Divide'
   *  Product: '<S205>/Product'
   *  Saturate: '<S205>/Saturation'
   *  SignalConversion generated from: '<S338>/Signal Copy'
   *  Sum: '<S203>/Sum'
   *  Switch: '<S205>/Switch'
   */
  INS_Y.INS_Out.lat = (rtb_Sum_g0[0] / (rtb_Scalefactor1 *
    rtb_DataTypeConversion1) + rtb_Switch4_c_idx_0) * (real_T)rtb_Compare_cio;

  /* End of Outputs for SubSystem: '<S56>/TF_Data_PreProcess' */

  /* Signum: '<S205>/Sign' */
  if (rtb_Switch1_idx_1 < 0.0) {
    rtb_Saturation1_j_idx_1 = -1;
  } else {
    rtb_Saturation1_j_idx_1 = (rtb_Switch1_idx_1 > 0.0);
  }

  /* Abs: '<S205>/Abs' incorporates:
   *  Signum: '<S205>/Sign'
   */
  rtb_Scalefactor1 = fabs(rtb_Switch1_idx_1);

  /* Saturate: '<S205>/Saturation' */
  if (rtb_Scalefactor1 > INS_P.Saturation_UpperSat) {
    rtb_Scalefactor1 = INS_P.Saturation_UpperSat;
  } else if (rtb_Scalefactor1 < INS_P.Saturation_LowerSat) {
    rtb_Scalefactor1 = INS_P.Saturation_LowerSat;
  }

  /* Switch: '<S205>/Switch' incorporates:
   *  Constant: '<S205>/Constant'
   */
  if (rtb_Saturation1_j_idx_1 != 0) {
    rtb_DataTypeConversion1 = rtb_Saturation1_j_idx_1;
  } else {
    rtb_DataTypeConversion1 = INS_P.Constant_Value;
  }

  /* Outputs for Atomic SubSystem: '<S56>/TF_Data_PreProcess' */
  /* BusCreator generated from: '<Root>/INS_Out' incorporates:
   *  DataTypeConversion: '<S202>/Data Type Conversion2'
   *  DataTypeConversion: '<S203>/Data Type Conversion'
   *  DataTypeConversion: '<S203>/Data Type Conversion1'
   *  Outport: '<Root>/INS_Out'
   *  Product: '<S202>/Multiply'
   *  Product: '<S204>/Divide'
   *  Product: '<S205>/Product'
   *  Saturate: '<S205>/Saturation'
   *  SignalConversion generated from: '<S338>/Signal Copy'
   *  Sum: '<S203>/Sum'
   *  Switch: '<S205>/Switch'
   */
  INS_Y.INS_Out.lon = (rtb_Sum_g0[1] / (rtb_Scalefactor1 *
    rtb_DataTypeConversion1) + rtb_Switch4_c_idx_1) * (real_T)rtb_Compare_cio;
  INS_Y.INS_Out.alt = (rtb_MathFunction[0] + rtb_ff) * (real_T)rtb_Compare_cio;

  /* End of Outputs for SubSystem: '<S56>/TF_Data_PreProcess' */
  /* End of Outputs for SubSystem: '<S56>/CF' */

  /* Update for Delay generated from: '<S56>/Delay' */
  INS_DWork.Delay_4_DSTATE_k = rtb_Sum_g0[0];

  /* Update for Delay generated from: '<S56>/Delay' */
  INS_DWork.Delay_5_DSTATE = rtb_Sum_g0[1];

  /* Update for Delay generated from: '<S56>/Delay' */
  INS_DWork.Delay_6_DSTATE = rtb_MathFunction[0];

  /* Update for Atomic SubSystem: '<S56>/CF' */
  /* Update for Delay: '<S290>/Delay' incorporates:
   *  Switch: '<S248>/Switch'
   */
  INS_DWork.Delay_DSTATE_b[0] = rtb_MathFunction[0];
  INS_DWork.Delay_DSTATE_b[1] = rtb_MathFunction[1];
  INS_DWork.Delay_DSTATE_b[2] = rtb_MathFunction[2];

  /* Update for Delay: '<S236>/Delay' incorporates:
   *  Switch: '<S208>/Switch'
   */
  for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 6;
       rtb_Saturation1_j_idx_1++) {
    INS_DWork.Delay_DSTATE_l[rtb_Saturation1_j_idx_1] =
      rtb_Sum_g0[rtb_Saturation1_j_idx_1];
  }

  /* End of Update for Delay: '<S236>/Delay' */
  /* End of Update for SubSystem: '<S56>/CF' */
  /* End of Outputs for SubSystem: '<Root>/Data_Fusion' */

  /* Outputs for Atomic SubSystem: '<Root>/Bus_Constructor' */
  /* Outputs for Atomic SubSystem: '<S1>/Counter' */
  /* BusCreator generated from: '<Root>/INS_Out' incorporates:
   *  Outport: '<Root>/INS_Out'
   *  UnitDelay: '<S4>/Output'
   */
  INS_Y.INS_Out.timestamp = INS_DWork.Output_DSTATE;

  /* Update for UnitDelay: '<S4>/Output' incorporates:
   *  Constant: '<S4>/Constant'
   *  Sum: '<S4>/Add'
   */
  INS_DWork.Output_DSTATE += INS_EXPORT.period;

  /* End of Outputs for SubSystem: '<S1>/Counter' */

  /* Outputs for Atomic SubSystem: '<S1>/Rotation_Output' */
  /* Product: '<S5>/Multiply' incorporates:
   *  SignalConversion generated from: '<S5>/Multiply'
   */
  rtb_Gain_ok = rtb_Sum_g0[4];
  rtb_Gain1_k = rtb_Sum_g0[5];
  rtb_Sum2_m = rtb_MathFunction[2];

  /* Sum: '<S5>/Sum' incorporates:
   *  Concatenate: '<S436>/Vector Concatenate1'
   *  Math: '<S59>/Math Function'
   *  Product: '<S5>/Multiply'
   *  SignalConversion generated from: '<S59>/Signal Conversion'
   */
  for (rtb_MathFunction1_tmp = 0; rtb_MathFunction1_tmp < 3;
       rtb_MathFunction1_tmp++) {
    /* Outputs for Atomic SubSystem: '<Root>/Data_Fusion' */
    /* Outputs for Atomic SubSystem: '<S55>/AHRS' */
    /* Outputs for Atomic SubSystem: '<S57>/Bus_Constructor' */
    rtb_Gauss_to_uT[rtb_MathFunction1_tmp] =
      rtb_VectorConcatenate1[rtb_MathFunction1_tmp] -
      ((rtb_M_BO_c[rtb_MathFunction1_tmp + 3] * rtb_Gain1_k +
        rtb_M_BO_c[rtb_MathFunction1_tmp] * rtb_Gain_ok) +
       rtb_M_BO_c[rtb_MathFunction1_tmp + 6] * rtb_Sum2_m);

    /* End of Outputs for SubSystem: '<S57>/Bus_Constructor' */
    /* End of Outputs for SubSystem: '<S55>/AHRS' */
    /* End of Outputs for SubSystem: '<Root>/Data_Fusion' */
  }

  /* End of Sum: '<S5>/Sum' */
  /* End of Outputs for SubSystem: '<S1>/Rotation_Output' */

  /* Outputs for Atomic SubSystem: '<S1>/Status_Output' */
  /* Outputs for Atomic SubSystem: '<Root>/Data_Fusion' */
  /* Outputs for Atomic SubSystem: '<S56>/CF' */
  /* RelationalOperator: '<S24>/Compare' incorporates:
   *  Constant: '<S24>/Constant'
   *  Logic: '<S9>/Logical Operator3'
   *  RelationalOperator: '<S25>/Compare'
   *  SignalConversion generated from: '<S194>/Signal Copy'
   */
  rtb_Saturation1_j_idx_1 = (rtb_Multiply_cb != 0);

  /* End of Outputs for SubSystem: '<S56>/CF' */
  /* End of Outputs for SubSystem: '<Root>/Data_Fusion' */
  rtb_Switch_g3 = (rtb_Saturation1_j_idx_1 > (int32_T)
                   INS_P.CompareToConstant1_const_m);

  /* DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
  if (rtb_Switch_g3 || (INS_DWork.DiscreteTimeIntegrator_PrevR_nf != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_bo = INS_P.DiscreteTimeIntegrator_IC;
  }

  /* RelationalOperator: '<S39>/Compare' incorporates:
   *  Constant: '<S39>/Constant'
   */
  rtb_WGS84_pos_valid = ((int32_T)rtb_FixPtRelationalOperator_nc > (int32_T)
    INS_P.CompareToConstant1_const_j);

  /* DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */
  if (rtb_WGS84_pos_valid || (INS_DWork.DiscreteTimeIntegrator_PrevRe_m != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_hi =
      INS_P.DiscreteTimeIntegrator_IC_i;
  }

  /* Relay: '<S9>/Relay' */
  INS_DWork.Relay_Mode_n1 = ((rtb_Sum2_by >= INS_P.Relay_OnVal) || ((rtb_Sum2_by
    > INS_P.Relay_OffVal) && INS_DWork.Relay_Mode_n1));

  /* Relay: '<S9>/Relay1' */
  INS_DWork.Relay1_Mode_j = ((rtb_MathFunction1 >= INS_P.Relay1_OnVal) ||
    ((rtb_MathFunction1 > INS_P.Relay1_OffVal) && INS_DWork.Relay1_Mode_j));

  /* Relay: '<S9>/Relay' */
  if (INS_DWork.Relay_Mode_n1) {
    rtb_Gain1_n_idx_0 = INS_P.Relay_YOn;
  } else {
    rtb_Gain1_n_idx_0 = INS_P.Relay_YOff;
  }

  /* Relay: '<S9>/Relay1' */
  if (INS_DWork.Relay1_Mode_j) {
    rtb_LogicalOperator2_g = INS_P.Relay1_YOn_i;
  } else {
    rtb_LogicalOperator2_g = INS_P.Relay1_YOff_k;
  }

  /* Logic: '<S9>/Logical Operator4' incorporates:
   *  Logic: '<S9>/Logical Operator6'
   *  Relay: '<S9>/Relay'
   *  Relay: '<S9>/Relay1'
   */
  rtb_LogicalOperator1_cc = ((rtb_Compare_cio && (rtb_Gain1_n_idx_0 != 0.0F)) ||
    rtb_LogicalOperator2_g || rtb_LogicalOperator5);

  /* RelationalOperator: '<S49>/Compare' incorporates:
   *  Constant: '<S49>/Constant'
   */
  rtb_LogicalOperator5 = ((int32_T)rtb_LogicalOperator1_cc > (int32_T)
    INS_P.CompareToConstant1_const_g);

  /* DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
  if (rtb_LogicalOperator5 || (INS_DWork.DiscreteTimeIntegrator_PrevR_dj != 0))
  {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_b3 =
      INS_P.DiscreteTimeIntegrator_IC_o;
  }

  /* Outputs for Atomic SubSystem: '<Root>/Data_Fusion' */
  /* Outputs for Atomic SubSystem: '<S56>/CF' */
  /* RelationalOperator: '<S19>/Compare' incorporates:
   *  Constant: '<S19>/Constant'
   *  Logic: '<S9>/Logical Operator2'
   *  RelationalOperator: '<S20>/Compare'
   *  RelationalOperator: '<S29>/Compare'
   *  RelationalOperator: '<S30>/Compare'
   *  SignalConversion generated from: '<S194>/Signal Copy'
   */
  rtb_MathFunction1_tmp = (rtb_Multiply_jy != 0);

  /* End of Outputs for SubSystem: '<S56>/CF' */
  /* End of Outputs for SubSystem: '<Root>/Data_Fusion' */
  rtb_Compare_cio = (rtb_MathFunction1_tmp > (int32_T)
                     INS_P.CompareToConstant1_const_e);

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
  if (rtb_Compare_cio || (INS_DWork.DiscreteTimeIntegrator_PrevR_h1 != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_ca =
      INS_P.DiscreteTimeIntegrator_IC_l;
  }

  /* RelationalOperator: '<S29>/Compare' incorporates:
   *  Constant: '<S29>/Constant'
   */
  rtb_LogicalOperator5_i = (rtb_MathFunction1_tmp > (int32_T)
    INS_P.CompareToConstant1_const_ei);

  /* DiscreteIntegrator: '<S13>/Discrete-Time Integrator' */
  if (rtb_LogicalOperator5_i || (INS_DWork.DiscreteTimeIntegrator_PrevR_as != 0))
  {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_e =
      INS_P.DiscreteTimeIntegrator_IC_j;
  }

  /* Outputs for Atomic SubSystem: '<Root>/Data_Fusion' */
  /* Outputs for Atomic SubSystem: '<S56>/CF' */
  /* RelationalOperator: '<S34>/Compare' incorporates:
   *  Constant: '<S34>/Constant'
   *  Logic: '<S9>/Logical Operator'
   *  RelationalOperator: '<S35>/Compare'
   *  SignalConversion generated from: '<S194>/Signal Copy'
   */
  rtb_Saturation1_j_idx_0 = (rtb_Multiply_o != 0);

  /* End of Outputs for SubSystem: '<S56>/CF' */
  /* End of Outputs for SubSystem: '<Root>/Data_Fusion' */
  rtb_Compare_o = (rtb_Saturation1_j_idx_0 > (int32_T)
                   INS_P.CompareToConstant1_const_ec);

  /* DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
  if (rtb_Compare_o || (INS_DWork.DiscreteTimeIntegrator_PrevRe_o != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_kg =
      INS_P.DiscreteTimeIntegrator_IC_ig;
  }

  /* Outputs for Atomic SubSystem: '<Root>/Data_Fusion' */
  /* Outputs for Atomic SubSystem: '<S56>/CF' */
  /* RelationalOperator: '<S44>/Compare' incorporates:
   *  Constant: '<S44>/Constant'
   *  Logic: '<S9>/Logical Operator5'
   *  RelationalOperator: '<S45>/Compare'
   *  SignalConversion generated from: '<S194>/Signal Copy'
   */
  rtb_Compare_he_tmp = (rtb_Multiply_gs != 0);

  /* End of Outputs for SubSystem: '<S56>/CF' */
  /* End of Outputs for SubSystem: '<Root>/Data_Fusion' */
  rtb_Compare_fo = (rtb_Compare_he_tmp > (int32_T)
                    INS_P.CompareToConstant1_const_em);

  /* DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
  if (rtb_Compare_fo || (INS_DWork.DiscreteTimeIntegrator_PrevR_ar != 0)) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_a =
      INS_P.DiscreteTimeIntegrator_IC_e;
  }

  /* Outputs for Atomic SubSystem: '<Root>/Data_Fusion' */
  /* Outputs for Atomic SubSystem: '<S55>/AHRS' */
  /* Outputs for Atomic SubSystem: '<S57>/Bus_Constructor' */
  /* Gain: '<S8>/Gain10' incorporates:
   *  SignalConversion generated from: '<S59>/Signal Conversion1'
   */
  rtb_Gain1_n_idx_0 = fmodf(floorf(INS_P.Gain10_Gain * rtb_Relay), 4.2949673E+9F);

  /* End of Outputs for SubSystem: '<S57>/Bus_Constructor' */
  /* End of Outputs for SubSystem: '<S55>/AHRS' */
  /* End of Outputs for SubSystem: '<Root>/Data_Fusion' */

  /* Sum: '<S8>/Sum2' incorporates:
   *  Constant: '<S18>/Constant'
   *  Constant: '<S23>/Constant'
   *  Constant: '<S28>/Constant'
   *  Constant: '<S33>/Constant'
   *  Constant: '<S38>/Constant'
   *  Constant: '<S43>/Constant'
   *  Constant: '<S48>/Constant'
   *  Constant: '<S8>/Constant'
   *  Delay: '<S11>/Delay'
   *  Delay: '<S12>/Delay'
   *  Delay: '<S13>/Delay'
   *  Delay: '<S14>/Delay'
   *  Delay: '<S15>/Delay'
   *  Delay: '<S16>/Delay'
   *  Delay: '<S17>/Delay'
   *  DiscreteIntegrator: '<S11>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S13>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S14>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S15>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S16>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S17>/Discrete-Time Integrator'
   *  Gain: '<S8>/Gain1'
   *  Gain: '<S8>/Gain10'
   *  Gain: '<S8>/Gain11'
   *  Gain: '<S8>/Gain12'
   *  Gain: '<S8>/Gain13'
   *  Gain: '<S8>/Gain2'
   *  Gain: '<S8>/Gain4'
   *  Gain: '<S8>/Gain5'
   *  Gain: '<S8>/Gain9'
   *  Logic: '<S11>/Logical Operator'
   *  Logic: '<S12>/Logical Operator'
   *  Logic: '<S13>/Logical Operator'
   *  Logic: '<S14>/Logical Operator'
   *  Logic: '<S15>/Logical Operator'
   *  Logic: '<S16>/Logical Operator'
   *  Logic: '<S17>/Logical Operator'
   *  Product: '<S11>/Multiply'
   *  Product: '<S12>/Multiply'
   *  Product: '<S13>/Multiply'
   *  Product: '<S14>/Multiply'
   *  Product: '<S15>/Multiply'
   *  Product: '<S16>/Multiply'
   *  Product: '<S17>/Multiply'
   *  RelationalOperator: '<S18>/Compare'
   *  RelationalOperator: '<S23>/Compare'
   *  RelationalOperator: '<S28>/Compare'
   *  RelationalOperator: '<S33>/Compare'
   *  RelationalOperator: '<S38>/Compare'
   *  RelationalOperator: '<S43>/Compare'
   *  RelationalOperator: '<S48>/Compare'
   *  Sum: '<S8>/Sum8'
   */
  INS_Y.INS_Out.flag = ((((((((uint32_T)(((uint64_T)INS_P.Gain9_Gain *
    INS_P.Constant_Value_pt) >> 31) + (rtb_Gain1_n_idx_0 < 0.0F ? (uint32_T)
    -(int32_T)(uint32_T)-rtb_Gain1_n_idx_0 : (uint32_T)rtb_Gain1_n_idx_0)) +
    (((uint32_T)(INS_DWork.DiscreteTimeIntegrator_DSTAT_hi <
                 INS_P.valid_check5_time_out ? (int32_T)
                 INS_DWork.Delay_DSTATE_cx : 0) * INS_P.Gain11_Gain) >> 13)) +
    (((uint32_T)(INS_DWork.DiscreteTimeIntegrator_DSTAT_b3 <
                 INS_P.valid_check8_time_out ? (int32_T)
                 INS_DWork.Delay_DSTATE_l0 : 0) * INS_P.Gain12_Gain) >> 12)) +
    (((uint32_T)(INS_DWork.DiscreteTimeIntegrator_DSTAT_ca <
                 INS_P.valid_check1_time_out ? (int32_T)
                 INS_DWork.Delay_DSTATE_cn : 0) * INS_P.Gain13_Gain) >> 11)) +
    (((uint32_T)(INS_DWork.DiscreteTimeIntegrator_DSTAT_bo <
                 INS_P.valid_check2_time_out ? (int32_T)
                 INS_DWork.Delay_DSTATE_bn : 0) * INS_P.Gain1_Gain_kq) >> 10)) +
    (((uint32_T)(INS_DWork.DiscreteTimeIntegrator_DSTATE_e <
                 INS_P.valid_check3_time_out ? (int32_T)
                 INS_DWork.Delay_DSTATE_pk : 0) * INS_P.Gain2_Gain_o5) >> 9)) +
                        (((uint32_T)(INS_DWork.DiscreteTimeIntegrator_DSTAT_kg <
    INS_P.valid_check4_time_out ? (int32_T)INS_DWork.Delay_DSTATE_db : 0) *
    INS_P.Gain4_Gain_a) >> 8)) + (((uint32_T)
    (INS_DWork.DiscreteTimeIntegrator_DSTATE_a < INS_P.valid_check6_time_out ?
     (int32_T)INS_DWork.Delay_DSTATE_lyf : 0) * INS_P.Gain5_Gain_e) >> 7);

  /* RelationalOperator: '<S22>/Compare' incorporates:
   *  Constant: '<S20>/Constant'
   *  Constant: '<S22>/Constant'
   *  RelationalOperator: '<S20>/Compare'
   */
  rtb_Compare_ir = ((rtb_MathFunction1_tmp > (int32_T)
                     INS_P.CompareToConstant2_const) > (int32_T)
                    INS_P.Constant_Value_mt);

  /* RelationalOperator: '<S27>/Compare' incorporates:
   *  Constant: '<S25>/Constant'
   *  Constant: '<S27>/Constant'
   *  RelationalOperator: '<S25>/Compare'
   */
  rtb_Compare_ay = ((rtb_Saturation1_j_idx_1 > (int32_T)
                     INS_P.CompareToConstant2_const_c) > (int32_T)
                    INS_P.Constant_Value_m2);

  /* RelationalOperator: '<S32>/Compare' incorporates:
   *  Constant: '<S30>/Constant'
   *  Constant: '<S32>/Constant'
   *  RelationalOperator: '<S30>/Compare'
   */
  rtb_Compare_fg = ((rtb_MathFunction1_tmp > (int32_T)
                     INS_P.CompareToConstant2_const_n) > (int32_T)
                    INS_P.Constant_Value_o2);

  /* RelationalOperator: '<S37>/Compare' incorporates:
   *  Constant: '<S35>/Constant'
   *  Constant: '<S37>/Constant'
   *  RelationalOperator: '<S35>/Compare'
   */
  rtb_Compare_n1 = ((rtb_Saturation1_j_idx_0 > (int32_T)
                     INS_P.CompareToConstant2_const_b) > (int32_T)
                    INS_P.Constant_Value_hk);

  /* RelationalOperator: '<S42>/Compare' incorporates:
   *  Constant: '<S40>/Constant'
   *  Constant: '<S42>/Constant'
   *  RelationalOperator: '<S40>/Compare'
   */
  rtb_LogicalOperator2_g = (((int32_T)rtb_FixPtRelationalOperator_nc > (int32_T)
    INS_P.CompareToConstant2_const_i) > (int32_T)INS_P.Constant_Value_l1);

  /* RelationalOperator: '<S47>/Compare' incorporates:
   *  Constant: '<S45>/Constant'
   *  Constant: '<S47>/Constant'
   *  RelationalOperator: '<S45>/Compare'
   */
  rtb_LogicalOperator3 = ((rtb_Compare_he_tmp > (int32_T)
    INS_P.CompareToConstant2_const_l) > (int32_T)INS_P.Constant_Value_m2n);

  /* RelationalOperator: '<S52>/Compare' incorporates:
   *  Constant: '<S50>/Constant'
   *  Constant: '<S52>/Constant'
   *  RelationalOperator: '<S50>/Compare'
   */
  rtb_LogicalOperator1_cc = (((int32_T)rtb_LogicalOperator1_cc > (int32_T)
    INS_P.CompareToConstant2_const_i1) > (int32_T)INS_P.Constant_Value_ao);

  /* Sum: '<S10>/Sum' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S53>/Constant'
   *  Constant: '<S54>/Constant'
   *  DataTypeConversion: '<S10>/Data Type Conversion'
   *  Gain: '<S10>/Gain1'
   *  Gain: '<S10>/Gain2'
   *  Gain: '<S10>/Gain3'
   *  Gain: '<S10>/Gain4'
   *  Gain: '<S10>/Gain5'
   *  Gain: '<S10>/Gain6'
   *  MinMax: '<S10>/Max'
   *  RelationalOperator: '<S53>/Compare'
   *  RelationalOperator: '<S54>/Compare'
   *  Sum: '<S10>/Sum5'
   */
  INS_Y.INS_Out.status = ((((((uint32_T)(((uint64_T)INS_P.Gain1_Gain_ap *
    INS_P.Constant_Value_lm) >> 30) + rtb_FixPtRelationalOperator_nc) +
    (rtb_MathFunction1 > INS_P.Constant_Value_h ? (uint32_T)(INS_P.Gain2_Gain_h >>
    5) : 0U)) + (rtb_FixPtRelationalOperator_cn ? (uint32_T)(INS_P.Gain3_Gain_f >>
    4) : 0U)) + (fmaxf(rtb_Sum2_by, rtb_Divide1) > INS_P.Constant_Value_j ?
                 (uint32_T)(INS_P.Gain4_Gain_p >> 3) : 0U)) + (rtb_Compare_c5 ?
    (uint32_T)(INS_P.Gain5_Gain_a >> 2) : 0U)) + (rtb_Compare_ai ? (uint32_T)
    (INS_P.Gain6_Gain >> 1) : 0U);

  /* Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S12>/Constant'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTAT_bo +=
    INS_P.DiscreteTimeIntegrator_gainval * (real32_T)INS_EXPORT.period;
  if (INS_DWork.DiscreteTimeIntegrator_DSTAT_bo >
      INS_P.DiscreteTimeIntegrator_UpperSat) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_bo =
      INS_P.DiscreteTimeIntegrator_UpperSat;
  } else if (INS_DWork.DiscreteTimeIntegrator_DSTAT_bo <
             INS_P.DiscreteTimeIntegrator_LowerSat) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_bo =
      INS_P.DiscreteTimeIntegrator_LowerSat;
  }

  INS_DWork.DiscreteTimeIntegrator_PrevR_nf = (int8_T)rtb_Switch_g3;

  /* End of Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */

  /* Update for Delay: '<S12>/Delay' incorporates:
   *  Logic: '<S12>/Logical Operator1'
   *  RelationalOperator: '<S26>/FixPt Relational Operator'
   *  UnitDelay: '<S26>/Delay Input1'
   */
  INS_DWork.Delay_DSTATE_bn = (((int32_T)rtb_Compare_ay > (int32_T)
    INS_DWork.DelayInput1_DSTATE_mu) || INS_DWork.Delay_DSTATE_bn);

  /* Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S15>/Constant'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTAT_hi +=
    INS_P.DiscreteTimeIntegrator_gainva_i * (real32_T)INS_EXPORT.period;
  if (INS_DWork.DiscreteTimeIntegrator_DSTAT_hi >
      INS_P.DiscreteTimeIntegrator_UpperS_g) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_hi =
      INS_P.DiscreteTimeIntegrator_UpperS_g;
  } else if (INS_DWork.DiscreteTimeIntegrator_DSTAT_hi <
             INS_P.DiscreteTimeIntegrator_LowerS_j) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_hi =
      INS_P.DiscreteTimeIntegrator_LowerS_j;
  }

  INS_DWork.DiscreteTimeIntegrator_PrevRe_m = (int8_T)rtb_WGS84_pos_valid;

  /* End of Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */

  /* Update for Delay: '<S15>/Delay' incorporates:
   *  Logic: '<S15>/Logical Operator1'
   *  RelationalOperator: '<S41>/FixPt Relational Operator'
   *  UnitDelay: '<S41>/Delay Input1'
   */
  INS_DWork.Delay_DSTATE_cx = (((int32_T)rtb_LogicalOperator2_g > (int32_T)
    INS_DWork.DelayInput1_DSTATE_ng) || INS_DWork.Delay_DSTATE_cx);

  /* Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S17>/Constant'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTAT_b3 +=
    INS_P.DiscreteTimeIntegrator_gainva_m * (real32_T)INS_EXPORT.period;
  if (INS_DWork.DiscreteTimeIntegrator_DSTAT_b3 >
      INS_P.DiscreteTimeIntegrator_UpperS_d) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_b3 =
      INS_P.DiscreteTimeIntegrator_UpperS_d;
  } else if (INS_DWork.DiscreteTimeIntegrator_DSTAT_b3 <
             INS_P.DiscreteTimeIntegrator_LowerS_n) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_b3 =
      INS_P.DiscreteTimeIntegrator_LowerS_n;
  }

  INS_DWork.DiscreteTimeIntegrator_PrevR_dj = (int8_T)rtb_LogicalOperator5;

  /* End of Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */

  /* Update for Delay: '<S17>/Delay' incorporates:
   *  Logic: '<S17>/Logical Operator1'
   *  RelationalOperator: '<S51>/FixPt Relational Operator'
   *  UnitDelay: '<S51>/Delay Input1'
   */
  INS_DWork.Delay_DSTATE_l0 = (((int32_T)rtb_LogicalOperator1_cc > (int32_T)
    INS_DWork.DelayInput1_DSTATE_fq) || INS_DWork.Delay_DSTATE_l0);

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S11>/Constant'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTAT_ca +=
    INS_P.DiscreteTimeIntegrator_gainva_k * (real32_T)INS_EXPORT.period;
  if (INS_DWork.DiscreteTimeIntegrator_DSTAT_ca >
      INS_P.DiscreteTimeIntegrator_UpperS_n) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_ca =
      INS_P.DiscreteTimeIntegrator_UpperS_n;
  } else if (INS_DWork.DiscreteTimeIntegrator_DSTAT_ca <
             INS_P.DiscreteTimeIntegrator_LowerS_l) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_ca =
      INS_P.DiscreteTimeIntegrator_LowerS_l;
  }

  INS_DWork.DiscreteTimeIntegrator_PrevR_h1 = (int8_T)rtb_Compare_cio;

  /* End of Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */

  /* Update for Delay: '<S11>/Delay' incorporates:
   *  Logic: '<S11>/Logical Operator1'
   *  RelationalOperator: '<S21>/FixPt Relational Operator'
   *  UnitDelay: '<S21>/Delay Input1'
   */
  INS_DWork.Delay_DSTATE_cn = (((int32_T)rtb_Compare_ir > (int32_T)
    INS_DWork.DelayInput1_DSTATE_dx) || INS_DWork.Delay_DSTATE_cn);

  /* Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S13>/Constant'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_e +=
    INS_P.DiscreteTimeIntegrator_gainva_p * (real32_T)INS_EXPORT.period;
  if (INS_DWork.DiscreteTimeIntegrator_DSTATE_e >
      INS_P.DiscreteTimeIntegrator_UpperS_f) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_e =
      INS_P.DiscreteTimeIntegrator_UpperS_f;
  } else if (INS_DWork.DiscreteTimeIntegrator_DSTATE_e <
             INS_P.DiscreteTimeIntegrator_LowerS_f) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_e =
      INS_P.DiscreteTimeIntegrator_LowerS_f;
  }

  INS_DWork.DiscreteTimeIntegrator_PrevR_as = (int8_T)rtb_LogicalOperator5_i;

  /* End of Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' */

  /* Update for Delay: '<S13>/Delay' incorporates:
   *  Logic: '<S13>/Logical Operator1'
   *  RelationalOperator: '<S31>/FixPt Relational Operator'
   *  UnitDelay: '<S31>/Delay Input1'
   */
  INS_DWork.Delay_DSTATE_pk = (((int32_T)rtb_Compare_fg > (int32_T)
    INS_DWork.DelayInput1_DSTATE_dq) || INS_DWork.Delay_DSTATE_pk);

  /* Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S14>/Constant'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTAT_kg +=
    INS_P.DiscreteTimeIntegrator_gainv_me * (real32_T)INS_EXPORT.period;
  if (INS_DWork.DiscreteTimeIntegrator_DSTAT_kg >
      INS_P.DiscreteTimeIntegrator_UpperS_m) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_kg =
      INS_P.DiscreteTimeIntegrator_UpperS_m;
  } else if (INS_DWork.DiscreteTimeIntegrator_DSTAT_kg <
             INS_P.DiscreteTimeIntegrator_LowerS_i) {
    INS_DWork.DiscreteTimeIntegrator_DSTAT_kg =
      INS_P.DiscreteTimeIntegrator_LowerS_i;
  }

  INS_DWork.DiscreteTimeIntegrator_PrevRe_o = (int8_T)rtb_Compare_o;

  /* End of Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */

  /* Update for Delay: '<S14>/Delay' incorporates:
   *  Logic: '<S14>/Logical Operator1'
   *  RelationalOperator: '<S36>/FixPt Relational Operator'
   *  UnitDelay: '<S36>/Delay Input1'
   */
  INS_DWork.Delay_DSTATE_db = (((int32_T)rtb_Compare_n1 > (int32_T)
    INS_DWork.DelayInput1_DSTATE_f4) || INS_DWork.Delay_DSTATE_db);

  /* Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S16>/Constant'
   */
  INS_DWork.DiscreteTimeIntegrator_DSTATE_a +=
    INS_P.DiscreteTimeIntegrator_gainv_my * (real32_T)INS_EXPORT.period;
  if (INS_DWork.DiscreteTimeIntegrator_DSTATE_a >
      INS_P.DiscreteTimeIntegrator_Upper_ml) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_a =
      INS_P.DiscreteTimeIntegrator_Upper_ml;
  } else if (INS_DWork.DiscreteTimeIntegrator_DSTATE_a <
             INS_P.DiscreteTimeIntegrator_LowerS_g) {
    INS_DWork.DiscreteTimeIntegrator_DSTATE_a =
      INS_P.DiscreteTimeIntegrator_LowerS_g;
  }

  INS_DWork.DiscreteTimeIntegrator_PrevR_ar = (int8_T)rtb_Compare_fo;

  /* End of Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */

  /* Update for Delay: '<S16>/Delay' incorporates:
   *  Logic: '<S16>/Logical Operator1'
   *  RelationalOperator: '<S46>/FixPt Relational Operator'
   *  UnitDelay: '<S46>/Delay Input1'
   */
  INS_DWork.Delay_DSTATE_lyf = (((int32_T)rtb_LogicalOperator3 > (int32_T)
    INS_DWork.DelayInput1_DSTATE_dql) || INS_DWork.Delay_DSTATE_lyf);

  /* Update for UnitDelay: '<S21>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_dx = rtb_Compare_ir;

  /* Update for UnitDelay: '<S26>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_mu = rtb_Compare_ay;

  /* Update for UnitDelay: '<S31>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_dq = rtb_Compare_fg;

  /* Update for UnitDelay: '<S36>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_f4 = rtb_Compare_n1;

  /* Update for UnitDelay: '<S41>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_ng = rtb_LogicalOperator2_g;

  /* Update for UnitDelay: '<S46>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_dql = rtb_LogicalOperator3;

  /* Update for UnitDelay: '<S51>/Delay Input1' */
  INS_DWork.DelayInput1_DSTATE_fq = rtb_LogicalOperator1_cc;

  /* End of Outputs for SubSystem: '<S1>/Status_Output' */

  /* Outputs for Atomic SubSystem: '<S1>/Rotation_Output' */
  /* BusCreator generated from: '<Root>/INS_Out' incorporates:
   *  Outport: '<Root>/INS_Out'
   *  Product: '<S117>/Divide'
   *  SignalConversion generated from: '<S59>/Rotation_Data'
   *  SignalConversion generated from: '<S5>/Signal Copy'
   *  SignalConversion generated from: '<S7>/Signal Copy'
   *  Sum: '<S59>/Sum'
   */
  INS_Y.INS_Out.phi = rtb_Gain_ca_idx_0;
  INS_Y.INS_Out.theta = rtb_Gain_ca_idx_1;
  INS_Y.INS_Out.psi = rtb_Gain_ca_idx_2;

  /* End of Outputs for SubSystem: '<S1>/Rotation_Output' */
  /* End of Outputs for SubSystem: '<Root>/Bus_Constructor' */

  /* Outputs for Atomic SubSystem: '<Root>/Data_Fusion' */
  /* Outputs for Atomic SubSystem: '<S55>/AHRS' */
  /* Outputs for Atomic SubSystem: '<S57>/Bus_Constructor' */
  INS_Y.INS_Out.quat[0] = rtb_Switch_kj_idx_0;
  INS_Y.INS_Out.quat[1] = rtb_Switch_kj_idx_1;
  INS_Y.INS_Out.quat[2] = rtb_Switch_kj_idx_2;

  /* End of Outputs for SubSystem: '<S57>/Bus_Constructor' */

  /* Outputs for Atomic SubSystem: '<S57>/Update' */
  INS_Y.INS_Out.quat[3] = rtb_Switch_kj_0;

  /* End of Outputs for SubSystem: '<S57>/Update' */

  /* Outputs for Atomic SubSystem: '<S57>/Bus_Constructor' */
  INS_Y.INS_Out.p = rtb_VectorConcatenate_idx_0;
  INS_Y.INS_Out.q = rtb_VectorConcatenate_idx_1;

  /* End of Outputs for SubSystem: '<S57>/Bus_Constructor' */
  /* End of Outputs for SubSystem: '<S55>/AHRS' */
  /* End of Outputs for SubSystem: '<Root>/Data_Fusion' */
  INS_Y.INS_Out.r = Constant_Value_b;
  INS_Y.INS_Out.ax = rtb_Gauss_to_uT[0];
  INS_Y.INS_Out.ay = rtb_Gauss_to_uT[1];
  INS_Y.INS_Out.az = rtb_Gauss_to_uT[2];

  /* Outputs for Atomic SubSystem: '<Root>/Bus_Constructor' */
  /* Outputs for Atomic SubSystem: '<S1>/Translation_Output' */
  INS_Y.INS_Out.vn = rtb_Sum_g0[2];
  INS_Y.INS_Out.ve = rtb_Sum_g0[3];
  INS_Y.INS_Out.vd = rtb_MathFunction[1];

  /* End of Outputs for SubSystem: '<S1>/Translation_Output' */
  /* End of Outputs for SubSystem: '<Root>/Bus_Constructor' */

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
  /* Outputs for Atomic SubSystem: '<S3>/AirSpeed_Process' */
  /* Signum: '<S396>/Sign' incorporates:
   *  Inport: '<Root>/AirSpeed'
   */
  if (INS_U.AirSpeed.diff_pressure < 0.0F) {
    rtb_MathFunction1_tmp = -1;
  } else {
    rtb_MathFunction1_tmp = (INS_U.AirSpeed.diff_pressure > 0.0F);
  }

  /* Product: '<S396>/Multiply' incorporates:
   *  Abs: '<S396>/Abs'
   *  Constant: '<S396>/AirDensity_15C'
   *  Gain: '<S396>/Gain'
   *  Inport: '<Root>/AirSpeed'
   *  Product: '<S396>/Divide'
   *  Signum: '<S396>/Sign'
   *  Sqrt: '<S396>/Sqrt'
   */
  rtb_DiscreteTimeIntegrator_g = sqrtf(INS_P.Gain_Gain_oz * fabsf
    (INS_U.AirSpeed.diff_pressure) / INS_P.AirDensity_15C_Value) * (real32_T)
    rtb_MathFunction1_tmp;

  /* Saturate: '<S388>/Saturation1' */
  if (rtb_DiscreteTimeIntegrator_g > INS_P.Saturation1_UpperSat_i) {
    /* BusCreator generated from: '<Root>/INS_Out' incorporates:
     *  Outport: '<Root>/INS_Out'
     */
    INS_Y.INS_Out.airspeed = INS_P.Saturation1_UpperSat_i;
  } else if (rtb_DiscreteTimeIntegrator_g < INS_P.Saturation1_LowerSat_n) {
    /* BusCreator generated from: '<Root>/INS_Out' incorporates:
     *  Outport: '<Root>/INS_Out'
     */
    INS_Y.INS_Out.airspeed = INS_P.Saturation1_LowerSat_n;
  } else {
    /* BusCreator generated from: '<Root>/INS_Out' incorporates:
     *  Outport: '<Root>/INS_Out'
     */
    INS_Y.INS_Out.airspeed = rtb_DiscreteTimeIntegrator_g;
  }

  /* End of Saturate: '<S388>/Saturation1' */
  /* End of Outputs for SubSystem: '<S3>/AirSpeed_Process' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_PreProcess' */

  /* Outputs for Atomic SubSystem: '<Root>/Data_Fusion' */
  /* Outputs for Atomic SubSystem: '<S56>/CF' */
  /* BusCreator generated from: '<Root>/INS_Out' incorporates:
   *  Outport: '<Root>/INS_Out'
   *  SignalConversion generated from: '<S194>/Signal Copy1'
   *  SignalConversion generated from: '<S194>/Signal Copy2'
   *  SignalConversion generated from: '<S194>/Signal Copy3'
   *  SignalConversion generated from: '<S194>/Signal Copy4'
   *  SignalConversion generated from: '<S194>/Signal Copy5'
   *  SignalConversion generated from: '<S7>/Signal Copy'
   *  Sum: '<S199>/Sum'
   */
  INS_Y.INS_Out.lat_0 = rtb_Switch4_c_idx_0;
  INS_Y.INS_Out.lon_0 = rtb_Switch4_c_idx_1;
  INS_Y.INS_Out.alt_0 = rtb_ff;
  INS_Y.INS_Out.dx_dlat = rtb_DataTypeConversion2;
  INS_Y.INS_Out.dy_dlon = rtb_Switch1_idx_1;

  /* End of Outputs for SubSystem: '<S56>/CF' */
  /* End of Outputs for SubSystem: '<Root>/Data_Fusion' */

  /* Outputs for Atomic SubSystem: '<Root>/Bus_Constructor' */
  /* Outputs for Atomic SubSystem: '<S1>/Translation_Output' */
  INS_Y.INS_Out.x_R = rtb_Sum_g0[0];
  INS_Y.INS_Out.y_R = rtb_Sum_g0[1];
  INS_Y.INS_Out.h_R = rtb_MathFunction[0];

  /* End of Outputs for SubSystem: '<S1>/Translation_Output' */
  /* End of Outputs for SubSystem: '<Root>/Bus_Constructor' */

  /* Outputs for Atomic SubSystem: '<Root>/Data_Fusion' */
  /* Outputs for Atomic SubSystem: '<S56>/CF' */
  INS_Y.INS_Out.h_AGL = rtb_MathFunction[0] - INS_B.rf_height_bias;

  /* End of Outputs for SubSystem: '<S56>/CF' */
  /* End of Outputs for SubSystem: '<Root>/Data_Fusion' */

  /* Update for Delay generated from: '<Root>/Delay' */
  INS_DWork.Delay_3_DSTATE = rtb_Gain_ca_idx_0;

  /* Update for Delay generated from: '<Root>/Delay' */
  INS_DWork.Delay_4_DSTATE = rtb_Gain_ca_idx_1;

  /* Update for Delay generated from: '<Root>/Delay' incorporates:
   *  Math: '<S114>/Transpose'
   *  SignalConversion generated from: '<S59>/Rotation_Data'
   */
  for (rtb_Saturation1_j_idx_1 = 0; rtb_Saturation1_j_idx_1 < 9;
       rtb_Saturation1_j_idx_1++) {
    /* Outputs for Atomic SubSystem: '<Root>/Data_Fusion' */
    /* Outputs for Atomic SubSystem: '<S55>/AHRS' */
    /* Outputs for Atomic SubSystem: '<S57>/Bus_Constructor' */
    INS_DWork.Delay_9_DSTATE[rtb_Saturation1_j_idx_1] =
      rtb_VectorConcatenate_g[rtb_Saturation1_j_idx_1];

    /* End of Outputs for SubSystem: '<S57>/Bus_Constructor' */
    /* End of Outputs for SubSystem: '<S55>/AHRS' */
    /* End of Outputs for SubSystem: '<Root>/Data_Fusion' */
  }
}

/* Model initialize function */
void INS_init(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(INS_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &INS_B), 0,
                sizeof(BlockIO_INS_T));

  /* states (dwork) */
  (void) memset((void *)&INS_DWork, 0,
                sizeof(D_Work_INS_T));

  /* external inputs */
  (void)memset(&INS_U, 0, sizeof(ExternalInputs_INS_T));

  /* external outputs */
  INS_Y.INS_Out = INS_rtZINS_Out_Bus;

  {
    int32_T i;
    INS_PrevZCSigState.x_delay_Reset_ZCE_lr = POS_ZCSIG;
    INS_PrevZCSigState.y_delay_Reset_ZCE = POS_ZCSIG;
    INS_PrevZCSigState.x_delay_Reset_ZCE_b = POS_ZCSIG;
    INS_PrevZCSigState.x_delay1_Reset_ZCE = POS_ZCSIG;
    INS_PrevZCSigState.vn_delay_Reset_ZCE_p = POS_ZCSIG;
    INS_PrevZCSigState.vn_delay1_Reset_ZCE = POS_ZCSIG;
    INS_PrevZCSigState.vn_delay_Reset_ZCE = POS_ZCSIG;
    INS_PrevZCSigState.ve_delay_Reset_ZCE = POS_ZCSIG;
    INS_PrevZCSigState.x_delay_Reset_ZCE_l = POS_ZCSIG;
    INS_PrevZCSigState.x_delay_Reset_ZCE = POS_ZCSIG;
    INS_PrevZCSigState.h_delay_Reset_ZCE_m = POS_ZCSIG;
    INS_PrevZCSigState.vd_delay_Reset_ZCE = POS_ZCSIG;
    INS_PrevZCSigState.h_delay_Reset_ZCE = POS_ZCSIG;
    INS_PrevZCSigState.WGS84_Model_Trig_ZCE = POS_ZCSIG;

    /* InitializeConditions for Delay generated from: '<Root>/Delay' */
    INS_DWork.Delay_3_DSTATE = INS_P.Delay_3_InitialCondition;

    /* InitializeConditions for Delay generated from: '<Root>/Delay' */
    INS_DWork.Delay_4_DSTATE = INS_P.Delay_4_InitialCondition_m;

    /* InitializeConditions for Delay generated from: '<Root>/Delay' */
    for (i = 0; i < 9; i++) {
      INS_DWork.Delay_9_DSTATE[i] = INS_P.Delay_9_InitialCondition;
    }

    /* SystemInitialize for Atomic SubSystem: '<Root>/Sensor_PreProcess' */
    /* SystemInitialize for Atomic SubSystem: '<S3>/Baro_PreProcess' */
    /* InitializeConditions for UnitDelay: '<S403>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_g = INS_P.DetectChange_vinit_d;

    /* InitializeConditions for UnitDelay: '<S406>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_c = INS_P.DetectChange_vinit_n;

    /* InitializeConditions for DiscreteIntegrator: '<S399>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_nm =
      INS_P.DiscreteTimeIntegrator_IC_iu;

    /* InitializeConditions for Delay: '<S407>/Delay' */
    INS_DWork.Delay_DSTATE_i1 = INS_P.Delay_InitialCondition_j0;

    /* InitializeConditions for Delay: '<S401>/Delay' */
    INS_DWork.Delay_DSTATE_fy = INS_P.Delay_InitialCondition_nt;

    /* SystemInitialize for Enabled SubSystem: '<S398>/Reference_Height' */
    /* InitializeConditions for Delay: '<S400>/Delay' */
    INS_DWork.Delay_DSTATE_d = INS_P.Delay_InitialCondition_p;

    /* InitializeConditions for Delay: '<S400>/Delay1' */
    INS_DWork.Delay1_DSTATE_i = INS_P.Delay1_InitialCondition_k;

    /* SystemInitialize for Product: '<S400>/Divide' incorporates:
     *  Outport: '<S400>/h_R_m'
     */
    INS_B.Divide = INS_P.h_R_m_Y0;

    /* End of SystemInitialize for SubSystem: '<S398>/Reference_Height' */
    /* End of SystemInitialize for SubSystem: '<S3>/Baro_PreProcess' */

    /* SystemInitialize for Atomic SubSystem: '<S3>/ExternalPos_Process' */
    /* InitializeConditions for UnitDelay: '<S413>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_b = INS_P.DetectChange_vinit_lj;

    /* InitializeConditions for DiscreteIntegrator: '<S411>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_nj =
      INS_P.DiscreteTimeIntegrator_IC_jj;

    /* InitializeConditions for Delay: '<S414>/Delay' */
    INS_DWork.Delay_DSTATE_g = INS_P.Delay_InitialCondition_h;

    /* End of SystemInitialize for SubSystem: '<S3>/ExternalPos_Process' */

    /* SystemInitialize for Atomic SubSystem: '<S3>/GPS_PreProcess' */
    /* InitializeConditions for UnitDelay: '<S428>/Unit Delay' */
    INS_DWork.UnitDelay_DSTATE = INS_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S431>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_i = INS_P.DetectChange_vinit_e;

    /* InitializeConditions for DiscreteIntegrator: '<S422>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_i =
      INS_P.DiscreteTimeIntegrator_IC_p;

    /* InitializeConditions for DiscreteIntegrator: '<S432>/Discrete-Time Integrator1' */
    INS_DWork.DiscreteTimeIntegrator1_PrevR_l = 0;
    INS_DWork.DiscreteTimeIntegrator1_IC_LO_j = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S433>/Discrete-Time Integrator1' */
    INS_DWork.DiscreteTimeIntegrator1_PrevR_j = 0;
    INS_DWork.DiscreteTimeIntegrator1_IC_LO_e = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S432>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_k =
      INS_P.DiscreteTimeIntegrator_IC_d;
    INS_DWork.DiscreteTimeIntegrator_PrevRe_a = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S433>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_l =
      INS_P.DiscreteTimeIntegrator_IC_f;
    INS_DWork.DiscreteTimeIntegrator_PrevRe_j = 0;

    /* SystemInitialize for Triggered SubSystem: '<S391>/WGS84_Model' */
    /* SystemInitialize for DataTypeConversion: '<S419>/Data Type Conversion' incorporates:
     *  Outport: '<S419>/lon_0_rad'
     */
    INS_B.DataTypeConversion = INS_P.lon_0_rad_Y0;

    /* SystemInitialize for DataTypeConversion: '<S419>/Data Type Conversion1' incorporates:
     *  Outport: '<S419>/lat_0_rad'
     */
    INS_B.DataTypeConversion1 = INS_P.lat_0_rad_Y0;

    /* SystemInitialize for Product: '<S435>/Product3' incorporates:
     *  Outport: '<S419>/dx_dlat'
     */
    INS_B.Rm = INS_P.dx_dlat_Y0;

    /* SystemInitialize for Product: '<S435>/Multiply2' incorporates:
     *  Outport: '<S419>/dy_dlon'
     */
    INS_B.Multiply2 = INS_P.dy_dlon_Y0;

    /* End of SystemInitialize for SubSystem: '<S391>/WGS84_Model' */
    /* End of SystemInitialize for SubSystem: '<S3>/GPS_PreProcess' */

    /* SystemInitialize for Atomic SubSystem: '<S3>/IMU_PreProcess' */
    /* InitializeConditions for UnitDelay: '<S439>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_h = INS_P.DetectChange_vinit_md;

    /* InitializeConditions for DiscreteIntegrator: '<S437>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_lp =
      INS_P.DiscreteTimeIntegrator_IC_ba;

    /* InitializeConditions for Delay: '<S440>/Delay' */
    INS_DWork.Delay_DSTATE_bw = INS_P.Delay_InitialCondition_ja;

    /* End of SystemInitialize for SubSystem: '<S3>/IMU_PreProcess' */

    /* SystemInitialize for Atomic SubSystem: '<S3>/MAG_PreProcess' */
    /* InitializeConditions for DiscreteIntegrator: '<S452>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE = INS_P.DiscreteTimeIntegrator_IC_mb;
    INS_DWork.DiscreteTimeIntegrator_PrevRe_k = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S452>/Discrete-Time Integrator1' */
    INS_DWork.DiscreteTimeIntegrator1_PrevRes = 0;
    INS_DWork.DiscreteTimeIntegrator1_IC_LOAD = 1U;

    /* InitializeConditions for UnitDelay: '<S459>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_n = INS_P.DetectChange_vinit_lp;

    /* InitializeConditions for DiscreteIntegrator: '<S445>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_lg =
      INS_P.DiscreteTimeIntegrator_IC_k;

    /* InitializeConditions for Delay: '<S460>/Delay' */
    INS_DWork.Delay_DSTATE_fp = INS_P.Delay_InitialCondition_jy;

    /* End of SystemInitialize for SubSystem: '<S3>/MAG_PreProcess' */

    /* SystemInitialize for Atomic SubSystem: '<S3>/Rangefinder_PreProcess' */
    /* InitializeConditions for UnitDelay: '<S477>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE = INS_P.DetectChange_vinit_c;

    /* InitializeConditions for DiscreteIntegrator: '<S473>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_e3 =
      INS_P.DiscreteTimeIntegrator_IC_f4;

    /* InitializeConditions for Delay: '<S478>/Delay' */
    INS_DWork.Delay_DSTATE_j = INS_P.Delay_InitialCondition_n;

    /* InitializeConditions for DiscreteIntegrator: '<S474>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_cv =
      INS_P.DiscreteTimeIntegrator_IC_n1;
    INS_DWork.DiscreteTimeIntegrator_PrevRese = 2;

    /* End of SystemInitialize for SubSystem: '<S3>/Rangefinder_PreProcess' */

    /* SystemInitialize for Atomic SubSystem: '<S3>/OpticalFlow_PreProcess' */
    /* InitializeConditions for DiscreteIntegrator: '<S466>/Discrete-Time Integrator5' */
    INS_DWork.DiscreteTimeIntegrator5_IC_LOAD = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S465>/Discrete-Time Integrator5' */
    INS_DWork.DiscreteTimeIntegrator5_IC_LO_o = 1U;

    /* InitializeConditions for UnitDelay: '<S469>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_k = INS_P.DetectChange_vinit_ju;

    /* InitializeConditions for DiscreteIntegrator: '<S463>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_g =
      INS_P.DiscreteTimeIntegrator_IC_n;

    /* InitializeConditions for Delay: '<S470>/Delay' */
    INS_DWork.Delay_DSTATE_c = INS_P.Delay_InitialCondition_f;

    /* End of SystemInitialize for SubSystem: '<S3>/OpticalFlow_PreProcess' */
    /* End of SystemInitialize for SubSystem: '<Root>/Sensor_PreProcess' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Data_Fusion' */
    /* InitializeConditions for Delay generated from: '<S56>/Delay' */
    INS_DWork.Delay_4_DSTATE_k = INS_P.Delay_4_InitialCondition;

    /* InitializeConditions for Delay generated from: '<S56>/Delay' */
    INS_DWork.Delay_5_DSTATE = INS_P.Delay_5_InitialCondition;

    /* InitializeConditions for Delay generated from: '<S56>/Delay' */
    INS_DWork.Delay_6_DSTATE = INS_P.Delay_6_InitialCondition;

    /* SystemInitialize for Atomic SubSystem: '<S55>/RF_Data_PreProcess' */
    /* InitializeConditions for UnitDelay: '<S135>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_pr = INS_P.DetectRisePositive_vinit_fc;

    /* InitializeConditions for Delay: '<S141>/Delay' */
    INS_DWork.Delay_DSTATE_i = INS_P.Delay_InitialCondition_n0;

    /* InitializeConditions for UnitDelay: '<S136>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_nk = INS_P.DetectRisePositive1_vinit;

    /* InitializeConditions for Delay: '<S142>/Delay' */
    INS_DWork.Delay_DSTATE_ly = INS_P.Delay_InitialCondition_m5;

    /* InitializeConditions for Delay: '<S137>/Delay' */
    INS_DWork.Delay_DSTATE_n = INS_P.Delay_InitialCondition_ij;

    /* InitializeConditions for UnitDelay: '<S145>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_mm = INS_P.DetectRisePositive1_vinit_b;

    /* InitializeConditions for DiscreteIntegrator: '<S191>/Discrete-Time Integrator5' */
    INS_DWork.DiscreteTimeIntegrator5_IC_LO_p = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S189>/Discrete-Time Integrator5' */
    INS_DWork.DiscreteTimeIntegrator5_IC_LO_n = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S190>/Discrete-Time Integrator5' */
    INS_DWork.DiscreteTimeIntegrator5_IC_L_ns = 1U;

    /* SystemInitialize for Enabled SubSystem: '<S58>/Initial_Attitude' */
    /* SystemInitialize for Merge: '<S151>/Merge' */
    INS_B.Merge_l[0] = INS_P.Merge_InitialOutput;

    /* SystemInitialize for SignalConversion generated from: '<S130>/quat_0' incorporates:
     *  Outport: '<S130>/quat_0'
     */
    INS_B.OutportBufferForquat_0[0] = INS_P.quat_0_Y0[0];

    /* SystemInitialize for Merge: '<S151>/Merge' */
    INS_B.Merge_l[1] = INS_P.Merge_InitialOutput;

    /* SystemInitialize for SignalConversion generated from: '<S130>/quat_0' incorporates:
     *  Outport: '<S130>/quat_0'
     */
    INS_B.OutportBufferForquat_0[1] = INS_P.quat_0_Y0[1];

    /* SystemInitialize for Merge: '<S151>/Merge' */
    INS_B.Merge_l[2] = INS_P.Merge_InitialOutput;

    /* SystemInitialize for SignalConversion generated from: '<S130>/quat_0' incorporates:
     *  Outport: '<S130>/quat_0'
     */
    INS_B.OutportBufferForquat_0[2] = INS_P.quat_0_Y0[2];

    /* SystemInitialize for Merge: '<S151>/Merge' */
    INS_B.Merge_l[3] = INS_P.Merge_InitialOutput;

    /* SystemInitialize for SignalConversion generated from: '<S130>/quat_0' incorporates:
     *  Outport: '<S130>/quat_0'
     */
    INS_B.OutportBufferForquat_0[3] = INS_P.quat_0_Y0[3];

    /* End of SystemInitialize for SubSystem: '<S58>/Initial_Attitude' */
    /* End of SystemInitialize for SubSystem: '<S55>/RF_Data_PreProcess' */

    /* SystemInitialize for Atomic SubSystem: '<S55>/AHRS' */
    /* SystemInitialize for Atomic SubSystem: '<S57>/Update' */
    /* InitializeConditions for Delay: '<S114>/Delay1' */
    INS_DWork.icLoad_o2 = true;

    /* End of SystemInitialize for SubSystem: '<S57>/Update' */

    /* InitializeConditions for Delay: '<S57>/Delay1' */
    INS_DWork.Delay1_DSTATE_h[0] = INS_P.Delay1_InitialCondition_h;

    /* InitializeConditions for Delay: '<S57>/Delay2' */
    INS_DWork.Delay2_DSTATE[0] = INS_P.Delay2_InitialCondition;

    /* SystemInitialize for Atomic SubSystem: '<S57>/Update' */
    /* InitializeConditions for DiscreteIntegrator: '<S115>/Discrete-Time Integrator2' */
    INS_DWork.DiscreteTimeIntegrator2_DSTATE[0] =
      INS_P.DiscreteTimeIntegrator2_IC;

    /* End of SystemInitialize for SubSystem: '<S57>/Update' */

    /* InitializeConditions for Delay: '<S57>/Delay1' */
    INS_DWork.Delay1_DSTATE_h[1] = INS_P.Delay1_InitialCondition_h;

    /* InitializeConditions for Delay: '<S57>/Delay2' */
    INS_DWork.Delay2_DSTATE[1] = INS_P.Delay2_InitialCondition;

    /* SystemInitialize for Atomic SubSystem: '<S57>/Update' */
    /* InitializeConditions for DiscreteIntegrator: '<S115>/Discrete-Time Integrator2' */
    INS_DWork.DiscreteTimeIntegrator2_DSTATE[1] =
      INS_P.DiscreteTimeIntegrator2_IC;

    /* End of SystemInitialize for SubSystem: '<S57>/Update' */

    /* InitializeConditions for Delay: '<S57>/Delay1' */
    INS_DWork.Delay1_DSTATE_h[2] = INS_P.Delay1_InitialCondition_h;

    /* InitializeConditions for Delay: '<S57>/Delay2' */
    INS_DWork.Delay2_DSTATE[2] = INS_P.Delay2_InitialCondition;

    /* SystemInitialize for Atomic SubSystem: '<S57>/Update' */
    /* InitializeConditions for DiscreteIntegrator: '<S115>/Discrete-Time Integrator2' */
    INS_DWork.DiscreteTimeIntegrator2_DSTATE[2] =
      INS_P.DiscreteTimeIntegrator2_IC;

    /* End of SystemInitialize for SubSystem: '<S57>/Update' */

    /* SystemInitialize for Atomic SubSystem: '<S57>/Correct' */
    /* InitializeConditions for DiscreteIntegrator: '<S89>/Discrete-Time Integrator1' */
    INS_DWork.DiscreteTimeIntegrator1_PrevR_p = 0;
    INS_DWork.DiscreteTimeIntegrator1_IC_LO_i = 1U;

    /* InitializeConditions for Delay: '<S87>/Delay' */
    for (i = 0; i < 600; i++) {
      INS_DWork.Delay_DSTATE_lv[i] = INS_P.Delay_InitialCondition_m;
    }

    /* End of InitializeConditions for Delay: '<S87>/Delay' */

    /* InitializeConditions for UnitDelay: '<S91>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_ff = INS_P.DetectIncrease_vinit_b;

    /* InitializeConditions for DiscreteIntegrator: '<S89>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_PrevRe_f = 0;

    /* InitializeConditions for Delay: '<S94>/Delay' */
    INS_DWork.Delay_DSTATE_b3 = INS_P.Delay_InitialCondition_d;

    /* InitializeConditions for UnitDelay: '<S97>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_ii = INS_P.DetectIncrease_vinit_i;

    /* InitializeConditions for DiscreteIntegrator: '<S105>/Discrete-Time Integrator1' */
    INS_DWork.DiscreteTimeIntegrator1_PrevR_m = 0;
    INS_DWork.DiscreteTimeIntegrator1_IC_LO_m = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S99>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_d =
      INS_P.DiscreteTimeIntegrator_IC_io;
    INS_DWork.DiscreteTimeIntegrator_PrevRe_n = 0;

    /* InitializeConditions for UnitDelay: '<S109>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_d2 = INS_P.DetectIncrease_vinit_d;

    /* InitializeConditions for Delay: '<S106>/Delay' */
    INS_DWork.Delay_DSTATE_lt = INS_P.Delay_InitialCondition_i;

    /* InitializeConditions for DiscreteIntegrator: '<S105>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_PrevRe_e = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S112>/Discrete-Time Integrator1' */
    INS_DWork.DiscreteTimeIntegrator1_PrevR_o = 0;
    INS_DWork.DiscreteTimeIntegrator1_IC_LO_l = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S112>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_PrevR_nh = 0;

    /* SystemInitialize for Enabled SubSystem: '<S88>/GPS_Meas_Acc' */
    /* InitializeConditions for DiscreteIntegrator: '<S92>/Integrator' */
    INS_DWork.Integrator_PrevResetState = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S92>/Integrator1' */
    INS_DWork.Integrator1_PrevResetState = 0;
    INS_DWork.Integrator1_IC_LOADING = 1U;

    /* End of SystemInitialize for SubSystem: '<S88>/GPS_Meas_Acc' */

    /* InitializeConditions for DiscreteIntegrator: '<S89>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_lq[0] =
      INS_P.DiscreteTimeIntegrator_IC_a;

    /* InitializeConditions for DiscreteIntegrator: '<S105>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_hs[0] =
      INS_P.DiscreteTimeIntegrator_IC_el;

    /* InitializeConditions for DiscreteIntegrator: '<S112>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_ce[0] =
      INS_P.DiscreteTimeIntegrator_IC_m;

    /* SystemInitialize for Enabled SubSystem: '<S88>/GPS_Meas_Acc' */
    /* InitializeConditions for DiscreteIntegrator: '<S92>/Integrator' */
    INS_DWork.Integrator_DSTATE[0] = INS_P.Integrator_IC;

    /* SystemInitialize for DiscreteIntegrator: '<S92>/Integrator' incorporates:
     *  Outport: '<S92>/gps_acc_O_mPs2'
     */
    INS_B.Integrator[0] = INS_P.gps_acc_O_mPs2_Y0;

    /* End of SystemInitialize for SubSystem: '<S88>/GPS_Meas_Acc' */

    /* InitializeConditions for DiscreteIntegrator: '<S89>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_lq[1] =
      INS_P.DiscreteTimeIntegrator_IC_a;

    /* InitializeConditions for DiscreteIntegrator: '<S105>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_hs[1] =
      INS_P.DiscreteTimeIntegrator_IC_el;

    /* InitializeConditions for DiscreteIntegrator: '<S112>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_ce[1] =
      INS_P.DiscreteTimeIntegrator_IC_m;

    /* SystemInitialize for Enabled SubSystem: '<S88>/GPS_Meas_Acc' */
    /* InitializeConditions for DiscreteIntegrator: '<S92>/Integrator' */
    INS_DWork.Integrator_DSTATE[1] = INS_P.Integrator_IC;

    /* SystemInitialize for DiscreteIntegrator: '<S92>/Integrator' incorporates:
     *  Outport: '<S92>/gps_acc_O_mPs2'
     */
    INS_B.Integrator[1] = INS_P.gps_acc_O_mPs2_Y0;

    /* End of SystemInitialize for SubSystem: '<S88>/GPS_Meas_Acc' */

    /* InitializeConditions for DiscreteIntegrator: '<S89>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_lq[2] =
      INS_P.DiscreteTimeIntegrator_IC_a;

    /* InitializeConditions for DiscreteIntegrator: '<S105>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_hs[2] =
      INS_P.DiscreteTimeIntegrator_IC_el;

    /* InitializeConditions for DiscreteIntegrator: '<S112>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_ce[2] =
      INS_P.DiscreteTimeIntegrator_IC_m;

    /* SystemInitialize for Enabled SubSystem: '<S88>/GPS_Meas_Acc' */
    /* InitializeConditions for DiscreteIntegrator: '<S92>/Integrator' */
    INS_DWork.Integrator_DSTATE[2] = INS_P.Integrator_IC;

    /* SystemInitialize for DiscreteIntegrator: '<S92>/Integrator' incorporates:
     *  Outport: '<S92>/gps_acc_O_mPs2'
     */
    INS_B.Integrator[2] = INS_P.gps_acc_O_mPs2_Y0;

    /* End of SystemInitialize for SubSystem: '<S88>/GPS_Meas_Acc' */
    /* End of SystemInitialize for SubSystem: '<S57>/Correct' */
    /* End of SystemInitialize for SubSystem: '<S55>/AHRS' */

    /* SystemInitialize for Atomic SubSystem: '<S56>/TF_Data_PreProcess' */
    /* InitializeConditions for DiscreteIntegrator: '<S326>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_f =
      INS_P.DiscreteTimeIntegrator_IC_c;
    INS_DWork.DiscreteTimeIntegrator_PrevRe_h = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S326>/Discrete-Time Integrator1' */
    INS_DWork.DiscreteTimeIntegrator1_PrevR_d = 0;
    INS_DWork.DiscreteTimeIntegrator1_IC_LO_k = 1U;

    /* InitializeConditions for Delay: '<S329>/Delay' */
    INS_DWork.Delay_DSTATE_n2 = INS_P.Delay_InitialCondition_o;

    /* InitializeConditions for UnitDelay: '<S332>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_ic = INS_P.DetectDecrease_vinit;

    /* InitializeConditions for Delay: '<S330>/Delay' */
    INS_DWork.Delay_DSTATE_a = INS_P.Delay_InitialCondition_m0;

    /* InitializeConditions for UnitDelay: '<S333>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_cz = INS_P.DetectIncrease_vinit_dy;

    /* InitializeConditions for Delay: '<S334>/Delay' */
    INS_DWork.Delay_DSTATE_e = INS_P.Delay_InitialCondition_du;

    /* InitializeConditions for UnitDelay: '<S344>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_o = INS_P.DetectRisePositive_vinit_me;

    /* InitializeConditions for DiscreteIntegrator: '<S351>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_b =
      INS_P.DiscreteTimeIntegrator_IC_g;
    INS_DWork.DiscreteTimeIntegrator_PrevR_ky = 0;

    /* InitializeConditions for UnitDelay: '<S360>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_hg = INS_P.DetectRisePositive_vinit_o;

    /* InitializeConditions for Delay: '<S351>/Delay' */
    INS_DWork.Delay_DSTATE_kh = INS_P.Delay_InitialCondition_in;

    /* InitializeConditions for UnitDelay: '<S345>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_j = INS_P.DetectRisePositive1_vinit_h;

    /* InitializeConditions for DiscreteIntegrator: '<S363>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_c =
      INS_P.DiscreteTimeIntegrator_IC_lb;
    INS_DWork.DiscreteTimeIntegrator_PrevRe_l = 0;

    /* InitializeConditions for UnitDelay: '<S373>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_p = INS_P.DetectRisePositive_vinit_h;

    /* InitializeConditions for Delay: '<S363>/Delay' */
    INS_DWork.Delay_DSTATE_k4 = INS_P.Delay_InitialCondition_ns;

    /* InitializeConditions for DiscreteIntegrator: '<S350>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_n =
      INS_P.DiscreteTimeIntegrator_IC_b;
    INS_DWork.DiscreteTimeIntegrator_PrevRe_d = 0;

    /* InitializeConditions for Delay: '<S350>/Delay' */
    INS_DWork.Delay_DSTATE_ng = INS_P.Delay_InitialCondition_k;

    /* InitializeConditions for UnitDelay: '<S355>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_kh = INS_P.DetectRisePositive_vinit_d;

    /* InitializeConditions for DiscreteIntegrator: '<S362>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_h =
      INS_P.DiscreteTimeIntegrator_IC_h;
    INS_DWork.DiscreteTimeIntegrator_PrevRe_b = 0;

    /* InitializeConditions for Delay: '<S362>/Delay' */
    INS_DWork.Delay_DSTATE_c1 = INS_P.Delay_InitialCondition_dh;

    /* InitializeConditions for UnitDelay: '<S368>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_ch = INS_P.DetectRisePositive_vinit_dn;

    /* InitializeConditions for DiscreteIntegrator: '<S364>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_k3 =
      INS_P.DiscreteTimeIntegrator_IC_ms;
    INS_DWork.DiscreteTimeIntegrator_PrevR_kt = 0;

    /* InitializeConditions for Delay: '<S364>/Delay' */
    INS_DWork.Delay_DSTATE_n2o = INS_P.Delay_InitialCondition_ia;

    /* InitializeConditions for UnitDelay: '<S378>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_jx = INS_P.DetectRisePositive_vinit_cj;

    /* InitializeConditions for Delay: '<S382>/Delay1' */
    INS_DWork.Delay1_DSTATE = INS_P.Delay1_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S384>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_dp = INS_P.DetectRisePositive3_vinit;

    /* InitializeConditions for Delay: '<S383>/Delay' */
    INS_DWork.Delay_DSTATE[0] = INS_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S383>/Delay1' */
    INS_DWork.Delay1_DSTATE_o[0] = INS_P.Delay1_InitialCondition_e;

    /* InitializeConditions for Delay: '<S383>/Delay' */
    INS_DWork.Delay_DSTATE[1] = INS_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S383>/Delay1' */
    INS_DWork.Delay1_DSTATE_o[1] = INS_P.Delay1_InitialCondition_e;

    /* InitializeConditions for UnitDelay: '<S386>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_mw = INS_P.DetectRisePositive3_vinit_h;

    /* End of SystemInitialize for SubSystem: '<S56>/TF_Data_PreProcess' */

    /* SystemInitialize for Atomic SubSystem: '<S56>/CF' */
    /* InitializeConditions for Delay: '<S290>/Delay' */
    INS_DWork.Delay_DSTATE_b[0] = INS_P.Delay_InitialCondition_mt;
    INS_DWork.Delay_DSTATE_b[1] = INS_P.Delay_InitialCondition_mt;
    INS_DWork.Delay_DSTATE_b[2] = INS_P.Delay_InitialCondition_mt;

    /* SystemInitialize for Merge: '<S293>/Merge' */
    INS_B.Merge = INS_P.Merge_InitialOutput_g;

    /* SystemInitialize for Merge: '<S294>/Merge' */
    INS_B.Merge_e = INS_P.Merge_InitialOutput_d;

    /* SystemInitialize for Enabled SubSystem: '<S247>/Baro_Correct' */
    /* InitializeConditions for UnitDelay: '<S252>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_lg = INS_P.DetectChange_vinit_m;

    /* InitializeConditions for Delay: '<S253>/Delay' */
    INS_DWork.Delay_DSTATE_dr[0] = INS_P.Delay_InitialCondition_j;
    INS_DWork.Delay_DSTATE_dr[1] = INS_P.Delay_InitialCondition_j;
    INS_DWork.Delay_DSTATE_dr[2] = INS_P.Delay_InitialCondition_j;

    /* InitializeConditions for Delay: '<S255>/x_delay' */
    INS_DWork.icLoad_a = true;

    /* InitializeConditions for UnitDelay: '<S259>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_f = INS_P.DetectIncrease_vinit_c;

    /* InitializeConditions for Delay: '<S257>/Delay' */
    INS_DWork.Delay_DSTATE_h = INS_P.Delay_InitialCondition_mk;

    /* SystemInitialize for Outport: '<S251>/X_Next' incorporates:
     *  Sum: '<S251>/Sum1'
     */
    INS_B.Sum1_pu[0] = INS_P.X_Next_Y0_m;
    INS_B.Sum1_pu[1] = INS_P.X_Next_Y0_m;

    /* SystemInitialize for Saturate: '<S251>/Saturation' incorporates:
     *  Outport: '<S251>/X_Next'
     */
    INS_B.Saturation = INS_P.X_Next_Y0_m;

    /* End of SystemInitialize for SubSystem: '<S247>/Baro_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S249>/GPS_Correct' */
    /* InitializeConditions for UnitDelay: '<S270>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_d = INS_P.DetectChange_vinit_h;

    /* InitializeConditions for Delay: '<S273>/h_delay' */
    INS_DWork.icLoad_o = true;

    /* InitializeConditions for Delay: '<S273>/vd_delay' */
    INS_DWork.icLoad_f = true;

    /* InitializeConditions for UnitDelay: '<S277>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_ib = INS_P.DetectIncrease_vinit_ji;

    /* InitializeConditions for Memory: '<S275>/Memory' */
    INS_DWork.Memory_PreviousInput_b = INS_P.Memory_InitialCondition_p;

    /* End of SystemInitialize for SubSystem: '<S249>/GPS_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S250>/Rangefinder_Correct' */
    /* InitializeConditions for UnitDelay: '<S279>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_l = INS_P.DetectChange_vinit_g;

    /* InitializeConditions for Delay: '<S282>/h_delay' */
    INS_DWork.icLoad = true;

    /* InitializeConditions for UnitDelay: '<S286>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_oe = INS_P.DetectIncrease_vinit_a;

    /* InitializeConditions for Delay: '<S287>/Delay' */
    INS_DWork.Delay_DSTATE_f = INS_P.Delay_InitialCondition_dc;

    /* InitializeConditions for Delay: '<S287>/Delay1' */
    INS_DWork.icLoad_b = true;

    /* InitializeConditions for UnitDelay: '<S289>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_m = INS_P.DetectIncrease_vinit;

    /* InitializeConditions for Delay: '<S287>/Delay2' */
    INS_DWork.Delay2_DSTATE_o = INS_P.Delay2_InitialCondition_o;

    /* InitializeConditions for Memory: '<S284>/Memory' */
    INS_DWork.Memory_PreviousInput = INS_P.Memory_InitialCondition_g;

    /* SystemInitialize for Switch: '<S284>/Switch' incorporates:
     *  Outport: '<S278>/rf_bias'
     */
    INS_B.rf_height_bias = INS_P.rf_bias_Y0;

    /* End of SystemInitialize for SubSystem: '<S250>/Rangefinder_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S248>/ExternalPos_Correct' */
    /* InitializeConditions for UnitDelay: '<S261>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_a = INS_P.DetectChange_vinit_j;

    /* InitializeConditions for Delay: '<S264>/x_delay' */
    INS_DWork.icLoad_p = true;

    /* InitializeConditions for UnitDelay: '<S268>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_a4 = INS_P.DetectIncrease_vinit_j;

    /* InitializeConditions for Delay: '<S266>/Delay' */
    INS_DWork.Delay_DSTATE_m = INS_P.Delay_InitialCondition_d2;

    /* End of SystemInitialize for SubSystem: '<S248>/ExternalPos_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S249>/GPS_Correct' */
    /* InitializeConditions for Memory: '<S271>/Memory' */
    INS_DWork.Memory_PreviousInput_e[0] = INS_P.Memory_InitialCondition_c;

    /* SystemInitialize for Sum: '<S269>/Sum1' incorporates:
     *  Outport: '<S269>/X_Next'
     */
    INS_B.Sum1_p[0] = INS_P.X_Next_Y0_i;

    /* End of SystemInitialize for SubSystem: '<S249>/GPS_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S250>/Rangefinder_Correct' */
    /* InitializeConditions for Memory: '<S280>/Memory' */
    INS_DWork.Memory_PreviousInput_f[0] = INS_P.Memory_InitialCondition_h;

    /* SystemInitialize for Sum: '<S278>/Sum1' incorporates:
     *  Outport: '<S278>/X_Next'
     */
    INS_B.Sum1[0] = INS_P.X_Next_Y0_mm;

    /* End of SystemInitialize for SubSystem: '<S250>/Rangefinder_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S248>/ExternalPos_Correct' */
    /* InitializeConditions for Delay: '<S262>/Delay' */
    INS_DWork.Delay_DSTATE_p[0] = INS_P.Delay_InitialCondition_ms;

    /* SystemInitialize for Sum: '<S260>/Sum1' incorporates:
     *  Outport: '<S260>/X_Next'
     */
    INS_B.Sum1_c[0] = INS_P.X_Next_Y0_j;

    /* End of SystemInitialize for SubSystem: '<S248>/ExternalPos_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S249>/GPS_Correct' */
    /* InitializeConditions for Memory: '<S271>/Memory' */
    INS_DWork.Memory_PreviousInput_e[1] = INS_P.Memory_InitialCondition_c;

    /* SystemInitialize for Sum: '<S269>/Sum1' incorporates:
     *  Outport: '<S269>/X_Next'
     */
    INS_B.Sum1_p[1] = INS_P.X_Next_Y0_i;

    /* End of SystemInitialize for SubSystem: '<S249>/GPS_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S250>/Rangefinder_Correct' */
    /* InitializeConditions for Memory: '<S280>/Memory' */
    INS_DWork.Memory_PreviousInput_f[1] = INS_P.Memory_InitialCondition_h;

    /* SystemInitialize for Sum: '<S278>/Sum1' incorporates:
     *  Outport: '<S278>/X_Next'
     */
    INS_B.Sum1[1] = INS_P.X_Next_Y0_mm;

    /* End of SystemInitialize for SubSystem: '<S250>/Rangefinder_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S248>/ExternalPos_Correct' */
    /* InitializeConditions for Delay: '<S262>/Delay' */
    INS_DWork.Delay_DSTATE_p[1] = INS_P.Delay_InitialCondition_ms;

    /* SystemInitialize for Sum: '<S260>/Sum1' incorporates:
     *  Outport: '<S260>/X_Next'
     */
    INS_B.Sum1_c[1] = INS_P.X_Next_Y0_j;

    /* End of SystemInitialize for SubSystem: '<S248>/ExternalPos_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S249>/GPS_Correct' */
    /* InitializeConditions for Memory: '<S271>/Memory' */
    INS_DWork.Memory_PreviousInput_e[2] = INS_P.Memory_InitialCondition_c;

    /* SystemInitialize for Sum: '<S269>/Sum1' incorporates:
     *  Outport: '<S269>/X_Next'
     */
    INS_B.Sum1_p[2] = INS_P.X_Next_Y0_i;

    /* End of SystemInitialize for SubSystem: '<S249>/GPS_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S250>/Rangefinder_Correct' */
    /* InitializeConditions for Memory: '<S280>/Memory' */
    INS_DWork.Memory_PreviousInput_f[2] = INS_P.Memory_InitialCondition_h;

    /* SystemInitialize for Sum: '<S278>/Sum1' incorporates:
     *  Outport: '<S278>/X_Next'
     */
    INS_B.Sum1[2] = INS_P.X_Next_Y0_mm;

    /* End of SystemInitialize for SubSystem: '<S250>/Rangefinder_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S248>/ExternalPos_Correct' */
    /* InitializeConditions for Delay: '<S262>/Delay' */
    INS_DWork.Delay_DSTATE_p[2] = INS_P.Delay_InitialCondition_ms;

    /* SystemInitialize for Sum: '<S260>/Sum1' incorporates:
     *  Outport: '<S260>/X_Next'
     */
    INS_B.Sum1_c[2] = INS_P.X_Next_Y0_j;

    /* End of SystemInitialize for SubSystem: '<S248>/ExternalPos_Correct' */

    /* SystemInitialize for Merge: '<S239>/Merge' */
    INS_B.Merge_g[0] = INS_P.Merge_InitialOutput_o;

    /* SystemInitialize for Merge: '<S240>/Merge' */
    INS_B.Merge_n[0] = INS_P.Merge_InitialOutput_c;

    /* SystemInitialize for Merge: '<S239>/Merge' */
    INS_B.Merge_g[1] = INS_P.Merge_InitialOutput_o;

    /* SystemInitialize for Merge: '<S240>/Merge' */
    INS_B.Merge_n[1] = INS_P.Merge_InitialOutput_c;

    /* SystemInitialize for Enabled SubSystem: '<S210>/OptFlow_Correct' */
    /* InitializeConditions for UnitDelay: '<S231>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_ml = INS_P.DetectChange_vinit_l;

    /* InitializeConditions for Delay: '<S234>/vn_delay' */
    INS_DWork.icLoad_h = true;

    /* InitializeConditions for Delay: '<S234>/ve_delay' */
    INS_DWork.icLoad_j = true;

    /* End of SystemInitialize for SubSystem: '<S210>/OptFlow_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S209>/GPS_Correct' */
    /* InitializeConditions for UnitDelay: '<S221>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_d0 = INS_P.DetectChange_vinit_i;

    /* InitializeConditions for Delay: '<S224>/x_delay' */
    INS_DWork.icLoad_op = true;

    /* InitializeConditions for Delay: '<S224>/x_delay1' */
    INS_DWork.icLoad_i = true;

    /* InitializeConditions for Delay: '<S224>/vn_delay' */
    INS_DWork.icLoad_m = true;

    /* InitializeConditions for Delay: '<S224>/vn_delay1' */
    INS_DWork.icLoad_jp = true;

    /* InitializeConditions for UnitDelay: '<S229>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_gn = INS_P.DetectIncrease_vinit_p;

    /* InitializeConditions for Memory: '<S227>/Memory' */
    INS_DWork.Memory_PreviousInput_d[0] = INS_P.Memory_InitialCondition_l[0];
    INS_DWork.Memory_PreviousInput_d[1] = INS_P.Memory_InitialCondition_l[1];

    /* End of SystemInitialize for SubSystem: '<S209>/GPS_Correct' */

    /* SystemInitialize for Enabled SubSystem: '<S208>/ExternalPos_Correct' */
    /* InitializeConditions for UnitDelay: '<S212>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_no = INS_P.DetectChange_vinit;

    /* InitializeConditions for Delay: '<S215>/x_delay' */
    INS_DWork.icLoad_hw = true;

    /* InitializeConditions for Delay: '<S215>/y_delay' */
    INS_DWork.icLoad_od = true;

    /* InitializeConditions for UnitDelay: '<S219>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_dp5 = INS_P.DetectIncrease_vinit_m;

    /* InitializeConditions for Delay: '<S217>/Delay' */
    INS_DWork.Delay_DSTATE_k[0] = INS_P.Delay_InitialCondition_e;
    INS_DWork.Delay_DSTATE_k[1] = INS_P.Delay_InitialCondition_e;

    /* SystemInitialize for Enabled SubSystem: '<S209>/GPS_Correct' */
    /* SystemInitialize for Enabled SubSystem: '<S210>/OptFlow_Correct' */
    for (i = 0; i < 6; i++) {
      /* InitializeConditions for Delay: '<S236>/Delay' */
      INS_DWork.Delay_DSTATE_l[i] = INS_P.Delay_InitialCondition_g;

      /* InitializeConditions for Memory: '<S232>/Memory' */
      INS_DWork.Memory_PreviousInput_n[i] = INS_P.Memory_InitialCondition_i;

      /* SystemInitialize for Sum: '<S230>/Sum1' incorporates:
       *  Outport: '<S230>/X_Next'
       */
      INS_B.Sum1_f[i] = INS_P.X_Next_Y0_k;

      /* InitializeConditions for Memory: '<S222>/Memory' */
      INS_DWork.Memory_PreviousInput_h[i] = INS_P.Memory_InitialCondition_o;

      /* SystemInitialize for Sum: '<S220>/Sum1' incorporates:
       *  Outport: '<S220>/X_Next'
       */
      INS_B.Sum1_o[i] = INS_P.X_Next_Y0_c;

      /* InitializeConditions for Memory: '<S213>/Memory' */
      INS_DWork.Memory_PreviousInput_m[i] = INS_P.Memory_InitialCondition;

      /* SystemInitialize for Sum: '<S211>/Sum1' incorporates:
       *  Outport: '<S211>/X_Next'
       */
      INS_B.Sum1_b[i] = INS_P.X_Next_Y0;
    }

    /* End of SystemInitialize for SubSystem: '<S210>/OptFlow_Correct' */
    /* End of SystemInitialize for SubSystem: '<S209>/GPS_Correct' */
    /* End of SystemInitialize for SubSystem: '<S208>/ExternalPos_Correct' */
    /* End of SystemInitialize for SubSystem: '<S56>/CF' */
    /* End of SystemInitialize for SubSystem: '<Root>/Data_Fusion' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Bus_Constructor' */
    /* SystemInitialize for Atomic SubSystem: '<S1>/Counter' */
    /* InitializeConditions for UnitDelay: '<S4>/Output' */
    INS_DWork.Output_DSTATE = INS_P.Output_InitialCondition;

    /* End of SystemInitialize for SubSystem: '<S1>/Counter' */

    /* SystemInitialize for Atomic SubSystem: '<S1>/Status_Output' */
    /* InitializeConditions for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_bo = INS_P.DiscreteTimeIntegrator_IC;
    INS_DWork.DiscreteTimeIntegrator_PrevR_nf = 0;

    /* InitializeConditions for Delay: '<S12>/Delay' */
    INS_DWork.Delay_DSTATE_bn = INS_P.Delay_InitialCondition_go;

    /* InitializeConditions for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_hi =
      INS_P.DiscreteTimeIntegrator_IC_i;
    INS_DWork.DiscreteTimeIntegrator_PrevRe_m = 0;

    /* InitializeConditions for Delay: '<S15>/Delay' */
    INS_DWork.Delay_DSTATE_cx = INS_P.Delay_InitialCondition_mz;

    /* InitializeConditions for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_b3 =
      INS_P.DiscreteTimeIntegrator_IC_o;
    INS_DWork.DiscreteTimeIntegrator_PrevR_dj = 0;

    /* InitializeConditions for Delay: '<S17>/Delay' */
    INS_DWork.Delay_DSTATE_l0 = INS_P.Delay_InitialCondition_a;

    /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_ca =
      INS_P.DiscreteTimeIntegrator_IC_l;
    INS_DWork.DiscreteTimeIntegrator_PrevR_h1 = 0;

    /* InitializeConditions for Delay: '<S11>/Delay' */
    INS_DWork.Delay_DSTATE_cn = INS_P.Delay_InitialCondition_c;

    /* InitializeConditions for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_e =
      INS_P.DiscreteTimeIntegrator_IC_j;
    INS_DWork.DiscreteTimeIntegrator_PrevR_as = 0;

    /* InitializeConditions for Delay: '<S13>/Delay' */
    INS_DWork.Delay_DSTATE_pk = INS_P.Delay_InitialCondition_cj;

    /* InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTAT_kg =
      INS_P.DiscreteTimeIntegrator_IC_ig;
    INS_DWork.DiscreteTimeIntegrator_PrevRe_o = 0;

    /* InitializeConditions for Delay: '<S14>/Delay' */
    INS_DWork.Delay_DSTATE_db = INS_P.Delay_InitialCondition_ae;

    /* InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
    INS_DWork.DiscreteTimeIntegrator_DSTATE_a =
      INS_P.DiscreteTimeIntegrator_IC_e;
    INS_DWork.DiscreteTimeIntegrator_PrevR_ar = 0;

    /* InitializeConditions for Delay: '<S16>/Delay' */
    INS_DWork.Delay_DSTATE_lyf = INS_P.Delay_InitialCondition_em;

    /* InitializeConditions for UnitDelay: '<S21>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_dx = INS_P.DetectRisePositive_vinit;

    /* InitializeConditions for UnitDelay: '<S26>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_mu = INS_P.DetectRisePositive_vinit_c;

    /* InitializeConditions for UnitDelay: '<S31>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_dq = INS_P.DetectRisePositive_vinit_m;

    /* InitializeConditions for UnitDelay: '<S36>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_f4 = INS_P.DetectRisePositive_vinit_k;

    /* InitializeConditions for UnitDelay: '<S41>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_ng = INS_P.DetectRisePositive_vinit_a;

    /* InitializeConditions for UnitDelay: '<S46>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_dql = INS_P.DetectRisePositive_vinit_f;

    /* InitializeConditions for UnitDelay: '<S51>/Delay Input1' */
    INS_DWork.DelayInput1_DSTATE_fq = INS_P.DetectRisePositive_vinit_l;

    /* End of SystemInitialize for SubSystem: '<S1>/Status_Output' */
    /* End of SystemInitialize for SubSystem: '<Root>/Bus_Constructor' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
