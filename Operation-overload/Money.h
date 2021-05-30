#pragma once
#include <iostream>
using namespace std;
class Money {
	long int rubles;
	int penny;
public:
	//������������
	Money() { //��� ����������
		rubles = 0;
		penny = 0;
	}
	Money(int r, int p) { //� �����������
		rubles = r;
		penny = p;
	}
	Money(const Money& temp) { //�����������
		rubles = temp.rubles;
		penny = temp.penny;
	}
	//����������
	~Money() {};
	//���������
	int get_rubles() {
		return rubles;
	}
	int get_penny() {
		return penny;
	}
	//������������
	void set_rubles(long int r) {
		rubles = r;
	}
	void set_penny(int p) {
		penny = p;
	}
	//������������� �������� ���������
	bool operator == (const Money&);
	bool operator > (const Money&) ;
	bool operator < (const Money&);
	//������������� �������
	Money& operator + (int);
	Money& operator - (const Money&);
	//���������� ������� �����-������
	friend istream& operator>> (istream& in, Money&);
	friend ostream& operator<< (ostream& out, const Money&);
};