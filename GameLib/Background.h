/**
 * @file Background.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_BACKGROUND_H
#define SPARTYGNOME_BACKGROUND_H

#include "Item.h"
#include "Visitor.h"

/// Background class to load object
class Background : public Item{

public:
    /**
     * The background constructor
     * @param stadium The stadium
     * @param picture The picture
     */
    Background(Stadium* stadium, std::shared_ptr<Picture> picture);

    ///destructor
    ~Background();
    
    /**
     * The draw function
     * @param graphics To Draw
     * */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * The accept function visitor
     * @param visitor The visitor
     */
    void Accept(Visitor* visitor) override {visitor->VisitBackground(this);}

};

#endif //SPARTYGNOME_BACKGROUND_H
