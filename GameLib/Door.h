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

/// Door item
class Door : public Item {
private:

public:
    /**
     * The door item
     * @param stadium The stadium to vist
     * @param picture The picture to draw
     */
    Door(Stadium *stadium, std::shared_ptr<Picture> picture);

/**
 * Collision test for door
 * @param item The item to with collision test
 * @return true if its with collision
 */
    bool CollisionTest(Item *item) override;

    /**
     * Draw function
     * @param graphics The graphics to draw
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * Accept for visitor
     * @param visitor The visitor to visit
     */
    void Accept(Visitor* visitor) override {visitor->VisitDoor(this);}

    /// Destructor
    ~Door();

};

#endif //SPARTYGNOME_DOOR_H
