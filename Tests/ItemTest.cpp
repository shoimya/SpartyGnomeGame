/**
 * @file ItemTest.cpp
 * @author Haoxiang Zhang
 */


#include <pch.h>
#include "gtest/gtest.h"

#include <Item.h>
#include <Stadium.h>
#include <Picture.h>

using namespace std;

class ItemMock : public Item
{
public:
    ItemMock(Stadium *stadium, std::shared_ptr<Picture> picture) : Item(stadium, picture)
    {

    }

    ItemMock() = delete;

    ItemMock(const ItemMock &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override {}

    void Accept(Visitor* visitor) override {}


};

TEST(ItemTest, constructor)
{
    Stadium *stadium;
    auto pic = make_shared<Picture>(stadium);
    ItemMock(stadium,pic);
}
TEST(ItemTest, SetLocation)
{
    Stadium *stadium;
    auto pic = make_shared<Picture>(stadium);
    ItemMock item(stadium,pic);
    ASSERT_EQ(0,item.GetX());
    ASSERT_EQ(0,item.GetY());

    item.SetLocation(10,20);
    ASSERT_EQ(10,item.GetX());
    ASSERT_EQ(20,item.GetY());
}

