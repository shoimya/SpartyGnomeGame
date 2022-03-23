/**
 * @file Visitor.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_VISITOR_H
#define SPARTYGNOME_VISITOR_H

class ItemPlatform;
class Gnome;
class Background;
class Door;
class Money;
class Villain;
class Stanley;
class TreasureBox;

/**
* this is the visitor base class
*/

class Visitor {
private:

public:
    /**
    * Visit platform object
    * @param platform Platform we are visiting
    */
    virtual void VisitItemPlatform(ItemPlatform* itemplatform) {}

    /**
     * Visit platform object
     * @param platform Platform we are visiting
     */
    virtual void VisitGnome(Gnome* gnome) {}

    /**
     * Visit platform object
     * @param platform Platform we are visiting
     */
    virtual void VisitBackground(Background* background) {}

    /**
     * Visit door object
     * @param door Door we are visiting
     */
    virtual void VisitDoor(Door* door){}

    /**
    * Visit money object
    * @param money Money we are visiting
    */
    virtual void VisitMoney(Money* money){}

    /**
    * Visit platform object
    * @param platform Platform we are visiting
    */
    virtual void VisitVillain(Villain* villain){}

    /**
    * Visit stanley object
    * @param platform Stanley we are visiting
    */
    virtual void VisitStanley(Stanley* stanley){}
    
    /**
    * Visit TreasureBox object
    * @param platform TreasureBox we are visiting
    */
    virtual void VisitTreasureBox(TreasureBox* treasure_box){}
};

#endif //SPARTYGNOME_VISITOR_H
