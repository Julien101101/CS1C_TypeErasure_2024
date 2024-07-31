#include "high_interest_savings.h"
#include <iostream>

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