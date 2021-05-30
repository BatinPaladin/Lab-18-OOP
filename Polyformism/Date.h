#pragma once
#include "Triad.h"
class Date : public Triad {
public:
	Date(void);
	Date(int, int, int);
	Date(const Date&);
	~Date(void);
	void Show();
	bool operator == (const Date&);
	bool operator > (const Date&);
	bool operator < (const Date&);
	friend istream& operator >> (istream&, Date&);
	friend ostream& operator << (ostream&, const Date&);
};