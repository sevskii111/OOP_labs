#include "Money.h"

Money::Money(long long penny)
{
  this->rubels = penny / 100;
  this->penny = penny % 100;
}

long long Money::ConvertToPennies(const Money &money)
{
  return money.rubels * 100 + money.penny;
}

std::string Money::to_string()
{
  return rubels + "." + penny;
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

Money operator*(Money const &a, Money const &b)
{
  return Money(Money::ConvertToPennies(a) * Money::ConvertToPennies(b));
}

Money operator/(Money const &a, Money const &b)
{
  return Money(Money::ConvertToPennies(a) / Money::ConvertToPennies(b));
}
