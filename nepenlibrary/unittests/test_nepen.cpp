#include <gtest/gtest.h>

#include "nepen.hpp"

TEST(NepenTests, CreateEmpty)
{
    Nepen nep;
    EXPECT_EQ(0u, nep.BoardCount());
}

TEST(NepenTests, AddBoard)
{
    Nepen nep;
    auto BoardId = nep.AddBoard("BoardsCaption");

    EXPECT_TRUE(BoardId);
    EXPECT_EQ(1u, *BoardId);

    EXPECT_EQ(1u, nep.BoardCount());
}

TEST(NepenTests, GetBoardsName)
{
    Nepen nep;
    auto BoardId = nep.AddBoard("BoardsCaption");

    EXPECT_TRUE(BoardId);

    auto TestBoard = nep.GetBoard(*BoardId);

    EXPECT_TRUE(TestBoard);

    EXPECT_EQ(std::string("BoardsCaption"), (*TestBoard).GetCaption());
}