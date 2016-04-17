#include"Date.h"

using namespace std;

Date::Date(string date){
	this->date = date;
	setDay();
	setMonth();
	setYear();
}

Date::Date(int day, int month, int year){
	this->day = day;
	this->month = month;
	this->year = year;
	setDate();
}

string Date::getDate(){
	return date;
}

int Date::getDay(){
	return day;
}

int Date::getMonth(){
	return month;
}

int Date::getYear(){
	return year;
}

void Date::setDate(){
	date = day + '/' + month + '/' + year;
}

void Date::setDay(){
	string d;
	getline(date, )
}



