/**
 * @file Snow.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_SNOW_H
#define SPARTYGNOME_SNOW_H

#include "ItemPlatform.h"
#include "Visitor.h"
class Snow : public ItemPlatform{
private:

public:
    Snow(Stadium *stadium, std::shared_ptr<Picture> picture);

    void Accept(Visitor* visitor);

    ~Snow();

};

#endif //SPARTYGNOME_SNOW_H
