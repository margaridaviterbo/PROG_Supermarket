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
	istringstream instr(date);
	instr >> day >> month >> year;
}

bool Date::isEqual(string date){
	if (date == this->date)
		return true;
	else
		return false;
}

bool Date::isBetween(Date date1, Date date2){
	
	if ((date1.year < this->year < date2.year) || (date2.year < this->year < date1.year))
		return true;
	else if (((date1.year = this->year <= date2.year) && (date1.month < this->month))
		|| ((date2.year = this->year <= date1.year) && (date2.month< this->month)))
		return true;


	
}

