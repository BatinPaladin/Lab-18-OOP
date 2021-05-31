#pragma once
#include <iostream>
using namespace std;
class Money {
private:
	long int rubles;
	int penny;
public:
	Money();
	Money(long int, int);
	Money(const Money&);
	~Money();
	Money& operator=(const Money&);
	long int get_rubles();
	int get_penny();
	void set_rubles(long int);
	void set_penny(int);
	bool operator==(const Money&) const;
	bool operator>(const Money&) const;
	bool operator<(const Money&) const;
	Money& operator-(const Money&);
	friend istream& operator>>(istream&, Money&);
	friend ostream& operator<<(ostream&, const Money&);
};
