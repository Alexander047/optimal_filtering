#include "filter.h"


namespace Filters
{


Filter::Filter (const FilterParameters &params, QObject *parent)
      : QObject (parent),
        m_name (""),
        m_type (""),
        KK (params.measurementCount()),
        LL (params.predictionCount()),
        NN (params.integrationCount()),
        SS (params.sampleSize()),
        max_t (params.maxTime()),
        delta_t (params.measurementStep()),
        delta_tau (params.predictionStep()),
        dt (params.integrationStep()),
        order_multiplicity (params.orderMultiplicity())
{
    init();
}

void Filter::init()
{
    x.resize (SS);
    y.resize (SS);
    z.resize (SS);
    e.resize (SS);

    size_t size = size_t (KK) * size_t (LL) * size_t (NN) + 1;
    m_result.resize (size);
    for (size_t i = 0; i < size; ++i) {
        m_result[i].time = dt * i;
    }
}

double Filter::run()
{
    long long time_start = std::clock();
    zeroIteration();
    algorithm();
    return double((std::clock() - time_start) / double(CLOCKS_PER_SEC));
}

void Filter::writeResult (size_t n, bool copy)
{
    assert (n < m_result.size());

    m_result[n].mx = Mean (x);
    m_result[n].Dx = Cov (x, m_result[n].mx);

    if (copy) {
        m_result[n].mz = m_result[n - 1].mz;
        m_result[n].me = m_result[n - 1].me;
        m_result[n].Dz = m_result[n - 1].Dz;
        m_result[n].De = m_result[n - 1].De;
    }
    else {
        for (size_t s = 0; s < SS; ++s) {
            e[s] = x[s] - z[s];
        }
        m_result[n].mz = Mean (z);
        m_result[n].Dz = Cov (z, m_result[n].mz);
        m_result[n].me = Mean (e);
        m_result[n].De = Cov (e, m_result[n].me);
    }

    emit updatePercent (int (100 * n / m_result.size()));
}

}  // end Filters
