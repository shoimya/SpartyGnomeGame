/**
 * @file Stadium.cpp
 * @author SHOIMYA CHOWDHURY, Haoxiang Zhang
 */


#include "pch.h"
#include "Stadium.h"
#include <wx/graphics.h>
#include "Background.h"
#include "Platform.h"
#include "Door.h"
#include "Money.h"
#include "Wall.h"
#include "Snow.h"
#include "Stanley.h"
#include "Grass.h"

using namespace std;
const std::wstring ImagesDirectory = L"GameLib/data/images";

/**
 * Generator
 */
Stadium::Stadium()
{
    double x = 100;
    double y = 100;

    mImagesDirectory = ImagesDirectory;

//    mGnome = make_shared<Gnome>(this);
//    mGnome->SetLocation(x,y);
}

void Stadium::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, double width, double height)
{
   ////     Automatic Scaling


///     Draw in virtual pixels on the graphics context

    mScale = double(height) / double(Height);
    graphics->Scale(mScale,mScale);
    auto virtualWidth = (double) width/mScale;

    auto xOffset = (double)mGnome->GetX() + virtualWidth / 2.0f;
    graphics->PushState();


    // Compute the amount to scroll in the X dimension
    graphics->Translate(xOffset,0);
    graphics->Scale(mScale,mScale);

     for (auto obj : mItems)
     {
         if (!obj->GetPicture()->Empty())
         {
             obj->Draw(graphics);
         }
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

std::shared_ptr<Item> Stadium::CollisionTest(Item *item)
{
    for(auto i : mItems)
    {
        if(i->CollisionTest(item))
        {
            return i;
        }

    }
    return nullptr;
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
        wxMessageBox(L"Unable to load xml file");
        return;
    }

    Clear();

    // Get the XML document root node
    auto root = xmlDoc.GetRoot();

    // return location of gnome
    auto vec = mLevel->XmlLoad(root);

    // set picture for gnome
    auto picture = Picture(this);
    picture.SetImage(L"gnome.png");
    mMapPictures[0] = &picture;
    AddPicture(&picture);
//    AddItem(mGnome);


    // create mGnome
    mGnome = make_shared<Gnome>(this,&picture);
    mGnome->SetLocation(vec);

    bool mImageLoad = false;

    auto child = root->GetChildren();
    for( ; child; child=child->GetNext())
    {
        auto name = child->GetName();
        if(name == L"background" or name == L"platform")
        {
            if(!mImageLoad)
            {
                XmlPicture(child);
            }
            else
            {
                XmlItem(child);
            }
        }
        else if( name == L"items")
        {
            mImageLoad = true;
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
        item = make_shared<Background>(this, &picture);
        item->XmlLoad(node);
        AddItem(item);
    }
    else if (id == L"i003")
    {
        item = make_shared<Grass>(this,&picture);

    }
    else if (id == L"i004")
    {

        item = make_shared<Snow>(this,&picture);
    }
    else if (id == L"i005")
    {
        // platform
        item = make_shared<Platform>(this,&picture);
        item->XmlLoad(node);
        AddItem(item);
    }
    else if (id == L"i006" || id == L"1007")
    {
        // wall1
        item = make_shared<Wall>(this,&picture);

    }
        // wall2
    else if (id == L"i008")
    {
        // money100
        item = make_shared<Money>(this,&picture);

    }
    else if (id == L"i009")
    {
        // money 1000
        item = make_shared<Money>(this,&picture);

    }
    else if (id == L"i010")
    {
        // stanley
//        item = make_shared<Stanley>(this,&picture);

        item = make_shared<Stanley>(this,&picture);

    }
    else if (id == L"i011")
    {
        // door
        item = make_shared<Door>(this,&picture);

    }
    else if (id == L"i012")
    {
        // UofM

    }
    else if (id == L"i013")
    {
        // wisc

    }

/*    if(item != nullptr)
    {
        item->XmlLoad(node);
        AddItem(item);
    }
*/

}

void Stadium::XmlPicture(wxXmlNode* node)
{
    Picture picture(this);
    auto p = &picture;
    auto id = node->GetAttribute(L"id");
    std::wstring leftImage = L"";
    std::wstring midImage = L"";

    std::wstring rightImage = L"";
    // select type
    if (id == L"i001")
    {
        auto imageName = node->GetAttribute(L"image").ToStdWstring();
        // backgroundForest
        p->SetImage(imageName);
        mMapPictures[1] = &picture;

    }
    else if(id == L"i002")
    {
        auto imageName = node->GetAttribute(L"image").ToStdWstring();
        p->SetImage(imageName);
        mMapPictures[2] = &picture;

    }
/*    else if (id == L"1003")
    {
    }
    else if (id == L"i004")
    {
    }
*/
    else if (id == L"i005")
    {
        Picture p1(this);
        Picture p2(this);
        Picture p3(this);
        leftImage = node->GetAttribute(L"left-image").ToStdWstring();
        midImage = node->GetAttribute(L"mid-image").ToStdWstring();
        rightImage = node->GetAttribute(L"right-image").ToStdWstring();
        p1.SetImage(leftImage);
        p2.SetImage(midImage);
        p3.SetImage(rightImage);
        mMapPictures[3] = &p1;
        mMapPictures[4] = &p2;
        mMapPictures[5] = &p3;
        // platform
    }
    /*
    else if (id == L"i006" || id == L"1007")
    {
        // wall1

    }
        // wall2
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
//        item = make_shared<Stanley>(this,&picture);


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
     */
}

void Stadium::AddItem(const std::shared_ptr<Item>& item)
{
    mItems.push_back(item);
}

void Stadium::AddPicture(Picture* picture)
{
    mPictures.push_back(picture);
}

void Stadium::SetImagesDirectory(const wstring& dir)
{
    mImagesDirectory = dir + ImagesDirectory;
}
void Stadium::Load(int level)
{
    Clear();
//    mTime = 0;
    wstring path;
    switch (level){
        case 0:
            path = L"GameLib/data/levels/level0.xml";
            break;
        case 1:
            path = L"GameLib/data/levels/level1.xml";
            break;
        case 2:
            path = L"GameLib/data/levels/level2.xml";
            break;
        case 3:
            path = L"GameLib/data/levels/level3.xml";
            break;
    default:
        break;
    }
    Load(path);
}
