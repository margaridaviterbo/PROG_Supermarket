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
	Transaction(int id, int clientId, Date date);	//os parametros são passados por referencia quando quero alterar o valor ou forem muito grandes para andar a fazer copia e nesse caso uso const &parametro
	int getId();
	int getClientId();
	Date getDate();
	vector<Product*> getProducts();
	void addProduct(Product* product);
};


#endif