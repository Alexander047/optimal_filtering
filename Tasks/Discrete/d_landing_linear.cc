#include "d_landing_linear.h"

namespace Tasks
{

namespace Discrete
{

namespace Landing
{

static double KK       = -0.3;
static const double BB = 0.09;
static const double CC = 0.043333333333333333333333333333333333333333333333333;
static const double GG = 3.711E-3;
static const double RR = 3390.0;


// линеаризованный объект :

Linear::Linear() : DiscreteTask()
{
    m_name       = "Спуск ЛА на планету";
    m_approxType = "Л-";

    mx.resize (3);
    mx << 6.0, DegToRad (-18.0), 100.0;

    Dx.resize (3, 3);
    Dx << pow (15E-3, 2), 0.0, 0.0, 0.0, pow (DegToRad (1.0), 2), 0.0, 0.0, 0.0,
    pow (3.5, 2);  /// 7.0

    mv.resize (3);
    mv << 0.0, 0.0, 0.0;

    Dv.resize (3, 3);
    Dv << 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0;

    my = Vector::Zero (2);
    Dy = Matrix::Zero (2, 2);
    mw = Vector::Zero (4);

    Dw.resize (4, 4);
    Dw << pow (1E-2, 2), 0.0, 0.0, 0.0, 0.0, pow (1E-2, 2), 0.0, 0.0, 0.0, 0.0, pow (2E-7, 2), 0.0,
    0.0, 0.0, 0.0, pow (2E-7, 2);
}

Vector Linear::funcA (const Vector &x, double t) const
{
    KK = (t < 45.0 ? -0.3 : 0.3);

    double e = exp (-BB * x[2]);
    Vector a (3);

    a << -CC * x[0] * x[0] * e - GG * sin (x[1]),
    CC * KK * x[0] * e + cos (x[1]) * (x[0] / (RR + x[2]) - GG / x[0]), x[0] * sin (x[1]);

    return a;
}

Matrix Linear::funcB (const Vector & /*x*/, double /*t*/) const
{
    return Matrix::Zero (3, 3);
}

Vector Linear::funcTau (const Vector &m, const Matrix & /*D*/, double t) const
{
    // tau (m, D, t) = a (m, t) :
    return funcA (m, t);
}

Matrix Linear::funcTheta (const Vector & /*m*/, const Matrix & /*D*/, double /*t*/) const
{
    return Matrix::Zero (3, 3);
}

Matrix Linear::funcAA (const Vector &m, const Matrix & /*D*/, double /*t*/) const
{
    double e = exp (-BB * m[2]);
    Matrix a (3, 3);

    a (0, 0) = -2.0 * CC * m[0] * e;
    a (0, 1) = -GG * cos (m[1]);
    a (0, 2) = BB * CC * m[0] * m[0] * e;

    a (1, 0) = CC * KK * e + (GG / (m[0] * m[0]) + 1.0 / (RR + m[2])) * cos (m[1]);
    a (1, 1) = (GG / m[0] - m[0] / (RR + m[2])) * sin (m[1]);
    a (1, 2) = -CC * BB * KK * m[0] * e - m[0] * cos (m[1]) / ((RR + m[2]) * (RR + m[2]));

    a (2, 0) = sin (m[1]);
    a (2, 1) = m[0] * cos (m[1]);
    a (2, 2) = 0.0;

    return a;
}


Vector Linear::funcC (const Vector &x) const
{
    double e = exp (-BB * x[2]);
    Vector w = Rand::gaussianVector (mw, Dw);
    Vector c (2);

    c << CC * (w[0] + 1.0) * x[0] * x[0] * e * (cos (x[1]) - KK * sin (x[1])) + w[2],
    CC * (w[1] + 1.0) * x[0] * x[0] * e * (sin (x[1]) - KK * cos (x[1])) + w[3];

    return c;
}

Vector Linear::funcH (const Vector &m, const Matrix & /* D*/) const
{
    double e = exp (-BB * m[2]);
    Vector h (2);

    h << CC * m[0] * m[0] * e * (cos (m[1]) - KK * sin (m[1])) * (1.0 + mw[0]) + mw[2],
    CC * m[0] * m[0] * e * (sin (m[1]) - KK * cos (m[1])) * (1.0 + mw[1]) + mw[3];

    return h;
}

Matrix Linear::funcG (const Vector &m, const Matrix & /*D*/) const
{
    double e = exp (-BB * m[2]);
    Matrix g (2, 3);

    g (0, 0) = 2 * CC * m[0] * (mw[0] + 1) * e * (cos (m[1]) - KK * sin (m[1]));
    g (0, 1) = -CC * m[0] * m[0] * (mw[0] + 1) * e * sin (m[1]);
    g (0, 2) = -BB * CC * m[0] * m[0] * (mw[0] + 1) * e * (cos (m[1]) - KK * sin (m[1]));

    g (1, 0) = 2 * CC * m[0] * (mw[1] + 1) * e * (sin (m[1]) - KK * cos (m[1]));
    g (1, 1) = CC * m[0] * m[0] * (mw[1] + 1) * e * cos (m[1]);
    g (1, 2) = -BB * CC * m[0] * m[0] * (mw[1] + 1) * e * (sin (m[1]) - KK * cos (m[1]));

    return g;
}

Matrix Linear::funcF (const Vector &m, const Matrix &D) const
{
    double e  = exp (-BB * m[2]);
    Matrix cx = funcG (m, D);
    Matrix cw (2, 4);

    cw (0, 0) = CC * m[0] * m[0] * e * (cos (m[1]) - KK * sin (m[1]));
    cw (0, 1) = 0.0;
    cw (0, 2) = 1.0;
    cw (0, 3) = 0.0;

    cw (1, 0) = 0.0;
    cw (1, 1) = CC * m[0] * m[0] * e * (sin (m[1]) - KK * cos (m[1]));
    cw (1, 2) = 0.0;
    cw (1, 3) = 1.0;

    return cx * D * cx.transpose() + cw * Dw * cw.transpose();
}



}  // end Tasks::Discrete::Landing

}  // end Tasks::Discrete

}  // end Tasks
