#ifndef CONTINUOUS_VANDERPOL_GAUSS_H
#define CONTINUOUS_VANDERPOL_GAUSS_H

#include "c_van_der_pol_linear.h"


namespace Tasks
{

namespace Continuous
{

namespace VanDerPol
{


class Gauss : public Linear
{

public:

    Gauss();


protected:

    //TODO
//    Vector funcA  (const Vector &x, double t) const override;
//    Matrix funcB  (const Vector &x, double t) const override;
//    Vector funcC  (const Vector &x, double t) const override;
//    Matrix funcD  (const Vector &x, double t) const override;
//    Matrix funcAA (const Vector &x, double t) const override;
//    Matrix funcG  (const Vector &x, double t) const override;
};


}  // end Tasks::Continuous::VanDerPol

}  // end Tasks::Continuous

}  // end Tasks


#endif // CONTINUOUS_VANDERPOL_GAUSS_H
