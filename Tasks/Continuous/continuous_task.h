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

    ContinuousTask();
    ~ContinuousTask();

    Vector a (const Vector &x, double t) const;
    Matrix B (const Vector &x, double t) const;
    Vector c (const Vector &x, double t) const;
    Matrix D (const Vector &x, double t) const;
    Matrix A (const Vector &m, const Matrix &D, double t) const;
    Matrix G (const Vector &m, const Matrix &D, double t) const;
    Matrix K (const Vector &x, const Matrix &D, double t) const;
    Matrix Psy (const Vector &x, const Matrix &D, double t) const;

protected:

    virtual Vector funcA  (const Vector &x, double t) const = 0;
    virtual Matrix funcB  (const Vector &x, double t) const = 0;
    virtual Vector funcC  (const Vector &x, double t) const = 0;
    virtual Matrix funcD  (const Vector &x, double t) const = 0;
    virtual Matrix funcAA (const Vector &m, const Matrix &D, double t) const = 0;
    virtual Matrix funcG  (const Vector &m, const Matrix &D, double t) const = 0;
    virtual Matrix funcQ  (const Vector &m, const Matrix &D, double t) const = 0;
    virtual Matrix funcS  (const Vector &m, const Matrix &D, double t) const = 0;
    virtual Matrix funcR  (const Vector &m, const Matrix &D, double t) const = 0;
};


}  // end Tasks::Continuous

}  // end Tasks


using CTask = Tasks::Continuous::ContinuousTask;


#endif  // CONTINUOUS_TASK_H
