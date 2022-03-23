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
    ///  Money Visitor Constructor
    VisitorMoney();
    /// Money Visitor Destructor
    ~VisitorMoney();
    /// Visit Money function
    void VisitMoney(Money* money) override;

};

#endif //SPARTYGNOME_VISITORMONEY_H
