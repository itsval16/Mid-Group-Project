#ifndef BankAccount_h 
#define BankAccount_h 

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class BankAccount {
    private:
        
        string ownerName;
        int accountNumber;
        double balance;
        vector<string> history;
        
        template <typename T>
        string numToStr (T num) const {
            stringstream ss;
            ss << num;
            return ss.str();
        }
        
    public:
    
        BankAccount (const string& name, int accNum, double deposit);
        void deposit(double amount);
        bool withdraw(double amount);
        double getBalance() const;
        void display() const;
        void showHistory() const;
};

#endif
