#include "hw06.h"

const double ServiceChargeChecking::monthlyServiceCharge = 10.0;

ServiceChargeChecking::ServiceChargeChecking(std::string name, int accountNumber)
    : name(name), accountNumber(accountNumber), balance(0.0) {}

void ServiceChargeChecking::deposit(double amount) {
    balance += amount;
}

void ServiceChargeChecking::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
    }
    else {
        std::cout << "Cannot withdraw amount. Insufficient balance.\n";
    }
}

void ServiceChargeChecking::createMonthlyStatement() {
    balance -= monthlyServiceCharge;
    std::cout << "Monthly statement for Service Charge Checking Account\n";
    std::cout << "Account Holder: " << name << "\n";
    std::cout << "Account Number: " << accountNumber << "\n";
    std::cout << "Final Balance: " << balance << "\n";
    std::cout << "------------------------------------------\n";
}

std::string ServiceChargeChecking::getAccountName() const {
    return name;
}

int ServiceChargeChecking::getAccountNumber() const {
    return accountNumber;
}

double ServiceChargeChecking::getBalance() const {
    return balance;
}

// Implementations for NoServiceChargeChecking
NoServiceChargeChecking::NoServiceChargeChecking(std::string name, int accountNumber, double minBalance)
    : name(name), accountNumber(accountNumber), balance(0.0), minimumBalance(minBalance), interestRate(0.02) {}

void NoServiceChargeChecking::deposit(double amount) {
    balance += amount;
}

void NoServiceChargeChecking::withdraw(double amount) {
    if (balance - amount >= minimumBalance) {
        balance -= amount;
    }
    else {
        std::cout << "Cannot withdraw amount. Minimum balance requirement not met.\n";
    }
}

void NoServiceChargeChecking::createMonthlyStatement() {
    if (balance >= minimumBalance) {
        balance += (balance * interestRate);
    }
    std::cout << "Monthly statement for No Service Charge Checking Account\n";
    std::cout << "Account Holder: " << name << "\n";
    std::cout << "Account Number: " << accountNumber << "\n";
    std::cout << "Final Balance: " << balance << "\n";
    std::cout << "------------------------------------------\n";
}

std::string NoServiceChargeChecking::getAccountName() const {
    return name;
}

int NoServiceChargeChecking::getAccountNumber() const {
    return accountNumber;
}

double NoServiceChargeChecking::getBalance() const {
    return balance;
}

// Implementations for HighInterestChecking
HighInterestChecking::HighInterestChecking(std::string name, int accountNumber, double minBalance)
    : name(name), accountNumber(accountNumber), balance(0.0), interestRate(0.05), minimumBalance(minBalance) {}

void HighInterestChecking::deposit(double amount) {
    balance += amount;
}

void HighInterestChecking::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
    }
    else {
        std::cout << "Insufficient balance to withdraw.\n";
    }
}

void HighInterestChecking::createMonthlyStatement() {
    if (balance >= minimumBalance) {
        balance += (balance * interestRate);
    }
    std::cout << "Monthly statement for High Interest Checking Account\n";
    std::cout << "Account Holder: " << name << "\n";
    std::cout << "Account Number: " << accountNumber << "\n";
    std::cout << "Final Balance: " << balance << "\n";
    std::cout << "------------------------------------------\n";
}

std::string HighInterestChecking::getAccountName() const {
    return name;
}

int HighInterestChecking::getAccountNumber() const {
    return accountNumber;
}

double HighInterestChecking::getBalance() const {
    return balance;
}

// Implementations for SavingsAccount
SavingsAccount::SavingsAccount(std::string name, int accountNumber, double rate)
    : name(name), accountNumber(accountNumber), balance(0.0), interestRate(rate) {}

void SavingsAccount::deposit(double amount) {
    balance += amount;
}

void SavingsAccount::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
    }
    else {
        std::cout << "Insufficient balance to withdraw.\n";
    }
}

void SavingsAccount::createMonthlyStatement() {
    balance += (balance * interestRate);
    std::cout << "Monthly statement for Savings Account\n";
    std::cout << "Account Holder: " << name << "\n";
    std::cout << "Account Number: " << accountNumber << "\n";
    std::cout << "Final Balance: " << balance << "\n";
    std::cout << "------------------------------------------\n";
}

std::string SavingsAccount::getAccountName() const {
    return name;
}

int SavingsAccount::getAccountNumber() const {
    return accountNumber;
}

double SavingsAccount::getBalance() const {
    return balance;
}

// Implementations for HighInterestSavings
HighInterestSavings::HighInterestSavings(std::string name, int accountNumber, double rate, double minBalance)
    : name(name), accountNumber(accountNumber), balance(0.0), interestRate(rate), minimumBalance(minBalance) {}

void HighInterestSavings::deposit(double amount) {
    balance += amount;
}

void HighInterestSavings::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
    }
    else {
        std::cout << "Insufficient balance to withdraw.\n";
    }
}

void HighInterestSavings::createMonthlyStatement() {
    if (balance >= minimumBalance) {
        balance += (balance * interestRate);
    }
    std::cout << "Monthly statement for High Interest Savings Account\n";
    std::cout << "Account Holder: " << name << "\n";
    std::cout << "Account Number: " << accountNumber << "\n";
    std::cout << "Final Balance: " << balance << "\n";
    std::cout << "------------------------------------------\n";
}

std::string HighInterestSavings::getAccountName() const {
    return name;
}

int HighInterestSavings::getAccountNumber() const {
    return accountNumber;
}

double HighInterestSavings::getBalance() const {
    return balance;
}

// Implementations for CertificateOfDeposit
CertificateOfDeposit::CertificateOfDeposit(std::string name, int accountNumber, double rate, int months)
    : name(name), accountNumber(accountNumber), balance(0.0), interestRate(rate), maturityMonths(months), currentMonth(0) {}

void CertificateOfDeposit::deposit(double amount) {
    balance += amount;
}

void CertificateOfDeposit::withdraw(double amount) {
    if (currentMonth >= maturityMonths) {
        balance -= amount;
    }
    else {
        std::cout << "Cannot withdraw now.\n";
    }
}

void CertificateOfDeposit::createMonthlyStatement() {
    if (currentMonth >= maturityMonths) {
        balance += (balance * interestRate);
    }
    currentMonth++;
    std::cout << "Monthly statement for Certificate of Deposit\n";
    std::cout << "Account Holder: " << name << "\n";
    std::cout << "Account Number: " << accountNumber << "\n";
    std::cout << "Interest Rate: " << interestRate << "\n";
    std::cout << "Maturity Months: " << maturityMonths << "\n";
    std::cout << "Current Month: " << currentMonth << "\n";
    std::cout << "Final Balance: " << balance << "\n";
    std::cout << "------------------------------------------\n";
}

std::string CertificateOfDeposit::getAccountName() const {
    return name;
}

int CertificateOfDeposit::getAccountNumber() const {
    return accountNumber;
}

double CertificateOfDeposit::getBalance() const {
    return balance;
}

// Menu
void displayMenu(std::vector<Account>& accounts) {
    int choice;
    double amount;
    int accountNumber;
    Account* account;

    do {
        std::cout << "\nBank Account Management Menu\n";
        std::cout << "1. Deposit\n";
        std::cout << "2. Withdraw\n";
        std::cout << "3. Create Monthly Statement\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter account number to deposit into: ";
            std::cin >> accountNumber;
            account = findAccountByNumber(accounts, accountNumber);
            if (account) {
                std::cout << "Enter deposit amount: ";
                std::cin >> amount;
                account->deposit(amount);
                std::cout << "New Balance: " << account->getBalance() << "\n";
            }
            else {
                std::cout << "Invalid account number.\n";
            }
            break;

        case 2:
            std::cout << "Enter account number to withdraw from: ";
            std::cin >> accountNumber;
            account = findAccountByNumber(accounts, accountNumber);
            if (account) {
                std::cout << "Enter withdrawal amount: ";
                std::cin >> amount;
                account->withdraw(amount);
                std::cout << "New Balance: " << account->getBalance() << "\n";
            }
            else {
                std::cout << "Invalid account number.\n";
            }
            break;

        case 3:
            for (auto& acc : accounts) {
                acc.createMonthlyStatement();
            }
            break;

        case 4:
            std::cout << "Exiting menu. \n";
            break;

        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

// Utility functions
Account* findAccountByNumber(std::vector<Account>& accounts, int accountNumber) {
    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accountNumber) {
            return &acc;
        }
    }
    return nullptr;
}
