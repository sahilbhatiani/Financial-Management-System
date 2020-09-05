#include "Transaction.hpp"
#include <string>

int Transaction::o = 0;

Transaction::Transaction(Account* fromAccount, Account* toAccount, Money amount) {
	//TODO Implement
	
	//initialises all the fields.
	this->fromAccount = fromAccount;
	this->toAccount = toAccount;
	this->ID = o++;
	state = PENDING;
	this->amount = amount;

	//if amount is negative, it makes the transaction amount value equal to 0.
	if(amount.asCents() < 0){
		this->amount.addCents(-(amount.asCents()));
	}
	
}

bool Transaction::performTransaction(){
	// TODO Implement
	//checks if the amount can be withdrawn from the fromAccount and deposited to the toAccount
	//if the conditions are satisfied, it performs the transaction.
	if(fromAccount->checkWithdraw(amount) == true && toAccount->checkDeposit(amount)==true){
		fromAccount->withdrawMoney(amount);
		toAccount->depositMoney(amount);
		state = COMPLETED;
		return true;
	}
	else{
		state = FAILED;
		return false;
	}
	
}

TransactionState Transaction::getState() const {
	//TODO Implement

	return state;
}

Money Transaction::getAmount() const {
	//TODO Implement
	return amount;
}

Account* Transaction::getToAccount() const {
	//TODO Implement
	return toAccount;
}

Account* Transaction::getFromAccount() const {
	//TODO Implement
	return fromAccount;
}


int Transaction::getID() const {
	//TODO Implement
	return ID;
}

Transaction::~Transaction() {
	// TODO implement
}

