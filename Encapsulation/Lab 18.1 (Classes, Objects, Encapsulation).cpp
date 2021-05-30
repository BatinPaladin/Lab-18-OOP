#include <iostream>
#include "coordinates.h"
using namespace std;
coordinates make_coordinates(double F, double S) {
	coordinates temp;
	temp.Init(F,S);
	return temp;
}
void main() {
	system("chcp 1251");
	//Через main
	coordinates A;
	coordinates B;
	cout << "\nТочка А\nx = 4.5\ny = 3.6";
	A.Init(4.5, 3.6);
	cout << "\n\nТочка А";
	A.Show();
	cout << "\nРасстояние от начала координат до точки А = " << A.distance() << endl;
	cout << "\nТочка B";
	B.Read();
	cout << "\nТочка B";
	B.Show();
	cout << "\nРасстояние от начала координат до точки B = " << B.distance() << endl;
	//Указатель
	coordinates* X = new coordinates;
	cout << "\nТочка X\nx = 2.4\ny = 0.5";
	X->Init(2.4, 0.5);
	cout << "\n\nТочка X";
	X->Show();
	cout << "\nРасстояние от начала координат до точки X = " << X->distance();
	delete X;
	//Массив
	coordinates mas[3];
	for (int i = 0; i < 3; i++) {
		cout << "\n\nТочка C" << i + 1;
		mas[i].Read();
		cout << "\nТочка C" << i + 1;
		mas[i].Show();
		cout << "\nРасстояние от начала координат до точки C" << i+1 << " = " << mas[i].distance();
	}
	//Динамический массив
	coordinates* p_mas = new coordinates[3];
	for (int i = 0; i < 3; i++) {
		cout << "\n\nТочка D" << i + 1;
		p_mas[i].Read();
		cout << "\nТочка D" << i + 1;
		p_mas[i].Show();
		cout << "\nРасстояние от начала координат до точки D" << i + 1 << " = " << p_mas[i].distance();
	}
	delete[] p_mas;
	//Через функцию make_coordinates
	double x, y;
	cout << "\n\nТочка F";
	cout << "\nx = "; cin >> x;
	cout << "y = "; cin >> y;
	coordinates F = make_coordinates(x, y);
	cout << "\nТочка F";
	F.Show();
	cout << "\nРасстояние от начала координат до точки F = " << F.distance() << endl;
	system("pause");
}