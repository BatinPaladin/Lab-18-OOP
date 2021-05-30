#include <iostream>
#include "Triad.h"
#include "Object.h"
#include "Date.h"
#include "Vector.h"
using namespace std;
void main() {
	system("chcp 1251");
	Vector v(3);
	Triad A, B(3, 5, 20);
	Object* p;
	cin >> A; 	
	p = &A;
	v.Add(p);
	cout << "\nТриада A";
	p->Show();
	p = &B;
	v.Add(p);
	cout << "\nТриада B";
	p->Show();
	if (A == B) {
		cout << "\nТриады равны\n";
	}
	if (A > B) {
		cout << "\nТриада A > Триады B\n";
	}
	if (A < B) {
		cout << "\nТриада A < Триады B\n";
	}
	Date C, D(12, 10, 2001);
	cin >> C;
	p = &C;
	v.Add(p);
	cout << "\nДата 1:";
	p->Show();
	p = &D;
	v.Add(p);
	cout << "\nДата 2:";
	p->Show();
	if (C == D) {
		cout << "\nДаты равны\n";
	}
	if (C > D) {
		cout << "\nДата 2 следует Дате 1\n";
	}
	if (C < D) {
		cout << "\nДата 1  Дате 2\n";
	}
	cout << "\nМножество укзателей:\n" << v;
	system("pause");
}