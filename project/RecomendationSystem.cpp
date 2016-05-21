#include"RecomendationSystem.h"

using namespace std;

RecomendationSystem::RecomendationSystem(Supermarket* supermarket, Client* targetClient){
	targetClientID = targetClient->getId();

	this->supermarket = supermarket;
	this->targetClient = targetClient;

	for (int i = 0; i < supermarket->getClients().size(); i++){
		for (int j = 0; j < supermarket->getProducts().size(); j++){
			matches.push_back(make_pair(0, j));
			mismatches.push_back(0);
			matrix.at(i).at(j) = false;
			if (i == targetClientID)
				targetClientProducts.at(j) = false;
		}
	}
}

Product* RecomendationSystem::personalizedAdvertising(){
	int i, j;
	int clientID;
	for (i = 0; i < supermarket->getTransactions().size(); i++){
		clientID = supermarket->getTransactions().at(i).getClientId();
		for (j = 0; j < supermarket->getTransactions().at(i).getProducts().size(); j++){
			if (supermarket->getProduct(supermarket->getTransactions().at(i).getProducts().at(j)->getName()) != NULL){
				matrix.at(clientID).at(supermarket->getPosition()) = true;
				if (clientID == targetClientID)
					targetClientProducts.at(supermarket->getPosition()) = true;
			}
		}
	}



	for (i = 0; i < matrix.size(); i++){
		for (j = 0; j < matrix.at(i).size(); j++){
			if (targetClientProducts.at(j) == true && matrix.at(i).at(j) == true)
				matches.at(j).first++;
			else if (targetClientProducts.at(j) == false && matrix.at(i).at(j) == true)
				mismatches.at(j)++;
		}
	}

	bool found = false;
	for (i = 0; i < matches.size(); i++){
		if (matches.at(i).first != 0)
			found = true;
	}
	if (found = false)
		return NULL;

	sort(matches.begin(), matches.end());
	reverse(matches.begin(), matches.end());
	idSelectedClients.push_back(matches.at(0).second);

	i = 0;
	while (mismatches.at(matches.at(i).second) == 0){
		idSelectedClients.back() = matches.at(i).second;
		i++;
	}
	while (matches.at(i + 1).first == matches.at(i).first && i<matches.size()){
		idSelectedClients.push_back(matches.at(i + 1).second);
		i++;
	}

	found = false;
	int k;
	for (i = 0; i < idSelectedClients.size(); i++){
		for (j = 0; j < matrix.at(i).size(); j++){
			if (matrix.at(idSelectedClients.at(i)).at(j) == true && targetClientProducts.at(j) == false){
				for (k = 0; k < selectedProducts.size(); k++){
					if (selectedProducts.at(k).second->getName() == supermarket->getProducts().at(j)->getName())
						found = true;
				}
				if (found == true)
					selectedProducts.at(k).first++;
				else{
					selectedProducts.push_back(make_pair(1, supermarket->getProducts().at(j)));
				}
			}
		}
	}

	sort(selectedProducts.begin(), selectedProducts.end());
	reverse(selectedProducts.begin(), selectedProducts.end());
	if (selectedProducts.size() == 0)
		return NULL;

	return selectedProducts.at(0).second;

}