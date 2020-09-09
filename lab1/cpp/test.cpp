#include "common.h"
#include "iostream"
#include "money.h"

bool testMoney()
{
  bool pass = true;
  Money money_zero = Money();
  std::cout << money_zero.to_string();
}

int main()
{
  testMoney();
}