#include "Money.h"
Money::Money() {
	rubles = 0;
	penny = 0;
}
Money::Money(long int r, int p) {
	rubles = r;
	penny = p;
}
Money::Money(const Money& temp_Money) {
	rubles = temp_Money.rubles;
	penny = temp_Money.penny;
}
Money& Money::operator=(const Money& temp_Money) {
	if (*this == temp_Money) {
		return *this;
	}
	rubles = temp_Money.rubles;
	penny = temp_Money.penny;
	return *this;
}
int Money::get_rubles() {
	return rubles;
}
void Money::set_rubles(long int r) {
	rubles = r;
}
int Money::get_penny() {
	return penny;
}
void Money::set_penny(int p) {
	penny = p;
}
bool Money::operator==(const Money& temp_Money) {
	return (rubles == temp_Money.rubles && penny == temp_Money.penny);
}
bool Money::operator>(const Money& temp_Money) {
	return (rubles * 100 + penny > temp_Money.rubles * 100 + temp_Money.penny);
}
bool Money::operator<(const Money& temp_Money) {
	return (rubles * 100 + penny < temp_Money.rubles * 100 + temp_Money.penny);
}
Money& Money::operator+(int x) {
	long int Money = rubles * 100 + penny;
	Money += x;
	rubles = Money / 100;
	penny = Money % 100;
	return *this;
}
Money::~Money() { }
istream& operator>>(istream& in, Money& temp_Money) {
	do {
		cout << "\nРубли > "; in >> temp_Money.rubles;
	} while (temp_Money.rubles < 0);
	do {
		cout << "Копейки > "; in >> temp_Money.penny;
	} while (temp_Money.penny > 99 || temp_Money.penny < 0);
	return in;
}
ostream& operator<<(ostream& out, const Money& temp_Money) {
	if (temp_Money.penny < 10) {
		out << temp_Money.rubles << ",0" << temp_Money.penny;
	}
	else {
		out << temp_Money.rubles << "," << temp_Money.penny;
	}
	return out;
}
fstream& operator>>(fstream& fin, Money& temp_Money) {
	string str;
	getline(fin, str, ',');
	if (str.length() > 0) {
		temp_Money.rubles = stoi(str);
	}
	getline(fin, str);
	if (str.length() > 0) {
		temp_Money.penny = stoi(str);
	}
	return fin;
}
fstream& operator<<(fstream& fout, const Money& temp_Money) {
	if (temp_Money.penny < 10) {
		fout << temp_Money.rubles << ",0" << temp_Money.penny;
	}
	else {
		fout << temp_Money.rubles << "," << temp_Money.penny;
	}
	return fout;
}