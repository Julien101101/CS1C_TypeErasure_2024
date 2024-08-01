#include "certificate_of_deposit.h"
#include <iostream>

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