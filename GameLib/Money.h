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
    Picture* mPicture;

    double mWidth = 0.0;
    double mHeight = 0.0;
public:
    Money(Stadium* stadium, std::shared_ptr<Picture> picture);
    bool CollisionTest(Item *item) override;
    
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    void XmlLoad(wxXmlNode *node) override;
    void Accept(Visitor* visitor) override {}
    ~Money();

    void SetHeight(double hei) {mHeight = hei;}

    void SetWidth(double wid) {mWidth = wid;}

};

#endif //SPARTYGNOME_MONEY_H
