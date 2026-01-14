#include "Account.h"

void Account::Deposit(int money)
{
	balance += money;
}

void Account::WithDraw(int money)
{
	balance -= money;
}
