#include "filter_parameters.h"


namespace Filters
{


FilterParameters::FilterParameters (double max_t, double step_measurement, double step_prediction,
                                    double step_integration, uint order_multiplicity,
                                    uint sample_size)
{
    m_maximumTime     = max_t;  // это значения устанавливаются в setStep*
    m_predictionStep  = step_prediction;  // но при создании объекта в set-ах о них неизвестно.
    m_integrationStep = step_integration;

    setMeasurementStep (step_measurement);

    setSampleSize (sample_size);
    setOrderMultiplicity (order_multiplicity);
}

void FilterParameters::correctStepAndCount (double interval, double &step, uint &count)
{
    uint tempCount = uint (interval / step);
    if (interval - tempCount * step >= 0.5 * step) {
        tempCount++;
    }
    count = tempCount;
    step  = interval / count;
}

void FilterParameters::setMeasurementStep (double step)
{
    m_measurementStep  = step;
    m_measurementCount = uint (m_maximumTime / m_measurementStep);

    setPredictionStep (m_predictionStep);
}

void FilterParameters::setPredictionStep (double step)
{
    m_predictionStep = step;
    correctStepAndCount (m_measurementStep, m_predictionStep, m_predictionCount);
    assert (m_predictionStep <= m_measurementStep);

    setMaxTime (m_maximumTime);
    setIntegrationStep (m_integrationStep);
}

void FilterParameters::setMaxTime (double max_t)
{
    m_measurementCount = max_t / m_measurementStep;
    double T1 = m_measurementCount * m_measurementStep;
    if (max_t - T1 >= 0.5 * m_measurementStep) {
        m_maximumTime = T1 + m_measurementStep;
        m_measurementCount++;
    }
    else {
        m_maximumTime = T1;
    }
}

void FilterParameters::setIntegrationStep (double step)
{
    assert (step > 0.0);
    m_integrationStep = step;
    correctStepAndCount (m_predictionStep, m_integrationStep, m_integrationCount);
    assert (m_integrationStep <= m_predictionStep);
}

void FilterParameters::setOrderMultiplicity (uint order_multiplicity)
{
    assert (order_multiplicity > 0);
    m_orderMultiplicity = order_multiplicity;
}

void FilterParameters::setSampleSize (uint sample_size)
{
    assert (sample_size > 0);
    m_sampleSize = sample_size;
}


}  // end Filters
