#include "common.h"
#include "money.h"
#include "person.h"
#include "singlePayment.h"
#include "recurringPayment.h"
#include "paymentPlan.h"
#include "wage.h"

void testPayments()
{
  Person person(Money(1000, 0));
  std::cout << person.get_balance() << std::endl;
  SinglePayment *oneRubelPayment = new SinglePayment(Money(1, 0));
  person.pay(oneRubelPayment);
  std::cout << person.get_balance() << std::endl;
  person.pay(oneRubelPayment);
  std::cout << person.get_balance() << std::endl;
  RecurringPayment *netflixSubscription = new RecurringPayment(Money(300, 0), 30);
  //Первая оплата подпски идёт не в день её оформления, а через period дней
  uint sid = person.addRecurringPayment(netflixSubscription);
  person.liveADay();
  std::cout << person.get_balance() << std::endl;
  for (int i = 0; i < 29; i++)
  {
    person.liveADay();
  }
  std::cout << person.get_balance() << std::endl;
  for (int i = 0; i < 30; i++)
  {
    person.liveADay();
  }
  std::cout << person.get_balance() << std::endl;
  person.removeRecrringPayment(sid);
  for (int i = 0; i < 30; i++)
  {
    person.liveADay();
  }
  std::cout << person.get_balance() << std::endl;
  RecurringPayment *wage = new Wage(Money(1000, 0), 30);
  sid = person.addRecurringPayment(wage);
  for (int i = 0; i < 12; i++)
  {
    for (int i = 0; i < 30; i++)
    {
      person.liveADay();
    }
    std::cout << person.get_balance() << std::endl;
  }
  person.removeRecrringPayment(sid);
  PaymentPlan *loan = new PaymentPlan(Money(10000, 0), 30, 12);
  sid = person.addRecurringPayment(loan);
  for (int i = 0; i < 12; i++)
  {
    for (int i = 0; i < 30; i++)
    {
      person.liveADay();
    }
    std::cout << person.get_balance() << std::endl;
  }
  person.removeRecrringPayment(sid);
}

int main()
{
  testPayments();
}