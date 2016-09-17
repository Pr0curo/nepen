#include "nepen_form.hpp"

#include <iostream>

NepenForm::NepenForm(std::unique_ptr<Nepen> && nepen) : m_Modell(std::move(nepen))
{
    m_Controller = std::make_unique<NepenController>(*this, *m_Modell);
    m_Modell->AddVisitor(this);

    this->caption("NepenForm");

    m_CreateNewProject.caption("new_project");
    m_CreateNewItem.caption("new_Item");


    m_CreateNewProject.events().click([&]()
    {
        m_Controller->NewProjectBtnClicked();
    });

    m_CreateNewItem.events().click([&]()
    {
        m_Controller->NewItemBtnClicked();
    });

    m_Place.div("<lb><vertical <new_nepen><new_Item><new_pile><new_card>> <DataView>");

    m_Place["lb"] << m_Todos;
    m_Place["new_nepen"] << m_CreateNewProject;
    m_Place["new_Item"] << m_CreateNewItem;
    m_Place["DataView"] << m_DataView;

    m_Place.collocate();

    m_Todos.append_header("Item");
}

