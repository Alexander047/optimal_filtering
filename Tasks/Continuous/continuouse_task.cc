#include "continuous_task.h"


namespace Tasks
{

namespace Continuous
{


ContinuousTask::ContinuousTask() :
    Task()
{
}

ContinuousTask::~ContinuousTask()
{
}

Vector ContinuousTask::a (const Vector &x, double t) const
{
    assert (x.size() == m_dimX && "ContinuousTask::a(x,t) : corrupt dim of x");
    return funcA (x, t);
}

Matrix ContinuousTask::B (const Vector &x, double t) const
{
    assert (x.size() == m_dimX && "ContinuousTask::B(x,t) : corrupt dim of x");
    return funcB (x, t);
}

Vector ContinuousTask::c (const Vector &x, double t) const
{
    assert (x.size() == m_dimX && "ContinuousTask::c(x,t) : corrupt dim of x");
    return funcC (x, t);
}

Matrix ContinuousTask::D (const Vector &x, double t) const
{
    assert (x.size() == m_dimX && "ContinuousTask::D(x,t) : corrupt dim of x");
    return funcD (x, t);
}

Matrix ContinuousTask::A (const Vector &m, const Matrix &D, double t) const
{
    assert (m.size() == m_dimX && "ContinuousTask::A(m,D,t) : corrupt dim of m");
    return funcAA (m, D, t);
}

Matrix ContinuousTask::G (const Vector &m, const Matrix &D, double t) const
{
    assert (m.size() == m_dimX && "ContinuousTask::G(m,D,t) : corrupt dim of m");
    return funcG (m, D, t);
}

Matrix ContinuousTask::K (const Vector &m, const Matrix &D, double t) const
{
    assert (m.size() == m_dimX && "ContinuousTask::K(m,D,t) : corrupt dim of m");
    assert (D.rows() == m_dimX && "ContinuousTask::K(m,D,t) : corrupt dim of D (count of rows)");
    assert (D.cols() == m_dimX && "ContinuousTask::K(m,D,t) : corrupt dim of D (count of cols)");
    return (D * funcG(m,D,t).transpose() + funcS(m,D,t)) * LinAlg::PseudoInverseSVD (funcR(m,D,t));
}

Matrix ContinuousTask::Psy (const Vector &m, const Matrix &D, double t) const
{
    assert (m.size() == m_dimX && "ContinuousTask::Psy(m,D,t) : corrupt dim of m");
    assert (D.rows() == m_dimX && "ContinuousTask::Psy(m,D,t) : corrupt dim of D (count of rows)");
    assert (D.cols() == m_dimX && "ContinuousTask::Psy(m,D,t) : corrupt dim of D (count of cols)");
    Matrix k = K (m, D, t);
    Matrix a = funcAA (m, D, t);
    return a * D + D * a.transpose() + funcQ (m, D, t) - k * funcR (m, D, t) * k.transpose();
}


}  // end Tasks::Continuous

}  // end Tasks
