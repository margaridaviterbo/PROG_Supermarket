#include"RecomendationSystem.h"

using namespace std;

RecomendationSystem::RecomendationSystem(Supermarket* supermarket, Client* targetClient){
	targetClientID = targetClient->getId();

	this->supermarket = supermarket;
	this->targetClient = targetClient;

	matrix.push_back(vector<bool>());
	matches.push_back(make_pair(0, 0));
	mismatches.push_back(0);
	for (int i = 1; i <= supermarket->getMaxId(); i++){
		matrix.push_back(vector<bool>());
		matches.push_back(make_pair(0, i));
		mismatches.push_back(0);
		for (int j = 0; j < supermarket->getProducts().size(); j++){
			matrix.at(i).push_back(false);
			if (i == targetClientID)
				targetClientProducts.push_back(false);
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
				matrix.at(clientID).at(supermarket->getPositionProduct()) = true;
				if (clientID == targetClientID)
					targetClientProducts.at(supermarket->getPositionProduct()) = true;
			}
		}
	}


	for (i = 1; i < matrix.size(); i++){
		for (j = 0; j < matrix.at(i).size(); j++){
			if (targetClientProducts.at(j) == true && matrix.at(i).at(j) == true)
				matches.at(i).first++;
			else if (targetClientProducts.at(j) == false && matrix.at(i).at(j) == true)
				mismatches.at(i)++;
		}
	}

	bool found = false;
	for (i = 1; i < matches.size(); i++){
		if (matches.at(i).first != 0)
			found = true;
	}
	if (!found)
		return NULL;

	sort(matches.begin(), matches.end());
	reverse(matches.begin(), matches.end());
	idSelectedClients.push_back(0);
	idSelectedClients.push_back(matches.at(1).second);

	i = 1;
	while (mismatches.at(matches.at(i).second) == 0 && i<matches.size()){
		idSelectedClients.back() = matches.at(i).second;
		i++;
	}

	i = 1;
	while ((i<matches.size() - 1) && (matches.at(i + 1).first == matches.at(i).first)){
		idSelectedClients.push_back(matches.at(i + 1).second);
		i++;
	}

	found = false;
	int k;
	selectedProducts.push_back(make_pair(0, nullptr));
	for (i = 1; i < idSelectedClients.size(); i++){
		for (j = 0; j < matrix.at(i).size(); j++){
			if (matrix.at(idSelectedClients.at(i)).at(j) == true && targetClientProducts.at(j) == false){
				for (k = 1; k < selectedProducts.size(); k++){
					if (selectedProducts.at(k).second->getName() == supermarket->getProducts().at(j)->getName()){
						found = true;
						if (found)
							selectedProducts.at(k).first++;
						else
							selectedProducts.push_back(make_pair(1, supermarket->getProducts().at(j)));
					}
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