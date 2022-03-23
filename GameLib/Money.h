/**
 * @file Money.h
 * @author Haoxiang Zhang SHOIMYA CHOWDHURY Sarah Swann
 *
 *
 */

#ifndef SPARTYGNOME_MONEY_H
#define SPARTYGNOME_MONEY_H

#include "Item.h"
#include "Visitor.h"

/// Money class
class Money : public Item {
private:

    /// Money value
    int mValue = 0;

    /// Money value stored
    int mInitValue = 0;

    bool mHit = false; /// Money hit indicator

    double mDuration = 0; /// Frame duration in milliseconds

    double mMoneySpeed = 300; /// Money speed in pixels per second

    wxTimer mFlyTime; /// Timer for floating money

    wxStopWatch mStopWatch; /// Stopwatch used to measure elapsed time

public:
    /// Money constructor
    Money(Stadium* stadium, std::shared_ptr<Picture> picture, int value);

    /**
     * Draw the money on a graphics context
     * @param graphics Graphics context to draw on
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /// Load Xml
    void XmlLoad(wxXmlNode *node) override;

    /// Accept a visitor
    void Accept(Visitor* visitor) override {visitor->VisitMoney(this);}
    /**
     * Set money value
     * @param value money value to be set
     */
    void SetValue(int value){mValue = value;}

    /**
     * Get money value
     * @return money value
     */
    int GetValue(){return mValue;}

    /**
     * Checks if money is hit
     * @param item item we hit
     */
    bool CollisionTest(Item *item) override;
    ~Money();

    /**
     * Update money behavior
     * @param elapsed time since last update
     */
    void Update(double elapsed) override;

};

#endif //SPARTYGNOME_MONEY_H
