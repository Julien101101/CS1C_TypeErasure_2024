class bankAccount {
public:
   virtual void retrieveAccountInfo();
   virtual void deposit(double : amount);
   virtual void withdraw(double : amount); 
   virtual void createMonthlyStatement();

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
   virtual void writeCheck();
};

class savingsAccount : bankAccount {
};

class certificateOfDeposit : bankAccount {
private:
   maturityMonths
   interestRate
   currentMonth
};
