/**
 * @file TreasureBox.h
 * @author Sarah Swann
 *
 *
 */

#ifndef SPARTYGNOME_TREASUREBOX_H
#define SPARTYGNOME_TREASUREBOX_H

#include "Item.h"
#include "Visitor.h"

class TreasureBox : public Item {
private:

public:

    TreasureBox(Stadium* stadium, std::shared_ptr<Picture> picture);
    ~TreasureBox();

    void Draw(std::shared_ptr<wxGraphicsContext> graphics);
};

#endif //SPARTYGNOME_TREASUREBOX_H
