#ifndef SUPERMARKET_H
#define SUPERMARKET_H
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"Client.h"
#include"Product.h"
#include"Transaction.h"

using namespace std;

class Supermarket{
private:
	vector<Client> clients;
	vector<Product> products;
	vector<Transaction> transactions;
public:
	Supermarket();
	void readClients();
	void readProducts();
	void readTransactions();


};


#endif