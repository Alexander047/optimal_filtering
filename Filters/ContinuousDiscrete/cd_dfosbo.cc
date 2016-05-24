#include "cd_dfosbo.h"


namespace Filters
{

namespace ContinuousDiscrete
{

void DFOSBO::init()
{
    Filter::init();
    Zb.resize (SS);
}


void DFOSBO::zeroIteration()
{
    ContinuousDiscreteFilter::zeroIteration();  // тут вычисляются общие для всех фильтров H0, e0 и
                                                 // т.д. и заполняется результат 0-го шага

    Zb.resize (SS);

    ny = m_task->dimY();
    p  = ny * order_multiplicity;

    for (size_t s = 0; s < SS; ++s) {
        Zb[s] = Vector::Zero (p);
        for (size_t i = 0; i < ny; ++i) {
            Zb[s][i] = y[s][i];
        }
    }
}

void DFOSBO::algorithm()
{
    for (size_t n = 1; n < m_result.size(); ++n) {  // n = 1 .. KK * LL * NN
        for (size_t s = 0; s < SS; ++s) {
            x[s] = x[s] + m_task->a (x[s], m_result[n - 1].time) * dt +
                   m_task->B (x[s], m_result[n - 1].time) *
                   Rand::gaussianVector (m_task->dimV(), 0.0, std::sqrt (dt));
        }

        writeResult (n, true); //  mX, DX вычисляются, а mZ, DZ, mE, DE копируются из предыдущего

        if (n % NN == 0) {
            DxZb  = Cov (x, Zb);
            mZb   = Mean (Zb);
            DZb   = Cov (Zb, mZb);
            Gamma = DxZb * LinAlg::PseudoInverseSVD (DZb);
            kappa = m_result[n].mx - Gamma * mZb;
            if (n % (LL * NN) == 0) {
                T = m_result[n].Dx - Gamma * DxZb.transpose();
            }
            for (size_t s = 0; s < SS; ++s) {
                z[s] = Gamma * Zb[s] + kappa;
            }
            writeResult (n);
        }

        if (n % (LL * NN) == 0) {
            for (size_t s = 0; s < SS; ++s) {
                y[s] = m_task->c (x[s]);  // = Yk (Y в момент t = tk)
                h    = m_task->h (z[s], T);
                G    = m_task->G (z[s], T);
                F    = m_task->F (z[s], T);
                z[s] = z[s] + T * G.transpose() * LinAlg::PseudoInverseSVD (F) * (y[s] - h);

                for (int i = int(p - 1); i >= int(ny); --i) {
                    Zb[s][i] = Zb[s][i - ny];
                }
                for (size_t i = 0; i < ny; ++i) {
                    Zb[s][i] = y[s][i];
                }
            }
            writeResult (n);
        }
    }
}


}  // end ContinuousDiscrete

}  // end Filters
