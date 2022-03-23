/**
 * @file VisitorDoor.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_VISITORDOOR_H
#define SPARTYGNOME_VISITORDOOR_H

#include "Visitor.h"
/// Visitor of door
class VisitorDoor : public Visitor{
private:

public:
    /// Constructor
    VisitorDoor();
/**
 * Visit door
 * @param door The door to visit
 */
    void VisitDoor(Door* door) override;
    /// Destructor
    ~VisitorDoor();


};

#endif //SPARTYGNOME_VISITORDOOR_H
