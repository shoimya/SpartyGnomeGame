/**
 * @file Gnome.cpp
 * @author Haoxiang Zhang
 */

#include "pch.h"
#include "Gnome.h"
using namespace std;

const wstring GnomeImageName = L"/images/gnome.png";

Gnome::Gnome(Stadium* stadium, Picture* picture)
        :Item(stadium, picture)
{

}

void Gnome::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{

}

Gnome::~Gnome()
{

}
