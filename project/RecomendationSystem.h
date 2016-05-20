#ifndef RECOMENDATIONSYSTEM_H
#define RECOMENDATIONSYSTEM_H
#include <vector>
#include "Client.h"


using namespace std;

class RecomendationSystem{
private:
	Supermarket supermarket;
	Client targetClient;
	vector<vector<bool>> matrix;
public:
	RecomendationSystem(Supermarket &supermarket, Client targtClient);
	void personalizedAdvertising();
};


#endif