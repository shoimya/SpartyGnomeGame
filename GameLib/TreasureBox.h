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
public:
    TreasureBox(Stadium* stadium, std::shared_ptr<Picture> picture, int value);
    ~TreasureBox();

    void SetValue(int value){mValue = value;}
    int GetValue(){return mValue;}
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    bool CollisionTest(Item* item) override;
    void XmlLoad(wxXmlNode *node) override;
    void Accept(Visitor* visitor) override{ visitor->VisitTreasureBox(this);}

};

#endif //SPARTYGNOME_TREASUREBOX_H
