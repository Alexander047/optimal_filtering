#ifndef FUNCTIONTIME_H
#define FUNCTIONTIME_H


class FunctionTime
{

public:

    FunctionTime (const double initialTime = 0.0);
    virtual ~FunctionTime();

    double time() const;
    double timeStep() const;
    virtual void setTime (const double newTime);
    virtual void setTimeStep (const double newStep);
    virtual void advanceTime (const double timeStep = 0);


private:

    double m_time;
    double m_timeStep;
};


#endif // FUNCTIONTIME_H
