#pragma once
#include"BankingCommonDecl07.h"
#include"String.h"
class Account
{
private:
    int accID;      // 계좌번호
    int balance;    // 잔    액
    String cusName;   // 고객이름
public:
    Account(int id, int _balance, const char* _cusName) :accID(id), balance(_balance),cusName(_cusName)
    {             
    }
    Account(const Account& acc1) :accID(acc1.accID), balance(acc1.balance),cusName(acc1.cusName) //복사생성자
    {       
    }
    Account& operator=(const Account&ac)
    {
        accID=ac.accID;
        balance = ac.balance;
        cusName = ac.cusName;       
    }
    void Deposit(int money);
    void WithDraw(int money);
    void SetBalance(int bal) { balance = bal; }
    void SetAccID(int id) { accID = id; }
    void SetCusName(const char* _cusName) {        
        cusName = _cusName;
    }
    int GetID() const { return accID; }
    int GetBalance() const { return balance; }
    const String GetCusName() const { return cusName; }

    virtual int AddInterest(int money) const = 0;
    ~Account()
    {
        cusName.~String();
    }
};