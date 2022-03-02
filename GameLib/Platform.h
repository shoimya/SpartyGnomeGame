/**
 * @file Platform.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_PLATFORM_H
#define SPARTYGNOME_PLATFORM_H

#include "Level.h"

class Platform : public Level{
private:
    Picture *mPicture;

public:
    Platform(Stadium *stadium, Picture *picture);
    ~Platform();

};

#endif //SPARTYGNOME_PLATFORM_H
