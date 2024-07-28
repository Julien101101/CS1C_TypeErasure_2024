/**********************************************************
* AUTHOR               : Adam Mirski
* TEAM                 : Type_Erasures
* GitHub Project       : Financial Accounts with Type Erasure
* CLASS                : CS1C
* SECTION              : MTWTH: 3:00p - 6:15p
* DUE DATE             : Jul 28, 2024
**********************************************************/

/*********************************************************
*
*   Financial Accounts with Type Erasure - Header File
*---------------------------------------------------------
*
* This file contains the declarations for the various bank
* account classes and type erasure framework used in the
* Financial Accounts with Type Erasure project. It provides
* the base class for accounts, type-erased derived classes,
* and specific account implementations such as service
* charge checking, no service charge checking, high interest
* checking, high interest savings, high interest savings
* with minimum balance, and certificate of deposit accounts.
*
**********************************************************/

#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>

// Type-erased base class
class Account {
public:
    virtual ~Account() = default;
    virtual void getAccountInfo() const = 0;
    virtual void performOperations() = 0;
};

// Type-erased derived class
template <typename T>
class AccountImpl : public Account {
public:
    AccountImpl(T account);
    void getAccountInfo() const override;
    void performOperations() override;

private:
    T account_;
};

// Account implementations
class ServiceChargeChecking {
public:
    ServiceChargeChecking(std::string name, int accountNumber, double balance, double serviceCharge, int checkLimit);
    void getAccountInfo() const;
    void performOperations();

private:
    std::string name_;
    int accountNumber_;
    double balance_;
    double serviceCharge_;
    int checkLimit_;
    int checksWritten_;
};

class NoServiceChargeChecking {
public:
    NoServiceChargeChecking(std::string name, int accountNumber, double balance, double interestRate, double minBalance);
    void getAccountInfo() const;
    void performOperations();

private:
    std::string name_;
    int accountNumber_;
    double balance_;
    double interestRate_;
    double minBalance_;
};

class HighInterestChecking {
public:
    HighInterestChecking(std::string name, int accountNumber, double balance, double interestRate, double minBalance);
    void getAccountInfo() const;
    void performOperations();

private:
    std::string name_;
    int accountNumber_;
    double balance_;
    double interestRate_;
    double minBalance_;
};

class HighInterestSavings {
public:
    HighInterestSavings(std::string name, int accountNumber, double balance, double interestRate);
    void getAccountInfo() const;
    void performOperations();

private:
    std::string name_;
    int accountNumber_;
    double balance_;
    double interestRate_;
};

class HighInterestSavingsWithMinBalance {
public:
    HighInterestSavingsWithMinBalance(std::string name, int accountNumber, double balance, double interestRate, double minBalance);
    void getAccountInfo() const;
    void performOperations();

private:
    std::string name_;
    int accountNumber_;
    double balance_;
    double interestRate_;
    double minBalance_;
};

class CertificateOfDeposit {
public:
    CertificateOfDeposit(std::string name, int accountNumber, double balance, int maturityMonths, int currentMonth, double interestRate);
    void getAccountInfo() const;
    void performOperations();

private:
    std::string name_;
    int accountNumber_;
    double balance_;
    int maturityMonths_;
    int currentMonth_;
    double interestRate_;
};

#endif // ACCOUNTS_H
