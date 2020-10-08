#include "payment.h"
#include "paymentStatus.h"

class RecurringPayment : Payment
{
public:
    RecurringPayment(tm firstDate, Money totalAmount, tm paymentPeriod)
        : Payment(firstDate, totalAmount), paymentPeriod(paymentPeriod){};
    PaymentStatus getPaymentAmont(tm currentTime) override;

private:
    tm paymentPeriod;
    int chunksNum;
    int chunksPaid;
};