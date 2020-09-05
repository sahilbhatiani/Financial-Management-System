#ifndef ACCOUNT_HPP_
#define ACCOUNT_HPP_
#include "Money.hpp"
class Account{
//TODO Implement members as needed
private:
	Account& operator=(const Account &other);
	Account(const Account &other);
	const int customerID;
	const int accountID;
	static int count;  //count is our counter that will be responsible for giving unique account ID's to every new account.
protected:
	Money balance;   //Declared this in private so that the child classes can access it.

public:
	Account(const int customerID);
	virtual bool checkDeposit(Money amount) = 0;
	virtual bool checkWithdraw(Money amount) = 0;
	virtual bool withdrawMoney(Money amount) = 0;
	virtual bool depositMoney(Money amount) = 0;
	int getCustomerID() const;
	int getAccountID() const;
	Money getBalance() const;
	virtual ~Account();
};



#endif /* ACCOUNT_HPP_ */
