#ifndef CONTINUOUS_FILTER_H
#define CONTINUOUS_FILTER_H

#include "../filter.h"
#include "Tasks/Continuous/continuous_task.h"


namespace Filters
{

namespace Continuous
{


class ContinuousFilter : public Filter
{

public:

    ContinuousFilter (const FilterParameters &input, const CTask *task,
                              QObject *parent = nullptr);
    ~ContinuousFilter();


protected:

    void zeroIteration() override;


protected:

    const CTask *m_task;
};


}  // end Continuous

}  // end Filters


using CFilter = Filters::Continuous::ContinuousFilter;


#endif  // CONTINUOUS_FILTER_H
