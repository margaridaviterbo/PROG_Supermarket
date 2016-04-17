#include"Supermarket.h"

using namespace std;

Supermarket::Supermarket(){		//TODO preciso de definir um construtor sem parametros? como decidir se os parametros sao passados por referencia ou nao?

}

void Supermarket:: readClients(){
	string id;
	string name;
	string amountSpent;

	ifstream infile;
	infile.open("Client.csv");
	if (infile.fail()){
		cerr << "Error opening " << "Client.csv";
		exit(1);
	}
	else{
		while (!infile.eof){
			getline(infile, id, ';');	//TODO o ; é guardado em id ou deitado fora?
			getline(infile, name, ';');
			getline(infile, amountSpent);
			Client client = Client(atoi(id.c_str()), name, atoi(amountSpent.c_str()));	//TODO usar cats? porque nao posso usar atoi?
			clients.push_back(client);
		}
	}
	infile.close();
}

void readProducts(){

}

void readTransactions(){

}