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
    * Visit platform object
    * @param platform Platform we are visiting
    */
    virtual void VisitMoney(Money* money){}


};

#endif //SPARTYGNOME_VISITOR_H
