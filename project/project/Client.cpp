#include"Client.h"

using namespace std;

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
