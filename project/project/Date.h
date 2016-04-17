#ifndef DATE_H
#define DATE_H
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class Date{

private:
	string date;
	int day;
	int month;
	int year;
public:
	Date(string date);
	Date(int day, int month, int year);
	string getDate();
	int getDay();
	int getMonth();
	int getYear();
	void setDate();
	void setDay();
	void setMonth();
	void setYear();
};

#endif
