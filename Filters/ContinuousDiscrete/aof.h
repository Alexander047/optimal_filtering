#ifndef CD_AOF_H
#define CD_AOF_H

#include "continuous_discrete_filter.h"


namespace Filters
{

namespace ContinuousDiscrete
{


class AOF : public ContinuousDiscreteFilter
{

public:

    AOF (const FilterParameters &input, const CDTask *task, QObject *parent = nullptr)
          : ContinuousDiscreteFilter (input, task, parent)
    {
        uint n = task->dimX();
        m_name = m_type + " " + m_task->approxType() +
                 "AОФ (" + std::to_string (n * (n + 3) / 2) + ")";
    }


protected:

    void zeroIteration() override;
    void algorithm() override;


protected:

    Array< Matrix > P;
    Matrix R, A, Kappa, Theta;
};


}  // end ContinuousDiscrete

}  // end Filters


#endif  // CD_AOF_H
