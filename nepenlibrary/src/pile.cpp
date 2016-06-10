#include "pile.hpp"

Pile::Pile()
{

}

Pile::Pile(PileId Id, const std::string& Caption) : m_Id(Id), m_Caption(Caption)
{ // empty on purpose
}

PileId Pile::GetId() const
{
    return m_Id;
}

std::string Pile::GetCaption() const
{
    return m_Caption;
}

CardCount Pile::CardCount() const
{
    return m_Cards.size();
}

opt::optional<CardId> Pile::AddCard(std::string const& Caption)
{ // ✔ fixme id @done (June 10th 2016, 9:00)
    m_Cards.push_back(Card(++m_CardIdCounter, Caption));
    return m_CardIdCounter;
}

opt::optional<Card> Pile::GetCard(CardId Id) const
{
    for(auto card : m_Cards)
    {
        if( Id == card.GetId() )
        {
            return card;
        }
    }
    return opt::nullopt;
}