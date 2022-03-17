/**
 * @file VisitorDoor.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_VISITORDOOR_H
#define SPARTYGNOME_VISITORDOOR_H

#include "Visitor.h"
class VisitorDoor : public Visitor{
private:

public:
    VisitorDoor();
    void VisitDoor(Door* door) override;
    ~VisitorDoor();


};

#endif //SPARTYGNOME_VISITORDOOR_H
