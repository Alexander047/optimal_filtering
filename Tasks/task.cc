#include "task.h"


namespace Tasks
{


Task::Task()
      : m_name (""),
        m_approxType (""),
        m_params (nullptr),
        mx (Vector::Zero (2)),
        my (Vector::Zero (2)),
        mv (Vector::Zero (2)),
        mw (Vector::Zero (2)),
        Dx (Matrix::Zero (2, 2)),
        Dy (Matrix::Zero (2, 2)),
        Dv (Matrix::Zero (2, 2)),
        Dw (Matrix::Zero (2, 2))
{ /*...*/
}


}  // end Tasks
