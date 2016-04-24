#ifndef PRNG_H
#define PRNG_H

#include <cstdlib>
#include <ctime>
#include "matrix.h"
#include "linear_algebra.h"


// ГЕНЕРАЦИЯ СЛУЧАЙНЫХ ВЕЛИЧИН (СКАЛЯРНЫХ И ВЕКТОРНЫХ) :

namespace Rand
{


void setRandomize();
void setRandSeed (uint seed);

// случайные числа:
double uniform();
double uniform (double a, double b);
double gaussian();
double gaussian (double m, double s);
double logNormal (double m, double s);
double chiSquared (uint k);
double students (uint n);
double fishers (uint n1, uint n2);
double rayleighs (double s);
double exponential (double l);

// случайные векторы:
Vector gaussianVector (size_t n);
Vector gaussianVector (size_t n, double m, double s);
Vector gaussianVector (const Vector &m, const Matrix &D);


}  // end Rand


#endif  // PRNG_H
