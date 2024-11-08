/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 13.0
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Sat Nov  2 09:12:11 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: RISC-V->RV32I
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Controller.h"
#include "Controller_types.h"
#include "csi_math.h"
#include <math.h>
#include "rtwtypes.h"
#include <string.h>
#include "Controller_private.h"

/* Exported block parameters */
struct_2EnWz3ceFwjQa7SDRNn3C CONTROL_PARAM = {
  1.4F,
  0.2F,
  0.2F,
  0.6F,
  0.1F,
  0.0F,
  -1.0F,
  1.0F,
  -1.0F,
  1.0F,
  -0.15F,
  0.15F,
  -0.1F,
  0.1F,
  5.0F,
  5.0F,
  0.52359879F,
  0.1F,
  0.1F,
  0.15F,
  0.1F,
  0.1F,
  0.2F,
  0.003F,
  0.003F,
  0.001F,
  -0.1F,
  0.1F,
  -0.1F,
  0.1F,
  1.57079637F,
  3.14159274F,
  0.5F
} ;                                    /* Variable: CONTROL_PARAM
                                        * Referenced by:
                                        *   '<S17>/hover_throttle'
                                        *   '<S23>/hover_throttle'
                                        *   '<S29>/hover_throttle'
                                        *   '<S35>/hover_throttle'
                                        *   '<S41>/hover_throttle'
                                        *   '<S47>/hover_throttle'
                                        *   '<S53>/hover_throttle'
                                        *   '<S59>/hover_throttle'
                                        *   '<S92>/Saturation'
                                        *   '<S68>/Saturation'
                                        *   '<S68>/Saturation1'
                                        *   '<S101>/kd'
                                        *   '<S101>/Saturation'
                                        *   '<S102>/ki'
                                        *   '<S102>/Discrete-Time Integrator'
                                        *   '<S103>/kp'
                                        *   '<S115>/kd'
                                        *   '<S115>/Saturation'
                                        *   '<S116>/Constant'
                                        *   '<S116>/ki'
                                        *   '<S116>/Discrete-Time Integrator'
                                        *   '<S117>/kp'
                                        *   '<S85>/Constant1'
                                        *   '<S85>/Constant2'
                                        *   '<S74>/gain1'
                                        *   '<S74>/gain2'
                                        *   '<S74>/gain3'
                                        *   '<S74>/Saturation'
                                        *   '<S75>/gain1'
                                        *   '<S75>/gain2'
                                        *   '<S75>/gain3'
                                        *   '<S75>/Discrete-Time Integrator'
                                        *   '<S76>/gain1'
                                        *   '<S76>/gain2'
                                        *   '<S76>/gain3'
                                        */

struct_ny3PY9hontv4J5WqwlFzJB CONTROL_EXPORT = {
  4U,

  { 77, 67, 32, 67, 111, 110, 116, 114, 111, 108, 108, 101, 114, 32, 118, 49, 46,
    48, 46, 48, 0 }
} ;                                    /* Variable: CONTROL_EXPORT
                                        * Referenced by: '<S3>/Constant'
                                        */

/* Block states (default storage) */
DW_Controller_T Controller_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Controller_T Controller_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Controller_T Controller_Y;

/* Real-time model */
static RT_MODEL_Controller_T Controller_M_;
RT_MODEL_Controller_T *const Controller_M = &Controller_M_;
const Control_Out_Bus Controller_rtZControl_Out_Bus = { 0U,/* timestamp */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }/* actuator_cmd */
};

/* Model step function */
void Controller_step(void)
{
  real32_T rtb_VectorConcatenate[9];
  real32_T rtb_Add3;
  real32_T rtb_Gain_fl;
  real32_T rtb_Gain_g2;
  real32_T rtb_Subtract3_i;

#if AIRFRAME == 6

  uint16_T rtb_MultiportSwitch_p[12];

#endif

#if (AIRFRAME == 3) || (AIRFRAME == 7) || (AIRFRAME == 8)

  uint16_T rtb_MultiportSwitch_ev[8];

#endif

#if (AIRFRAME == 1) || (AIRFRAME == 2) || (AIRFRAME == 3) || (AIRFRAME == 4) || (AIRFRAME == 5) || (AIRFRAME == 6) || (AIRFRAME == 7) || (AIRFRAME == 8)

  uint16_T rtb_throttle_cmd_f;

#endif

#if (AIRFRAME == 4) || (AIRFRAME == 5)

  uint16_T rtb_MultiportSwitch_i[6];

#endif

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  uint16_T rtb_MultiportSwitch_b0[4];

#endif

  int32_T i;
  int32_T rtb_uv_error_C_mPs_0;
  real32_T rtb_VectorConcatenate_0[3];
  real32_T rtb_Add_g_idx_0;
  real32_T rtb_Gain_idx_0;
  real32_T rtb_Gain_idx_1;
  real32_T rtb_Multiply_lq_idx_1;
  real32_T rtb_Multiply_lq_idx_2;
  real32_T rtb_Saturation1_is_idx_0;
  real32_T rtb_Saturation_d_idx_0;
  real32_T rtb_Saturation_d_idx_1;
  real32_T rtb_Saturation_d_idx_2;
  real32_T rtb_Saturation_idx_0;
  real32_T rtb_Saturation_idx_1;
  real32_T rtb_Subtract3_idx_0;
  real32_T rtb_Subtract3_idx_1;
  real32_T rtb_a_n;
  real32_T rtb_rate_error_B_radPs_idx_0;
  real32_T rtb_rate_error_B_radPs_idx_1;
  real32_T rtb_rate_error_B_radPs_idx_2;
  real32_T rtb_uv_error_C_mPs_idx_0;
  real32_T rtb_uv_error_C_mPs_idx_1;

#if (AIRFRAME == 1) || (AIRFRAME == 2) || (AIRFRAME == 3) || (AIRFRAME == 4) || (AIRFRAME == 5) || (AIRFRAME == 6) || (AIRFRAME == 7) || (AIRFRAME == 8)

  uint16_T u0;

#endif

  int32_T tmp;
  real32_T u;
  real32_T u_0;

  /* Trigonometry: '<S99>/Trigonometric Function1' incorporates:
   *  Gain: '<S98>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S99>/Trigonometric Function3'
   */
  rtb_uv_error_C_mPs_idx_1 = csi_cos_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[0] = rtb_uv_error_C_mPs_idx_1;

  /* Trigonometry: '<S99>/Trigonometric Function' incorporates:
   *  Gain: '<S98>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S99>/Trigonometric Function2'
   */
  rtb_Gain_idx_0 = csi_sin_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[1] = rtb_Gain_idx_0;

  /* SignalConversion generated from: '<S99>/Vector Concatenate1' incorporates:
   *  Constant: '<S99>/Constant3'
   */
  rtb_VectorConcatenate[2] = 0.0F;

  /* Gain: '<S99>/Gain' */
  rtb_VectorConcatenate[3] = -rtb_Gain_idx_0;

  /* Trigonometry: '<S99>/Trigonometric Function3' */
  rtb_VectorConcatenate[4] = rtb_uv_error_C_mPs_idx_1;

  /* SignalConversion generated from: '<S99>/Vector Concatenate2' incorporates:
   *  Constant: '<S99>/Constant4'
   */
  rtb_VectorConcatenate[5] = 0.0F;

  /* SignalConversion generated from: '<S99>/Vector Concatenate' incorporates:
   *  Concatenate: '<S99>/Vector Concatenate3'
   */
  rtb_VectorConcatenate[6] = Controller_ConstB.VectorConcatenate3[0];
  rtb_VectorConcatenate[7] = Controller_ConstB.VectorConcatenate3[1];
  rtb_VectorConcatenate[8] = Controller_ConstB.VectorConcatenate3[2];

  /* Product: '<S96>/Multiply' incorporates:
   *  Concatenate: '<S99>/Vector Concatenate'
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion generated from: '<S96>/Multiply'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_0[i] = rtb_VectorConcatenate[i + 3] *
      Controller_U.INS_Out.ve + rtb_VectorConcatenate[i] *
      Controller_U.INS_Out.vn;
  }

  /* End of Product: '<S96>/Multiply' */

  /* Sum: '<S93>/Sum' incorporates:
   *  DiscreteIntegrator: '<S97>/Integrator1'
   */
  rtb_uv_error_C_mPs_idx_0 = Controller_DW.Integrator1_DSTATE[0] -
    rtb_VectorConcatenate_0[0];
  rtb_uv_error_C_mPs_idx_1 = Controller_DW.Integrator1_DSTATE[1] -
    rtb_VectorConcatenate_0[1];

  /* DiscreteIntegrator: '<S102>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
      Controller_ConstB.Constant_g;
    if (Controller_ConstB.Constant_g > CONTROL_PARAM.VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
        CONTROL_PARAM.VEL_XY_I_MAX;
    } else if (Controller_ConstB.Constant_g < CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
      Controller_ConstB.Constant_g;
    if (Controller_ConstB.Constant_g > CONTROL_PARAM.VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
        CONTROL_PARAM.VEL_XY_I_MAX;
    } else if (Controller_ConstB.Constant_g < CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }
  }

  /* DiscreteIntegrator: '<S104>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = rtb_uv_error_C_mPs_idx_0;
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_uv_error_C_mPs_idx_1;
  }

  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = rtb_uv_error_C_mPs_idx_0;
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_uv_error_C_mPs_idx_1;
  }

  /* Gain: '<S104>/Gain' incorporates:
   *  DiscreteIntegrator: '<S104>/Discrete-Time Integrator1'
   *  Sum: '<S104>/Sum5'
   */
  rtb_Gain_idx_0 = (rtb_uv_error_C_mPs_idx_0 -
                    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0]) *
    62.831852F;
  rtb_Gain_idx_1 = (rtb_uv_error_C_mPs_idx_1 -
                    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1]) *
    62.831852F;

  /* Switch: '<S104>/Switch' incorporates:
   *  Gain: '<S104>/Gain1'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.reset > 0) {
    rtb_Saturation_idx_0 = 0.0F;
    rtb_Saturation_idx_1 = 0.0F;
  } else {
    rtb_Saturation_idx_0 = rtb_Gain_idx_0;
    rtb_Saturation_idx_1 = rtb_Gain_idx_1;
  }

  /* End of Switch: '<S104>/Switch' */

  /* Saturate: '<S101>/Saturation' incorporates:
   *  Constant: '<S101>/kd'
   *  Product: '<S101>/Multiply'
   */
  rtb_Saturation_d_idx_0 = CONTROL_PARAM.VEL_XY_D * rtb_Saturation_idx_0;
  rtb_Saturation1_is_idx_0 = CONTROL_PARAM.VEL_XY_D * rtb_Saturation_idx_1;

  /* Switch: '<S95>/Switch' incorporates:
   *  Constant: '<S103>/kp'
   *  Constant: '<S105>/Constant'
   *  Constant: '<S107>/Constant'
   *  Constant: '<S108>/Constant'
   *  DiscreteIntegrator: '<S102>/Discrete-Time Integrator'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S103>/Multiply'
   *  Product: '<S106>/Multiply2'
   *  Product: '<S106>/Multiply3'
   *  RelationalOperator: '<S105>/Compare'
   *  RelationalOperator: '<S107>/Compare'
   *  RelationalOperator: '<S108>/Compare'
   *  S-Function (sfix_bitop): '<S106>/cmd_ax valid'
   *  S-Function (sfix_bitop): '<S106>/cmd_ay valid'
   *  S-Function (sfix_bitop): '<S106>/cmd_u valid'
   *  S-Function (sfix_bitop): '<S106>/cmd_v valid'
   *  Saturate: '<S101>/Saturation'
   *  Sum: '<S106>/Sum1'
   *  Sum: '<S94>/Add'
   */
  if (Controller_U.FMS_Out.ctrl_mode == 6) {
    /* Saturate: '<S101>/Saturation' */
    if (rtb_Saturation_d_idx_0 > CONTROL_PARAM.VEL_XY_D_MAX) {
      rtb_Saturation_d_idx_0 = CONTROL_PARAM.VEL_XY_D_MAX;
    } else if (rtb_Saturation_d_idx_0 < CONTROL_PARAM.VEL_XY_D_MIN) {
      rtb_Saturation_d_idx_0 = CONTROL_PARAM.VEL_XY_D_MIN;
    }

    rtb_Saturation_idx_0 = ((Controller_U.FMS_Out.cmd_mask & 64U) > 0U ?
      (CONTROL_PARAM.VEL_XY_P * rtb_uv_error_C_mPs_idx_0 +
       Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) + rtb_Saturation_d_idx_0 :
      0.0F) + ((Controller_U.FMS_Out.cmd_mask & 512U) > 0U ?
               Controller_U.FMS_Out.ax_cmd : 0.0F);

    /* Saturate: '<S101>/Saturation' incorporates:
     *  Constant: '<S103>/kp'
     *  Constant: '<S107>/Constant'
     *  Constant: '<S108>/Constant'
     *  DiscreteIntegrator: '<S102>/Discrete-Time Integrator'
     *  Product: '<S103>/Multiply'
     *  Product: '<S106>/Multiply2'
     *  Product: '<S106>/Multiply3'
     *  RelationalOperator: '<S107>/Compare'
     *  RelationalOperator: '<S108>/Compare'
     *  S-Function (sfix_bitop): '<S106>/cmd_ax valid'
     *  S-Function (sfix_bitop): '<S106>/cmd_u valid'
     *  Sum: '<S106>/Sum1'
     *  Sum: '<S94>/Add'
     */
    if (rtb_Saturation1_is_idx_0 > CONTROL_PARAM.VEL_XY_D_MAX) {
      rtb_Saturation1_is_idx_0 = CONTROL_PARAM.VEL_XY_D_MAX;
    } else if (rtb_Saturation1_is_idx_0 < CONTROL_PARAM.VEL_XY_D_MIN) {
      rtb_Saturation1_is_idx_0 = CONTROL_PARAM.VEL_XY_D_MIN;
    }

    rtb_Saturation_idx_1 = ((Controller_U.FMS_Out.cmd_mask & 128U) > 0U ?
      (CONTROL_PARAM.VEL_XY_P * rtb_uv_error_C_mPs_idx_1 +
       Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) +
      rtb_Saturation1_is_idx_0 : 0.0F) + ((Controller_U.FMS_Out.cmd_mask & 1024U)
      > 0U ? Controller_U.FMS_Out.ay_cmd : 0.0F);
  } else {
    if (rtb_Saturation_d_idx_0 > CONTROL_PARAM.VEL_XY_D_MAX) {
      /* Saturate: '<S101>/Saturation' */
      rtb_Saturation_d_idx_0 = CONTROL_PARAM.VEL_XY_D_MAX;
    } else if (rtb_Saturation_d_idx_0 < CONTROL_PARAM.VEL_XY_D_MIN) {
      /* Saturate: '<S101>/Saturation' */
      rtb_Saturation_d_idx_0 = CONTROL_PARAM.VEL_XY_D_MIN;
    }

    rtb_Saturation_idx_0 = (CONTROL_PARAM.VEL_XY_P * rtb_uv_error_C_mPs_idx_0 +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) + rtb_Saturation_d_idx_0;

    /* Saturate: '<S101>/Saturation' incorporates:
     *  Constant: '<S103>/kp'
     *  DiscreteIntegrator: '<S102>/Discrete-Time Integrator'
     *  Product: '<S103>/Multiply'
     *  Sum: '<S94>/Add'
     */
    if (rtb_Saturation1_is_idx_0 > CONTROL_PARAM.VEL_XY_D_MAX) {
      rtb_Saturation1_is_idx_0 = CONTROL_PARAM.VEL_XY_D_MAX;
    } else if (rtb_Saturation1_is_idx_0 < CONTROL_PARAM.VEL_XY_D_MIN) {
      rtb_Saturation1_is_idx_0 = CONTROL_PARAM.VEL_XY_D_MIN;
    }

    rtb_Saturation_idx_1 = (CONTROL_PARAM.VEL_XY_P * rtb_uv_error_C_mPs_idx_1 +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) + rtb_Saturation1_is_idx_0;
  }

  /* End of Switch: '<S95>/Switch' */

  /* Gain: '<S92>/gain' incorporates:
   *  Constant: '<S92>/g'
   *  Gain: '<S92>/Gain1'
   *  Product: '<S92>/Divide'
   */
  rtb_Subtract3_i = 1.1F * -rtb_Saturation_idx_0 / 9.8055F;

  /* Trigonometry: '<S92>/Atan' incorporates:
   *  Constant: '<S92>/g'
   *  Gain: '<S92>/gain'
   *  Product: '<S92>/Divide'
   */
  rtb_Saturation_idx_0 = atanf(1.1F * rtb_Saturation_idx_1 / 9.8055F);

  /* Saturate: '<S92>/Saturation' */
  if (rtb_Saturation_idx_0 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
    rtb_Saturation_idx_0 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
  } else if (rtb_Saturation_idx_0 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
    rtb_Saturation_idx_0 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
  }

  /* Trigonometry: '<S92>/Atan' */
  rtb_Saturation_idx_1 = atanf(rtb_Subtract3_i);

  /* Saturate: '<S92>/Saturation' */
  if (rtb_Saturation_idx_1 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
    rtb_Saturation_idx_1 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
  } else if (rtb_Saturation_idx_1 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
    rtb_Saturation_idx_1 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
  }

  /* Switch: '<S83>/Switch' incorporates:
   *  Constant: '<S89>/Constant'
   *  Constant: '<S90>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  Logic: '<S83>/Logical Operator'
   *  RelationalOperator: '<S89>/Compare'
   *  RelationalOperator: '<S90>/Compare'
   *  Switch: '<S83>/Switch1'
   */
  if ((Controller_U.FMS_Out.ctrl_mode == 3) || (Controller_U.FMS_Out.ctrl_mode ==
       4)) {
    rtb_Saturation_idx_0 = Controller_U.FMS_Out.phi_cmd;
    rtb_Saturation_idx_1 = Controller_U.FMS_Out.theta_cmd;
  } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
    /* Switch: '<S91>/Switch' incorporates:
     *  S-Function (sfix_bitop): '<S91>/cmd_phi valid'
     *  S-Function (sfix_bitop): '<S91>/cmd_theta valid'
     *  Switch: '<S83>/Switch1'
     */
    if ((Controller_U.FMS_Out.cmd_mask & 8U) > 0U) {
      rtb_Saturation_idx_0 = Controller_U.FMS_Out.phi_cmd;
    }

    if ((Controller_U.FMS_Out.cmd_mask & 16U) > 0U) {
      rtb_Saturation_idx_1 = Controller_U.FMS_Out.theta_cmd;
    }

    /* End of Switch: '<S91>/Switch' */
  }

  /* End of Switch: '<S83>/Switch' */

  /* Sum: '<S84>/Sum' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Saturation_idx_0 -= Controller_U.INS_Out.phi;
  rtb_Saturation_idx_1 -= Controller_U.INS_Out.theta;

  /* Product: '<S87>/Divide1' incorporates:
   *  Abs: '<S87>/Abs'
   *  Constant: '<S87>/const2'
   */
  rtb_Add_g_idx_0 = fabsf(rtb_Saturation_idx_0) / 0.004F;

  /* Product: '<S87>/Divide' incorporates:
   *  Constant: '<S85>/Constant1'
   *  Constant: '<S87>/const1'
   *  Math: '<S87>/Square'
   *  SignalConversion generated from: '<S87>/Square'
   */
  rtb_Multiply_lq_idx_1 = 9.5993F / (CONTROL_PARAM.ROLL_P * CONTROL_PARAM.ROLL_P);

  /* Signum: '<S87>/Sign' incorporates:
   *  Abs: '<S87>/Abs'
   */
  if (rtb_Saturation_idx_0 < 0.0F) {
    rtb_Multiply_lq_idx_2 = -1.0F;
  } else {
    rtb_Multiply_lq_idx_2 = (real32_T)(rtb_Saturation_idx_0 > 0.0F);
  }

  /* Switch: '<S87>/Switch' incorporates:
   *  Abs: '<S87>/Abs'
   *  Constant: '<S85>/Constant1'
   *  Gain: '<S87>/Gain1'
   *  Gain: '<S87>/Gain2'
   *  Logic: '<S87>/Logical Operator'
   *  Product: '<S87>/Multiply'
   *  Product: '<S87>/Multiply1'
   *  Product: '<S87>/Multiply2'
   *  Product: '<S87>/Multiply3'
   *  RelationalOperator: '<S87>/Relational Operator'
   *  RelationalOperator: '<S87>/Relational Operator2'
   *  SignalConversion generated from: '<S87>/Square'
   *  Sqrt: '<S87>/Sqrt'
   *  Sum: '<S87>/Subtract'
   */
  if ((rtb_Saturation_idx_0 <= rtb_Multiply_lq_idx_1) && (rtb_Saturation_idx_0 >=
       -rtb_Multiply_lq_idx_1)) {
    rtb_Multiply_lq_idx_2 = rtb_Saturation_idx_0 * CONTROL_PARAM.ROLL_P;
  } else {
    rtb_Multiply_lq_idx_2 *= sqrtf((rtb_Multiply_lq_idx_2 * rtb_Saturation_idx_0
      - 0.5F * rtb_Multiply_lq_idx_1) * Controller_ConstB.Gain);
  }

  /* Saturate: '<S68>/Saturation1' incorporates:
   *  Gain: '<S87>/Gain3'
   *  RelationalOperator: '<S88>/LowerRelop1'
   *  RelationalOperator: '<S88>/UpperRelop'
   *  Switch: '<S88>/Switch'
   *  Switch: '<S88>/Switch2'
   */
  if (rtb_Multiply_lq_idx_2 > rtb_Add_g_idx_0) {
    rtb_Multiply_lq_idx_2 = rtb_Add_g_idx_0;
  } else if (rtb_Multiply_lq_idx_2 < -rtb_Add_g_idx_0) {
    /* Switch: '<S88>/Switch' incorporates:
     *  Gain: '<S87>/Gain3'
     */
    rtb_Multiply_lq_idx_2 = -rtb_Add_g_idx_0;
  }

  if (rtb_Multiply_lq_idx_2 > CONTROL_PARAM.P_Q_CMD_LIM) {
    rtb_Saturation1_is_idx_0 = CONTROL_PARAM.P_Q_CMD_LIM;
  } else if (rtb_Multiply_lq_idx_2 < -CONTROL_PARAM.P_Q_CMD_LIM) {
    rtb_Saturation1_is_idx_0 = -CONTROL_PARAM.P_Q_CMD_LIM;
  } else {
    rtb_Saturation1_is_idx_0 = rtb_Multiply_lq_idx_2;
  }

  /* Product: '<S87>/Divide1' incorporates:
   *  Abs: '<S87>/Abs'
   *  Constant: '<S87>/const2'
   */
  rtb_Add_g_idx_0 = fabsf(rtb_Saturation_idx_1) / 0.004F;

  /* Product: '<S87>/Divide' incorporates:
   *  Constant: '<S85>/Constant2'
   *  Constant: '<S87>/const1'
   *  Math: '<S87>/Square'
   *  SignalConversion generated from: '<S87>/Square'
   */
  rtb_Multiply_lq_idx_1 = 9.5993F / (CONTROL_PARAM.PITCH_P *
    CONTROL_PARAM.PITCH_P);

  /* Signum: '<S87>/Sign' incorporates:
   *  Abs: '<S87>/Abs'
   */
  if (rtb_Saturation_idx_1 < 0.0F) {
    rtb_Multiply_lq_idx_2 = -1.0F;
  } else {
    rtb_Multiply_lq_idx_2 = (real32_T)(rtb_Saturation_idx_1 > 0.0F);
  }

  /* Switch: '<S87>/Switch' incorporates:
   *  Abs: '<S87>/Abs'
   *  Constant: '<S85>/Constant2'
   *  Gain: '<S87>/Gain1'
   *  Gain: '<S87>/Gain2'
   *  Logic: '<S87>/Logical Operator'
   *  Product: '<S87>/Multiply'
   *  Product: '<S87>/Multiply1'
   *  Product: '<S87>/Multiply2'
   *  Product: '<S87>/Multiply3'
   *  RelationalOperator: '<S87>/Relational Operator'
   *  RelationalOperator: '<S87>/Relational Operator2'
   *  SignalConversion generated from: '<S87>/Square'
   *  Sqrt: '<S87>/Sqrt'
   *  Sum: '<S87>/Subtract'
   */
  if ((rtb_Saturation_idx_1 <= rtb_Multiply_lq_idx_1) && (rtb_Saturation_idx_1 >=
       -rtb_Multiply_lq_idx_1)) {
    rtb_Multiply_lq_idx_2 = rtb_Saturation_idx_1 * CONTROL_PARAM.PITCH_P;
  } else {
    rtb_Multiply_lq_idx_2 *= sqrtf((rtb_Multiply_lq_idx_2 * rtb_Saturation_idx_1
      - 0.5F * rtb_Multiply_lq_idx_1) * Controller_ConstB.Gain);
  }

  /* Saturate: '<S68>/Saturation1' incorporates:
   *  Gain: '<S87>/Gain3'
   *  RelationalOperator: '<S88>/LowerRelop1'
   *  RelationalOperator: '<S88>/UpperRelop'
   *  Switch: '<S88>/Switch'
   *  Switch: '<S88>/Switch2'
   */
  if (rtb_Multiply_lq_idx_2 > rtb_Add_g_idx_0) {
    rtb_Multiply_lq_idx_2 = rtb_Add_g_idx_0;
  } else if (rtb_Multiply_lq_idx_2 < -rtb_Add_g_idx_0) {
    /* Switch: '<S88>/Switch' incorporates:
     *  Gain: '<S87>/Gain3'
     */
    rtb_Multiply_lq_idx_2 = -rtb_Add_g_idx_0;
  }

  if (rtb_Multiply_lq_idx_2 > CONTROL_PARAM.P_Q_CMD_LIM) {
    rtb_Add_g_idx_0 = CONTROL_PARAM.P_Q_CMD_LIM;
  } else if (rtb_Multiply_lq_idx_2 < -CONTROL_PARAM.P_Q_CMD_LIM) {
    rtb_Add_g_idx_0 = -CONTROL_PARAM.P_Q_CMD_LIM;
  } else {
    rtb_Add_g_idx_0 = rtb_Multiply_lq_idx_2;
  }

  /* Saturate: '<S68>/Saturation' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.R_CMD_LIM) {
    rtb_Subtract3_i = CONTROL_PARAM.R_CMD_LIM;
  } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.R_CMD_LIM) {
    rtb_Subtract3_i = -CONTROL_PARAM.R_CMD_LIM;
  } else {
    rtb_Subtract3_i = Controller_U.FMS_Out.psi_rate_cmd;
  }

  /* End of Saturate: '<S68>/Saturation' */

  /* Trigonometry: '<S78>/Sin' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Add3 = csi_sin_f32(Controller_U.INS_Out.phi);

  /* Trigonometry: '<S78>/Cos1' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S110>/Cos1'
   */
  rtb_Saturation_idx_1 = csi_cos_f32(Controller_U.INS_Out.theta);

  /* Trigonometry: '<S78>/Cos' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S110>/Cos'
   */
  rtb_Saturation_idx_0 = csi_cos_f32(Controller_U.INS_Out.phi);

  /* Switch: '<S69>/Switch' incorporates:
   *  Constant: '<S79>/Constant'
   *  Constant: '<S80>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  RelationalOperator: '<S79>/Compare'
   *  RelationalOperator: '<S80>/Compare'
   *  Switch: '<S69>/Switch1'
   */
  if (Controller_U.FMS_Out.ctrl_mode == 2) {
    rtb_Saturation1_is_idx_0 = Controller_U.FMS_Out.p_cmd;
    rtb_Multiply_lq_idx_1 = Controller_U.FMS_Out.q_cmd;
    rtb_Multiply_lq_idx_2 = Controller_U.FMS_Out.r_cmd;
  } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
    /* Switch: '<S81>/Switch' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S78>/Multiply'
     *  Product: '<S78>/Multiply1'
     *  Product: '<S78>/Multiply3'
     *  Product: '<S78>/Multiply4'
     *  Product: '<S78>/Multiply5'
     *  S-Function (sfix_bitop): '<S81>/cmd_p valid'
     *  S-Function (sfix_bitop): '<S81>/cmd_q valid'
     *  S-Function (sfix_bitop): '<S81>/cmd_r valid'
     *  Saturate: '<S68>/Saturation1'
     *  Sum: '<S78>/Add'
     *  Sum: '<S78>/Add1'
     *  Sum: '<S78>/Add2'
     *  Switch: '<S69>/Switch1'
     *  Trigonometry: '<S78>/Cos'
     *  Trigonometry: '<S78>/Cos1'
     *  Trigonometry: '<S78>/Sin1'
     */
    if ((Controller_U.FMS_Out.cmd_mask & 1U) > 0U) {
      rtb_Saturation1_is_idx_0 = Controller_U.FMS_Out.p_cmd;
    } else {
      rtb_Saturation1_is_idx_0 -= csi_sin_f32(Controller_U.INS_Out.theta) *
        rtb_Subtract3_i;
    }

    if ((Controller_U.FMS_Out.cmd_mask & 2U) > 0U) {
      rtb_Multiply_lq_idx_1 = Controller_U.FMS_Out.q_cmd;
    } else {
      rtb_Multiply_lq_idx_1 = rtb_Add3 * rtb_Saturation_idx_1 * rtb_Subtract3_i
        + rtb_Saturation_idx_0 * rtb_Add_g_idx_0;
    }

    if ((Controller_U.FMS_Out.cmd_mask & 4U) > 0U) {
      rtb_Multiply_lq_idx_2 = Controller_U.FMS_Out.r_cmd;
    } else {
      rtb_Multiply_lq_idx_2 = rtb_Saturation_idx_0 * rtb_Saturation_idx_1 *
        rtb_Subtract3_i - rtb_Add3 * rtb_Add_g_idx_0;
    }

    /* End of Switch: '<S81>/Switch' */
  } else {
    /* Switch: '<S69>/Switch1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S78>/Multiply'
     *  Product: '<S78>/Multiply1'
     *  Product: '<S78>/Multiply3'
     *  Product: '<S78>/Multiply4'
     *  Product: '<S78>/Multiply5'
     *  Saturate: '<S68>/Saturation1'
     *  Sum: '<S78>/Add'
     *  Sum: '<S78>/Add1'
     *  Sum: '<S78>/Add2'
     *  Trigonometry: '<S78>/Cos'
     *  Trigonometry: '<S78>/Cos1'
     *  Trigonometry: '<S78>/Sin1'
     */
    rtb_Saturation1_is_idx_0 -= csi_sin_f32(Controller_U.INS_Out.theta) *
      rtb_Subtract3_i;
    rtb_Multiply_lq_idx_1 = rtb_Add3 * rtb_Saturation_idx_1 * rtb_Subtract3_i +
      rtb_Saturation_idx_0 * rtb_Add_g_idx_0;
    rtb_Multiply_lq_idx_2 = rtb_Saturation_idx_0 * rtb_Saturation_idx_1 *
      rtb_Subtract3_i - rtb_Add3 * rtb_Add_g_idx_0;
  }

  /* End of Switch: '<S69>/Switch' */

  /* Sum: '<S70>/Sum' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_rate_error_B_radPs_idx_0 = rtb_Saturation1_is_idx_0 -
    Controller_U.INS_Out.p;
  rtb_rate_error_B_radPs_idx_1 = rtb_Multiply_lq_idx_1 - Controller_U.INS_Out.q;
  rtb_rate_error_B_radPs_idx_2 = rtb_Multiply_lq_idx_2 - Controller_U.INS_Out.r;

  /* DiscreteIntegrator: '<S73>/Discrete-Time Integrator5' */
  if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] =
      rtb_rate_error_B_radPs_idx_0;
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] =
      rtb_rate_error_B_radPs_idx_1;
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] =
      rtb_rate_error_B_radPs_idx_2;
  }

  /* DiscreteIntegrator: '<S75>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator_PrevRe_g != 0)) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
      Controller_ConstB.Constant[0];
    if (Controller_ConstB.Constant[0] > CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
        CONTROL_PARAM.RATE_I_MAX;
    } else if (Controller_ConstB.Constant[0] < CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
        CONTROL_PARAM.RATE_I_MIN;
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
      Controller_ConstB.Constant[1];
    if (Controller_ConstB.Constant[1] > CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
        CONTROL_PARAM.RATE_I_MAX;
    } else if (Controller_ConstB.Constant[1] < CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
        CONTROL_PARAM.RATE_I_MIN;
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
      Controller_ConstB.Constant[2];
    if (Controller_ConstB.Constant[2] > CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
        CONTROL_PARAM.RATE_I_MAX;
    } else if (Controller_ConstB.Constant[2] < CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  /* DiscreteIntegrator: '<S77>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S73>/Discrete-Time Integrator5'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_l != 0) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0] =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0];
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1] =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1];
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[2] =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2];
  }

  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevR_i != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0] =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0];
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1] =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1];
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[2] =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2];
  }

  /* Gain: '<S77>/Gain' incorporates:
   *  DiscreteIntegrator: '<S73>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S77>/Discrete-Time Integrator1'
   *  Sum: '<S77>/Sum5'
   */
  rtb_Saturation1_is_idx_0 = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] -
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0]) * 188.49556F;
  rtb_Multiply_lq_idx_1 = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] -
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1]) * 188.49556F;
  rtb_Multiply_lq_idx_2 = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] -
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[2]) * 188.49556F;

  /* Switch: '<S77>/Switch' incorporates:
   *  Gain: '<S77>/Gain1'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.reset > 0) {
    rtb_Saturation_d_idx_0 = 0.0F;
    rtb_Saturation_d_idx_1 = 0.0F;
    rtb_Saturation_d_idx_2 = 0.0F;
  } else {
    rtb_Saturation_d_idx_0 = rtb_Saturation1_is_idx_0;
    rtb_Saturation_d_idx_1 = rtb_Multiply_lq_idx_1;
    rtb_Saturation_d_idx_2 = rtb_Multiply_lq_idx_2;
  }

  /* End of Switch: '<S77>/Switch' */

  /* Product: '<S74>/Multiply' incorporates:
   *  Constant: '<S74>/gain1'
   */
  rtb_Saturation_d_idx_0 *= CONTROL_PARAM.ROLL_RATE_D;

  /* Saturate: '<S74>/Saturation' */
  if (rtb_Saturation_d_idx_0 > CONTROL_PARAM.RATE_D_MAX) {
    rtb_Saturation_d_idx_0 = CONTROL_PARAM.RATE_D_MAX;
  } else if (rtb_Saturation_d_idx_0 < CONTROL_PARAM.RATE_D_MIN) {
    rtb_Saturation_d_idx_0 = CONTROL_PARAM.RATE_D_MIN;
  }

  /* Sum: '<S71>/Add' incorporates:
   *  Constant: '<S76>/gain1'
   *  DiscreteIntegrator: '<S73>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S75>/Discrete-Time Integrator'
   *  Product: '<S76>/Multiply'
   *  Saturate: '<S74>/Saturation'
   */
  rtb_Add_g_idx_0 = (CONTROL_PARAM.ROLL_RATE_P *
                     Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +
                     Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0]) +
    rtb_Saturation_d_idx_0;

  /* Product: '<S74>/Multiply' incorporates:
   *  Constant: '<S74>/gain2'
   */
  rtb_Saturation_d_idx_0 = CONTROL_PARAM.PITCH_RATE_D * rtb_Saturation_d_idx_1;

  /* Saturate: '<S74>/Saturation' */
  if (rtb_Saturation_d_idx_0 > CONTROL_PARAM.RATE_D_MAX) {
    rtb_Saturation_d_idx_0 = CONTROL_PARAM.RATE_D_MAX;
  } else if (rtb_Saturation_d_idx_0 < CONTROL_PARAM.RATE_D_MIN) {
    rtb_Saturation_d_idx_0 = CONTROL_PARAM.RATE_D_MIN;
  }

  /* Sum: '<S71>/Add' incorporates:
   *  Constant: '<S76>/gain2'
   *  DiscreteIntegrator: '<S73>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S75>/Discrete-Time Integrator'
   *  Product: '<S76>/Multiply'
   *  Saturate: '<S74>/Saturation'
   */
  rtb_Saturation_d_idx_1 = (CONTROL_PARAM.PITCH_RATE_P *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1]) + rtb_Saturation_d_idx_0;

  /* Product: '<S74>/Multiply' incorporates:
   *  Constant: '<S74>/gain3'
   */
  rtb_Saturation_d_idx_0 = CONTROL_PARAM.YAW_RATE_D * rtb_Saturation_d_idx_2;

  /* Saturate: '<S74>/Saturation' */
  if (rtb_Saturation_d_idx_0 > CONTROL_PARAM.RATE_D_MAX) {
    rtb_Saturation_d_idx_0 = CONTROL_PARAM.RATE_D_MAX;
  } else if (rtb_Saturation_d_idx_0 < CONTROL_PARAM.RATE_D_MIN) {
    rtb_Saturation_d_idx_0 = CONTROL_PARAM.RATE_D_MIN;
  }

  /* Sum: '<S71>/Add' incorporates:
   *  Constant: '<S76>/gain3'
   *  DiscreteIntegrator: '<S73>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S75>/Discrete-Time Integrator'
   *  Product: '<S76>/Multiply'
   *  Saturate: '<S74>/Saturation'
   */
  rtb_Saturation_d_idx_2 = (CONTROL_PARAM.YAW_RATE_P *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2]) + rtb_Saturation_d_idx_0;

  /* Gain: '<S111>/Gain' incorporates:
   *  DiscreteIntegrator: '<S113>/Integrator1'
   *  Inport: '<Root>/INS_Out'
   *  Sum: '<S111>/Sum1'
   */
  rtb_Gain_fl = -(Controller_DW.Integrator1_DSTATE_p - Controller_U.INS_Out.vd);

  /* DiscreteIntegrator: '<S116>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S116>/Constant'
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator_PrevRe_m != 0)) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_Z_I_MIN;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m >
        CONTROL_PARAM.VEL_Z_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_Z_I_MAX;
    } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m <
               CONTROL_PARAM.VEL_Z_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_Z_I_MIN;
    }
  }

  /* DiscreteIntegrator: '<S118>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_k != 0) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_h = rtb_Gain_fl;
  }

  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_Prev_iy != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_h = rtb_Gain_fl;
  }

  /* Gain: '<S118>/Gain' incorporates:
   *  DiscreteIntegrator: '<S118>/Discrete-Time Integrator1'
   *  Sum: '<S118>/Sum5'
   */
  rtb_Gain_g2 = (rtb_Gain_fl - Controller_DW.DiscreteTimeIntegrator1_DSTAT_h) *
    62.831852F;

  /* Switch: '<S118>/Switch' incorporates:
   *  Gain: '<S118>/Gain1'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.reset > 0) {
    rtb_Saturation_d_idx_0 = 0.0F;
  } else {
    rtb_Saturation_d_idx_0 = rtb_Gain_g2;
  }

  /* Product: '<S115>/Multiply' incorporates:
   *  Constant: '<S115>/kd'
   *  Switch: '<S118>/Switch'
   */
  rtb_Add3 = CONTROL_PARAM.VEL_Z_D * rtb_Saturation_d_idx_0;

  /* Product: '<S110>/Multiply' */
  rtb_Subtract3_i = rtb_Saturation_idx_0 * rtb_Saturation_idx_1;

  /* Gain: '<S110>/Gain' */
  rtb_Saturation_d_idx_0 = 2.0F * rtb_Subtract3_i;

  /* Saturate: '<S115>/Saturation' */
  if (rtb_Add3 > CONTROL_PARAM.VEL_Z_D_MAX) {
    rtb_Add3 = CONTROL_PARAM.VEL_Z_D_MAX;
  } else if (rtb_Add3 < CONTROL_PARAM.VEL_Z_D_MIN) {
    rtb_Add3 = CONTROL_PARAM.VEL_Z_D_MIN;
  }

  /* Saturate: '<S110>/Saturation1' */
  if (rtb_Subtract3_i < 0.5F) {
    rtb_Subtract3_i = 0.5F;
  }

  /* Saturate: '<S110>/Saturation' */
  if (rtb_Saturation_d_idx_0 > 1.0F) {
    rtb_Saturation_d_idx_0 = 1.0F;
  } else if (rtb_Saturation_d_idx_0 < 0.0F) {
    rtb_Saturation_d_idx_0 = 0.0F;
  }

  /* Product: '<S110>/Multiply1' incorporates:
   *  Constant: '<S110>/Constant'
   *  Constant: '<S117>/kp'
   *  DiscreteIntegrator: '<S116>/Discrete-Time Integrator'
   *  Product: '<S110>/Divide'
   *  Product: '<S117>/Multiply'
   *  Saturate: '<S110>/Saturation'
   *  Saturate: '<S110>/Saturation1'
   *  Saturate: '<S115>/Saturation'
   *  Sum: '<S112>/Add'
   */
  rtb_Saturation_idx_1 = ((CONTROL_PARAM.VEL_Z_P * rtb_Gain_fl +
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m) + rtb_Add3) * (1.0F /
    rtb_Subtract3_i) * rtb_Saturation_d_idx_0;

  /* Saturate: '<S109>/Saturation' */
  if (rtb_Saturation_idx_1 > 0.35F) {
    rtb_Saturation_idx_1 = 0.35F;
  } else if (rtb_Saturation_idx_1 < -0.35F) {
    rtb_Saturation_idx_1 = -0.35F;
  }

  /* End of Saturate: '<S109>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S2>/Control_Allocation' */
#if AIRFRAME == 6

  /* Outputs for Atomic SubSystem: '<S4>/Coxial_Hexacopter_x' */
  /* MultiPortSwitch: '<S16>/Multiport Switch' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  switch (Controller_U.FMS_Out.status) {
   case 1:
    for (i = 0; i < 12; i++) {
      rtb_MultiportSwitch_p[i] = 1000U;
    }
    break;

   case 2:
    for (i = 0; i < 12; i++) {
      rtb_MultiportSwitch_p[i] = 1150U;
    }
    break;

   case 3:
    /* Switch: '<S15>/Switch' incorporates:
     *  Constant: '<S18>/Constant'
     *  Constant: '<S19>/Constant'
     *  Logic: '<S15>/Logical Operator'
     *  RelationalOperator: '<S18>/Compare'
     *  RelationalOperator: '<S19>/Compare'
     *  Switch: '<S15>/Switch1'
     */
    if ((Controller_U.FMS_Out.ctrl_mode == 1) || (Controller_U.FMS_Out.ctrl_mode
         == 2) || (Controller_U.FMS_Out.ctrl_mode == 3)) {
      rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
    } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
      /* Switch: '<S20>/Switch' incorporates:
       *  Constant: '<S17>/Constant1'
       *  DataTypeConversion: '<S17>/Data Type Conversion'
       *  Gain: '<S17>/Gain1'
       *  S-Function (sfix_bitop): '<S20>/cmd_throttle valid'
       *  Saturate: '<S17>/Saturation'
       *  Sum: '<S17>/Sum1'
       *  Switch: '<S15>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 4096U) > 0U) {
        rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
      } else {
        /* Sum: '<S17>/Sum' incorporates:
         *  Constant: '<S17>/hover_throttle'
         *  Saturate: '<S7>/Saturation2'
         */
        rtb_Saturation_d_idx_0 = rtb_Saturation_idx_1 + CONTROL_PARAM.HOVER_THRO;

        /* Saturate: '<S17>/Saturation' */
        if (rtb_Saturation_d_idx_0 > 1.0F) {
          rtb_Saturation_d_idx_0 = 1.0F;
        } else if (rtb_Saturation_d_idx_0 < 0.0F) {
          rtb_Saturation_d_idx_0 = 0.0F;
        }

        rtb_throttle_cmd_f = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation_d_idx_0), 4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S20>/Switch' */
    } else {
      /* Sum: '<S17>/Sum' incorporates:
       *  Constant: '<S17>/hover_throttle'
       *  Saturate: '<S7>/Saturation2'
       */
      rtb_Saturation_d_idx_0 = rtb_Saturation_idx_1 + CONTROL_PARAM.HOVER_THRO;

      /* Saturate: '<S17>/Saturation' */
      if (rtb_Saturation_d_idx_0 > 1.0F) {
        rtb_Saturation_d_idx_0 = 1.0F;
      } else if (rtb_Saturation_d_idx_0 < 0.0F) {
        rtb_Saturation_d_idx_0 = 0.0F;
      }

      /* Switch: '<S15>/Switch1' incorporates:
       *  Constant: '<S17>/Constant1'
       *  DataTypeConversion: '<S17>/Data Type Conversion'
       *  Gain: '<S17>/Gain1'
       *  Saturate: '<S17>/Saturation'
       *  Sum: '<S17>/Sum1'
       */
      rtb_throttle_cmd_f = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        rtb_Saturation_d_idx_0), 4.2949673E+9F) + 1000U);
    }

    /* End of Switch: '<S15>/Switch' */

    /* Saturate: '<S7>/Saturation1' */
    if (rtb_Add_g_idx_0 > 1.0F) {
      rtb_Saturation_idx_0 = 1.0F;
    } else if (rtb_Add_g_idx_0 < -1.0F) {
      rtb_Saturation_idx_0 = -1.0F;
    } else {
      rtb_Saturation_idx_0 = rtb_Add_g_idx_0;
    }

    if (rtb_Saturation_d_idx_1 > 1.0F) {
      rtb_Subtract3_i = 1.0F;
    } else if (rtb_Saturation_d_idx_1 < -1.0F) {
      rtb_Subtract3_i = -1.0F;
    } else {
      rtb_Subtract3_i = rtb_Saturation_d_idx_1;
    }

    if (rtb_Saturation_d_idx_2 > 1.0F) {
      rtb_Add3 = 1.0F;
    } else if (rtb_Saturation_d_idx_2 < -1.0F) {
      rtb_Add3 = -1.0F;
    } else {
      rtb_Add3 = rtb_Saturation_d_idx_2;
    }

    /* End of Saturate: '<S7>/Saturation1' */

    /* Product: '<S7>/Multiply' */
    for (i = 0; i < 12; i++) {
      /* Saturate: '<S7>/Saturation' incorporates:
       *  Constant: '<S7>/Effective_Matrix'
       *  Gain: '<S7>/Gain'
       *  MultiPortSwitch: '<S16>/Multiport Switch'
       *  Sum: '<S7>/Add'
       */
      rtb_Saturation_d_idx_0 = fmodf(floorf
        (((Controller_ConstP.Effective_Matrix_Value[i + 12] * rtb_Subtract3_i +
           Controller_ConstP.Effective_Matrix_Value[i] * rtb_Saturation_idx_0) +
          Controller_ConstP.Effective_Matrix_Value[i + 24] * rtb_Add3) * 1000.0F
         + (real32_T)rtb_throttle_cmd_f), 65536.0F);
      u0 = (uint16_T)(rtb_Saturation_d_idx_0 < 0.0F ? (int32_T)(uint16_T)
                      -(int16_T)(uint16_T)-rtb_Saturation_d_idx_0 : (int32_T)
                      (uint16_T)rtb_Saturation_d_idx_0);
      if (u0 > 1900) {
        rtb_MultiportSwitch_p[i] = 1900U;
      } else if (u0 < 1100) {
        rtb_MultiportSwitch_p[i] = 1100U;
      } else {
        rtb_MultiportSwitch_p[i] = u0;
      }

      /* End of Saturate: '<S7>/Saturation' */
    }

    /* End of Product: '<S7>/Multiply' */
    break;

   default:
    for (i = 0; i < 12; i++) {
      rtb_MultiportSwitch_p[i] = 1000U;
    }
    break;
  }

  /* End of MultiPortSwitch: '<S16>/Multiport Switch' */

  /* Reshape: '<S16>/Reshape' incorporates:
   *  Constant: '<S16>/Constant'
   *  VariantMerge generated from: '<S4>/actuator_cmd'
   */
  for (i = 0; i < 12; i++) {
    Controller_Y.Control_Out.actuator_cmd[i] = rtb_MultiportSwitch_p[i];
  }

  Controller_Y.Control_Out.actuator_cmd[12] = 0U;
  Controller_Y.Control_Out.actuator_cmd[13] = 0U;
  Controller_Y.Control_Out.actuator_cmd[14] = 0U;
  Controller_Y.Control_Out.actuator_cmd[15] = 0U;

  /* End of Reshape: '<S16>/Reshape' */
  /* End of Outputs for SubSystem: '<S4>/Coxial_Hexacopter_x' */
#elif AIRFRAME == 3

  /* Outputs for Atomic SubSystem: '<S4>/Coxial_Quadcopter_x' */
  /* MultiPortSwitch: '<S22>/Multiport Switch' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  switch (Controller_U.FMS_Out.status) {
   case 1:
    for (i = 0; i < 8; i++) {
      rtb_MultiportSwitch_ev[i] = 1000U;
    }
    break;

   case 2:
    for (i = 0; i < 8; i++) {
      rtb_MultiportSwitch_ev[i] = 1150U;
    }
    break;

   case 3:
    /* Switch: '<S21>/Switch' incorporates:
     *  Constant: '<S24>/Constant'
     *  Constant: '<S25>/Constant'
     *  Logic: '<S21>/Logical Operator'
     *  RelationalOperator: '<S24>/Compare'
     *  RelationalOperator: '<S25>/Compare'
     *  Switch: '<S21>/Switch1'
     */
    if ((Controller_U.FMS_Out.ctrl_mode == 1) || (Controller_U.FMS_Out.ctrl_mode
         == 2) || (Controller_U.FMS_Out.ctrl_mode == 3)) {
      rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
    } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
      /* Switch: '<S26>/Switch' incorporates:
       *  Constant: '<S23>/Constant1'
       *  DataTypeConversion: '<S23>/Data Type Conversion'
       *  Gain: '<S23>/Gain1'
       *  S-Function (sfix_bitop): '<S26>/cmd_throttle valid'
       *  Saturate: '<S23>/Saturation'
       *  Sum: '<S23>/Sum1'
       *  Switch: '<S21>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 4096U) > 0U) {
        rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
      } else {
        /* Sum: '<S23>/Sum' incorporates:
         *  Constant: '<S23>/hover_throttle'
         *  Saturate: '<S8>/Saturation2'
         */
        rtb_Saturation_d_idx_0 = rtb_Saturation_idx_1 + CONTROL_PARAM.HOVER_THRO;

        /* Saturate: '<S23>/Saturation' */
        if (rtb_Saturation_d_idx_0 > 1.0F) {
          rtb_Saturation_d_idx_0 = 1.0F;
        } else if (rtb_Saturation_d_idx_0 < 0.0F) {
          rtb_Saturation_d_idx_0 = 0.0F;
        }

        rtb_throttle_cmd_f = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation_d_idx_0), 4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S26>/Switch' */
    } else {
      /* Sum: '<S23>/Sum' incorporates:
       *  Constant: '<S23>/hover_throttle'
       *  Saturate: '<S8>/Saturation2'
       */
      rtb_Saturation_d_idx_0 = rtb_Saturation_idx_1 + CONTROL_PARAM.HOVER_THRO;

      /* Saturate: '<S23>/Saturation' */
      if (rtb_Saturation_d_idx_0 > 1.0F) {
        rtb_Saturation_d_idx_0 = 1.0F;
      } else if (rtb_Saturation_d_idx_0 < 0.0F) {
        rtb_Saturation_d_idx_0 = 0.0F;
      }

      /* Switch: '<S21>/Switch1' incorporates:
       *  Constant: '<S23>/Constant1'
       *  DataTypeConversion: '<S23>/Data Type Conversion'
       *  Gain: '<S23>/Gain1'
       *  Saturate: '<S23>/Saturation'
       *  Sum: '<S23>/Sum1'
       */
      rtb_throttle_cmd_f = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        rtb_Saturation_d_idx_0), 4.2949673E+9F) + 1000U);
    }

    /* End of Switch: '<S21>/Switch' */

    /* Saturate: '<S8>/Saturation1' */
    if (rtb_Add_g_idx_0 > 1.0F) {
      rtb_Saturation_idx_0 = 1.0F;
    } else if (rtb_Add_g_idx_0 < -1.0F) {
      rtb_Saturation_idx_0 = -1.0F;
    } else {
      rtb_Saturation_idx_0 = rtb_Add_g_idx_0;
    }

    if (rtb_Saturation_d_idx_1 > 1.0F) {
      rtb_Subtract3_i = 1.0F;
    } else if (rtb_Saturation_d_idx_1 < -1.0F) {
      rtb_Subtract3_i = -1.0F;
    } else {
      rtb_Subtract3_i = rtb_Saturation_d_idx_1;
    }

    if (rtb_Saturation_d_idx_2 > 1.0F) {
      rtb_Add3 = 1.0F;
    } else if (rtb_Saturation_d_idx_2 < -1.0F) {
      rtb_Add3 = -1.0F;
    } else {
      rtb_Add3 = rtb_Saturation_d_idx_2;
    }

    /* End of Saturate: '<S8>/Saturation1' */

    /* Product: '<S8>/Multiply' */
    for (i = 0; i < 8; i++) {
      /* Saturate: '<S8>/Saturation' incorporates:
       *  Constant: '<S8>/Effective_Matrix'
       *  Gain: '<S8>/Gain'
       *  MultiPortSwitch: '<S22>/Multiport Switch'
       *  Sum: '<S8>/Add'
       */
      rtb_Saturation_d_idx_0 = fmodf(floorf
        (((Controller_ConstP.Effective_Matrix_Value_j[i + 8] * rtb_Subtract3_i +
           Controller_ConstP.Effective_Matrix_Value_j[i] * rtb_Saturation_idx_0)
          + Controller_ConstP.Effective_Matrix_Value_j[i + 16] * rtb_Add3) *
         1000.0F + (real32_T)rtb_throttle_cmd_f), 65536.0F);
      u0 = (uint16_T)(rtb_Saturation_d_idx_0 < 0.0F ? (int32_T)(uint16_T)
                      -(int16_T)(uint16_T)-rtb_Saturation_d_idx_0 : (int32_T)
                      (uint16_T)rtb_Saturation_d_idx_0);
      if (u0 > 1900) {
        rtb_MultiportSwitch_ev[i] = 1900U;
      } else if (u0 < 1100) {
        rtb_MultiportSwitch_ev[i] = 1100U;
      } else {
        rtb_MultiportSwitch_ev[i] = u0;
      }

      /* End of Saturate: '<S8>/Saturation' */
    }

    /* End of Product: '<S8>/Multiply' */
    break;

   default:
    for (i = 0; i < 8; i++) {
      rtb_MultiportSwitch_ev[i] = 1000U;
    }
    break;
  }

  /* End of MultiPortSwitch: '<S22>/Multiport Switch' */

  /* Reshape: '<S22>/Reshape' incorporates:
   *  VariantMerge generated from: '<S4>/actuator_cmd'
   */
  for (i = 0; i < 8; i++) {
    Controller_Y.Control_Out.actuator_cmd[i] = rtb_MultiportSwitch_ev[i];
    Controller_Y.Control_Out.actuator_cmd[i + 8] = 0U;
  }

  /* End of Reshape: '<S22>/Reshape' */
  /* End of Outputs for SubSystem: '<S4>/Coxial_Quadcopter_x' */
#elif AIRFRAME == 5

  /* Outputs for Atomic SubSystem: '<S4>/Hexacopter_+' */
  /* MultiPortSwitch: '<S28>/Multiport Switch' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  switch (Controller_U.FMS_Out.status) {
   case 1:
    for (i = 0; i < 6; i++) {
      rtb_MultiportSwitch_i[i] = 1000U;
    }
    break;

   case 2:
    for (i = 0; i < 6; i++) {
      rtb_MultiportSwitch_i[i] = 1150U;
    }
    break;

   case 3:
    /* Switch: '<S27>/Switch' incorporates:
     *  Constant: '<S30>/Constant'
     *  Constant: '<S31>/Constant'
     *  Logic: '<S27>/Logical Operator'
     *  RelationalOperator: '<S30>/Compare'
     *  RelationalOperator: '<S31>/Compare'
     *  Switch: '<S27>/Switch1'
     */
    if ((Controller_U.FMS_Out.ctrl_mode == 1) || (Controller_U.FMS_Out.ctrl_mode
         == 2) || (Controller_U.FMS_Out.ctrl_mode == 3)) {
      rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
    } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
      /* Switch: '<S32>/Switch' incorporates:
       *  Constant: '<S29>/Constant1'
       *  DataTypeConversion: '<S29>/Data Type Conversion'
       *  Gain: '<S29>/Gain1'
       *  S-Function (sfix_bitop): '<S32>/cmd_throttle valid'
       *  Saturate: '<S29>/Saturation'
       *  Sum: '<S29>/Sum1'
       *  Switch: '<S27>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 4096U) > 0U) {
        rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
      } else {
        /* Sum: '<S29>/Sum' incorporates:
         *  Constant: '<S29>/hover_throttle'
         *  Saturate: '<S9>/Saturation2'
         */
        rtb_Saturation_d_idx_0 = rtb_Saturation_idx_1 + CONTROL_PARAM.HOVER_THRO;

        /* Saturate: '<S29>/Saturation' */
        if (rtb_Saturation_d_idx_0 > 1.0F) {
          rtb_Saturation_d_idx_0 = 1.0F;
        } else if (rtb_Saturation_d_idx_0 < 0.0F) {
          rtb_Saturation_d_idx_0 = 0.0F;
        }

        rtb_throttle_cmd_f = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation_d_idx_0), 4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S32>/Switch' */
    } else {
      /* Sum: '<S29>/Sum' incorporates:
       *  Constant: '<S29>/hover_throttle'
       *  Saturate: '<S9>/Saturation2'
       */
      rtb_Saturation_d_idx_0 = rtb_Saturation_idx_1 + CONTROL_PARAM.HOVER_THRO;

      /* Saturate: '<S29>/Saturation' */
      if (rtb_Saturation_d_idx_0 > 1.0F) {
        rtb_Saturation_d_idx_0 = 1.0F;
      } else if (rtb_Saturation_d_idx_0 < 0.0F) {
        rtb_Saturation_d_idx_0 = 0.0F;
      }

      /* Switch: '<S27>/Switch1' incorporates:
       *  Constant: '<S29>/Constant1'
       *  DataTypeConversion: '<S29>/Data Type Conversion'
       *  Gain: '<S29>/Gain1'
       *  Saturate: '<S29>/Saturation'
       *  Sum: '<S29>/Sum1'
       */
      rtb_throttle_cmd_f = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        rtb_Saturation_d_idx_0), 4.2949673E+9F) + 1000U);
    }

    /* End of Switch: '<S27>/Switch' */

    /* Saturate: '<S9>/Saturation1' */
    if (rtb_Add_g_idx_0 > 1.0F) {
      rtb_Saturation_idx_0 = 1.0F;
    } else if (rtb_Add_g_idx_0 < -1.0F) {
      rtb_Saturation_idx_0 = -1.0F;
    } else {
      rtb_Saturation_idx_0 = rtb_Add_g_idx_0;
    }

    if (rtb_Saturation_d_idx_1 > 1.0F) {
      rtb_Subtract3_i = 1.0F;
    } else if (rtb_Saturation_d_idx_1 < -1.0F) {
      rtb_Subtract3_i = -1.0F;
    } else {
      rtb_Subtract3_i = rtb_Saturation_d_idx_1;
    }

    if (rtb_Saturation_d_idx_2 > 1.0F) {
      rtb_Add3 = 1.0F;
    } else if (rtb_Saturation_d_idx_2 < -1.0F) {
      rtb_Add3 = -1.0F;
    } else {
      rtb_Add3 = rtb_Saturation_d_idx_2;
    }

    /* End of Saturate: '<S9>/Saturation1' */

    /* Product: '<S9>/Multiply' */
    for (i = 0; i < 6; i++) {
      /* Saturate: '<S9>/Saturation' incorporates:
       *  Constant: '<S9>/Effective_Matrix'
       *  Gain: '<S9>/Gain'
       *  MultiPortSwitch: '<S28>/Multiport Switch'
       *  Sum: '<S9>/Add'
       */
      rtb_Saturation_d_idx_0 = fmodf(floorf
        (((Controller_ConstP.Effective_Matrix_Value_je[i + 6] * rtb_Subtract3_i
           + Controller_ConstP.Effective_Matrix_Value_je[i] *
           rtb_Saturation_idx_0) + Controller_ConstP.Effective_Matrix_Value_je[i
          + 12] * rtb_Add3) * 1000.0F + (real32_T)rtb_throttle_cmd_f), 65536.0F);
      u0 = (uint16_T)(rtb_Saturation_d_idx_0 < 0.0F ? (int32_T)(uint16_T)
                      -(int16_T)(uint16_T)-rtb_Saturation_d_idx_0 : (int32_T)
                      (uint16_T)rtb_Saturation_d_idx_0);
      if (u0 > 1900) {
        rtb_MultiportSwitch_i[i] = 1900U;
      } else if (u0 < 1100) {
        rtb_MultiportSwitch_i[i] = 1100U;
      } else {
        rtb_MultiportSwitch_i[i] = u0;
      }

      /* End of Saturate: '<S9>/Saturation' */
    }

    /* End of Product: '<S9>/Multiply' */
    break;

   default:
    for (i = 0; i < 6; i++) {
      rtb_MultiportSwitch_i[i] = 1000U;
    }
    break;
  }

  /* End of MultiPortSwitch: '<S28>/Multiport Switch' */

  /* Reshape: '<S28>/Reshape' incorporates:
   *  VariantMerge generated from: '<S4>/actuator_cmd'
   */
  for (i = 0; i < 6; i++) {
    Controller_Y.Control_Out.actuator_cmd[i] = rtb_MultiportSwitch_i[i];
  }

  for (i = 0; i < 10; i++) {
    Controller_Y.Control_Out.actuator_cmd[i + 6] = 0U;
  }

  /* End of Reshape: '<S28>/Reshape' */
  /* End of Outputs for SubSystem: '<S4>/Hexacopter_+' */
#elif AIRFRAME == 4

  /* Outputs for Atomic SubSystem: '<S4>/Hexacopter_x' */
  /* MultiPortSwitch: '<S34>/Multiport Switch' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  switch (Controller_U.FMS_Out.status) {
   case 1:
    for (i = 0; i < 6; i++) {
      rtb_MultiportSwitch_i[i] = 1000U;
    }
    break;

   case 2:
    for (i = 0; i < 6; i++) {
      rtb_MultiportSwitch_i[i] = 1150U;
    }
    break;

   case 3:
    /* Switch: '<S33>/Switch' incorporates:
     *  Constant: '<S36>/Constant'
     *  Constant: '<S37>/Constant'
     *  Logic: '<S33>/Logical Operator'
     *  RelationalOperator: '<S36>/Compare'
     *  RelationalOperator: '<S37>/Compare'
     *  Switch: '<S33>/Switch1'
     */
    if ((Controller_U.FMS_Out.ctrl_mode == 1) || (Controller_U.FMS_Out.ctrl_mode
         == 2) || (Controller_U.FMS_Out.ctrl_mode == 3)) {
      rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
    } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
      /* Switch: '<S38>/Switch' incorporates:
       *  Constant: '<S35>/Constant1'
       *  DataTypeConversion: '<S35>/Data Type Conversion'
       *  Gain: '<S35>/Gain1'
       *  S-Function (sfix_bitop): '<S38>/cmd_throttle valid'
       *  Saturate: '<S35>/Saturation'
       *  Sum: '<S35>/Sum1'
       *  Switch: '<S33>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 4096U) > 0U) {
        rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
      } else {
        /* Sum: '<S35>/Sum' incorporates:
         *  Constant: '<S35>/hover_throttle'
         *  Saturate: '<S10>/Saturation2'
         */
        rtb_Saturation_d_idx_0 = rtb_Saturation_idx_1 + CONTROL_PARAM.HOVER_THRO;

        /* Saturate: '<S35>/Saturation' */
        if (rtb_Saturation_d_idx_0 > 1.0F) {
          rtb_Saturation_d_idx_0 = 1.0F;
        } else if (rtb_Saturation_d_idx_0 < 0.0F) {
          rtb_Saturation_d_idx_0 = 0.0F;
        }

        rtb_throttle_cmd_f = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation_d_idx_0), 4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S38>/Switch' */
    } else {
      /* Sum: '<S35>/Sum' incorporates:
       *  Constant: '<S35>/hover_throttle'
       *  Saturate: '<S10>/Saturation2'
       */
      rtb_Saturation_d_idx_0 = rtb_Saturation_idx_1 + CONTROL_PARAM.HOVER_THRO;

      /* Saturate: '<S35>/Saturation' */
      if (rtb_Saturation_d_idx_0 > 1.0F) {
        rtb_Saturation_d_idx_0 = 1.0F;
      } else if (rtb_Saturation_d_idx_0 < 0.0F) {
        rtb_Saturation_d_idx_0 = 0.0F;
      }

      /* Switch: '<S33>/Switch1' incorporates:
       *  Constant: '<S35>/Constant1'
       *  DataTypeConversion: '<S35>/Data Type Conversion'
       *  Gain: '<S35>/Gain1'
       *  Saturate: '<S35>/Saturation'
       *  Sum: '<S35>/Sum1'
       */
      rtb_throttle_cmd_f = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        rtb_Saturation_d_idx_0), 4.2949673E+9F) + 1000U);
    }

    /* End of Switch: '<S33>/Switch' */

    /* Saturate: '<S10>/Saturation1' */
    if (rtb_Add_g_idx_0 > 1.0F) {
      rtb_Saturation_idx_0 = 1.0F;
    } else if (rtb_Add_g_idx_0 < -1.0F) {
      rtb_Saturation_idx_0 = -1.0F;
    } else {
      rtb_Saturation_idx_0 = rtb_Add_g_idx_0;
    }

    if (rtb_Saturation_d_idx_1 > 1.0F) {
      rtb_Subtract3_i = 1.0F;
    } else if (rtb_Saturation_d_idx_1 < -1.0F) {
      rtb_Subtract3_i = -1.0F;
    } else {
      rtb_Subtract3_i = rtb_Saturation_d_idx_1;
    }

    if (rtb_Saturation_d_idx_2 > 1.0F) {
      rtb_Add3 = 1.0F;
    } else if (rtb_Saturation_d_idx_2 < -1.0F) {
      rtb_Add3 = -1.0F;
    } else {
      rtb_Add3 = rtb_Saturation_d_idx_2;
    }

    /* End of Saturate: '<S10>/Saturation1' */

    /* Product: '<S10>/Multiply' */
    for (i = 0; i < 6; i++) {
      /* Saturate: '<S10>/Saturation' incorporates:
       *  Constant: '<S10>/Effective_Matrix'
       *  Gain: '<S10>/Gain'
       *  MultiPortSwitch: '<S34>/Multiport Switch'
       *  Sum: '<S10>/Add'
       */
      rtb_Saturation_d_idx_0 = fmodf(floorf
        (((Controller_ConstP.Effective_Matrix_Value_f[i + 6] * rtb_Subtract3_i +
           Controller_ConstP.Effective_Matrix_Value_f[i] * rtb_Saturation_idx_0)
          + Controller_ConstP.Effective_Matrix_Value_f[i + 12] * rtb_Add3) *
         1000.0F + (real32_T)rtb_throttle_cmd_f), 65536.0F);
      u0 = (uint16_T)(rtb_Saturation_d_idx_0 < 0.0F ? (int32_T)(uint16_T)
                      -(int16_T)(uint16_T)-rtb_Saturation_d_idx_0 : (int32_T)
                      (uint16_T)rtb_Saturation_d_idx_0);
      if (u0 > 1900) {
        rtb_MultiportSwitch_i[i] = 1900U;
      } else if (u0 < 1100) {
        rtb_MultiportSwitch_i[i] = 1100U;
      } else {
        rtb_MultiportSwitch_i[i] = u0;
      }

      /* End of Saturate: '<S10>/Saturation' */
    }

    /* End of Product: '<S10>/Multiply' */
    break;

   default:
    for (i = 0; i < 6; i++) {
      rtb_MultiportSwitch_i[i] = 1000U;
    }
    break;
  }

  /* End of MultiPortSwitch: '<S34>/Multiport Switch' */

  /* Reshape: '<S34>/Reshape' incorporates:
   *  VariantMerge generated from: '<S4>/actuator_cmd'
   */
  for (i = 0; i < 6; i++) {
    Controller_Y.Control_Out.actuator_cmd[i] = rtb_MultiportSwitch_i[i];
  }

  for (i = 0; i < 10; i++) {
    Controller_Y.Control_Out.actuator_cmd[i + 6] = 0U;
  }

  /* End of Reshape: '<S34>/Reshape' */
  /* End of Outputs for SubSystem: '<S4>/Hexacopter_x' */
#elif AIRFRAME == 8

  /* Outputs for Atomic SubSystem: '<S4>/Octocopter_+' */
  /* MultiPortSwitch: '<S40>/Multiport Switch' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  switch (Controller_U.FMS_Out.status) {
   case 1:
    for (i = 0; i < 8; i++) {
      rtb_MultiportSwitch_ev[i] = 1000U;
    }
    break;

   case 2:
    for (i = 0; i < 8; i++) {
      rtb_MultiportSwitch_ev[i] = 1150U;
    }
    break;

   case 3:
    /* Switch: '<S39>/Switch' incorporates:
     *  Constant: '<S42>/Constant'
     *  Constant: '<S43>/Constant'
     *  Logic: '<S39>/Logical Operator'
     *  RelationalOperator: '<S42>/Compare'
     *  RelationalOperator: '<S43>/Compare'
     *  Switch: '<S39>/Switch1'
     */
    if ((Controller_U.FMS_Out.ctrl_mode == 1) || (Controller_U.FMS_Out.ctrl_mode
         == 2) || (Controller_U.FMS_Out.ctrl_mode == 3)) {
      rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
    } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
      /* Switch: '<S44>/Switch' incorporates:
       *  Constant: '<S41>/Constant1'
       *  DataTypeConversion: '<S41>/Data Type Conversion'
       *  Gain: '<S41>/Gain1'
       *  S-Function (sfix_bitop): '<S44>/cmd_throttle valid'
       *  Saturate: '<S41>/Saturation'
       *  Sum: '<S41>/Sum1'
       *  Switch: '<S39>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 4096U) > 0U) {
        rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
      } else {
        /* Sum: '<S41>/Sum' incorporates:
         *  Constant: '<S41>/hover_throttle'
         *  Saturate: '<S11>/Saturation2'
         */
        rtb_Saturation_d_idx_0 = rtb_Saturation_idx_1 + CONTROL_PARAM.HOVER_THRO;

        /* Saturate: '<S41>/Saturation' */
        if (rtb_Saturation_d_idx_0 > 1.0F) {
          rtb_Saturation_d_idx_0 = 1.0F;
        } else if (rtb_Saturation_d_idx_0 < 0.0F) {
          rtb_Saturation_d_idx_0 = 0.0F;
        }

        rtb_throttle_cmd_f = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation_d_idx_0), 4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S44>/Switch' */
    } else {
      /* Sum: '<S41>/Sum' incorporates:
       *  Constant: '<S41>/hover_throttle'
       *  Saturate: '<S11>/Saturation2'
       */
      rtb_Saturation_d_idx_0 = rtb_Saturation_idx_1 + CONTROL_PARAM.HOVER_THRO;

      /* Saturate: '<S41>/Saturation' */
      if (rtb_Saturation_d_idx_0 > 1.0F) {
        rtb_Saturation_d_idx_0 = 1.0F;
      } else if (rtb_Saturation_d_idx_0 < 0.0F) {
        rtb_Saturation_d_idx_0 = 0.0F;
      }

      /* Switch: '<S39>/Switch1' incorporates:
       *  Constant: '<S41>/Constant1'
       *  DataTypeConversion: '<S41>/Data Type Conversion'
       *  Gain: '<S41>/Gain1'
       *  Saturate: '<S41>/Saturation'
       *  Sum: '<S41>/Sum1'
       */
      rtb_throttle_cmd_f = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        rtb_Saturation_d_idx_0), 4.2949673E+9F) + 1000U);
    }

    /* End of Switch: '<S39>/Switch' */

    /* Saturate: '<S11>/Saturation1' */
    if (rtb_Add_g_idx_0 > 1.0F) {
      rtb_Saturation_idx_0 = 1.0F;
    } else if (rtb_Add_g_idx_0 < -1.0F) {
      rtb_Saturation_idx_0 = -1.0F;
    } else {
      rtb_Saturation_idx_0 = rtb_Add_g_idx_0;
    }

    if (rtb_Saturation_d_idx_1 > 1.0F) {
      rtb_Subtract3_i = 1.0F;
    } else if (rtb_Saturation_d_idx_1 < -1.0F) {
      rtb_Subtract3_i = -1.0F;
    } else {
      rtb_Subtract3_i = rtb_Saturation_d_idx_1;
    }

    if (rtb_Saturation_d_idx_2 > 1.0F) {
      rtb_Add3 = 1.0F;
    } else if (rtb_Saturation_d_idx_2 < -1.0F) {
      rtb_Add3 = -1.0F;
    } else {
      rtb_Add3 = rtb_Saturation_d_idx_2;
    }

    /* End of Saturate: '<S11>/Saturation1' */

    /* Product: '<S11>/Multiply' */
    for (i = 0; i < 8; i++) {
      /* Saturate: '<S11>/Saturation' incorporates:
       *  Constant: '<S11>/Effective_Matrix'
       *  Gain: '<S11>/Gain'
       *  MultiPortSwitch: '<S40>/Multiport Switch'
       *  Sum: '<S11>/Add'
       */
      rtb_Saturation_d_idx_0 = fmodf(floorf
        (((Controller_ConstP.Effective_Matrix_Value_m[i + 8] * rtb_Subtract3_i +
           Controller_ConstP.Effective_Matrix_Value_m[i] * rtb_Saturation_idx_0)
          + Controller_ConstP.Effective_Matrix_Value_m[i + 16] * rtb_Add3) *
         1000.0F + (real32_T)rtb_throttle_cmd_f), 65536.0F);
      u0 = (uint16_T)(rtb_Saturation_d_idx_0 < 0.0F ? (int32_T)(uint16_T)
                      -(int16_T)(uint16_T)-rtb_Saturation_d_idx_0 : (int32_T)
                      (uint16_T)rtb_Saturation_d_idx_0);
      if (u0 > 1900) {
        rtb_MultiportSwitch_ev[i] = 1900U;
      } else if (u0 < 1100) {
        rtb_MultiportSwitch_ev[i] = 1100U;
      } else {
        rtb_MultiportSwitch_ev[i] = u0;
      }

      /* End of Saturate: '<S11>/Saturation' */
    }

    /* End of Product: '<S11>/Multiply' */
    break;

   default:
    for (i = 0; i < 8; i++) {
      rtb_MultiportSwitch_ev[i] = 1000U;
    }
    break;
  }

  /* End of MultiPortSwitch: '<S40>/Multiport Switch' */

  /* Reshape: '<S40>/Reshape' incorporates:
   *  VariantMerge generated from: '<S4>/actuator_cmd'
   */
  for (i = 0; i < 8; i++) {
    Controller_Y.Control_Out.actuator_cmd[i] = rtb_MultiportSwitch_ev[i];
    Controller_Y.Control_Out.actuator_cmd[i + 8] = 0U;
  }

  /* End of Reshape: '<S40>/Reshape' */
  /* End of Outputs for SubSystem: '<S4>/Octocopter_+' */
#elif AIRFRAME == 7

  /* Outputs for Atomic SubSystem: '<S4>/Octocopter_x' */
  /* MultiPortSwitch: '<S46>/Multiport Switch' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  switch (Controller_U.FMS_Out.status) {
   case 1:
    for (i = 0; i < 8; i++) {
      rtb_MultiportSwitch_ev[i] = 1000U;
    }
    break;

   case 2:
    for (i = 0; i < 8; i++) {
      rtb_MultiportSwitch_ev[i] = 1150U;
    }
    break;

   case 3:
    /* Switch: '<S45>/Switch' incorporates:
     *  Constant: '<S48>/Constant'
     *  Constant: '<S49>/Constant'
     *  Logic: '<S45>/Logical Operator'
     *  RelationalOperator: '<S48>/Compare'
     *  RelationalOperator: '<S49>/Compare'
     *  Switch: '<S45>/Switch1'
     */
    if ((Controller_U.FMS_Out.ctrl_mode == 1) || (Controller_U.FMS_Out.ctrl_mode
         == 2) || (Controller_U.FMS_Out.ctrl_mode == 3)) {
      rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
    } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
      /* Switch: '<S50>/Switch' incorporates:
       *  Constant: '<S47>/Constant1'
       *  DataTypeConversion: '<S47>/Data Type Conversion'
       *  Gain: '<S47>/Gain1'
       *  S-Function (sfix_bitop): '<S50>/cmd_throttle valid'
       *  Saturate: '<S47>/Saturation'
       *  Sum: '<S47>/Sum1'
       *  Switch: '<S45>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 4096U) > 0U) {
        rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
      } else {
        /* Sum: '<S47>/Sum' incorporates:
         *  Constant: '<S47>/hover_throttle'
         *  Saturate: '<S12>/Saturation2'
         */
        rtb_Saturation_d_idx_0 = rtb_Saturation_idx_1 + CONTROL_PARAM.HOVER_THRO;

        /* Saturate: '<S47>/Saturation' */
        if (rtb_Saturation_d_idx_0 > 1.0F) {
          rtb_Saturation_d_idx_0 = 1.0F;
        } else if (rtb_Saturation_d_idx_0 < 0.0F) {
          rtb_Saturation_d_idx_0 = 0.0F;
        }

        rtb_throttle_cmd_f = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation_d_idx_0), 4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S50>/Switch' */
    } else {
      /* Sum: '<S47>/Sum' incorporates:
       *  Constant: '<S47>/hover_throttle'
       *  Saturate: '<S12>/Saturation2'
       */
      rtb_Saturation_d_idx_0 = rtb_Saturation_idx_1 + CONTROL_PARAM.HOVER_THRO;

      /* Saturate: '<S47>/Saturation' */
      if (rtb_Saturation_d_idx_0 > 1.0F) {
        rtb_Saturation_d_idx_0 = 1.0F;
      } else if (rtb_Saturation_d_idx_0 < 0.0F) {
        rtb_Saturation_d_idx_0 = 0.0F;
      }

      /* Switch: '<S45>/Switch1' incorporates:
       *  Constant: '<S47>/Constant1'
       *  DataTypeConversion: '<S47>/Data Type Conversion'
       *  Gain: '<S47>/Gain1'
       *  Saturate: '<S47>/Saturation'
       *  Sum: '<S47>/Sum1'
       */
      rtb_throttle_cmd_f = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        rtb_Saturation_d_idx_0), 4.2949673E+9F) + 1000U);
    }

    /* End of Switch: '<S45>/Switch' */

    /* Saturate: '<S12>/Saturation1' */
    if (rtb_Add_g_idx_0 > 1.0F) {
      rtb_Saturation_idx_0 = 1.0F;
    } else if (rtb_Add_g_idx_0 < -1.0F) {
      rtb_Saturation_idx_0 = -1.0F;
    } else {
      rtb_Saturation_idx_0 = rtb_Add_g_idx_0;
    }

    if (rtb_Saturation_d_idx_1 > 1.0F) {
      rtb_Subtract3_i = 1.0F;
    } else if (rtb_Saturation_d_idx_1 < -1.0F) {
      rtb_Subtract3_i = -1.0F;
    } else {
      rtb_Subtract3_i = rtb_Saturation_d_idx_1;
    }

    if (rtb_Saturation_d_idx_2 > 1.0F) {
      rtb_Add3 = 1.0F;
    } else if (rtb_Saturation_d_idx_2 < -1.0F) {
      rtb_Add3 = -1.0F;
    } else {
      rtb_Add3 = rtb_Saturation_d_idx_2;
    }

    /* End of Saturate: '<S12>/Saturation1' */

    /* Product: '<S12>/Multiply' */
    for (i = 0; i < 8; i++) {
      /* Saturate: '<S12>/Saturation' incorporates:
       *  Constant: '<S12>/Effective_Matrix'
       *  Gain: '<S12>/Gain'
       *  MultiPortSwitch: '<S46>/Multiport Switch'
       *  Sum: '<S12>/Add'
       */
      rtb_Saturation_d_idx_0 = fmodf(floorf
        (((Controller_ConstP.Effective_Matrix_Value_k[i + 8] * rtb_Subtract3_i +
           Controller_ConstP.Effective_Matrix_Value_k[i] * rtb_Saturation_idx_0)
          + Controller_ConstP.Effective_Matrix_Value_k[i + 16] * rtb_Add3) *
         1000.0F + (real32_T)rtb_throttle_cmd_f), 65536.0F);
      u0 = (uint16_T)(rtb_Saturation_d_idx_0 < 0.0F ? (int32_T)(uint16_T)
                      -(int16_T)(uint16_T)-rtb_Saturation_d_idx_0 : (int32_T)
                      (uint16_T)rtb_Saturation_d_idx_0);
      if (u0 > 1900) {
        rtb_MultiportSwitch_ev[i] = 1900U;
      } else if (u0 < 1100) {
        rtb_MultiportSwitch_ev[i] = 1100U;
      } else {
        rtb_MultiportSwitch_ev[i] = u0;
      }

      /* End of Saturate: '<S12>/Saturation' */
    }

    /* End of Product: '<S12>/Multiply' */
    break;

   default:
    for (i = 0; i < 8; i++) {
      rtb_MultiportSwitch_ev[i] = 1000U;
    }
    break;
  }

  /* End of MultiPortSwitch: '<S46>/Multiport Switch' */

  /* Reshape: '<S46>/Reshape' incorporates:
   *  VariantMerge generated from: '<S4>/actuator_cmd'
   */
  for (i = 0; i < 8; i++) {
    Controller_Y.Control_Out.actuator_cmd[i] = rtb_MultiportSwitch_ev[i];
    Controller_Y.Control_Out.actuator_cmd[i + 8] = 0U;
  }

  /* End of Reshape: '<S46>/Reshape' */
  /* End of Outputs for SubSystem: '<S4>/Octocopter_x' */
#elif AIRFRAME == 2

  /* Outputs for Atomic SubSystem: '<S4>/Quadcopter_+' */
  /* MultiPortSwitch: '<S52>/Multiport Switch' incorporates:
   *  Constant: '<S52>/Disarm'
   *  Constant: '<S52>/Standby'
   *  Inport: '<Root>/FMS_Out'
   */
  switch (Controller_U.FMS_Out.status) {
   case 1:
    rtb_MultiportSwitch_b0[0] = 1000U;
    rtb_MultiportSwitch_b0[1] = 1000U;
    rtb_MultiportSwitch_b0[2] = 1000U;
    rtb_MultiportSwitch_b0[3] = 1000U;
    break;

   case 2:
    rtb_MultiportSwitch_b0[0] = 1150U;
    rtb_MultiportSwitch_b0[1] = 1150U;
    rtb_MultiportSwitch_b0[2] = 1150U;
    rtb_MultiportSwitch_b0[3] = 1150U;
    break;

   case 3:
    /* Switch: '<S51>/Switch' incorporates:
     *  Constant: '<S54>/Constant'
     *  Constant: '<S55>/Constant'
     *  Logic: '<S51>/Logical Operator'
     *  RelationalOperator: '<S54>/Compare'
     *  RelationalOperator: '<S55>/Compare'
     *  Switch: '<S51>/Switch1'
     */
    if ((Controller_U.FMS_Out.ctrl_mode == 1) || (Controller_U.FMS_Out.ctrl_mode
         == 2) || (Controller_U.FMS_Out.ctrl_mode == 3)) {
      rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
    } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
      /* Switch: '<S56>/Switch' incorporates:
       *  Constant: '<S53>/Constant1'
       *  DataTypeConversion: '<S53>/Data Type Conversion'
       *  Gain: '<S53>/Gain1'
       *  S-Function (sfix_bitop): '<S56>/cmd_throttle valid'
       *  Saturate: '<S53>/Saturation'
       *  Sum: '<S53>/Sum1'
       *  Switch: '<S51>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 4096U) > 0U) {
        rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
      } else {
        /* Sum: '<S53>/Sum' incorporates:
         *  Constant: '<S53>/hover_throttle'
         *  Saturate: '<S13>/Saturation2'
         */
        rtb_Saturation_d_idx_0 = rtb_Saturation_idx_1 + CONTROL_PARAM.HOVER_THRO;

        /* Saturate: '<S53>/Saturation' */
        if (rtb_Saturation_d_idx_0 > 1.0F) {
          rtb_Saturation_d_idx_0 = 1.0F;
        } else if (rtb_Saturation_d_idx_0 < 0.0F) {
          rtb_Saturation_d_idx_0 = 0.0F;
        }

        rtb_throttle_cmd_f = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation_d_idx_0), 4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S56>/Switch' */
    } else {
      /* Sum: '<S53>/Sum' incorporates:
       *  Constant: '<S53>/hover_throttle'
       *  Saturate: '<S13>/Saturation2'
       */
      rtb_Saturation_d_idx_0 = rtb_Saturation_idx_1 + CONTROL_PARAM.HOVER_THRO;

      /* Saturate: '<S53>/Saturation' */
      if (rtb_Saturation_d_idx_0 > 1.0F) {
        rtb_Saturation_d_idx_0 = 1.0F;
      } else if (rtb_Saturation_d_idx_0 < 0.0F) {
        rtb_Saturation_d_idx_0 = 0.0F;
      }

      /* Switch: '<S51>/Switch1' incorporates:
       *  Constant: '<S53>/Constant1'
       *  DataTypeConversion: '<S53>/Data Type Conversion'
       *  Gain: '<S53>/Gain1'
       *  Saturate: '<S53>/Saturation'
       *  Sum: '<S53>/Sum1'
       */
      rtb_throttle_cmd_f = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        rtb_Saturation_d_idx_0), 4.2949673E+9F) + 1000U);
    }

    /* End of Switch: '<S51>/Switch' */

    /* Saturate: '<S13>/Saturation1' */
    if (rtb_Add_g_idx_0 > 1.0F) {
      rtb_Saturation_idx_0 = 1.0F;
    } else if (rtb_Add_g_idx_0 < -1.0F) {
      rtb_Saturation_idx_0 = -1.0F;
    } else {
      rtb_Saturation_idx_0 = rtb_Add_g_idx_0;
    }

    if (rtb_Saturation_d_idx_1 > 1.0F) {
      rtb_Subtract3_i = 1.0F;
    } else if (rtb_Saturation_d_idx_1 < -1.0F) {
      rtb_Subtract3_i = -1.0F;
    } else {
      rtb_Subtract3_i = rtb_Saturation_d_idx_1;
    }

    if (rtb_Saturation_d_idx_2 > 1.0F) {
      rtb_Add3 = 1.0F;
    } else if (rtb_Saturation_d_idx_2 < -1.0F) {
      rtb_Add3 = -1.0F;
    } else {
      rtb_Add3 = rtb_Saturation_d_idx_2;
    }

    /* End of Saturate: '<S13>/Saturation1' */

    /* Product: '<S13>/Multiply' */
    for (i = 0; i < 4; i++) {
      /* Saturate: '<S13>/Saturation' incorporates:
       *  Constant: '<S13>/Effective_Matrix'
       *  Gain: '<S13>/Gain'
       *  MultiPortSwitch: '<S52>/Multiport Switch'
       *  Sum: '<S13>/Add'
       */
      rtb_Saturation_d_idx_0 = fmodf(floorf
        (((Controller_ConstP.Effective_Matrix_Value_fr[i + 4] * rtb_Subtract3_i
           + Controller_ConstP.Effective_Matrix_Value_fr[i] *
           rtb_Saturation_idx_0) + Controller_ConstP.Effective_Matrix_Value_fr[i
          + 8] * rtb_Add3) * 1000.0F + (real32_T)rtb_throttle_cmd_f), 65536.0F);
      u0 = (uint16_T)(rtb_Saturation_d_idx_0 < 0.0F ? (int32_T)(uint16_T)
                      -(int16_T)(uint16_T)-rtb_Saturation_d_idx_0 : (int32_T)
                      (uint16_T)rtb_Saturation_d_idx_0);
      if (u0 > 1900) {
        rtb_MultiportSwitch_b0[i] = 1900U;
      } else if (u0 < 1100) {
        rtb_MultiportSwitch_b0[i] = 1100U;
      } else {
        rtb_MultiportSwitch_b0[i] = u0;
      }

      /* End of Saturate: '<S13>/Saturation' */
    }

    /* End of Product: '<S13>/Multiply' */
    break;

   default:
    rtb_MultiportSwitch_b0[0] = 1000U;
    rtb_MultiportSwitch_b0[1] = 1000U;
    rtb_MultiportSwitch_b0[2] = 1000U;
    rtb_MultiportSwitch_b0[3] = 1000U;
    break;
  }

  /* End of MultiPortSwitch: '<S52>/Multiport Switch' */

  /* Reshape: '<S52>/Reshape' incorporates:
   *  VariantMerge generated from: '<S4>/actuator_cmd'
   */
  Controller_Y.Control_Out.actuator_cmd[0] = rtb_MultiportSwitch_b0[0];
  Controller_Y.Control_Out.actuator_cmd[1] = rtb_MultiportSwitch_b0[1];
  Controller_Y.Control_Out.actuator_cmd[2] = rtb_MultiportSwitch_b0[2];
  Controller_Y.Control_Out.actuator_cmd[3] = rtb_MultiportSwitch_b0[3];
  for (i = 0; i < 12; i++) {
    Controller_Y.Control_Out.actuator_cmd[i + 4] = 0U;
  }

  /* End of Reshape: '<S52>/Reshape' */
  /* End of Outputs for SubSystem: '<S4>/Quadcopter_+' */
#elif AIRFRAME == 1

  /* Outputs for Atomic SubSystem: '<S4>/Quadcopter_x' */
  /* MultiPortSwitch: '<S58>/Multiport Switch' incorporates:
   *  Constant: '<S58>/Disarm'
   *  Constant: '<S58>/Standby'
   *  Inport: '<Root>/FMS_Out'
   */
  switch (Controller_U.FMS_Out.status) {
   case 1:
    rtb_MultiportSwitch_b0[0] = 1000U;
    rtb_MultiportSwitch_b0[1] = 1000U;
    rtb_MultiportSwitch_b0[2] = 1000U;
    rtb_MultiportSwitch_b0[3] = 1000U;
    break;

   case 2:
    rtb_MultiportSwitch_b0[0] = 1150U;
    rtb_MultiportSwitch_b0[1] = 1150U;
    rtb_MultiportSwitch_b0[2] = 1150U;
    rtb_MultiportSwitch_b0[3] = 1150U;
    break;

   case 3:
    /* Switch: '<S57>/Switch' incorporates:
     *  Constant: '<S60>/Constant'
     *  Constant: '<S61>/Constant'
     *  Logic: '<S57>/Logical Operator'
     *  RelationalOperator: '<S60>/Compare'
     *  RelationalOperator: '<S61>/Compare'
     *  Switch: '<S57>/Switch1'
     */
    if ((Controller_U.FMS_Out.ctrl_mode == 1) || (Controller_U.FMS_Out.ctrl_mode
         == 2) || (Controller_U.FMS_Out.ctrl_mode == 3)) {
      rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
    } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
      /* Switch: '<S62>/Switch' incorporates:
       *  Constant: '<S59>/Constant1'
       *  DataTypeConversion: '<S59>/Data Type Conversion'
       *  Gain: '<S59>/Gain1'
       *  S-Function (sfix_bitop): '<S62>/cmd_throttle valid'
       *  Saturate: '<S59>/Saturation'
       *  Sum: '<S59>/Sum1'
       *  Switch: '<S57>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 4096U) > 0U) {
        rtb_throttle_cmd_f = Controller_U.FMS_Out.throttle_cmd;
      } else {
        /* Sum: '<S59>/Sum' incorporates:
         *  Constant: '<S59>/hover_throttle'
         *  Saturate: '<S14>/Saturation2'
         */
        rtb_Saturation_d_idx_0 = rtb_Saturation_idx_1 + CONTROL_PARAM.HOVER_THRO;

        /* Saturate: '<S59>/Saturation' */
        if (rtb_Saturation_d_idx_0 > 1.0F) {
          rtb_Saturation_d_idx_0 = 1.0F;
        } else if (rtb_Saturation_d_idx_0 < 0.0F) {
          rtb_Saturation_d_idx_0 = 0.0F;
        }

        rtb_throttle_cmd_f = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation_d_idx_0), 4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S62>/Switch' */
    } else {
      /* Sum: '<S59>/Sum' incorporates:
       *  Constant: '<S59>/hover_throttle'
       *  Saturate: '<S14>/Saturation2'
       */
      rtb_Saturation_d_idx_0 = rtb_Saturation_idx_1 + CONTROL_PARAM.HOVER_THRO;

      /* Saturate: '<S59>/Saturation' */
      if (rtb_Saturation_d_idx_0 > 1.0F) {
        rtb_Saturation_d_idx_0 = 1.0F;
      } else if (rtb_Saturation_d_idx_0 < 0.0F) {
        rtb_Saturation_d_idx_0 = 0.0F;
      }

      /* Switch: '<S57>/Switch1' incorporates:
       *  Constant: '<S59>/Constant1'
       *  DataTypeConversion: '<S59>/Data Type Conversion'
       *  Gain: '<S59>/Gain1'
       *  Saturate: '<S59>/Saturation'
       *  Sum: '<S59>/Sum1'
       */
      rtb_throttle_cmd_f = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        rtb_Saturation_d_idx_0), 4.2949673E+9F) + 1000U);
    }

    /* End of Switch: '<S57>/Switch' */

    /* Saturate: '<S14>/Saturation1' */
    if (rtb_Add_g_idx_0 > 1.0F) {
      rtb_Add_g_idx_0 = 1.0F;
    } else if (rtb_Add_g_idx_0 < -1.0F) {
      rtb_Add_g_idx_0 = -1.0F;
    }

    if (rtb_Saturation_d_idx_1 > 1.0F) {
      rtb_Saturation_d_idx_1 = 1.0F;
    } else if (rtb_Saturation_d_idx_1 < -1.0F) {
      rtb_Saturation_d_idx_1 = -1.0F;
    }

    if (rtb_Saturation_d_idx_2 > 1.0F) {
      rtb_Saturation_d_idx_2 = 1.0F;
    } else if (rtb_Saturation_d_idx_2 < -1.0F) {
      rtb_Saturation_d_idx_2 = -1.0F;
    }

    /* End of Saturate: '<S14>/Saturation1' */

    /* Product: '<S14>/Multiply' */
    for (i = 0; i < 4; i++) {
      /* Saturate: '<S14>/Saturation' incorporates:
       *  Constant: '<S14>/Effective_Matrix'
       *  Gain: '<S14>/Gain'
       *  MultiPortSwitch: '<S58>/Multiport Switch'
       *  Sum: '<S14>/Add'
       */
      rtb_Saturation_d_idx_0 = fmodf(floorf
        (((Controller_ConstP.Effective_Matrix_Value_h[i + 4] *
           rtb_Saturation_d_idx_1 + Controller_ConstP.Effective_Matrix_Value_h[i]
           * rtb_Add_g_idx_0) + Controller_ConstP.Effective_Matrix_Value_h[i + 8]
          * rtb_Saturation_d_idx_2) * 1000.0F + (real32_T)rtb_throttle_cmd_f),
        65536.0F);
      u0 = (uint16_T)(rtb_Saturation_d_idx_0 < 0.0F ? (int32_T)(uint16_T)
                      -(int16_T)(uint16_T)-rtb_Saturation_d_idx_0 : (int32_T)
                      (uint16_T)rtb_Saturation_d_idx_0);
      if (u0 > 1900) {
        rtb_MultiportSwitch_b0[i] = 1900U;
      } else if (u0 < 1100) {
        rtb_MultiportSwitch_b0[i] = 1100U;
      } else {
        rtb_MultiportSwitch_b0[i] = u0;
      }

      /* End of Saturate: '<S14>/Saturation' */
    }

    /* End of Product: '<S14>/Multiply' */
    break;

   default:
    rtb_MultiportSwitch_b0[0] = 1000U;
    rtb_MultiportSwitch_b0[1] = 1000U;
    rtb_MultiportSwitch_b0[2] = 1000U;
    rtb_MultiportSwitch_b0[3] = 1000U;
    break;
  }

  /* End of MultiPortSwitch: '<S58>/Multiport Switch' */

  /* Reshape: '<S58>/Reshape' incorporates:
   *  VariantMerge generated from: '<S4>/actuator_cmd'
   */
  Controller_Y.Control_Out.actuator_cmd[0] = rtb_MultiportSwitch_b0[0];
  Controller_Y.Control_Out.actuator_cmd[1] = rtb_MultiportSwitch_b0[1];
  Controller_Y.Control_Out.actuator_cmd[2] = rtb_MultiportSwitch_b0[2];
  Controller_Y.Control_Out.actuator_cmd[3] = rtb_MultiportSwitch_b0[3];
  for (i = 0; i < 12; i++) {
    Controller_Y.Control_Out.actuator_cmd[i + 4] = 0U;
  }

  /* End of Reshape: '<S58>/Reshape' */
  /* End of Outputs for SubSystem: '<S4>/Quadcopter_x' */
#endif

  /* End of Outputs for SubSystem: '<S2>/Control_Allocation' */

  /* Product: '<S75>/Multiply' incorporates:
   *  Constant: '<S75>/gain1'
   *  Constant: '<S75>/gain2'
   *  Constant: '<S75>/gain3'
   *  DiscreteIntegrator: '<S73>/Discrete-Time Integrator5'
   */
  rtb_Saturation_d_idx_0 = CONTROL_PARAM.ROLL_RATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0];
  rtb_Saturation_d_idx_1 = CONTROL_PARAM.PITCH_RATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1];
  rtb_Saturation_d_idx_2 = CONTROL_PARAM.YAW_RATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2];

  /* Product: '<S100>/Multiply1' incorporates:
   *  Constant: '<S100>/const1'
   *  DiscreteIntegrator: '<S97>/Integrator'
   */
  rtb_Saturation_idx_0 = Controller_DW.Integrator_DSTATE[0] * 0.05F;
  rtb_Saturation_idx_1 = Controller_DW.Integrator_DSTATE[1] * 0.05F;

  /* Sum: '<S100>/Add' incorporates:
   *  DiscreteIntegrator: '<S97>/Integrator1'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S97>/Subtract'
   */
  rtb_Subtract3_idx_0 = (Controller_DW.Integrator1_DSTATE[0] -
    Controller_U.FMS_Out.u_cmd) + rtb_Saturation_idx_0;
  rtb_Subtract3_idx_1 = (Controller_DW.Integrator1_DSTATE[1] -
    Controller_U.FMS_Out.v_cmd) + rtb_Saturation_idx_1;

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   */
  Controller_Y.Control_Out.timestamp =
    Controller_DW.DiscreteTimeIntegrator_DSTATE_n;

  /* Product: '<S114>/Multiply1' incorporates:
   *  Constant: '<S114>/const1'
   *  DiscreteIntegrator: '<S113>/Integrator'
   */
  rtb_Add3 = Controller_DW.Integrator_DSTATE_p * 0.05F;

  /* Sum: '<S114>/Add' incorporates:
   *  DiscreteIntegrator: '<S113>/Integrator1'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S113>/Subtract'
   */
  rtb_Subtract3_i = (Controller_DW.Integrator1_DSTATE_p -
                     Controller_U.FMS_Out.w_cmd) + rtb_Add3;

  /* Signum: '<S114>/Sign' */
  if (rtb_Subtract3_i < 0.0F) {
    i = -1;
  } else {
    i = (rtb_Subtract3_i > 0.0F);
  }

  /* Sum: '<S114>/Add2' incorporates:
   *  Abs: '<S114>/Abs'
   *  Gain: '<S114>/Gain'
   *  Gain: '<S114>/Gain1'
   *  Product: '<S114>/Multiply2'
   *  Product: '<S114>/Multiply3'
   *  Signum: '<S114>/Sign'
   *  Sqrt: '<S114>/Sqrt'
   *  Sum: '<S114>/Add1'
   *  Sum: '<S114>/Subtract'
   */
  rtb_a_n = (sqrtf((8.0F * fabsf(rtb_Subtract3_i) + Controller_ConstB.d_n) *
                   Controller_ConstB.d_n) - Controller_ConstB.d_n) * 0.5F *
    (real32_T)i + rtb_Add3;

  /* Sum: '<S114>/Add3' */
  u = rtb_Subtract3_i + Controller_ConstB.d_n;

  /* Sum: '<S114>/Subtract1' */
  u_0 = rtb_Subtract3_i - Controller_ConstB.d_n;

  /* Signum: '<S114>/Sign1' */
  if (u < 0.0F) {
    i = -1;
  } else {
    i = (u > 0.0F);
  }

  /* Signum: '<S114>/Sign2' */
  if (u_0 < 0.0F) {
    tmp = -1;
  } else {
    tmp = (u_0 > 0.0F);
  }

  /* Sum: '<S114>/Add5' incorporates:
   *  Gain: '<S114>/Gain2'
   *  Product: '<S114>/Multiply4'
   *  Signum: '<S114>/Sign1'
   *  Signum: '<S114>/Sign2'
   *  Sum: '<S114>/Add4'
   *  Sum: '<S114>/Subtract2'
   */
  rtb_a_n += ((rtb_Subtract3_i - rtb_a_n) + rtb_Add3) * ((real32_T)(i - tmp) *
    0.5F);

  /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S104>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

  /* Signum: '<S100>/Sign' */
  if (rtb_Subtract3_idx_0 < 0.0F) {
    i = -1;
  } else {
    i = (rtb_Subtract3_idx_0 > 0.0F);
  }

  /* Sum: '<S100>/Add2' incorporates:
   *  Abs: '<S100>/Abs'
   *  Gain: '<S100>/Gain'
   *  Gain: '<S100>/Gain1'
   *  Product: '<S100>/Multiply2'
   *  Product: '<S100>/Multiply3'
   *  Signum: '<S100>/Sign'
   *  Sqrt: '<S100>/Sqrt'
   *  Sum: '<S100>/Add1'
   *  Sum: '<S100>/Subtract'
   */
  rtb_Add_g_idx_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_idx_0) +
    Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
    (real32_T)i + rtb_Saturation_idx_0;

  /* Signum: '<S100>/Sign1' incorporates:
   *  Signum: '<S100>/Sign'
   *  Sum: '<S100>/Add3'
   */
  u = rtb_Subtract3_idx_0 + Controller_ConstB.d;

  /* Signum: '<S100>/Sign2' incorporates:
   *  Signum: '<S100>/Sign'
   *  Sum: '<S100>/Subtract1'
   */
  u_0 = rtb_Subtract3_idx_0 - Controller_ConstB.d;

  /* Signum: '<S100>/Sign1' */
  if (u < 0.0F) {
    i = -1;
  } else {
    i = (u > 0.0F);
  }

  /* Signum: '<S100>/Sign2' */
  if (u_0 < 0.0F) {
    tmp = -1;
  } else {
    tmp = (u_0 > 0.0F);
  }

  /* Sum: '<S100>/Add5' incorporates:
   *  Gain: '<S100>/Gain2'
   *  Product: '<S100>/Multiply4'
   *  Signum: '<S100>/Sign'
   *  Signum: '<S100>/Sign1'
   *  Signum: '<S100>/Sign2'
   *  Sum: '<S100>/Add2'
   *  Sum: '<S100>/Add4'
   *  Sum: '<S100>/Subtract2'
   */
  rtb_Subtract3_i = ((rtb_Subtract3_idx_0 - rtb_Add_g_idx_0) +
                     rtb_Saturation_idx_0) * ((real32_T)(i - tmp) * 0.5F) +
    rtb_Add_g_idx_0;

  /* Update for DiscreteIntegrator: '<S97>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S97>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE[0] += 0.004F *
    Controller_DW.Integrator_DSTATE[0];

  /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S102>/ki'
   *  Product: '<S102>/Multiply'
   */
  rtb_uv_error_C_mPs_idx_0 = CONTROL_PARAM.VEL_XY_I * rtb_uv_error_C_mPs_idx_0 *
    0.004F + Controller_DW.DiscreteTimeIntegrator_DSTATE[0];
  Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = rtb_uv_error_C_mPs_idx_0;
  if (rtb_uv_error_C_mPs_idx_0 > CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.VEL_XY_I_MAX;
  } else if (rtb_uv_error_C_mPs_idx_0 < CONTROL_PARAM.VEL_XY_I_MIN) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.VEL_XY_I_MIN;
  }

  /* Update for DiscreteIntegrator: '<S104>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.004F * rtb_Gain_idx_0;

  /* Signum: '<S100>/Sign' */
  if (rtb_Subtract3_idx_1 < 0.0F) {
    i = -1;
  } else {
    i = (rtb_Subtract3_idx_1 > 0.0F);
  }

  /* Sum: '<S100>/Add2' incorporates:
   *  Abs: '<S100>/Abs'
   *  Gain: '<S100>/Gain'
   *  Gain: '<S100>/Gain1'
   *  Product: '<S100>/Multiply2'
   *  Product: '<S100>/Multiply3'
   *  Signum: '<S100>/Sign'
   *  Sqrt: '<S100>/Sqrt'
   *  Sum: '<S100>/Add1'
   *  Sum: '<S100>/Subtract'
   */
  rtb_Add_g_idx_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_idx_1) +
    Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
    (real32_T)i + rtb_Saturation_idx_1;

  /* Signum: '<S100>/Sign1' incorporates:
   *  Signum: '<S100>/Sign'
   *  Sum: '<S100>/Add3'
   */
  u = rtb_Subtract3_idx_1 + Controller_ConstB.d;

  /* Signum: '<S100>/Sign2' incorporates:
   *  Signum: '<S100>/Sign'
   *  Sum: '<S100>/Subtract1'
   */
  u_0 = rtb_Subtract3_idx_1 - Controller_ConstB.d;

  /* Signum: '<S100>/Sign1' */
  if (u < 0.0F) {
    i = -1;
  } else {
    i = (u > 0.0F);
  }

  /* Signum: '<S100>/Sign2' */
  if (u_0 < 0.0F) {
    tmp = -1;
  } else {
    tmp = (u_0 > 0.0F);
  }

  /* Sum: '<S100>/Add5' incorporates:
   *  Gain: '<S100>/Gain2'
   *  Product: '<S100>/Multiply4'
   *  Signum: '<S100>/Sign'
   *  Signum: '<S100>/Sign1'
   *  Signum: '<S100>/Sign2'
   *  Sum: '<S100>/Add2'
   *  Sum: '<S100>/Add4'
   *  Sum: '<S100>/Subtract2'
   */
  rtb_Add_g_idx_0 += ((rtb_Subtract3_idx_1 - rtb_Add_g_idx_0) +
                      rtb_Saturation_idx_1) * ((real32_T)(i - tmp) * 0.5F);

  /* Update for DiscreteIntegrator: '<S97>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S97>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE[1] += 0.004F *
    Controller_DW.Integrator_DSTATE[1];

  /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S102>/ki'
   *  Product: '<S102>/Multiply'
   */
  rtb_uv_error_C_mPs_idx_0 = CONTROL_PARAM.VEL_XY_I * rtb_uv_error_C_mPs_idx_1 *
    0.004F + Controller_DW.DiscreteTimeIntegrator_DSTATE[1];
  Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = rtb_uv_error_C_mPs_idx_0;
  if (rtb_uv_error_C_mPs_idx_0 > CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.VEL_XY_I_MAX;
  } else if (rtb_uv_error_C_mPs_idx_0 < CONTROL_PARAM.VEL_XY_I_MIN) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.VEL_XY_I_MIN;
  }

  /* Update for DiscreteIntegrator: '<S104>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.004F * rtb_Gain_idx_1;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes =
    Controller_DW.DiscreteTimeIntegrator_PrevRese;

  /* Update for DiscreteIntegrator: '<S73>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

  /* Update for DiscreteIntegrator: '<S75>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_g =
    Controller_DW.DiscreteTimeIntegrator_PrevRese;

  /* Update for DiscreteIntegrator: '<S77>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_l = 0U;

  /* Update for DiscreteIntegrator: '<S73>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S73>/Gain'
   *  Sum: '<S73>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +=
    (rtb_rate_error_B_radPs_idx_0 -
     Controller_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 188.49556F * 0.004F;

  /* Update for DiscreteIntegrator: '<S75>/Discrete-Time Integrator' */
  rtb_uv_error_C_mPs_idx_1 = 0.004F * rtb_Saturation_d_idx_0 +
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0];
  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] = rtb_uv_error_C_mPs_idx_1;
  if (rtb_uv_error_C_mPs_idx_1 > CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] = CONTROL_PARAM.RATE_I_MAX;
  } else if (rtb_uv_error_C_mPs_idx_1 < CONTROL_PARAM.RATE_I_MIN) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] = CONTROL_PARAM.RATE_I_MIN;
  }

  /* Update for DiscreteIntegrator: '<S77>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0] += 0.004F *
    rtb_Saturation1_is_idx_0;

  /* Update for DiscreteIntegrator: '<S73>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S73>/Gain'
   *  Sum: '<S73>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +=
    (rtb_rate_error_B_radPs_idx_1 -
     Controller_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 188.49556F * 0.004F;

  /* Update for DiscreteIntegrator: '<S75>/Discrete-Time Integrator' */
  rtb_uv_error_C_mPs_idx_1 = 0.004F * rtb_Saturation_d_idx_1 +
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1];
  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] = rtb_uv_error_C_mPs_idx_1;
  if (rtb_uv_error_C_mPs_idx_1 > CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] = CONTROL_PARAM.RATE_I_MAX;
  } else if (rtb_uv_error_C_mPs_idx_1 < CONTROL_PARAM.RATE_I_MIN) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] = CONTROL_PARAM.RATE_I_MIN;
  }

  /* Update for DiscreteIntegrator: '<S77>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1] += 0.004F *
    rtb_Multiply_lq_idx_1;

  /* Update for DiscreteIntegrator: '<S73>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S73>/Gain'
   *  Sum: '<S73>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +=
    (rtb_rate_error_B_radPs_idx_2 -
     Controller_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 188.49556F * 0.004F;

  /* Update for DiscreteIntegrator: '<S75>/Discrete-Time Integrator' */
  rtb_uv_error_C_mPs_idx_1 = 0.004F * rtb_Saturation_d_idx_2 +
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2];
  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] = rtb_uv_error_C_mPs_idx_1;
  if (rtb_uv_error_C_mPs_idx_1 > CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] = CONTROL_PARAM.RATE_I_MAX;
  } else if (rtb_uv_error_C_mPs_idx_1 < CONTROL_PARAM.RATE_I_MIN) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] = CONTROL_PARAM.RATE_I_MIN;
  }

  /* Update for DiscreteIntegrator: '<S77>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[2] += 0.004F *
    rtb_Multiply_lq_idx_2;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_i =
    Controller_DW.DiscreteTimeIntegrator_PrevRese;

  /* Update for DiscreteIntegrator: '<S113>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S113>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE_p += 0.004F *
    Controller_DW.Integrator_DSTATE_p;

  /* Update for DiscreteIntegrator: '<S116>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S116>/ki'
   *  Product: '<S116>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_m += CONTROL_PARAM.VEL_Z_I *
    rtb_Gain_fl * 0.004F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m > CONTROL_PARAM.VEL_Z_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_Z_I_MAX;
  } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m <
             CONTROL_PARAM.VEL_Z_I_MIN) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_Z_I_MIN;
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_m =
    Controller_DW.DiscreteTimeIntegrator_PrevRese;

  /* End of Update for DiscreteIntegrator: '<S116>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S118>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_k = 0U;
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_h += 0.004F * rtb_Gain_g2;
  Controller_DW.DiscreteTimeIntegrator1_Prev_iy =
    Controller_DW.DiscreteTimeIntegrator_PrevRese;

  /* Signum: '<S100>/Sign5' incorporates:
   *  Sum: '<S100>/Add5'
   */
  if (rtb_Subtract3_i < 0.0F) {
    /* Signum: '<S100>/Sign6' */
    rtb_uv_error_C_mPs_0 = -1;
  } else {
    /* Signum: '<S100>/Sign6' */
    rtb_uv_error_C_mPs_0 = (rtb_Subtract3_i > 0.0F);
  }

  /* Signum: '<S100>/Sign3' incorporates:
   *  Sum: '<S100>/Add5'
   *  Sum: '<S100>/Add6'
   */
  u = rtb_Subtract3_i + Controller_ConstB.d;

  /* Signum: '<S100>/Sign4' incorporates:
   *  Sum: '<S100>/Add5'
   *  Sum: '<S100>/Subtract3'
   */
  u_0 = rtb_Subtract3_i - Controller_ConstB.d;

  /* Signum: '<S100>/Sign3' */
  if (u < 0.0F) {
    i = -1;
  } else {
    i = (u > 0.0F);
  }

  /* Signum: '<S100>/Sign4' */
  if (u_0 < 0.0F) {
    tmp = -1;
  } else {
    tmp = (u_0 > 0.0F);
  }

  /* Update for DiscreteIntegrator: '<S97>/Integrator' incorporates:
   *  Constant: '<S100>/const'
   *  Gain: '<S100>/Gain3'
   *  Product: '<S100>/Divide'
   *  Product: '<S100>/Multiply5'
   *  Product: '<S100>/Multiply6'
   *  Signum: '<S100>/Sign3'
   *  Signum: '<S100>/Sign4'
   *  Signum: '<S100>/Sign5'
   *  Signum: '<S100>/Sign6'
   *  Sum: '<S100>/Add5'
   *  Sum: '<S100>/Subtract4'
   *  Sum: '<S100>/Subtract5'
   *  Sum: '<S100>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE[0] += ((rtb_Subtract3_i / Controller_ConstB.d
    - (real32_T)rtb_uv_error_C_mPs_0) * Controller_ConstB.Gain4 * ((real32_T)(i
    - tmp) * 0.5F) - (real32_T)rtb_uv_error_C_mPs_0 * 58.836F) * 0.004F;

  /* Signum: '<S100>/Sign5' incorporates:
   *  Sum: '<S100>/Add5'
   */
  if (rtb_Add_g_idx_0 < 0.0F) {
    /* Signum: '<S100>/Sign6' */
    rtb_uv_error_C_mPs_0 = -1;
  } else {
    /* Signum: '<S100>/Sign6' */
    rtb_uv_error_C_mPs_0 = (rtb_Add_g_idx_0 > 0.0F);
  }

  /* Signum: '<S100>/Sign3' incorporates:
   *  Sum: '<S100>/Add5'
   *  Sum: '<S100>/Add6'
   */
  u = rtb_Add_g_idx_0 + Controller_ConstB.d;

  /* Signum: '<S100>/Sign4' incorporates:
   *  Sum: '<S100>/Add5'
   *  Sum: '<S100>/Subtract3'
   */
  u_0 = rtb_Add_g_idx_0 - Controller_ConstB.d;

  /* Signum: '<S100>/Sign3' */
  if (u < 0.0F) {
    i = -1;
  } else {
    i = (u > 0.0F);
  }

  /* Signum: '<S100>/Sign4' */
  if (u_0 < 0.0F) {
    tmp = -1;
  } else {
    tmp = (u_0 > 0.0F);
  }

  /* Update for DiscreteIntegrator: '<S97>/Integrator' incorporates:
   *  Constant: '<S100>/const'
   *  Gain: '<S100>/Gain3'
   *  Product: '<S100>/Divide'
   *  Product: '<S100>/Multiply5'
   *  Product: '<S100>/Multiply6'
   *  Signum: '<S100>/Sign3'
   *  Signum: '<S100>/Sign4'
   *  Signum: '<S100>/Sign5'
   *  Signum: '<S100>/Sign6'
   *  Sum: '<S100>/Add5'
   *  Sum: '<S100>/Subtract4'
   *  Sum: '<S100>/Subtract5'
   *  Sum: '<S100>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE[1] += ((rtb_Add_g_idx_0 / Controller_ConstB.d
    - (real32_T)rtb_uv_error_C_mPs_0) * Controller_ConstB.Gain4 * ((real32_T)(i
    - tmp) * 0.5F) - (real32_T)rtb_uv_error_C_mPs_0 * 58.836F) * 0.004F;

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S3>/Constant'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_n += CONTROL_EXPORT.period;

  /* Signum: '<S114>/Sign5' */
  if (rtb_a_n < 0.0F) {
    /* Signum: '<S114>/Sign6' */
    rtb_uv_error_C_mPs_0 = -1;
  } else {
    /* Signum: '<S114>/Sign6' */
    rtb_uv_error_C_mPs_0 = (rtb_a_n > 0.0F);
  }

  /* Sum: '<S114>/Add6' */
  u = rtb_a_n + Controller_ConstB.d_n;

  /* Sum: '<S114>/Subtract3' */
  u_0 = rtb_a_n - Controller_ConstB.d_n;

  /* Signum: '<S114>/Sign3' */
  if (u < 0.0F) {
    i = -1;
  } else {
    i = (u > 0.0F);
  }

  /* Signum: '<S114>/Sign4' */
  if (u_0 < 0.0F) {
    tmp = -1;
  } else {
    tmp = (u_0 > 0.0F);
  }

  /* Update for DiscreteIntegrator: '<S113>/Integrator' incorporates:
   *  Constant: '<S114>/const'
   *  Gain: '<S114>/Gain3'
   *  Product: '<S114>/Divide'
   *  Product: '<S114>/Multiply5'
   *  Product: '<S114>/Multiply6'
   *  Signum: '<S114>/Sign3'
   *  Signum: '<S114>/Sign4'
   *  Signum: '<S114>/Sign5'
   *  Sum: '<S114>/Subtract4'
   *  Sum: '<S114>/Subtract5'
   *  Sum: '<S114>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE_p += ((rtb_a_n / Controller_ConstB.d_n -
    (real32_T)rtb_uv_error_C_mPs_0) * Controller_ConstB.Gain4_k * ((real32_T)(i
    - tmp) * 0.5F) - (real32_T)rtb_uv_error_C_mPs_0 * 78.448F) * 0.004F;
}

/* Model initialize function */
void Controller_init(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Controller_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&Controller_DW, 0,
                sizeof(DW_Controller_T));

  /* external inputs */
  (void)memset(&Controller_U, 0, sizeof(ExtU_Controller_T));

  /* external outputs */
  Controller_Y.Control_Out = Controller_rtZControl_Out_Bus;

  {
    real32_T Constant_tmp;

    /* InitializeConditions for DiscreteIntegrator: '<S116>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S116>/Constant'
     */
    Constant_tmp = CONTROL_PARAM.VEL_Z_I_MIN;

    /* Start for Constant: '<S116>/Constant' */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_Z_I_MIN;

    /* InitializeConditions for DiscreteIntegrator: '<S102>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
      Controller_ConstB.Constant_g;
    if (Controller_ConstB.Constant_g > CONTROL_PARAM.VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
        CONTROL_PARAM.VEL_XY_I_MAX;
    } else if (Controller_ConstB.Constant_g < CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
      Controller_ConstB.Constant_g;
    if (Controller_ConstB.Constant_g > CONTROL_PARAM.VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
        CONTROL_PARAM.VEL_XY_I_MAX;
    } else if (Controller_ConstB.Constant_g < CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }

    Controller_DW.DiscreteTimeIntegrator_PrevRese = 0;

    /* End of InitializeConditions for DiscreteIntegrator: '<S102>/Discrete-Time Integrator' */

    /* InitializeConditions for DiscreteIntegrator: '<S104>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;
    Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S73>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S75>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
      Controller_ConstB.Constant[0];
    if (Controller_ConstB.Constant[0] > CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
        CONTROL_PARAM.RATE_I_MAX;
    } else if (Controller_ConstB.Constant[0] < CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
        CONTROL_PARAM.RATE_I_MIN;
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
      Controller_ConstB.Constant[1];
    if (Controller_ConstB.Constant[1] > CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
        CONTROL_PARAM.RATE_I_MAX;
    } else if (Controller_ConstB.Constant[1] < CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
        CONTROL_PARAM.RATE_I_MIN;
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
      Controller_ConstB.Constant[2];
    if (Controller_ConstB.Constant[2] > CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
        CONTROL_PARAM.RATE_I_MAX;
    } else if (Controller_ConstB.Constant[2] < CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
        CONTROL_PARAM.RATE_I_MIN;
    }

    Controller_DW.DiscreteTimeIntegrator_PrevRe_g = 0;

    /* End of InitializeConditions for DiscreteIntegrator: '<S75>/Discrete-Time Integrator' */

    /* InitializeConditions for DiscreteIntegrator: '<S77>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_PrevR_i = 0;
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_l = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S116>/Discrete-Time Integrator' */
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m >
        CONTROL_PARAM.VEL_Z_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_Z_I_MAX;
    } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m <
               CONTROL_PARAM.VEL_Z_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m = Constant_tmp;
    }

    Controller_DW.DiscreteTimeIntegrator_PrevRe_m = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S118>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_Prev_iy = 0;
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_k = 1U;
  }
}

/* Model terminate function */
void Controller_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
