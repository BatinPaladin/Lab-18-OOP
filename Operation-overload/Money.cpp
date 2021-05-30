#include <iostream>
#include "Money.h"
using namespace std;
bool Money::operator == (const Money& temp) {
	return (rubles == temp.rubles && penny == temp.penny);
}
bool Money::operator > (const Money& temp) {
	return (rubles * 100 + penny > temp.rubles * 100 + temp.penny);
}
bool Money::operator < (const Money& temp) {
	return (rubles * 100 + penny < temp.rubles * 100 + temp.penny);
}
Money& Money::operator + (int x) {
	long int temp = rubles * 100 + penny;
	temp += x;
	rubles = temp / 100;
	penny = temp % 100;
	return *this;
}
Money& Money::operator - (const Money& temp) {
	long int sum1 = rubles * 100 + penny;
	long int sum2 = temp.rubles * 100 + temp.penny;
	sum1 -= sum2;
	rubles = sum1 / 100;
	penny = sum1 % 100;
	return *this;
}
istream& operator >> (istream& in, Money& temp) {
	do {
		cout << "Рубли: "; in >> temp.rubles;
	} while (temp.rubles < 0);
	do {
		cout << "Копейки: "; in >> temp.penny;
	} while (temp.penny>99 || temp.penny < 0);
	return in;
}
ostream& operator << (ostream& out, const Money& temp) {
	if (temp.penny < 10) {
		return (out << temp.rubles << ",0" << temp.penny);
	}
	else { 
		return (out << temp.rubles << "," << temp.penny); 
	}
}