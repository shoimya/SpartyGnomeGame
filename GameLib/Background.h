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

class Background : public Item{
private:
    Picture* mPicture;
public:
    Background(Stadium* stadium, std::shared_ptr<Picture> picture);
    ~Background();

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    void Accept(Visitor* visitor) override {visitor->VisitBackground(this);}

};

#endif //SPARTYGNOME_BACKGROUND_H
