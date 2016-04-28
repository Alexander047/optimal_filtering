#ifndef DISCRETE_TASK
#define DISCRETE_TASK

#include "../task.h"

namespace Tasks
{

namespace Discrete
{

class DiscreteTask : public Task
{

public:
    DiscreteTask() : Task()
    { /*...*/
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

}  // end Tasks::Discrete

}  // end Tasks

using DTask = Tasks::Discrete::DiscreteTask;

#endif // DISCRETE_TASK

