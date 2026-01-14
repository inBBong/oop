/*
 * Banking System Ver 0.6
 * 작성자: 윤성우
 * 내  용:
 *      파일 분할, Account 함수 추가
 *      
 *      
 */

#include"BankingCommonDecl.h"
#include"AccountHandler.h"



int main(void)
{
    AccountHandler handler;
    int choice;

    while (1)
    {
        handler.ShowMenu();
        cout << "선택: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case MAKE:
            handler.MakeAccount();
            break;
        case DEPOSIT:
            handler.DepositMoney();
            break;
        case WITHDRAW:
            handler.WithdrawMoney();
            break;
        case INQUIRE:
            handler.ShowAllAccInfo();
            break;
        case EXIT:
            return 0;
        default:
            cout << "Illegal selection.." << endl;
        }
    }
    return 0;
}


