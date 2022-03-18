/**
 * @file Money.h
 * @author Haoxiang Zhang SHOIMYA CHOWDHURY
 *
 *
 */

#ifndef SPARTYGNOME_MONEY_H
#define SPARTYGNOME_MONEY_H

#include "Item.h"
#include "Visitor.h"

class Money : public Item {
private:

    int mValue = 0;

public:
    Money(Stadium* stadium, std::shared_ptr<Picture> picture, int value);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    void XmlLoad(wxXmlNode *node) override;
    void Accept(Visitor* visitor) override {visitor->VisitMoney(this);}

    void SetValue(int value){mValue = value;}
    int GetValue(){return mValue;}

    bool CollisionTest(Item *item) override;
    ~Money();

};

#endif //SPARTYGNOME_MONEY_H
