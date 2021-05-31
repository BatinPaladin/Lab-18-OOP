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
Money::~Money() { }
Money& Money::operator=(const Money& temp_Money) {
	if (*this == temp_Money) {
		return *this;
	}
	rubles = temp_Money.rubles;
	penny = temp_Money.penny;
	return *this;
}
long int Money::get_rubles() {
	return rubles;
}
int Money::get_penny() {
	return penny;
}
void Money::set_rubles(long int r) {
	rubles = r;
}
void Money::set_penny(int p) {
	penny = p;
}
bool Money::operator==(const Money& temp_Money) const{
	return (rubles == temp_Money.rubles && penny == temp_Money.penny);
}
bool Money::operator>(const Money& temp_Money) const{
	return (rubles * 100 + penny > temp_Money.rubles * 100 + temp_Money.penny);
}
bool Money::operator<(const Money& temp_Money) const{
	return (rubles * 100 + penny < temp_Money.rubles * 100 + temp_Money.penny);
}
Money& Money::operator-(const Money& temp_Money) {
	long int sum1 = rubles * 100 + penny;
	long int sum2 = temp_Money.rubles * 100 + temp_Money.penny;
	sum1 -= sum2;
	rubles = sum1 / 100;
	if (sum1 < 0) {
		sum1 *= -1;
	}
	penny = sum1 % 100;
	return *this;
}
istream& operator>> (istream& in, Money& temp_Money) {
	do {
		cout << "Рубли: "; in >> temp_Money.rubles;
	} while (temp_Money.rubles < 0);
	do {
		cout << "Копейки: "; in >> temp_Money.penny;
	} while (temp_Money.penny > 99 || temp_Money.penny < 0);
	return in;
}
ostream& operator << (ostream& out, const Money& temp_Money) {
	if (temp_Money.penny < 10) {
		out << temp_Money.rubles << ",0" << temp_Money.penny;
	}
	else {
		out << temp_Money.rubles << "," << temp_Money.penny;
	}
	return out;
}