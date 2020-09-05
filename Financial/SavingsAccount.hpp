#include "Account.hpp"

#ifndef SAVINGSACCOUNT_HPP_
#define SAVINGSACCOUNT_HPP_

class SavingsAccount : public Account {
//TODO Implement members as needed
private:
	SavingsAccount& operator=(const SavingsAccount &other);
    SavingsAccount(const SavingsAccount &other);
	int ss;  //ss is our counter for keeping track of each 2nd succesful deposit, so we can add the bonus.
	Money bonus;
public:
	SavingsAccount(const int customerID);
	bool checkWithdraw(Money amount);
	bool checkDeposit(Money amount);
	bool withdrawMoney(Money amount);
	bool depositMoney(Money amount);
	Money getBonusValue() const;
	virtual ~SavingsAccount();
};

#endif /* SAVINGSACCOUNT_HPP_ */
