#pragma once

#include <nana/gui.hpp>

#include <nana/gui/widgets/listbox.hpp>
#include <nana/gui/widgets/button.hpp>

#include "subject.hpp"
#include "nepen.hpp"
#include "nepen_controller.hpp"



class NepenForm : public nana::form, public Subject
{
public:
    // make ownershiptransfer und checken ob das notwendig ist
    NepenForm(std::unique_ptr<Nepen> && nepen);

    virtual void ModellUpdated() override
    {
        std::cout << "View was notified that Modell has changed State\n";

        m_Todos.clear();

        auto ItemIds = m_Modell->GetItemIds();

        auto cat = m_Todos.at(0);

        for(auto& ItemId : ItemIds)
        {
            auto optItem = m_Modell->GetItem(ItemId);
            if(optItem)
            {
                cat.append((*optItem).GetCaption());
            }
        }

    }

    void ShowNewItemDlg()
    {
        nana::inputbox::text Caption("<blue> Caption</>");

        nana::inputbox inbox(*this, "Test");

        if(inbox.show(Caption))
        {
            auto capt = Caption.value();
            m_Controller->RequestNewItem(capt);
        }
    }

private:
    nana::place     m_Place{*this};
    nana::listbox   m_Todos{*this};
    nana::button    m_CreateNewProject{*this};
    nana::button    m_CreateNewItem{*this};

    Nepen m_Nepen;

    std::unique_ptr<Nepen>              m_Modell;
    std::unique_ptr<NepenController>    m_Controller;
};