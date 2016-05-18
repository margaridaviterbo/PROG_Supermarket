#include"Transaction.h"

using namespace std;

Transaction::Transaction(int id, int clientId, Date date) {
	this->id = id;
	this->clientId = clientId;
	this->date = date;
}

Transaction::Transaction(int id, int clientId, Date date, vector<Product*> productsT){
	int i;
	this->id = id;
	this->clientId = clientId;
	this->date = date;
	for (i = 0; i < productsT.size(); i++){
		products.push_back(productsT.at(i));
	}
	
}

int Transaction::getId(){
	return id;
}

int Transaction::getClientId(){
	return clientId;
}

Date Transaction::getDate(){
	return date;
}

vector<Product*> Transaction::getProducts(){
	return products;
}

void Transaction::addProduct(Product* product){
	products.push_back(product);
}

bool Transaction::isEqual(int clientId){
	if (clientId == this->clientId)
		return true;
	else
		return false;
}