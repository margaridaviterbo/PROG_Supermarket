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

bool Date::isBetween(Date date1, Date date2){	//TODO nao está completament bem
	bool date1Minordate2;
	bool date1MinorOrEqualThisDate;
	bool date2MajorOrEqualThisDate;

	if (date1.year < date2.year)
		date1Minordate2 = true;
	else if ((date1.year = date2.year) && (date1.month < date2.month))
		date1Minordate2 = true;
	else if ((date1.year = date2.year) && (date1.month = date2.month) && (date1.day < date2.day))
		date1Minordate2 = true;
	else
		date1Minordate2 = false;

	if (date1.year < this->year)
		date1MinorOrEqualThisDate = true;
	else if ((date1.year = this->year)){
		if (date1.month < this->month)
			date1MinorOrEqualThisDate = true;
		else if ((date1.month = this->month) && (date1.day <= this->day))
			date1MinorOrEqualThisDate = true;
	}
	else
		date1MinorOrEqualThisDate = false;

	if (date2.year > this->year)
		date2MajorOrEqualThisDate = true;
	else if ((date2.year = this->year)){
		if (date2.month > this->month)
			date2MajorOrEqualThisDate = true;
		else if ((date1.month = this->month) && (date1.day >= this->day))
			date2MajorOrEqualThisDate = true;
	}
	else
		date2MajorOrEqualThisDate = false;

	if (date1Minordate2 == true && date1MinorOrEqualThisDate == true && date2MajorOrEqualThisDate == true)
		return true;
	else if (date1Minordate2 == false && date1MinorOrEqualThisDate == false && date2MajorOrEqualThisDate == false)
		return true;
	else return false;

}

