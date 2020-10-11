#pragma once
#include "common.h"
#include "money.h"

class Payment
{
public:
    Payment(Money _amount) : amount(_amount), isPositive(false) {}
    Payment(Money _amount, bool _isPostitive) : amount(_amount), isPositive(_isPostitive) {}
    virtual Money getAmount();
    bool getIsPositive();

protected:
    Money amount;
    bool isPositive;
};