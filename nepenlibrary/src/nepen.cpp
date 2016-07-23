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