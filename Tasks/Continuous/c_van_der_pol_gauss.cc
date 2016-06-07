#include "c_van_der_pol_gauss.h"


namespace Tasks
{

namespace Continuous
{

namespace VanDerPol
{


Gauss::Gauss () :
    Linear ()
{
    m_approxType = "Г-";
}

Matrix Gauss::funcAA (const Vector &m, const Matrix &D, double /*t*/) const
{
    Matrix A (m_dimX, m_dimX);
    A (0, 0) = 0.0;
    A (0, 1) = 1.0;
    A (1, 0) = -omega * omega - 2.0 * alpha * beta * (m[0] * m[1] + D(0,1));
    A (1, 1) = alpha - alpha * beta * (m[0] * m[0] + D(0,0));
    return A;
}

Matrix Gauss::funcG  (const Vector &/*m*/, const Matrix &/*D*/, double /*t*/) const
{
    Matrix G (m_dimY, m_dimX);
    G << 1.0, 0.0, //WARNING G(0,0) = 2 * m[0] ??
         0.0, 1.0;
    return G;
}

Matrix Gauss::funcQ (const Vector &m, const Matrix &D, double t) const
{
    Matrix b = funcB (m, t);
    Matrix q = b * b.transpose();
    q(1,1) += D(1,1);
    return q;
}


}  // end Tasks::Continuous::VanDerPol

}  // end Tasks::Continuous

}  // end Tasks
