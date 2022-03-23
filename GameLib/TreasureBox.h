/**
 * @file TreasureBox.h
 * @author Sarah Swann SHOIMYA CHOWDHURY
 *
 *
 */

#ifndef SPARTYGNOME_TREASUREBOX_H
#define SPARTYGNOME_TREASUREBOX_H

#include "Item.h"
#include "Visitor.h"

class TreasureBox : public Item {
private:

    /// The value for treasurebox
    int mValue = 0;

    bool mHit = false; /// Money hit indicator

    double mDuration = 0; /// Frame duration in milliseconds

    double mMoneySpeed = 300; /// Money speed in pixels per second

    wxTimer mFlyTime; /// Timer for floating money

    wxStopWatch mStopWatch; /// Stopwatch used to measure elapsed time
public:
    /// Constructor
    TreasureBox(Stadium* stadium, std::shared_ptr<Picture> picture, int value);
    /// Destructor
    ~TreasureBox();

    /**
     * Set the value of treasure
     * @param value The value to set
     */
    void SetValue(int value){mValue = value;}

    /**
     * Get the value
     * @return value The value for treasurebox
     */
    int GetValue(){return mValue;}

    /**
     * The draw function
     * @param graphics The graphics we are using
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    /**
     * The collision test
     * @param item The item to test collision
     * @return true if its with collision otherwise false
     */
    bool CollisionTest(Item* item) override;

    /**
     * Xml load function
     * @param node The node we are visiting
     */
    void XmlLoad(wxXmlNode *node) override;

    /**
     * Accept function for visitor
     * @param visitor The visitor
     */
    void Accept(Visitor* visitor) override{ visitor->VisitTreasureBox(this);}

    /**
     * The update function
     * @param elapsed The time to update
     */
    void Update(double elapsed) override;
};

#endif //SPARTYGNOME_TREASUREBOX_H
