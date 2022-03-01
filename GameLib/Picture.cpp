/**
 * @file Picture.cpp
 * @author Haoxiang Zhang
 */

#include "pch.h"
#include "Picture.h"

using namespace std;


Picture::Picture(Stadium* stadium)
{
    mStadium = stadium;
}
void Picture::SetImage(const wstring &file)
{
    if (!file.empty())
    {
        wstring filename = mStadium->GetImagesDirectory() + L"/" + file;
    }

    mFile = file;
}

Picture::~Picture()
{

}

