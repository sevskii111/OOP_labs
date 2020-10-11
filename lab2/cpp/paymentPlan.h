#pragma once
#include "recurringPayment.h"

class PaymentPlan : public RecurringPayment
{
public:
    PaymentPlan(Money _amount, uint _period, uint _parts) : RecurringPayment(_amount, _period), parts(_parts), partsPaid(0), paid(0){};
    Money getAmount() override;
    uint getParts();
    uint getPartsPaid();

protected:
    uint parts;
    uint partsPaid;
    Money paid;
};