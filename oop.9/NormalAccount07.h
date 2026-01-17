#pragma once
#include"BankingCommonDecl07.h"
#include"Account07.h"

class NormalAccount :public Account
{
private:
    float baseRatio;
public:
    NormalAccount(int id, int _balance, const char* _cusName, float _baseRatio) :Account(id, _balance, _cusName), baseRatio(_baseRatio) {};
    int AddInterest(int money) const { return money * baseRatio; }
};