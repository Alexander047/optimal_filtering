#ifndef CONTINUOUSDISCRETETASK_H
#define CONTINUOUSDISCRETETASK_H

#include "../task.h"


namespace Tasks
{


namespace ContinuousDiscrete
{


class ContinuousDiscreteTask : public Task
{

public:
    ContinuousDiscreteTask() : Task()
    { /*...*/
    }

    // функции объекта :
    Vector a (const Vector &x, double t) const
    {
        return funcA (x, t);
    }

    Matrix B (const Vector &x, double t) const
    {
        return funcB (x, t);
    }

    Vector tau (const Vector &m, const Matrix &D, double t) const
    {
        return funcTau (m, D, t);
    }

    Matrix Theta (const Vector &m, const Matrix &D, double t) const
    {
        return funcTheta (m, D, t);
    }

    Matrix A (const Vector &m, const Matrix &D, double t) const
    {
        return funcAA (m, D, t);
    }

    // функции измерителя :
    Vector c (const Vector &x) const
    {
        return funcC (x);
    }

    Vector h (const Vector &m, const Matrix &D) const
    {
        return funcH (m, D);
    }

    Matrix G (const Vector &m, const Matrix &D) const
    {
        return funcG (m, D);
    }

    Matrix F (const Vector &m, const Matrix &D) const
    {
        return funcF (m, D);
    }


protected:

    // функции объекта :
    virtual Vector funcA (const Vector &x, double t) const = 0;
    virtual Matrix funcB (const Vector &x, double t) const = 0;
    virtual Vector funcTau (const Vector &m, const Matrix &D, double t) const = 0;
    virtual Matrix funcTheta (const Vector &m, const Matrix &D, double t) const = 0;
    virtual Matrix funcAA (const Vector &m, const Matrix &D, double t) const = 0;

    // функции измерителя :
    virtual Vector funcC (const Vector &pred_x) const = 0;
    virtual Vector funcH (const Vector &m, const Matrix &D) const = 0;
    virtual Matrix funcG (const Vector &m, const Matrix &D) const = 0;
    virtual Matrix funcF (const Vector &m, const Matrix &D) const = 0;
};


}  // end Tasks::ContinuousDiscrete

}  // end Tasks


using CDTask = Tasks::ContinuousDiscrete::ContinuousDiscreteTask;


#endif  // CONTINUOUSDISCRETETASK_H
