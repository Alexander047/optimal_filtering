#ifndef FOS_H
#define FOS_H

#include "continuous_discrete_filter.h"


namespace Filters
{

namespace ContinuousDiscrete
{


class FOS : public ContinuousDiscreteFilter
{

public:

    FOS (const FilterParameters &input, const CDTask *task, QObject *parent = nullptr)
          : ContinuousDiscreteFilter (input, task, parent)
    {
        uint n = task->dimX();
        m_name = m_type + " " + m_task->approxType() + "ФМП (" + std::to_string (n) + ")";
    }


protected:

    void algorithm() override;

    Matrix Gamma;
    Vector kappa;
};


}  // end ContinuousDiscrete

}  // end Filters


#endif  // FOS_H
