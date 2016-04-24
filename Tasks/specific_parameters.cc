#include "specific_parameters.h"


namespace Tasks
{


void SpecificParameters::setValue (size_t index, double new_value)
{
    if (index < m_data.size()) {
        m_data[index].value = new_value;
    }
}

void SpecificParameters::setValue (const std::string &name, double new_value)
{
    size_t index = 100500;
    for (size_t i = 0; i < m_data.size(); ++i) {
        if (m_data[i].name == name) {
            index = i;
            i     = 100500;
        }
    }
    assert (index <= m_data.size());
    this->setValue (index, new_value);
}

void SpecificParameters::add (const std::string &name, double value)
{
    if (m_data.size() > 0) {
        for (size_t i = 0; i < m_data.size(); ++i) {
            if (m_data[i].name == name) {
                return;
            }
        }
    }

    m_data.reset (m_data.size() + 1);
    m_data[m_data.size() - 1].name = name;
    m_data[m_data.size() - 1].value = value;
}

double SpecificParameters::value (size_t index) const
{
    assert (index < m_data.size());
    return m_data[index].value;
}

const std::string &SpecificParameters::name (size_t index) const
{
    assert (index < m_data.size());
    return m_data[index].name;
}


}  // end Tasks
