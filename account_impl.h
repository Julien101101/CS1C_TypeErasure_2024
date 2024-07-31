#ifndef ACCOUNT_IMPL_H
#define ACCOUNT_IMPL_H

#include "accounts.h"

template <typename T>
class AccountImpl : public Account {
public:
    AccountImpl(T account) : account_(std::move(account)) {}
    
    void getAccountInfo() const override {
        account_.getAccountInfo();
    }
    
    void performOperations() override {
        account_.performOperations();
    }

private:
    T account_;
};

#endif // ACCOUNT_IMPL_H