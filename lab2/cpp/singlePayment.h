#pragma once
#include "payment.h"

class SinglePayment : public Payment
{
public:
    SinglePayment(Money _amount) : Payment(_amount){};
    SinglePayment(Money _amount, bool _isPositive) : Payment(_amount, _isPositive){};
    Money getAmount() override;
};