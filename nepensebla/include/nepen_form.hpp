#pragma once

#include <nana/gui.hpp>

#include <nana/gui/widgets/listbox.hpp>

class NepenForm : public nana::form
{
public:
    NepenForm();
private:
    nana::place m_Place{*this};
    nana::listbox m_Todos{*this};
};