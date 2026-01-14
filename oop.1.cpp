/*
 * Banking System Ver 0.２
 * 작성자: 윤성우
 * 내  용: 
 */

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void);       // 메뉴출력
void MakeAccount(void);    // 계좌개설을 위한 함수
void DepositMoney(void);       // 입    금
void WithdrawMoney(void);      // 출    금
void ShowAllAccInfo(void);     // 잔액조회

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account
{
private:
	int accID;      // 계좌번호
	int balance;    // 잔    액
	char* cusName;   // 고객이름
public:
	Account(int id,int _balance,char* _cusName):accID(id),balance(_balance)
	{
		int nameLen = strlen(_cusName) + 1;
		cusName = new char[nameLen];
		strcpy(cusName, _cusName);
	}
	void SetBalance(int bal) { balance = bal; }
	void SetAccID(int id) { accID= id; }
	void SetCusName(char* _cusName) { 
		int nameLen = strlen(_cusName) + 1;
		cusName = new char[nameLen];
		strcpy(cusName, _cusName);
	}
	int GetID() { return accID; }
	int GetBalance() { return balance; }
	char* GetCusName() { return cusName; }
} ;

Account *accArr[100];   // Account 저장을 위한 배열
int accNum = 0;        // 저장된 Account 수

int main(void)
{
	int choice;

	while (1)
	{
		ShowMenu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}

void ShowMenu(void)
{
	cout << "-----Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입    금" << endl;
	cout << "3. 출    금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "이  름: ";	cin >> name;
	cout << "입금액: ";	cin >> balance;
	cout << endl;
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetID() == id)
		{
			cout << "이미 개설된 계좌입니다." << endl;
			return;
		}
	}
	accArr[accNum++] = new Account(id, balance, name);
}

void DepositMoney(void)
{
	int money;
	int id;
	cout << "[입    금]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "입금액: ";	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetID() == id)
		{
			accArr[i]->SetBalance(accArr[i]->GetBalance()+money);
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[출    금]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "출금액: ";	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetID() == id)
		{
			if (accArr[i]->GetBalance()< money)
			{
				cout << "잔액부족" << endl << endl;
				return;
			}

			accArr[i]->SetBalance(accArr[i]->GetBalance() - money);
			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void ShowAllAccInfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
		cout << "계좌ID: " << accArr[i]->GetID()<< endl;
		cout << "이  름: " << accArr[i]->GetCusName() << endl;
		cout << "잔  액: " << accArr[i]->GetBalance()<< endl << endl;
	}
}