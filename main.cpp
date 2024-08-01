#include "accounts.h"
#include "account_impl.h"
#include "service_charge_checking.h"
#include "no_service_charge_checking.h"
#include "high_interest_checking.h"
#include "high_interest_savings.h"
#include "high_interest_savings_with_min_balance.h"
#include "certificate_of_deposit.h"

#include <vector>
#include <memory>

int main() {
    std::vector<std::unique_ptr<Account>> accounts;

    accounts.push_back(std::make_unique<AccountImpl<ServiceChargeChecking>>(ServiceChargeChecking("Alice", 1, 350.0, 10.0, 5)));
    accounts.push_back(std::make_unique<AccountImpl<NoServiceChargeChecking>>(NoServiceChargeChecking("Bob", 2, 1700.0, 2.0, 1000.0)));
    accounts.push_back(std::make_unique<AccountImpl<HighInterestChecking>>(HighInterestChecking("Charlie", 3, 2600.0, 3.0, 2000.0)));
    accounts.push_back(std::make_unique<AccountImpl<HighInterestSavings>>(HighInterestSavings("Dave", 4, 1300.0, 1.0)));
    accounts.push_back(std::make_unique<AccountImpl<HighInterestSavingsWithMinBalance>>(HighInterestSavingsWithMinBalance("Eve", 5, 3200.0, 5.0, 2500.0)));
    accounts.push_back(std::make_unique<AccountImpl<CertificateOfDeposit>>(CertificateOfDeposit("Frank", 6, 5000.0, 6, 6, 4.0)));

    for (const auto& account : accounts) {
        account->performOperations();
        account->getAccountInfo();
    }

    return 0;
}