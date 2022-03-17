/**
 * @file VisitorMoney.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_VISITORMONEY_H
#define SPARTYGNOME_VISITORMONEY_H

#include "Visitor.h"
class VisitorMoney : public Visitor{
private:

public:
    VisitorMoney();
    void VisitMoney(Money* money) override;
    ~VisitorMoney();

};

#endif //SPARTYGNOME_VISITORMONEY_H
