#pragma once
#include "common.h"

class Money
{
private:
  long rubels;
  unsigned char penny;

  static long long ConvertToPennies(const Money &money);

public:
  Money() : rubels(0), penny(0) {}
  Money(long long penny);
  Money(long rubels, unsigned char penny) : Money(rubels * 100 + penny){};

  std::string to_string();

  friend Money operator+(Money const &a, Money const &b);
  friend Money operator-(Money const &a, Money const &b);
  friend Money operator*(Money const &a, Money const &b);
  friend Money operator/(Money const &a, Money const &b);

  friend bool operator<(Money const &a, Money const &b);
  friend bool operator<=(Money const &a, Money const &b);
  friend bool operator>(Money const &a, Money const &b);
  friend bool operator>=(Money const &a, Money const &b);
  friend bool operator==(Money const &a, Money const &b);
  friend bool operator!=(Money const &a, Money const &b);
};