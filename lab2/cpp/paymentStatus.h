#include "common.h"
#include "money.h"

class PaymentStatus
{
public:
    PaymentStatus(Money amount) : amount(amount), isLast(true), nextDueDate(){};
    PaymentStatus(Money amount, tm nextDueDate) : amount(amount), nextDueDate(nextDueDate), isLast(false){};
    const Money amount;
    const bool isLast;
    const tm nextDueDate;
};