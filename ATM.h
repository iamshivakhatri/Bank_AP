// ATM.h
#ifndef ATM_H
#define ATM_H

#include "Bank.h"

class ATM {
private:
    Bank& bank; // Reference to a Bank object

public:
    ATM(Bank& bankObj); // Constructor takes a reference to a Bank object
    int start(); // Start the ATM
    void transactions(Account& acct); // Perform transactions
};

#endif // ATM_H
