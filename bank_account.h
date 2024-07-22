class bankAccount {
public:
   virtual void retrieveAccountInfo() const = 0;
   virtual void deposit(double : amount) const = 0;
   virtual void withdraw(double : amount) const = 0; 
   virtual void createMonthlyStatement() const = 0;

private:
   string name;
   string accountNumber;
   double balance;
};

virtual void bankAccount::retrieveAccountInfo()
{

}

virtual void bankAccount::deposit(double : amount)
{

}

virtual void bankAccount::withdraw(double : amount)
{

}

virtual void bankAccount::createMonthlyStatement()
{

}



class checkingAccount : bankAccount {
public:
   virtual void writeCheck() const = 0;
};

class savingsAccount : bankAccount {
};

class certificateOfDeposit : bankAccount {
private:
   maturityMonths
   interestRate
   currentMonth
};
