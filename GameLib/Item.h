/**
 * @file Item.h
 * @author Haoxiang Zhang, Shaojie Zhang
 *
 *
 */



#ifndef SPARTYGNOME_ITEM_H
#define SPARTYGNOME_ITEM_H

#include <string>
#include <memory>

#include "Vector.h"
#include "Picture.h"

class Stadium;
class Visitor;

class Item {
private:
    /// The stadium this item is contained in
    Stadium *mStadium = nullptr;

    /// Item location in the stadium
    Vector mPos;

    /// Picture of this item
    std::shared_ptr<Picture> mPicture;

protected:
    Item(Stadium *stadium, std::shared_ptr<Picture> picture);

public:
    /// How much we offset drawing the tile to the left of the center
    const static int OffsetLeft = 64;

    /// How much we offset drawing the tile above the center
    const static int OffsetDown = 32;

    ///  Copy constructor (disabled)
    Item(const Item &) = delete;

    virtual ~Item();

    /**  The X location of the center of the tile
    * @return X location in pixels */
    virtual double GetX() const { return mPos.X(); }

    /**  The Y location of the center of the tile
    * @return Y location in pixels */
    virtual double GetY() const { return mPos.Y(); }

    virtual Vector GetPos() const { return mPos;}

    /**
     * Get width of picture
     * @return The width of picture
     */
    virtual int GetWidth() const {return mPicture->GetWidth();}

    /**
     * Get height of picture
     * @return The height of picture
     */
    virtual int GetHeight() const {return mPicture->GetHeight();}

    virtual std::shared_ptr<Picture> GetPicture() {return mPicture;}

    /**  Set the item location
    * @param x X location
    * @param y Y location */
    virtual void SetLocation(double x, double y) { mPos.Set(x,y); }

    /**  Set the item location
    * @param vector Vector */
    virtual void SetLocation(const Vector &v) { mPos.Set(v); }

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) = 0;

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int scrollx);

//    virtual wxXmlNode *XmlSave(wxXmlNode *node){return nullptr;}
//    virtual void XmlLoad(wxXmlNode *node){}

    ///  Handle updates for animation
    /// @param elapsed The time since the last update
    virtual void Update(double elapsed);

    ///  Get the city this item is in
    /// @return Stadium pointer
    virtual Stadium *GetStadium() { return mStadium; }

    virtual bool CollisionTest(Item *item) {return false;}

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    virtual void Accept(Visitor* visitor) = 0;


    virtual wxXmlNode *XmlSave(wxXmlNode *node);
    virtual void XmlLoad(wxXmlNode *node);

    void SetPicture(const std::wstring &file);
};

#endif //SPARTYGNOME_ITEM_H
