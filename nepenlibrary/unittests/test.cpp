#include <gtest/gtest.h>

#include "board.hpp"
#include "pile.hpp"


TEST(BoardTests, CreateEmpty)
{
    Board b;
    EXPECT_EQ(static_cast<unsigned int>(0), b.NumberOfPiles());

}

TEST(BoardTests, FillBoard)
{
    Board b;
    auto t = b.AddPile("Caption");

    EXPECT_TRUE(t);

    EXPECT_EQ(static_cast<unsigned int>(1), b.NumberOfPiles());

}

TEST(BoardTests, GetPile)
{
    Board b;
    auto oPileId = b.AddPile("Sowas");
    EXPECT_TRUE(oPileId);

    auto pile = b.GetPile(*oPileId);

    EXPECT_TRUE((*pile).GetId() != 0);
}