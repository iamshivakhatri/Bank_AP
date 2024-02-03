// ATM.cpp
#include "ATM.h" // Include the ATM class header file
#include <iostream> // Include the input/output stream library
#include <limits> // Include the limits library
using namespace std; // Use the standard namespace

ATM::ATM(Bank& bankObj) : bank(bankObj) {   // Constructor initializes the reference to a Bank object
    // Constructor initializes the reference to a Bank object
}

int ATM::start() { // Start the ATM
    char choice; // Variable to store the user's choice
    do {
        cout << "Please enter your command:" << endl; // Prompt the user for input
        cout << "Q - quit/exit" << endl; // Display the options
        cout << "L - login to account" << endl; // Display the options

        cin >> choice; // Read the user's choice
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        switch (choice) { // Check the user's choice
            case 'Q': // If the user chooses Q
            case 'q': // If the user chooses q
                return 0; // Quit the program
            case 'L': // If the user chooses L
            case 'l': // If the user chooses l
            {
                int loginAttempts = 0; // Variable to store the number of login attempts
                Account loggedInAccount; // Variable to store the logged-in account
                do {
                    string id, pin; // Variables to store the account ID and PIN
                    cout << "Enter accountID: "; // Prompt the user for the account ID
                    cin >> id; // Read the account ID
                    cout << "Enter accountPIN: "; // Prompt the user for the account PIN
                    cin >> pin; // Read the account PIN

                    loggedInAccount = bank.findAcct(id, pin); // Find the account by ID and PIN

                    if (loggedInAccount.getAccountID().empty() || loggedInAccount.getAccountPIN().empty()) { // If the account ID or PIN is empty
                        cout << "Sorry - no match. Try again" << endl; // Print an error message
                        loginAttempts++; // Increment the number of login attempts
                    } else {
                        cout << "Account Found. Welcome, " << loggedInAccount.getAccountID() << "!" << endl; // Print a welcome message
                        transactions(loggedInAccount); // Perform transactions
                        break; // break the loop after the transaction is done
                    }
                } while (loginAttempts < 3); // Repeat until the maximum number of login attempts is reached

                if (loginAttempts >= 3) { // If the maximum number of login attempts is reached
                    return 1; // Exit with error code
                }else{
                    break; // Break out of the switch statement when the transaction is done and presents the user with the main menu
                }

            }
            default: // If the user's choice is not recognized
                cout << "Unrecognized command"<< choice << endl; // Print the message "Unrecognized command"
        }
    } while (true); // Repeat until the user quits
}

void ATM::transactions(Account& acct) { // Perform transactions
    char choice; // Variable to store the user's choice
    do {
        cout << "Please enter your selection or Q to quit:" << endl; // Prompt the user for input
        cout << "W - withdraw funds" << endl;
        cout << "D - deposit funds" << endl;
        cout << "B - check balance" << endl;
        cout << "Q - quit/exit" << endl << endl;

        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        switch (choice) { // Check the user's choice
            case 'W': // If the user chooses W
            case 'w':
            {
                double amount; // Variable to store the withdrawal amount
                cout << "Enter withdrawal amount: "; // Prompt the user for the withdrawal amount
                cin >> amount; // Read the withdrawal amount
                acct.Withdraw(amount); // Withdraw the amount
                break; // Break out of the switch statement
            }
            case 'D': // If the user chooses D
            case 'd':
            {
                double amount; // Variable to store the deposit amount
                cout << "Enter deposit amount: "; // Prompt the user for the deposit amount
                cin >> amount; // Read the deposit amount
                acct.Deposit(amount); // Deposit the amount
                break;
            }
            case 'B': // If the user chooses B
            case 'b': // If the user chooses b
                acct.Balance(); // Check the balance
                break; // Break out of the switch statement
            case 'Q':
            case 'q': // If the user chooses Q
                cout << "Goodbye" << endl; // Print a goodbye message
                return;
            default:
                cout << "Invalid choice. Please try again." << endl; // Print an error message
        }
    } while (true); // Repeat until the user quits
}
