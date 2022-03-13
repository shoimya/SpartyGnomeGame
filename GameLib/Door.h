/**
 * @file Door.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_DOOR_H
#define SPARTYGNOME_DOOR_H

#include "Item.h"
#include "Visitor.h"

class Door : public Item {
private:
    Picture* mPicture;

public:
    Door(Stadium *stadium, std::shared_ptr<Picture> picture);
    bool CollisionTest(Item *item) override;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void Accept(Visitor* visitor) override {visitor->VisitDoor(this);}

    ~Door();

};

#endif //SPARTYGNOME_DOOR_H
