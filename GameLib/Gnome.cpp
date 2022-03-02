/**
 * @file Gnome.cpp
 * @author Haoxiang Zhang
 */

#include "pch.h"
#include "Gnome.h"
#include "string"
using namespace std;

const wstring GnomeImageName = L"data/images/gnome.png";


Gnome::Gnome(Stadium* stadium) : mStadium(stadium)
{
    mGnomeImage = make_unique<wxImage>(GnomeImageName, wxBITMAP_TYPE_ANY);
    mGnomeBitmap = make_unique<wxBitmap>(*mGnomeImage);
}


void Gnome::Draw(wxDC* dc)
{
    double wid = mGnomeBitmap->GetWidth();
    double hit = mGnomeBitmap->GetHeight();
    dc->DrawBitmap(*mGnomeBitmap,
            int(mX - wid / 2),
            int(mY - hit / 2));
}