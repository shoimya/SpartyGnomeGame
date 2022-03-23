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

/// Villain class
class Villain : public Item{
private:
//    Picture *picture;

    /// Fish speed in the Y direction
    /// in pixels per second
    double mSpeedY = -240;

    /// Initial Item location in stadium
    Vector mPosInit;

public:
    /// constructor
    Villain(Stadium* stadium, std::shared_ptr<Picture> picture);
    /**
     * The draw function
     * @param graphics The graphics we are using
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    /**
     * Visitor function
     * @param visitor The visitor
     */
    void Accept(Visitor* visitor) override {};
    ~Villain();

    /**
     * Xml load function
     * @param node The node we are visiting
     */
    void XmlLoad(wxXmlNode *node) override;

    /**
     * The update function
     * @param elapsed The time value to update
     */
    void Update(double elapsed) override;

    /**
     * Set the init position
     * @param x The init x value
     * @param y The init y value
     */
    void SetInitialLocation(double x, double y) { mPosInit.Set(x,y); }

    /**
     * The collision test
     * @param item The item to test collision
     * @return true if it is with collision
     */
    bool CollisionTest(Item* item) override;

    /**
     * Get the velocity
     * @return speed The speed of this villain
     */
    double GetVelocity(){return mSpeedY;}
};

#endif //SPARTYGNOME_VILLAIN_H
