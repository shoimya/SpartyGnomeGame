/**
 * @file Money.cpp
 * @author Haoxiang Zhang
 */

#include "pch.h"
#include "Money.h"
using namespace std;

const wstring filename1 = L"money100.png";
const wstring filename2 = L"money1000.png";

Money::Money(Stadium* stadium, std::shared_ptr<Picture> picture, int value)
        :Item(stadium, picture)
{
    SetValue(value);
}

void Money::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    if(!GetPicture()->Empty()) {
        int wid = GetPicture()->GetWidth();
        int hit = GetPicture()->GetHeight();
        graphics->DrawBitmap(GetPicture()->AsBitmap(graphics),
                (int) GetX()-wid/2 , (int) GetY()-hit/2 ,
                wid+1, hit );
    }
}

Money::~Money()
{

}

void Money::XmlLoad(wxXmlNode* node)
{
    long x, y = 0;
    node->GetAttribute(L"x", L"0").ToLong(&x);
    node->GetAttribute(L"y", L"0").ToLong(&y);
    SetLocation(x,y);
}

bool Money::CollisionTest(Item* item)
{
    // Border for the item
    auto itemLeft = item->GetX() - 32 / 2;
    auto itemRight = item->GetX() + 32 / 2;
    auto itemTop = item->GetY() - 32 / 2;
    auto itemBottom = item->GetY() + 32 / 2;

    // For us
    //
    auto Left = GetX() - 32 / 2;
    auto Right = GetX() + 32 / 2;
    auto Top = GetY() - 32 / 2;
    auto Bottom = GetY() + 32 / 2;

    // Test for all of the non-collision cases,
    // cases where there is a gap between the two items
    if ( Right < itemLeft ||  // Completely to the left
         Left > itemRight ||  // Completely to the right
         Top > itemBottom ||  // Completely below
         Bottom < itemTop)
    {
        return false;
    }

    SetStatus(true);
    return true;
}

