#include "nepen.hpp"

BoardCount Nepen::BoardCount()
{
    return m_Boards.size();
}

opt::optional<BoardId> Nepen::AddBoard(const std::string& Caption)
{
    m_Boards.push_back(Board(++m_BoardIdCounter, Caption));
    return m_BoardIdCounter;
}

opt::optional<const Board> Nepen::GetBoard(BoardId Id)
{
    for(auto& board : m_Boards)
    {
        if(Id == board.GetId())
        {
            return board;
        }
    }
    return opt::nullopt;
}

void Nepen::Reset()
{
    m_Boards.clear();

    TellEveryoneIChanged();
}