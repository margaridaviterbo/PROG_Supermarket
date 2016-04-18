
#include"Product.h"
#include"Supermarket.h"


using namespace std;


Product::Product(string name, float price){
	this->name = name;
	this->price = price;
}

string Product::getName(){
	return name;
}

float Product::getPrice(){
	return price;
}


