#include"AccountHandler07.h"
#include"HighCreditAccount07.h"

void AccountHandler::ShowMenu(void)
{
    cout << "-----Menu------" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입    금" << endl;
    cout << "3. 출    금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccount(void)
{
    int id;
    char name[NAME_LEN];
    int balance;
    int AccountType;
    float baseRatio;
    char Rank;
    cout << "[계좌개설]" << endl;
    cout << "1. 보통예금계좌" << endl << "2. 신용신뢰계좌" << endl << "계좌종류: ";   cin >> AccountType;
    cout << "계좌ID: ";   cin >> id;
    cout << "이  름: ";   cin >> name;
    cout << "입금액: ";   cin >> balance;
    cout << "기본이율: "; cin >> baseRatio;
    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i]->GetID() == id)
        {
            cout << "이미 개설된 계좌입니다." << endl;
            return;
        }
    }
    if (AccountType == 2)
    {
        cout << "**신용등급(A/B/C): "; cin >> Rank;
        accArr[accNum++] = new HighCreditAccount(id, balance, name, baseRatio, Rank);
    }
    else if (AccountType == 1)
    {
        accArr[accNum++] = new NormalAccount(id, balance, name, baseRatio);
    }
    else
    {
        cout << "잘못된 계좌 종류입니다." << endl;
        return;
    }

    cout << endl;
    //accArr[accNum++] = new Account(id, balance, name);
}

void AccountHandler::DepositMoney(void)
{
	int money;
	int id;
	cout << "[입    금]" << endl;
	cout << "계좌ID: ";   cin >> id;
	while (1)
	{
		cout << "입금액: ";   cin >> money;
		try 
        {
			for (int i = 0; i < accNum; i++)
			{
				if (accArr[i]->GetID() == id)
				{

					accArr[i]->Deposit(money);
					cout << "입금완료" << endl << endl;
					return;

				}
			}
			cout << "유효하지 않은 ID 입니다." << endl << endl;
			break;
		}
		catch (DepositException& dex)
		{
			dex.ShowException();
			cout << "입금액을 다시 입력하세요." << endl;
		}
	}
}

void AccountHandler::WithdrawMoney(void)
{
    int money;
    int id;
    cout << "[출    금]" << endl;
    cout << "계좌ID: ";   cin >> id;
    while(1)
    {
		cout << "출금액: ";   cin >> money;
		try
		{
			for (int i = 0; i < accNum; i++)
			{
				if (accArr[i]->GetID() == id)
				{

					accArr[i]->WithDraw(money);
					cout << "출금완료" << endl << endl;
					return;

				}
			}
			cout << "유효하지 않은 ID 입니다." << endl << endl;
            break;
		}
		catch (WithdrawException& wex)
		{
			wex.ShowException();
			cout << "출금액을 다시 입력하세요." << endl;
		}
	}
}

void AccountHandler::ShowAllAccInfo(void)
{
    for (int i = 0; i < accNum; i++)
    {
        cout << "계좌ID: " << accArr[i]->GetID() << endl;
        cout << "이  름: " << accArr[i]->GetCusName() << endl;
        cout << "잔  액: " << accArr[i]->GetBalance() << endl << endl;
    }
}