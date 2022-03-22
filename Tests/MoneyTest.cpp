/**
 * @file MoneyTest.cpp
 * @author Shoimya Chowdhury
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
#include <Money.h>

using namespace std;

class MoneyTest : public Money{
protected:

};

TEST(MoneyTest, Getters)
{
    Stadium stadium = Stadium();
    wstring file = L"Money100.png";
    shared_ptr<Picture> picture = make_shared<Picture>(&stadium);
    picture->SetImage(file);

    /// testing getters
    Money money = Money(&stadium, picture,100);
    ASSERT_EQ(money.GetValue(),100);
    money.SetValue(1000);
    ASSERT_EQ(money.GetValue(),1000);
}

//TEST(MoneyTest, Update)
//{
//    Stadium stadium = Stadium();
//    wstring file = L"Money100.png";
//    shared_ptr<Picture> picture = make_shared<Picture>(&stadium);
//    picture->SetImage(file);
//
//    /// testing getters
//    Money money = Money(&stadium, picture,100);
//    ASSERT_EQ(money.GetValue(),100);
//    money.SetValue(1000);
//    ASSERT_EQ(money.GetValue(),1000);
//}