// JULIEN SAVARY
#include "bank_account.hpp"

int main() {
    CheckingAccount checkingAccount;
    checkingAccount.setName("John Doe");
    checkingAccount.setAccountNumber("123456");
    checkingAccount.setBalance(1000.0);

    checkingAccount.retrieveAccountInfo();
    checkingAccount.deposit(200.0);
    checkingAccount.withdraw(150.0);
    checkingAccount.createMonthlyStatement();
    checkingAccount.writeCheck();

    SavingsAccount savingsAccount;
    savingsAccount.setName("Jane Smith");
    savingsAccount.setAccountNumber("789012");
    savingsAccount.setBalance(2000.0);

    savingsAccount.retrieveAccountInfo();
    savingsAccount.deposit(300.0);
    savingsAccount.withdraw(100.0);
    savingsAccount.createMonthlyStatement();

    CertificateOfDeposit cdAccount(12, 3.0, 1);
    cdAccount.setName("Alice Johnson");
    cdAccount.setAccountNumber("345678");
    cdAccount.setBalance(5000.0);

    cdAccount.retrieveAccountInfo();
    cdAccount.deposit(500.0);
    cdAccount.withdraw(100.0);  // Should print that withdrawals are not allowed
    cdAccount.createMonthlyStatement();

    return 0;
}

