/**
 * @file Money.cpp
 * @author Haoxiang Zhang
 */

#include "pch.h"
#include "Money.h"

Money::Money(Stadium* stadium, std::shared_ptr<Picture> picture)
        :Item(stadium, picture)
{

}

void Money::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{

}

Money::~Money()
{

}

