#ifndef SPECIFICPARAMETERS_H
#define SPECIFICPARAMETERS_H

#include <string>
#include "Core/array.h"


namespace Tasks
{


class SpecificParameters
{

public:

    SpecificParameters()
    {
    }

    void setValue (size_t index, double new_value);
    void setValue (const std::string &name, double new_value);
    void add (const std::string &name, double value);

    double value (size_t index) const;
    const std::string &name (size_t index) const;

    size_t size() const
    {
        return m_data.size();
    }


private:

    struct SPData
    {
        double value;
        std::string name;
    };

    Array< SPData > m_data;
};


}  // end Tasks


#endif  // SPECIFICPARAMETERS_H
