#include "c_landing_linear.h"


namespace Tasks
{

namespace Continuous
{

namespace Landing
{


static double KK       = -0.3;
static const double BB = 0.09;
static const double CC = 0.043333333333333333333333333333333333333333333333333;
static const double GG = 3.711E-3;
static const double RR = 3390.0;


Linear::Linear() :
    ContinuousTask ()
{
    m_name       = "Спуск ЛА на планету";
    m_approxType = "Л-";

    m_dimX = 3;
    m_dimY = 2;
    m_dimV = 3;
    m_dimW = 4;

    mx = Vector (m_dimX);
    mx << 6.0,
          DegToRad (-18.0),
          100.0;

    Dx = Matrix (m_dimX, m_dimX);
    Dx << pow (15E-3, 2), 0.0,                     0.0,
          0.0,            pow (DegToRad (1.0), 2), 0.0,
          0.0,            0.0,                     pow (7.0, 2);

    mv = Vector::Zero (m_dimV);
    Dv = Matrix::Zero (m_dimV, m_dimV);

    mw = Vector::Zero (m_dimW);
    Dw = Matrix (m_dimW, m_dimW);
    Dw << pow (1E-2, 2), 0.0,           0.0,           0.0,
          0.0,           pow (1E-2, 2), 0.0,           0.0,
          0.0,           0.0,           pow (2E-7, 2), 0.0,
          0.0,           0.0,           0.0,           pow (2E-7, 2);
}

Vector Linear::funcA (const Vector &x, double t) const
{
    KK = (t < 45.0 ? -0.3 : 0.3);

    double e = exp (-BB * x[2]);
    Vector a (m_dimX);

    a << -CC * x[0] * x[0] * e - GG * sin (x[1]),
          CC * KK * x[0] * e + cos (x[1]) * (x[0] / (RR + x[2]) - GG / x[0]),
          x[0] * sin (x[1]);

    return a;
}

Matrix Linear::funcB (const Vector & /*x*/, double /*t*/) const
{
    return Matrix::Zero (m_dimX, m_dimV);
}


Vector Linear::funcC  (const Vector &x, double /*t*/) const
{
    double e = exp (-BB * x[2]);
    Vector c (m_dimY);

    c << CC * x[0] * x[0] * e * (cos (x[1]) - KK * sin (x[1])),
         CC * x[0] * x[0] * e * (sin (x[1]) - KK * cos (x[1]));

    return c;
}

Matrix Linear::funcD  (const Vector &x, double t) const
{
    Matrix d = Matrix::Zero (m_dimY, m_dimW);
    Vector c = funcC (x, t);

    d << c[0], 0.0,  1.0, 0.0,
         0.0,  c[1], 0.0, 1.0;

    return d;
}

Matrix Linear::funcQ (const Vector &x, const Matrix &/*D*/, double t) const
{
    Matrix b = funcB (x, t);
    return b * b.transpose();
}

Matrix Linear::funcS (const Vector &/*x*/, const Matrix &/*D*/, double /*t*/) const
{
    return Matrix::Zero (m_dimX, m_dimY);
}

Matrix Linear::funcR (const Vector &x, const Matrix &/*D*/, double t) const
{
    Matrix d = funcD (x, t);
    return d * d.transpose();
}

Matrix Linear::funcAA (const Vector &m, const Matrix &/*D*/, double /*t*/) const
{
    double e = exp (-BB * m[2]);
    Matrix a (m_dimX, m_dimX);

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

Matrix Linear::funcG  (const Vector &m, const Matrix &/*D*/, double /*t*/) const
{
    double e = exp (-BB * m[2]);
    Matrix g (m_dimY, m_dimX);

    g (0, 0) = 2 * CC * m[0] * e * (cos (m[1]) - KK * sin (m[1]));
    g (0, 1) = -CC * m[0] * m[0] * e * sin (m[1]);
    g (0, 2) = -BB * CC * m[0] * m[0] * e * (cos (m[1]) - KK * sin (m[1]));

    g (1, 0) = 2 * CC * m[0] * e * (sin (m[1]) - KK * cos (m[1]));
    g (1, 1) = CC * m[0] * m[0] * e * cos (m[1]);
    g (1, 2) = -BB * CC * m[0] * m[0] * e * (sin (m[1]) - KK * cos (m[1]));

    return g;
}


}  // end Tasks::Continuous::Landing

}  // end Tasks::Continuous

}  // end Tasks
