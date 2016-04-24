#ifndef ODE_H
#define ODE_H

#include "array.h"
#include "matrix.h"


// Type = double - обыкновенное ДУ
// Type = Vector - система ДУ

template < typename Type >
class Ode
{

public:

    Ode()
    {
        setDefaultRhs();
    }

    explicit Ode (Type (*f) (double, double, const Type &))
    {
        setRhs (f);
    }

    Ode (const Ode &)           = delete;
    Ode &operator=(const Ode &) = delete;

    void setRhs (Type (*f) (double, const Type &))
    {
        m_userRhs        = f;
        m_useDefaultRhs = false;
    }

    void setDefaultRhs()
    {
        m_userRhs        = 0;
        m_useDefaultRhs = true;
    }

    bool defaultRhsUsed() const
    {
        return m_useDefaultRhs;
    }

    Array< Type > solveByEuler (double x0, double x1, double dx, Type y0);
    Array< Type > solveByEulerCauchy (double x0, double x1, double dx, Type y0);
    Array< Type > solveByRungeKutta4 (double x0, double x1, double dx, Type y0);
    Array< Type > solveByAdamsExplicit4 (double x0, double x1, double dx, Type y0);
    Array< Type > solveByAdamsImplicit4 (double x0, double x1, double dx, Type y0);


protected:

    //можно сделать наследника с определенной правой частью:
    virtual Type defaultRhs (double, const Type &)
    {
        return 0;
    }

    //или передать указатель на правую часть:
    Type (*m_userRhs) (double x, const Type &);

    Type rhs (double x, const Type &y)
    {
        if (m_useDefaultRhs) {
            return defaultRhs (x, y);
        }
        return m_userRhs (x, y);
    }

    bool m_useDefaultRhs;

    static size_t calcKnotsCount (double a, double b, double &h)
    {
        double L = Abs (b - a);
        double t = Abs (h);

        // n - количество отрезков, на которые делят интервал интегрирования,
        //узлов на 1 больше : k = n + 1
        size_t n = size_t (L / t);
        if (L - t * double(n) >= 0.5 * t) {
            n++;
        }
        h = L / double(n);

        return n + 1;
    }
};


//простой метод Эйлера:
template < typename Type >
Array< Type > Ode< Type >::solveByEuler (double x0, double x1, double dx, Type y0)
{
    size_t n = calcKnotsCount (x0, x1, dx);
    Array< Type > y (n);

    if (x0 < x1) {
        y[0] = y0;
        for (size_t i = 0; i < n - 1; i++) {
            double xi = x0 + double(i) * dx;
            y[i + 1]  = y[i] + dx * rhs (xi, y[i]);
        }
    }
    else  //решаем в обратном направлении
    {
        y[n - 1] = y0;
        for (size_t i = n - 1; i > 0; i--) {
            double xi = x0 - double(n - i - 1) * dx;
            y[i - 1]  = y[i] - dx * rhs (xi, y[i]);
        }
    }

    return y;
}


//метод Эйлера-Коши (или метод Эйлера с пересчетом):
template < typename Type >
Array< Type > Ode< Type >::solveByEulerCauchy (double x0, double x1, double dx, Type y0)
{
    size_t n = calcKnotsCount (x0, x1, dx);
    Array< Type > y (n);

    if (x0 < x1) {
        y[0] = y0;
        for (size_t i = 0; i < n - 1; i++) {
            double xi = x0 + double(i) * dx;
            Type tmp  = y[i] + dx * rhs (xi, y[i]);
            y[i + 1]  = y[i] + 0.5 * dx * (rhs (xi, y[i]) + rhs (xi + dx, tmp));
        }
    }
    else {
        y[n - 1] = y0;
        for (size_t i = n - 1; i > 0; i--) {
            double xi = x0 - double(n - i - 1) * dx;
            Type tmp  = y[i] - dx * rhs (xi, y[i]);
            y[i - 1]  = y[i] - 0.5 * dx * (rhs (xi, y[i]) + rhs (xi - dx, tmp));
        }
    }

    return y;
}


//метод Рунге-Кутта 4го порядка:
template < typename Type >
Array< Type > Ode< Type >::solveByRungeKutta4 (double x0, double x1, double dx, Type y0)
{
    size_t n = calcKnotsCount (x0, x1, dx);
    Array< Type > y (n);

    if (x0 < x1) {
        y[0] = y0;
        for (size_t i = 0; i < n - 1; i++) {
            double xi = x0 + double(i) * dx;
            Type k1   = dx * rhs (xi, y[i]);
            Type k2   = dx * rhs (xi + 0.5 * dx, y[i] + 0.5 * k1);
            Type k3   = dx * rhs (xi + 0.5 * dx, y[i] + 0.5 * k2);
            Type k4   = dx * rhs (xi + dx, y[i] + k3);
            y[i + 1]  = y[i] + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        }
    }
    else {
        y[n - 1] = y0;
        for (size_t i = n - 1; i > 0; i--) {
            double xi = x0 - double(n - i - 1) * dx;
            Type k1   = dx * rhs (xi, y[i]);
            Type k2   = dx * rhs (xi - 0.5 * dx, y[i] - 0.5 * k1);
            Type k3   = dx * rhs (xi - 0.5 * dx, y[i] - 0.5 * k2);
            Type k4   = dx * rhs (xi - dx, y[i] - k3);
            y[i - 1]  = y[i] - (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        }
    }

    return y;
}

//метод Адамса 4го порядка, явный:
template < typename Type >
Array< Type > Ode< Type >::solveByAdamsExplicit4 (double x0, double x1, double dx, Type y0)
{
    size_t n = calcKnotsCount (x0, x1, dx);
    Array< double > y (n);

    double k1 = 55.0 / 24.0;
    double k2 = 59.0 / 24.0;
    double k3 = 37.0 / 24.0;
    double k4 = 9.0 / 24.0;

    if (x0 < x1) {
        //предварительно найдем значения в 4х точках методом Рунге-Кутты :
        Array< Type > u = solveByRungeKutta4 (x0, x0 + 3 * dx, dx, y0);
        for (size_t i = 0; i < 4; i++) {
            y[i] = u[i];
        }

        Array< double > x (n);
        for (size_t i = 0; i < n; i++) {
            x[i] = x0 + double(i) * dx;
        }

        for (size_t i = 0; i < n - 4; i++) {
            y[i + 4] = y[i + 3] +
                       dx * (k1 * rhs (x[i + 3], y[i + 3]) - k2 * rhs (x[i + 2], y[i + 2]) +
                             k3 * rhs (x[i + 1], y[i + 1]) - k4 * rhs (x[i], y[i]));
        }
    }
    else {
        //предварительно найдем значения в 4х точках методом Рунге-Кутты :
        Array< Type > u = solveByRungeKutta4 (x0, x0 - 3 * dx, dx, y0);
        for (size_t i = 0; i < 4; i++) {
            y[n - 1 - i] = u[3 - i];
        }

        Array< double > x (n);
        for (size_t i = 0; i < (size_t) n; i++) {
            x[i] = x0 - double(n - 1 - i) * dx;
        }

        for (size_t i = n - 4; i > 0; i--) {
            y[i - 1] = y[i] -
                       dx * (k1 * rhs (x[i], y[i]) - k2 * rhs (x[i + 1], y[i + 1]) +
                             k3 * rhs (x[i + 2], y[i + 2]) - k4 * rhs (x[i + 3], y[i + 3]));
        }
    }

    return y;
}


//метод Адамса 4го порядка, неявный:
template < typename Type >
Array< Type > Ode< Type >::solveByAdamsImplicit4 (double x0, double x1, double dx, Type y0)
{
    size_t n = calcKnotsCount (x0, x1, dx);
    Array< Type > y (n);

    double k1 = 55.0 / 24.0;
    double k2 = 59.0 / 24.0;
    double k3 = 37.0 / 24.0;
    double k4 = 9.0 / 24.0;

    double s1 = 251.0 / 720.0;
    double s2 = 646.0 / 720.0;
    double s3 = 264.0 / 720.0;
    double s4 = 106.0 / 720.0;
    double s5 = 19.0 / 720.0;

    if (x0 < x1) {
        //предварительно найдем значения в 4х точках методом Рунге-Кутты :
        Array< Type > u = solveByRungeKutta4 (x0, x0 + 3 * dx, dx, y0);
        for (size_t i = 0; i < 4; i++) {
            y[i] = u[i];
        }

        Array< double > x (n);
        for (size_t i = 0; i < (size_t) n; i++) {
            x[i] = x0 + double(i) * dx;
        }

        for (size_t i = 0; i < n - 4; i++) {
            Type tmp = y[i + 3] +
                       dx * (k1 * rhs (x[i + 3], y[i + 3]) - k2 * rhs (x[i + 2], y[i + 2]) +
                             k3 * rhs (x[i + 1], y[i + 1]) - k4 * rhs (x[i], y[i]));

            y[i + 4] = y[i + 3] +
                       dx * (s1 * rhs (x[i + 4], tmp) + s2 * rhs (x[i + 3], y[i + 3]) -
                             s3 * rhs (x[i + 2], y[i + 2]) + s4 * rhs (x[i + 1], y[i + 1]) -
                             s5 * rhs (x[i], y[i]));
        }
    }
    else {
        //предварительно найдем значения в 4х точках методом Рунге-Кутты :
        Array< Type > u = solveByRungeKutta4 (x0, x0 - 3 * dx, dx, y0);
        for (size_t i = 0; i < 4; i++) {
            y[n - 1 - i] = u[3 - i];
        }

        Array< double > x (n);
        for (size_t i = 0; i < (size_t) n; i++) {
            x[i] = x0 - double(n - 1 - i) * dx;
        }

        for (size_t i = n - 4; i > 1; i--) {
            Type tmp = y[i] -
                       dx * (k1 * rhs (x[i], y[i]) - k2 * rhs (x[i + 1], y[i + 1]) +
                             k3 * rhs (x[i + 2], y[i + 2]) - k4 * rhs (x[i + 3], y[i + 3]));

            y[i - 1] =
            y[i] -
            dx * (s1 * rhs (x[i - 1], tmp) + s2 * rhs (x[i], y[i]) - s3 * rhs (x[i + 1], y[i + 1]) +
                  s4 * rhs (x[i + 2], y[i + 2]) - s5 * rhs (x[i + 3], y[i + 3]));
        }
    }

    return y;
}


typedef Ode< double > ODE;
typedef Ode< Vector > SODE;


#endif  // ODE_H
