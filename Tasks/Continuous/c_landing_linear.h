#ifndef CONTINUOUS_LANDING_LINEAR_H
#define CONTINUOUS_LANDING_LINEAR_H

#include "continuous_task.h"


namespace Tasks
{

namespace Continuous
{

namespace Landing
{


class Linear : public ContinuousTask
{

public:

    Linear();


protected:

    Vector funcA  (const Vector &x, double t) const override;
    Matrix funcB  (const Vector &x, double t) const override;
    Vector funcC  (const Vector &x, double t) const override;
    Matrix funcD  (const Vector &x, double t) const override;
    Matrix funcAA (const Vector &x, double t) const override;
    Matrix funcG  (const Vector &x, double t) const override;

    double omega, alpha, beta;
};


}  // end Tasks::Continuous::Landing

}  // end Tasks::Continuous

}  // end Tasks


#endif // CONTINUOUS_LANDING_LINEAR_H
