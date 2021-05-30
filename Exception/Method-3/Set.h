#pragma once
#include <iostream>
using namespace std;
const int MAX_SIZE = 20;
class Set {
private:
	int* data;
	int size;
public:
	Set();
	Set(Set&);
	~Set();
	void Insert(int);
	int get_size();
	Set& operator = (const Set&);
	int operator [] (int);
	bool operator > (int);
	bool operator == (const Set&);
	int operator - (int);
	friend ostream& operator << (ostream&, const Set&);
	friend istream& operator >> (istream&, Set&);
};