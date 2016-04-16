#ifndef PRODUCT_H
#define PRODUCT_H
#include<iostream>
#include<string>

using namespace std;

class Product {
private:
	float price;
	string name;
public:
	Product();
	float getPrice();
	string getName();
};

#endif