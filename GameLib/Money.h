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
     *  The money class
     * @param stadium The stadium
     * @param picture The picture of money
     * @param value The value of money
     */
    Money(Stadium* stadium, std::shared_ptr<Picture> picture, int value);

    /**
     * Draw the money on a graphics context
     * @param graphics Graphics context to draw on
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * Xml load for money
     * @param node The node we are visiting
     */
    void XmlLoad(wxXmlNode *node) override;


    /**
     * The accept function
     * @param visitor The visitor we are visiting
     */
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
     * @return true if its collision
      */
    bool CollisionTest(Item *item) override;

    /// Destructor
    ~Money();

    /**
     * Update money behavior
     * @param elapsed time since last update
     */
    void Update(double elapsed) override;

};

#endif //SPARTYGNOME_MONEY_H
