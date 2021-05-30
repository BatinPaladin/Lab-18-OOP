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
	virtual ~Money() {}
	bool operator == (Money&);
	bool operator != (Money&);
	bool operator > (const Money&);
	bool operator < (const Money&);
	Money& operator = (const Money&);
	Money& operator + (int);
	friend istream& operator >> (istream&, Money&);
	friend ostream& operator << (ostream&, const Money&);
};