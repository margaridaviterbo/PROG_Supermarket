#include"RecomendationSystem.h"

using namespace std;

RecomendationSystem::RecomendationSystem(Supermarket &supermarket, Client targetClient){
	targetClientID = targetClient.getId();

    this->supermarket = supermarket;
    this->targetClient = targetClient;

    for (int i = 0; i < supermarket.getClients().size(); i++){
		for (int j = 0; j < supermarket.getProducts().size(); j++){
			matrix.at(i).at(j) = false;
			if (i == targetClientID)
				targetClientProducts.at(j) = false;
		}
    }
}

void RecomendationSystem::personalizedAdvertising(){
	int clientID;
	for (int i = 0; i < supermarket.getTransactions().size(); i++){
		clientID = supermarket.getTransactions().at(i).getClientId();
		for (int j = 0; j < supermarket.getTransactions().at(i).getProducts().size(); j++){
			if (supermarket.getProduct(supermarket.getTransactions().at(i).getProducts().at(j)->getName()) != NULL){
				matrix.at(clientID).at(supermarket.getPosition()) = true;
				if (clientID == targetClientID)
					targetClientProducts.at(supermarket.getPosition()) = true;
			}
		}
	}



}