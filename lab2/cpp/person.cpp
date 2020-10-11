#include "common.h"
#include "person.h"

Person::Person()
{
  recurringPaymentsCounter = 0;
}

Person::Person(Money money) : Person()
{
  set_balance(money);
}

Person::~Person()
{
  for (const std::pair<int, RecurringPayment *> &payment : recurringPayments)
  {
    delete payment.second;
  }
}

void Person::set_balance(Money money)
{
  this->balance = money;
}

void Person::set_balance(int64_t penny)
{
  this->balance = Money(penny);
}

void Person::set_balance(int64_t rubels, uint8_t penny)
{
  this->balance = Money(rubels, penny);
}

void Person::increase_balance(Money money)
{
  this->balance = this->balance + money;
}

void Person::increase_balance(int64_t penny)
{
  this->balance = this->balance + Money(penny);
}

void Person::increase_balance(int64_t rubels, uint8_t penny)
{
  this->balance = this->balance + Money(rubels, penny);
}

void Person::decrease_balance(Money money)
{
  this->balance = this->balance - money;
}

void Person::decrease_balance(int64_t penny)
{
  this->balance = this->balance - Money(penny);
}

void Person::decrease_balance(int64_t rubels, uint8_t penny)
{
  this->balance = this->balance - Money(rubels, penny);
}

Money Person::get_balance()
{
  return this->balance;
}

std::ostream &operator<<(std::ostream &os, const Person &person)
{
  os << "This person has " << person.balance;
  return os;
}

void Person::pay(Payment *payment)
{
  Money amount = payment->getAmount();
  if (payment->getIsPositive())
  {
    balance = balance + amount;
  }
  else
  {
    balance = balance - amount;
  }
}

uint Person::addRecurringPayment(RecurringPayment *payment)
{
  recurringPayments.emplace(recurringPaymentsCounter, payment);
  return recurringPaymentsCounter++;
}

void Person::removeRecrringPayment(int paymentId)
{
  delete recurringPayments[paymentId];
  recurringPayments.erase(paymentId);
}

void Person::liveADay()
{
  for (const std::pair<int, RecurringPayment *> &payment : recurringPayments)
  {
    pay(payment.second);
  }
}