#ifndef KALMAN_FILTER_HPP
#define KALMAN_FILTER_HPP

#include <Eigen/Dense>
class KalmanFilter_1
{
public:
    Eigen::Matrix2f A = Eigen::Matrix2f::Zero(2, 2);
    Eigen::MatrixXf B = Eigen::MatrixXf::Zero(2, 1);
    Eigen::Matrix2f C = Eigen::Matrix2f::Zero(2, 2);
    Eigen::Matrix2f Q = Eigen::Matrix2f::Zero(2, 2);
    Eigen::Matrix2f R = Eigen::Matrix2f::Zero(2, 2);
    Eigen::Matrix2f P = Eigen::Matrix2f::Zero(2, 2);
    Eigen::Matrix2f P_ = Eigen::Matrix2f::Zero(2, 1);
    Eigen::Matrix2f K = Eigen::Matrix2f::Zero(2, 2);
    Eigen::Matrix2f X = Eigen::Matrix2f::Zero(2, 1);
    Eigen::Matrix2f X_ = Eigen::Matrix2f::Zero(2, 1);
    Eigen::MatrixXf u = Eigen::MatrixXf::Zero(1, 1);
    Eigen::MatrixXf z = Eigen::MatrixXf::Zero(2, 1);
    Eigen::Matrix2f I = Eigen::Matrix2f::Identity(2, 2);
    // Eigen::Matrix<float, 2, 2> A = Eigen::Matrix<float, 2, 2>::Zero(2, 2);
    // Eigen::Matrix<float, 2, 1> B = Eigen::Matrix<float, 2, 1>::Zero(2, 1);
    // Eigen::Matrix<float, 2, 2> C = Eigen::Matrix<float, 2, 2>::Zero(2, 2);
    // Eigen::Matrix<float, 2, 2> Q = Eigen::Matrix<float, 2, 2>::Zero(2, 2);
    // Eigen::Matrix<float, 2, 2> R = Eigen::Matrix<float, 2, 2>::Zero(2, 2);
    // Eigen::Matrix<float, 1, 1> u = Eigen::Matrix<float, 1, 1>::Zero(1, 1);
    // Eigen::Matrix<float, 2, 1> z = Eigen::Matrix<float, 2, 1>::Zero(2, 1);
    // Eigen::Matrix<float, 2, 2> I = Eigen::Matrix<float, 2, 2>::Identity(2, 2);
    // Eigen::Matrix<float, 2, 1> X = Eigen::Matrix<float, 2, 1>::Zero(2, 1);
    // Eigen::Matrix<float, 2, 2> P = Eigen::Matrix<float, 2, 2>::Zero(2, 2);
    // Eigen::Matrix<float, 2, 1> X_ = Eigen::Matrix<float, 2, 1>::Zero(2, 1);
    // Eigen::Matrix<float, 2, 2> P_ = Eigen::Matrix<float, 2, 2>::Zero(2, 2);
    // Eigen::Matrix<float, 2, 2> K = Eigen::Matrix<float, 2, 2>::Zero(2, 2);

    KalmanFilter_1() {
        printf("init\n");
        // A = Eigen::Matrix2f::Zero(2, 2);
        // B = Eigen::Matrix<float, 2, 1>::Zero(2, 1);
        // C = Eigen::Matrix2f::Zero(2, 2);
        // Q = Eigen::Matrix2f::Zero(2, 2);
        // R = Eigen::Matrix2f::Zero(2, 2);
        // u = Eigen::Matrix<float, 1, 1>::Zero(1, 1);
        // z = Eigen::Matrix<float, 2, 1>::Zero(2, 1);
        // I = Eigen::Matrix2f::Identity(2, 2);
        // X = Eigen::Matrix<float, 2, 1>::Zero(2, 1);
        // P = Eigen::Matrix2f::Zero(2, 2);
        // X_ = Eigen::Matrix<float, 2, 1>::Zero(2, 1);
        // P_ = Eigen::Matrix2f::Zero(2, 2);
        // K = Eigen::Matrix2f::Zero(2, 2);
    }

    void initialize(float X_0_0, float X_0_1, float P_0_0, float P_1_1);
    void setQR(float Q_0_0, float Q_0_1, float Q_1_0, float Q_1_1, float R_0_0, float R_0_1, float R_1_0, float R_1_1);
    void process(float time_dif, float u_input, float z_0_0, float z_1_0);
};


// class KalmanFilter_2
// {
// public:
//     Eigen::Matrix<float, 4, 4> A2;
//     Eigen::Matrix<float, 4, 2> B2;
//     Eigen::Matrix<float, 2, 4> C2;
//     Eigen::Matrix<float, 4, 4> Q2;
//     Eigen::Matrix<float, 2, 2> R2;
//     Eigen::Matrix<float, 2, 1> u2;
//     Eigen::Matrix<float, 2, 1> z2;
//     Eigen::Matrix<float, 4, 4> I2;
//     Eigen::Matrix<float, 4, 1> X2;
//     Eigen::Matrix<float, 4, 4> P2;
//     Eigen::Matrix<float, 4, 1> X2_;
//     Eigen::Matrix<float, 4, 4> P2_;
//     Eigen::Matrix<float, 4, 2> K2;

//     KalmanFilter_2() {
//         A2 = Eigen::Matrix4f::Zero(4, 4);
//         B2 = Eigen::MatrixXf::Zero(4, 2);
//         C2 = Eigen::MatrixXf::Zero(2, 4);
//         Q2 = Eigen::Matrix4f::Zero(4, 4);
//         R2 = Eigen::MatrixXf::Zero(2, 2);
//         u2 = Eigen::MatrixXf::Zero(2, 1);
//         z2 = Eigen::MatrixXf::Zero(2, 1);
//         I2 = Eigen::Matrix4f::Identity(4, 4);
//         X2 = Eigen::MatrixXf::Zero(4, 1);
//         P2 = Eigen::Matrix4f::Zero(4, 4);
//         X2_ = Eigen::MatrixXf::Zero(4, 1);
//         P2_ = Eigen::Matrix4f::Zero(4, 4);
//         K2 = Eigen::MatrixXf::Zero(4, 2);
//     }

//     // Eigen::Matrix<float, 4, 4> A2;
//     // Eigen::Matrix<float, 4, 2> B2;
//     // Eigen::Matrix<float, 3, 4> C2;
//     // Eigen::Matrix<float, 4, 4> Q2;
//     // Eigen::Matrix<float, 3, 3> R2;
//     // Eigen::Matrix<float, 2, 1> u2;
//     // Eigen::Matrix<float, 3, 1> z2;
//     // Eigen::Matrix<float, 4, 4> I2;
//     // Eigen::Matrix<float, 4, 1> X2;
//     // Eigen::Matrix<float, 4, 4> P2;
//     // Eigen::Matrix<float, 4, 1> X2_;
//     // Eigen::Matrix<float, 4, 4> P2_;
//     // Eigen::Matrix<float, 4, 3> K2;

//     // KalmanFilter_2() {
//     //     A2 = Eigen::Matrix4f::Zero(4, 4);
//     //     B2 = Eigen::MatrixXf::Zero(4, 2);
//     //     C2 = Eigen::MatrixXf::Zero(3, 4);
//     //     Q2 = Eigen::Matrix4f::Zero(4, 4);
//     //     R2 = Eigen::MatrixXf::Zero(3, 3);
//     //     u2 = Eigen::MatrixXf::Zero(2, 1);
//     //     z2 = Eigen::MatrixXf::Zero(3, 1);
//     //     I2 = Eigen::Matrix4f::Identity(4, 4);
//     //     X2 = Eigen::MatrixXf::Zero(4, 1);
//     //     P2 = Eigen::Matrix4f::Zero(4, 4);
//     //     X2_ = Eigen::MatrixXf::Zero(4, 1);
//     //     P2_ = Eigen::Matrix4f::Zero(4, 4);
//     //     K2 = Eigen::MatrixXf::Zero(4, 3);
//     // }

//     void initialize2(float X_0_0, float X_1_0, float P_0_0, float P_1_1, float P_2_2, float P_3_3, float P_0_2, float P_1_3);
//     void setQR2(float Q_0_0, float Q_1_1, float Q_2_2, float Q_3_3, float Q_0_2, float Q_1_3, float R_0_0, float R_1_1);
//     void process2(float time_dif, float u_input_0, float u_input_1, float z_input_0, float z_input_1);

//     void setQR23(float Q_0_0, float Q_1_1, float Q_2_2, float Q_3_3, float Q_0_2, float Q_1_3, 
//                  float R_0_0, float R_1_1, float R_2_2, float R_1_2);
//     void process23(float time_dif, float u_input_0, float u_input_1, float z_input_0, float z_input_1, float z_input_2);
// };



#endif 


