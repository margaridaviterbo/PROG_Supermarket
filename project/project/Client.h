#ifndef CLIENT_H
#define CLIENT_H
#include<iostream>
#include<string>

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
};







#endif