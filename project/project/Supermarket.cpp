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

void Supermarket::readClients(){
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
			lastClientAddedId = clients.back().getId();
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
			infile >> price;
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
	string productName = "";
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
				if (strProducts.at(i) != ','){
					productName = productName + strProducts.at(i);
				}
				else{
					transactions.back().addProduct(getProduct(productName));
					productName = "";
				}
				i++;
			}
			strProducts.clear();
			productName.clear();

		}
	}
	infile.close();
}


Product* Supermarket::getProduct(string productName){
	int i = 0;

	while (i < products.size()){
		if (products.at(i)->isEqual(productName))
			return products.at(i);
		i++;
	}
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
	int i, j;
	string print;

	cout << setw(85) << "TRANSACTIONS\n";
	cout << "____________________________________________________________________________________________________________________________________________________________________\n\n";

	cout << setw(10) << "ID" <<
		setw(10) << "|" <<
		setw(20) << "Client ID" <<
		setw(10) << "|" <<
		setw(15) << "Date" <<
		setw(15) << "|" <<
		setw(50) << "Products" <<
		setw(40) << '\n';

	cout << "____________________________________________________________________________________________________________________________________________________________________\n";

	for (i = 0; i < transactions.size(); i++){

		cout << setw(10) << transactions.at(i).getId() <<
			setw(10) << "|" <<
			setw(15) << transactions.at(i).getClientId() <<
			setw(15) << "|" <<
			setw(20) << transactions.at(i).getDate().getDate() <<
			setw(10) << "|" <<
			setw(15) << transactions.at(i).getProducts().at(0)->getName();

		for (j = 1; j < transactions.at(i).getProducts().size(); j++){
			cout << ", " << transactions.at(i).getProducts().at(j)->getName();
		}
		cout << endl;
	}
}

void Supermarket::searchClient(){
	int i;
	int op;
	int id;
	string name;
	bool found;

	cout << "Search client by: " << endl << "1 - ID" << endl << "2 - Complete Name" << endl << endl;
	cin >> op;
	cout << endl;

	while (cin.fail() || (op != 1 && op != 2)) {
		cerr << "Invalid input! Please enter a number from the menu.\n";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> op;
		cout << endl;
	}

	cin.clear();
	cin.ignore();


	if (op == 1){
		cout << "Client ID: ";
		cin >> id;
		cout << endl;

		while (cin.fail()) {
			cerr << "Invalid input!\n";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> id;
			cout << endl;
		}
		found = false;
		for (i = 0; i < clients.size(); i++){
			if (clients.at(i).isEqual(id)){
				cout << "ID: " << clients.at(i).getId() << "\t\tName: " << clients.at(i).getName() << "\t\tAmount Spent: " << clients.at(i).getAmountSpent();
				position = i;
				found = true;
			}
		}
		if (found == false)
			cout << "Client not found.";
	}
	else{
		cerr << "Client Complete Name: ";
		cin.clear();
		cin.ignore(256, '\n');
		getline(cin, name);
		cout << endl;

		while (cin.fail()) {
			cerr << "Invalid input!\n";
			cin.clear();
			cin.ignore(256, '\n');
			getline(cin, name);
			cout << endl;
		}
		found = false;
		for (i = 0; i < clients.size(); i++){
			if (clients.at(i).isEqual(name)){
				cout << "ID: " << clients.at(i).getId() << "\t\tName: " << clients.at(i).getName() << "\t\tAmount Spent: " << clients.at(i).getAmountSpent();
				position = i;
				found = true;
			}
		}
		if (found == false)
			cout << "Client not found.";


	}
	return;
}

void Supermarket::searchTransaction(){	//TODO ainda nao funciona opcao 3
	int i, j;
	int op;
	int id;
	bool found;
	string date_1, date_2;
	Date date1;
	Date date2;

	cout << "Search transaction by: " << endl << "1 - Client" << endl << "2 - Day" << endl << "3 - Between two dates: " << endl << endl;
	cin >> op;
	cout << endl;


	while (cin.fail() || (op != 1 && op != 2 && op != 3)) {
		cerr << "Invalid input! Please enter a number from the menu.\n";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> op;
		cout << endl;
	}


	if (op == 1){
		cout << "Client ID: ";
		cin >> id;
		cout << endl;

		while (cin.fail()) {
			cerr << "Invalid input!\n";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> id;
			cout << endl;
		}
		found = false;
		for (i = 0; i < transactions.size(); i++){
			if (transactions.at(i).isEqual(id)){
				cout << "Transaction ID: " << transactions.at(i).getId()
					<< "\tClient ID: " << transactions.at(i).getClientId()
					<< "\tDate: " << transactions.at(i).getDate().getDate()
					<< "\tProducts: " << transactions.at(i).getProducts().at(0)->getName();
				for (j = 1; j < transactions.at(i).getProducts().size(); j++)
					cout << ", " << transactions.at(i).getProducts().at(j)->getName() << endl << endl;
				found = true;
			}
		}
		if (found == false)
			cout << "Transaction not found." << endl;
	}
	else if (op == 2){
		cout << "Search transactions in date (dd/mm/yyyy): ";
		cin >> date_1;
		cout << endl;

		while (cin.fail()) {
			cerr << "Invalid input!\n";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> date_1;
			cout << endl;
		}
		found = false;
		for (i = 0; i < transactions.size(); i++){
			if (transactions.at(i).getDate().isEqual(date_1)){
				cout << "Transaction ID: " << transactions.at(i).getId()
					<< "\tClient ID: " << transactions.at(i).getClientId()
					<< "\tDate: " << transactions.at(i).getDate().getDate()
					<< "\tProducts: " << transactions.at(i).getProducts().at(0)->getName();
				for (j = 1; j < transactions.at(i).getProducts().size(); j++)
					cout << ", " << transactions.at(i).getProducts().at(j)->getName() << endl << endl;
				found = true;
			}
		}
		if (found == false)
			cout << "Transaction not found." << endl;
	}
	else{
		cout << "Search transactions between date 1 and date 2 (dd/mm/yyyy dd/mm/yyyy): ";
		cin >> date_1;
		cout << endl;

		while (cin.fail()) {
			cerr << "Invalid input!\n";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> date_1;
			cout << endl;
		}

		date1 = Date(date_1);

		cin >> date_2;
		cout << endl;

		while (cin.fail()) {
			cerr << "Invalid input!\n";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> date_2;
			cout << endl;
		}

		date2 = Date(date_2);

		found = false;
		for (i = 0; i < transactions.size(); i++){
			if (transactions.at(i).getDate().isBetween(date1, date2)){
				cout << "Transaction ID: " << transactions.at(i).getId() << "\tClient ID: " << transactions.at(i).getClientId()
					<< "\tDate: " << transactions.at(i).getDate().getDate() << "\tProducts: " << transactions.at(i).getProducts().at(0)->getName();
				for (j = 1; j < transactions.at(i).getProducts().size(); j++)
					cout << ", " << transactions.at(i).getProducts().at(j)->getName() << endl << endl;
				found = true;
			}

			if (found == false)
				cout << "Transaction not found." << endl;
		}

	}
}


void Supermarket::addClient(){
	string name;
	ofstream outfile;

	lastClientAddedId = lastClientAddedId + 1;

	cin.ignore(1);

	cout << "Client Complete Name: ";
	getline(cin, name);

	while (cin.fail()) {
		cerr << "Invalid Name!\n";
		cin.clear();
		cin.ignore(256, '\n');
		getline(cin, name);
		cout << endl;
	}

	cin.clear();

	clients.push_back(Client(lastClientAddedId, name, 0));
	cout << "Client added with success.\n\n";

	outfile.open("Clients.csv");

	outfile << clients.back().getId() << ";" << clients.back().getName() << ";" << clients.back().getAmountSpent() << endl;

	outfile.close();

}

void Supermarket::editClient(){
	/*	string name;
		int i;


		cin.ignore(1);

		cout << "Please search client you want to edit.\n\n";

		searchClient();

		cout << "\n\nNew client name: ";

		getline(cin, name);

		while (cin.fail()) {
		cerr << "Invalid Name!\n";
		cin.clear();
		cin.ignore(256, '\n');
		getline(cin, name);
		cout << endl;
		}

		cin.clear();
		cin.ignore();

		clients.at(position).setName(name);

		cout << "\n\nClient name changed with success.";
		*/
}

void Supermarket::deleteClient(){

	cout << "Please search client you want to delete.\n\n";

	searchClient();

	clients.erase(clients.begin() + position);

	cout << "\n\nClient deleted with success.";
}

void Supermarket::createTransaction(){
	/*int i;
	int clientID;
	int id;
	int nProducts;
	Date date;
	string str_products;
	string productName;
	vector<Product> productsTransaction;

	cout << "Client ID: ";
	cin >> clientID;

	while (cin.fail()) {
	cerr << "\n\nInvalid ID!\n";
	cin.clear();
	cin.ignore(256, '\n');
	cin >> clientID;
	cout << endl;
	}

	cin.clear();
	cin.ignore();

	cout << "Insert number of productsof the transaction (separated by comma): ";
	cin >> str_products;

	while (cin.fail()) {
	cerr << "\n\nInvalid ID!\n";
	cin.clear();
	cin.ignore(256, '\n');
	cin >> str_products;
	cout << endl;
	}

	cin.clear();
	cin.ignore();


	for (i = 0; i < nProducts; i++){
	if (str_products.at(i) != ','){
	productName = productName + str_products.at(i);
	}
	else{
	products.push_back(getProduct(productName));
	productName = "";
	}
	}
	str_products.clear();
	productName.clear();

	date = currentDateTime();		// Get current date/time, format is YYYY-MM-DD.HH:mm:ss!!!!!!!!!!

	id = transactions.back().getId() + 1;

	transactions.push_back(Transaction(id, clientID, date, productsTransaction));

	}

	const string Supermarket::currentDateTime() {
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);

	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;*/
}

void Supermarket::save(){
	/*	ofstream outfile;
		int i, j;

		outfile.open("Clients.csv");

		for (i = 0; i < clients.size(); i++){
		outfile << clients.at(i).getId() << ";" << clients.at(i).getName() << ";" << clients.at(i).getAmountSpent() << endl;
		}
		outfile.close();

		outfile.open("Products.csv");

		for (i = 0; i < products.size(); i++){
		outfile << products.at(i)->getName() << ";" << products.at(i)->getPrice() << endl;
		}

		outfile.close();

		outfile.open("Transactions.csv");

		for (i = 0; i < transactions.size(); i++){
		outfile << transactions.at(i).getId() << ";" << transactions.at(i).getClientId() << ";" << transactions.at(i).getDate().getDate() << ";"
		<< transactions.at(i).getProducts().at(0)->getName();

		for (j = 1; j < transactions.at(i).getProducts().size(); j++){
		outfile << ", " << transactions.at(i).getProducts().at(j)->getName();
		}
		outfile << endl;
		}
		outfile.close();*/
}