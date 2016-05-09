#ifndef RECOMENDATION_SYSTEM_H
#define RECOMENDATION_SYSTEM_H
#include<iostream>
#include<string>
#include<vector>
#include"Supermarket.h"
#include"Client.h"
#include"Menu.cpp"

using namespace std;

class RecomendationSystem{
private:
	Client targetCustomer;
	vector<vector<bool>> matrix;
public:
	RecomendationSystem();
};

#endif