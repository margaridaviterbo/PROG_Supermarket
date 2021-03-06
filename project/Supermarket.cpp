#include"Supermarket.h"
#include"RecomendationSystem.h"

using namespace std;


Supermarket::Supermarket(){
	cout << "Name of the clients' file (xxxxxxx.txt): ";
	getline(cin, clientFile);
	invalidInput(clientFile);
	readClients();

	cout << "\n\nName of the products' file (xxxxxxx.txt): ";
	getline(cin, productFile);
	invalidInput(productFile);
	readProducts();

	cout << "\n\nName of the transactions' file (xxxxxxx.txt): ";
	getline(cin, transactionFile);
	invalidInput(transactionFile);
	readTransactions();

	//Falta inicializar o resto dos atributos!
	cout << endl << endl;
}

int Supermarket::getPositionProduct(){
	return positionProduct;
}

vector<Client>& Supermarket::getClients(){
	return clients;
}

vector<Product*>& Supermarket::getProducts(){
	return products;
}

vector<Transaction>& Supermarket::getTransactions(){
	return transactions;
}

void Supermarket::readClients(){
	int i, id;
	string name;
	string date;
	float amountSpent;
	string trash;
	ifstream infile = openFile(clientFile);
	Client tempClient;

	infile >> nClients;
	while (!infile.eof()){
		infile >> id;
		getline(infile, trash, ';');
		getline(infile, name, ';');
		getline(infile, date, ';');
		infile >> amountSpent;
		clients.push_back(Client(id, name, Date(date), amountSpent));
		i = clients.size() - 1;
		while (i > 0 && clients.at(i) < clients.at(i - 1)) {
			tempClient = clients.at(i);
			clients.at(i) = clients.at(i - 1);
			clients.at(i - 1) = tempClient;
			i--;
		}
	}

	//lastClientAddedId = clients.back().getId();
}

void Supermarket::readProducts(){
	string name;
	float price;
	string trash;
	ifstream infile = openFile(productFile);

	infile >> nProducts;
	getline(infile, trash, '\n');

	while (!infile.eof()){
		getline(infile, name, ';');
		infile >> price;
		getline(infile, trash, '\n');
		products.push_back(new Product(name, price));
	}

	infile.close();
}

void Supermarket::readTransactions(){
	int i;
	int id;
	int clientId;
	string d;
	Date date;
	string strProducts;
	string productName = "";
	string trash;
	ifstream infile = openFile(transactionFile);

	infile >> nTransactions;

	while (!infile.eof()){
		infile >> id;
		getline(infile, trash, ';');
		infile >> clientId;
		getline(infile, trash, ';');
		getline(infile, d, ';');
		date = Date(d);
		transactions.push_back(Transaction(id, clientId, date));
		getline(infile, strProducts);
		strProducts += ",";
		i = 0;
		while (i < strProducts.size()){
			if (strProducts.at(i) != ','){
				productName = productName + strProducts.at(i);
			}
			else {
				transactions.back().addProduct(getProduct(productName));
				productName = "";
			}
			i++;
		}
		strProducts = "";
		productName = "";
		for (int i = 0; i < clients.size(); i++){
			if (clients.at(i).isEqual(clientId))
				clients.at(i).addTransaction(transactions.back());
		}
	}
	infile.close();
}

ifstream Supermarket::openFile(string fileName){
	ifstream infile;
	int i = 0;
	infile.open(fileName);
	while ((i < 3) && (infile.fail())) {
		cerr << "Error opening file " << fileName <<
			". This file might not exist. Please enter a new name for the file (you have a maximum of 3 tries): ";
		getline(cin, fileName, '\n');
		invalidInput(fileName);
		infile.open(fileName);
		i++;
	}

	if (i == 3)
		exit(1);
	return infile;
}

Product* Supermarket::getProduct(string productName){
	int i = 0;
	while (i < products.size()){
		if (products.at(i)->isEqual(productName)){
			positionProduct = i;
			return products.at(i);
		}
		i++;
	}
	return NULL;
}

void Supermarket::printClients(){
	int i;

	cout << setw(50) << "CLIENTS\n";
	cout << "______________________________________________________________________________________________________________________________________\n\n";

	cout << setw(10) << "ID" <<
		setw(10) << "|" <<
		setw(30) << "Name" <<
		setw(20) << "|" <<
		setw(25) << "Subscription Date" <<
		setw(15) << "|" <<
		setw(15) << "Amount Spent" <<
		setw(15) << '\n';

	cout << "______________________________________________________________________________________________________________________________________\n";


	for (i = 0; i < clients.size(); i++){

		cout << setw(10) << clients.at(i).getId() <<
			setw(10) << "|" <<
			setw(40) << clients.at(i).getName() <<
			setw(10) << "|" <<
			setw(20) << clients.at(i).getSubscriptionDate().getDate() <<
			setw(20) << "|" <<
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

bool Supermarket::searchClient(){
	int i;
	int op;
	int id;
	string name;

	cout << "Search client by: " << endl << "1 - ID" << endl << "2 - Complete Name" << endl << endl;
	cin >> op;
	cout << endl;

	while (cin.fail() || (op != 1 && op != 2)) {
		cerr << "Invalid input! Please enter a number from the menu.\n";
		cin >> op;
		cin.clear();
		cin.ignore(256, '\n');
		cout << endl;
	}


	if (op == 1){
		cout << "Client ID: ";
		cin >> id;
		cin.clear();
		cin.ignore(256, '\n');
		cout << endl;

		invalidInput(id, "Invalid id!\n");

		clientFound = false;
		for (i = 0; i < clients.size(); i++){
			if (clients.at(i).isEqual(id)){
				printSelectedClient(i);
			}
		}
	}
	else{
		cout << "Client Complete Name: ";
		cin.clear();
		cin.ignore(256, '\n');
		getline(cin, name);
		cout << endl;

		invalidInput(name);

		clientFound = false;
		for (i = 0; i < clients.size(); i++){
			if (clients.at(i).isEqual(name)){
				printSelectedClient(i);
			}
		}
	}
	if (clientFound == false){
 		cout << "Client not found.";
		return false;
	}
	else
		return true;
}

void Supermarket::printSelectedClient(int i){
	cout << "ID: " << clients.at(i).getId() << "\t\tName: " <<
		clients.at(i).getName() << "\tSubscription Date: " <<
		clients.at(i).getSubscriptionDate().getDate() << "\t\tAmount Spent: " <<
		clients.at(i).getAmountSpent();
	position = i;
	clientFound = true;
}

void Supermarket::searchTransaction(){
	int i;
	int op;
	int id;
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

	transactionFound = false;

	if (op == 1){
		if (searchClient()){
			if (clients.at(position).getTransactions().size() != 0){
				cout << endl << endl << "Transactions:" << endl << endl;
				clients.at(position).printTransactions();
				transactionFound = true;
			}
			cout << endl;
		}
	}
	else if (op == 2){
		cout << "Search transactions in date (dd/mm/yyyy): ";
		cin >> date_1;
		cout << endl;

		invalidInput(date_1, "Invalid date\n");

		for (i = 0; i < transactions.size(); i++){
			if (transactions.at(i).getDate() == (date_1)){
				printSelectedTransaction(i);
			}
		}
		cout << endl;
	}
	else{
		cout << "Search transactions between date 1 and date 2 (dd/mm/yyyy dd/mm/yyyy): ";
		cin >> date_1;
		cout << endl;

		invalidInput(date_1, "Invalid date\n");

		date1 = Date(date_1);

		cin >> date_2;
		cout << endl;

		invalidInput(date_2, "Invalid date\n");

		date2 = Date(date_2);

		while (!(date1 <= date2)){
			cerr << "First date is more recent than the second one, please fix the error (dd/mm/yyyy dd/mm/yyyy):";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> date_1;
			cout << endl;

			invalidInput(date_1, "Invalid date\n");

			date1 = Date(date_1);

			cin >> date_2;
			cout << endl;

			invalidInput(date_2, "Invalid date\n");

			date2 = Date(date_2);
		}

		for (i = 0; i < transactions.size(); i++){
			if (transactions.at(i).getDate() >= (date1) && transactions.at(i).getDate() <= (date2)){
				printSelectedTransaction(i);
			}
		}
		cout << endl;
	}
	if (transactionFound == false)
		cout << "Transaction not found." << endl;
}

void Supermarket::printSelectedTransaction(int i){
	int j;
	cout << "Transaction ID: " << transactions.at(i).getId()
		<< "\tClient ID: " << transactions.at(i).getClientId()
		<< "\tDate: " << transactions.at(i).getDate().getDate()
		<< "\tProducts: " << transactions.at(i).getProducts().at(0)->getName();
	for (j = 1; j < transactions.at(i).getProducts().size(); j++)
		cout << ", " << transactions.at(i).getProducts().at(j)->getName();
	cout << endl;
	transactionFound = true;
}

int Supermarket::getMaxId(){
	vector<int> ids;
	for (int i = 0; i < clients.size(); i++){
		ids.push_back(clients.at(i).getId());
	}

	sort(ids.begin(), ids.end());

	return ids.at(ids.size() - 1);
}

void Supermarket::addClient(){
	string name;
	string date;
	ofstream outfile;
	Client tempClient;

	//lastClientAddedId += 1;

	nClients += 1;

	cin.ignore(1);

	cout << "Client Complete Name: ";
	getline(cin, name);

	invalidInput(name);

	cin.clear();

	cout << "Subscription Date (dd/mm/yyyy): ";
	getline(cin, date);

	invalidInput(date, "Invalid date!");

	cin.clear();

	clients.push_back(Client(getMaxId() + 1, name, Date(date), 0));
	int i = clients.size() - 1;
	while (i > 0 && clients.at(i) < clients.at(i - 1)) {
		tempClient = clients.at(i);
		clients.at(i) = clients.at(i - 1);
		clients.at(i - 1) = tempClient;
		i--;
	}
	cout << "\nClient added with success.\n\n";

}

void Supermarket::editClient(){
	string name;
	int i;

	cout << "Please search client you want to edit.\n\n";

	searchClient();

	if (clientFound == true){

		cout << "\n\nNew client name: ";

		getline(cin, name);

		invalidInput(name);

		clients.at(position).setName(name);

		cout << "\n\nClient name changed with success.";
	}

}

void Supermarket::deleteClient(){

	cout << "Please search client you want to delete.\n\n";

	searchClient();

	if (clientFound == true){

		clients.erase(clients.begin() + position);

		cout << "\n\nClient deleted with success.";
	}

	nClients -= 1;
}

void Supermarket::createTransaction(){
	int i, op;
	int id;
	Date date;
	string date_str;
	string str_products;
	string productName;
	vector<Product*> productsTransaction;

	cout << "1 - Shop with an existig client\n";
	cout << "2 - Shop with a new client\n\n";
	cout << "Choose an option: ";
	cin >> op;
	cout << endl;

	while (cin.fail() || (op != 1 && op != 2)) {
		cerr << "Invalid input! Please enter a number from the menu.\n";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> op;
		cout << endl;
	}

	if (op == 1){
		searchClient();
		cout << endl << endl;
		while (clientFound == false)
			searchClient();
	}

	if (op == 2){
		addClient();
	}

	printProducts();

	cout << "Insert products to buy (separated by comma without spaces and end with period): ";
	getline(cin, str_products);

	invalidInput(str_products, "Invalid input!\n");

	for (i = 0; i < str_products.size(); i++){
		if (str_products.at(i) != ',' && str_products.at(i) != '.'){
			productName = productName + str_products.at(i);
		}
		else{
			if (getProduct(productName) == NULL)
				cout << endl << "Product " << productName << " doens't exist therefore it wasn't added to your shopping list." << endl << endl;
			else{
				productsTransaction.push_back(getProduct(productName));
			}
			productName = "";
		}
	}
	str_products.clear();
	productName.clear();

	cout << "Date of the purchase (dd/mm/yyyy): ";
	cin >> date_str;
	cout << endl;

	invalidInput(date_str, "Invalid date\n");

	date = Date(date_str);

	id = transactions.back().getId() + 1;

	if (op == 1){
		transactions.push_back(Transaction(id, clients.at(position).getId(), date, productsTransaction));
		clients.at(position).updateAmountSpent(productsTransaction);
		clients.at(position).addTransaction(transactions.back());
	}
	else{
		transactions.push_back(Transaction(id, clients.back().getId(), date, productsTransaction));
		clients.back().updateAmountSpent(productsTransaction);
		clients.back().addTransaction(transactions.back());
	}
	nTransactions += 1;
	cout << endl << "Successful purchase." << endl;
}

vector<Client*> Supermarket::bottomTen(){
	int i, j;
	Client* tempClient;
	vector<Client*> clientsByOrder;

	for (i = 0; i < clients.size(); i++){
		clientsByOrder.push_back(&clients.at(i));
		j = clientsByOrder.size() - 1;
		while (j > 0 && (clientsByOrder.at(j)->getAmountSpent() < clientsByOrder.at(j - 1)->getAmountSpent())){
			tempClient = clientsByOrder.at(j);
			clientsByOrder.at(j) = clientsByOrder.at(j - 1);
			clientsByOrder.at(j - 1) = tempClient;
			j--;
		}
	}
	int pos = clientsByOrder.size();
	while (pos > 10){
		clientsByOrder.erase(clientsByOrder.begin() + (pos - 1));
		pos--;
	}

	return clientsByOrder;
}

void Supermarket::printBottomTen(){
	vector<Client*> clientsByOrder = bottomTen();

	cout << endl << endl;
	for (int i = 0; i < clientsByOrder.size(); i++){
		cout << i + 1 << "o:\t" << "ID: " << setw(10) << clientsByOrder.at(i)->getId() << setw(10) << "Name: " << setw(10) <<
			clientsByOrder.at(i)->getName() << setw(40) << "\tSubscription Date: " << setw(10) <<
			clientsByOrder.at(i)->getSubscriptionDate().getDate() << setw(20) << "Amount Spent: " <<
			clientsByOrder.at(i)->getAmountSpent() << endl;
	}
}

void Supermarket::runRecomendationSystem(){
	int op;

	cout << "This system will suggest a product that we think the client(s) you choose would interested in.\n";
	cout << "Please choose an option.\n\n";
	cout << "1 - Select a client\n";
	cout << "2 - Use recomendation system with bottom 10 clients\n\n";
	cin >> op;
	cout << endl;

	while (cin.fail() || (op != 1 && op != 2)) {
		cerr << "Invalid input! Please enter a number from the menu.\n";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> op;
		cout << endl;
	}

	if (op == 1){
		if (searchClient()==false)
			cout << "We couldn't find a suitable product because the client doesn't exist.\n\n";
		else{
			cout << endl << endl;
			callPersonalizedAdvertising(&clients.at(position));
		}
	}
	else
		for (int i = 0; i < bottomTen().size(); i++)
			callPersonalizedAdvertising(bottomTen().at(i));
}

void Supermarket::callPersonalizedAdvertising(Client* client){

	RecomendationSystem clientSelected = RecomendationSystem(this, client);
	Product* suggestedProduct = clientSelected.personalizedAdvertising();

	if (suggestedProduct == NULL)
		cout << "We couldn't find a suitable product for you.\n\n";
	else{
		cout << "We suggest you this product: \n";
		cout << setw(30) << suggestedProduct->getName() <<
			setw(15) << "|" <<
			setw(20) << suggestedProduct->getPrice() << endl;
	}
}

void Supermarket::save(){
	ofstream outfile;
	int i, j;

	outfile.open(clientFile);

	outfile << nClients << endl;

	for (i = 0; i < clients.size() - 1; i++){
		outfile << clients.at(i).getId() << ";" << clients.at(i).getName() << ";" << clients.at(i).getSubscriptionDate().getDate() << ";" << clients.at(i).getAmountSpent() << endl;
	}
	outfile << clients.at(i).getId() << ";" << clients.at(i).getName() << ";" << clients.at(i).getSubscriptionDate().getDate() << ";" << clients.at(i).getAmountSpent();
	outfile.close();

	outfile.open(productFile);

	outfile << nProducts << endl;

	for (i = 0; i < products.size() - 1; i++){
		outfile << products.at(i)->getName() << ";" << products.at(i)->getPrice() << endl;
	}
	outfile << products.at(i)->getName() << ";" << products.at(i)->getPrice();
	outfile.close();

	outfile.open(transactionFile);

	outfile << nTransactions << endl;

	for (i = 0; i < transactions.size() - 1; i++){
		outfile << transactions.at(i).getId() << ";" << transactions.at(i).getClientId() << ";" << transactions.at(i).getDate().getDate() << ";"
			<< transactions.at(i).getProducts().at(0)->getName();

		for (j = 1; j < transactions.at(i).getProducts().size(); j++){
			outfile << "," << transactions.at(i).getProducts().at(j)->getName();
		}
		outfile << endl;
	}
	outfile << transactions.at(i).getId() << ";" << transactions.at(i).getClientId() << ";" << transactions.at(i).getDate().getDate() << ";"
		<< transactions.at(i).getProducts().at(0)->getName();

	for (j = 1; j < transactions.at(i).getProducts().size(); j++){
		outfile << "," << transactions.at(i).getProducts().at(j)->getName();
	}

	outfile.close();

	cout << "Data saved with success." << endl;
}

void Supermarket::invalidInput(int& input, string msg){

	while (cin.fail()) {
		cerr << msg;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> input;
		cout << endl;
	}

}

void Supermarket::invalidInput(string& input, string msg){

	while (cin.fail()) {
		cerr << msg;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> input;
		cout << endl;
	}
}

void Supermarket::invalidInput(string& input){

	while (cin.fail()) {
		cerr << "Invalid name! Please enter a different one: \n";
		cin.clear();
		cin.ignore(256, '\n');
		getline(cin, input, '\n');
		cout << endl;
	}
}