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
	cin >> A; cout << "\n������ A " << A << "\n������ B " << B;
	if (A == B) {
		cout << "\n������ �����\n";
	}
	if (A > B) {
		cout << "\n������ A > ������ B\n" ;
	}
	if (A < B) {
		cout << "\n������ A < ������ B\n";
	}
	Date C;
	cin >> C; cout << "\n���� 1: " << C;
	Date D(12, 10, 2001);
	cout << "\n���� 2: " << D;
	if (C == D) {
		cout << "\n���� �����\n";
	}
	if (C > D) {
		cout << "\n���� 2 ������� ����� ���� 1\n";
	}
	if (C < D) {
		cout << "\n���� 1 ������� ����� ���� 2\n";
	}
	cout << "\n�����������";
	f1(C);
	A = f2();
	cout << A;
	system("pause");
}