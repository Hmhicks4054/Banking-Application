#include <iostream>
#include "Transaction.h"
using namespace std;
//
// Created by Tyler MacPhee on 11/17/22.
//

double Transaction::withdrawal(double balance, double amount) {
    return balance - amount;
}

double Transaction::deposit(double balance, double amount) {
    return balance + amount;
}
