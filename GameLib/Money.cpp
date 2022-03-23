/**
 * @file Money.cpp
 * @author Haoxiang Zhang Sarah Swann
 */
#include "pch.h"
#include <string>
#include "Money.h"
#include "Stadium.h"
using namespace std;

/// filename for 1st money option
const wstring filename1 = L"money100.png";
/// filename for 2nd money option
const wstring filename2 = L"money1000.png";

Money::Money(Stadium* stadium, std::shared_ptr<Picture> picture, int value)
        :Item(stadium, picture)
{
    SetValue(value);
    mInitValue = value;
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
    if(mHit) // add time till money leaves
    {
        wxFont font(wxSize(20, 30),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_MEDIUM);

        graphics->SetFont(font, wxColour(0, 128, 0)); // green
        graphics->DrawText("$" + to_string(mInitValue) ,GetX(),GetY());  // Text to draw
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
    auto itemLeft = item->GetX() - (double)item->GetWidth() / 2;
    auto itemRight = item->GetX() + (double)item->GetWidth() / 2;
    auto itemTop = item->GetY() - (double)item->GetHeight() / 2;
    auto itemBottom = item->GetY() + (double)item->GetHeight() / 2;

    // For us
    auto ourLeft = GetX() - (double)GetWidth() / 2;
    auto ourRight = GetX() + (double)GetWidth() / 2;
    auto ourTop = GetY() - (double)GetHeight() / 2;
    auto ourBottom = GetY() + (double)GetHeight() / 2;

    // Test for all of the non-collision cases,
    // cases where there is a gap between the two items
    if (ourRight < itemLeft ||  // Completely to the left
            ourLeft > itemRight ||  // Completely to the right
            ourTop > itemBottom ||  // Completely below
            ourBottom < itemTop)    // Completely above
    {
        return false;
    }

    GetStadium()->AddScore(GetValue());
    SetStatus(true);
    SetValue(0);
    mHit = true;
    return true;
}

void Money::Update(double elapsed)
{
    if (mHit)
    {

        mStopWatch.Start();
        SetLocation(GetX(),
                GetY() - mMoneySpeed * elapsed);


    }

}

