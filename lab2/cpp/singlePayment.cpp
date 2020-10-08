#include "singlePayment.h"

PaymentStatus SinglePayment::getPaymentAmont(tm currentTime)
{
  if (lastTimeGotPayed < currentTime && currentTime > firstDate)
  {
    std::time_t t = std::time(0);
    lastTimeGotPayed = *std::localtime(&t);
    return PaymentStatus(totalAmount);
  }
  else if (lastTimeGotPayed > currentTime)
  {
    return PaymentStatus(Money(0));
  }
  else
  {
    return PaymentStatus(Money(0), firstDate);
  }
}