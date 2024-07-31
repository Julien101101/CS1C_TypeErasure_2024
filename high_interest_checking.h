#ifndef HIGH_INTEREST_CHECKING_H
#define HIGH_INTEREST_CHECKING_H

#include <string>

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

#endif // HIGH_INTEREST_CHECKING_H