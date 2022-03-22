/**
 * @file StanleyTest.cpp
 * @author Connor
 */

#include <pch.h>
#include "gtest/gtest.h"
#include "Money.h"
#include <Stadium.h>
#include <Gnome.h>
#include <Picture.h>
#include <Stanley.h>
#include <string>
#include <streambuf>
#include <wx/filename.h>

using namespace std;

class StanleyTest : public Stanley{
protected:

};

TEST(StanleyTest, SetLocation)
{
    Stadium *stadium;
    auto pic = make_shared<Picture>(stadium);
    Stanley stanley(stadium,pic);
    ASSERT_EQ(0,stanley.GetX());
    ASSERT_EQ(0,stanley.GetY());

    stanley.SetLocation(10,20);
    ASSERT_EQ(10,stanley.GetX());
    ASSERT_EQ(20,stanley.GetY());
}

TEST(StanleyTest, CollisionTest)
{
    Stadium stadium = Stadium();

    wstring file = L"gnome.png";
    shared_ptr<Picture> picture = make_shared<Picture>(&stadium);
    picture->SetImage(file);
    Gnome* gnome =  new Gnome(&stadium, picture);
    gnome->SetLocation(200,0);

    file = L"money100.png";
    picture = make_shared<Picture>(&stadium);
    picture->SetImage(file);
    Money money = Money(&stadium, picture, 100);

    stadium.AddItem(&money);

    file = L"stanley.png";
    picture = make_shared<Picture>(&stadium);
    picture->SetImage(file);
    Stanley stanley = Stanley(&stadium, picture);

    stadium.AddItem(&stanley);

    ASSERT_EQ(stanley.CollisionTest(gnome), false);
    ASSERT_EQ(stanley.GetX(), 0);
    ASSERT_EQ(gnome->GetX(), 200);

    gnome->SetLocation(0,0);
    ASSERT_EQ(stanley.GetX(), 0);
    ASSERT_EQ(gnome->GetX(), 0);
    ASSERT_EQ(stanley.CollisionTest(gnome), true);
    ASSERT_EQ(money.GetValue(), 110);
}