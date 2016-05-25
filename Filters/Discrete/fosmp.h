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
        m_name = m_type + " " + m_task->approxType() + "ФОСмп (" + std::to_string (p) + ")";
    }

protected:

    void algorithm() override;

    Matrix Gamma, T;
    Vector kappa;
};


}  // end Discrete

}  // end Filters

#endif // FOSMP_H
