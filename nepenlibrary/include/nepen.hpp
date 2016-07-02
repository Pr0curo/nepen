#pragma once

#include <string>
#include <vector>
#include <memory>
#include <experimental/optional>

#include "board.hpp"
#include "subject.hpp"

#include "gsl.h"

namespace opt = std::experimental;

using BoardCount = unsigned int;
using BoardId = unsigned int;

class Nepen
{
public:
    BoardCount BoardCount();
    opt::optional<BoardId> AddBoard(const std::string& Caption);
    opt::optional<const Board> GetBoard(BoardId Id);
    std::vector<BoardId> GetBoardIds()
    {
        std::vector<BoardId> BoardIds;

        for(auto& Board : m_Boards)
        {
            BoardIds.push_back(Board.GetId());
        }

        return BoardIds;
    }

    void Reset();

    void AddVisitor(gsl::not_null<Subject*> sub)
    {
        m_subs.push_back(sub);
    }

    void TellEveryoneIChanged()
    {
        for(auto& subj : m_subs)
        {
            subj->ModellUpdated();
        }
    }

private:
    std::vector<Board> m_Boards;

    unsigned int m_BoardIdCounter = 0;

    std::vector<Subject*> m_subs;
};