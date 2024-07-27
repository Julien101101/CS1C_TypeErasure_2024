#ifndef HW06_H
#define HW06_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>

// Type-erased base class
class AccountFunction {
public:
    virtual ~AccountFunction() = default;
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void createMonthlyStatement() = 0;
    virtual std::string getAccountName() const = 0;
    virtual int getAccountNumber() const = 0;
    virtual double getBalance() const = 0;
};

// Type-erased derived class
class Account {
public:
    template <typename T>
    Account(T account) : account(std::make_unique<Model<T>>(std::move(account))) {}

    void deposit(double amount) { account->deposit(amount); }
    void withdraw(double amount) { account->withdraw(amount); }
    void createMonthlyStatement() { account->createMonthlyStatement(); }
    std::string getAccountName() const { return account->getAccountName(); }
    int getAccountNumber() const { return account->getAccountNumber(); }
    double getBalance() const { return account->getBalance(); }

private:
    struct Concept {
        virtual ~Concept() = default;
        virtual void deposit(double amount) = 0;
        virtual void withdraw(double amount) = 0;
        virtual void createMonthlyStatement() = 0;
        virtual std::string getAccountName() const = 0;
        virtual int getAccountNumber() const = 0;
        virtual double getBalance() const = 0;
    };

    template <typename T>
    struct Model : Concept {
        Model(T model) : data(std::move(model)) {}

        void deposit(double amount) override { data.deposit(amount); }
        void withdraw(double amount) override { data.withdraw(amount); }
        void createMonthlyStatement() override { data.createMonthlyStatement(); }
        std::string getAccountName() const override { return data.getAccountName(); }
        int getAccountNumber() const override { return data.getAccountNumber(); }
        double getBalance() const override { return data.getBalance(); }

        T data;
    };

    std::unique_ptr<Concept> account;
};

// Account classes
class ServiceChargeChecking {
public:
    ServiceChargeChecking(std::string name, int accountNumber);
    void deposit(double amount);
    void withdraw(double amount);
    void createMonthlyStatement();
    std::string getAccountName() const;
    int getAccountNumber() const;
    double getBalance() const;

private:
    std::string name;
    int accountNumber;
    double balance;
    static const double monthlyServiceCharge;
};

class NoServiceChargeChecking {
public:
    NoServiceChargeChecking(std::string name, int accountNumber, double minBalance);
    void deposit(double amount);
    void withdraw(double amount);
    void createMonthlyStatement();
    std::string getAccountName() const;
    int getAccountNumber() const;
    double getBalance() const;

private:
    std::string name;
    int accountNumber;
    double balance;
    double minimumBalance;
    double interestRate;
};

class HighInterestChecking {
public:
    HighInterestChecking(std::string name, int accountNumber, double minBalance);
    void createMonthlyStatement();
    void deposit(double amount);
    void withdraw(double amount);
    std::string getAccountName() const;
    int getAccountNumber() const;
    double getBalance() const;

private:
    std::string name;
    int accountNumber;
    double balance;
    double interestRate;
    double minimumBalance;
};

class SavingsAccount {
public:
    SavingsAccount(std::string name, int accountNumber, double rate);
    void deposit(double amount);
    void withdraw(double amount);
    void createMonthlyStatement();
    std::string getAccountName() const;
    int getAccountNumber() const;
    double getBalance() const;

private:
    std::string name;
    int accountNumber;
    double balance;
    double interestRate;
};

class HighInterestSavings {
public:
    HighInterestSavings(std::string name, int accountNumber, double rate, double minBalance);
    void createMonthlyStatement();
    void deposit(double amount);
    void withdraw(double amount);
    std::string getAccountName() const;
    int getAccountNumber() const;
    double getBalance() const;

private:
    std::string name;
    int accountNumber;
    double balance;
    double interestRate;
    double minimumBalance;
};

class CertificateOfDeposit {
public:
    CertificateOfDeposit(std::string name, int accountNumber, double rate, int months);
    void deposit(double amount);
    void withdraw(double amount);
    void createMonthlyStatement();
    std::string getAccountName() const;
    int getAccountNumber() const;
    double getBalance() const;

private:
    std::string name;
    int accountNumber;
    double balance;
    double interestRate;
    int maturityMonths;
    int currentMonth;
};

// Utility functions
void displayMenu(std::vector<Account>& accounts);
Account* findAccountByNumber(std::vector<Account>& accounts, int accountNumber);

#endif 
