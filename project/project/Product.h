#ifndef PRODUCT_H
#define PRODUCT_H
#include<iostream>
#include<string>

using namespace std;

class Product {
private:
	string name;
	float price;
	
public:
	Product(string name, float price);
	string getName();
	float getPrice();
	
};

#endif