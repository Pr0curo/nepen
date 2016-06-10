#include <gtest/gtest.h>

#include "pile.hpp"

TEST(PileTests, CreateEmptyPile)
{
    Pile pile;
    EXPECT_EQ(0u, pile.CardCount());
}

TEST(PileTests, AddCard)
{
    Pile pile;
    auto CardId = pile.AddCard("CardsCaption");

    EXPECT_TRUE(CardId);
    EXPECT_EQ(1u, *CardId);

    EXPECT_EQ(1u, pile.CardCount());
}

TEST(PileTests, GetCard)
{
    Pile pile;
    auto CardId = pile.AddCard("CardsCaption");

    EXPECT_TRUE(CardId);

    auto card = pile.GetCard(*CardId);
    EXPECT_TRUE(card);
}

TEST(PileTests, GetCardsCaption)
{
    Pile pile;
    auto CardId = pile.AddCard("CardsCaption");

    EXPECT_TRUE(CardId);

    auto card = pile.GetCard(*CardId);
    EXPECT_EQ(std::string("CardsCaption"), (*card).GetCaption());
}