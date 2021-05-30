#pragma once
#include <iostream>
using namespace std;
const int Lenght = 10;
class Iterator {
	friend class Set;
private:
	int* element;
public:
	Iterator() { 
		element = 0; 
	}
	Iterator(const Iterator& it) {
		element = it.element;
	}
	bool operator == (const Iterator& it){
		if (element == it.element) {
			return true;
		}
		else false;
	}
	void operator ++ () {
		++element;
	}
	void operator -- () {
		--element;
	}
	void operator - (int shift) {
		for (int i = 0; i < shift; i++) {
			--element;
		}
	}
	int& operator *() {
		return*element;
	}
};
class Set {
private:
	int* data;
	int size;
	int max_size;
	Iterator begin;
	Iterator end;
public:
	Set();
	Set(Set&);
	~Set();
	int get_size() {
		return size;
	}
	Iterator first() {
		return begin;
	}
	Iterator last() {
		return end;
	}
	Set& operator = (const Set&);
	void Insert(int);
	int operator [] (int);
	bool operator == (const Set&);
	bool operator > (int);
	friend istream& operator >> (istream&, Set&);
	friend ostream& operator << (ostream&, const Set&);
};