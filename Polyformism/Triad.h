#pragma once
#include <iostream>
#include "Object.h"
using namespace std;
class Triad : public Object{
protected:
	int first;
	int second;
	int third;
public:
	Triad(void);
	Triad(int, int, int);
	Triad(const Triad&);
	virtual ~Triad(void);
	void Show();
	int get_first() { return first; }
	int get_second() { return second; }
	int get_third() { return third; }
	void set_first(int);
	void set_second(int);
	void set_third(int);
	bool operator == (const Triad&);
	bool operator > (const Triad&);
	bool operator < (const Triad&);
	friend istream& operator >> (istream&, Triad&);
	friend ostream& operator << (ostream&, const Triad&);
};