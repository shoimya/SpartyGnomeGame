/**
 * @file Level.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_LEVEL_H
#define SPARTYGNOME_LEVEL_H

#include "Item.h"

class Level : public Item{
private:

public:
    Level(Stadium* stadium, Picture* picture);
    ~Level();
    bool CollisionTest(Item *item) override;

};

#endif //SPARTYGNOME_LEVEL_H
