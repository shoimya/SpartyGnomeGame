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

    /// Collision Status
    bool mStatus = false;

    /// Physical status
    bool mPhysical = true;

protected:
    /// Base-Class Item constructor
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

    /**
     * Get the position
     * @return position Vector The position of item
     */
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

    /**
     * Get the picture of item
     * @return picture The picture of item
     */
    virtual std::shared_ptr<Picture> GetPicture() {return mPicture;}

    /**  Set the item location
    * @param x X location
    * @param y Y location */
    virtual void SetLocation(double x, double y) { mPos.Set(x,y); }

    /**  Set the item location
    * @param vector Vector */
    virtual void SetLocation(const Vector &v) { mPos.Set(v); }

    /**
     * The draw function
     * @param graphics The graphics we using
     */
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) = 0;

    /**
     * The draw function with x offset
     * @param graphics The graphics we using
     * @param scrollx The xoffset value
     */
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int scrollx);

//    virtual wxXmlNode *XmlSave(wxXmlNode *node){return nullptr;}
//    virtual void XmlLoad(wxXmlNode *node){}

    ///  Handle updates for animation
    /// @param elapsed The time since the last update
    virtual void Update(double elapsed);

    ///  Get the city this item is in
    /// @return Stadium pointer
    virtual Stadium *GetStadium() { return mStadium; }

    /**
     * The collision test
     * @param item The item to do collision test
     * @return true if it is with collision otherwise false
     */
    virtual bool CollisionTest(Item *item) {return false;}

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    virtual void Accept(Visitor* visitor) = 0;


    /**
     * Xml save function
     * @param node The node we are visiting
     * @return node The node value we retrun
     */
    virtual wxXmlNode *XmlSave(wxXmlNode *node);

    /**
     * Xml load function
     * @param node The node we are visiting
     */
    virtual void XmlLoad(wxXmlNode *node);

    /**
     * Set the picture for item
     * @param file The picture item fil path
     */
    virtual void SetPicture(const std::wstring &file);

    /**
     * The hit test
     * @param x The x value
     * @param y The y value
     * @return true if it hitted
     */
    virtual bool HitTest(int x, int y);

    /**
     * Set ths status of destroyed
     * @param status
     */
    virtual void SetStatus(bool status){mStatus = status;}

    /**
     * Get the status of destroyed
     * @return The status of destroyed
     */
    virtual bool GetStatus(){return mStatus;}

    /**
     * Get the physical status
     * @return physical The current physicla status
     */
    virtual bool GetPhysical(){return mPhysical;}

    /**
     * Set item to physical
     * @param physical The physical status
     */
    virtual void SetPhysical(bool physical){mPhysical = physical;}

};

#endif //SPARTYGNOME_ITEM_H
