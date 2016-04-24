#ifndef TASK_H
#define TASK_H

#include <string>
#include "Core/array.h"
#include "Core/matrix.h"
#include "Core/prng.h"

#include "specific_parameters.h"


namespace Tasks
{


class Task
{

public:

    Task();

    virtual ~Task()
    {
        delete m_params;
    }

    Task (const Task &)           = delete;
    Task &operator=(const Task &) = delete;

    const std::string &name() const
    {
        return m_name;
    }

    const std::string &approxType() const
    {
        return m_approxType;
    }

    SpecificParameters *parameters() const
    {
        return m_params;
    }

    size_t dimX() const
    {
        return mx.size();
    }

    size_t dimY() const
    {
        return my.size();
    }

    size_t dimV() const
    {
        return mv.size();
    }

    size_t dimW() const
    {
        return mw.size();
    }

    const Vector &meanX() const
    {
        return mx;
    }

    const Vector &meanY() const
    {
        return my;
    }

    const Vector &meanV() const
    {
        return mv;
    }

    const Vector &meanW() const
    {
        return mw;
    }

    const Matrix &covX() const
    {
        return Dx;
    }

    const Matrix &covY() const
    {
        return Dy;
    }

    const Matrix &covV() const
    {
        return Dv;
    }

    const Matrix &covW() const
    {
        return Dw;
    }

    Vector x0() const
    {
        return Rand::gaussianVector (mx, Dx);
    }

    void setMeanX (const Vector &m)
    {
        mx = m;
    }
    void setMeanY (const Vector &m)
    {
        my = m;
    }

    void setMeanV (const Vector &m)
    {
        mv = m;
    }

    void setMeanW (const Vector &m)
    {
        mw = m;
    }

    void setCovX (const Matrix &D)
    {
        Dx = D;
    }

    void setCovY (const Matrix &D)
    {
        Dy = D;
    }

    void setCovV (const Matrix &D)
    {
        Dv = D;
    }

    void setCovW (const Matrix &D)
    {
        Dw = D;
    }


protected:

    std::string m_name;
    std::string m_approxType;
    SpecificParameters *m_params;

    Vector mx;
    Vector my;
    Vector mv;  // V -- шум объекта
    Vector mw;  // W -- шум измерителя
    Matrix Dx;
    Matrix Dy;
    Matrix Dv;
    Matrix Dw;
};


}  // end Tasks


#endif  // TASK_H
