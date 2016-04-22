#ifndef SUPERMARKET_H
#define SUPERMARKET_H
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
#include"Client.h"
#include"Product.h"
#include"Transaction.h"
#include"Date.h"

using namespace std;

class Supermarket{
private:
	int lastClientAddedId;
	vector<Client> clients;
	vector<Product*> products;
	vector<Transaction> transactions;
public:
	Supermarket();
	vector<Client> getClients();
	vector<Product*> getProducts();
	vector<Transaction> getTransactions();
	void readClients();
	void readProducts();
	void readTransactions();
	void printClients();
	void printProducts();
	void printTransactions();
	void searchClient();
	void searchTransaction();
	void addClient();
	Product* getProduct(string productName);

};


#endif