/**
 * @file TreasureBox.cpp
 * @author Sarah Swann
 */

#include "pch.h"
#include "TreasureBox.h"
using namespace std;

const wstring filename1 = L"treasureChest.png";

TreasureBox::TreasureBox(Stadium* stadium, std::shared_ptr<Picture> picture)
        :Item(stadium, picture)
{

}

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
}


