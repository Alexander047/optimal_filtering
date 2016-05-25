#include "filter_factory.h"
#include <QDebug>


Filters::Filter *FilterFactory::createFilter (FILTER_TYPE filterType, FILTER_ID filterId,
                                              TASK_ID taskId, APPROX_TYPE approxType,
                                              const Filters::FilterParameters &input)
{
    Filters::Filter *filter = nullptr;
    if (filterType == FILTER_TYPE::Continuous) {
        const CTask *task = createCTask (taskId, approxType);
        assert (task != nullptr);
        filter = createCFilter (filterId, input, task);
    }
    else if (filterType == FILTER_TYPE::Discrete) {

//        const DTask *task = createDTask (taskId, approxType);
//        assert (task != nullptr);
//        filter = createDFilter (filterId, input, task);

        // TODO
         const DTask* task = createDTask (taskId, approxType);
         filter = createDFilter (filterId, input, task);
    }
    else { // if (filterType == FILTER_TYPE::ContinuousDiscrete)
        const CDTask *task = createCDTask (taskId, approxType);
        assert (task != nullptr);
        filter = createCDFilter (filterId, input, task);
    }
    assert (filter != nullptr);
    return filter;
}

CTask *FilterFactory::createCTask (TASK_ID id, APPROX_TYPE type)
{
    if (type == APPROX_TYPE::Linear) {
        switch (id) {
        case TASK_ID::Landing:
//            return new Tasks::Continuous::Landing::Linear;
            qDebug() << "No Landing for continuous filters";
            return nullptr;
        case TASK_ID::VanDerPol:
            return new Tasks::Continuous::VanDerPol::Linear;
        }
    }
    else {
        switch (id) {
        case TASK_ID::Landing:
//            return new Tasks::Continuous::Landing::Gauss;
            qDebug() << "No Landing for continuous filters";
            return nullptr;
        case TASK_ID::VanDerPol:
            return new Tasks::Continuous::VanDerPol::Gauss;
        }
    }
    return nullptr;
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

Filters::Filter *FilterFactory::createCFilter (FILTER_ID id,
                                                const Filters::FilterParameters &input,
                                                const CTask *task)
{
    switch (id) {
    case FILTER_ID::AOF:
        return new Filters::Continuous::AOF (input, task);
    case FILTER_ID::FOS:
        return new Filters::Continuous::FOS (input, task);
    case FILTER_ID::DFOS:
        qDebug() << "No DFOS as continuous filter!";
        return nullptr;
    case FILTER_ID::DFOSBO:
        qDebug() << "No DFOSBO as continuous filter!";
        return nullptr;
    }
    return nullptr;
}


DTask *FilterFactory::createDTask (TASK_ID id, APPROX_TYPE type)
{
    DTask *task = nullptr;

    if (type == APPROX_TYPE::Linear) {
        switch (id) {
        case TASK_ID::Landing:
            task = new Tasks::Discrete::Landing::DLinear;
            break;
        case TASK_ID::VanDerPol:
            task = new Tasks::Discrete::VanDerPol::DLinear;
            break;
        default:
            task = nullptr;
            break;
        }
    }
    else {
        switch (id) {
        case TASK_ID::Landing:
            task = new Tasks::Discrete::Landing::DGauss;
            break;
        case TASK_ID::VanDerPol:
            task = new Tasks::Discrete::VanDerPol::DGauss;
            break;
        default:
            task = nullptr;
            break;
        }
    }

    assert (task != nullptr);
    return task;
}


Filters::Filter *FilterFactory::createDFilter (FILTER_ID id,
                                               const Filters::FilterParameters& input,
                                               const DTask* task)
{
    switch (id) {
//    case FILTER_ID::AOF:
//        return new Filters::ContinuousDiscrete::AOF (input, task);
//        break;
//    case FILTER_ID::FOS:
//        return new Filters::ContinuousDiscrete::FOS (input, task);
//        break;
//    case FILTER_ID::DFOS:
//        return new Filters::ContinuousDiscrete::DFOS (input, task);
//        break;
    case FILTER_ID::FOSmp:
        return new Filters::Discrete::FOSMP (input, task);
        break;
    default:
        return nullptr;
    }
}
