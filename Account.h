\

#ifndef KHATRI_SHIVA_PROG1CSC402_ACCOUNT_H
#define KHATRI_SHIVA_PROG1CSC402_ACCOUNT_H

// account.h


#include <iostream>
#include <iomanip>
#include <string>




using namespace std;

class Account {
private:
    string accountID;
    string accountPIN;
    double accountBalance;
public:
// Default Constructor
    Account();

    Account(const string& id, const string& pin, double balance);

    // Get method for accountID
    string getAccountID()  ;

    //set method for accountID
    void setAccountID(const string& id) ;

    // Get method for accountPIN
    string getAccountPIN()  ;

    // Set method for accountPIN
    void setAccountPIN(const string& pin);
    //


    // Get method for accountBalance
    double getAccountBalance() ;
    // Set method for accountBalance
    void setAccountBalance(double balance) ;

    void Balance();

    void Deposit(double amount);

    void Withdraw(double amount);

};// End of Account class




#endif // ACCOUNT_H

