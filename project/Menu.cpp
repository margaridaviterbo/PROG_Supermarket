#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"Supermarket.h"
#include"Client.h"
#include"Product.h"
#include"Transaction.h"


using namespace std;
 

void selectOption(int op);
void Menu();
void endMenu();
void space();

enum option { EXIT, CLIENTS, PRODUCTS, TRANSACTIONS, SEARCH_CLIENT, SEARCH_TRANSACTION, ADD_CLIENT, EDIT_CLIENT, DELETE_CLIENT, CREATE_TRANSACTION, RECOMENDATION_SYSTEM, SAVE, MENU };
Supermarket supermarket;

int main(){
	int x;
	cout << "WELCOME TO SUPERMARKET MANAGER!!!\n";
	cout << "_________________________________\n\n";

	Menu();

	system("pause");
	cin >> x;
	return 0;
}

void Menu(){
	int op;
	cout << "0 - Exit\n\n";
	cout << "1 - Cients List\n";
	cout << "2 - Products List\n";
	cout << "3 - Transactions List\n" << endl;
	cout << "___________________________________\n" << endl;
	cout << "4 - Search Client\n";
	cout << "5 - Search Transaction\n";
	cout << "___________________________________\n" << endl;
	cout << "6 - Add Client\n";
	cout << "7 - Edit Client\n";
	cout << "8 - Delete Client\n" << endl;
	cout << "___________________________________\n" << endl;
	cout << "9 - Create transaction\n";
	cout << "10- Recomendation System\n";
	cout << "11- Save\n\n";
	cout << "Please choose an option:\n";
	cin >> op;
	cout << endl;

	while (cin.fail() || op<0 || op>11) {
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
	cout << "12 - Return to Menu\n";
	cin >> op;
	cout << endl;

	while (cin.fail() || (op!=0 && op!=12)) {	
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
		supermarket.searchTransaction();
		endMenu();
		break;
	case ADD_CLIENT:
		space();
		supermarket.addClient();
		endMenu();
		break;
	case EDIT_CLIENT:
		space();
		supermarket.editClient();
		endMenu();
		break;
	case DELETE_CLIENT:
		space();
		supermarket.deleteClient();
		endMenu();
		break;
	case CREATE_TRANSACTION:
		space();
		supermarket.createTransaction();
		endMenu();
		break;
	case RECOMENDATION_SYSTEM:
		space();
//		supermarket.runRecomendationSystem();
		endMenu();
		break;
	case SAVE:
		space();
		supermarket.save();
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




