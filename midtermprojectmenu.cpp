#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

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
            
        } else if (choice == 5){ // Option 5: Show Transaction History
            
        } else if (choice == 6){ // Option 6: Exit
        cout << "Goodbye!";
            bankingStatus = false;
        }
        cout << endl;
    }
    
    return 0;
}