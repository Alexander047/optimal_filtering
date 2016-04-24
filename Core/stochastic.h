#ifndef STOCHASTIC_H
#define STOCHASTIC_H

#include "matrix.h"
#include "array.h"
#include "prng.h"


// МОМЕНТНЫЕ ХАРАКТЕРИСТИКИ СВ (ПО ВЫБОРКАМ) :

double Mean (const Array< double > &x);
double Cov (const Array< double > &x, const Array< double > &y);
double Cov (const Array< double > &x, double mx);

Vector Mean (const Array< Vector > &x);
Matrix Cov (const Array< Vector > &x, const Array< Vector > &y);
Matrix Cov (const Array< Vector > &x, const Vector &mx);


#endif  // STOCHASTIC_H
