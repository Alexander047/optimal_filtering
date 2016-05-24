#include "continuous_filter.h"


namespace Filters
{

namespace Continuous
{


ContinuousFilter::ContinuousFilter (const FilterParameters &input, const CTask *task,
                                    QObject *parent)
      : Filter (input, parent)
{
    m_task             = task;
    order_multiplicity = input.orderMultiplicity();
    m_type             = "н";
}

ContinuousFilter::~ContinuousFilter()
{
    delete m_task;
}

void ContinuousFilter::zeroIteration()
{
    for (size_t s = 0; s < SS; ++s) {
        x[s] = m_task->x0();
        y[s] = Vector::Zero (m_task->dimY());
    }

    m_result[0].mx = Mean (x);
    m_result[0].Dx = Cov (x, m_result[0].mx);
    m_result[0].mz = m_result[0].mx;

    for (size_t s = 0; s < SS; ++s) {
        z[s] = m_result[0].mx;
        e[s] = x[s] - z[s];
    }

    m_result[0].me   = Mean (e);
    m_result[0].Dz   = Cov (z, m_result[0].mz);
    m_result[0].De   = Cov (e, m_result[0].me);
    m_result[0].time = 0.0;
}


}  // end Continuous

}  // end Filters
