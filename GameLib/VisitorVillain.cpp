/**
 * @file VisitorVillain.cpp
 * @author Haoxiang Zhang
 */

#include "pch.h"
#include "VisitorVillain.h"
#include "Stadium.h"
#include "Villain.h"

VisitorVillain::VisitorVillain()
{

}

VisitorVillain::~VisitorVillain()
{

}

void VisitorVillain::VisitVillain(Villain* villain)
{
    /// MAKE GNOME FALL OFF MAP
    /// CALL "YOU LOSE!" FUNCTION FOR 2 SECONDS
    villain->GetStadium()->Reset();
}


