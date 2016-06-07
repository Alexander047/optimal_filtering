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
    virtual ~Task();

    Task (const Task &)           = delete;
    Task &operator=(const Task &) = delete;

    const std::string &name() const;
    const std::string &approxType() const;
    SpecificParameters *parameters() const;

    long dimX() const;
    long dimY() const;
    long dimV() const;
    long dimW() const;

    const Vector &meanX() const;
    const Vector &meanV() const;
    const Vector &meanW() const;
    const Matrix &covX() const;
    const Matrix &covV() const;
    const Matrix &covW() const;

    Vector x0() const;

    void setMeanX (const Vector &m);
    void setMeanV (const Vector &m);
    void setMeanW (const Vector &m);
    void setCovX (const Matrix &D);
    void setCovV (const Matrix &D);
    void setCovW (const Matrix &D);


protected:

    std::string m_name;
    std::string m_approxType;
    SpecificParameters *m_params;

    long m_dimX;
    long m_dimY;
    long m_dimV;
    long m_dimW;

    Vector mx;
    Vector mv;  // V -- шум объекта
    Vector mw;  // W -- шум измерителя
    Matrix Dx;
    Matrix Dv;
    Matrix Dw;
};


}  // end Tasks


#endif  // TASK_H
