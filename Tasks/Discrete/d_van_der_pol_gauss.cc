#include "d_van_der_pol_gauss.h"

namespace Tasks
{

namespace Discrete
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


Vector Gauss::funcH (const Vector &m, const Matrix &D) const
{
    Vector h (2);
    h << m[0] * m[0] + D (0, 0) + mw[0], m[1] + mw[1];
    return h;
}

Matrix Gauss::funcG (const Vector &m, const Matrix & /*D*/) const
{
    Matrix g (2, 2);
    g << 2.0 * m[0], 0.0, 0.0, 1.0;
    return g;
}

Matrix Gauss::funcF (const Vector &m, const Matrix &D) const
{
    Matrix f (2, 2);
    f (0, 0) = 2.0 * D (0, 0) * (2.0 * m[0] * m[0] + D (0, 0)) + Dw (0, 0);
    f (0, 1) = f (1, 0) = 2.0 * m[0] * D (0, 1) + Dw (0, 1);
    f (1, 1) = D (1, 1) + Dw (1, 1);
    return f;
}



}  // end Tasks::Discrete::VanDerPol

}  // end Tasks::Discrete

}  // end Tasks
