#ifndef PROG_SUPERMARKET_RECOMENDATIONSYSTEM_H
#define PROG_SUPERMARKET_RECOMENDATIONSYSTEM_H

#include <vector>
#include"Client.h"
#include"Supermarket.h"

using namespace std;

class RecomendationSystem{
private:
    Supermarket supermarket;
    Client targetClient;
    vector<vector<bool>> matrix;
public:
    RecomendationSystem(Supermarket &supermarket, Client targetClient);
    void personalizedAdvertising();
};

#endif //PROG_SUPERMARKET_RECOMENDATIONSYSTEM_H
