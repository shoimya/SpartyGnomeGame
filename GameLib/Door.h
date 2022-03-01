/**
 * @file Door.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_DOOR_H
#define SPARTYGNOME_DOOR_H

#include "Item.h"

class Door : public Item {
private:
    Picture* mPicture;

public:
    Door(Stadium *stadium, Picture *picture);
    bool CollisionTest(Item *item) override;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    ~Door();

};

#endif //SPARTYGNOME_DOOR_H
