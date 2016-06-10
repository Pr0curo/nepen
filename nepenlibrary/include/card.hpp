#pragma once

#include <string>
#include <experimental/optional>
#include <boost/uuid/uuid_generators.hpp>

namespace opt = std::experimental;

#include <boost/uuid/uuid.hpp>

using CardId = boost::uuids::uuid;

class Card
{
public:
    Card();
    Card(std::string const & Caption);

    opt::optional<CardId> GetId() const;
    std::string GetCaption() const;

private:
    CardId  m_Id;
    std::string m_Caption = std::string("");
};