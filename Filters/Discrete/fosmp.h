#ifndef FOSMP_H
#define FOSMP_H

#include "discrete_filter.h"


namespace Filters
{

namespace Discrete
{


class FOSMP : public DiscreteFilter
{

public:

    FOSMP (const FilterParameters &input, const DTask *task, QObject *parent = nullptr)
          : DiscreteFilter (input, task, parent)
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


}  // end Discrete

}  // end Filters

#endif // FOSMP_H
