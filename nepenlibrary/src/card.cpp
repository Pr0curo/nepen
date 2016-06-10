#include "card.hpp"

Card::Card()
{
    // empty
}

Card::Card(CardId Id, std::string const & Caption) : m_Id(Id), m_Caption(Caption)
{

}

    opt::optional<CardId> Card::GetId() const
    {
        if(m_Id != 0)
        {
            return m_Id;
        }

        return opt::nullopt;
    }

    std::string Card::GetCaption() const
    {
        return m_Caption;
    }