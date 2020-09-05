#include "FinancialServicesSystem.hpp"
#include <iostream>
#include <vector>

FinancialServicesSystem::FinancialServicesSystem() {
	// TODO implement
}

std::string FinancialServicesSystem::author(){
	// TODO implement
	return "sbha899";
}

bool FinancialServicesSystem::addCustomer(Customer* customer) {
	// TODO implement
	//checks if this customer is already present in the system. 
	// If they are not, it adds them to the system.
	bool isverified = verifyCustomer(customer->getID());
	if(!isverified){
		customerList.push_back(customer);
	}
	return !isverified;
	
}

bool FinancialServicesSystem::addAccount(Account* account) {
	// TODO implement
	// Checks for account and customer. If the customer is already present in the system and 
	// the account is not, it adds the account succesfully. Otherwise doesnt add the account.
	bool isAccountVerified = verifyAccount(account->getAccountID());
	bool isCustomerVerified = verifyCustomer(account->getCustomerID());
	if(isCustomerVerified == true && isAccountVerified == false){
		accountList.push_back(account);
		return true;
	}
	else{return false;}

}

bool FinancialServicesSystem::addTransaction(Transaction* transaction) {
	// TODO implement
	//Checks if the to and from accounts are both present in the system. Also checks if 
	// the transaction state is pending and that the transaction is not already present 
	// in the system.If these conditions are satisfied, it adds the transaction to the 
	// transactionList.
	bool isAccount1Verified = verifyAccount(transaction->getFromAccount()->getAccountID());
	bool isAccount2Verified = verifyAccount(transaction->getToAccount()->getAccountID());
	bool isTransactionVerified = verifyTransaction(transaction->getID());
	if(isAccount1Verified == true && isAccount2Verified==true && transaction->getState() == PENDING && isTransactionVerified == false){
		transactionList.push_back(transaction);
		return true;
	}
	else{
		return false;
	}

	
}


std::vector<Transaction*> FinancialServicesSystem::performPendingTransactions() {
	// TODO implement
	std::vector<Transaction*> v;

	//uses a bubble sort algorithm to sort the transactionList in ascending order of IDs.
	int index = transactionList.size() - 1;
	while(index >=0){
		for(unsigned int i=0;i<index;i++){
			if(transactionList[i]->getID() > transactionList[i+1]->getID())
				std::swap(transactionList[i],transactionList[i+1]);
		}
		index = index - 1;
	}

	//Now all PENFING transactions are carried out in ascending order of IDs.
	for(unsigned int i=0;i<transactionList.size();i++){
		if(transactionList[i]->getState() == PENDING){
			bool x = transactionList[i]->performTransaction();
			if(x == true){
				v.push_back(transactionList[i]);
			}

		}
	}
		
	return v;
}

Money FinancialServicesSystem::getCustomerBalance(int customerID) const {
	// TODO implement
	//Sums up all the money present in all the accounts owned by this particular customer.
	int money = 0;
	for(unsigned int i=0;i<accountList.size();i++){
		if(accountList[i]->getCustomerID() == customerID){
			money = money + accountList[i]->getBalance().asCents();
		}
	}
	Money customerBalance(money/100,money%100);
	return customerBalance;

	
}

bool FinancialServicesSystem::verifyCustomer(int customerID) const {
	// TODO implement
	//Iterates through each customer in the system, and checks if this customer ID matches
	//any one in the system. If yes,returns true otherwise false.
	bool ismatch = false;
	for(unsigned int i=0;i<customerList.size();i++){
		Customer* sample = customerList[i];
		if(customerID == sample->getID()){
			ismatch = true;
		}
	}
	return ismatch;
}

bool FinancialServicesSystem::verifyAccount(int accountID) const {
	// TODO implement
	//Similar working to verifyCustomer and verifyTransaction
	bool ismatch = false;
	for(unsigned int i=0;i<accountList.size();i++){
		Account* sample = accountList[i];
		if(accountID == sample->getAccountID()){
			ismatch = true;
		}
	}
	return ismatch;
}

bool FinancialServicesSystem::verifyTransaction(int transactionID) const {
	// TODO implement
	//Similar working to verifyCustomer and verifyAccount
	bool ismatch = false;
	for(unsigned int i=0;i<transactionList.size();i++){
		Transaction* sample = transactionList[i];
		if(transactionID == sample->getID()){
			ismatch = true;
		}
	}
	return ismatch;
}

std::vector<Account*> FinancialServicesSystem::getAccounts() const {
	// TODO implement

	return accountList;
}

std::vector<Customer*> FinancialServicesSystem::getCustomers() const {
	// TODO implement
	
	return customerList;
}

std::vector<Transaction*> FinancialServicesSystem::getTransactions() const {
	// TODO implement

	return transactionList;
}

std::vector<Transaction*> FinancialServicesSystem::getTransactions(TransactionState state) const {
	// TODO implement
	//this functions returns a list of only those transactions that have the same state
	//as is given in the input.
	std::vector<Transaction*> v;
	for(unsigned int i=0;i<transactionList.size();i++){
		Transaction* sample = transactionList[i];
		if(state == sample->getState()){
			v.push_back(sample);
		}
	}
	return v;
}

FinancialServicesSystem::~FinancialServicesSystem() {
	// TODO implement
}

