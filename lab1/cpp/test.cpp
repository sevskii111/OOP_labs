#include "common.h"
#include "money.h"
#include "person.h"

void testMoney()
{
  Money money_zero = Money(0);
  std::cout << money_zero << std::endl;

  Money money_five_rubels = Money(5, 0);
  std::cout << money_five_rubels << std::endl;

  Money money_five_rubels_fifty_penny = Money(5, 50);
  std::cout << money_five_rubels_fifty_penny << std::endl;

  Money money_ten_rubles_fifty_penny = Money(1050);
  std::cout << money_ten_rubles_fifty_penny << std::endl;

  Money tmp;

  if (money_ten_rubles_fifty_penny > money_five_rubels)
  {
    std::cout << "(" << money_ten_rubles_fifty_penny << ") > (" << money_five_rubels << ")" << std::endl;
  }
  else
  {
    std::cout << "(" << money_ten_rubles_fifty_penny << ") !> (" << money_five_rubels << ")" << std::endl;
  }

  if (money_zero > money_five_rubels)
  {
    std::cout << "(" << money_zero << ") > (" << money_five_rubels << ")" << std::endl;
  }
  else
  {
    std::cout << "(" << money_zero << ") !> (" << money_five_rubels << ")" << std::endl;
  }

  if ((tmp = Money(500)) == money_five_rubels)
  {
    std::cout << "(" << tmp << ") == (" << money_five_rubels << ")" << std::endl;
  }
  else
  {
    std::cout << "(" << tmp << ") != (" << money_five_rubels << ")" << std::endl;
  }

  if (money_zero == money_five_rubels)
  {
    std::cout << "(" << money_zero << ") == (" << money_five_rubels << ")" << std::endl;
  }
  else
  {
    std::cout << "(" << money_zero << ") != (" << money_five_rubels << ")" << std::endl;
  }

  if (money_zero < money_five_rubels)
  {
    std::cout << "(" << money_zero << ") < (" << money_five_rubels << ")" << std::endl;
  }
  else
  {
    std::cout << "(" << money_zero << ") !< (" << money_five_rubels << ")" << std::endl;
  }

  if (money_ten_rubles_fifty_penny < money_five_rubels)
  {
    std::cout << "(" << money_ten_rubles_fifty_penny << ") < (" << money_five_rubels << ")" << std::endl;
  }
  else
  {
    std::cout << "(" << money_ten_rubles_fifty_penny << ") !< (" << money_five_rubels << ")" << std::endl;
  }

  std::cout << "(" << money_five_rubels_fifty_penny << ") + (" << money_ten_rubles_fifty_penny << ") = (" << (money_five_rubels_fifty_penny + money_ten_rubles_fifty_penny) << ")" << std::endl;
  try
  {
    std::cout << "(" << money_five_rubels << ") - (" << money_five_rubels_fifty_penny << ") = (" << (money_five_rubels - money_five_rubels_fifty_penny) << ")" << std::endl;
  }
  catch (std::string &caught)
  {
    std::cout << caught << std::endl;
  }
  tmp = Money(10, 0);
  std::cout << "(" << tmp << ") - (" << money_five_rubels_fifty_penny << ") = (" << (tmp - money_five_rubels_fifty_penny) << ")" << std::endl;

  std::cout << "(" << money_five_rubels_fifty_penny << ") * 2 = (" << (money_five_rubels_fifty_penny * 2) << ")" << std::endl;
  try
  {
    std::cout << "(" << money_five_rubels_fifty_penny << ") * -2 = (" << (money_five_rubels_fifty_penny * -2) << ")" << std::endl;
  }
  catch (std::string &caught)
  {
    std::cout << caught << std::endl;
  }

  std::cout << "(" << money_five_rubels_fifty_penny << ") / 2 = (" << (money_five_rubels_fifty_penny / 2) << ")" << std::endl;

  try
  {
    std::cout << "(" << money_five_rubels_fifty_penny << ") / 0 = (" << (money_five_rubels_fifty_penny / 0) << ")" << std::endl;
  }
  catch (std::string &caught)
  {
    std::cout << caught << std::endl;
  }
}

void testPerson()
{
  Person person1 = Person();
  std::cout << person1 << std::endl;
  Person person2 = Person(Money(100521));
  std::cout << person2 << std::endl;
  std::cout << "Increase 10 k." << std::endl;
  person2.increase_balance(Money(10));
  std::cout << person2 << std::endl;
  std::cout << "Decrease 35 k." << std::endl;
  person2.decrease_balance(Money(35));
  std::cout << person2 << std::endl;
  std::cout << "Set 12345 k." << std::endl;
  person2.set_balance(12345);
  std::cout << person2 << std::endl;
}

int main()
{
  std::cout << "Money test:" << std::endl;
  testMoney();
  std::cout << "Person test:" << std::endl;
  testPerson();
}