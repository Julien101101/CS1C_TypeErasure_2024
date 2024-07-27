#ifndef BANK_ACCOUNT_HPP
#define BANK_ACCOUNT_HPP

#include <string>
#include <iostream>

class BankAccount {
public:
    virtual void retrieveAccountInfo() const = 0;
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void createMonthlyStatement() const = 0;

    // Getter methods
    std::string getName() const { return name; }
    std::string getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }

    // Setter methods
    void setName(const std::string& name) { this->name = name; }
    void setAccountNumber(const std::string& accountNumber) { this->accountNumber = accountNumber; }
    void setBalance(double balance) { this->balance = balance; }

protected:
    std::string name;
    std::string accountNumber;
    double balance = 0.0;
};

class CheckingAccount : public BankAccount {
public:
    void retrieveAccountInfo() const override {
        std::cout << "Checking Account Info: " << name << ", " << accountNumber << ", Balance: " << balance << std::endl;
    }

    void deposit(double amount) override {
        balance += amount;
    }

    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds" << std::endl;
        }
    }

    void createMonthlyStatement() const override {
        std::cout << "Monthly statement for Checking Account: " << balance << std::endl;
    }

    void writeCheck() {
        std::cout << "Writing a check from Checking Account" << std::endl;
    }
};

class SavingsAccount : public BankAccount {
public:
    void retrieveAccountInfo() const override {
        std::cout << "Savings Account Info: " << name << ", " << accountNumber << ", Balance: " << balance << std::endl;
    }

    void deposit(double amount) override {
        balance += amount;
    }

    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds" << std::endl;
        }
    }

    void createMonthlyStatement() const override {
        std::cout << "Monthly statement for Savings Account: " << balance << std::endl;
    }
};

class CertificateOfDeposit : public BankAccount {
public:
    CertificateOfDeposit(int maturityMonths, double interestRate, int currentMonth)
        : maturityMonths(maturityMonths), interestRate(interestRate), currentMonth(currentMonth) {}

    void retrieveAccountInfo() const override {
        std::cout << "CD Account Info: " << name << ", " << accountNumber << ", Balance: " << balance
                  << ", Maturity Months: " << maturityMonths << ", Interest Rate: " << interestRate << "%" << std::endl;
    }

    void deposit(double amount) override {
        balance += amount;
    }

    void withdraw(double amount) override {
        std::cout << "Withdrawals not allowed for CD Accounts" << std::endl;
    }

    void createMonthlyStatement() const override {
        std::cout << "Monthly statement for CD Account: " << balance << std::endl;
    }

private:
    int maturityMonths;
    double interestRate;
    int currentMonth;
};

#endif // BANK_ACCOUNT_HPP

