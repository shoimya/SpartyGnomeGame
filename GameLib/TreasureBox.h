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
    int mValue = 0;

    bool mHit = false; /// Money hit indicator

    double mDuration = 0; /// Frame duration in milliseconds

    double mMoneySpeed = 300; /// Money speed in pixels per second

    wxTimer mFlyTime; /// Timer for floating money

    wxStopWatch mStopWatch; /// Stopwatch used to measure elapsed time
public:
    TreasureBox(Stadium* stadium, std::shared_ptr<Picture> picture, int value);
    ~TreasureBox();

    void SetValue(int value){mValue = value;}
    int GetValue(){return mValue;}
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    bool CollisionTest(Item* item) override;
    void XmlLoad(wxXmlNode *node) override;
    void Accept(Visitor* visitor) override{ visitor->VisitTreasureBox(this);}

    void Update(double elapsed) override;
};

#endif //SPARTYGNOME_TREASUREBOX_H
