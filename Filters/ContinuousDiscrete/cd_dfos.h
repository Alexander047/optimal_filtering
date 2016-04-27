#ifndef CONTINUOUS_DISCRETE_DFOS_H
#define CONTINUOUS_DISCRETE_DFOS_H

#include "continuous_discrete_filter.h"


namespace Filters
{

namespace ContinuousDiscrete
{


class DFOS : public ContinuousDiscreteFilter
{

public:

    DFOS (const FilterParameters &input, const CDTask *task, QObject *parent = nullptr)
          : ContinuousDiscreteFilter (input, task, parent)
    {
        uint n = task->dimX();
        m_name = m_task->approxType() +  "ФМПнд-дп (" + std::to_string (n) + ")";
    }


protected:

    void algorithm() override;

    Matrix Gamma, T;
    Vector kappa;
};


}  // end ContinuousDiscrete

}  // end Filters


#endif  // CONTINUOUS_DISCRETE_DFOS_H
