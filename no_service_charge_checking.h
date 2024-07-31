#ifndef NO_SERVICE_CHARGE_CHECKING_H
#define NO_SERVICE_CHARGE_CHECKING_H

#include <string>

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

#endif // NO_SERVICE_CHARGE_CHECKING_H