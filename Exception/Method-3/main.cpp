#include <iostream>
#include "Set.h"
#include "Error.h"
using namespace std;
int main() {
	system("chcp 1251");
	Set A, B;
	try {
		cout << "\n���������� �������� A:\n"; cin >> A;
	}
	catch (Error &e) {
		e.what();
	}
	try {
		cout << "\n���������� �������� B:\n"; cin >> B;
	}
	catch (Error &e) {
		e.what();
	}
	cout << "\n���������� ��������� A: " << A;
	cout << "\n���������� ��������� B: " << B;
	if (A == B) {
		cout << "\n��������� �����\n";
	}
	else {
		cout << "\n��������� �� �����\n";
	}
	int value;
	try {
		cout << "\n�������� ��������� '[]' �� ��������� �\n������� ������:\n> "; cin >> value; cout << A[value - 1] << endl;
	}
	catch (Error &e) {
		e.what();
	}
	cout << "\n�������� ��������� '>' �� ��������� �\n������� �������:\n> "; cin >> value;
	if (A > value) {
		cout << "\n������� " << value << " �� ��������� ����!\n";
	}
	else {
		cout << "\n�������� " << value << " �� ��������� ���!\n";
	}
	try {
		int size; size = A.get_size();
		cout << "\n�������� ��������� '-' �� ��������� �\n������� �����:\n> "; cin >> value; 
		cout << A[size - 1] << endl << A - value << endl;
	}
	catch (Error &e) {
		e.what();
	}
	system("pause");
	return 0;
}