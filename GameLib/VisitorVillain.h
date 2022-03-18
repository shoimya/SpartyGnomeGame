/**
 * @file VisitorVillain.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_VISITORVILLAIN_H
#define SPARTYGNOME_VISITORVILLAIN_H

#include "Visitor.h"
class VisitorVillain : public Visitor{
private:

public:
    VisitorVillain();
    void VisitVillain(Villain* villain) override;
    ~VisitorVillain();

};

#endif //SPARTYGNOME_VISITORVILLAIN_H
