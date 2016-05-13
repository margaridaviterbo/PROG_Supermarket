#include"Date.h"
#include <sstream>

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

void Date::setDayMonthYear(){		//TODO corrigir porque guarda lixo em mes e ano FAZER BUFF.STR("") EM VEZ DE CLEAR
	stringstream buf;
	int temp;
	char tmp_str[2];
	char tmp_year[4];

	tmp_str[0] = date.c_str()[0];
	tmp_str[1] = date.c_str()[1];


	cout << tmp_str[0] << endl;
	cout << tmp_str[1] << endl;	

	buf << tmp_str;
	buf >> day;
	buf.clear();
	buf.ignore();

	tmp_str[0] = date.c_str()[3];
	tmp_str[1] = date.c_str()[4];

	cout << "Mes " << endl;
	cout << tmp_str[0] << endl;
	cout << tmp_str[1] << endl;
	 
	buf.str("");

	buf << tmp_str;
	buf >> month;
	buf.clear();
	buf.ignore();

	tmp_year[0] = date.c_str()[6];
	tmp_year[1] = date.c_str()[7];
	tmp_year[2] = date.c_str()[8];
	tmp_year[3] = date.c_str()[9];

	cout << "Ano " << endl;
	cout << tmp_year[0] << endl;
	cout << tmp_year[1] << endl;
	cout << tmp_year[2] << endl;
	cout << tmp_year[3] << endl;

	buf << tmp_str;
	buf >> year;
	buf.clear();
	buf.ignore();
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
