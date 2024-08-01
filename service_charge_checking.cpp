#include "service_charge_checking.h"
#include <iostream>

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