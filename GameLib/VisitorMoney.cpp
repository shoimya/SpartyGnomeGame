/**
 * @file VisitorMoney.cpp
 * @author Haoxiang Zhang
 */

#include "pch.h"
#include "VisitorMoney.h"
#include "Stadium.h"
#include "Money.h"

VisitorMoney::VisitorMoney()
{


}

VisitorMoney::~VisitorMoney()
{

}

void VisitorMoney::VisitMoney(Money* money)
{
    auto stadium = money->GetStadium();
    int value = stadium->GetValue();
    value += money->GetValue();
    stadium->SetValue(value);
}
