#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"Supermarket.h"
#include"Client.h"
#include"Product.h"
#include"Transaction.h"


using namespace std;

//TODO AO SUBMETER O PROJETO E O READ ME SUBMETER OS MEUS TRES FICHEIROS 

int main(){
	enum option { CLIENTS, PRODUCTS, TRANSACTIONS };
	int op;
	Supermarket supermarket;
	
	cout << "WELCOME TO SUPERMARKET MANAGER!!!\n";
	cout << "_________________________________\n\n";
	cout << "1 - Cients\n";
	cout << "2 - Products\n";
	cout << "3 - Transactions\n\n";
	cout << "Please choose an option:\n";
	cin >> op;
	
	op--;
	switch (op) {
	case CLIENTS:
		supermarket.printClients();
		break;
	case PRODUCTS:
		supermarket.printProducts();
		break;
	case TRANSACTIONS:
		supermarket.printTransactions();
		break;
	}


	system("pause");
	return 0;
}







