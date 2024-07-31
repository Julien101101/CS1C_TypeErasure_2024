#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>

// Type-erased base class
class Account {
public:
    virtual ~Account() = default;
    virtual void getAccountInfo() const = 0;
    virtual void performOperations() = 0;
};

#endif // ACCOUNTS_H