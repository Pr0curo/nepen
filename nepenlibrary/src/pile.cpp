#include "pile.hpp"


Pile::Pile(PileId Id, const std::string& Caption) : m_Id(Id), m_Caption(Caption)
{ // empty on purpose
}

PileId Pile::GetId() const
{
    return m_Id;
}