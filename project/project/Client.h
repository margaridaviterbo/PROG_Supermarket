#ifndef CLIENT_H
#define CLIENT_H
#include<iostream>
#include<string>
#include<vector>
#include"Product.h"

using namespace std;

class Client{

private:
	int id;
	string name;
	double amountSpent;
public:
	Client();
	Client(int id, string name, double amountSpent);
	int getId();
	string getName();
	void setName(string name);
	double getAmountSpent();
	bool isEqual(int id);
	bool isEqual(string name);
	void updateAmoutSpent(vector<Product*> newProducts);
};







#endif