#ifndef FILTERFACTORY_H
#define FILTERFACTORY_H


#include "Filters/filters.h"
#include "Tasks/tasks.h"


enum class FILTER_ID { AOF, FOS, DFOS, DFOSBO };
enum class FILTER_TYPE { Continuous, Discrete, ContinuousDiscrete };
enum class TASK_ID { Landing, VanDerPol };
enum class APPROX_TYPE { Linear, Gauss };


class FilterFactory
{

public:

    Filters::Filter *createFilter (FILTER_TYPE filterType, FILTER_ID filterId, TASK_ID taskId,
                                   APPROX_TYPE approxType, const Filters::FilterParameters &input);


private:

    CDTask *createCDTask (TASK_ID id, APPROX_TYPE type);
    CTask *createCTask (TASK_ID id, APPROX_TYPE type);
    DTask *createDTask (TASK_ID id, APPROX_TYPE type);

    Filters::Filter *createCDFilter (FILTER_ID id, const Filters::FilterParameters &input,
                                     const CDTask *task);
    Filters::Filter* createCFilter (FILTER_ID id, const Filters::FilterParameters& input,
                                    const CTask* task);
     Filters::Filter* createDFilter (FILTER_ID id, const Filters::FilterParameters& input,
                                     const DTask* task);
};


#endif  // FILTERFACTORY_H
