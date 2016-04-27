#ifndef CONTINUOUS_DISCRETE_DFOSBO_H
#define CONTINUOUS_DISCRETE_DFOSBO_H

#include "continuous_discrete_filter.h"


namespace Filters
{

namespace ContinuousDiscrete
{


class DFOSBO : public ContinuousDiscreteFilter
{

public:

    DFOSBO (const FilterParameters &input, const CDTask *task, QObject *parent = nullptr)
          : ContinuousDiscreteFilter (input, task, parent)
    {
        uint p = task->dimY() * input.orderMultiplicity();
        m_name = m_type + " " + m_task->approxType() + "ФКПд (" + std::to_string (p) + ")";
    }


protected:

    void init() override;
    void zeroIteration() override;
    void algorithm() override;

    uint ny, p;
    Array< Vector > Zb;
    Matrix Gamma, T, DZb, DxZb;
    Vector kappa, mx, mZb;
};


}  // end ContinuousDiscrete

}  // end Filters


#endif  // CONTINUOUS_DISCRETE_DFOSBO_H
