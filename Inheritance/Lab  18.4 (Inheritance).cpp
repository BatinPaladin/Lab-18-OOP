#include <iostream>
#include "Triad.h"
#include "Date.h"
using namespace std;
void f1(Triad& temp) {
	temp.set_first(2);
	temp.set_second(5);
	cout << temp;
}
Triad f2() {
	Date d(3, 5, 2002);
	return d;
}
void main() {
	system("chcp 1251");
	Triad A, B(3, 5, 20);
	cin >> A; cout << "\nТриада A " << A << "\nТриада B " << B;
	if (A == B) {
		cout << "\nТриады равны\n";
	}
	if (A > B) {
		cout << "\nТриада A > Триады B\n" ;
	}
	if (A < B) {
		cout << "\nТриада A < Триады B\n";
	}
	Date C;
	cin >> C; cout << "\nДата 1: " << C;
	Date D(12, 10, 2001);
	cout << "\nДата 2: " << D;
	if (C == D) {
		cout << "\nДаты равны\n";
	}
	if (C > D) {
		cout << "\nДата 2 следует после Даты 1\n";
	}
	if (C < D) {
		cout << "\nДата 1 следует после Даты 2\n";
	}
	cout << "\nПодстановка";
	f1(C);
	A = f2();
	cout << A;
	system("pause");
}