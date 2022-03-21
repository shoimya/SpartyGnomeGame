/**
 * @file Stanley.h
 * @author Connor Fischetti & Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_STANLEY_H
#define SPARTYGNOME_STANLEY_H

#include "Item.h"
#include "Visitor.h"

class Stanley : public Item{
private:

public:
    Stanley(Stadium* stadium, std::shared_ptr<Picture> picture);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    void Accept(Visitor* visitor) override {visitor->VisitStanley(this);}

    bool CollisionTest(Item* item) override;

    ~Stanley();
};

#endif //SPARTYGNOME_STANLEY_H
