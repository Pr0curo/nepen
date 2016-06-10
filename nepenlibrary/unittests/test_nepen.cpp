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

TEST(NepenTests, GetBoard)
{
    Nepen nep;
    auto BoardId = nep.AddBoard("BoardsCaption");
    EXPECT_TRUE(BoardId);

    auto Board = nep.GetBoard(*BoardId);
    EXPECT_TRUE(Board);
}

TEST(NepenTests, GetBoardsCaption)
{
    Nepen nep;
    auto BoardId = nep.AddBoard("BoardsCaption");

    auto TestBoard = nep.GetBoard(*BoardId);

    EXPECT_TRUE(TestBoard);

    EXPECT_EQ(std::string("BoardsCaption"), (*TestBoard).GetCaption());
}