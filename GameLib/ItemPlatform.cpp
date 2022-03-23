/**
 * @file ItemPlatform.cpp
 * @author Haoxiang Zhang
 */


#include "pch.h"
#include "ItemPlatform.h"

using namespace std;
const wstring filename = L"";


/**
 * The collision test for item platform
 * @param item The item to test
 * @return true if is with collision
 */
bool ItemPlatform::CollisionTest(Item* item)
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

    return true;
}

ItemPlatform::ItemPlatform(Stadium* stadium, std::shared_ptr<Picture> picture)
        :Item(stadium, picture)
{

}

ItemPlatform::~ItemPlatform()
{

}

/**
 * The draw function for item platform
 * @param graphics  The graphics we are using
 */
void ItemPlatform::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    if(!GetPicture()->Empty()) {
        int wid = GetPicture()->GetWidth();
        int hit = GetPicture()->GetHeight();
        graphics->DrawBitmap(GetPicture()->AsBitmap(graphics),
                (int) GetX()-wid/2 , (int) GetY()-hit/2 ,
                wid+1, hit );
    }

}

/**
 * The draw function with x and y offset
 * @param graphics The graphics we using
 * @param XOffSet  The x offset
 * @param YOffSet  The y offset
 */
void ItemPlatform::Draw(std::shared_ptr<wxGraphicsContext> graphics, double XOffSet, double YOffSet)
{
    int wid = GetPicture()->GetWidth();
    int hit = GetPicture()->GetHeight();
    graphics->DrawBitmap(GetPicture()->AsBitmap(graphics),
            (int)GetX() - wid / 2 , (int)GetY() - hit / 2,
            (wid + 1)*XOffSet, hit*YOffSet);

}

/**
 * The xml load function
 * @param node The node we visit
 * @param xPos The x position we visit
 */
void ItemPlatform::XmlLoad(wxXmlNode* node, double xPos)
{
    double x, y = 0;
    double hit, wid = 0.0;
    node->GetAttribute(L"x", L"0").ToDouble(&x);
    node->GetAttribute(L"y", L"0").ToDouble(&y);
    node->GetAttribute(L"width").ToDouble(&wid);
    node->GetAttribute(L"height").ToDouble(&hit);
    SetWidth(wid);
    SetHeight(hit);

    SetLocation(x + 32*xPos,y);
}
/**
 * The xml load in y
 * @param node The node we visit
 * @param yPos The y position we visit
 */
void ItemPlatform::XmlLoady(wxXmlNode* node, double yPos)
{
    double x, y = 0;
    double hit, wid = 0.0;
    node->GetAttribute(L"x", L"0").ToDouble(&x);
    node->GetAttribute(L"y", L"0").ToDouble(&y);
    node->GetAttribute(L"width").ToDouble(&wid);
    node->GetAttribute(L"height").ToDouble(&hit);
    SetWidth(wid);
    SetHeight(hit);

    SetLocation(x,y+32*yPos);
}

