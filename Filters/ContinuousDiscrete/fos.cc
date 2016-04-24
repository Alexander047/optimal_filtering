#include "fos.h"


namespace Filters
{

namespace ContinuousDiscrete
{


void FOS::algorithm()
{
    Gamma = Cov (x, x) - Cov (z, z);

    for (size_t n = 1; n < m_result.size(); ++n) {
        double t = m_result[n - 1].time;  // время получения предыдущей оценки = tau_k0
        Gamma    = Cov (x, x) - Cov (z, z);  // Gamma для t = tn - dt;

        for (size_t s = 0; s < SS; ++s) {
            x[s] = x[s] + m_task->a (x[s], t) * dt +
                   m_task->B (x[s], t) * Rand::gaussianVector (m_task->dimV(), 0.0, std::sqrt (dt));
            z[s] = z[s] + m_task->tau (z[s], Gamma, m_result[n - 1].time) * dt;
        }

        if (n % (LL * NN) == 0) {
            Gamma = Cov (x, x) - Cov (z, z);  // здесь нужна Gamma для t = tn = tk
            for (size_t s = 0; s < SS; ++s) {
                y[s] = m_task->c (x[s]);
                h    = m_task->h (z[s], Gamma);
                G    = m_task->G (z[s], Gamma);
                F    = m_task->F (z[s], Gamma);
                z[s] = z[s] + Gamma * G.transpose() * LinAlg::PseudoInverseSVD (F) * (y[s] - h);
            }
        }
        writeResult (n);
    }
}


}  // end ContinuousDiscrete

}  // end Filters
