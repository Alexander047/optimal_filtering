#ifndef DVANDERPOL_H
#define DVANDERPOL_H

#include "discrete_task.h"


namespace Tasks
{

namespace Discrete
{

namespace VanDerPol
{


class DLinear : public DiscreteTask {
public:
    DLinear();

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

    double omega, alpha, beta;
};

}  // end Tasks::Discrete::VanDerPol

}  // end Tasks::Discrete

}  // end Tasks


#endif // DVANDERPOL_H
