#include <gtest/gtest.h>

#include "nepen.hpp"

TEST(ItemTests, CreateEmpty)
{
    Item item;
    EXPECT_TRUE(item.GetId());
}

TEST(ItemTests, CreateFilled)
{
    Item item("Sowas");
    EXPECT_TRUE(item.GetId());
    EXPECT_EQ(std::string("Sowas"), item.GetCaption());
}

TEST(ItemTests, Equal)
{
    Item item1("sowas");
    Item& ref_to_item1(item1);

    EXPECT_TRUE((item1 == ref_to_item1));

    Item item2("sowas");
    EXPECT_FALSE(item1 == item2);
}