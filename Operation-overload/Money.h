#pragma once
#include <iostream>
using namespace std;
class Money {
	long int rubles;
	int penny;
public:
	//Конструкторы
	Money() { //без параметров
		rubles = 0;
		penny = 0;
	}
	Money(int r, int p) { //с параметрами
		rubles = r;
		penny = p;
	}
	Money(const Money& temp) { //копирования
		rubles = temp.rubles;
		penny = temp.penny;
	}
	//Деструктор
	~Money() {};
	//Селекторы
	int get_rubles() {
		return rubles;
	}
	int get_penny() {
		return penny;
	}
	//Модификаторы
	void set_rubles(long int r) {
		rubles = r;
	}
	void set_penny(int p) {
		penny = p;
	}
	//Перегруженные операции сравнения
	bool operator == (const Money&);
	bool operator > (const Money&) ;
	bool operator < (const Money&);
	//Перегруженные функции
	Money& operator + (int);
	Money& operator - (const Money&);
	//Перегрузка функций ввода-вывода
	friend istream& operator>> (istream& in, Money&);
	friend ostream& operator<< (ostream& out, const Money&);
};