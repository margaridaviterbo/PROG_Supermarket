#ifndef SUPERMARKET_H
#define SUPERMARKET_H
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
#include <stdio.h>
#include <time.h>
#include"Client.h"
#include"Product.h"
#include"Transaction.h"
#include"Date.h"

using namespace std;

class Supermarket{
private:
	string clientFile;
	string productFile;
	string transactionFile;
	int lastClientAddedId;
	int position;
	bool clientFound;
	bool transactionFound;
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
	ifstream openFile(string fileName);
	void printClients();
	void printProducts();
	void printTransactions();
	void searchClient();
	void printSelectedClient(int i);
	void searchTransaction();
	void printSelectedTransaction(int i);
	void addClient();
	void editClient();
	void deleteClient();
	void createTransaction();
	void save();
	Product* getProduct(string productName);
	void invalidInput(int& input, string msg);
	void invalidInput(string& input, string msg);
	void invalidInput(string& input);

};


#endif