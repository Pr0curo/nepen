#include <gtest/gtest.h>

#include "board.hpp"
#include "pile.hpp"


TEST(BoardTests, CreateEmpty)
{
    Board b;
    EXPECT_EQ(0u, b.NumberOfPiles());

}

TEST(BoardTests, FillBoard)
{
    Board b;
    auto t = b.AddPile("Caption");

    EXPECT_TRUE(t);

    EXPECT_EQ(1u, b.NumberOfPiles());
}

TEST(BoardTests, GetPile)
{
    Board b;
    auto oPileId = b.AddPile("Sowas");
    EXPECT_TRUE(oPileId);

    auto pile = b.GetPile(*oPileId);

    EXPECT_TRUE((*pile).GetId() != 0);
}

TEST(BoardTests, GetPilesCaption)
{
    Board b;
    auto pileId = b.AddPile("Sowas");
    EXPECT_TRUE(pileId);

    auto pile = b.GetPile(*pileId);

    EXPECT_EQ(std::string("Sowas"), (*pile).GetCaption());
}