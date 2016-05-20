#include"RecomendationSystem.h"

using namespace std;

RecomendationSystem::RecomendationSystem(Supermarket &supermarket, Client targetClient){
    this->supermarket = supermarket;
    this->targetClient = targetClient;

    for (int i = 0; i < supermarket.getClients().size(); i++){
        for (int j = 0; j < supermarket.getProducts().size(); j++)
            matrix.at(i).at(j) = false;
    }
}

void RecomendationSystem::personalizedAdvertising(){

}