#include "discrete_filter.h"

namespace Filters
{

namespace Discrete
{


DiscreteFilter::DiscreteFilter (const FilterParameters &input,
                                                    const DTask *task, QObject *parent)
      : Filter (input, parent), m_task (task)
{
    order_multiplicity = input.orderMultiplicity();
    m_type             = "д";
}

DiscreteFilter::~DiscreteFilter()
{
    delete m_task;
}

void DiscreteFilter::zeroIteration()
{
    for (size_t s = 0; s < SS; ++s) {
        x[s] = m_task->x0();
        y[s] = m_task->c(x[s]);
    }

    Vector mx0  = Mean (x);
    Vector my0  = Mean (y);
    Matrix Dy0  = Cov (y, my0);
    Matrix Dxy0 = Cov (x, y);

    Matrix H0 = Dxy0 * LinAlg::PseudoInverseSVD (Dy0);
    Vector e0 = mx0 - H0 * my0;

    for (size_t s = 0; s < SS; ++s) {
        z[s] = H0 * y[s] + e0;
        e[s] = x[s] - z[s];
    }

    m_result[0].mx   = mx0;
    m_result[0].Dx   = Cov (x, m_result[0].mx);
    m_result[0].mz   = Mean (z);
    m_result[0].me   = Mean (e);
    m_result[0].Dz   = Cov (z, m_result[0].mz);
    m_result[0].De   = Cov (e, m_result[0].me);
    m_result[0].time = 0.0;
}


}  // end Discrete

}  // end Filters
