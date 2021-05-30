#pragma once
#include "Triad.h"
class Date : public Triad {
public: 
	//Конструктор без параметров
	Date(void);
	//Конструктор с параметрами
	Date(int, int, int);
	//Конструктор клпирования
	Date(const Date&);
	//Деструктор
	~Date(void);
	//Перегруженные операции сравнения
	bool operator == (const Date&);
	bool operator > (const Date&);
	bool operator < (const Date&);
	//Перегруженные операции ввода/вывода
	friend istream& operator >> (istream&, Date&);
	friend ostream& operator << (ostream&, const Date&);
};

