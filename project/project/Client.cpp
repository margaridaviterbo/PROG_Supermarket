#include"Client.h"

using namespace std;

Client::Client(){

}

Client::Client(int id, string name, double amountSpent){
	this->id = id;
	this->name = name;
	this->amountSpent = amountSpent;
}

int Client::getId(){
	return id;
}

string Client::getName(){
	return name;
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

void Client::updateAmoutSpent(vector<Product*> newProducts){
	for (int i = 0; i < newProducts.size(); i++)
		amountSpent += newProducts.at(i)->getPrice();
}
