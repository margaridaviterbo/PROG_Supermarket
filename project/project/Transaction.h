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
	string date;	//TODO mudar data para objeto de uma classe provavelmente pre definida Date
	vector<Product*> products;
public:
	Transaction(int id, int clientId, string date);	//os parametros são passados por referencia quando quero alterar o valor ou forem muito grandes para andar a fazer copia e nesse caso uso const &parametro
	int getId();
	int getClientId();
	string getDate();
	vector<Product*> getProducts();
	void addProduct(Product* product);
};


#endif