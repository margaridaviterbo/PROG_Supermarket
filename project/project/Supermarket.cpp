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
	int i, pos_i, pos_f;
	int id;
	int clientId;
	string d;	
	Date date;
	string strProducts;
	string productName="";
	string trash;
	ifstream infile;

	infile.open("Transactions.csv");
	if (infile.fail()){
		cerr << "Error opening file " << "Transactions.csv";
		exit(1);
	}
	else{
		while (!infile.eof()){
			infile >> id;
			getline(infile, trash, ';');
			infile >> clientId;
			getline(infile, trash, ';');
			getline(infile, d, ';');
			date = Date(d);
			transactions.push_back(Transaction(id, clientId, date));
			getline(infile, strProducts);
			
			i = 0;
			while (i < strProducts.size()){
				if (strProducts.at(i) != ',')
					productName = productName + strProducts.at(i);
				else{
					transactions.back().addProduct(getProduct(productName));
					productName = "";
				}
				i++;
			}
		}
	}
	infile.close();
}

Product* Supermarket::getProduct(string productName){
	int i = 0;

   	while ( i<products.size()){
		if ((products.at(i)->getName()) != productName)
			break;
		i++;
	}
	return products.at(i);
}

void Supermarket::printClients(){
	int i;
	
	cout << setw(50) << "CLIENTS\n";
	cout << "_________________________________________________________________________________________\n\n";

	cout << setw(10) << "ID" <<
		setw(10) << "|" <<
		setw(30) << "Name" <<
		setw(20) << "|" <<
		setw(15) << "Amount Spent" <<
		setw(10) << '\n';

	cout << "_________________________________________________________________________________________\n";


	for (i = 0; i < clients.size(); i++){
		
		cout << setw(10) << clients.at(i).getId() <<
			setw(10) << "|" <<
			setw(40) << clients.at(i).getName() <<
			setw(10) << "|" <<
			setw(10) << clients.at(i).getAmountSpent() <<
			setw(10) << '\n';
	}
	cout << "\n\n";
}

void Supermarket::printProducts(){
	int i;

	for (i = 0; i < 55; i++)
		cout << endl;
	
	cout << setw(50) << "PRODUCTS\n";
	cout << "_________________________________________________________________________________________\n\n";

	cout << setw(30) << "Name" <<
		setw(15) << "|" <<
		setw(25) << "Price (euros)" << '\n';

	cout << "_________________________________________________________________________________________\n";


	for (i = 0; i < products.size(); i++){

		cout << setw(30) << products.at(i)->getName() <<
			setw(15) << "|" <<
			setw(20) << products.at(i)->getPrice() << '\n';
	}
}

void Supermarket::printTransactions(){
	int i,j;
	string print;

	cout << setw(50) << "TRANSACTIONS\n";
	cout << "____________________________________________________________________________________________________________________________\n\n";

	cout << setw(10) << "ID" <<
		setw(10) << "|" <<
		setw(20) << "Client ID" << 
		setw(10) << "|" <<
		setw(15) << "Date" <<
		setw(15) << "|" <<
		setw(40) << "Products" <<
		setw(40) << '\n';

	cout << "____________________________________________________________________________________________________________________________\n";


	/*for (i = 0; i < transactions.size(); i++){
		print = "\t" + transactions.at(i).getId() + '\t' + '|' + '\t' + transactions.at(i).getClientId() + '\t' + '|' + '\t' + transactions.at(i).getDate().getDate() + "\t|\t\t\t";
		print = print + (transactions.at(i).getProducts()).at(0)->getName();
		for (j = 1; j < transactions.at(i).getProducts().size(); j++){
			print = print + ", " + transactions.at(i).getProducts().at(j)->getName();
		}
		cout << print << endl;
	}
*/
	for (i = 0; i < transactions.size(); i++){

		cout << setw(10) << transactions.at(i).getId() <<
			setw(10) << "|" <<
			setw(15) << transactions.at(i).getClientId() <<
			setw(15) << "|" <<
			setw(20) << transactions.at(i).getDate().getDate() <<
			setw(20) << "|" <<
			setw(10) << (transactions.at(i).getProducts()).at(0)->getName();
		for (j = 1; j < transactions.at(i).getProducts().size(); j++){
			cout << ", " << (transactions.at(i).getProducts()).at(j)->getName();
		}
		cout << endl;
	}


}
