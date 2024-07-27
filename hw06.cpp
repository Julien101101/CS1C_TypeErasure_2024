#include "hw06.h"

int main() {
    std::vector<Account> accounts;

    accounts.push_back(ServiceChargeChecking("John Doe", 1001));
    accounts.push_back(NoServiceChargeChecking("Jane Smith", 1002, 500.0));
    accounts.push_back(HighInterestChecking("Alice Johnson", 1003, 1000.0));
    accounts.push_back(SavingsAccount("Bob Brown", 1004, 0.01));
    accounts.push_back(HighInterestSavings("Carol White", 1005, 0.03, 1000.0));
    accounts.push_back(CertificateOfDeposit("David Green", 1006, 0.03, 6));

    displayMenu(accounts);

    return 0;
}