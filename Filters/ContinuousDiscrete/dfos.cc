#include "dfos.h"


namespace Filters
{

namespace ContinuousDiscrete
{


void DFOS::algorithm()
{
    Matrix Dxz = Cov (x, z);

    for (size_t n = 1; n < m_result.size(); ++n) {
        for (size_t s = 0; s < SS; ++s) {
            x[s] = x[s] + m_task->a (x[s], m_result[n - 1].time) * dt +
                   m_task->B (x[s], m_result[n - 1].time) *
                   Rand::gaussianVector (m_task->dimV(), 0.0, std::sqrt (dt));
        }

        writeResult (n, true); //  mX, DX вычисляются, а mZ, DZ, mE, DE копируются из предыдущего

        if (n % NN == 0) {  // t = t_tau_k^i
            Dxz   = Cov (x, z);
            Gamma = Dxz * LinAlg::PseudoInverseSVD (m_result[n].Dz);
            kappa = m_result[n].mx - Gamma * m_result[n].mz;
            if (n % (LL * NN) == 0) {
                T = m_result[n].Dx - Gamma * Dxz.transpose();
            }
            for (size_t s = 0; s < SS; ++s) {
                z[s] = Gamma * z[s] + kappa;
            }
            writeResult (n);
        }

        if (n % (LL * NN) == 0)  // t = tk
        {
            for (size_t s = 0; s < SS; ++s) {
                y[s] = m_task->c (x[s]);  // = Yk (Y в момент t = tk)
                h    = m_task->h (z[s], T);
                G    = m_task->G (z[s], T);
                F    = m_task->F (z[s], T);
                z[s] = z[s] + T * G.transpose() * LinAlg::PseudoInverseSVD (F) * (y[s] - h);
            }
            writeResult (n);
        }
    }
}


}  // end ContinuousDiscrete

}  // end Filters
