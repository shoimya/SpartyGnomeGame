/**
 * @file Item.h
 * @author Haoxiang Zhang
 *
 *
 */



#ifndef SPARTYGNOME_ITEM_H
#define SPARTYGNOME_ITEM_H


#include <string>
#include <memory>

#include "Vector.h"
#include "Picture.h"
#include "Stadium.h"


class Item {
private:
    /// The stadium this item is contained in
    Stadium *mStadium;

    /// Item location in the stadium
    Vector mPos;

    /// Picture of this item
    Picture *mPicture;

protected:
    Item(Stadium *stadium, Picture *picture);

public:
    /// How much we offset drawing the tile to the left of the center
    const static int OffsetLeft = 64;

    /// How much we offset drawing the tile above the center
    const static int OffsetDown = 32;

    ///  Default constructor (disabled)
    Item() = delete;

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

    virtual Picture* GetPicture() {return mPicture;}

    /**  Set the item location
    * @param x X location
    * @param y Y location */
    virtual void SetLocation(int x, int y) { mPos.Set(x,y); }

    /**  Set the item location
    * @param vector Vector */
    virtual void SetLocation(const Vector &v) { mPos.Set(v); }

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) = 0;

    /**  Test this item to see if it has been clicked on
    * @param x X location on the city to test
    * @param y Y location on the city to test
    * @return true if clicked on */
    virtual bool HitTest(int x, int y);

//    virtual wxXmlNode *XmlSave(wxXmlNode *node){return nullptr;}
//    virtual void XmlLoad(wxXmlNode *node){}

    ///  Handle updates for animation
    /// @param elapsed The time since the last update
    virtual void Update(double elapsed);

    ///  Get the city this item is in
    /// @return Stadium pointer
    virtual Stadium *GetStadium() { return mStadium; }

//    virtual bool CollisionTest(Player *player){ return false;}

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
//    virtual void Accept(ItemVisitor* visitor) = 0;


};

#endif //SPARTYGNOME_ITEM_H
