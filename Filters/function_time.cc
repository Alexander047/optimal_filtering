#include "function_time.h"


FunctionTime::FunctionTime (const double initialTime) :
    m_time (initialTime)
{
}

FunctionTime::~FunctionTime()
{
}

void FunctionTime::setTime (const double newTime)
{
    m_time = newTime;
}

void FunctionTime::setTimeStep (const double newStep)
{
    m_timeStep = newStep;
}

void FunctionTime::advanceTime (const double timeStep)
{
    double dt = m_timeStep;
    if (timeStep > 0) {
        dt = timeStep;
    }
    setTime (m_time + dt);
}

double FunctionTime::time() const
{
    return m_time;
}

double FunctionTime::timeStep() const
{
    return m_timeStep;
}
