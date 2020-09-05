#include "Customer.hpp"
#include <string>

int Customer::count = 0;

Customer::Customer(const std::string &name) {
	// TODO implement
	this->name = name;
	this->id = count++;

}

std::string Customer::getName() const {
	// TODO implement
	return this->name;
}

int Customer::getID() const {
	// TODO implement
	return this->id;
}

Customer::~Customer() {
	// TODO implement
}

