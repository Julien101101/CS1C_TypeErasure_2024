#ifndef BANK_ACCOUNT_HPP
#define BANK_ACCOUNT_HPP

#include <iostream>
#include <string>

class BankAccount {
public:
    BankAccount(const std::string& name, const std::string& accountNumber, double initialBalance)
        : name(name), accountNumber(accountNumber), balance(initialBalance) {}

    virtual void retrieveAccountInfo() const;
    virtual void deposit(double amount);
    virtual void withdraw(double amount);
    virtual void createMonthlyStatement() const;

protected:
    std::string name;
    std::string accountNumber;
    double balance;
};

void BankAccount::retrieveAccountInfo() const {
    std::cout << "Name: " << name << "\nAccount Number: " << accountNumber << "\nBalance: " << balance << std::endl;
}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "Deposited: " << amount << std::endl;
    } else {
        std::cout << "Invalid deposit amount!" << std::endl;
    }
}

void BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        std::cout << "Withdrew: " << amount << std::endl;
    } else {
        std::cout << "Invalid withdrawal amount or insufficient funds!" << std::endl;
    }
}

void BankAccount::createMonthlyStatement() const {
    std::cout << "Monthly Statement:\n";
    retrieveAccountInfo();
}

// Derived classes
class CheckingAccount : public BankAccount {
public:
    CheckingAccount(const std::string& name, const std::string& accountNumber, double initialBalance)
        : BankAccount(name, accountNumber, initialBalance) {}

    void writeCheck(double amount) {
        withdraw(amount);
        std::cout << "Check written for: " << amount << std::endl;
    }
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(const std::string& name, const std::string& accountNumber, double initialBalance)
        : BankAccount(name, accountNumber, initialBalance) {}
};

class CertificateOfDeposit : public BankAccount {
public:
    CertificateOfDeposit(const std::string& name, const std::string& accountNumber, double initialBalance,
                         int maturityMonths, double interestRate)
        : BankAccount(name, accountNumber, initialBalance), maturityMonths(maturityMonths),
          interestRate(interestRate), currentMonth(0) {}

    void createMonthlyStatement() const override {
        std::cout << "Certificate of Deposit Statement:\n";
        retrieveAccountInfo();
        std::cout << "Maturity Months: " << maturityMonths << "\nInterest Rate: " << interestRate << "%" << std::endl;
    }

private:
    int maturityMonths;
    double interestRate;
    int currentMonth;
};

#endif // BANK_ACCOUNT_HPP

