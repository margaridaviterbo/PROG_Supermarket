#ifndef TRANSACTION_H
#define TRANSACTION_H
#include"Product.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Transaction{
private:
	int id;
	int clientId;
	string date;	//TODO mudar data para objeto de uma classe provavelmente pre definida Date
	vector<Product> products;
public:
	Transaction(int id, int clientId, string date, vector<Product> products);
	int getId();
	int getClientId();
	string getDate();
	vector<Product> getProducts();
};





#endif