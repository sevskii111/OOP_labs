#include "common.h"
#include "person.h"

Person::Person(Money money)
{
  set_balance(money);
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