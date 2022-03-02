/**
 * @file Level.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_LEVEL_H
#define SPARTYGNOME_LEVEL_H

#include "Item.h"
#include "Visitor.h"

class Level : public Item{
private:
    Picture* mPicture;

public:
    Level(Stadium* stadium, Picture* picture);
    ~Level();
    bool CollisionTest(Item *item) override;

    void Accept(Visitor* visitor) override {visitor->VisitLevel(this);}

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int scrollx);

};

#endif //SPARTYGNOME_LEVEL_H
