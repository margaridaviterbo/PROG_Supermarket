#ifndef PROG_SUPERMARKET_RECOMENDATIONSYSTEM_H
#define PROG_SUPERMARKET_RECOMENDATIONSYSTEM_H

#include <vector>
#include"Client.h"
#include"Supermarket.h"

using namespace std;

class RecomendationSystem{
private:
    Supermarket supermarket;
	int targetClientID;
    Client targetClient;
    vector<vector<bool>> matrix;
	vector<bool>targetClientProducts;	//vetor com os true e false nos produtos que este cliente comprou TODO usar este vetor para comparar com todas as linhas da matrix e ir incrementando as matches nos diferentes clientes para ver quem tem mais
	vector<bool> matches;		//numero de produtos iguais aos do target que cada cliente tem {5,2,10,...}
public:
    RecomendationSystem(Supermarket &supermarket, Client targetClient);
    void personalizedAdvertising();
};

#endif //PROG_SUPERMARKET_RECOMENDATIONSYSTEM_H
