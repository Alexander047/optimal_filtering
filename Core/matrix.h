#ifndef MATRIX_H
#define MATRIX_H

#include "Libs/Eigen/Dense"
#include "core_base.h"


// Matrix, Vector - размер определяется динамически в run-time и может изменяться
// MatrixNxN, VectorNxN - размеры определяются в compile-time, работают быстрее,
// но размер нельзя изменить
// Можно определить MatrixNxM фиксированного размера так :
// typedef Eigen::Matrix <Scalar, N, M> MatrixNxM
// где Scalar - это double, int и т.д.


typedef Eigen::MatrixXd Matrix;
typedef Eigen::Matrix2d Matrix2x2;
typedef Eigen::Matrix3d Matrix3x3;
typedef Eigen::Matrix4d Matrix4x4;

typedef Eigen::MatrixXi MatrixInt;
typedef Eigen::Matrix2i MatrixInt2x2;
typedef Eigen::Matrix3i MatrixInt3x3;
typedef Eigen::Matrix4i MatrixInt4x4;

typedef Eigen::VectorXd Vector;
typedef Eigen::Vector2d Vector2;
typedef Eigen::Vector3d Vector3;
typedef Eigen::Vector4d Vector4;

typedef Eigen::VectorXi VectorInt;
typedef Eigen::Vector2i VectorInt2;
typedef Eigen::Vector3i VectorInt3;
typedef Eigen::Vector4i VectorInt4;

typedef Eigen::RowVectorXd RowVector;
typedef Eigen::RowVector2d RowVector2;
typedef Eigen::RowVector3d RowVector3;
typedef Eigen::RowVector4d RowVector4;

typedef Eigen::RowVectorXi RowVectorInt;
typedef Eigen::RowVector2i RowVectorInt2;
typedef Eigen::RowVector3i RowVectorInt3;
typedef Eigen::RowVector4i RowVectorInt4;


#endif  // MATRIX_H
