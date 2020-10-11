#include "recurringPayment.h"

Money RecurringPayment::getAmount()
{
    counter++;
    if (counter % period == 0)
    {
        return amount;
    }
    else
    {
        return Money();
    }
}

uint RecurringPayment::getPeriod()
{
    return period;
}