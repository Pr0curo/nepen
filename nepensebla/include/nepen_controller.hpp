#pragma once

#include <memory>
#include <iostream>

#include "nepen.hpp"

class NepenForm;

class NepenController
{
public:
    NepenController(NepenForm& View, Nepen& Modell);

    void NewProjectBtnClicked()
    {
        std::cout << "New Project Button Clicked!!!" << std::endl;

        m_Modell.Reset();

    }

private:

    NepenForm&  m_View;
    Nepen&      m_Modell;
};