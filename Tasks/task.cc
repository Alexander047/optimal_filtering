#include "task.h"


namespace Tasks
{


Task::Task()
      : m_name (""),
        m_approxType (""),
        m_params (nullptr),
        m_dimX (2),
        m_dimY (2),
        m_dimV (2),
        m_dimW (2),
        mx (Vector::Zero (2)),
        mv (Vector::Zero (2)),
        mw (Vector::Zero (2)),
        Dx (Matrix::Zero (2, 2)),
        Dv (Matrix::Zero (2, 2)),
        Dw (Matrix::Zero (2, 2))
{
}

Task::~Task()
{
    delete m_params;
}

const std::string& Task::name() const
{
    return m_name;
}

const std::string& Task::approxType() const
{
    return m_approxType;
}

SpecificParameters* Task::parameters() const
{
    return m_params;
}

long Task::dimX() const
{
    return m_dimX;
}

long Task::dimY() const
{
    return m_dimY;
}

long Task::dimV() const
{
    return m_dimV;
}

long Task::dimW() const
{
    return m_dimW;
}

const Vector& Task::meanX() const
{
    return mx;
}

const Vector& Task::meanV() const
{
    return mv;
}

const Vector& Task::meanW() const
{
    return mw;
}

const Matrix& Task::covX() const
{
    return Dx;
}

const Matrix& Task::covV() const
{
    return Dv;
}

const Matrix& Task::covW() const
{
    return Dw;
}

Vector Task::x0() const
{
    return Rand::gaussianVector (mx, Dx);
}

void Task::setMeanX (const Vector &m)
{
    assert (m.size() == m_dimX);
    mx = m;
}

void Task::setMeanV (const Vector &m)
{
    mv = m;
}

void Task::setMeanW (const Vector &m)
{
    mw = m;
}

void Task::setCovX (const Matrix &D)
{
    assert (D.rows() == m_dimX);
    assert (D.cols() == m_dimX);
    Dx = D;
}

void Task::setCovV (const Matrix &D)
{
    Dv = D;
}

void Task::setCovW (const Matrix &D)
{
    Dw = D;
}


}  // end Tasks
