#include "cd_aof.h"

namespace Filters
{

namespace ContinuousDiscrete
{


void AOF::zeroIteration()
{
    ContinuousDiscreteFilter::zeroIteration();

    P.resize (SS);
    for (size_t s = 0; s < SS; ++s) {
        P[s] = m_result[0].De;
    }
}

void AOF::algorithm()
{
    for (size_t n = 1; n < m_result.size(); ++n) {  // tn = t0 + n * dt
        double t = m_result[n - 1].time;
        for (size_t s = 0; s < SS; ++s) {
            x[s] = x[s] + m_task->a (x[s], t) * dt +
                   m_task->B (x[s], t) * Rand::gaussianVector (m_task->dimV(), 0.0, std::sqrt (dt));
            A     = m_task->A (z[s], P[s], t);
            Theta = m_task->Theta (z[s], P[s], t);
            z[s]  = z[s] + m_task->tau (z[s], P[s], t) * dt;
            P[s]  = P[s] + (A * P[s] + P[s] * A.transpose() + Theta) * dt;
            P[s]  = 0.5 * (P[s] + P[s].transpose());
        }

        if (n % (LL * NN) == 0) {  // t = tk - приходит измерение
            for (size_t s = 0; s < SS; ++s) {
                y[s]  = m_task->c (x[s]);
                h     = m_task->h (z[s], P[s]);
                G     = m_task->G (z[s], P[s]);
                F     = m_task->F (z[s], P[s]);
                Kappa = P[s] * G.transpose() * LinAlg::PseudoInverseSVD (F);
                z[s]  = z[s] + Kappa * (y[s] - h);
                P[s]  = P[s] - Kappa * G * P[s];
                P[s]  = 0.5 * (P[s] + P[s].transpose());
            }
        }

        writeResult (n);
    }
}


}  // end ContinuousDiscrete

}  // end Filters
