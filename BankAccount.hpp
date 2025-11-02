// BankAccount.h
// Created by: Ali | Edits: Valeria
// Date: October 30, 2025

// BankAccount.h
#ifndef BANKACCOUNT_H //ensure that this header file isn't repeated multiple times
#define BANKACCOUNT_H

#include <string> //a string library that includes the name of the owner and the transaction strings
#include <vector> //helps store th transaction hisroty
using namespace std;

class BankAccount { //helps track the bank account's information to track the transactions going through
private: //data protection
    string ownerName; //stores the name of the owner
    int accountNumber; //stores the account number
    double balance; //helps store the balance of the account as the transactions are happening
    vector<string> history; //allows for all the transaction history to be recorded for later, so it can be called back later to print in chronological order
    string numToStr(double num) const; //helps convert the double value into a string so it can be displayed

public: //helps interact with the bank account info
    BankAccount(const string& name, int accNum, double deposit); //helps with storing and keeping track of the user's inputs
    void deposit(double amount); //ensures a positive number is being entered
    bool withdraw(double amount); //ensure that the withdrawal goes through successfully
    double getBalance() const; //return the current baance of the account
    void display() const; //shows the info needed to be shared with the user
    void showHistory() const; //shares all info with the user
    
};

#endif // end of the header guard
