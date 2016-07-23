#pragma once

#include <string>
#include <vector>
#include <memory>
#include <experimental/optional>

#include "item.hpp"
#include "subject.hpp"

#include "gsl.h"

namespace opt = std::experimental;

using ItemCount = unsigned int;

class Nepen
{
public:
    ItemCount ItemCount();
    opt::optional<ItemId> AddItem(const std::string& Caption);
    opt::optional<const Item> GetItem(ItemId Id);
    std::vector<ItemId> GetItemIds()
    {
        std::vector<ItemId> ItemIds;

        for(auto& Item : m_Items)
        {
            auto id = Item.GetId();
            if(id)
            {
                ItemIds.push_back(*id);
            }
        }

        return ItemIds;
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
    std::vector<Item> m_Items;

    unsigned int m_ItemIdCounter = 0;

    std::vector<Subject*> m_subs;
};