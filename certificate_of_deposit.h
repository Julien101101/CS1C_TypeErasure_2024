#ifndef CERTIFICATE_OF_DEPOSIT_H
#define CERTIFICATE_OF_DEPOSIT_H

#include <string>

class CertificateOfDeposit {
public:
    CertificateOfDeposit(std::string name, int accountNumber, double balance, int maturityMonths, int currentMonth, double interestRate);
    void getAccountInfo() const;
    void performOperations();

private:
    std::string name_;
    int accountNumber_;
    double balance_;
    int maturityMonths_;
    int currentMonth_;
    double interestRate_;
};

#endif // CERTIFICATE_OF_DEPOSIT_H