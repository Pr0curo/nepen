#pragma once

#include <string>
#include <vector>
#include <experimental/optional>

#include "Card.hpp"

using PileId = unsigned int;
using CardCount = unsigned int;
using CardIdCounter = unsigned int;

namespace opt = std::experimental;

class Pile
{

public:
    Pile();
    Pile(PileId Id, const std::string& Caption);

    PileId GetId() const;
    std::string GetCaption() const;
    CardCount CardCount() const;
    opt::optional<CardId> AddCard(std::string const& Caption);
    opt::optional<Card> GetCard(CardId Id) const;

private:
    PileId      m_Id;
    std::string m_Caption;

    std::vector<Card> m_Cards;

    CardIdCounter m_CardIdCounter = 0;
};

