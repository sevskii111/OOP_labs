#include "payment.h"
#include "paymentStatus.h"

class SinglePayment : Payment
{
public:
  SinglePayment(tm firstDate, Money totalAmount) : Payment(firstDate, totalAmount){};
  PaymentStatus getPaymentAmont(tm currentTime) override;
};