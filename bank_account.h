class bankAccount {
public:
   void virtual retrieveAccountInfo();
   void virtual deposit(double : amount);
   void virtual withdraw(double : amount); 
   void virtual createMonthlyStatement();

private:
   string name;
   string accountNumber;
   double balance;
};

void virtual bankAccount::retrieveAccountInfo()
{

}

void virtual bankAccount::deposit(double : amount)
{

}

void virtual bankAccount::withdraw(double : amount)
{

}

void virtual bankAccount::createMonthlyStatement()
{

}



class checkingAccount : bankAccount {
public:
   void virtual writeCheck();
};

class savingsAccount : bankAccount {
};

class certificateOfDeposit : bankAccount {
private:
   maturityMonths
   interestRate
   currentMonth
};
