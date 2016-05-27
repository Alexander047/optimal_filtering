#include "c_fos.h"


namespace Filters
{

namespace Continuous
{


FOS::FOS (const FilterParameters &input, const CTask *task, QObject *parent)
      : ContinuousFilter (input, task, parent)
{
    long n = task->dimX();
    m_name = m_task->approxType() + "ФОСн (" + std::to_string (n) + ")";
}

void FOS::zeroIteration()
{
    ContinuousFilter::zeroIteration();

    dy.resize (SS);
    for (size_t s = 0; s < SS; ++s) {
        dy[s] = Vector::Zero (m_task->dimY());
    }
}

void FOS::algorithm()
{
    Matrix Gamma;
    for (size_t n = 1; n < m_result.size(); ++n) {  // tn = t0 + n * dt
        double t = m_result[n - 1].time;
        Gamma = m_result[n - 1].Dx - m_result[n - 1].Dz;
        for (size_t s = 0; s < SS; ++s) {
            x[s]  = x[s] + m_task->a (x[s], t) * dt +
                    m_task->B (x[s], t) * Rand::gaussianVector (m_task->dimV(), 0, std::sqrt (dt));
            dy[s] = m_task->c (x[s], t) * dt +
                    m_task->D (x[s], t) * Rand::gaussianVector (m_task->dimW(), 0, std::sqrt (dt));
            y[s]  = y[s] + dy[s];

            z[s] = z[s] + m_task->a (z[s], t) * dt +
                   m_task->K (z[s], Gamma, t) * (dy[s] - m_task->c (z[s], t) * dt);
        }
        writeResult (n);
    }
}


}  // end Filters::Continuous

}  // end Filters
