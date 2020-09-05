#include "SavingsAccount.hpp"
//TODO Implement the SavingsAccount class

SavingsAccount::SavingsAccount(const int customerID) : Account(customerID) {
	// TODO implement
	ss = 0;
	bonus.addDollars(10);
}

bool SavingsAccount::checkWithdraw(Money amount) {
	// TODO implement
	if((amount.asCents() >= 0) && (amount.asCents() <= this->getBalance().asCents())){
		return true;
	}
	else{
		return false;
	}
	
}

bool SavingsAccount::withdrawMoney(Money amount) {
	// TODO implement
	if((amount.asCents() >= 0) && (amount.asCents() <= this->getBalance().asCents())){
		balance.subtract(amount);
		if(this->bonus.asCents()>=200){
				bonus.subtractDollars(2);
		}
	
		return true;
	}
	else{
		return false;
	}
	
}

bool SavingsAccount::checkDeposit(Money amount) {
	// TODO implement
	if(amount.asCents() >= 0){
		return true;	
	}
	else{
		return false;
	}
	
}

bool SavingsAccount::depositMoney(Money amount) {
	// TODO implement
	if(amount.asCents() >= 0){
		balance.add(amount);
		ss++;
		if(ss==2){
			balance.add(this->getBonusValue());
			ss=0;
		}
		return true;	
	}
	else{
		return false;
	}
	
}

Money SavingsAccount::getBonusValue() const {
	// TODO implement
	
	return bonus;
}

SavingsAccount::~SavingsAccount() {
	// TODO implement
}


