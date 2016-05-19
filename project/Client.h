#ifndef CLIENT_H
#define CLIENT_H
#include<iostream>
#include<string>
#include<vector>
#include"Product.h"
#include"Date.h"
#include"Transaction.h"

using namespace std;

class Client{

private:
	int id;
	string name;
	Date subscriptionDate;
	double amountSpent;
	vector<Transaction> transactions;
public:
	Client();
	Client(int id, string name, Date subscriptionDate, double amountSpent);
	int getId();
	string getName();
	Date getSubscriptionDate();
	void setName(string name);
	double getAmountSpent();
	vector<Transaction> getTransactions();
	bool isEqual(int id);
	bool isEqual(string name);
	void updateAmountSpent(vector<Product *> newProducts);
	void addTransaction(Transaction transaction);
	bool printTransactions();
	bool operator<(Client client);
};
#endif
