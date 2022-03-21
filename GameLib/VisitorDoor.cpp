/**
 * @file VisitorDoor.cpp
 * @author Haoxiang Zhang
 */

#include "pch.h"
#include "VisitorDoor.h"
#include "Stadium.h"
#include "Door.h"

VisitorDoor::VisitorDoor()
{

}

VisitorDoor::~VisitorDoor()
{

}

void VisitorDoor::VisitDoor(Door* door)
{
    auto stadium =  door->GetStadium();
    stadium->LevelComplete();
}


