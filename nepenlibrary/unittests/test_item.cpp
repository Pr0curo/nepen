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

