#include <iostream>
#include <stdexcept>

class BankAccount {
private:
    double balance; // hidden internal state
    int accountNumber;

public:
    BankAccount(int accNo, double init = 0.0)
        : balance(init), accountNumber(accNo) {
    }

    // read-only getter (const correctness)
    double getBalance() const { return balance; }
    int getAccountNumber() const { return accountNumber; }

    // controlled mutations with validation
    void deposit(double amount) {
        if (amount <= 0) throw std::invalid_argument("Deposit must be > 0");
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= 0) throw std::invalid_argument("Withdraw must be > 0");
        if (amount > balance) throw std::runtime_error("Insufficient funds");
        balance -= amount;
    }

    // friend can access private fields (use sparingly)
    friend void printAccount(const BankAccount &a);
};

void printAccount(const BankAccount &a) {
    std::cout << "Account " << a.accountNumber << " balance: " << a.balance << '\n';
}

int main() {
    BankAccount acc(12345, 100.0);
    acc.deposit(50);
    acc.withdraw(30);
    std::cout << acc.getBalance() << '\n'; // 120
    printAccount(acc);
}
