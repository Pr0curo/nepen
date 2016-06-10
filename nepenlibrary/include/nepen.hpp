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
    BoardCount BoardCount();
    opt::optional<BoardId> AddBoard(const std::string& Caption);
    opt::optional<const Board> GetBoard(BoardId Id);

private:
    std::vector<Board> m_Boards;

    unsigned int m_BoardIdCounter = 0;
};