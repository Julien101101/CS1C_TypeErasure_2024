/**********************************************************
* AUTHOR               : 
* TEAM                 : Type_Erasures
* GitHub Project       : Financial Accounts with Type Erasure
* CLASS                : CS1C
* SECTION              : MTWTH: 3:00p - 6:15p
* DUE DATE             : Jul 28, 2024
**********************************************************/

/*********************************************************
*
*   Financial Accounts with Type Erasure - Main Program
*---------------------------------------------------------
*
* This file contains the main program to test the various
* bank account classes using type erasure. It performs
* operations such as depositing money, withdrawing money,
* applying interest, and displaying account information.
*
**********************************************************/
#include "accounts.h"

// Template class member function implementations
template <typename T>
AccountImpl<T>::AccountImpl(T account) : account_(std::move(account)) {}

template <typename T>
void AccountImpl<T>::getAccountInfo() const {
    account_.getAccountInfo();
}

template <typename T>
void AccountImpl<T>::performOperations() {
    account_.performOperations();
}

// Account implementations' member functions

ServiceChargeChecking::ServiceChargeChecking(std::string name, int accountNumber, double balance, double serviceCharge, int checkLimit)
    : name_(std::move(name)), accountNumber_(accountNumber), balance_(balance), serviceCharge_(serviceCharge), checkLimit_(checkLimit), checksWritten_(0) {}

void ServiceChargeChecking::getAccountInfo() const {
    std::cout << "Account Number: " << accountNumber_ << "\n"
              << "Holder Name: " << name_ << "\n"
              << "Balance: $" << balance_ << "\n"
              << "Service Charge: $" << serviceCharge_ << "\n"
              << "Check Limit: " << checkLimit_ << "\n"
              << "Checks Written: " << checksWritten_ << "\n"
              << "------------------------\n";
}

void ServiceChargeChecking::performOperations() {
    // Implementation of operations for ServiceChargeChecking
}

NoServiceChargeChecking::NoServiceChargeChecking(std::string name, int accountNumber, double balance, double interestRate, double minBalance)
    : name_(std::move(name)), accountNumber_(accountNumber), balance_(balance), interestRate_(interestRate), minBalance_(minBalance) {}

void NoServiceChargeChecking::getAccountInfo() const {
    std::cout << "Account Number: " << accountNumber_ << "\n"
              << "Holder Name: " << name_ << "\n"
              << "Balance: $" << balance_ << "\n"
              << "Interest Rate: " << interestRate_ << "%\n"
              << "Minimum Balance: $" << minBalance_ << "\n"
              << "------------------------\n";
}

void NoServiceChargeChecking::performOperations() {
    if (balance_ >= minBalance_) {
        balance_ += (balance_ * interestRate_ / 100);
    }
}

HighInterestChecking::HighInterestChecking(std::string name, int accountNumber, double balance, double interestRate, double minBalance)
    : name_(std::move(name)), accountNumber_(accountNumber), balance_(balance), interestRate_(interestRate), minBalance_(minBalance) {}

void HighInterestChecking::getAccountInfo() const {
    std::cout << "Account Number: " << accountNumber_ << "\n"
              << "Holder Name: " << name_ << "\n"
              << "Balance: $" << balance_ << "\n"
              << "Interest Rate: " << interestRate_ << "%\n"
              << "Minimum Balance: $" << minBalance_ << "\n"
              << "------------------------\n";
}

void HighInterestChecking::performOperations() {
    if (balance_ >= minBalance_) {
        balance_ += (balance_ * interestRate_ / 100);
    }
}

HighInterestSavings::HighInterestSavings(std::string name, int accountNumber, double balance, double interestRate)
    : name_(std::move(name)), accountNumber_(accountNumber), balance_(balance), interestRate_(interestRate) {}

void HighInterestSavings::getAccountInfo() const {
    std::cout << "Account Number: " << accountNumber_ << "\n"
              << "Holder Name: " << name_ << "\n"
              << "Balance: $" << balance_ << "\n"
              << "Interest Rate: " << interestRate_ << "%\n"
              << "------------------------\n";
}

void HighInterestSavings::performOperations() {
    balance_ += (balance_ * interestRate_ / 100);
}

HighInterestSavingsWithMinBalance::HighInterestSavingsWithMinBalance(std::string name, int accountNumber, double balance, double interestRate, double minBalance)
    : name_(std::move(name)), accountNumber_(accountNumber), balance_(balance), interestRate_(interestRate), minBalance_(minBalance) {}

void HighInterestSavingsWithMinBalance::getAccountInfo() const {
    std::cout << "Account Number: " << accountNumber_ << "\n"
              << "Holder Name: " << name_ << "\n"
              << "Balance: $" << balance_ << "\n"
              << "Interest Rate: " << interestRate_ << "%\n"
              << "Minimum Balance: $" << minBalance_ << "\n"
              << "------------------------\n";
}

void HighInterestSavingsWithMinBalance::performOperations() {
    if (balance_ >= minBalance_) {
        balance_ += (balance_ * interestRate_ / 100);
    }
}

CertificateOfDeposit::CertificateOfDeposit(std::string name, int accountNumber, double balance, int maturityMonths, int currentMonth, double interestRate)
    : name_(std::move(name)), accountNumber_(accountNumber), balance_(balance), maturityMonths_(maturityMonths), currentMonth_(currentMonth), interestRate_(interestRate) {}

void CertificateOfDeposit::getAccountInfo() const {
    std::cout << "Account Number: " << accountNumber_ << "\n"
              << "Holder Name: " << name_ << "\n"
              << "Balance: $" << balance_ << "\n"
              << "Maturity Months: " << maturityMonths_ << "\n"
              << "Current Month: " << currentMonth_ << "\n"
              << "Interest Rate: " << interestRate_ << "%\n"
              << "------------------------\n";
}

void CertificateOfDeposit::performOperations() {
    if (currentMonth_ >= maturityMonths_) {
        balance_ += (balance_ * interestRate_ / 100);
    }
}

int main() {
    std::vector<std::unique_ptr<Account>> accounts;

    accounts.push_back(std::make_unique<AccountImpl<ServiceChargeChecking>>(ServiceChargeChecking("Alice", 1, 350.0, 10.0, 5)));
    accounts.push_back(std::make_unique<AccountImpl<NoServiceChargeChecking>>(NoServiceChargeChecking("Bob", 2, 1700.0, 2.0, 1000.0)));
    accounts.push_back(std::make_unique<AccountImpl<HighInterestChecking>>(HighInterestChecking("Charlie", 3, 2600.0, 3.0, 2000.0)));
    accounts.push_back(std::make_unique<AccountImpl<HighInterestSavings>>(HighInterestSavings("Dave", 4, 1300.0, 1.0)));
    accounts.push_back(std::make_unique<AccountImpl<HighInterestSavingsWithMinBalance>>(HighInterestSavingsWithMinBalance("Eve", 5, 3200.0, 5.0, 2500.0)));
    accounts.push_back(std::make_unique<AccountImpl<CertificateOfDeposit>>(CertificateOfDeposit("Frank", 6, 5000.0, 6, 6, 4.0)));

    for (const auto& account : accounts) {
        account->performOperations();
        account->getAccountInfo();
    }

    return 0;
}
