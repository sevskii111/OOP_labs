#pragma once
#include "common.h"

class Money
{
private:
  int64_t rubels;
  uint8_t penny;

  static int64_t ConvertToPennies(const Money &money);

public:
  Money() : rubels(0), penny(0){};
  Money(int64_t penny);
  Money(int64_t rubels, uint8_t penny);

  friend Money operator+(Money const &a, Money const &b) noexcept;
  friend Money operator-(Money const &a, Money const &b) noexcept;
  friend Money operator*(Money const &a, int64_t const &b);
  friend Money operator/(Money const &a, int64_t const &b);

  friend bool operator<(Money const &a, Money const &b) noexcept;
  friend bool operator<=(Money const &a, Money const &b) noexcept;
  friend bool operator>(Money const &a, Money const &b) noexcept;
  friend bool operator>=(Money const &a, Money const &b) noexcept;
  friend bool operator==(Money const &a, Money const &b) noexcept;
  friend bool operator!=(Money const &a, Money const &b) noexcept;

  friend std::ostream &operator<<(std::ostream &os, const Money &money);
};