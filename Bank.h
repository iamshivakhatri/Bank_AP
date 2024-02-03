//
//

#ifndef KHATRI_SHIVA_PROG1CSC402_BANK_H
#define KHATRI_SHIVA_PROG1CSC402_BANK_H


#include "Account.h"

using namespace std;

class Bank { // Bank class
private:
    vector<Account> allAccounts; // Vector to store all accounts
    Account dummyAccount; // Dummy account to return if no matching account is found

public:
    Account & findAcct(string id, string pin); // Find an account by ID and PIN
    void addAcct(Account & acct); // Add an account to the vector
    void loadAccounts(ifstream & inf); // Load accounts from a file to the vector


};


#endif //KHATRI_SHIVA_PROG1CSC402_BANK_H
