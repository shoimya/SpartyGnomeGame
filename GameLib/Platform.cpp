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

Platform::Platform(Stadium* stadium, std::shared_ptr<Picture> picture)
        :ItemPlatform(stadium, picture)
{

}

Platform::~Platform()
{

}

void Platform::XmlLoad(wxXmlNode* node)
{
    long x, y = 0;
    double hit, wid = 0.0;
    node->GetAttribute(L"x", L"0").ToLong(&x);
    node->GetAttribute(L"y", L"0").ToLong(&y);
    node->GetAttribute(L"width").ToDouble(&wid);
    node->GetAttribute(L"height").ToDouble(&hit);
    SetHeight(hit);
    SetWidth(wid);
    SetLocation(x,y);

}

void Platform::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    ItemPlatform::Draw(graphics);
}


/*void Platform::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    auto size = GetImageWidth()/32 - 2;
    ItemPlatform::Draw(graphics,size,GetImageHeight()/32);
}
*/
