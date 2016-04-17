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
