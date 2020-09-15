#pragma once
#include "common.h"
#include "money.h"

class Person
{
private:
  void *other;
  Money balance;

public:
  Person() {};
  Person(Money money);
  void set_balance(Money money);
  void set_balance(long long penny);
  void set_balance(long rubels, unsigned char penny);
  void increase_balance(Money money);
  void increase_balance(long long penny);
  void increase_balance(long rubels, unsigned char penny);
  void decrease_balance(Money money);
  void decrease_balance(long long penny);
  void decrease_balance(long rubels, unsigned char penny);
  Money get_balance();
  friend std::ostream &operator<<(std::ostream &os, const Person &person);
};