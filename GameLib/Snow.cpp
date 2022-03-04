/**
 * @file Snow.cpp
 * @author Haoxiang Zhang
 */

#include "pch.h"
#include "Snow.h"

Snow::Snow(Stadium* stadium, Picture* picture)
        :Item(stadium, picture)
{

}

void Snow::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{

}

void Snow::Accept(Visitor* visitor)
{

}

Snow::~Snow()
{

}
