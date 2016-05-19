#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"Supermarket.h"
#include"Client.h"
#include"Product.h"
#include"Transaction.h"


using namespace std;

//TODO melhorar c�digo e usar estruturas novas que o prof pede
//TODO ver onde usar nClients, nProducts, nTransactions que tive de criar por causa de obrigar a por na primeira linha dos ficheiros
 

void selectOption(int op, Supermarket &supermarket);
void Menu(Supermarket &supermarket);
void endMenu(Supermarket &supermarket);
void space();

enum option { EXIT, CLIENTS, PRODUCTS, TRANSACTIONS, SEARCH_CLIENT, SEARCH_TRANSACTION, ADD_CLIENT, EDIT_CLIENT, DELETE_CLIENT, CREATE_TRANSACTION, RECOMENDATION_SYSTEM, SAVE, MENU };

int main(){

	cout << "WELCOME TO SUPERMARKET MANAGER!!!\n";
	cout << "_________________________________\n\n";

	cout << "We need to update your database before you begin. Please enter the name of the files that contain the necessary information!\n\n";
	Supermarket supermarket;

	Menu(supermarket);

	system("pause");
	return 0;
}

void Menu(Supermarket &supermarket){
	int op;
	cout << "0 - Exit\n\n";
	cout << "1 - Clients List\n";
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
	selectOption(op, supermarket);
}

void endMenu(Supermarket &supermarket){
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

	selectOption(op, supermarket);
}

void space(){
	int i;
	for (i = 0; i < 50; i++)
		cout << endl;
}

void selectOption(int op, Supermarket &supermarket){

	switch (op) {
	case EXIT:
		exit(0);
		break;
	case CLIENTS:
		space();
		supermarket.printClients();
		endMenu(supermarket);
		break;
	case PRODUCTS:
		space();
		supermarket.printProducts();
		endMenu(supermarket);
		break;
	case TRANSACTIONS:
		space();
		supermarket.printTransactions();
		endMenu(supermarket);
		break;
	case SEARCH_CLIENT:
		space();
		supermarket.searchClient();
		endMenu(supermarket);
		break;
	case SEARCH_TRANSACTION:
		space();
		supermarket.searchTransaction();
		endMenu(supermarket);
		break;
	case ADD_CLIENT:
		space();
		supermarket.addClient();
		endMenu(supermarket);
		break;
	case EDIT_CLIENT:
		space();
		supermarket.editClient();
		endMenu(supermarket);
		break;
	case DELETE_CLIENT:
		space();
		supermarket.deleteClient();
		endMenu(supermarket);
		break;
	case CREATE_TRANSACTION:
		space();
		supermarket.createTransaction();
		endMenu(supermarket);
		break;
	case RECOMENDATION_SYSTEM:
		space();
//		supermarket.runRecomendationSystem();
		endMenu(supermarket);
		break;
	case SAVE:
		space();
		supermarket.save();
		endMenu(supermarket);
		break;
	case MENU:
		space();
		cout << "MENU:\n";
		cout << "_____\n\n";
		Menu(supermarket);
		break;
	}
}
