#pragma once
#include "common.h"
#include "money.h"

class Payment
{
public:
  Payment(tm firstDate, Money totalAmount) : firstDate(firstDate), totalAmount(totalAmount){};
  virtual PaymentStatus getPaymentAmont(tm currentTime);

protected:
  tm firstDate;
  tm lastTimeGotPayed;
  Money totalAmount;
};