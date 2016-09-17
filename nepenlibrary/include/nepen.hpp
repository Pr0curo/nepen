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

//-------------------------------------------------------------------------------------------------
// Nepen ist das Modell, über eine Nepen-Objekt erfolgt der Zugang auf die Daten
//
// Wo möglich wird zur Rückgabe "std::optional" verwendet
//-------------------------------------------------------------------------------------------------
class Nepen
{
public:
    ItemCount ItemCount();
    opt::optional<ItemId> AddItem(const std::string& Caption);
    opt::optional<const Item> GetItem(ItemId Id);
    std::vector<ItemId> GetItemIds();

    void Reset();

    void AddVisitor(gsl::not_null<Subject*> sub);

    void TellEveryoneIChanged();

private:
    std::vector<Item> m_Items;

    unsigned int m_ItemIdCounter = 0;

    std::vector<Subject*> m_subs;
};