#ifndef CONTINUOUS_FOS_H
#define CONTINUOUS_FOS_H


#include "continuous_filter.h"


namespace Filters
{

namespace Continuous
{


class FOS : public ContinuousFilter
{

public:

    FOS (const FilterParameters &input, const CTask *task, QObject *parent = nullptr);


protected:

    void zeroIteration() override;
    void algorithm() override;


protected:

    Array< Vector > dy;
};


} // end Filters::Continuous

} // end Filters



#endif // CONTINUOUS_FOS_H
