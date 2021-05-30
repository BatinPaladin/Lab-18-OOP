#pragma once
#include <iostream>
#include "Person.h"
using namespace std;
class Abiturient : public Person {
protected:
	int points; //Баллы
	string special; //Специализация
public:
	Abiturient();
	Abiturient(string, int, int, string);
	Abiturient(const Abiturient&);
	~Abiturient();
	void Show();
	void Input();
	int get_points();
	string get_special();
	void set_points(int);
	void set_special(string);
	Abiturient& operator = (const Abiturient&);
};