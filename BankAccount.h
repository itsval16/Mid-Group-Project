#ifndef BankAccount.h 
#define BankAccount.h 

#include <iostream>
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
    
        BankAccount (const string& name, int accNum, double deposit);
        void deposit(double amount);
        bool withdraw(double amount);
        double getBalance() const;
        void display() const;
        void showHistory() const;
};

#endif
