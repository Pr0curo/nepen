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
        m_ItemId = *m_Nepen.AddItem("first Item");
    }
    void TearDown( )
    {
    }
    Nepen m_Nepen;

    ItemId m_ItemId;
};

TEST_F(NepenTestFixture, test1)
{
    EXPECT_EQ(1u, m_Nepen.ItemCount());
}

TEST(NepenTests, CreateEmpty)
{
    Nepen nep;
    EXPECT_EQ(0u, nep.ItemCount());
}

TEST(NepenTests, AddItem)
{
    Nepen nep;
    auto ItemId = nep.AddItem("ItemsCaption");

    EXPECT_TRUE(ItemId);

    EXPECT_EQ(1u, nep.ItemCount());
}

TEST(NepenTests, GetBoard)
{
    Nepen nep;
    auto ItemId = nep.AddItem("Items Caption");
    EXPECT_TRUE(ItemId);

    auto Item = nep.GetItem(*ItemId);
    EXPECT_TRUE(Item);
}

TEST(NepenTests, GetBoardsCaption)
{
    Nepen nep;
    auto ItemId = nep.AddItem("Items Caption");

    auto TestItem = nep.GetItem(*ItemId);

    EXPECT_TRUE(TestItem);

    EXPECT_EQ(std::string("Items Caption"), (*TestItem).GetCaption());
}

TEST(NepenTests, Reset)
{
    Nepen nep;
    nep.AddItem("ItemsCaption");

    nep.Reset();

    EXPECT_EQ(0u, nep.ItemCount());
}