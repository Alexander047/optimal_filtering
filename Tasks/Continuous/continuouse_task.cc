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

Matrix ContinuousTask::A (const Vector &x, double t) const
{
    assert (x.size() == m_dimX && "ContinuousTask::A(x,t) : corrupt dim of x");
    return funcAA (x, t);
}

Matrix ContinuousTask::G (const Vector &x, double t) const
{
    assert (x.size() == m_dimX && "ContinuousTask::G(x,t) : corrupt dim of x");
    return funcG (x, t);
}

Matrix ContinuousTask::K (const Vector &x, const Matrix &D, double t) const
{
    assert (x.size() == m_dimX && "ContinuousTask::K(x,D,t) : corrupt dim of x");
    assert (D.rows() == m_dimX && "ContinuousTask::K(x,D,t) : corrupt dim of D (count of rows)");
    assert (D.cols() == m_dimX && "ContinuousTask::K(x,D,t) : corrupt dim of D (count of cols)");
    Matrix d = funcD (x, t);
    return D * funcG(x,t).transpose() * LinAlg::PseudoInverseSVD (d * d.transpose());
}

Matrix ContinuousTask::Psy (const Vector &x, const Matrix &D, double t) const
{
    assert (x.size() == m_dimX && "ContinuousTask::Psy(x,D,t) : corrupt dim of x");
    assert (D.rows() == m_dimX && "ContinuousTask::Psy(x,D,t) : corrupt dim of D (count of rows)");
    assert (D.cols() == m_dimX && "ContinuousTask::Psy(x,D,t) : corrupt dim of D (count of cols)");
    Matrix k = K (x, D, t);
    Matrix a = funcAA (x, t);
    Matrix b = funcB (x, t);
    Matrix d = funcD (x, t);
    return a * D + D * a.transpose() + b * b.transpose() - k * d * d.transpose() * k.transpose();
}


}  // end Tasks::Continuous

}  // end Tasks
