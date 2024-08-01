#ifndef HIGH_INTEREST_SAVINGS_H
#define HIGH_INTEREST_SAVINGS_H

#include <string>

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

#endif // HIGH_INTEREST_SAVINGS_H