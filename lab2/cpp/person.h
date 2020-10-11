#pragma once
#include "common.h"
#include "money.h"
#include "payment.h"
#include "singlePayment.h"
#include "recurringPayment.h"

class Person
{
private:
  void *other;
  Money balance;
  std::map<int, RecurringPayment *> recurringPayments;
  uint recurringPaymentsCounter;

public:
  Person();
  Person(Money money);
  ~Person();
  void set_balance(Money money);
  void set_balance(int64_t penny);
  void set_balance(int64_t rubels, uint8_t penny);
  void increase_balance(Money money);
  void increase_balance(int64_t penny);
  void increase_balance(int64_t rubels, uint8_t penny);
  void decrease_balance(Money money);
  void decrease_balance(int64_t penny);
  void decrease_balance(int64_t rubels, uint8_t penny);
  Money get_balance();
  friend std::ostream &operator<<(std::ostream &os, const Person &person);

  void pay(Payment *payment);
  uint addRecurringPayment(RecurringPayment *payment);
  void removeRecrringPayment(int paymentId);
  void liveADay();
};