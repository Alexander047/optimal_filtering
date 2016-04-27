#ifndef CONTINUOUS_AOF_H
#define CONTINUOUS_AOF_H

#include "continuous_filter.h"


namespace Filters
{

namespace Continuous
{


class AOF : public ContinuousFilter
{

public:

    AOF (const FilterParameters &input, const CTask *task, QObject *parent = nullptr);


protected:

    void zeroIteration() override;
    void algorithm() override;


protected:

    Array< Matrix > P, dy;
};


} // end Filters::Continuous

} // end Filters


#endif // CONTINUOUS_AOF_H
