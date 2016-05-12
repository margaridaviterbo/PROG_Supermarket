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

void Date::setDayMonthYear(){
	day = date.at(0) + date.at(1);
	month = date.at(3) + date.at(4);
	year = date.at(6) + date.at(7) + date.at(8) + date.at(9);	//TODO corrigir porque crasha nesta linha (date.at(9))
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
