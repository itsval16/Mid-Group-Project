#include "BankAccount.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

BankAccount :: BankAccount(const string& name, int accNum, double deposit) //Constructor, including the BankAccount function in the scope of the class
 : ownerName(name), accountNumber(accNum), balance(deposit) { //Initializer list to set data members to the new initial values
     history.push_back("Initial deposit amount: $" + numToStr (deposit)); //Recording initial deposit in history
 }
 
 void BankAccount :: deposit (double amount) {
     if (amount > 0) {
         balance += amount; //Adding money into account
         history.push_back ("Deposited: $" + numToStr (amount)); //Recording deposit transaction in history
         cout << "Deposited: $" << fixed << setprecision(2) << amount << endl;
     } else {
         cout << "Deposit must be positive." << endl;
     }
 }
 
 bool BankAccount :: withdraw(double amount) {
     if (amount <= 0) { //Won't allow you to withdraw 0 or a negative amount
         cout << "Withdrawl must be positive." << endl; 
         return false;
     }
     if (amount > balance) { //Won't allow you to withdraw more than the balance
         cout << "You're going broke :(." << endl;
         return false;
     }
     balance -= amount;
     history.push_back ("Withdrew: $" + numToStr(amount));
     cout << "Withdrew $" << fixed << setprecision(2) << amount << endl;
     if (balance == 0) {
         cout << "Your balance is 0 :(" << endl;
         return true;
     }
     return true;
 }
 
 double BankAccount :: getBalance() const {
     return balance; //Prints the current balance
 }
 
 void BankAccount :: display() const { //Displaying account info when chosen in the menu
     cout << "Owner: " << ownerName << endl;
     cout << "Account #" << accountNumber << endl;
     cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
 }
 
 void BankAccount :: showHistory() const{ //Outputs the history
     cout << "Transaction History " << endl;
     for (const auto& record : history) { //Uses a copy of the record variable so it doesn't change it when looping through history
         cout << record << endl;
     }
 }

int main()
{
    // temporary variable
    string tempName;
    int tempAccNum;
    double tempBalance;
    
    // Asking for Information
    cout << "=== Banking System ===" << endl;
    cout << "Enter owner name: ";
    cin >> tempName;
    cout << "Enter account number: ";
    cin >> tempAccNum;
    cout << "Enter initial deposit (>0): "; // Need to add a check system to make sure initial deposit is positive
    cin >> tempBalance;
    cout << endl;
    
    BankAccount account(tempName, tempAccNum, tempBalance);
    
    // Menu
    cout << "Menu:" << endl;
    cout << "1) Deposit" << endl;
    cout << "2) Withdraw" << endl;
    cout << "3) Show Balance" << endl;
    cout << "4) Show Account Info" << endl;
    cout << "5) Show Transaction History" << endl;
    cout << "6) Exit" << endl;
    
    
    bool bankingStatus = true; // Using the system
    
    while(bankingStatus){
        int choice;
        cout << "Choose option: ";
        cin >> choice;
        
        if (choice == 1){ // Option 1: Deposit
            double curDeposit;
            cout << "Amount to deposit: ";
            cin >> curDeposit;
            tempBalance += curDeposit;
            cout << "Deposited " << fixed << setprecision(2) << curDeposit << endl;
        } else if (choice == 2){ // Option 2: Withdraw
            double curWithdraw;
            cout << "Amount to withdraw: ";
            cin >> curWithdraw;
            if (curWithdraw > tempBalance){
                cout << "Insufficient funds." << endl;
            } else if (curWithdraw == tempBalance){
                tempBalance -= curWithdraw;
                cout << "Withdrew $" << fixed << setprecision(2) << curWithdraw << endl;
                cout << "Balance is now zero." << endl;
            } else {
                tempBalance -= curWithdraw;
                cout << "Withdrew $" << fixed << setprecision(2) << curWithdraw << endl;
            }
        } else if (choice == 3){ // Option 3: Show Balance
            cout << "Current Balance: " << fixed << setprecision(2) << tempBalance << endl;
        } else if (choice == 4){ // Option 4: Show Account Info
            account.display();
        } else if (choice == 5){ // Option 5: Show Transaction History
            account.showHistory();
        } else if (choice == 6){ // Option 6: Exit
        cout << "Goodbye!";
            bankingStatus = false;
        }
        cout << endl;
    }
    
    return 0;
}


/* 
Ali Roshdi 
11/01/2025
 Reflection -> What I found tricky for this assignment was splitting up the work initially, as we all just kind of went with the flow for 
 a little bit and then were able to properly figure things out as we went along. Another tricky part was figuring out how to use the vector 
 properly for the transaction history, as in order to constantly add the new transactions we'd have to implement the push_back function. As 
 well as having to convert the integers/doubles into strings, after some time I was able to put it all together using a stringstream and 
 template function. However, prior to coming across that solution, I was doing some research and came across something new that I learned
 which was a function named 'to_string' that is in the <iomanip> library that automatically converts integers and doubles into strings. I
 did not use that solution however, and ended up using the stringstream as I've mentioned earlier.
 */


