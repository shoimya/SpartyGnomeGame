/**
 * @file Stadium.cpp
 * @author SHOIMYA CHOWDHURY, Haoxiang Zhang
 */


#include "pch.h"
#include "Stadium.h"
#include <wx/graphics.h>
#include "Background.h"
#include "Platform.h"

using namespace std;
const std::wstring ImagesDirectory = L"/data/images";

/**
 * Generator
 */
Stadium::Stadium()
{
    double x = 100;
    double y = 100;

//    mGnome = make_shared<Gnome>(this);
//    mGnome->SetLocation(x,y);
}

void Stadium::SetImageDirectory(const std::wstring &dir)
{
    mImagesDirectory = dir + ImagesDirectory;
}


void Stadium::OnDraw(shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    ////     Automatic Scaling

    mScale = double(height) / double(mHeight);
    graphics->Scale(mScale, mScale);

    auto virtualWidth = (double)width/mScale;
    // Compute the amount to scroll in the X dimension
    auto xOffset = (double)-mGnome->GetX() + virtualWidth / 2.0f;

    graphics->PushState();
    graphics->Translate(xOffset, 0);


///     Draw in virtual pixels on the graphics context

     for (auto obj : mItems)
     {
         obj->Draw(graphics);
     }

     graphics->PopState();
}

void Stadium::Update(double elapsed)
{
    for (auto item : mItems)
    {
        item->Update(elapsed);
    }
}

Item* Stadium::CollisionTest(Item *item)
{
    for (auto i = mItems.begin(); i != mItems.end(); i++)
    {
        if ((*i)->CollisionTest(item))
        {
            return nullptr;
        }
    }
    return item;
}

/**
 * Save the stadium as a .aqua XML file.
 *
 * Open an XML file and stream the stadium data to it.
 *
 * @param filename The filename of the file to save the stadium to
 */
void Stadium::Save(const wxString &filename)
{

}

void Stadium::Load(const wxString& filename)
{

    wxXmlDocument xmlDoc;
    if(!xmlDoc.Load(filename))
    {
        wxMessageBox(L"Unable to load Aquarium file");
        return;
    }

    Clear();

    // Get the XML document root node
    auto root = xmlDoc.GetRoot();

    auto picture = Picture(this);

    auto child = root->GetChildren();
    for( ; child; child=child->GetNext())
    {
        auto name = child->GetName();
        if(name == L"item")
        {
            XmlItem(child);
        }
    }

}

void Stadium::Clear()
{
    mItems.clear();
}

void Stadium::XmlItem(wxXmlNode* node)
{
    shared_ptr<Item> item;

    auto id= node->GetAttribute(L"id");
    auto picture = Picture(this);

    // select type
    if (id == L"i001" || id == L"i002" )
    {
        // backgroundForest
        item = make_shared<Background>(this,&picture);
    }
    else if (id == L"1003")
    {
        // grass

    }
    else if (id == L"i004")
    {
        // snow

    }

    else if (id == L"i005")
    {
        // platform
        item = make_shared<Platform>(this,&picture);
    }
    else if (id == L"i006")
    {
        // wall1

    }
    else if (id == L"i007")
    {
        // wall2

    }
    else if (id == L"i008")
    {
        // money100

    }
    else if (id == L"i009")
    {
        // money 1000

    }
    else if (id == L"i010")
    {
        // stanley

    }
    else if (id == L"i011")
    {
        // door

    }
    else if (id == L"i012")
    {
        // UofM

    }
    else if (id == L"i013")
    {
        // wisc

    }

    if(item != nullptr)
    {
        item->XmlLoad(node);
        AddItem(item);
    }



}

void Stadium::AddItem(std::shared_ptr<Item> item)
{
    mItems.push_back(item);
}

void Stadium::AddPicture(std::shared_ptr<Picture> picture)
{
    mPictures.push_back(picture);
}

void Stadium::SetImagesDirectory(const wstring& dir)
{
    mImagesDirectory = dir + ImagesDirectory;

}
