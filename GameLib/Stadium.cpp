/**
 * @file Stadium.cpp
 * @author SHOIMYA CHOWDHURY, Haoxiang Zhang
 */


#include "pch.h"
#include "Stadium.h"
#include <wx/graphics.h>
#include "Background.h"
#include "Door.h"
#include "Money.h"
#include "Stanley.h"
#include "VisitorDoor.h"
#include "Villain.h"
#include "VisitorMoney.h"
#include "Wall.h"
#include "Snow.h"
#include "TreasureBox.h"
using namespace std;

/// The image path
const std::wstring ImagesDirectory = L"data/images";

///The level path
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
    mGameMode = begin;
    mLevel = make_shared<Level>(this);
    mTime = -1;

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
                    obj->Draw(graphics);
        }
    }

    mGnome->Draw(graphics);
    graphics->SetPen(*wxBLACK_PEN);

    wxFont gameFont(wxSize(100, 100),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);
    graphics->SetFont(gameFont,wxColor(0,0,0));

    double time =  GetTime();
    int min = (int)time / 60;
    int sec = (int)time - min*60;
    std::string strMin = to_string(min);
    std::string strSec= to_string(sec);
    if(time < 0)
    {
        strSec = "0";
    }
    if(sec < 10)
    {
        strSec = "0" + strSec;
    }


    double pos = mGnome->GetPos().X() - mGnome->GetInitPos().X();
    graphics->DrawText(strMin,200+pos,0);
    graphics->DrawText(":",265+pos,0);
    graphics->DrawText(strSec,300+pos,0);

    int score =  GetScore();
    std::string strScore ="$" + to_string(score);
    graphics->DrawText(strScore,1210+pos,0);
    graphics->PopState();
}

/**
 * Update item in game
 * @param elapsed The time to update
 */
void Stadium::Update(double elapsed)
{
    if(mTime >= 0)
    {
        mGameMode = progress;
        mGnome->SetStop(false);
        if(mGnome->GetY() > 1200)
        {
            mGameMode = loss;
            Stop();
        }
    }
    else if(mTime < 0 && mTime > -1) {
        if(mGameMode == loss)
        {
            mGnome->InitPosition();
        }
        else if (mGameMode == win)
        {
            int levelNum = GetLevelNum();
            levelNum++;
            SetLevelNum(levelNum);
            Load(levelNum);
        }
        mGameMode = begin;
    }
    else{
        mGnome->SetStop(true);
    }

    if(mGameMode == progress )
    {
        mGnome->Update(elapsed);
    }
    for (auto item : mItems)
    {
        item->Update(elapsed);
    }

    mTime += elapsed;
//    mGnome->Update(elapsed);
}

/**
 * The collision test for item
 * @param item
 * @return
 */
Item* Stadium::CollisionTest(Item *item)
{
    VisitorDoor visitorDoor;
//    VisitorVillain visitorVillain;
    vector<Item*> toRemove;

    for(auto i : mItems)
    {
        if(i->CollisionTest(item))
        {
            i->Accept(&visitorDoor);
            if(i->GetStatus())
            {
                toRemove.push_back(i);
            }
            if(i->GetPhysical())
            {
                return i;
            }
        }
    }

    if(!toRemove.empty())
    {
        for(auto i: toRemove)
        {
            if(i->GetY() > 1200 || i->GetY() <0)
            {
                Delete(i);
            }
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

/**
 * The stadium load function
 * @param filename  The file to load
 */
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
        // create mGnome
    }
    // Set init position
    mGnome = new Gnome (this,mMapPictures[L"i000"]);
    mGnome->SetInitPosition(vec);
    mGnome->InitPosition();

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
    }
    mGameMode = progress;

}

/**
 * Clear items
 */
void Stadium::Clear()
{
    mItems.clear();
}

/**
 * Xml load item
 * @param node The node we are visiting
 */
void Stadium::XmlItem(wxXmlNode* node)
{

    auto id= node->GetAttribute(L"id").ToStdWstring();

    // select type
    if (id == L"i001" || id == L"i002" )
    {
        auto picture = mMapPictures[id];
        // backgroundForest
        auto item = new Background (this, picture);
        item->XmlLoad(node);
        AddItem(item);
    }
//        item = make_shared<Snow>(this,&picture);
    else if (id == L"i005" || id == L"i004" || id == L"i003")
    {
        // platform
        auto picture1 = mMapPictures[L"i0051"];
        auto picture2 = mMapPictures[L"i0052"];
        auto picture3 = mMapPictures[L"i0053"];
        if (id == L"i004")
        {
            picture1 = mMapPictures[L"i0041"];
            picture2 = mMapPictures[L"i0042"];
            picture3 = mMapPictures[L"i0043"];
        }
        else if (id == L"i003")
        {
            picture1 = mMapPictures[L"i0031"];
            picture2 = mMapPictures[L"i0032"];
            picture3 = mMapPictures[L"i0033"];

        }
        auto item = new ItemPlatform(this,picture1);
        auto item2 =  new ItemPlatform(this,picture3);
        double pos = 0;
        node->GetAttribute(L"width").ToDouble(&pos);
        pos = pos / 32 - 2;
        pos = pos / 2;
        item->XmlLoad(node, -pos-0.5);
        AddItem(item);

        double i = -pos+0.5;
        while (i < pos+0.5) {
                auto item1 = new ItemPlatform(this, picture2);
                item1->XmlLoad(node, i);
                AddItem(item1);
                i++;
        }
        item2->XmlLoad(node, pos+0.5);
        AddItem(item2);
    }
    else if (id == L"i006" || id == L"i007")
    {
        // wall1
        auto picture = mMapPictures[L"i006"];
        if (id == L"i007")
        {
            picture = mMapPictures[L"i007"];
        }
        double pos = 0;
        node->GetAttribute(L"height").ToDouble(&pos);
        pos = pos / 32;
        pos = pos / 2;
        double i = -pos+0.5;
        while (i<=pos-0.5)
        {
            auto item = new ItemPlatform(this,picture);
            item->XmlLoady(node,i);
            AddItem(item);
            i++;
        }
    }
        // wall2
    else if (id == L"i008")
    {
        // money100
        auto picture = mMapPictures[id];
        auto item = new Money(this, picture,100);
        item->SetPhysical(false);
        item->XmlLoad(node);
        AddItem(item);
    }
    else if (id == L"i009")
    {

        auto picture = mMapPictures[id];
        auto item = new Money(this, picture,1000);
        item->SetPhysical(false);
        item->XmlLoad(node);
        AddItem(item);

    }
    else if (id == L"i010")
    {
        // stanley
        auto picture = mMapPictures[L"i010"];
        auto item = new Stanley(this,picture);
        item->SetPhysical(false);
        item->XmlLoad(node);
        AddItem(item);
    }
    else if (id == L"i011")
    {
        // door
        auto picture = mMapPictures[L"i011"];
        auto item = new Door(this,picture);
        item->SetPhysical(false);
        item->XmlLoad(node);
        AddItem(item);

    }
    else if (id == L"i012" || id ==L"i013")
    {
        // UofM & Wisc
        auto picture = mMapPictures[id];
        auto item = new Villain(this,picture);
        item->XmlLoad(node);
        AddItem(item);
    }
    // treasureBox
    else if(id == L"i014")
    {
        auto picture = mMapPictures[id];
        auto item = new TreasureBox(this, picture,10000);
        item->SetPhysical(false);
        item->XmlLoad(node);
        AddItem(item);
    }


}

/**
 * Xml set up picture
 * @param node The node we are visiting
 */
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
    else if (id == L"i003" || id == L"i005" || id == L"i004")
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
        else if (id == L"i005")
        {
            picture->SetImage(leftImage);
            mMapPictures[L"i0051"] = picture;

            picture1->SetImage(midImage);
            mMapPictures[L"i0052"] = picture1;

            picture2->SetImage(rightImage);
            mMapPictures[L"i0053"] = picture2;
        }
        else
        {
            picture->SetImage(leftImage);
            mMapPictures[L"i0041"] = picture;

            picture1->SetImage(midImage);
            mMapPictures[L"i0042"] = picture1;

            picture2->SetImage(rightImage);
            mMapPictures[L"i0043"] = picture2;

        }
        picture->SetImagePos(L"left");
        picture1->SetImagePos(L"mid");
        picture2->SetImagePos(L"right");
    }
    else
    {
        // wall1
        auto imageName = node->GetAttribute(L"image",L"").ToStdWstring();
        if(!imageName.empty())
        {
            picture->SetImage(imageName);
            mMapPictures[id] = picture;
        }
    }

}

/**
 * Add item to mItems
 * @param item The item to add
 */
void Stadium::AddItem(Item* item)
{
    mItems.push_back(item);
}

/**
 * Load level function
 * @param level The level to load
 */
void Stadium::Load(int level)
{
//    mTime = 0;
    wstring path;
    switch (level){
        case 0:
            path = mLevel->Level0();
            break;

        case 1:
            path = mLevel->Level1();
            break;

        case 2:
            path = mLevel->Level2();
            break;

        default:
            path = mLevel->Level3();
            break;
    }
    if(level>3)
    {
        level = 3;
    }
    Clear();
    SetLevelNum(level);
    mScoreBoard.SetScore(0);
    Load(path);
}

/**
 * The hit test
 * @param x The x value
 * @param y The y value
 * @return
 */
Item* Stadium::HitTest(int x, int y)
{
    for (auto i = mItems.rbegin(); i!=mItems.rend(); i++) {
        if ((*i)->HitTest(x, y)) {
            return *i;
        }
    }
    return nullptr;
}

/**
 * Delete item
 * @param item The item to be deleted
 */
void Stadium::Delete(Item* item)
{
    auto loc = std::find(mItems.begin(),mItems.end(),item);
    if(loc != mItems.end())
    {
        mItems.erase(loc);
    }

}

/**
 * Add score for scoreboard
 * @param value The value to add
 */
void Stadium::AddScore(int value)
{
    auto score = mScoreBoard.GetScore();
    mScoreBoard.SetScore(score + value);
}

/**
 * Get score
 * @return score The score we get
 */
int Stadium::GetScore()
{
    return mScoreBoard.GetScore();
}

/**
 * The tution up function
 */
void Stadium::TuitionUp()
{
    VisitorMoney visitorMoney;
    for(auto i : mItems)
    {
        i->Accept(&visitorMoney);
    }
}

/**
 * Stop the game
 */
void Stadium::Stop()
{
    mTime = -2;
    mGameMode = loss;
    mScoreBoard.SetScore(0);
//    Load(GetLevelNum());w
}

/**
 * Level complete
 */
void Stadium::LevelComplete()
{
    mTime = -2;
    mGameMode = win;
    mScoreBoard.SetScore(0);
}