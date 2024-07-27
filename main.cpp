// hw06 main.cpp
// PROFESSOR DRB
// JULIEN SAVARY


#include "bank_account.hpp"
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::string accountNumber = "12912412"; // Fixed account number for simplicity
    double initialBalance = 0.0;

    // Create an account
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    BankAccount account(name, accountNumber, initialBalance);

    std::cout << "Hi " << name << ", your account number will be #" << accountNumber << std::endl;

    int choice;
    do {
        std::cout << "\nWhat would you like to do today?\n";
        std::cout << "1. Withdraw\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Check Statement\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;

        double amount;
        switch (choice) {
            case 1:
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                account.withdraw(amount);
                break;

            case 2:
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                account.deposit(amount);
                break;

            case 3:
                account.createMonthlyStatement();
                break;

            case 4:
                std::cout << "Exiting. Have a great day!" << std::endl;
                break;

            default:
                std::cout << "Invalid choice! Please enter a number between 1 and 4." << std::endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
