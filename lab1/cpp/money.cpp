#include "common.h"
#include "Money.h"

Money::Money(long long penny)
{
  if (penny < 0) 
  {
    throw std::string("You can't have negative money");
  }
  this->rubels = penny / 100;
  this->penny = penny % 100;
}

long long Money::ConvertToPennies(const Money &money)
{
  return money.rubels * 100 + money.penny;
}

bool operator<(const Money &a, const Money &b)
{
  return Money::ConvertToPennies(a) < Money::ConvertToPennies(b);
}

bool operator>(Money const &a, Money const &b)
{
  return Money::ConvertToPennies(a) > Money::ConvertToPennies(b);
}

bool operator==(Money const &a, Money const &b)
{
  return Money::ConvertToPennies(a) == Money::ConvertToPennies(b);
}

bool operator!=(Money const &a, Money const &b)
{
  return !(a == b);
}

bool operator<=(const Money &a, const Money &b)
{
  return !(a > b);
}

bool operator>=(Money const &a, Money const &b)
{
  return !(a < b);
}

Money operator+(Money const &a, Money const &b)
{
  return Money(Money::ConvertToPennies(a) + Money::ConvertToPennies(b));
}

Money operator-(Money const &a, Money const &b)
{
  return Money(Money::ConvertToPennies(a) - Money::ConvertToPennies(b));
}

Money operator*(Money const &a, long const &b)
{
  return Money(Money::ConvertToPennies(a) * b);
}

Money operator/(Money const &a, long const &b)
{
  if (b == 0)
  {
    throw std::string("Division by 0");
  }
  return Money(Money::ConvertToPennies(a) / b);
}


std::ostream& operator<<(std::ostream& os, const Money& money)
{
  os << money.rubels << " p. " << (int)money.penny << " k.";
  return os;
}