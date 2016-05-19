#ifndef CLIENT_H
#define CLIENT_H
#include<iostream>
#include<string>
#include<vector>
#include"Product.h"
#include"Date.h"

using namespace std;

class Client{

private:
	int id;
	string name;
	Date subscriptionDate;
	double amountSpent;
public:
	Client();
	Client(int id, string name, Date subscriptionDate, double amountSpent);
	int getId();
	string getName();
	Date getSubscriptionDate();
	void setName(string name);
	double getAmountSpent();
	bool isEqual(int id);
	bool isEqual(string name);
	void updateAmountSpent(vector<Product *> newProducts);
	bool operator<(string name);
	void setId(int id);
	void setSubscriptionDate(const Date &subscriptionDate);
	void setAmountSpent(double amountSpent);
};

#endif