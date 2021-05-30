#pragma once
#include <iostream>
using namespace std;
class Triad {
protected:
	int first;
	int second;
	int third;
public:
	//����������� ��� ����������
	Triad(void);
	//����������� � �����������
	Triad(int, int, int);
	//����������� �����������
	Triad(const Triad&);
	//���������� ����� virtual
	virtual ~Triad(void);
	//���������
	int get_first() { 
		return first; 
	}
	int get_second() {
		return second;
	}
	int get_third() {
		return third;
	}
	//������������
	void set_first(int);
	void set_second(int);
	void set_third(int);
	//������������� �������� ���������
	bool operator == (const Triad&);
	bool operator > (const Triad&);
	bool operator < (const Triad&);
	//������������� �������� �����/������
	friend istream& operator >> (istream&, Triad&);
	friend ostream& operator << (ostream&, const Triad&);
};
