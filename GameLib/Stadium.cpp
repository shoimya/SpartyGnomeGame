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
const std::wstring ImagesDirectory = L"data/images";
const std::wstring LevelDirectory = L"data/levels";

/**
 * Generator
 */
Stadium::Stadium()
{
    double x = 100;
    double y = 100;


//    mGnome = make_shared<Gnome>(this);
//    mGnome->SetLocation(x,y);
    auto initialPicture = make_shared<Picture>(this);
    mMapPictures = {{L"i000",initialPicture}};

}

/**
 * Draw the game
 * @param graphics The graphics context to draw on
 * @param width The width
 * @param height The height
 */
void Stadium::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, double width, double height)
{
    ////     Automatic Scaling


///     Draw in virtual pixels on the graphics context

    mScale = double(height) / double(Height);
    graphics->Scale(mScale,mScale);

    auto virtualWidth = (double) width/mScale;
    graphics->PushState();

    auto xOffset = (double)-mGnome->GetX() + virtualWidth / 2.0f;


    // Compute the amount to scroll in the X dimension
    graphics->Translate(xOffset,0);
//    graphics->Scale(mScale,mScale);
    if (!mItems.empty())
    {
        for (auto obj : mItems)
        {
            if (!obj->GetPicture()->Empty())
            {
                    obj->Draw(graphics);
            }
        }
    }
    mGnome->Draw(graphics);
    graphics->PopState();
}

/**
 * Update item in game
 * @param elapsed The time to update
 */
void Stadium::Update(double elapsed)
{
    for (auto item : mItems)
    {
        item->Update(elapsed);
    }
//    mGnome->Update(elapsed);
}

/**
 * The collision test for item
 * @param item
 * @return
 */
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
    if(mMapPictures[L"i000"]->Empty())
    {
        mMapPictures[L"i000"]->SetImage(L"gnome.png");
    }


    // create mGnome
    mGnome = make_shared<Gnome>(this,mMapPictures[L"i000"]);
    mGnome->SetLocation(vec);


//    bool mImageLoad = false;

    auto child = root->GetChildren();
    for( ; child; child=child->GetNext())
    {
       auto name = child->GetName();
       if(name == L"declarations")
       {
           auto subChild = child->GetChildren();
           for(;subChild;subChild=subChild->GetNext())
           {
               XmlPicture(subChild);
           }
       }
       else if(name == L"items")
       {
           auto subChild = child->GetChildren();
           for(;subChild;subChild=subChild->GetNext())
           {
               XmlItem(subChild);
           }
       }
        mItems.push_back(mGnome);
    }

}

void Stadium::Clear()
{
    mItems.clear();
}

void Stadium::XmlItem(wxXmlNode* node)
{

    auto id= node->GetAttribute(L"id").ToStdWstring();

    // select type
    if (id == L"i001" || id == L"i002" )
    {
        auto picture = mMapPictures[id];
        // backgroundForest
        auto item = make_shared<Background>(this, picture);
        item->XmlLoad(node);
        AddItem(item);
    }
    else if (id == L"i003")
    {

        auto picture1 = mMapPictures[L"i0031"];
        auto picture2 = mMapPictures[L"i0032"];
        auto picture3 = mMapPictures[L"i0033"];
        auto item = make_shared<ItemPlatform>(this,picture1);
        auto item1 = make_shared<ItemPlatform>(this,picture2);
        auto item2 = make_shared<ItemPlatform>(this,picture3);
//        item = make_shared<Grass>(this,picture);
        double pos = 0;
        node->GetAttribute(L"width").ToDouble(&pos);
        pos = pos / 32 - 2;
        pos = pos / 2;
        item->XmlLoad(node,-pos);
        AddItem(item);
        for(int i = -pos + 1;i<pos;i++)
        {
            auto item1 = make_shared<ItemPlatform>(this,picture2);
            item1->XmlLoad(node,i);
            AddItem(item1);
        }
        item2->XmlLoad(node,pos);
        AddItem(item2);


    }
    else if (id == L"i004")
    {

//        item = make_shared<Snow>(this,&picture);
    }
    else if (id == L"i005" || id == L"i003")
    {
        // platform
        auto picture1 = mMapPictures[L"i0051"];
        auto picture2 = mMapPictures[L"i0052"];
        auto picture3 = mMapPictures[L"i0053"];
        if(id == L"i003")
        {

            picture1 = mMapPictures[L"i0031"];
            picture2 = mMapPictures[L"i0032"];
            picture3 = mMapPictures[L"i0033"];

        }

        auto item = make_shared<ItemPlatform>(this,picture1);
        auto item2 =  make_shared<ItemPlatform>(this,picture3);
        double pos = 0;
        node->GetAttribute(L"width").ToDouble(&pos);
        pos = pos / 32 - 2;
        pos = pos / 2;
        item->XmlLoad(node,-pos);
        AddItem(item);
        for(int i = -pos + 1;i<pos;i++)
        {
            auto item1 = make_shared<ItemPlatform>(this,picture2);
            item1->XmlLoad(node,i);
            AddItem(item1);
        }
        item2->XmlLoad(node,pos);
        AddItem(item2);
    }
    else if (id == L"i006" || id == L"1007")
    {
        // wall1
//        item = make_shared<Wall>(this,&picture);

    }
        // wall2
    else if (id == L"i008")
    {
        // money100
 //       item = make_shared<Money>(this,&picture);

    }
    else if (id == L"i009")
    {
        // money 1000
//        item = make_shared<Money>(this,&picture);

    }
    else if (id == L"i010")
    {
        // stanley
//        item = make_shared<Stanley>(this,&picture);

//        item = make_shared<Stanley>(this,&picture);

    }
    else if (id == L"i011")
    {
        // door
//        item = make_shared<Door>(this,&picture);

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
    auto picture = make_shared<Picture>(this);
    auto id = node->GetAttribute(L"id").ToStdWstring();

    // select type
    if (id == L"i001" || id == L"i002")
    {
        auto imageName = node->GetAttribute(L"image").ToStdWstring();
        // backgroundForest
        picture->SetImage(imageName);
        mMapPictures[id] = picture;
    }
    else if (id == L"i003" || id == L"i005")
    {

        auto leftImage = node->GetAttribute(L"left-image").ToStdWstring();
        auto midImage =  node->GetAttribute(L"mid-image").ToStdWstring();
        auto rightImage =  node->GetAttribute(L"right-image").ToStdWstring();

        auto picture1 = make_shared<Picture>(this);
        auto picture2 = make_shared<Picture>(this);
        if(id == L"i003")
        {
            picture->SetImage(leftImage);
            mMapPictures[L"i0031"] = picture;

            picture1->SetImage(midImage);
            mMapPictures[L"i0032"] = picture1;

            picture2->SetImage(rightImage);
            mMapPictures[L"i0033"] = picture2;
        }
        else
        {
            picture->SetImage(leftImage);
            mMapPictures[L"i0051"] = picture;

            picture1->SetImage(midImage);
            mMapPictures[L"i0052"] = picture1;

            picture2->SetImage(rightImage);
            mMapPictures[L"i0053"] = picture2;
        }
        picture->SetImagePos(L"left");
        picture1->SetImagePos(L"mid");
        picture2->SetImagePos(L"right");


    }
    else if (id == L"i004")
    {
    }
//    else if (id == L"i005")
//    {
/*        Picture p1(this);
        Picture p2(this);
        Picture p3(this);
        leftImage = node->GetAttribute(L"left-image").ToStdWstring();
        midImage = node->GetAttribute(L"mid-image").ToStdWstring();
        rightImage = node->GetAttribute(L"right-image").ToStdWstring();
        p1.SetImage(leftImage);
        p2.SetImage(midImage);
        p3.SetImage(rightImage);
        */
//        mMapPictures[3] = &p1;
//        mMapPictures[4] = &p2;
//        mMapPictures[5] = &p3;
        // platform
//    }
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
