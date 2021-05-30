#include "Triad.h"
#include <iostream>
Triad::Triad(void) {
	first = 1;
	second = 1;
	third = 1;
}
Triad::Triad(int f, int s, int t) {
	first = f;
	second = s;
	third = t;
}
Triad::Triad(const Triad& temp) {
	first = temp.first;
	second = temp.second;
	third = temp.third;
}
Triad::~Triad(void) {

}
void Triad::Show() {
	cout << "\n" << first << " " << second << " " << third << "\n";
}
void Triad::set_first(int f) {
	first = f;
}
void Triad::set_second(int s) {
	second = s;
}
void Triad::set_third(int t) {
	third = t;
}
bool Triad::operator == (const Triad& temp) {
	if (first == temp.first && second==temp.second && third == temp.third) {
		return true;
	}
	return false;
}
bool Triad::operator > (const Triad& temp) {
	long int triad1 = first + second * 100 + third * 10000;
	long int triad2 = temp.first + temp.second * 100 + temp.third * 10000;
	if (triad1 > triad2) {
		return true;
	}
	return false;
}
bool Triad::operator < (const Triad& temp) {
	long int triad1 = first + second * 100 + third * 10000;
	long int triad2 = temp.first + temp.second * 100 + temp.third * 10000;
	if (triad1 < triad2) {
		return true;
	}
	return false;
}
istream& operator >> (istream& in, Triad& temp) {
	cout << "\n";
	do {
		cout << "1 - "; in >> temp.first;
	} while (temp.first < 1);
	do {
		cout << "2 - "; in >> temp.second;
	} while (temp.second < 1);
	do {
		cout << "3 - "; in >> temp.third;
	} while (temp.third < 1);
	return in;
}
ostream& operator << (ostream& out, const Triad& temp) {
	out << "\n" << temp.first << " " << temp.second << " " << temp.third << "\n";
	return out;
}
