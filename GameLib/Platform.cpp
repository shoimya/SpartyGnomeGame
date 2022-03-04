/**
 * @file Platform.cpp
 * @author Haoxiang Zhang
 */

#include "pch.h"
#include "Platform.h"

using namespace std;

const wstring filename1 = L"platformIndustrial_057.png";
const wstring filename2 = L"platformIndustrial_059.png";
const wstring filename3 = L"platformIndustrial_060.png";
const wstring filename4 = L"platformIndustrial_061.png";

Platform::Platform(Stadium* stadium, Picture* picture)
        :ItemPlatform(stadium, picture)
{

}

Platform::~Platform()
{

}


/** void Platform::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    if(mPicture->GetImage() == nullptr)
    {
        mPicture->SetImage(filename1);
    }
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
*/
