#include "nepen_controller.hpp"

#include "nepen_form.hpp"


// todo: wäre hier std::weak_ptr besser?
NepenController::NepenController(NepenForm& View, Nepen& Modell) :
    m_View(View), m_Modell(Modell)
{
    // empty
}