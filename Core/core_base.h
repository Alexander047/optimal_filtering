#ifndef CORE_BASE_H
#define CORE_BASE_H

#include <limits>
#include <cmath>

//#define NDEBUG  /* раскомментировать, чтобы выключить assert-ы в релизе */
#include <cassert>


typedef unsigned int uint;


namespace Const
{

static const double PI  = 3.14159265358979323846;
static const double E   = 2.71828182845904523536;
static const double EPS = std::numeric_limits< double >::epsilon();
static const double MIN = std::numeric_limits< double >::min();
static const double MAX = std::numeric_limits< double >::max();
static const double INF = std::numeric_limits< double >::infinity();

}  // end Const


//----------------------------------------------------------------------------//


inline double Min (double r1, double r2)
{
    return r1 < r2 ? r1 : r2;
}

inline double Min (double r1, double r2, double r3)
{
    return Min (Min (r1, r2), r3);
}

inline double Max (double r1, double r2)
{
    return r1 > r2 ? r1 : r2;
}

inline double Max (double r1, double r2, double r3)
{
    return Max (Max (r1, r2), r3);
}

inline double Abs (double r)
{
    return r < 0.0 ? -r : r;
}

inline double Sign (double r)
{
    if (r > Const::EPS) {
        return 1.0;
    }
    if (r < -Const::EPS) {
        return -1.0;
    }
    return 0.0;
}

inline double DegToRad (double x)
{
    return x * Const::PI / 180.0;
}

inline double RadToDeg (double x)
{
    return x * 180.0 / Const::PI;
}


#endif  // CORE_BASE_H
