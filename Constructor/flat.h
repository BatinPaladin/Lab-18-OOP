#pragma once
#include <iostream>
#include <string>
using namespace std;
class Flat {
	string adress;
	double square;
	int rooms;
public:
	Flat();//Конструкторо без параметров
	Flat(string, double, int);//Конструктор с параметрами
	Flat(const Flat&);//Конструктор копирования
	~Flat();//Деструктор
	string get_adress();//Селектор
	void set_adress(string);//Модификатор
	double get_square();//Селектор
	void set_square(double);//Модификатор
	int get_rooms();//Селектор
	void set_rooms(int);//Модификатор
	void show();//Просмотр атрибутов
};