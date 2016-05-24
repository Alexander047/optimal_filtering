#ifndef CONTINUOUS_DISCRETE_LANDING_LINEAR_H
#define CONTINUOUS_DISCRETE_LANDING_LINEAR_H

#include "continuous_discrete_task.h"


namespace Tasks
{

namespace ContinuousDiscrete
{

namespace Landing
{


class Linear : public ContinuousDiscreteTask
{

public:

    Linear();


protected:

    Vector funcA (const Vector &x, double t) const override;
    Matrix funcB (const Vector &x, double t) const override;
    Vector funcTau (const Vector &m, const Matrix &D, double t) const override;
    Matrix funcTheta (const Vector &m, const Matrix &D, double t) const override;
    Matrix funcAA (const Vector &m, const Matrix &D, double t) const override;

    Vector funcC (const Vector &x) const override;
    Vector funcH (const Vector &m, const Matrix &D) const override;
    Matrix funcG (const Vector &m, const Matrix &D) const override;
    Matrix funcF (const Vector &m, const Matrix &D) const override;
};


}  // end Tasks::ContinuousDiscrete::Landing

}  // end Tasks::ContinuousDiscrete

}  // end Tasks


#endif  // CONTINUOUS_DISCRETE_LANDING_LINEAR_H
