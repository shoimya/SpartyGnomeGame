/**
 * @file Money.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_MONEY_H
#define SPARTYGNOME_MONEY_H

#include "Item.h"
#include "Visitor.h"

class Money : public Item {
private:
    Picture* mPicture;

public:
    Money(Stadium* stadium, std::shared_ptr<Picture> picture);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    void Accept(Visitor* visitor) override {}
    ~Money();


};

#endif //SPARTYGNOME_MONEY_H
