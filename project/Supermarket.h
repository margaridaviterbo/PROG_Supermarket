/*
this class simulates a supermarket and contains all the funtions called by the menu in main()
*/

#ifndef SUPERMARKET_H
#define SUPERMARKET_H
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
#include <stdio.h>
#include <time.h>
#include<algorithm>
#include"Client.h"
#include"Product.h"
#include"Transaction.h"
#include"Date.h"

using namespace std;

class Supermarket{
private:
	int nClients, nProducts, nTransactions;
	string clientFile;
	string productFile;
	string transactionFile;
	/*int lastClientAddedId;*/
	int position;
	int positionProduct;
	bool clientFound;
	bool transactionFound;
	vector<Client> clients;
	vector<Product*> products;
	vector<Transaction> transactions;
public:
	Supermarket();
	int getPositionProduct();
	vector<Client>& getClients();
	vector<Product*>& getProducts();
	vector<Transaction>& getTransactions();
	void readClients();
	void readProducts();
	void readTransactions();
	ifstream openFile(string fileName);
	void printClients();
	void printProducts();
	void printTransactions();
	bool searchClient();
	void printSelectedClient(int i);
	void searchTransaction();
	void printSelectedTransaction(int i);
	void addClient();
	void editClient();
	void deleteClient();
	void createTransaction();
	vector<Client*> bottomTen();
	void printBottomTen();
	void runRecomendationSystem();
	void callPersonalizedAdvertising(Client* client);
	void save();
	Product* getProduct(string productName);
	void invalidInput(int& input, string msg);
	void invalidInput(string& input, string msg);
	void invalidInput(string& input);
	int getMaxId();
};


#endif