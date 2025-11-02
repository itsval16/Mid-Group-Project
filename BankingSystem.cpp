// BankingSystem.cpp
// Created by: Junjie Li | Edits: Valeria & Ali
// Date: October 31, 2025

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <vector>
#include "BankAccount.h"

using namespace std;

// Input for numbers // only positive numbers can work
double getValidNum(string prompt) {
    double num;
    while (true) {
        cout << prompt;
        cin >> num;
        if (cin.fail() || num <= 0) { //ensures here if the number is not positive or if input fails to go through
            cout << "Invalid input! Please enter a positive number: ";
            cin.clear(); //clears any errors
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //forget about the invaild input
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears buffer from input
            return num; //return the number
        }
    }
}

// Input for menu //menu selection between options 1 through 6
int getMenuChoice() {
    int choice;
    while (true) {
        cout << "Choose option: ";
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 6) { //ensures if input fails or if it's out of range
            cout << "Invalid menu option! Please choose 1-6: ";
            cin.clear(); //clears any errors
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //forget about the invaild input
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears buffer from input
            return choice; //return to the choice number given
        }
    }
}

// helps with the function to format numbers as strings
string BankAccount::numToStr(double num) const {
    string str = to_string(num); //convert the numbers to strings
    return str.substr(0, str.find(".") + 3); //only has two digits after the decimal point
}

//junjie added
// Constructor - FIXED: removed extra text and fixed syntax
BankAccount::BankAccount(const string& name, int accNum, double deposit)
    : ownerName(name), accountNumber(accNum), balance(deposit) { // takes name of account owner, account number, and their initial deposit amount
    history.push_back("Account created with initial deposit $" + numToStr(deposit)); //adds the initial deposit with the transaction history for when later needed, can be printed
}

void BankAccount::deposit(double amount) { //allows for a specific amount to be added to our account balance
    balance += amount; //increases the amount balance to the amount that is being deposited
    history.push_back("Deposited $" + numToStr(amount)); //adds the deposited amount with the transaction history for when later needed, can be printed
    cout << "Deposited $" << fixed << setprecision(2) << amount << endl; //prints out the amount deposited!
}

bool BankAccount::withdraw(double amount) { //removes a specific amount that is input
    if (amount > balance) { //ensures that the amount being withdrawn is not greater than the current balance
        cout << "Insufficient funds." << endl;
        return false; //if it is greater than, the withdrawal fails to continue
    }
    balance -= amount; //decrease the amount that is being withdrawn
    history.push_back("Withdraw $" + numToStr(amount)); //stores the withdrawn amount to the transaction history for when later needed, can be printed
    cout << "Withdraw $" << fixed << setprecision(2) << amount << endl; //outputs the withdrawal amount
    // ensures if the balance has reached zero after it has withdrawn the amount
        if (abs(balance) < amount) {
            cout << "Balance is now zero." << endl; // prints to the user that the balance is zero
        }
        return true; // withdrawl went through
    }

// returns the current amount in balance | not as the transaction history
double BankAccount::getBalance() const {
    return balance;
}

//prints all the information of the account holder, such as name,account num. and balance amount
void BankAccount::display() const {
    cout << "Owner: " << ownerName << endl;
    cout << "Account: " << accountNumber << endl;
    cout << "Balance: $" << fixed << setprecision(2) << balance << endl; //double
}

//prints the transaction history from the order it started
//recalls the push.back function
void BankAccount::showHistory() const {
    cout << "Transaction History (" << history.size() << "):" << endl; // prints out the amount of transction history it has in a parentheses
    for (const auto& record : history) { //lops through all the transactions that went through and outputs them
        cout << "- " << record << endl;
    }
}

//main function that helps receive all users input and print the correct information
int main() {
    // Get account info
    cout << "=== Banking System ===" << endl;
    
    string tempName;
    cout << "Enter owner name: "; //get owners name
    getline(cin, tempName); //read's the users input
    
    int tempAccNum;
    cout << "Enter account number: "; //get users account number
    cin >> tempAccNum;
    cin.ignore(1000, '\n'); // clears any buffers from the users input
    
    double tempBalance = getValidNum("Enter initial deposit (>0): "); //user can enter the amount they would like to deposit
    
    // Create BankAccount object
    BankAccount account(tempName, tempAccNum, tempBalance);
    cout << endl;
    
    // Menu loop
    bool bankingStatus = true;
    
    while(bankingStatus) {
        //display the whole menu
        cout << "Menu:" << endl;
        cout << "1) Deposit" << endl;
        cout << "2) Withdraw" << endl;
        cout << "3) Show Balance" << endl;
        cout << "4) Show Account Info" << endl;
        cout << "5) Show Transaction History" << endl;
        cout << "6) Exit" << endl;
        
        int choice = getMenuChoice();//revices the users input menu selection
        
        if (choice == 1) {
            //recieves amount and deposits
            double amount = getValidNum("Amount to deposit: ");
            account.deposit(amount); //prints the amount
        }
        else if (choice == 2) {
            //recieves amount and withdraws
            double amount = getValidNum("Amount to withdraw: ");
            account.withdraw(amount); //prints the amount
        }
        else if (choice == 3) {
            //shows the amount balance //double
            cout << "Current Balance: $" << fixed << setprecision(2) << account.getBalance() << endl;
        }
        else if (choice == 4) {
            //displays the amount information
            account.display();
        }
        else if (choice == 5) {
            //prints out the transaction history
            account.showHistory();
        }
        else if (choice == 6) {
            //exits the programs and prints goodbye to the user
            cout << "Goodbye!" << endl;
            bankingStatus = false;
        }
        cout << endl; //adds space between the options of the menu
    }
    
    return 0; //program ends
}



/*
 INDIVIDUAL REFLECTIONS:
 //Ali Roshdi
 //11/01/2025
 //Reflection -> What I found tricky for this assignment was splitting up the work initially, as we all just kind of went with the flow for a little bit and then were able to properly figure things out as we went along. Another tricky part was figuring out how to use the vector properly for the transaction history, as in order to constantly add the new transactions we'd have to implement the push_back function. As well as having to convert the integers/doubles into strings, after some time I was able to put it all together using a stringstream and template function. However, prior to coming across that solution, I was doing some research and came across something new that I learned which was a function named 'to_string' that is in the <iomanip> library that automatically converts integers and doubles into strings. IBak did not use that solution however, and ended up using the stringstream as I've mentioned earlier.
 //
 // Valeria Pavia
 // 11/01/2025
 // Reflection -> For me the hardest part of the project had to be organizing the whole structure of the .cpp file. I had to note down how the 
 
*/

