#ifndef CONTINUOUS_TASK_H
#define CONTINUOUS_TASK_H

#include "../task.h"


namespace Tasks
{

namespace Continuous
{


class ContinuousTask : public Task
{

public:
    ContinuousTask() : Task()
    { /*...*/
    }

    Vector a (const Vector &x, double t) const
    {
        return funcA (x, t);
    }

    Matrix B (const Vector &x, double t) const
    {
        return funcB (x, t);
    }

    Vector c (const Vector &x, double t) const
    {
        return funcC (x, t);
    }

    Matrix D (const Vector &x, double t) const
    {
        return funcD (x, t);
    }

    Matrix A (const Vector &x, double t) const
    {
        return funcAA (x, t);
    }

    Matrix G (const Vector &x, double t) const
    {
        return funcA (x, t);
    }

    Matrix K (const Vector &x, const Matrix &D, double t) const
    {
        return (D * funcG(x,t).transpose() + funcB(x,t) * funcD(x,t).transpose());
    }

    Matrix Psy (const Vector &x, const Matrix &D, double t) const
    {
        Matrix k = K (x, D, t);
        Matrix a = funcAA (x, t);
        Matrix b = funcB (x, t);
        Matrix d = funcD (x, t);
        return a * D + D * a + b * b.transpose() - k * d * d.transpose() * k;
    }

protected:

    virtual Vector funcA  (const Vector &x, double t) const = 0;
    virtual Matrix funcB  (const Vector &x, double t) const = 0;
    virtual Vector funcC  (const Vector &x, double t) const = 0;
    virtual Matrix funcD  (const Vector &x, double t) const = 0;
    virtual Matrix funcAA (const Vector &x, double t) const = 0;
    virtual Matrix funcG  (const Vector &x, double t) const = 0;
};


}  // end Tasks::Continuous

}  // end Tasks


using CTask = Tasks::Continuous::ContinuousTask;


#endif  // CONTINUOUS_TASK_H
