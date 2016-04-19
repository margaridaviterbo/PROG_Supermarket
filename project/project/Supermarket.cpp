#include"Supermarket.h"

using namespace std;

Supermarket::Supermarket(){
	readClients();
	readProducts();
	readTransactions();
}

vector<Client> Supermarket::getClients(){
	return clients;
}

vector<Product*> Supermarket::getProducts(){
	return products;
}

vector<Transaction> Supermarket::getTransactions(){
	return transactions;
}

void Supermarket:: readClients(){
	int id;
	string name;
	float amountSpent;
	string trash;

	ifstream infile;
	infile.open("Clients.csv");
	if (infile.fail()){
		cerr << "Error opening file Clients.csv";
		exit(1);
	}
	else{
		while (!infile.eof()){
			infile >> id;
			getline(infile, trash, ';');
			getline(infile, name, ';');
			infile >> amountSpent;
			clients.push_back(Client(id, name, amountSpent));
		}
	}
	infile.close();
}

void Supermarket::readProducts(){
	string name;
	float price;
	string trash;
	ifstream infile;

	infile.open("Products.csv");
	if (infile.fail()){
		cerr << "Error opening file Products.csv";
		exit(1);
	}
	else{
		while (!infile.eof()){
			getline(infile, name, ';');
			infile>> price;
			getline(infile, trash, '\n');
			products.push_back(new Product(name, price));
		}
	}
	infile.close();
}

void Supermarket::readTransactions(){

	int id;
	int clientId;
	string d;	
	Date date;
	string productName;
	string trash;
	ifstream infile;

	infile.open("Transactions.csv");
	if (infile.fail()){
		cerr << "Error opening file " << "Transactions.csv";
		exit(1);
	}
	else{
		cout << "transactions\n";
		while (!infile.eof()){
			infile>> id;		// TODO CORRIGIR isto lê as virgulas
			infile >> clientId;
			getline(infile, trash, ';');
			getline(infile, d, ';');
			date=Date(d);
			transactions.push_back(Transaction(id, clientId, date));
			getline(infile, productName, ',');
			while (productName != "\n"){
				transactions.back().addProduct(getProduct(productName));
				getline(infile, productName, ',');
			}
		}
	}
	infile.close();
}

Product* Supermarket::getProduct(string productName){
	int i = 0;

	while (products.at(i)->getName() != productName){
		i++;
	}
	return products.at(i);
}

void Supermarket::printClients(){
	int i;

	cout << "\t\t\tCLIENTS\n";
	cout << "\t\t\t_______\n";
	cout << "\tID\t|\t\t\t\tName\t\t\t\t|\tAmount Spent\n";
	cout << "_________________________________________________________________________________________________________________________________";

	for (i = 0; i < clients.size(); i++){
		cout << "\t" << clients.at(i).getId() << "\t|\t\t\t\t" << clients.at(i).getName() << "\t\t\t\t|\t" << clients.at(i).getAmountSpent() << "\n";
	}
}

void Supermarket::printProducts(){
	int i;

	cout << "\t\t\tPRODUCTS\n";
	cout << "\t\t\t________\n";
	cout << "\t\t\tName\t\t\t|\tPrice\n";
	cout << "_________________________________________";

	for (i = 0; i < products.size(); i++){
		cout << "\t\t\t" << products.at(i)->getName() << "\t\t\t|\t" << products.at(i)->getPrice() << "\n";
	}
}

void Supermarket::printTransactions(){
	int i,j;
	string print;

	cout << "\t\t\tTRANSACTIONS\n";
	cout << "\t\t\t____________\n";
	cout << "\tID\t|\tClient ID\t|\tDate\t|\t\t\t\t\t\t\t\t\t\tPorducts\n";
	cout << "_________________________________________________________________________________________________________________________________";

	for (i = 0; i < transactions.size(); i++){
		print = "\t" + transactions.at(i).getId() + '\t' + '|' + '\t' + transactions.at(i).getClientId() + '\t' + '|' + '\t' + transactions.at(i).getDate().getDate() + "\t|\t\t\t";
		print = print + (transactions.at(i).getProducts()).at(0)->getName();
		for (j = 1; j < transactions.at(i).getProducts().size(); j++){
			print = print + ", " + transactions.at(i).getProducts().at(j)->getName();
		}
		cout << print << endl;
	}
}
