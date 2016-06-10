#include <gtest/gtest.h>

#include "nepen.hpp"

TEST(CardTests, CreateEmpty)
{
    Card card;
    EXPECT_FALSE(card.GetId());
}

TEST(CardTests, CreateFilled)
{
    Card card(23, "Sowas");
    EXPECT_TRUE(card.GetId());
    EXPECT_EQ(std::string("Sowas"), card.GetCaption());
}

