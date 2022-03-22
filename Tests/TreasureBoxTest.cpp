/**
 * @file TreasureBoxTest.cpp
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
#include <TreasureBox.h>

using namespace std;

class TreasureBoxTest : public TreasureBox{
protected:

};

TEST(TreasureBoxTest, Getters)
{
    Stadium stadium = Stadium();
    wstring file = L"chest5.png";
    shared_ptr<Picture> picture = make_shared<Picture>(&stadium);
    picture->SetImage(file);

    /// testing getters
    TreasureBox tb = TreasureBox(&stadium, picture,10000);
    tb.SetLocation(100,200);
    ASSERT_EQ(tb.GetX(),100);
    ASSERT_EQ(tb.GetY(),200);
    ASSERT_EQ(tb.GetValue(),10000);

}
