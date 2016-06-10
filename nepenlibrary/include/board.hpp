#pragma once

#include <string>
#include <vector>
#include <experimental/optional>

#include "pile.hpp"

using BoardId = unsigned int;
using PileIdCounter =  unsigned int;

namespace opt = std::experimental;

class Board
{

public:
    Board(){};
    Board(BoardId Id, const std::string& Caption);

    unsigned int NumberOfPiles();
    opt::optional<PileId> AddPile(const std::string& Caption);
    opt::optional<const Pile> GetPile(PileId Id);
    std::string GetCaption() const;
    BoardId GetId() const;

private:
    BoardId m_Id;
    std::string m_Caption;

    std::vector<Pile> m_Piles;

    PileIdCounter m_PileIdCounter = 0;

};

//TODO: Zeit beim erstellen des Boards speichern