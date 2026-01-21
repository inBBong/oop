#include "Account07.h"

void Account::Deposit(int money) throw(DepositException)
{
	DepositException dex(money);
	if (money < 0)
		throw DepositException(dex);
	balance += money + AddInterest(money);
}

void Account::WithDraw(int money) throw(WithdrawException)
{
	WithdrawException wex(money, balance);
	if (balance < money)
		throw WithdrawException(wex);
	balance -= money;
}
