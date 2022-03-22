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

class Stanley : public Item{
private:
    bool mHit = false; /// Money hit indicator

    double mDuration = 0; /// Frame duration in milliseconds

    double mMoneySpeed = 300; /// Money speed in pixels per second

    wxTimer mFlyTime; /// Timer for floating money

    wxStopWatch mStopWatch; /// Stopwatch used to measure elapsed time
public:
    Stanley(Stadium* stadium, std::shared_ptr<Picture> picture);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    void Accept(Visitor* visitor) override {visitor->VisitStanley(this);}

    bool CollisionTest(Item* item) override;

    ~Stanley();

    void Update(double elapsed) override;
};

#endif //SPARTYGNOME_STANLEY_H
