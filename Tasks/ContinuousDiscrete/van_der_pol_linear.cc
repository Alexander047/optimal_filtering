#include "van_der_pol_linear.h"


namespace Tasks
{

namespace ContinuousDiscrete
{

namespace VanDerPol
{


Linear::Linear() : ContinuousDiscreteTask()
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

Vector Linear::funcA (const Vector &x, double /*t*/) const
{
    Vector a (2);
    a[0] = x[1];
    a[1] = -omega * omega * x[0] + alpha * x[1] - alpha * beta * x[0] * x[0] * x[1];
    return a;
}

Matrix Linear::funcB (const Vector &x, double /*t*/) const
{
    Matrix b (2, 2);
    b << 0.0, 0.0, 0.0, x[0];
    return b;
}

Vector Linear::funcTau (const Vector &m, const Matrix & /*D*/, double /*t*/) const
{
    Vector tau (2);
    tau[0] = m[1];
    tau[1] = -omega * omega * m[0] + alpha * m[1] - alpha * beta * m[0] * m[0] * m[1];
    return tau;
}

Matrix Linear::funcTheta (const Vector &m, const Matrix & /*D*/, double t) const
{
    Matrix B = funcB (m, t);
    return B * B.transpose();
}

Matrix Linear::funcAA (const Vector &m, const Matrix & /*D*/, double /*t*/) const
{
    Matrix A (2, 2);
    A << 0.0, 1.0, -omega * omega - 2.0 * alpha * beta * m[0] * m[1],
    alpha * (1 - beta * m[0] * m[0]);
    return A;
}


Vector Linear::funcC (const Vector &x) const
{
    Vector v = Rand::gaussianVector (mw, Dv);
    Vector c (2);
    c << x[0] * x[0] + v[0], x[1] + v[1];
    return c;
}

Vector Linear::funcH (const Vector &m, const Matrix & /* D*/) const
{
    Vector h (2);
    h << m[0] * m[0] + mw[0], m[1] + mw[1];
    return h;
}

Matrix Linear::funcG (const Vector &m, const Matrix & /*D*/) const
{
    Matrix g (2, 2);
    g << 2.0 * m[0], 0.0, 0.0, 1.0;
    return g;
}

Matrix Linear::funcF (const Vector &m, const Matrix &D) const
{
    Matrix f (2, 2);
    f (0, 0) = 4.0 * m[0] * m[0] * D (0, 0) + Dw (0, 0);
    f (0, 1) = f (1, 0) = 2.0 * m[0] * D (0, 1) + Dw (0, 1);
    f (1, 1) = D (1, 1) + Dw (1, 1);
    return f;
}


}  // end Tasks::ContinuousDiscrete::VanDerPol

}  // end Tasks::ContinuousDiscrete

}  // end Tasks
