/**
 * @file Stadium.cpp
 * @author Haoxiang Zhang
 */


#include "pch.h"
#include "Stadium.h"


using namespace std;
const std::wstring ImagesDirectory = L"/data/images";

/**
 * Generator
 */
Stadium::Stadium()
{
    double x = 100;
    double y = 100;

    mGnome = make_shared<Gnome>(this);
    mGnome->SetLocation(x,y);
}

void Stadium::SetImageDirectory(const std::wstring &dir)
{
    mImagesDirectory = dir + ImagesDirectory;
}


void Stadium::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, wxDC *dc)
{
   ////     Automatic Scaling

    mScale = double(height) / double(Height);
    graphics->Scale(mScale, mScale);

    auto virtualWidth = (double)width/mScale;
    graphics->PushState();


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

