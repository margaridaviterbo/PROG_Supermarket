#include"RecomendationSystem.h"

using namespace std;

RecomendationSystem::RecomendationSystem(Supermarket &supermarket, Client targetClient){
	targetClientID = targetClient.getId();

    this->supermarket = supermarket;
    this->targetClient = targetClient;

    for (int i = 0; i < supermarket.getClients().size(); i++){
		for (int j = 0; j < supermarket.getProducts().size(); j++){
			matches.insert(0, j);
			mismatches.push_back(0);
			matrix.at(i).at(j) = false;
			if (i == targetClientID)
				targetClientProducts.at(j) = false;
		}
    }
}

void RecomendationSystem::personalizedAdvertising(){
	int i,j;
	int clientID;
	for (i = 0; i < supermarket.getTransactions().size(); i++){
		clientID = supermarket.getTransactions().at(i).getClientId();
		for (j = 0; j < supermarket.getTransactions().at(i).getProducts().size(); j++){
			if (supermarket.getProduct(supermarket.getTransactions().at(i).getProducts().at(j)->getName()) != NULL){
				matrix.at(clientID).at(supermarket.getPosition()) = true;
				if (clientID == targetClientID)
					targetClientProducts.at(supermarket.getPosition()) = true;
			}
		}
	}

	

	for (i = 0; i < matrix.size(); i++){
		for (j = 0; j < matrix.at(i).size(); j++){
			if (targetClientProducts.at(j) == true && matrix.at(i).at(j) == true)
				matches.at(j)++;
			else if (targetClientProducts.at(j) == false && matrix.at(i).at(j) == true)
				mismatches.at(j)++;
		}
	}

	sort(matches.begin(), matches.end()); 
	reverse(matches.begin(), matches.end());	//nao possofico em id
	
	

}