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
    * Visit item platform object
    * @param itemplatform Platform we are visiting
    */
    virtual void VisitItemPlatform(ItemPlatform* itemplatform) {};

    /**
     * Visit gnome object
     * @param gnome Gnome we are visiting
     */
    virtual void VisitGnome(Gnome* gnome) {}

    /**
     * Visit background object
     * @param background we are visiting
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
    * Visit villain object
    * @param villain Villain we are visiting
    */
    virtual void VisitVillain(Villain* villain){}

    /**
    * Visit stanley object
    * @param stanley Stanley we are visiting
    */
    virtual void VisitStanley(Stanley* stanley){}
    
    /**
    * Visit TreasureBox object
    * @param treasureBox TreasureBox  we are visiting
    */
    virtual void VisitTreasureBox(TreasureBox* treasure_box){}

    virtual void VisitMoneyText(Money* money){}
};

#endif //SPARTYGNOME_VISITOR_H
