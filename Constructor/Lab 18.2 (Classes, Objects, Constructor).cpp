#include <iostream>
#include <string>
#include "flat.h"
using namespace std;
Flat make_flat() {
	string s;
	cout << "\nВведите адресс квартиры: "; getline(cin,s);
	double d;
	cout << "\nВведите площадь квартиры: "; cin >> d;
	int i;
	cout << "\nВведи кол-во комнат в квартире: "; cin >> i;
	Flat temp(s, d, i);
	return temp;
}
void print_flat(Flat temp) {
	temp.show();
}
void main() {
	system("chcp 1251");
	//Конструктор без параметров
	cout << "\n1.\n";
	Flat apartment1;
	apartment1.show();
	//Конструктор с параметрами
	cout << "\n2.\n";
	Flat apartment2 = {"Ленина 48", 20.0, 3};
	apartment2.show();
	//Конструктор копирования
	cout << "\n3.\n";
	Flat apartment3 = apartment2;
	apartment3.set_adress("Екатериниская 28а");
	apartment3.set_square(14.23);
	apartment3.set_rooms(1);
	print_flat(apartment3);
	//Через функцию make_flat
	cout << "\n4.\n";
	apartment1 = make_flat();
	apartment1.show();
	//Через селекторы
	cout << "\n5.\n";
	string s = apartment2.get_adress();
	double d = apartment2.get_square();
	int i = apartment2.get_rooms();
	cout << "\nКвартира\n\nАдресс: " << s << endl;
	cout << "\nПлощадь: " << d << endl;
	cout << "\nКол-во комнат: " << i << endl;
	system("pause");
}