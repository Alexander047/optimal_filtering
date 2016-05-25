#ifndef DISCRETE_VANDERPOL_GAUSS_H
#define DISCRETE_VANDERPOL_GAUSS_H

#include "d_van_der_pol_linear.h"


namespace Tasks
{

namespace Discrete
{

namespace VanDerPol
{


class Gauss : public Linear
{

public:
    Gauss();

protected:

    Vector funcTau (const Vector &m, const Matrix &D, double t) const override;
    Matrix funcTheta (const Vector &m, const Matrix &D, double t) const override;
    Matrix funcAA (const Vector &m, const Matrix &D, double t) const override;

    Vector funcH (const Vector &m, const Matrix &D) const override;
    Matrix funcG (const Vector &m, const Matrix &D) const override;
    Matrix funcF (const Vector &m, const Matrix &D) const override;
};


}  // end Tasks::Discrete::VanDerPol

}  // end Tasks::Discrete

}  // end Tasks


#endif // DISCRETE_VANDERPOL_GAUSS_H
