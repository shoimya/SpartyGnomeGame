/**
 * @file Background.cpp
 * @author Haoxiang Zhang
 */

#include "pch.h"
#include "Background.h"

Background::Background(Stadium* stadium, Picture* picture)
        :Item(stadium, picture)
{

}

Background::~Background()
{

}

void Background::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{

}
