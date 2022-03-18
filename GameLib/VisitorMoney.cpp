/**
 * @file VisitorMoney.cpp
 * @author Haoxiang Zhang
 */

#include "pch.h"
#include "Stadium.h"
#include "Money.h"
#include "VisitorMoney.h"

VisitorMoney::VisitorMoney()
{

}

VisitorMoney::~VisitorMoney()
{

}

void VisitorMoney::VisitMoney(Money* money)
{
    money->SetValue(money->GetValue()*1.1);
}
