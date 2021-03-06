#ifndef DISCRETE_LINEAR_H
#define DISCRETE_LINEAR_H

#include "discrete_task.h"


namespace Tasks
{

namespace Discrete
{

namespace Landing
{

class Linear : public DiscreteTask
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

}  // end Tasks::Discrete::Landing

}  // end Tasks::Discrete

}  // end Tasks


#endif // DISCRETE_LINEAR_H
