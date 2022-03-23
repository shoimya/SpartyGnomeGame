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

/// Class stanley
class Stanley : public Item{
private:
    bool mHit = false; ///< Money hit indicator

    double mDuration = 0; ///< Frame duration in milliseconds

    double mMoneySpeed = 300; ///< Money speed in pixels per second

    wxTimer mFlyTime; ///< Timer for floating money

    wxStopWatch mStopWatch; ///< Stopwatch used to measure elapsed time
public:
    /**
     * Constructor
     * @param stadium The stadium
     * @param picture The picture
     */
    Stanley(Stadium* stadium, std::shared_ptr<Picture> picture);

    /**
     * Draw function for stanley
     * @param graphics The graphics we are using
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * Accept function
     * @param visitor The visitor we are using
     */
    void Accept(Visitor* visitor) override {visitor->VisitStanley(this);}

    /**
     * The collision test
     * @param item The item
     * @return true If its collision test
     */
    bool CollisionTest(Item* item) override;

    /// Destructor
    ~Stanley();

    /**
     * Update function
     * @param elapsed The time to update
     */
    void Update(double elapsed) override;
};

#endif //SPARTYGNOME_STANLEY_H
