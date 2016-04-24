#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include "matrix.h"


namespace LinAlg
{


enum class PSEUDOINVERSE_METHOD { SVD, Greville };


Vector SolveSystem (const Matrix &A, const Vector &b);

Matrix LU (const Matrix &A);
Matrix LU (const Matrix &A, Matrix &L, Matrix &U, Matrix &permutationP, Matrix &permutationQ);

Matrix Cholesky (const Matrix &A);
Matrix Cholesky (const Matrix &A, Matrix &L, Matrix &U);

Matrix PseudoInverseSVD (const Matrix &A);
Matrix PseudoInverseGreville (const Matrix &A);
Matrix PseudoInverse (const Matrix &A, PSEUDOINVERSE_METHOD method = PSEUDOINVERSE_METHOD::SVD);


}  // end LinAlg


#endif  // LINEAR_ALGEBRA_H
