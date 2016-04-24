#ifndef FILTER_H
#define FILTER_H

#include <QObject>

#include "Core/array.h"
#include "Core/matrix.h"
#include "Core/stochastic.h"
#include "filter_parameters.h"
#include "filter_output.h"


namespace Filters
{


class Filter : public QObject
{
    Q_OBJECT

public:

    explicit Filter (const FilterParameters &params, QObject *parent = nullptr);
    virtual ~Filter()
    { /*...*/
    }

    Filter (const Filter &)           = delete;
    Filter &operator=(const Filter &) = delete;

    virtual const std::string &name() const
    {
        return m_name;
    }

    const FilterOutput &result() const
    {
        return m_result;
    }

    double run();


protected:

    virtual void init();
    virtual void zeroIteration() = 0;
    virtual void algorithm() = 0;
    void writeResult (size_t n, bool copy = false);


signals:

    void updatePercent (int p);


protected:

    std::string m_name;
    std::string m_type;
    FilterOutput m_result;

    uint KK;  // - кол-во измерений
    uint LL;  // - кол-во прогнозов между измерениями (t_k = t_k0 < t_k1 < ... < t_kL = t_k+1)
    uint NN;  // - кол-во узлов интегрирования между прогнозами
    size_t SS;  // - размер выборок

    double max_t;
    double delta_t;    // - шаг между измерениями
    double delta_tau;  // - шаг между прогнозами, delta_tau = delta_t / L
    double dt;         // - шаг интегрирования

    uint order_multiplicity;  // в книге p = l * ny, здесь order_multiplicity = l

    Array< Vector > x;
    Array< Vector > y;
    Array< Vector > z;
    Array< Vector > e;  // массивы для выборок
};


}  // end Filters


#endif  // FILTER_H
