#ifndef FILTEROUTPUT_H
#define FILTEROUTPUT_H

#include "Core/array.h"
#include "Core/matrix.h"


namespace Filters
{


struct _SingleFilterOutput_
{
    Vector mx, mz, me;
    Matrix Dx, Dz, De;
    double time;
};


typedef Array< _SingleFilterOutput_ > FilterOutput;


}  // end Filters


#endif  // FILTEROUTPUT_H
