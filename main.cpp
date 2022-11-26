#include <iostream>
#include "Transaction.h"
using namespace std;

class Account {
public:
    double balance = 0;
};

int main() {
    Account account; //checking
    Account account2; //savings

    cout <<"Enter balance: ";
    cin>>account.balance;

    cout << "What would you like to do?"<< endl << "1: Withdrawal\n2: Deposit\n3: Transfer" << endl;
    int input;
    cin>>input;

    if (input == 1) {
        double withdrawal_amount;
        cout <<"Enter withdrawal amount: "<< endl;
        cin>>withdrawal_amount;

        Transaction transaction;
        account.balance = transaction.withdrawal(account.balance, withdrawal_amount);

        if (account.balance) {
            cout << account.balance;
        }
    } else if (input == 2) {
        Transaction transaction;

        double deposit_amount;
        cout <<"Enter deposit amount: "<< endl;
        cin>>deposit_amount;

        cout <<"Which account are you depositing into?\n1: Checking\n2: Savings";

        int input;
        cin >> input;

        if (input == 1) {
            account.balance = transaction.deposit(account.balance, deposit_amount);
            cout << account.balance;
        } else {
            account2.balance = transaction.deposit(account2.balance, deposit_amount);
            cout << account2.balance;
        }

    } else {
        Transaction transaction;

        double transfer_amount;
        cout <<"Enter transfer amount: "<< endl;
        cin>>transfer_amount;

        cout<< "Enter what account you'd like to transfer to:\n1: Savings\n2: Checking" << endl;
        int input;
        int source_acc_balance;
        int transfer_acc_balance;
        //use withdraw and deposity functions to 'transfer' to the desired account


    }

    return 0;

}
