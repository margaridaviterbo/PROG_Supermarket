//TODO definir funções

#include"Product.h"

#include <iostream>
#include<string>
#include<fstream>

using namespace std;

float Product::getPrice(){
	string temp;
	ifstream infile;
	infile.open("Product.csv");
	if (infile.fail()){
		cerr << "Error opening " << "Product.csv";
		return 1;
	}
	else{
		getline(infile, temp, ';');
		getline(infile, price);
	}
	infile.close();
	return price;
}