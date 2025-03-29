/*
Abstraction is one of the four pillars of Object-Oriented Programming (OOP).
It is the concept of hiding unnecessary details and showing only the relevant features to the user.
*/

#include <iostream>
using namespace std;

// Abstracting the internal details of a Bank Account
class BankAccount 
{
private:
    double balance;  // Hidden data (Encapsulation)

public:
    BankAccount(double initialBalance)
     {  // Constructor
        balance = initialBalance;
     }

    void deposit(double amount) 
    {  // Only exposing necessary operations
        balance += amount;
    }

    void showBalance()
    {
        cout << "Current Balance: Rs. " << balance << endl;
    }
};

int main() 
{
    BankAccount myAccount(500.0);  // Creating an account with Rs.500
    myAccount.deposit(200.0);      // Depositing Rs. 200
    myAccount.showBalance();       // Displaying balance

    return 0;
}
/* Expected Output
Current Balance: Rs 700
*/
