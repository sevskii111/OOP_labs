#include "common.h"
#include "money.h"

Money::Money(int64_t penny)
{
  if (penny < 0)
  {
    throw std::runtime_error("You can't have negative money");
  }
  this->rubels = penny / 100;
  this->penny = penny % 100;
}

Money::Money(int64_t rubels, uint8_t penny)
{
  if (rubels < 0)
  {
    throw std::runtime_error("You can't have negative money");
  }
  this->rubels = rubels;
  this->penny = penny;
}

int64_t Money::ConvertToPennies(const Money &money)
{
  return money.rubels * 100 + money.penny;
}

bool operator<(const Money &a, const Money &b) noexcept
{
  if (a.rubels < b.rubels)
  {
    return true;
  }
  else if (a.rubels == b.rubels)
  {
    return a.penny < b.penny;
  }
  return false;
}

bool operator>(Money const &a, Money const &b) noexcept
{
  if (a.rubels > b.rubels)
  {
    return true;
  }
  else if (a.rubels == b.rubels)
  {
    return a.penny > b.penny;
  }
  return false;
}

bool operator==(Money const &a, Money const &b) noexcept
{
  return a.rubels == b.rubels && a.penny == b.penny;
}

bool operator!=(Money const &a, Money const &b) noexcept
{
  return !(a == b);
}

bool operator<=(const Money &a, const Money &b) noexcept
{
  return !(a > b);
}

bool operator>=(Money const &a, Money const &b) noexcept
{
  return !(a < b);
}

Money operator+(Money const &a, Money const &b) noexcept
{
  uint8_t penny_sum = a.penny + b.penny;
  return Money(a.rubels + b.rubels + penny_sum / 100, penny_sum % 100);
}

Money operator-(Money const &a, Money const &b) noexcept
{
  if (b.penny > a.penny)
  {
    return Money(a.rubels - b.rubels - 1, 100 + a.penny - b.penny);
  }
  else
  {
    return Money(a.rubels - b.rubels, a.penny - b.penny);
  }
}

Money operator*(Money const &a, int64_t const &b)
{
  if (b < 0)
  {
    throw std::runtime_error("You can't have negative money");
  }
  uint64_t penny = a.penny * b;
  return Money(a.rubels * b + penny / 100, penny % 100);
}

Money operator/(Money const &a, int64_t const &b)
{
  if (b == 0)
  {
    throw std::runtime_error("Division by 0");
  }
  if (b < 0)
  {
    throw std::runtime_error("You can't have negative money");
  }

  uint64_t penny_reminder = (a.rubels % b) * 100 / b;
  uint64_t penny = penny_reminder + a.penny / b;

  return Money(a.rubels / b + penny / 100, penny % 100);
}

std::ostream &operator<<(std::ostream &os, const Money &money)
{
  os << money.rubels << " p. " << (int)money.penny << " k.";
  return os;
}