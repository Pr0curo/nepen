#pragma once

#include <string>
#include <experimental/optional>

namespace opt = std::experimental;

using CardId = unsigned int;

class Card
{
public:
    Card();
    Card(CardId Id, std::string const & Caption);

    opt::optional<CardId> GetId() const;
    std::string GetCaption() const;

private:
    CardId  m_Id = 0;
    std::string m_Caption = std::string("");
};