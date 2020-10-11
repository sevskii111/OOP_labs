#include "wage.h"

Money Wage::getAmount()
{
    Money amount;
    if ((timesPaid + 1) % 12 == 0)
    {
        amount = RecurringPayment::getAmount() * 2;
    }
    else
    {
        amount = RecurringPayment::getAmount();
    }
    if (amount != Money(0))
    {
        timesPaid++;
    }

    return amount;
}

uint Wage::getTimesPaid()
{
    return timesPaid;
}
