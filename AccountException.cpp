#include "AccountException.h"

void DepositException::ShowException()
{
	cout << money << "는 올바른 입금액이 아닙니다."<<endl;
}

void WithdrawException::ShowException()
{
	cout << money << " 는 출금할 수 없습니다." << endl << "잔액: " << balance<<endl;
}
