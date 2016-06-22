#include "nepen_form.hpp"

NepenForm::NepenForm()
{
    this->caption("NepenForm");

    m_Place.div("<lb>");

    m_Place["lb"] << m_Todos;

    m_Place.collocate();
}