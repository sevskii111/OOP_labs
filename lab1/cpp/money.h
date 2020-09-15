#pragma once
#include "common.h"

class Money
{
private:
  long rubels;
  unsigned char penny;

  static long long ConvertToPennies(const Money &money);

public:
  Money() : rubels(0), penny(0){};
  Money(long long penny);
  Money(long rubels, unsigned char penny) : Money(rubels * 100 + penny){};

  friend Money operator+(Money const &a, Money const &b);
  friend Money operator-(Money const &a, Money const &b);
  friend Money operator*(Money const &a, long const &b);
  friend Money operator/(Money const &a, long const &b);

  friend bool operator<(Money const &a, Money const &b);
  friend bool operator<=(Money const &a, Money const &b);
  friend bool operator>(Money const &a, Money const &b);
  friend bool operator>=(Money const &a, Money const &b);
  friend bool operator==(Money const &a, Money const &b);
  friend bool operator!=(Money const &a, Money const &b);

  friend std::ostream &operator<<(std::ostream &os, const Money &money);
};