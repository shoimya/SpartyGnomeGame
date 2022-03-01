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

}

void Stadium::SetImageDirectory(const std::wstring &dir)
{
    mImagesDirectory = dir + ImagesDirectory;
}

void Stadium::OnDraw(std::shared_ptr<wxGraphicsContext> graphics)
{

}
