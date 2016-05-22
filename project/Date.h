/*
this class similates dates
*/


#ifndef DATE_H
#define DATE_H
#include<iostream>
#include<string>
#include<istream>
#include<sstream>

using namespace std;

class Date{

private:
	string date;		//date string (dd/mm/yyyy)
	int day;			//date day
	int month;			//date month
	int year;			//date year
public:
	Date();									//empty constructor
	Date(string date);						//constructor
	Date(int day, int month, int year);		//constructor
	string getDate();						//returns string date
	int getDay();							//returns date day
	int getMonth();							//returns date month
	int getYear();							//returns date year
	void setDate();							//sets date string
	void setDayMonthYear();					//sets day, month, year
	bool operator==(string date);			//compares date by string
	bool operator<=(Date date);				//compares dates and returns true if a date is earlier or the same date as another one
	bool operator>=(Date date);				//compares dates and returns true if a date is later or the same date as another one
};

#endif
