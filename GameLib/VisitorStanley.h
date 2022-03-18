/**
 * @file VisitorStanley.h
 * @author Connor
 *
 *
 */

#ifndef SPARTYGNOME_VISITORSTANLEY_H
#define SPARTYGNOME_VISITORSTANLEY_H

#include "Stadium.h"
#include "Stanley.h"

class VisitorStanley : public Visitor{
private:

public:
    VisitorStanley();
    ~VisitorStanley();
    void VisitStanley(Stanley* stanley) override;
};

#endif //SPARTYGNOME_VISITORSTANLEY_H
