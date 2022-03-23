/**
 * @file Stanley.h
 * @author Connor Fischetti & Haoxiang Zhang Sarah Swann
 *
 *
 */

#ifndef SPARTYGNOME_STANLEY_H
#define SPARTYGNOME_STANLEY_H

#include "Item.h"
#include "Visitor.h"

/**
 * Class for Stanley item
*/
class Stanley : public Item{
private:
    /// Money hit indicator
    bool mHit = false;

    /// Frame duration in milliseconds
    double mDuration = 0;

    /// Money speed in pixels per second
    double mMoneySpeed = 300;

    /// Timer for floating money
    wxTimer mFlyTime;

    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;
public:
    /**
     * Stanley constructor
     * @param stadium the stadium Stanley is a part of
     * @param picture the picture for Stanley
     */
    Stanley(Stadium* stadium, std::shared_ptr<Picture> picture);
    /**
     * Draw Stanley on a graphics context
     * @param graphics Graphics context to draw on
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * Accept a visitor
     * @param visitor we accept
     */
    void Accept(Visitor* visitor) override {visitor->VisitStanley(this);}

    /**
     * Checks if money is hit
     * @param item item we hit
     * @return bool value if hit is true/false
     */
    bool CollisionTest(Item* item) override;

    ~Stanley();

    /**
     * Checks if money is hit
     * @param elapsed time since last update
     */
    void Update(double elapsed) override;
};

#endif //SPARTYGNOME_STANLEY_H
