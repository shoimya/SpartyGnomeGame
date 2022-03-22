/**
 * @file Stanley.cpp
 * @author Connor Sarah Swann
 */

#include "pch.h"
#include "Stanley.h"
#include "Stadium.h"

using namespace std;

Stanley::Stanley(Stadium* stadium, std::shared_ptr<Picture> picture)
        :Item(stadium, picture)
{

}

void Stanley::Draw(std::shared_ptr<wxGraphicsContext> graphics)
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
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_BOLD);
        graphics->SetFont(font, wxColour(0, 150, 0)); // green
        graphics->DrawText("Tuition Increase!" ,GetX(),GetY());  // Text to draw
    }
}

Stanley::~Stanley()
{

}

bool Stanley::CollisionTest(Item* item)
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

    //SetStatus(true);
    GetStadium()->TuitionUp();
    mHit = true;
    return true;
}

void Stanley::Update(double elapsed)
{
    if (mHit)
    {

        mStopWatch.Start();
        auto mCurrentTime = elapsed - mStopWatch.Time();
        SetLocation(GetX(),
                GetY() + mMoneySpeed * elapsed);

        // Delete money after 5 sec
        if (mCurrentTime >= 5){
            SetStatus(true);
        }

    }

}
