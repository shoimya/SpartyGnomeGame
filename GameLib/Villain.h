/**
 * @file Villain.h
 * @author Connor
 *
 *
 */

#ifndef SPARTYGNOME_VILLAIN_H
#define SPARTYGNOME_VILLAIN_H

#include "Item.h"
#include "Visitor.h"

class Villain : public Item{
private:
//    Picture *picture;

    /// Fish speed in the Y direction
    /// in pixels per second
    double mSpeedY = -240;

    /// Initial Item location in stadium
    Vector mPosInit;

public:
    Villain(Stadium* stadium, std::shared_ptr<Picture> picture);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    void Accept(Visitor* visitor) override {};
    ~Villain();

    void XmlLoad(wxXmlNode *node) override;

    void Update(double elapsed) override;

    void SetInitialLocation(double x, double y) { mPosInit.Set(x,y); }

    bool CollisionTest(Item* item) override;

    double GetVelocity(){return mSpeedY;}
};

#endif //SPARTYGNOME_VILLAIN_H
