#ifndef DISCRETEFILTER_H
#define DISCRETEFILTER_H

#include "../filter.h"
#include "Tasks/Discrete/discrete_task.h"

namespace Filters
{

namespace ContinuousDiscrete
{


class DiscreteFilter : public Filter
{
public:
    DiscreteFilter (const FilterParameters &input, const DTask *task,
                              QObject *parent = nullptr);
    ~DiscreteFilter();

protected:

    void zeroIteration() override;
};

}  // end Discrete

}  // end Filters


#endif // DISCRETEFILTER_H
