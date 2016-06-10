#include "board.hpp"

Board::Board(BoardId Id, const std::string& Caption) : m_Id(Id), m_Caption(Caption)
{   // empty on purpose
}

std::string Board::GetCaption() const
{
    return m_Caption;
}

BoardId Board::GetId() const
{
    return m_Id;
}

unsigned int Board::NumberOfPiles()
{
    return m_Piles.size();
}

opt::optional<PileId> Board::AddPile(const std::string& Caption)
{
    m_Piles.push_back(Pile(++m_PileIdCounter, Caption));

    return m_PileIdCounter;
}

opt::optional<const Pile> Board::GetPile(PileId Id)
{
    for(auto& pile : m_Piles)
    {
        if(Id == pile.GetId())
        {
            return pile;
        }
    }

    return opt::nullopt;
}