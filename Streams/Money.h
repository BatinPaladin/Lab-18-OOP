#pragma once
#include <iostream> //���������� ��� ������ � ������������ ��������
#include <fstream> //���������� ��� ������ � ��������� ��������
#include <string>
using namespace std;
class Money {
	long int rubles;
	int penny;
public:
	Money();
	Money(long int, int);
	Money(const Money&);
	Money& operator = (const Money&);
	int get_rubles();
	int get_penny();
	void set_rubles(long int);
	void set_penny(int);
	bool operator == (const Money&);
	bool operator > (const Money&);
	bool operator < (const Money&);
	Money& operator + (int);
	friend istream& operator>> (istream& in, Money&);
	friend ostream& operator<< (ostream& out, const Money&);
	friend fstream& operator>> (fstream& fin, Money&);
	friend fstream& operator<< (fstream& fout, const Money&);
	~Money();
};
