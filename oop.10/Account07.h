#pragma once
#include"BankingCommonDecl07.h"

class Account
{
private:
    int accID;      // 계좌번호
    int balance;    // 잔    액
    char* cusName;   // 고객이름
public:
    Account(int id, int _balance, const char* _cusName) :accID(id), balance(_balance)
    {
        int nameLen = strlen(_cusName) + 1;
        cusName = new char[nameLen];
        strcpy(cusName, _cusName);
    }
    Account(const Account& acc1) :accID(acc1.accID), balance(acc1.balance) //복사생성자
    {
        int nameLen = strlen(acc1.cusName) + 1;
        cusName = new char[nameLen];
        strcpy(cusName, acc1.cusName);
    }
    Account& operator=(const Account&ac)
    {
        accID=ac.accID;
        balance = ac.balance;
        int nameLen = strlen(ac.cusName) + 1;
        cusName = new char[nameLen];
        strcpy(cusName, ac.cusName);
    }
    void Deposit(int money);
    void WithDraw(int money);
    void SetBalance(int bal) { balance = bal; }
    void SetAccID(int id) { accID = id; }
    void SetCusName(const char* _cusName) {
        delete[] cusName;
        int nameLen = strlen(_cusName) + 1;
        cusName = new char[nameLen];
        strcpy(cusName, _cusName);
    }
    int GetID() const { return accID; }
    int GetBalance() const { return balance; }
    const char* GetCusName() const { return cusName; }

    virtual int AddInterest(int money) const = 0;
    ~Account()
    {
        delete[] cusName;
    }
};