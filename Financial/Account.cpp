#include "Account.hpp"

 
int Account::count=0;

Account::Account(const int customerID) : customerID(customerID),accountID(count++) {
	// TODO implement
	

	
}



int Account::getAccountID() const {
	// TODO implement
	return accountID;

}

int Account::getCustomerID() const {
	// TODO implement
	return customerID;
}

Money Account::getBalance() const {
	// TODO implement

	return balance;
}

Account::~Account() {
	// TODO implement
}

