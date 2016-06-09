#pragma once

#include <string>
#include <vector>
#include <experimental/optional>

#include "board.hpp"

namespace opt = std::experimental;

using BoardCount = unsigned int;
using BoardId = unsigned int;

class Nepen
{
public:
    BoardCount BoardCount()
    {
        return m_Boards.size();
    }

    opt::optional<BoardId> AddBoard(const std::string& Caption)
    {
        m_Boards.push_back(Board(++m_BoardIdCounter, Caption));

        return m_BoardIdCounter;
    }

    opt::optional<const Board> GetBoard(BoardId Id)
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


private:
    std::vector<Board> m_Boards;

    unsigned int m_BoardIdCounter = 0;
};