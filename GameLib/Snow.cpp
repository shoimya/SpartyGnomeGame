/**
 * @file Snow.cpp
 * @author Haoxiang Zhang
 */

#include "pch.h"
#include "Snow.h"

Snow::Snow(Stadium* stadium, std::shared_ptr<Picture> picture)
        :ItemPlatform(stadium, picture)
{

}

void Snow::Accept(Visitor* visitor)
{

}

Snow::~Snow()
{

}
