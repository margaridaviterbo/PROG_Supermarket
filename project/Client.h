/*
Class that simulates a client.
*/


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
	int id;								//Client id
	string name;						//Client Name
	Date subscriptionDate;				//Client subscription date
	double amountSpent;					//Total amount spent by the client in all the transactions made
	vector<Transaction> transactions;	//transactions made by the client
public:
	Client();																//empty constructor
	Client(int id, string name, Date subscriptionDate, double amountSpent);	//constructor
	int getId();															//return the client id
	string getName();														//returns the client name
	Date getSubscriptionDate();												//returns the client subscription date
	void setName(string name);												//changes the atribute name
	double getAmountSpent();												//returns the client total amount spent
	vector<Transaction> getTransactions();									//returns the clients transactions
	bool isEqual(int id);													//compares clients by id
	bool isEqual(string name);												//compares clients by name
	void updateAmountSpent(vector<Product *> newProducts);					//adds the amount of a new transactions of the client to the total amount spent by the client
	void addTransaction(Transaction transaction);							//adds a new transaction to the vector transactions of the client
	bool printTransactions();												//prints the client transactions
	bool operator<(Client client);											//compares names of the clients 
};
#endif
