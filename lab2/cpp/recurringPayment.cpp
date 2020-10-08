#include "common.h"
#include "recurringPayment.h"

PaymentStatus RecurringPayment::getPaymentAmont(tm currentTime)
{
    if (((lastTimeGotPayed + paymentPeriod) > currentTime) || (lastTimeGotPayed < firstDate && firstDate > currentTime))
    {
        if (chunksPaid >= chunksNum)
        {
            return PaymentStatus(Money(0));
        }
        chunksPaid++;
        Money amount(totalAmount / chunksNum);
        lastTimeGotPayed = lastTimeGotPayed + paymentPeriod;
        while ((this->lastTimeGotPayed + paymentPeriod) > currentTime && chunksPaid < chunksNum)
        {
            amount = amount + Money(totalAmount / chunksNum);
            lastTimeGotPayed = lastTimeGotPayed + paymentPeriod;
            chunksPaid++;
        }
        if (chunksPaid >= chunksNum)
        {
            return PaymentStatus(amount);
        }
        else
        {
            return PaymentStatus(amount, lastTimeGotPayed + paymentPeriod);
        }
    }
    else if (lastTimeGotPayed < firstDate)
    {
        return PaymentStatus(Money(0), firstDate);
    }
    else
    {
        return PaymentStatus(Money(0), lastTimeGotPayed + paymentPeriod);
    }
}