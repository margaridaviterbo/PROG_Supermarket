#ifndef TRANSACTION_H
#define TRANSACTION_H
#include"Product.h"
#include"Date.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Transaction{
private:
	int id;
	int clientId;
	Date date;	
	vector<Product*> products;
public:
	Transaction();
	Transaction(int id, int clientId, Date date);	
	Transaction(int id, int clientId, Date date, vector<Product*> productsT);
	int getId();
	int getClientId();
	Date getDate();
	vector<Product*> getProducts();
	void addProduct(Product* product);
	bool isEqual(int clientId);
};


#endif