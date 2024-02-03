// main.cpp

/**
 Shiva Khatri
This program simulates an ATM machine. It reads account information from a file and allows the user to log in and perform transactions.
It uses the Bank and ATM classes to accomplish this. The Bank class stores account information and the ATM class provides the user interface.

 */
#include <iostream>
#include <fstream>
#include "Bank.h"
#include "ATM.h"

using namespace std;

int main() {
    ifstream inf; // Input file stream object where inf is the name of the object
    Bank bk; // Bank object

    // Prompt the user for the path to the input file
    string filePath; // Path to the input file to store account information
    cout << "Enter the path to the input file: "; // Prompt the user for the path to the input file
    cin >> filePath; // Read the path from the user

    // Open the file as an input file
    inf.open(filePath); // Open the file at the given path
    if (!inf.is_open()) { // Check if the file was opened successfully
        cerr << "Error opening the input file. Exiting program." << endl; // Print an error message
        cerr << "Error details: " << strerror(errno) << endl; // Print detailed error information
        return 1; // Exit with error code
    }

    // Load all accounts
    bk.loadAccounts(inf); // Call the loadAccounts() method of the Bank object

    // Close the input file
    inf.close();

    // Create an ATM object and pass it the Bank object
    ATM atm(bk);

    // Call the start() method of the object atm
    int result = atm.start();

    // Check the value returned by start()
    switch (result) {
        case 0:
            cout << "Normal Exit" << endl;
            break;
        case 1:
            cout << "Account not found – system shutting down" << endl;
            break;
        default:
            cerr << "Unexpected result from ATM start(). Exiting program." << endl;
            return 1; // Exit with error code
    }

    return 0; // Normal exit
}
