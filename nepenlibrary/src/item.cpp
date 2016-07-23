#include "item.hpp"

Item::Item() : m_Id()
{
    boost::uuids::random_generator gen;
    m_Id = gen();
}

Item::Item(std::string const & Caption) : Item()
{
    m_Caption = Caption;
}

opt::optional<ItemId> Item::GetId() const
{
    return m_Id;
}

std::string Item::GetCaption() const
{
    return m_Caption;
}