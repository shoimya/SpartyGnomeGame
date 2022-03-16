/**
 * @file ItemPlatform.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_ITEMPLATFORM_H
#define SPARTYGNOME_ITEMPLATFORM_H

#include "Item.h"
#include "Visitor.h"

class ItemPlatform : public Item{
private:
    Picture* mPicture;

    double mWidth = 0.0;
    double mHeight = 0.0;


public:
    ItemPlatform(Stadium* stadium, std::shared_ptr<Picture> picture);
    ~ItemPlatform();
    bool CollisionTest(Item *item) override;

    void Accept(Visitor* visitor) override {visitor->VisitItemPlatform(this);}

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, double XOffSet, double yOffSet);

    void XmlLoad(wxXmlNode *node, double xPos);

    double GetImageHeight() const {return mHeight;}

    double GetImageWidth() const {return mWidth;}


    void SetHeight(double hei) {mHeight = hei;}

    void SetWidth(double wid) {mWidth = wid;}
};

#endif //SPARTYGNOME_ITEMPLATFORM_H
