#ifndef ARRAY_H
#define ARRAY_H

#include <cstdlib>
#include <memory>
#include <type_traits>

#include "core_base.h"


template < typename Type >
class Array
{

public:

    Array() : m_data (nullptr), m_size (0)
    { /*...*/
    }

    Array (size_t n, const Type &value = Type())
    {
        allocate (n);
        fillWith (value);
    }

    Array (size_t n, const Type *p)
    {
        allocate (n);
        copyFrom (p);
    }

    Array (const Array &x)
    {
        allocate (x.m_size);
        copyFrom (x.m_data);
    }

    virtual ~Array()
    {
        deallocate();
    }


    Array &operator= (const Array &x)
    {
        if (this != &x) {
            if (m_size != x.m_size) {
                deallocate();
                m_size = x.m_size;
                m_data = nullptr;
                allocate (x.m_size);
            }
            copyFrom (x.m_data);
        }
        return *this;
    }


    const Type &operator[] (size_t n) const
    {
        assert (n < m_size);
        return m_data[n];
    }

    Type &operator[] (size_t n)
    {
        assert (n < m_size);
        return m_data[n];
    }

    void swap (size_t i, size_t j)
    {
        if (m_size < 2) {
            return;
        }

        assert (i < m_size);
        assert (j < m_size);

        Type tmp  = m_data[i];
        m_data[i] = m_data[j];
        m_data[j] = tmp;
    }

    Type first() const
    {
        return m_data[0];
    }

    Type last() const
    {
        return m_data[m_size - 1];
    }


    size_t size() const
    {
        return m_size;
    }

    void resize (size_t n, Type x = Type())
    {
        if (m_size == n) {
            return;
        }

        deallocate();
        allocate (n);
        fillWith (x);
    }

    void reset (size_t n, Type x = Type())
    {
        if (m_size == n) {
            return;
        }
        if (m_size == 0) {
            resize (n, x);
            return;
        }

        Type *tmp = new Type[n];
        size_t K = (n < m_size ? n : m_size);
        for (size_t i = 0; i < K; i++) {
            tmp[i] = m_data[i];
        }
        for (size_t i = K; i < n; ++i) {
            tmp[i] = x;
        }
        m_data = tmp;
        m_size = n;
    }


    // WARNING сработают только с типами, для которых определены <,<=, >, >= !!!
    Type minElement() const
    {
        if (m_size == 0) {
            return 0;  // WARNING
        }

        Type min = m_data[0];
        for (size_t i = 1; i < m_size; ++i) {
            if (min > m_data[i]) {
                min = m_data[i];
            }
        }
        return min;
    }

    Type maxElement() const
    {
        if (m_size == 0) {
            return 0;  // WARNING
        }

        Type max = m_data[0];
        for (size_t i = 1; i < m_size; ++i) {
            if (max < m_data[i]) {
                max = m_data[i];
            }
        }
        return max;
    }


protected:

    void allocate (size_t n)
    {
        if (n != 0) {
            m_data = new Type[n];
            m_size = n;
        }
        else {
            m_data = nullptr;
            m_size = 0;
        }
    }

    void deallocate()
    {
        if (m_data) {
            delete[] m_data;
            m_data = nullptr;
        }
        m_size = 0;
    }

    void fillWith (const Type &value = Type())
    {
        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] = value;
        }
    }

    void copyFrom (Type *const p)
    {
        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] = p[i];
        }
    }


private:

    Type  *m_data;
    size_t m_size;
};


//---- бинарные логические операции между массивами : ------------------------//

template < typename Type >
bool operator== (const Array< Type > &x, const Array< Type > &y)
{
    if (x.size() != y.size()) {
        return false;
    }

    for (size_t i = 0; i < x.size(); ++i) {
        if (x[i] != y[i]) {
            return false;
        }
    }

    return true;
}

template < typename Type >
bool operator!= (const Array< Type > &x, const Array< Type > &y)
{
    return !(x == y);
}


#endif  // ARRAY_H
