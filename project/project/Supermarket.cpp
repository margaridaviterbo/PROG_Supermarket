#include"Supermarket.h"

using namespace std;

Supermarket(){

}

void readClients(){

	ifstream infile;
	infile.open("Client.csv");
	if (infile.fail()){
		cerr << "Error opening " << "Client.csv";
		exit(1);
	}
	else{
		while (!infile.eof){
			clients
				getline(infile, temp, ';');
			getline(infile, price);
		}
	}
	infile.close();
}

void readProducts(){

}

void readTransactions(){

}