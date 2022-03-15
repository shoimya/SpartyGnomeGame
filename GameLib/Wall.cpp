/**
 * @file Wall.cpp
 * @author Haoxiang Zhang
 */

#include "pch.h"
#include "Wall.h"


Wall::Wall(Stadium *Stadium, std::shared_ptr<Picture> Picture) : ItemPlatform(Stadium, Picture)
{

}

Wall::~Wall(){

}

void Wall::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    ItemPlatform::Draw(graphics);
}

void Wall::Draw(std::shared_ptr<wxGraphicsContext> graphics, double XOffSet, double yOffSet)
{
    ItemPlatform::Draw(graphics, XOffSet, yOffSet);
}

void Wall::XmlLoad(wxXmlNode* node, int xPos)
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