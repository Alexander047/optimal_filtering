#include "c_aof.h"


namespace Filters
{

namespace Continuous
{


AOF::AOF (const FilterParameters &input, const CTask *task, QObject *parent)
      : ContinuousFilter (input, task, parent)
{
    long n = task->dimX();
    m_name = m_task->approxType() + "AОФн (" + std::to_string (n * (n + 3) / 2) + ")";
}

void AOF::zeroIteration()
{
    ContinuousFilter::zeroIteration();

    P.resize (SS);
    dy.resize (SS);
    for (size_t s = 0; s < SS; ++s) {
        P[s]  = m_result[0].Dx;
        dy[s] = Vector::Zero (m_task->dimY());
    }
}

void AOF::algorithm()
{
    for (size_t n = 1; n < m_result.size(); ++n) {  // tn = t0 + n * dt
        double t = m_result[n - 1].time;
        Matrix KK = m_task->K (z[0], P[0], t);
        for (size_t s = 0; s < SS; ++s) {
            x[s]  = x[s] + m_task->a (x[s], t) * dt +
                    m_task->B (x[s], t) * Rand::gaussianVector (m_task->dimV(), 0, std::sqrt (dt));
            dy[s] = m_task->c (x[s], t) * dt +
                    m_task->D (x[s], t) * Rand::gaussianVector (m_task->dimW(), 0, std::sqrt (dt));
            y[s]  = y[s] + dy[s];

            Vector z1 = z[s];
            KK += m_task->K (z[s], P[s], t);
            z[s] = z[s] + m_task->a (z[s], t) * dt +
                   m_task->K (z[s], P[s], t) * (dy[s] - m_task->c (z[s], t) * dt);
            P[s] = P[s] + m_task->Psy (z1, P[s], t) * dt;
            P[s] = 0.5 * (P[s] + P[s].transpose());
        }
        KK /= (SS+1);
        writeResult (n);
    }
}


}  // end Filters::Continuous

}  // end Filters
