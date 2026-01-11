#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string name;
    double balance;

public:
    BankAccount(string holder, double bal) {
        cout << "Making account for " << holder << endl;
        if (bal < 0) {
            throw "Bad balance! Cannot create account.";
        }
        name = holder;
        balance = bal;
        cout << "Account OK, balance = " << balance << endl;
    }

    ~BankAccount() {
        cout << "Deleting account " << name << endl;
    }

    void withdraw(double amt) {
        if (amt > balance) {
            throw "Not enough money!";
        }
        balance -= amt;
        cout << "OK, new balance = " << balance << endl;
    }
};

int main() {
    try {
        // Bad account
        BankAccount* acc1 = new BankAccount("Ali", -10);
        delete acc1;
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
    cout << "----" << endl;

    try {
        // Good account
        BankAccount* acc2 = new BankAccount("Sara", 500);
        acc2->withdraw(200);
        acc2->withdraw(400);  // Fail here
        delete acc2;
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }

    cout << "Done!" << endl;
    return 0;
}


