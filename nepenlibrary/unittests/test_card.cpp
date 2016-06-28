#include <gtest/gtest.h>

#include "nepen.hpp"

TEST(CardTests, CreateEmpty)
{
    Card card;
    EXPECT_TRUE(card.GetId());
}

TEST(CardTests, CreateFilled)
{
    Card card("Sowas");
    EXPECT_TRUE(card.GetId());
    EXPECT_EQ(std::string("Sowas"), card.GetCaption());
}

