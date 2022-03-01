/**
 * @file Item.cpp
 * @author Haoxiang Zhang
 */

#include "pch.h"
#include "Item.h"
#include "Stadium.h"

using namespace std;

/**
 * Constructor
 * @param stadium  The stadium this item is member of
 */
Item::Item(Stadium *stadium, Picture *picture) : mStadium(stadium), mPicture(picture)
{

}

/**
 * Destructor
 */
Item::~Item()
{

}


void Item::Update(double elapsed)
{
  Vector mV;
  Vector newP = GetPos() + mV*elapsed;
  SetLocation(newP);
}

