/**
 * @file GnomeTest.cpp
 * @author CK
 */

#include <pch.h>
#include "gtest/gtest.h"
#include "GnomeTest.h"
#include <Stadium.h>
#include <Gnome.h>
#include <Picture.h>
using namespace std;

TEST(GnomeTest, Update)
{
    Stadium stadium = Stadium();
    wstring file = L"gnome.png";
    shared_ptr<Picture> picture = make_shared<Picture>(&stadium);
    picture->SetImage(file);

    Gnome gnome = Gnome(&stadium, picture);

    gnome.MovingUp();
    ASSERT_EQ(gnome.GetVelocity().Y(),-800);
    double Y = gnome.GetY();
    for (int i=1; i<9; i++)
    {
        gnome.Update(0.1);
        ASSERT_EQ(gnome.GetVelocity().Y(),-800 + (i*100));
        ASSERT_EQ(gnome.GetY(), Y + (gnome.GetVelocity().Y() * 0.1));
        Y += gnome.GetVelocity().Y() * 0.1;
    }


    gnome.MovingRight();
    ASSERT_EQ(gnome.GetVelocity().X(), 500);
    double X = gnome.GetX();
    for (int i = 1; i < 9; i++)
    {
        gnome.Update(0.1);
        ASSERT_EQ(gnome.GetVelocity().X(), 500);
        ASSERT_EQ(gnome.GetX(), X + gnome.GetVelocity().X() * 0.1);
        X += gnome.GetVelocity().X() * 0.1;
    }

    gnome.MovingLeft();
    ASSERT_EQ(gnome.GetVelocity().X(), -500);
    for (int i = 1; i < 9; i++)
    {
        gnome.Update(0.1);
        ASSERT_EQ(gnome.GetVelocity().X(), -500);
        ASSERT_EQ(gnome.GetX(), X + gnome.GetVelocity().X() * 0.1);
        X += gnome.GetVelocity().X() * 0.1;
    }

    gnome.ResetX();
    ASSERT_EQ(gnome.GetVelocity().X(), 0);
}

