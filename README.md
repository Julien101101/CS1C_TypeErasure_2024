# Bankroll

Banks offer various types of financial accounts, such as savings, checking, certificate of deposits, and money market, to attract customers as well as meet their specific needs. Two of the most commonly used accounts are savings and checking. Each of these accounts has various options. For example, you may have a savings account that requires no minimum balance but has a lower interest rate. Similarly, you may have a checking account that limits the number of checks you may write. Another type of account that is used to save money for the long term is certificate of deposit (CD).

In this programming exercise, you will use abstract classes and pure virtual functions to design classes to manipulate various types of accounts. For simplicity, assume that the bank offers three types of accounts: savings, checking, and certificate of deposit, as described next.

## Abstract Classes and Inheritance Hierarchy

### `bankAccount`
Abstract base class representing a bank account.

- `name`
- `accountNumber`
- `balance`
- `retrieveAccountInfo()`: pure virtual function
- `deposit(amount)`: pure virtual function
- `withdraw(amount)`: pure virtual function
- `createMonthlyStatement()`: pure virtual function

### `checkingAccount`
Abstract class inheriting from `bankAccount`, represents a checking account.

- `writeCheck()`: pure virtual function

### `serviceChargeChecking`
Subclass of `checkingAccount`, represents a checking account with service charges.

### `noServiceChargeChecking`
Subclass of `checkingAccount`, represents a checking account without service charges.

### `highInterestChecking`
Subclass of `noServiceChargeChecking`, represents a checking account with high interest rates.

### `savingsAccount`
Subclass of `bankAccount`, represents a savings account.

### `highInterestSavings`
Subclass of `savingsAccount`, represents a high-interest savings account.

### `certificateOfDeposit`
Subclass of `bankAccount`, represents a certificate of deposit account.

- `maturityMonths`
- `interestRate`
- `currentMonth`

## Instructions for Programming Exercise

Define the above classes and their methods in your programming assignment. Ensure to implement necessary instance variables, constants, and functions as described. Design a program to test these classes, including a typescript output (`typescript` command) and a `git log` showing at least three commits.

Submit your assignment as a tar package containing all relevant source and header files by the due date specified.

