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
//TODO criar funçao para dar 50 enters para nao se ver cenas em cima (tipo parece que abriu nova janela)

void selectOption(int op);
void Menu();
void endMenu();
void space();

enum option { EXIT, CLIENTS, PRODUCTS, TRANSACTIONS, SEARCH_CLIENT, SEARCH_TRANSACTION, MENU };
Supermarket supermarket;

int main(){

	cout << "WELCOME TO SUPERMARKET MANAGER!!!\n";
	cout << "_________________________________\n\n";

	Menu();

	system("pause");
	return 0;
}

void Menu(){
	int op;
	cout << "0 - Exit\n";
	cout << "1 - Cients List\n";
	cout << "2 - Products List\n";
	cout << "3 - Transactions List\n";
	cout << "4 - Search Client\n";
	cout << "5 - Search Transaction\n\n";
	cout << "Please choose an option:\n";
	cin >> op;
	cout << endl;

	while (cin.fail() || op<0 || op>5) {
		cout << "Invalid input! Please enter a number from the menu.\n";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> op;
		cout << endl;
	}
	selectOption(op);
}

void endMenu(){
	int op;
	cout << "\n\n";
	cout << "Choose an option:\n\n";
	cout << "0 - Exit\n";
	cout << "6 - Return to Menu\n";
	cin >> op;
	cout << endl;

	while (cin.fail() || (op!=0 && op!=6)) {	
		cout << "Invalid input! Please enter a number from the menu.\n";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> op;
		cout << endl;
	}

	selectOption(op);
}

void space(){
	int i;
	for (i = 0; i < 50; i++)
		cout << endl;
}

void selectOption(int op){

	switch (op) {
	case EXIT:
		exit(0);
		break;
	case CLIENTS:
		space();
		supermarket.printClients();
		endMenu();
		break;
	case PRODUCTS:
		space();
		supermarket.printProducts();
		endMenu();
		break;
	case TRANSACTIONS:
		space();
		supermarket.printTransactions();
		endMenu();
		break;
	case SEARCH_CLIENT:
		space();
		supermarket.searchClient();
		endMenu();
		break;
	case SEARCH_TRANSACTION:
		space();
//		supermarket.searchTransaction();
		endMenu();
		break;
	case MENU:
		space();
		cout << "MENU:\n";
		cout << "_____\n\n";
		Menu();
		break;
	}
}




