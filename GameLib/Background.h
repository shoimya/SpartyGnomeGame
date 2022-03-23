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
private:
    Picture* mPicture;
public:
    /// constructor
    Background(Stadium* stadium, std::shared_ptr<Picture> picture);
    ///destructor
    ~Background();
    
    /**
     * Draw fucntion override
     * @param Graphics: shared pointer
     * */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    /**
     * The aceept function for visitor
     * @param visitor The visitor
     */
    void Accept(Visitor* visitor) override {visitor->VisitBackground(this);}

};

#endif //SPARTYGNOME_BACKGROUND_H
