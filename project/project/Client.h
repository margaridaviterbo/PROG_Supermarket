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
	int getId();
	string getName();
	double getAmountSpent;

};







#endif