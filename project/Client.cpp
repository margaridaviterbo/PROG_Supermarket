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

double Client::getAmountSpent(){
	return amountSpent;
}

void Client::setName(string name){
	this->name = name;
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

bool Client::operator<(Client client){
	if (name < client.name)
		return true;
	else
		return false;
}