// BankAccount.h
// Created by: Ali | Edits: Valeria
// Date: October 30, 2025

// BankAccount.h
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <vector>
using namespace std;

class BankAccount {
private:
    string ownerName;
    int accountNumber;
    double balance;
    vector<string> history;

public:
    BankAccount(const string& name, int accNum, double deposit);
    void deposit(double amount);
    bool withdraw(double amount);
    double getBalance() const;
    void display() const;
    void showHistory() const;
    
private:
    string numToStr(double num) const;
};

#endif

