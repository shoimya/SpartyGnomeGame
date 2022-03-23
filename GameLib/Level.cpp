/**
 * @file Level.cpp
 * @author Haoxiang Zhang
 */

#include "pch.h"
#include "Level.h"

using namespace std;

/// level 0
const wstring filename0 = L"data/levels/level0.xml";
/// level 1
const wstring filename1 = L"data/levels/level1.xml";
/// level 2
const wstring filename2 = L"data/levels/level2.xml";
/// level 3
const wstring filename3 = L"data/levels/level3.xml";

Level::Level(Stadium* stadium)
{
    mFile = filename0;
}

std::wstring Level::Level0()
{
    SetLevel(level0);
    return filename0;
}

std::wstring Level::Level1()
{
    SetLevel(level1);
    return filename1;
}
std::wstring Level::Level2()
{
    SetLevel(level2);
    return filename2;
}

std::wstring Level::Level3()
{
    SetLevel(level3);
    return filename3;
}

Level::~Level()
{

}

Vector Level::XmlLoad(wxXmlNode* node)
{
    double width, height;
    node->GetAttribute(L"width",L"0").ToDouble(&width);
    node->GetAttribute(L"height", L"0").ToDouble(&height);

    double x,y = 0;
    node->GetAttribute(L"start-y",L"0").ToDouble(&y);
    node->GetAttribute(L"start-x", L"0").ToDouble(&x);

    Vector gnomePos = Vector(x,y);
    return gnomePos;
}
