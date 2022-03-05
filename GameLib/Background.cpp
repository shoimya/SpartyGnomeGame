/**
 * @file Background.cpp
 * @author Haoxiang Zhang
 */

#include "pch.h"
#include "Background.h"

using namespace std;

const wstring filename1 = L"";
const wstring filename2 = L"";
const wstring filename3 = L"";

Background::Background(Stadium* stadium, Picture* picture)
        :Item(stadium, picture)
{

}

Background::~Background()
{

}

void Background::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    if(mPicture->GetImage() ==nullptr)
    {
        mPicture->SetImage(filename1);
    }

    int wid = mPicture->GetWidth();
    int hit = mPicture->GetHeight();

    graphics->DrawBitmap(mPicture->AsBitmap(graphics),
            (int)GetX() - wid / 2 , (int)GetY() - hit / 2,
            wid + 1, hit);

}
