#pragma once
#include <iostream>
using namespace std;
class Triad {
protected:
	int first;
	int second;
	int third;
public:
	//Конструктор без параметров
	Triad(void);
	//Конструктор с параметрами
	Triad(int, int, int);
	//Конструктор клпирования
	Triad(const Triad&);
	//Деструктор через virtual
	virtual ~Triad(void);
	//Селекторы
	int get_first() { 
		return first; 
	}
	int get_second() {
		return second;
	}
	int get_third() {
		return third;
	}
	//Модификаторы
	void set_first(int);
	void set_second(int);
	void set_third(int);
	//Перегруженные операции сравнения
	bool operator == (const Triad&);
	bool operator > (const Triad&);
	bool operator < (const Triad&);
	//Перегруженные операции ввода/вывода
	friend istream& operator >> (istream&, Triad&);
	friend ostream& operator << (ostream&, const Triad&);
};
