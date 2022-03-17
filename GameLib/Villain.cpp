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
//    auto collided = GetStadium() -> CollisionTest(this);
//    if(collided != GetStadium()->GetGnome())
//    {
    auto next = GetY()+(mSpeedY*elapsed);
    if (next<=mPosInit.Y() && next>=mPosInit.Y()-300) {
        SetLocation(mPosInit.X(), next);
    }
    else {
        mSpeedY = -mSpeedY;
    }
//    }
}