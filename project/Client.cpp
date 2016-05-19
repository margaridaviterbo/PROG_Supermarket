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

vector<Transaction> Client::getTransactions(){
	return transactions;
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

void Client::addTransaction(Transaction transaction){
	int i;
	Transaction tempTransaction;
	transactions.push_back(transaction);
	i = transactions.size() - 1;
	while (i > 0 && transactions.at(i).getDate() <= transactions.at(i - 1).getDate()){
		tempTransaction = transactions.at(i);
		transactions.at(i) = transactions.at(i - 1);
		transactions.at(i - 1) = tempTransaction;
		i--;
	}
}

bool Client::printTransactions(){
	int i,j;
	if (transactions.size() > 0){
		for (i = 0; i < transactions.size(); i++){
			cout << "Transaction ID: " << transactions.at(i).getId()
				<< "\tClient ID: " << transactions.at(i).getClientId()
				<< "\tDate: " << transactions.at(i).getDate().getDate()
				<< "\tProducts: " << transactions.at(i).getProducts().at(0)->getName();
			for (j = 1; j < transactions.at(i).getProducts().size(); j++)
				cout << ", " << transactions.at(i).getProducts().at(j)->getName();
			cout << endl;
		}
		cout << endl;
		return true;
	}
	else
		return false;
}

bool Client::operator<(Client client){
	if (name < client.name)
		return true;
	else
		return false;
}