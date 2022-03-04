/**
 * @file Picture.cpp
 * @author Haoxiang Zhang
 */

#include "pch.h"
#include "Picture.h"
#include "Stadium.h"

using namespace std;


Picture::Picture(Stadium* stadium)
{
    mStadium = stadium;
}
void Picture::SetImage(const wstring &file)
{
    wstring filename = mStadium->GetImagesDirectory() + L"/" + file;
    mImage = make_shared<wxImage>(filename);
    mEmpty = false;
}

Picture::~Picture()
{

}

