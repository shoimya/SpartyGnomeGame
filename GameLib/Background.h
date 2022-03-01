/**
 * @file Background.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_BACKGROUND_H
#define SPARTYGNOME_BACKGROUND_H

#include "Item.h"
class Background : public Item{
private:

public:
    Background(Stadium* stadium, Picture* picture);
    ~Background();
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

};

#endif //SPARTYGNOME_BACKGROUND_H
