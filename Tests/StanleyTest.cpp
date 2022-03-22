/**
 * @file StanleyTest.cpp
 * @author Shoimya Chowdhury
 */
#include <pch.h>
#include "gtest/gtest.h"
#include <Stadium.h>
#include <Picture.h>
#include <Villain.h>
#include <string>
#include <streambuf>
#include <wx/filename.h>
#include <Stanley.h>

using namespace std;

class StanleyTest : public Stanley{
protected:

};

TEST(StanleyTest, Getters)
{
    Stadium stadium = Stadium();
    wstring file = L"stanley.png";
    shared_ptr<Picture> picture = make_shared<Picture>(&stadium);
    picture->SetImage(file);

    /// testing getters
    Stanley stanley = Stanley(&stadium, picture);
    stanley.SetLocation(100,200);
    ASSERT_EQ(stanley.GetX(),100);
    ASSERT_EQ(stanley.GetY(),200);
}


