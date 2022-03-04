/**
 * @file ItemPlatform.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_ITEMPLATFORM_H
#define SPARTYGNOME_ITEMPLATFORM_H

#include "Item.h"
#include "Visitor.h"

class ItemPlatform : public Item{
private:
    Picture* mPicture;

public:
    ItemPlatform(Stadium* stadium, Picture* picture);
    ~ItemPlatform();
    bool CollisionTest(Item *item) override;

    void Accept(Visitor* visitor) override {visitor->VisitItemPlatform(this);}

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int scrollx);
};

#endif //SPARTYGNOME_ITEMPLATFORM_H
