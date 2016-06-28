#include <gtest/gtest.h>

#include "nepen.hpp"

class NepenTestFixture : public ::testing::Test
{
public:
    NepenTestFixture()
    {
    }
    void SetUp( )
    {
        m_BoardId = *m_Nepen.AddBoard("firstBoard");
    }
    void TearDown( )
    {
    }
    Nepen m_Nepen;

    BoardId m_BoardId;
};

TEST_F(NepenTestFixture, test1)
{
    EXPECT_EQ(1u, m_Nepen.BoardCount());

    EXPECT_EQ(1u, m_BoardId);


}

TEST(NepenTests, DISABLE_CreateEmpty)
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

TEST(NepenTests, Reset)
{
    Nepen nep;
    nep.AddBoard("BoardsCaption");

    nep.Reset();

    EXPECT_EQ(0u, nep.BoardCount());
}