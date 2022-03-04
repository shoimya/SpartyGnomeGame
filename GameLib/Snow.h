/**
 * @file Snow.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_SNOW_H
#define SPARTYGNOME_SNOW_H

#include "Item.h"
#include "Visitor.h"
class Snow : public Item{
private:
    Picture *picture;

public:
    Snow(Stadium *stadium, Picture *picture);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics);
    void Accept(Visitor* visitor);

    ~Snow();

};

#endif //SPARTYGNOME_SNOW_H
