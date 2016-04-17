#include"Transaction.h"

using namespace std;



Transaction::Transaction(int id, int clientId, string date, vector<Product> products) {
	this->id = id;
	this->clientId = clientId;
	this->date = date;
	this->products = products;
}

int Transaction::getId(){
	return id;
}

int Transaction::getClientId(){
	return clientId;
}

string Transaction::getDate(){
	return date;
}

vector<Product> Transaction::getProducts(){
	return products;
}

