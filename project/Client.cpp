#include"Client.h"

using namespace std; 

Client::Client(){

}

Client::Client(int id, string name, Date subscriptionDate, double amountSpent){
	this->id = id;
	this->name = name;
	this->subscriptionDate = subscriptionDate;
	this->amountSpent = amountSpent;
}

int Client::getId(){
	return id;
}

string Client::getName(){
	return name;
}

Date Client::getSubscriptionDate(){
	return subscriptionDate;
}

void Client::setName(string name){
	this->name = name;
}

double Client::getAmountSpent(){
	return amountSpent;
}

bool Client::isEqual(int id){
	if (id == this->id)
		return true;
	else
		return false;
}

bool Client::isEqual(string name){
	if (name == this->name)
		return true;
	else
		return false;
}

void Client::updateAmountSpent(vector<Product *> newProducts){
	for (int i = 0; i < newProducts.size(); i++)
		amountSpent += newProducts.at(i)->getPrice();
}
