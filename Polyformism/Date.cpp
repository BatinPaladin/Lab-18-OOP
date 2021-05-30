#include "Date.h"
#include <iostream>
Date::Date(void) :Triad() {}
Date::Date(int d, int m, int y) : Triad(d, m, y) {}
Date::Date(const Date& temp) {
	first = temp.first;
	second = temp.second;
	third = temp.third;
}
Date::~Date(void) {}
void Date::Show() {
	if (first < 10) {
		cout << "\n0" << first << ".";
	}
	else {
		cout << "\n" << first << ".";
	}
	if (second < 10) {
		cout << "0" << second << ".";
	}
	else {
		cout << second << ".";
	}
	cout << third << "\n";
}
bool Date::operator==(const Date& temp) {
	if (first == temp.first && second == temp.second && third == temp.third) {
		return true;
	}
	return false;
}
bool Date::operator>(const Date& temp) {
	long int date1 = first + second * 100 + third * 10000;
	long int date2 = temp.first + temp.second * 100 + temp.third * 10000;;
	if (date1 > date2) {
		return true;
	}
	return false;
}
bool Date::operator<(const Date& temp) {
	long int date1 = first + second * 100 + third * 10000;
	long int date2 = temp.first + temp.second * 100 + temp.third * 10000;;
	if (date1 < date2) {
		return true;
	}
	return false;
}
istream& operator >> (istream& in, Date& temp) {
	cout << "\n";
	do {
		cout << "×טסכמ - "; in >> temp.first;
	} while (temp.first < 1 || temp.first>31);
	do {
		cout << "Ìוסÿצ - "; in >> temp.second;
	} while (temp.second < 1 || temp.second>12);
	do {
		cout << "Ãמה - "; in >> temp.third;
	} while (temp.third < 1 || temp.third>2021);
	return in;
}
ostream& operator << (ostream& out, const Date& temp) {
	if (temp.first < 10) {
		out << "\n0" << temp.first << ".";
	}
	else {
		out << "\n" << temp.first << ".";
	}
	if (temp.second < 10) {
		out << "0" << temp.second << ".";
	}
	else {
		out << temp.second << ".";
	}
	out << temp.third << "\n";
	return out;
}
