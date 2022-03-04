/**
 * @file Platform.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_PLATFORM_H
#define SPARTYGNOME_PLATFORM_H

#include "ItemPlatform.h"

class Platform : public ItemPlatform{
private:
    Picture *mPicture;

public:
    Platform(Stadium *stadium, Picture *picture);
    ~Platform();

};

#endif //SPARTYGNOME_PLATFORM_H
