/**
 * @file Money.cpp
 * @author Haoxiang Zhang
 */

#include "pch.h"
#include "Money.h"
using namespace std;

const wstring filename1 = L"money100.png";
const wstring filename2 = L"money1000.png";

Money::Money(Stadium* stadium, std::shared_ptr<Picture> picture)
        :Item(stadium, picture)
{

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
    double hit, wid = 0.0;
    node->GetAttribute(L"x", L"0").ToLong(&x);
    node->GetAttribute(L"y", L"0").ToLong(&y);
    node->GetAttribute(L"width").ToDouble(&wid);
    node->GetAttribute(L"height").ToDouble(&hit);
    SetWidth(wid);
    SetHeight(hit);
    SetLocation(x,y);
}

bool Money::CollisionTest(Item* item)
{
    double dx = item->GetX() - GetX();
    double dy = item->GetY() - GetY();
    double D = sqrt(GetX()*GetX() + GetY()*GetY());
    double distance = sqrt(dx * dx + dy * dy);
    if (distance <= D)
    {
        return true;
    }

    return false;
}