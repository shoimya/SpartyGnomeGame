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

/// Snow class
class Snow : public ItemPlatform{
private:

public:

    /**  Snow platform constructor
    * @param stadium Stadium snow is a part of
    * @param picture Picture of snow */
    Snow(Stadium *stadium, std::shared_ptr<Picture> picture);

    /**  Accept Snow visitor
    * @param visitor Snow Visitor */
    void Accept(Visitor* visitor);

    /// Snow destructor
    ~Snow();

};

#endif //SPARTYGNOME_SNOW_H
