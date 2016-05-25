#ifndef FOS_H
#define FOS_H

#include "discrete_filter.h"


namespace Filters
{

namespace Discrete
{


class FOS : public DiscreteFilter
{

public:

    FOS (const FilterParameters &input, const DTask *task, QObject *parent = nullptr)
          : DiscreteFilter (input, task, parent)
    {
        uint p = task->dimY() * input.orderMultiplicity();
        m_name = m_type + " " + m_task->approxType() + "ФКП (" + std::to_string (p) + ")";
    }

protected:

    void algorithm() override;

    Matrix Gamma, T;
    Vector kappa;
};


}  // end Discrete

}  // end Filters

#endif // FOS_H
