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
bool Money:: operator == (Money& temp_Money) {
	long int temp1 = rubles * 100 + penny;
	long int temp2 = temp_Money.rubles * 100 + temp_Money.penny;
	if (temp1 == temp2) {
		return true;
	}
	return false;
}
bool Money:: operator != (Money& temp_Money) {
	long int temp1 = rubles * 100 + penny;
	long int temp2 = temp_Money.rubles * 100 + temp_Money.penny;
	if (temp1 != temp2) {
		return true;
	}
	return false;
}
bool Money::operator>(const Money& temp_Money) {
	return (rubles * 100 + penny > temp_Money.rubles * 100 + temp_Money.penny);
}
bool Money::operator<(const Money& temp_Money)
{
	return (rubles * 100 + penny < temp_Money.rubles * 100 + temp_Money.penny);
}
Money& Money::operator = (const Money& temp_Money) {
	rubles = temp_Money.rubles;
	penny = temp_Money.penny;
	return *this;
}
Money& Money::operator + (int x) {
	long int temp = rubles * 100 + penny;
	temp += x;
	rubles = temp / 100;
	penny = temp % 100;
	return *this;
}
istream& operator >> (istream& in, Money& temp_Money) {
	do {
		cout << "\nРубли: "; in >> temp_Money.rubles;
	} while (temp_Money.rubles < 0);
	do {
		cout << "Копейки: "; in >> temp_Money.penny;
	} while (temp_Money.penny > 99 || temp_Money.penny < 0);
	return in;
}
ostream& operator<<(ostream& out, const Money& temp_Money) {
	if (temp_Money.penny < 10) {
		return (out << temp_Money.rubles << ",0" << temp_Money.penny);
	}
	else {
		return (out << temp_Money.rubles << "," << temp_Money.penny);
	}
}
