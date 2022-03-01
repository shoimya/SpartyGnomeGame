/**
 * @file Platform.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_PLATFORM_H
#define SPARTYGNOME_PLATFORM_H

#include "Level.h"
#include "Picture.h"

class Platform : public Level{
private:
    Picture *mPicture;

public:
    Platform(Stadium *stadium, Picture *picture);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int scrollx);
};

#endif //SPARTYGNOME_PLATFORM_H
