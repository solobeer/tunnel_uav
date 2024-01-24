#include "kalman_filter.h"
// #include "laser_control.h"


void KalmanFilter_1::initialize(float X_0_0, float X_0_1, float P_0_0, float P_1_1) {
     X << X_0_0, 
          X_0_1;
     P << P_0_0, 0,
          0, P_0_0;
}


void KalmanFilter_1::setQR(float Q_0_0, float Q_0_1, float Q_1_0, float Q_1_1, float R_0_0, float R_0_1, float R_1_0, float R_1_1) {
     Q << Q_0_0, Q_0_1, 
          Q_1_0, Q_1_1;
     R << R_0_0, R_0_1,
          R_1_0, R_1_1;
}


void KalmanFilter_1::process(float time_dif, float u_input, float z_0_0, float z_1_0) {
     A << 1, time_dif, 
          0, 1;
     B << 0.5 * time_dif * time_dif, 
          time_dif;
     C << 1, 0,
          0, 1;
     u << u_input;
     z << z_0_0,
          z_1_0;
     X_ = A * X + B * u;
     P_ = A * P * A.transpose() + Q;
     Eigen::Matrix<float, 1, 1> tmp = C * P_ * C.transpose() + R;
     // K = P_ * C.transpose() * (tmp.inverse());
     X = X_ + K * (z - C * X_);
     P = (I - K * C) * P_;
}


// void KalmanFilter_2::initialize2(float X_0_0, float X_1_0, float P_0_0, float P_1_1, float P_2_2, float P_3_3, float P_0_2, float P_1_3) {
//      X2 << X_0_0, X_1_0, 
//            0, 0;
//      P2 << P_0_0, 0, P_0_2, 0,
//            0, P_1_1, 0, P_1_3,
//            P_0_2, 0, P_2_2, 0,
//            0, P_1_3, 0, P_3_3;
// }


// void KalmanFilter_2::setQR2(float Q_0_0, float Q_1_1, float Q_2_2, float Q_3_3, float Q_0_2, float Q_1_3, float R_0_0, float R_1_1) {
//      Q2 << Q_0_0, 0, Q_0_2, 0,
//            0, Q_1_1, 0, Q_1_3,
//            Q_0_2, 0, Q_2_2, 0,
//            0, Q_1_3, 0, Q_3_3;
//      R2 << R_0_0, 0,
//            0, R_1_1;
// }


// void KalmanFilter_2::process2(float time_dif, float u_input_0, float u_input_1, float z_input_0, float z_input_1) {
//      A2 << 1, 0, time_dif, 0,
//            0, 1, 0, time_dif,
//            0, 0, 1, 0,
//            0, 0, 0, 1;
//      B2 << 0, 0, 
//            0, 0, 
//            time_dif, 0, 
//            0, time_dif;
//      C2 << 1, 0, 0, 0, 
//            0, 1, 0, 0;
//      u2 << u_input_0, u_input_1;
//      z2 << z_input_0, z_input_1;
//      X2_ = A2 * X2 + B2 * u2;
//      P2_ = A2 * P2 * A2.transpose() + Q2;
//      Eigen::Matrix<float, 2, 2> tmp = C2 * P2_ * C2.transpose() + R2;
//      K2 = P2_ * C2.transpose() * tmp.inverse();
//      X2 = X2_ + K2 * (z2 - C2 * X2_);
//      P2 = (I2 - K2 * C2) * P2_;
// }


// void KalmanFilter_2::setQR23(float Q_0_0, float Q_1_1, float Q_2_2, float Q_3_3, float Q_0_2, float Q_1_3, 
//                              float R_0_0, float R_1_1, float R_2_2, float R_1_2) {
//      // Q2 << Q_0_0, 0, Q_0_2, 0,
//      //       0, Q_1_1, 0, Q_1_3,
//      //       Q_0_2, 0, Q_2_2, 0,
//      //       0, Q_1_3, 0, Q_3_3;
//      // R2 << R_0_0, 0, R_1_2,
//      //       0, R_1_1, 0,
//      //       R_1_2, 0, R_2_2;
// }

// void KalmanFilter_2::process23(float time_dif, float u_input_0, float u_input_1, float z_input_0, float z_input_1, float z_input_2) {
//      // A2 << 1, 0, time_dif, 0,
//      //       0, 1, 0, time_dif,
//      //       0, 0, 1, 0,
//      //       0, 0, 0, 1;
//      // B2 << 0, 0, 
//      //       0, 0, 
//      //       time_dif, 0, 
//      //       0, time_dif;
//      // C2 << 1, 0, 0, 0, 
//      //       0, 1, 0, 0, 
//      //       0, 0, 0, 1;
//      // u2 << u_input_0, u_input_1;
//      // z2 << z_input_0, z_input_1, z_input_2;
//      // X2_ = A2 * X2 + B2 * u2;
//      // P2_ = A2 * P2 * A2.transpose() + Q2;
//      // Eigen::Matrix<float, 3, 3> tmp = C2 * P2_ * C2.transpose() + R2;
//      // K2 = P2_ * C2.transpose() * tmp.inverse();
//      // X2 = X2_ + K2 * (z2 - C2 * X2_);
//      // P2 = (I2 - K2 * C2) * P2_;
// }