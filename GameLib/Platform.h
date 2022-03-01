/**
 * @file Platform.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_PLATFORM_H
#define SPARTYGNOME_PLATFORM_H

#include "Item.h"
#include "Picture.h"

class Platform : public Item{
private:
    Picture *mPicture;

public:
    Platform(Stadium *stadium, Picture *picture);
    bool CollisionTest(Item *item);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int scrollx);
};

#endif //SPARTYGNOME_PLATFORM_H
