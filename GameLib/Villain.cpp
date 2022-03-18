/**
 * @file Villain.cpp
 * @author Connor
 */

#include "pch.h"
#include "Villain.h"
#include "Stadium.h"

using namespace std;

const wstring filename1 = L"UofM.png";
const wstring filename2 = L"wisc.png";

Villain::Villain(Stadium* stadium, std::shared_ptr<Picture> picture)
        :Item(stadium, picture)
{

}

void Villain::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    if(!GetPicture()->Empty()) {
        int wid = GetPicture()->GetWidth();
        int hit = GetPicture()->GetHeight();
        graphics->DrawBitmap(GetPicture()->AsBitmap(graphics),
                (int) GetX()-wid/2 , (int) GetY()-hit/2 ,
                wid+1, hit );
    }
}

Villain::~Villain()
{

}

void Villain::XmlLoad(wxXmlNode* node)
{
    double x, y = 0;
    node->GetAttribute(L"x", L"0").ToDouble(&x);
    node->GetAttribute(L"y", L"0").ToDouble(&y);
    SetLocation(x,y);
    this->SetInitialLocation(x,y);
}

/**
 * Handle updates in time/movement of our villain
 *
 * @param elapsed Time elapsed since the class call
 */
void Villain::Update(double elapsed)
{
    auto next = GetY()+(mSpeedY*elapsed);
    if (next<=mPosInit.Y() && next>=mPosInit.Y()-300) {
        SetLocation(mPosInit.X(), next);
    }
    else {
        mSpeedY = -mSpeedY;
    }
}

bool Villain::CollisionTest(Item* item)
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
            ourBottom < itemTop )    // Completely above
    {
        return false;
    }

    return true;

}

void Villain::Accept(Visitor* visitor)
{
    visitor->VisitVillain(this);
}
