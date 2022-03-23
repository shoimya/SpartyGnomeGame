/**
 * @file VisitorMoney.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_VISITORMONEY_H
#define SPARTYGNOME_VISITORMONEY_H

#include "Visitor.h"
/// Visitor money
class VisitorMoney : public Visitor{
private:

public:
    ///  Money Visitor Constructor
    VisitorMoney();
    /// Money Visitor Destructor
    ~VisitorMoney();

    /**
     * Visit money
     * @param money The money to visit
     */
    void VisitMoney(Money* money) override;

};

#endif //SPARTYGNOME_VISITORMONEY_H
