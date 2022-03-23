/**
 * @file Wall.cpp
 * @author Haoxiang Zhang shoimya chowdhury
 */

#include "pch.h"
#include "Wall.h"
using namespace std;


const wstring filename1 = L"wall1.png";
const wstring filename2 = L"wall2.png";


Wall::Wall(Stadium *Stadium, std::shared_ptr<Picture> Picture) : ItemPlatform(Stadium, Picture)
{

}

Wall::~Wall(){

}

void Wall::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    if(!GetPicture()->Empty()) {
        int wid = GetPicture()->GetWidth();
        int hit = GetPicture()->GetHeight();
        graphics->DrawBitmap(GetPicture()->AsBitmap(graphics),
                (int) GetX()-wid , (int) GetY()-hit,
                wid+1, hit );
    }

}

/**
 * The xml load in y
 * @param node The node we visit
 * @param yPos The y position we visit
 */
void Wall::XmlLoady(wxXmlNode* node, double yPos)
{
    long x, y = 0;
    double hit, wid = 0.0;
    node->GetAttribute(L"x", L"0").ToLong(&x);
    node->GetAttribute(L"y", L"0").ToLong(&y);
    node->GetAttribute(L"width").ToDouble(&wid);
    node->GetAttribute(L"height").ToDouble(&hit);
    SetWidth(wid);
    SetHeight(hit);
    SetLocation(x,y+32*yPos);
}