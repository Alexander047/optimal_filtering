#ifndef BVP_H
#define BVP_H

#include "ode.h"
#include "prng.h"


Array<Vector> solveBvp (Vector (*rhs)(double, const Vector &), double initTime,
                        double finalTime, Vector initState, Vector finalState,
                        VectorInt initUnknown, double step, double epsilon);


#endif // BVP_H
