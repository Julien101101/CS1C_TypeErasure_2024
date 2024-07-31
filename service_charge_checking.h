#ifndef SERVICE_CHARGE_CHECKING_H
#define SERVICE_CHARGE_CHECKING_H

#include <string>

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

#endif // SERVICE_CHARGE_CHECKING_H