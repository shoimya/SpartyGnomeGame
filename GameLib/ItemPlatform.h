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


/// Base class for Platform and wall
class ItemPlatform : public Item{
private:

    /// The width of item platform
    double mWidth = 0.0;

    /// The height of item platform
    double mHeight = 0.0;


public:
    /// Consturctor
    ItemPlatform(Stadium* stadium, std::shared_ptr<Picture> picture);
    /// Destructor
    ~ItemPlatform();


    bool CollisionTest(Item *item) override;

    /**
     * The aceept function for visitor
     * @param visitor The visitor
     */
    void Accept(Visitor* visitor) override {visitor->VisitItemPlatform(this);}

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, double XOffSet, double yOffSet);

    void XmlLoad(wxXmlNode *node, double xPos);
    void XmlLoady(wxXmlNode *node, double yPos);

    /**
     * Get the image height
     * @return The image height
     */
    double GetImageHeight() const {return mHeight;}

    /**
     * Get the image width
     * @return The image width
     */
    double GetImageWidth() const {return mWidth;}

    /**
     * Set the height of Image
     * @param height The value we set
     */
    void SetHeight(double hei) {mHeight = hei;}

    /**
     * Set the width of image
     * @param wid The width we set
     */
    void SetWidth(double wid) {mWidth = wid;}
};

#endif //SPARTYGNOME_ITEMPLATFORM_H
