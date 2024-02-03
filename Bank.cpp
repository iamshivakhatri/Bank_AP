// Bank.cpp
#include "Bank.h" // Include the header file Bank.h
#include <fstream> // Include the header file fstream
#include <sstream> // Include the header file sstream
#include <iostream>// Include the header file iostream
using namespace std;//  Using the standard namespace

Account& Bank::findAcct(string id, string pin) { // Find an account by ID and PIN
    for (auto& account : allAccounts) { // Iterate through all accounts in the vector
        if (account.getAccountID() == id && account.getAccountPIN() == pin) { // Check if the account ID and PIN match the given ID and PIN
            return account; // Return the account if a match is found
        }
    }
    return dummyAccount; // Return dummyAccount if no matching account is found
}// Add an account to the vector

void Bank::addAcct(Account& acct) { // Add an account to the vector
    allAccounts.push_back(acct); // Add the account to the vector
}
void Bank::loadAccounts(ifstream& inf) { // Load accounts from a file to the vector
    string line; // String to store each line of the file
    int count = 0; // Variable to store the number of accounts read from the file
    while (getline(inf, line)) {
        count++;// Read each line of the file into the string line using getline() until the end of the file
        if (line.empty()) { // Check if the line is empty
            continue;  // Skip empty lines
        }

        istringstream iss(line); // Create an input string stream object iss and pass the line to it
        string id, pin; // Strings to store account ID and PIN
        double balance; // Double to store account balance

        if (iss >> id >> pin >> balance) { // Read account ID, PIN, and balance from the input string stream by passing them to the variables id, pin, and balance
            Account newAccount(id, pin, balance); // Create a new Account object with the read values
            addAcct(newAccount); // Add the new account to the vector
        } else { // If the read fails
            cout << "Some Accounts are not valid " << endl; // Print an error message
        }
    }
    cout << "Loading Data... " <<  endl;
    cout << count << " Accounts loaded." << endl; // Print the number of accounts loaded
}

// End of Bank.cpp