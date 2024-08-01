#ifndef ACCOUNT_IMPL_H
#define ACCOUNT_IMPL_H

#include "accounts.h"

struct TypeErased
{
    template<typename T>
    TypeErased(T&& value) { *this = value; }

    template<typename T>
    TypeErased& operator=(T&& value)
    { 
        m_value.reset(new Model<T>(value));
        return *this;
    }

    void getAccountInfo() const
    { m_value->getAccountInfo();}
    
    void performOperations()
    { m_value->performOperations(); }
private:
    struct Concept {
        virtual ~Concept() {}
        virtual void getAccountInfo() const = 0;
        virtual void performOperations() = 0;
};
    template<typename T>
    struct Model : Concept {
        Model(T const & value) : m_val(value) {}

        void getAccountInfo() const override
        { m_val.getAccountInfo(); }
        void performOperations() override
        { m_val.performOperations(); }

        T m_val;
    };
private:
    std::unique_ptr<Concept> m_value;
};

#endif // ACCOUNT_IMPL_H