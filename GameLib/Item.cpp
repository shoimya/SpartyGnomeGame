/**
 * @file Item.cpp
 * @author Haoxiang Zhang
 */

#include "pch.h"
#include "Item.h"
#include "Stadium.h"

using namespace std;

/**
 * Constructor
 * @param stadium  The stadium this item is member of
 */
Item::Item(Stadium *stadium, Picture *picture) : mStadium(stadium), mPicture(picture)
{

}

/**
 * Destructor
 */
Item::~Item()
{

}


void Item::Update(double elapsed)
{
  Vector mV;
  Vector newP = GetPos() + mV*elapsed;
  SetLocation(newP);
}

wxXmlNode* Item::XmlSave(wxXmlNode* node)
{
    auto itemNode = new wxXmlNode(wxXML_ELEMENT_NODE, L"id");
    node->AddChild(itemNode);

    itemNode->AddAttribute(L"x", wxString::Format(L"%i", mPos.X()));
    itemNode->AddAttribute(L"y", wxString::Format(L"%i", mPos.Y()));

    return itemNode;
}

void Item::XmlLoad(wxXmlNode* node)
{
    long x, y = 0;
    wstring filename;
    if(mPicture == nullptr)
    {
        filename = node->GetAttribute(L"image" ).ToStdWstring();
        mPicture->SetImage(filename);
    }
    else
    {
        node->GetAttribute(L"x", L"0").ToLong(&x);
        node->GetAttribute(L"y", L"0").ToLong(&y);
        mPos.Set(x,y);
    }
}

