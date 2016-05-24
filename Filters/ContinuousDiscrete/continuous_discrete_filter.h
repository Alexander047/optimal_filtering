#ifndef CONTINUOUS_DISCRETE_FILTER_H
#define CONTINUOUS_DISCRETE_FILTER_H

#include "../filter.h"
#include "Tasks/ContinuousDiscrete/continuous_discrete_task.h"


namespace Filters
{

namespace ContinuousDiscrete
{


class ContinuousDiscreteFilter : public Filter
{

public:

    ContinuousDiscreteFilter (const FilterParameters &input, const CDTask *task,
                              QObject *parent = nullptr);
    ~ContinuousDiscreteFilter();


protected:

    void zeroIteration() override;


protected:

    const CDTask *m_task;
    Vector h;
    Matrix G, F;
};


}  // end ContinuousDiscrete

}  // end Filters


using CDFilter = Filters::ContinuousDiscrete::ContinuousDiscreteFilter;


#endif  // CONTINUOUS_DISCRETE_FILTER_H
