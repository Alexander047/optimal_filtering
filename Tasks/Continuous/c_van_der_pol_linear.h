#ifndef CONTINUOUS_VANDERPOL_LINEAR_H
#define CONTINUOUS_VANDERPOL_LINEAR_H

#include "continuous_task.h"


namespace Tasks
{

namespace Continuous
{

namespace VanDerPol
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
    Matrix funcAA (const Vector &m, const Matrix &D, double t) const override;
    Matrix funcG  (const Vector &m, const Matrix &D, double t) const override;
    Matrix funcQ  (const Vector &m, const Matrix &D, double t) const override;
    Matrix funcS  (const Vector &m, const Matrix &D, double t) const override;
    Matrix funcR  (const Vector &m, const Matrix &D, double t) const override;

    double omega, alpha, beta;
};


}  // end Tasks::Continuous::VanDerPol

}  // end Tasks::Continuous

}  // end Tasks


#endif // CONTINUOUS_VANDERPOL_LINEAR_H
