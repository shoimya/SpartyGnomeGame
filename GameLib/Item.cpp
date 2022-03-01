/**
 * @file Item.cpp
 * @author Haoxiang Zhang
 */

#include "pch.h"
#include "Item.h"
#include "Stadium.h"

using namespace std;

const int InsideTolerance = 64;
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

bool Item::HitTest(int x, int y)
{

    return (abs(x - mPos.X()) + abs(y - mPos.Y()) * 2) <= InsideTolerance;

}

void Item::Update(double elapsed)
{
  Vector mV;
  Vector newP = GetPos() + mV*elapsed;
  SetLocation(newP);
}



