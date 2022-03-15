/**
 * @file VisitorBackground.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_VISITORBACKGROUND_H
#define SPARTYGNOME_VISITORBACKGROUND_H

#include "Visitor.h"
class VisitorBackground : public Visitor{
private:

public:
    VisitorBackground();
    void VisitBackground(Background* background);

    ~VisitorBackground();

};

#endif //SPARTYGNOME_VISITORBACKGROUND_H
