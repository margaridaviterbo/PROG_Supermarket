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
	Date();
	Date(string date);
	Date(int day, int month, int year);
	string getDate();
	int getDay();
	int getMonth();
	int getYear();
	void setDate();
	void setDayMonthYear();
	bool operator==(string date);
	bool operator<=(Date date);
};

#endif
