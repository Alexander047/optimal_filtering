#include "c_van_der_pol_linear.h"


namespace Tasks
{

namespace Continuous
{

namespace VanDerPol
{


Linear::Linear() :
    ContinuousTask ()
{
    m_name       = "Осциллятор Ван-дер-Поля";
    m_approxType = "Л-";

    m_dimX = 2;
    m_dimY = 2;
    m_dimV = 2;
    m_dimW = 2;

    omega = 0.1 * Const::PI;
    alpha = 1.0;
    beta  = 0.25;

    mx << 10.0, -3.0;

    mv = Vector::Zero (2);

    mw << 1.0, 1.5;

    Dx << 5.0, 0.0, 0.0, 5.0;

    Dv = Matrix::Identity (2, 2);

    Dw << 4.0, 0.0, 0.0, 4.0;
}

Vector Linear::funcA  (const Vector &x, double /*t*/) const
{
    Vector a (m_dimX);
    a << x[1],
         -omega * omega * x[0] + alpha * x[1] - alpha * beta * x[0] * x[0] * x[1];
    return a;
}

Matrix Linear::funcB  (const Vector &x, double /*t*/) const
{
    Matrix B (m_dimX, m_dimV);
    B << 0.0, 0.0,
         0.0, x[0];
    return B;
}

Vector Linear::funcC  (const Vector &x, double /*t*/) const
{
    Vector c (m_dimY);
    c << x[0],
         x[1];
    return c;
}

Matrix Linear::funcD  (const Vector &/*x*/, double /*t*/) const
{
    Matrix D (m_dimY, m_dimW);
    D << 1.0, 0.0,
         0.0, 1.0;
    return D;
}

Matrix Linear::funcQ (const Vector &x, const Matrix &/*D*/,  double t) const
{
    Matrix b = funcB (x, t);
    return b * b.transpose();
}

Matrix Linear::funcS (const Vector &/*x*/, const Matrix &/*D*/, double /*t*/) const
{
    return Matrix::Zero (m_dimX, m_dimY);
}

Matrix Linear::funcR (const Vector &x, const Matrix &/*D*/,  double t) const
{
    Matrix d = funcD (x, t);
    return d * d.transpose();
}

Matrix Linear::funcAA (const Vector &m, const Matrix &/*D*/, double /*t*/) const
{
    Matrix A (m_dimX, m_dimX);
    A(0,0) = 0.0;
    A(0,1) = 1.0;
    A(1,0) = -omega * omega -2.0 * alpha * beta * m[0] * m[1];
    A(1,1) = alpha * (1.0 - beta * m[0] * m[0]);
    return A;
}

Matrix Linear::funcG  (const Vector &/*m*/, const Matrix &/*D*/, double /*t*/) const
{
    Matrix G (m_dimY, m_dimX);
    G << 1.0, 0.0,
         0.0, 1.0;
    return G;
}


}  // end Tasks::Continuous::VanDerPol

}  // end Tasks::Continuous

}  // end Tasks
