#include "CreditAccount.hpp"
//TODO Implement CreditAccount class

CreditAccount::CreditAccount(const int customerID) : Account(customerID) {
	// TODO implement
	
}

bool CreditAccount::checkWithdraw(Money amount) {
	// TODO implement
	if(amount.asCents()>=0){
		return true;
	}
	else{
		return false;
	}
}

bool CreditAccount::withdrawMoney(Money amount) {
	// TODO implement
	if(amount.asCents()>=0){
		balance.subtractCents(amount.asCents());
		return true;
	}
	else{
		return false;
	}
}


bool CreditAccount::checkDeposit(Money amount) {
	// TODO implement
	if(balance.asCents()+amount.asCents()<=500000 && amount.asCents()>=0){
		return true;
	}
	else{
		return false;
	}
}

bool CreditAccount::depositMoney(Money amount) {
	// TODO implement
	if(balance.asCents()+amount.asCents()<=500000 && amount.asCents()>=0){
		balance.add(amount);
		return true;
	}
	else{
		return false;
	}
}

CreditAccount::~CreditAccount() {
	// TODO implement
}
