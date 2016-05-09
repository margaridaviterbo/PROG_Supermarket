#include"RecomendationSystem.h"

using namespace std;

RecomendationSystem::RecomendationSystem(){
	int id;
	int i,j;
	cout << "Choose target customer (by ID): ";
	cin >> id;


	while (cin.fail()) {
		cerr << "\n\nInvalid input!\n";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> id;
		cout << endl;
	}

	for (i = 0; i < supermarket.getClients().size(); i++){
		if (supermarket.getClients().at(i).isEqual(id)){
			targetCustomer = supermarket.getClients().at(i);
		}

	}



}