/*
 * Banking System Ver 0.6
 * 작성자: 윤성우
 * 내  용:
 *      AccountHandler -> BoundCheckPointPtrArray 배열 클래스로 대체
 *      대입연산자 정의
 *      
 *      
 */

#include"BankingCommonDecl07.h"
#include"AccountHandler07.h"
#include"AccountArray.h"


int main(void)
{
    AccountHandler handler;
   // BoundCheckAccountPtrArray arr(5);
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


