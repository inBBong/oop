#pragma once
#include"BankingCommonDecl.h"
#include"Account.h"
#include"NormalAccount.h"

class HighCreditAccount :public NormalAccount
{
private:
    char Rank;
public:
    HighCreditAccount(int id, int _balance, const char* _cusName, float _baseRatio, char _Rank) :NormalAccount(id, _balance, _cusName, _baseRatio), Rank(_Rank) {};
    int AddInterest(int money) const
    {

        int interest = NormalAccount::AddInterest(money);
        switch (Rank)
        {
        case 'A':
            interest += 0.07 * money;
            break;
        case 'B':
            interest += 0.04 * money;
            break;
        case 'C':
            interest += 0.02 * money;
            break;
        default:
            cout << "잘못된 등급입니다." << endl;
            break;
        }
        return interest;
    }
};