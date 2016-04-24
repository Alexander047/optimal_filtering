#ifndef FILTERINPUT_H
#define FILTERINPUT_H

#include "Core/array.h"
#include "Core/matrix.h"


namespace Filters
{


class FilterParameters
{

public:
    FilterParameters (double max_t, double step_measurement, double step_prediction,
                      double step_integration, uint order_multiplicity, uint sample_size);

    double maxTime() const
    {
        return m_maximumTime;
    }

    double integrationStep() const
    {
        return m_integrationStep;
    }

    double measurementStep() const
    {
        return m_measurementStep;
    }

    double predictionStep() const
    {
        return m_predictionStep;
    }

    uint measurementCount() const
    {
        return m_measurementCount;
    }

    uint predictionCount() const
    {
        return m_predictionCount;
    }

    uint integrationCount() const
    {
        return m_integrationCount;
    }

    uint orderMultiplicity() const
    {
        return m_orderMultiplicity;
    }

    uint sampleSize() const
    {
        return m_sampleSize;
    }

    void setMaxTime (double max_t);
    void setIntegrationStep (double step_integration);
    void setMeasurementStep (double step_measurement);
    void setPredictionStep (double step_prediction);
    void setOrderMultiplicity (uint order_multiplicity);
    void setSampleSize (uint sample_size);


private:

    double m_integrationStep;
    double m_measurementStep;
    double m_predictionStep;
    double m_maximumTime;
    uint m_measurementCount;
    uint m_predictionCount;
    uint m_integrationCount;
    uint m_orderMultiplicity;
    uint m_sampleSize;

    void correctStepAndCount (double interval, double &step, uint &count);
};


}  // end Filters


#endif  // FILTERINPUT_H
