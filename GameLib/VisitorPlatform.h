/**
 * @file VisitorPlatform.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_VISITORPLATFORM_H
#define SPARTYGNOME_VISITORPLATFORM_H

#include "Visitor.h"

class ItemPlatform;

class VisitorPlatform : public Visitor{
private:

public:
    VisitorPlatform();
    void VisitItemPlatform(ItemPlatform* platform) override;
    ~VisitorPlatform();


};

#endif //SPARTYGNOME_VISITORPLATFORM_H
