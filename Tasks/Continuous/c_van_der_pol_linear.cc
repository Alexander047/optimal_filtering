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

    omega = 0.1 * Const::PI;
    alpha = 1.0;
    beta  = 0.25;

    mx << 10.0, -3.0;

    mv = Vector::Zero (2);
    my = Vector::Zero (2);

    mw << 1.0, 1.5;

    Dx << 5.0, 0.0, 0.0, 5.0;

    Dv = Matrix::Identity (2, 2);
    Dy = Matrix::Zero (2, 2);

    Dw << 4.0, 0.0, 0.0, 4.0;
}

Vector Linear::funcA  (const Vector &x, double /*t*/) const
{
    Vector a (2);
    a << x[1],
         -omega * omega *x[0] + alpha * x[1] - alpha * beta * x[0] * x[0] * x[1];
    return a;
}

Matrix Linear::funcB  (const Vector &x, double /*t*/) const
{
    Matrix B (2, 2);
    B << 0.0, 0.0,
         0.0, x[0];
    return B;
}

Vector Linear::funcC  (const Vector &x, double /*t*/) const
{
    Vector c (2);
    c << x[0] * x[0],
         x[1];
    return c;
}

Matrix Linear::funcD  (const Vector &/*x*/, double /*t*/) const
{
    Matrix D (2, 2);
    D << 1.0, 0.0,
         0.0, 1.0;
    return D;
}

Matrix Linear::funcAA (const Vector &x, double /*t*/) const
{
    Matrix A (2, 2);
    A(0,0) = 0.0;
    A(0,1) = 1.0;
    A(1,0) = -omega * omega -2.0 * alpha * beta * x[0] * x[1];
    A(1,1) = alpha * (1.0 - beta * x[0] * x[0]);
    return A;
}

Matrix Linear::funcG  (const Vector &/*x*/, double /*t*/) const
{
    Matrix G (2, 2);
    G << 1.0, 0.0,
         0.0, 1.0;
    return G;
}


}  // end Tasks::Continuous::VanDerPol

}  // end Tasks::Continuous

}  // end Tasks
