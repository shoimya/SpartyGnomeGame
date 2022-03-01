/**
 * @file Door.cpp
 * @author Haoxiang Zhang
 */

#include "pch.h"
#include "Door.h"

using namespace std;
const double CollisionDistance = 20;
const wstring filename = L"/door.png";

Door::Door(Stadium* stadium, Picture* picture)
        :Item(stadium, picture)
{

}

bool Door::CollisionTest(Item* item)
{
    // Collision for door is different
    double dx = item->GetX() - GetX();
    double dy = item->GetY() - GetY();
    double distance = sqrt(dx * dx + dy * dy);
    if (distance < CollisionDistance)
    {
        return true;
    }

    return false;
}

void Door::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    if(mPicture->GetImage() ==nullptr)
    {
        mPicture->SetImage(filename);
    }

    int wid = mPicture->GetWidth();
    int hit = mPicture->GetHeight();
    graphics->DrawBitmap(mPicture->AsBitmap(graphics),
            (int)GetX() - wid / 2 , (int)GetY() - hit / 2,
            wid + 1, hit);
}

Door::~Door()
{

}

