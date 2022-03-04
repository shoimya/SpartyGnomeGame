/**
 * @file Level.cpp
 * @author Haoxiang Zhang
 */

#include "pch.h"
#include "Level.h"

using namespace std;
const wstring filename0 = L"level0.xml";

const wstring filename1 = L"level1.xml";
const wstring filename2 = L"level2.xml";
const wstring filename3 = L"level3.xml";

Level::Level(Stadium* stadium)
{
    mFile = filename0;
}

std::wstring Level::Level0()
{
    return filename0;
}

std::wstring Level::Level1()
{
    return filename1;
}
std::wstring Level::Level2()
{
    return filename2;
}

std::wstring Level::Level3()
{
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
