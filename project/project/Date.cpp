#include"Date.h"

using namespace std;

Date::Date(){

}

Date::Date(string date){
	this->date = date;
	setDayMonthYear();
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

void Date::setDayMonthYear(){		//TODO crrigir esta funçao porqu 
	int dmy[3];
	int j = 0;
	
	for (int i = 0; i < date.size(); i + 3){
		dmy[j] = date.at(i) + date.at(i + 1);
		j++ ;
	}

	day = dmy[0];
	month = dmy[1];
	year = dmy[2];
}

bool Date::operator==(string date){
	if (date == this->date)
		return true;
	else
		return false;
}

bool Date::operator<=(Date date){

	if (year < date.year)
		return true;
	else if (year == date.year) 
		if (month < date.month)
			return true;
		else if ((month == date.month) && (day <= date.day))
		return true;
	else
		return false;
}

bool Date::operator>=(Date date){
	if (year > date.year)
		return true;
	else if (year == date.year)
		if (month > date.month)
			return true;
		else if ((month == date.month) && (day >= date.day))
			return true;
		else
			return false;
}
