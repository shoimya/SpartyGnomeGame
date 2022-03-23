/**
 * @file TreasureBox.cpp
 * @author Sarah Swann SHOIMYA CHOWDHURY
 */

#include "pch.h"
#include "TreasureBox.h"
#include "Stadium.h"
using namespace std;

TreasureBox::~TreasureBox()
{

}

void TreasureBox::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    if(!GetPicture()->Empty()) {
        int wid = GetPicture()->GetWidth();
        int hit = GetPicture()->GetHeight();
        graphics->DrawBitmap(GetPicture()->AsBitmap(graphics),
                (int) GetX()-wid/2 , (int) GetY()-hit/2 ,
                wid+1, hit );
    }

    if(mHit == true)
    {
        wxFont font(wxSize(40, 50),
                wxFONTFAMILY_DECORATIVE,
                wxFONTSTYLE_ITALIC,
                wxFONTWEIGHT_BOLD);
        graphics->SetFont(font, wxColour(197,179,88)); // gold
        graphics->DrawText("$" + to_string(mValue) ,GetX(),GetY());  // Text to draw
    }
}

bool TreasureBox::CollisionTest(Item* item)
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

    SetStatus(true);
    GetStadium()->AddScore(GetValue());
    GetStadium()->TuitionUp();
    mHit = true;
    return true;
}

void TreasureBox::XmlLoad(wxXmlNode* node)
{
    long x, y = 0;
    node->GetAttribute(L"x", L"0").ToLong(&x);
    node->GetAttribute(L"y", L"0").ToLong(&y);
    SetLocation(x,y);
}

TreasureBox::TreasureBox(Stadium* stadium, std::shared_ptr<Picture> picture, int value)
        :Item(stadium, picture)
{
    SetValue(value);
}

void TreasureBox::Update(double elapsed)
{
    if (mHit)
    {

        mStopWatch.Start();
        auto mCurrentTime = elapsed - mStopWatch.Time();
        SetLocation(GetX(),
                GetY() - mMoneySpeed * elapsed);

        // Delete money after 5 sec
        if (mCurrentTime >= 5){
            SetStatus(true);
        }

    }

}