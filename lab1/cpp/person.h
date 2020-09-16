#pragma once
#include "common.h"
#include "money.h"

class Person
{
private:
  void *other;
  Money balance;

public:
  Person(){};
  Person(Money money);
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
};