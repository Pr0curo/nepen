#include "nepen_form.hpp"

#include <iostream>

NepenForm::NepenForm(std::unique_ptr<Nepen> && nepen) : m_Modell(std::move(nepen))
{
    m_Controller = std::make_unique<NepenController>(*this, *m_Modell);
    m_Modell->AddVisitor(this);

    this->caption("NepenForm");

    m_CreateNewProject.caption("new_project");
    m_CreateNewBoard.caption("new_board");
    m_CreateNewPile.caption("new_pile");
    m_CreateNewCard.caption("new_card");

    m_CreateNewProject.events().click([&]()
    {
        m_Controller->NewProjectBtnClicked();
    });

    m_CreateNewBoard.events().click([&]()
    {
        m_Controller->NewBoardBtnClicked();
    });

    m_CreateNewPile.events().click([](){std::cout << "new pile\n";});
    m_CreateNewCard.events().click([](){std::cout << "new card\n";});

    m_Place.div("<lb><vertical <new_nepen><new_board><new_pile><new_card> >");

    m_Place["lb"] << m_Todos;
    m_Place["new_nepen"] << m_CreateNewProject;
    m_Place["new_board"] << m_CreateNewBoard;
    m_Place["new_pile"] << m_CreateNewPile;
    m_Place["new_card"] << m_CreateNewCard;

    m_Place.collocate();

    m_Todos.append_header("Board");
}

