#include "no_service_charge_checking.h"
#include <iostream>

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