#ifndef TRANSACTION_HPP_
#define TRANSACTION_HPP_

#include <string>
#include "Account.hpp"
#include "Money.hpp"

enum TransactionState {
	COMPLETED,
	PENDING,
	FAILED
};

class Transaction {
	//TODO Implement members as needed
private:
	Transaction& operator=(const Transaction &other);
    Transaction(const Transaction &other);
	static int o;  //o is our counter for giving unique id's to each new transaction created.
	int ID;
	Account *fromAccount;
	Account *toAccount;
	Money amount;
protected:
	TransactionState state;
public:
	Transaction(Account* fromAccount, Account* toAccount, Money amount);
	bool performTransaction();
	TransactionState getState() const;
	Money getAmount() const;
	Account* getFromAccount() const;
	Account* getToAccount() const;
	int getID() const;
	virtual ~Transaction();
};



#endif /* TRANSACTION_HPP_ */
