#include "cd_van_der_pol_gauss.h"


namespace Tasks
{

namespace ContinuousDiscrete
{

namespace VanDerPol
{


Gauss::Gauss() : Linear()
{
    m_approxType = "Г-";
}


Vector Gauss::funcTau (const Vector &m, const Matrix &D, double /*t*/) const
{
    Vector tau (2);
    tau[0] = m[1];
    tau[1] = -omega * omega * m[0] + alpha * m[1] -
             alpha * beta * (m[0] * m[0] * m[1] + m[1] * D (0, 0) + 2.0 * m[0] * D (0, 1));
    return tau;
}

Matrix Gauss::funcTheta (const Vector &m, const Matrix &D, double /*t*/) const
{
    Matrix theta (2, 2);
    theta << 0.0, 0.0, 0.0, m[0] * m[0] + D (0, 0);
    return theta;
}

Matrix Gauss::funcAA (const Vector &m, const Matrix &D, double /*t*/) const
{
    Matrix a (2, 2);
    a (0, 0) = 0.0;
    a (0, 1) = 1.0;
    a (1, 0) = -omega * omega - 2.0 * alpha * beta * (m[0] * m[1] + D (0, 1));
    a (1, 1) = alpha - alpha * beta * (m[0] * m[0] + D (0, 0));
    return a;
}


Vector Gauss::funcH (const Vector &m, const Matrix &/*D*/) const
{
    return m + mw;
}

Matrix Gauss::funcG (const Vector &/*m*/, const Matrix & /*D*/) const
{
    return Matrix::Identity (2, 2);
}

Matrix Gauss::funcF (const Vector &/*m*/, const Matrix &D) const
{
    Matrix f = D;
    f(0,0) += Dw(0,0);
    f(1,1) += Dw(1,1);
    return f;
}


}  // end Tasks::ContinuousDiscrete::VanDerPol

}  // end Tasks::ContinuousDiscrete

}  // end Tasks
