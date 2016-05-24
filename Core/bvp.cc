#include "bvp.h"


Array< Vector > solveBvp (Vector (*rhs) (double, const Vector &), double initTime, double finalTime,
                          Vector initState, Vector finalState, VectorInt initUnknown, double step,
                          double epsilon)
{
    assert (initState.size () == finalState.size ());
    assert (initState.size () == initUnknown.size ());
    assert (initState.size () == rhs (0, initState).size ());

    long dim = initState.size ();
    int mult = (initTime > finalTime ? -1 : 1);

    std::srand (std::time (0));


    // 1:

    Vector alpha0 (dim), alpha1 (dim);
    for (long i = 0; i < dim; ++i) {
        if (initUnknown[i] != 0) {
            alpha0[i] = Rand::uniform (-100, 100);
        }
        else {
            alpha0[i] = initState[i];
        }
    }
    alpha1 = alpha0;

    SODE sode (rhs);
    Array< Vector > result = sode.solveByRungeKutta4 (initTime, finalTime, step, alpha0);
    Vector beta0;
    if (mult > 0) {
        beta0 = result.last ();
    }
    else {
        beta0 = result.first ();
    }
    Vector beta1 = beta0;

    VectorInt betaIsMoreThanStatePrevious = VectorInt::Zero (dim);
    VectorInt betaIsMoreThanStateCurrent  = VectorInt::Zero (dim);
    bool good                             = true;
    for (long i = 0; i < dim; ++i) {
        if (initUnknown[i] != 0) {
            if (std::fabs (beta0[i] - finalState[i]) > epsilon) {
                good = false;
                if (beta0[i] > finalState[i]) {
                    betaIsMoreThanStateCurrent[i] = 1;
                }
                else {
                    betaIsMoreThanStateCurrent[i] = -1;
                }
            }
            else {
                betaIsMoreThanStateCurrent[i] = 0;
            }
        }
    }
    if (good) {
        return result;
    }


    // 2:

    bool rangeIsBad = true;
    while (rangeIsBad) {
        betaIsMoreThanStatePrevious = betaIsMoreThanStateCurrent;
        for (long i = 0; i < dim; ++i) {
            if (betaIsMoreThanStateCurrent[i] == 1) {
                alpha1[i] = Rand::uniform (alpha1[i] - 101, alpha1[i] - 1);
            }
            else if (betaIsMoreThanStateCurrent[i] == -1) {
                alpha1[i] = Rand::uniform (alpha1[i] + 1, alpha1[i] + 101);
            }
        }
        result = sode.solveByRungeKutta4 (initTime, finalTime, step, alpha1);
        if (mult > 0) {
            beta1 = result.last ();
        }
        else {
            beta1 = result.first ();
        }

        good       = true;
        rangeIsBad = false;
        for (long i = 0; i < dim; ++i) {
            if (initUnknown[i] != 0) {
                if (std::fabs (beta1[i] - finalState[i]) > epsilon) {
                    good = false;
                    if (beta1[i] > finalState[i]) {
                        betaIsMoreThanStateCurrent[i] = 1;
                    }
                    else {
                        betaIsMoreThanStateCurrent[i] = -1;
                    }
                    if (betaIsMoreThanStateCurrent[i] * betaIsMoreThanStatePrevious[i] > 0) {
                        rangeIsBad = true;
                    }
                }
                else {
                    betaIsMoreThanStateCurrent[i] = 0;
                }
            }
        }
        if (good) {
            return result;
        }
    }


    // 3:

    alpha1 = initState;
    for (long i = 0; i < dim; ++i) {
        if (initUnknown[i] != 0) {
            alpha1[i] = alpha0[i] + 0.001 * step;
        }
    }
    for (long i = 0; i < dim; ++i) {
        if (initUnknown[i] != 0) {
            beta1 = sode.solveByRungeKutta4 (initTime, finalTime, step, alpha1).last ();
            alpha1[i] = alpha0[i] + 0.001 * step *
                                    (finalState[i] - beta0[i]) / (beta1[i] - beta0[i]);
        }
    }

    while (true) {
        beta0  = beta1;
        result = sode.solveByRungeKutta4 (initTime, finalTime, step, alpha1);
        if (mult > 0) {
            beta1 = result.last ();
        }
        else {
            beta1 = result.first ();
        }
        good = true;
        for (long i = 0; i < dim; ++i) {
            if (initUnknown[i] != 0) {
                if (std::fabs (beta1[i] - finalState[i]) > epsilon) {
                    good = false;
                }
            }
        }
        if (good) {
            return result;
        }
        for (long i = 0; i < dim; ++i) {
            if (initUnknown[i] != 0) {
                double tmp = alpha1[i] + (alpha1[i] - alpha0[i]) *
                                         (finalState[i] - beta1[i]) / (beta1[i] - beta0[i]);
                alpha0[i] = alpha1[i];
                alpha1[i] = tmp;
            }
        }
    }
}
