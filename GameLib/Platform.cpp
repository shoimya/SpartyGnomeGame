/**
 * @file Platform.cpp
 * @author Haoxiang Zhang
 */

#include "pch.h"
#include "Platform.h"

Platform::Platform(Stadium* stadium, Picture* picture)
        :Item(stadium, picture)
{

}

bool Platform::CollisionTest(Item* item)
{

    // Border for the item
    return false;

}

void Platform::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    int wid = mPicture->GetWidth();
    int hit = mPicture->GetHeight();
    graphics->DrawBitmap(mPicture->AsBitmap(graphics),
            (int)GetX() - wid / 2, (int)GetY() - hit / 2,
            wid + 1, hit);

}

void Platform::Draw(std::shared_ptr<wxGraphicsContext> graphics, int scrollx)
{
    int wid = mPicture->GetWidth();
    int hit = mPicture->GetHeight();
    graphics->DrawBitmap(mPicture->AsBitmap(graphics),
            (int)GetX() - wid / 2 + scrollx, (int)GetY() - hit / 2,
            wid + 1, hit);

}
