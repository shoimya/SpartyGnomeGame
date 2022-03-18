/**
 * @file VisitorStanley.h
 * @author Connor
 *
 *
 */

#ifndef SPARTYGNOME_VISITORSTANLEY_H
#define SPARTYGNOME_VISITORSTANLEY_H

#include "Stanley.h"

class VisitorStanley : public Visitor{
private:

public:
    VisitorStanley();
    ~VisitorStanley();
    void VisitStanley(Villain* villain) override;
};

#endif //SPARTYGNOME_VISITORSTANLEY_H
