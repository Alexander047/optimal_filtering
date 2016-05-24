#ifndef VANDERPOLGAUSS_H
#define VANDERPOLGAUSS_H

#include "cd_van_der_pol_linear.h"


namespace Tasks
{

namespace ContinuousDiscrete
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


}  // end Tasks::ContinuousDiscrete::VanDerPol

}  // end Tasks::ContinuousDiscrete

}  // end Tasks


#endif  // VANDERPOLGAUSS_H
