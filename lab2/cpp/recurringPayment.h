#pragma once
#include "payment.h"

class RecurringPayment : public Payment
{
public:
    RecurringPayment(Money _amount, uint _period) : Payment(_amount), period(_period), counter(0) {}
    RecurringPayment(Money _amount, uint _period, bool _isPositive) : Payment(_amount, _isPositive), period(_period), counter(0) {}
    Money getAmount() override;
    uint getPeriod();

protected:
    uint period;
    uint counter;
};