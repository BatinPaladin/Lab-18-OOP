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
	cout << "\n������ A";
	p->Show();
	p = &B;
	v.Add(p);
	cout << "\n������ B";
	p->Show();
	if (A == B) {
		cout << "\n������ �����\n";
	}
	if (A > B) {
		cout << "\n������ A > ������ B\n";
	}
	if (A < B) {
		cout << "\n������ A < ������ B\n";
	}
	Date C, D(12, 10, 2001);
	cin >> C;
	p = &C;
	v.Add(p);
	cout << "\n���� 1:";
	p->Show();
	p = &D;
	v.Add(p);
	cout << "\n���� 2:";
	p->Show();
	if (C == D) {
		cout << "\n���� �����\n";
	}
	if (C > D) {
		cout << "\n���� 2 ������� ���� 1\n";
	}
	if (C < D) {
		cout << "\n���� 1  ���� 2\n";
	}
	cout << "\n��������� ���������:\n" << v;
	system("pause");
}