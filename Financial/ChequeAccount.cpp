#include "ChequeAccount.hpp"
//TODO Implement ChequeAccount class

ChequeAccount::ChequeAccount(const int customerID) : Account(customerID) {
	// TODO implement
	this->transactionFee = new Money(1,0);
}

bool ChequeAccount::checkWithdraw(Money amount){
	if(amount.asCents()>=0 && (amount.asCents() + transactionFee->asCents())<=(this->getBalance().asCents())){
		return true;
	}
	else{
		return false;
	}
}
  
bool ChequeAccount::withdrawMoney(Money amount) {
	// TODO implement
	
	bool isWithdrawVerified = checkWithdraw(amount);
	if(isWithdrawVerified == true){
		balance.subtract(amount);
		balance.subtract(*(getTransactionFee()));
		transactionFee->addDollars(1);
	}
	return isWithdrawVerified;
	
}

bool ChequeAccount::checkDeposit(Money amount) {
	//TODO implement
	if(amount.asCents() >=0 && amount.asCents()<=300000){
		return true;
	}
	else{
		return false;
	}
	
}

bool ChequeAccount::depositMoney(Money amount) {
	//TODO implement
	if(amount.asCents() >=0 && amount.asCents()<=300000){
		balance.add(amount);
		return true;
	}
	else{
		return false;
	}
	
}

Money* ChequeAccount::getTransactionFee() const {
	// TODO implement
	return transactionFee;
}

ChequeAccount::~ChequeAccount() {
	// TODO implement
}

