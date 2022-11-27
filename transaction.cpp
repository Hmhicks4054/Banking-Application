#include <iostream>
#include "Transaction.h"
using namespace std;
//
// Created by Tyler MacPhee on 11/17/22.
//

double Transaction::withdrawal(double balance, double amount) {
    try {
        if (balance < amount) {
            throw 10;
        }
        return balance - amount;
    } catch (int e) {
        cout << "Error! Low funds";
        return 0;
    }
}

double Transaction::deposit(double balance, double amount) {
    try {
        if (amount <= 0) {
            throw 10;
        }
        return balance + amount;
    } catch (int e) {
        cout <<"Error! Deposits must be larger than 0";
        return 0;
    }
}