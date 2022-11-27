#include <iostream>
#include "Transaction.h"
using namespace std;

class Account {
public:
    double balance = 0;
};

class loginFunction{
public:
    string userNameAttempt;
    string passWordAttempt;

    // constructor
    loginFunction(){
        accessGranted = false;
    }

    //function
    void login(){
        cout << "Please enter your password and user.\nUsername: ";
        cin >>  userNameAttempt;
        if(userNameAttempt==userName){
            cout << "Password: ";
            cin >> passWordAttempt;
            if(passWordAttempt==passWord){
                cout << "Login successful!\n\n";
            }
        }
    }

private:
    string passWord = "password";
    string userName = "user@email.com";
    bool accessGranted;
};

int savingsAcc(){

    string input;

    cout << "Would you like to create a savings account (y/n): " << endl;
    cin >> input;
    if(input.compare("y"))
    {
        return 0;
    }
    else if(input.compare("n"))
    {
        cout << "Account created!\n\n" << endl;

        return 1;
    }
    return 0;
}

int main() {
    //handle logins
    loginFunction loginFunctionObj;
    loginFunctionObj.login();

    //account creation
    Account checking;
    Account savings;

    bool savings_created = false;
    if (savingsAcc()) {
        savings_created = true;
    } else {
        cout << "Since you don't have a savings account, any actions will be performed against your checking."<< endl;
    }

    int input;
    if (savings_created) {
        cout << "Enter balance of checking: ";
        cin >> checking.balance;
        cout << "\nEnter balance of savings: ";
        cin >> savings.balance;

        cout << "\nWhat would you like to do?"<< endl << "---1: Withdrawal\n---2: Deposit\n---3: Transfer\n---4: Display Account Balances" << endl;
    } else {
        cout << "Enter balance of checking: ";
        cin >> checking.balance;

        cout << "What would you like to do?"<< endl << "---1: Withdrawal\n---2: Deposit\n" << endl;
    }
    cin>>input;

    if (input == 1) {
        double withdrawal_amount;
        Transaction transaction;

        if (savings_created) {
            int input;
            cout << "\nWhat account would you like to withdraw from?" << endl << "---1: Checking\n---2: Deposit\n"<<endl;
            cin>>input;

            if (input == 1) {
                cout <<"Enter withdrawal amount: ";
                cin>>withdrawal_amount;
                checking.balance = transaction.withdrawal(checking.balance, withdrawal_amount);

                if (checking.balance) {
                    cout <<"Withdrawal complete!\n";
                    cout << "---Checking: $"<<checking.balance<<endl;
                }
            } else {
                cout <<"Enter withdrawal amount: ";
                cin>>withdrawal_amount;
                savings.balance = transaction.withdrawal(savings.balance, withdrawal_amount);

                if (savings.balance) {
                    cout <<"Withdrawal complete!\n";
                    cout << "---Savings: $"<<savings.balance<<endl;
                }
            }
        } else {
            cout <<"Enter withdrawal amount: ";
            cin>>withdrawal_amount;
            checking.balance = transaction.withdrawal(checking.balance, withdrawal_amount);

            if (checking.balance) {
                cout <<"Withdrawal complete!\n";
                cout << "---Checking: $"<<checking.balance<<endl;
            }
        }
    } else if (input == 2) {
        Transaction transaction;
        double deposit_amount;

        cout <<"Enter deposit amount: ";
        cin>>deposit_amount;

        if (savings_created) {
            cout <<"\nWhich account are you depositing into?\n---1: Checking\n---2: Savings\n";

            int input;
            cin >> input;

            if (input == 1) {
                checking.balance = transaction.deposit(checking.balance, deposit_amount);

                cout <<"Deposit complete!\n";
                cout << "---Checking: $"<<checking.balance<<endl;
            } else {
                savings.balance = transaction.deposit(savings.balance, deposit_amount);

                cout <<"Deposit complete!\n";
                cout << "---Savings: $"<< savings.balance<<endl;
            }
        } else {
            checking.balance = transaction.deposit(checking.balance, deposit_amount);

            cout <<"Deposit complete!\n";
            cout << "---Checking: $"<<checking.balance<<endl;
        }
    } else if (input == 3) {
        Transaction transaction;
        double transfer_amount;

        cout <<"Enter transfer amount: ";
        cin>>transfer_amount;

        int input;
        cout << "\nWhat account would you like to transfer from?" << endl << "---1: Checking\n---2: Savings\n" << endl;
        cin >> input;

        if (input == 1) {
            checking.balance = transaction.withdrawal(checking.balance, transfer_amount);
            savings.balance = transaction.deposit(savings.balance, transfer_amount);

            cout <<"Transfer complete! \n";
            if (checking.balance) {
                cout << "---Checking: $"<<checking.balance<<endl;
            }
            if (savings.balance) {
                cout << "---Savings: $"<<savings.balance<<endl;
            }
        } else {
            checking.balance = transaction.deposit(checking.balance, transfer_amount);
            savings.balance = transaction.withdrawal(savings.balance, transfer_amount);

            cout << "Transfer complete! \n";
            if (checking.balance) {
                cout << "---Checking: $" << checking.balance<<endl;
            }
            if (savings.balance) {
                cout << "---Savings: $" << savings.balance<<endl;
            }
        }

    } else {
        cout <<"Account Balances:\n";
        cout <<"---Checking: $" << checking.balance<<endl;

        if (savings_created) {
            cout <<"---Savings: $" << savings.balance<<endl;
        }
    }
    return 0;
}
