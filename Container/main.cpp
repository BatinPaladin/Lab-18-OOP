#include <iostream>
#include "Set.h"
using namespace std;
void main() {
	system("chcp 1251");
	Set a, b;
	int number, size_a;
	cout << "\n���������� ��������� a\n"; cin >> a; cout << "\n��������� a " << a;
	b.Insert(12);
	b.Insert(4);
	b.Insert(10);
	b.Insert(0);
	system("pause");
	cout << "\n�������\n> "; cin >> number;
	a.Insert(number);
	cout << "\n������� " << number << " �������� �� ��������� a\n";
	system("pause");
	cout << "\n��������� ��������\n\n��������� a " << a << "\n��������� b " << b;
	if (a == b) {
		cout << "\n��������� �����!\n";
	}
	else {
		cout << "\n��������� �� �����!\n";
	}
	system("pause");
	cout << "\n����� ����� �� ��������� a\n�����\n> "; cin >> number;
	if (a > number) {
		cout << "\n����� �� ��������� ����!\n";
	}
	else {
		cout << "\n����� �� ��������� ���!\n";
	}
	system("pause");
	int size = a.get_size();
	cout << "\n������ � �������� ��������� a\n\n����� ��������"; 
	do {
		cout << "\n> ";
		cin >> number;
		if (number > size) {
			cout << "\n������� ������ ������� ����� ���������\n";
		}
		if (number < 1) {
			cout << "\n������� ������������� ������\n";
		}
	} while (number > size || number < 1);
	cout << "\na[" << number << "] = " << a[number-1] << endl;
	system("pause");
	cout << "\n��������� a\n\n������ ������� ��������� - " << *(a.first()) << "\n��������� ������� ��������� - " << *(a.last()) << endl;
	Iterator it = a.last();
	size_a = a.get_size();
	cout << "\n�������� = " << *(it);
	cout << "\n����� ��������� � = " << size_a << "\n\n�� ������� ��������� �������� ��������?\n";
	do {
		cout << "\n�����\n> "; cin >> number;
		if (number >= size_a) {
			cout << "\n������� ����� ������ ����� ���������\n";
		}
		if (number < 0) {
			cout << "\n������� ������������� �����\n";
		}
	} while (number >= size_a || number < 0);
	it - number;
	cout << "\n�������� = " << *(it) << endl;
	system("pause");
}