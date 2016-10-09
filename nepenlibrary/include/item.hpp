#pragma once

#include <string>
#include <experimental/optional>
#include <boost/uuid/uuid_generators.hpp>

namespace opt = std::experimental;

#include <boost/uuid/uuid.hpp>

using ItemId = boost::uuids::uuid;

#include <chrono>
#include "../date/date.h"


//-------------------------------------------------------------------------------------------------
// Item ist die kleinste Informationseinheit
// es hat eine eigene UUID zur eindeutigen Identifikation
//-------------------------------------------------------------------------------------------------
class Item
{
public:
    Item();
    Item(std::string const & Caption);

    bool operator == (const Item& item);

    opt::optional<ItemId> GetId() const;
    std::string GetCaption() const;

    void AddData(std::string const& data);

    void AddDoneDate()
    {
        using namespace date;

        auto datum = date::year{2016};
    }

private:
    ItemId  m_Id;
    std::string m_Caption = std::string("");
    std::string m_Data = std::string("");
};