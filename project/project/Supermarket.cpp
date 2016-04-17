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
	infile.open("Client.csv");
	if (infile.fail()){
		cerr << "Error opening fie " << "Client.csv";
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

	infile.open("Produtos.csv");
	if (infile.fail()){
		cerr << "Error opening file " << "Products.csv";
		exit(1);
	}
	else{
		while (!infile.eof()){
			getline(infile, name, ';');
			cin >> price;
			getline(infile, trash, '\n');
			products.push_back(new Product(name, price));
		}
	}
	infile.close();
}

void Supermarket::readTransactions(){

	int id;
	int clientId;
	string date;	//TODO !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	string productName;
	string trash;
	ifstream infile;

	infile.open("Transactions.csv");
	if (infile.fail()){
		cerr << "Error opening file " << "Transactions.csv";
		exit(1);
	}
	else{
		while (!infile.eof()){
			cin >> id;
			cin >> clientId;
			getline(infile, trash, ';');
			getline(infile, date, ';');
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

