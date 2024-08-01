#include "accounts.h"
#include "account_impl.h"
#include "service_charge_checking.h"
#include "no_service_charge_checking.h"
#include "high_interest_checking.h"
#include "high_interest_savings.h"
#include "high_interest_savings_with_min_balance.h"
#include "certificate_of_deposit.h"

#include <vector>

int main() {
    std::vector<TypeErased> accounts;

    accounts.emplace_back(ServiceChargeChecking("Alice", 1, 350.0, 10.0, 5));
    accounts.emplace_back(NoServiceChargeChecking("Bob", 2, 1700.0, 2.0, 1000.0));
    accounts.emplace_back(HighInterestChecking("Charlie", 3, 2600.0, 3.0, 2000.0));
    accounts.emplace_back(HighInterestSavings("Dave", 4, 1300.0, 1.0));
    accounts.emplace_back(HighInterestSavingsWithMinBalance("Eve", 5, 3200.0, 5.0, 2500.0));
    accounts.emplace_back(CertificateOfDeposit("Frank", 6, 5000.0, 6, 6, 4.0));

    for (auto& account : accounts) {
        account.performOperations();
        account.getAccountInfo();
    }

    return 0;
}
