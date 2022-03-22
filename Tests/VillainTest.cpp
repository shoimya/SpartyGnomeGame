/**
 * @file VillainTest.cpp
 * @author Connor Fischetti
 */
#include <pch.h>
#include "gtest/gtest.h"
#include <Stadium.h>
#include <Gnome.h>
#include <Picture.h>
#include <Villain.h>
#include <string>
#include <streambuf>
#include <wx/filename.h>

using namespace std;

class VillainTest : public Villain{
protected:

};

TEST(VillainTest, Update)
{
    Stadium stadium = Stadium();
    wstring file = L"UofM.png";
    shared_ptr<Picture> picture = make_shared<Picture>(&stadium);
    picture->SetImage(file);

    Villain villain = Villain(&stadium, picture);

    /// villain moving up at -240 pixels/second
    ASSERT_EQ(villain.GetVelocity(),-240);
    double Y = villain.GetY();
    for (int i=1; i<13; i++)
    {
        villain.Update(0.1);
        ASSERT_EQ(villain.GetVelocity(),-240);
        ASSERT_EQ(villain.GetY(), Y + (villain.GetVelocity() * 0.1));
        Y += villain.GetVelocity() * 0.1;
    }
}

TEST(VillainTest, CollisionTest)
{
    Stadium stadium = Stadium();

    wstring file = L"gnome.png";
    shared_ptr<Picture> picture = make_shared<Picture>(&stadium);
    picture->SetImage(file);
    Gnome* gnome =  new Gnome(&stadium, picture);

    gnome->SetLocation(200,0);

    file = L"UofM.png";
    picture = make_shared<Picture>(&stadium);
    picture->SetImage(file);

    Villain villain = Villain(&stadium, picture);

    ASSERT_EQ(villain.CollisionTest(gnome), false);
    ASSERT_EQ(villain.GetX(), 0);
    ASSERT_EQ(gnome->GetX(), 200);

    gnome->SetLocation(0,0);
    ASSERT_EQ(villain.GetX(), 0);
    ASSERT_EQ(gnome->GetX(), 0);
    ASSERT_EQ(villain.CollisionTest(gnome), true);
    ASSERT_EQ(*(stadium.GetGameMode()), 3);
}