#include "nepen_controller.hpp"

#include "nepen_form.hpp"


// todo: wäre hier std::weak_ptr besser?
NepenController::NepenController(NepenForm& View, Nepen& Modell) :
    m_View(View), m_Modell(Modell)
{
    // empty
}

void NepenController::NewItemBtnClicked()
{
    //std::cout << "New Item Button Clicked!!!" << std::endl;
    //m_Modell.Reset();
    // bedingungen prüfen ob wir den klick weiter verfolgen wollen
    m_View.ShowNewItemDlg();
}
