#include "recurringPayment.h"

class Wage : public RecurringPayment
{
public:
    Wage(Money _amount, uint _period) : RecurringPayment(_amount, _period, true), timesPaid(0){};
    Money getAmount() override;
    uint getTimesPaid();
    uint getPartsPaid();

protected:
    uint timesPaid;
};