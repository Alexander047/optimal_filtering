#include "filter_factory.h"


Filters::Filter *FilterFactory::createFilter (FILTER_TYPE filterType, FILTER_ID filterId,
                                              TASK_ID taskId, APPROX_TYPE approxType,
                                              const Filters::FilterParameters &input)
{
    Filters::Filter *filter = nullptr;
    if (filterType == FILTER_TYPE::Continuous) {
        // TODO
        // const CTask* task = createCTask (taskId, approxType);
        // filter = createCFilter (filterId, input, task);
    }
    else if (filterType == FILTER_TYPE::Discrete) {
        // TODO
        // const DTask* task = createDTask (taskId, approxType);
        // filter = createDFilter (filterId, input, task);
    }
    else { // if (filterType == FILTER_TYPE::ContinuousDiscrete)
        const CDTask *task = createCDTask (taskId, approxType);
        assert (task != nullptr);
        filter = createCDFilter (filterId, input, task);
    }
    assert (filter != nullptr);
    return filter;
}

CDTask *FilterFactory::createCDTask (TASK_ID id, APPROX_TYPE type)
{
    if (type == APPROX_TYPE::Linear) {
        switch (id) {
        case TASK_ID::Landing:
            return new Tasks::ContinuousDiscrete::Landing::Linear;
        case TASK_ID::VanDerPol:
            return new Tasks::ContinuousDiscrete::VanDerPol::Linear;
        }
    }
    else {
        switch (id) {
        case TASK_ID::Landing:
            return new Tasks::ContinuousDiscrete::Landing::Gauss;
        case TASK_ID::VanDerPol:
            return new Tasks::ContinuousDiscrete::VanDerPol::Gauss;
        }
    }
    return nullptr;
}

Filters::Filter *FilterFactory::createCDFilter (FILTER_ID id,
                                                const Filters::FilterParameters &input,
                                                const CDTask *task)
{
    switch (id) {
    case FILTER_ID::AOF:
        return new Filters::ContinuousDiscrete::AOF (input, task);
    case FILTER_ID::FOS:
        return new Filters::ContinuousDiscrete::FOS (input, task);
    case FILTER_ID::DFOS:
        return new Filters::ContinuousDiscrete::DFOS (input, task);
    case FILTER_ID::DFOSBO:
        return new Filters::ContinuousDiscrete::DFOSBO (input, task);
    }
    return nullptr;
}
