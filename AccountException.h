#pragma once
#include"BankingCommonDecl07.h"

class AccountException
{
private:
public:
	virtual void ShowException() = 0;
};
class DepositException :public AccountException //음수 입금 했을때 예외
{
private:
	int money;
public:
	DepositException(int _money):money(_money){}
	void ShowException();
};

class WithdrawException :public AccountException //잔액부족떴을때 예외
{
private:
	int money;
	int balance;
public:
	WithdrawException(int _money,int _balance):money(_money),balance(_balance){}
	void ShowException();
};