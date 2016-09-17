#include "nepen.hpp"

ItemCount Nepen::ItemCount()
{
    return m_Items.size();
}

opt::optional<ItemId> Nepen::AddItem(const std::string& Caption)
{
    Item    item(Caption);
    auto item_id = item.GetId();
    m_Items.push_back(item);

    TellEveryoneIChanged();

    return item_id;
}

opt::optional<const Item> Nepen::GetItem(ItemId Id)
{
    for(auto& Item : m_Items)
    {
        if(Id == Item.GetId())
        {
            return Item;
        }
    }
    return opt::nullopt;
}

void Nepen::Reset()
{
    m_Items.clear();

    TellEveryoneIChanged();
}

std::vector<ItemId> Nepen::GetItemIds()
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
void Nepen::AddVisitor(gsl::not_null<Subject*> sub)
{
    m_subs.push_back(sub);
}
void Nepen::TellEveryoneIChanged()
{
    for(auto& subj : m_subs)
    {
        subj->ModellUpdated();
    }
}