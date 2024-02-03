
#include <iostream> // Include the input/output stream library
#include <iomanip>  // Include the input/output manipulators library

#include <string>  // Include the string library
#include "Account.h" // Include the Account class header file

using namespace std; // Use the standard namespace

// Default Constructor
Account::Account() { // Initialize the accountID, accountPIN, and accountBalance to default values
    accountID = ""; // Set the accountID to an empty string
    accountPIN = ""; // Set the accountPIN to an empty string
    accountBalance = 0.00;   // Set the accountBalance to 0.0
}

Account::Account(const string& id, const string& pin, double balance) { // Constructor with parameters

    // Check if ID is 8 characters long, PIN is 4 characters long, and consists of only digits
    if (id.length() == 8 && pin.length() == 4 && pin.find_first_not_of("0123456789") == string::npos && balance >= 0.0) {
        accountID = id; // Set the accountID to the value of id
        accountPIN = pin; // Set the accountPIN to the value of pin
        accountBalance = balance; // Set the accountBalance to the value of balance
    } else {
        cout << "Invalid input for ID :"<< id << "PIN: "<< pin <<"  or balance"<< balance <<" Account not created." << endl;
        // Set default values
        accountID = ""; // Set the accountID to an empty string
        accountPIN = ""; // Set the accountPIN to an empty string
        accountBalance = 0.0; // Set the accountBalance to 0.0
    }
}

// Get method for accountID
string Account::getAccountID()  { // Return the accountID
    return accountID; // Return the accountID
}

// Set method for accountID
void Account::setAccountID(const string& id) { // Set the accountID to the value of id
    if (id.length() == 8) { // Check if the length of id is 8
        accountID = id; // Set the accountID to the value of id
    } else { // If the length of id is not 8
        cerr << "Invalid input for ID. Account ID not changed." << endl;    // Print an error message
    }
}

// Get method for accountPIN
string Account::getAccountPIN()  {
    return accountPIN; // Return the accountPIN
}

// Set method for accountPIN
void Account::setAccountPIN(const string& pin){ // Set the accountPIN to the value of pin
    if(pin.length()== 4 && pin.find_first_not_of("0123456789") == string::npos) { // Check if the length of pin is 4 and consists of only digits
        accountPIN = pin; // Set the accountPIN to the value of pin
    }else{
        cout << "Invalid input for PIN. Account PIN not changed." << endl;  // Print an error message
    }
}

// Get method for accountBalance
double Account::getAccountBalance() {   // Return the accountBalance
    return accountBalance; // Return the accountBalance
}

// Set method for accountBalance
void Account::setAccountBalance(double balance) {
    accountBalance = balance; // Set the accountBalance to the value of balance
}

void Account::Balance(){
    cout << fixed << setprecision(2); // Set the output to display 2 decimal places
    cout << "Your current balance is: $" << getAccountBalance() << endl; // Print the current balance
}

void Account::Deposit(double amount){ // Deposit method
    if(amount > 0){
        setAccountBalance(getAccountBalance() + amount); // Add the amount to the account balance
       // cout << "Your new balance is: " << getAccountBalance() << endl; // Print the new balance
    }else{
        cout << "Invalid input for deposit amount. Balance not changed." << endl; // Print an error message
    }
}

void Account::Withdraw(double amount){ // Withdraw method
    if(amount > 0 && amount <= getAccountBalance()){ // Check if the amount is greater than 0 and less than or equal to the account balance
        setAccountBalance(getAccountBalance() - amount); // Subtract the amount from the account balance
     //   cout << "Your new balance is: $" << getAccountBalance() << endl; // Print the new balance
    }else{
        cout << "Invalid input for withdrawal amount. Balance not changed." << endl; // Print an error message
    }
}
