#include "paymentPlan.h"

Money PaymentPlan::getAmount()
{
    Money amount = RecurringPayment::getAmount();
    if (amount == Money(0))
        return Money();

    if (partsPaid < parts - 1)
    {
        amount = amount / parts;
        paid = paid + amount;
        partsPaid++;
        return amount;
    }
    else if (partsPaid < parts)
    {
        amount = amount - paid;
        paid = paid + amount;
        partsPaid++;
        return amount;
    }
    else
    {
        return Money();
    }
}

uint PaymentPlan::getParts()
{
    return parts;
}

uint PaymentPlan::getPartsPaid()
{
    return partsPaid;
}