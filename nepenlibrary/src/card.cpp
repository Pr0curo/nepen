#include "card.hpp"

Card::Card() : m_Id()
{
    boost::uuids::random_generator gen;
    m_Id = gen();
}

Card::Card(std::string const & Caption) : Card()
{
    m_Caption = Caption;
}

opt::optional<CardId> Card::GetId() const
{
    return m_Id;
}

std::string Card::GetCaption() const
{
    return m_Caption;
}