#include <iostream>
#include "Money.h"
#include "file_work.h"
#include <fstream>
#include <string>
using namespace std;
void main() {
	system("chcp 1251");
	int op, quantity;
	char file_name[30];
	do {
		cout << "\n===========================\n1 - ������� ����\n2 - ��������� ����\n3 - ������� ������ �� �����\n4 - ������� ������ � ����\n5 - �������� ������ � �����\n0 - �����\n===========================\n\n���� ����� > ";
		cin >> op;
		switch (op) {
		case 1:
			cout << "\n��� ����� > "; cin >> file_name;
			quantity = make_file(file_name);
			if (quantity < 0) {
				cout << "\n���������� ������� ����!\n";
			}
			break;
		case 2:
			cout << "\n��� ����� > "; cin >> file_name;
			quantity = print_file(file_name);
			if (quantity == 0) {
				cout << "\n���� ����!\n";
			}
			if (quantity < 0) {
				cout << "\n���������� �������� ����!\n";
			}
			break;
		case 3:
			cout << "\n��� ����� > "; cin >> file_name;
			quantity = delete_range(file_name);
			if (quantity < 0) {
				cout << "\n���������� �������� ����!\n";
			}
			break;
		case 4:
			cout << "\n��� ����� > "; cin >> file_name;
			quantity = add_begin(file_name);
			if (quantity < 0) {
				cout << "\n���������� �������� ����!\n";
			}
			break;
		case 5:
			cout << "\n��� ����� > "; cin >> file_name;
			quantity = change_file(file_name);
			if (quantity < 0) {
				cout << "\n���������� �������� ����!\n";
			}
			if (quantity == 0) {
				cout << "\n������ � ����� �� �������!\n";
			}
			if (quantity > 0) {
				cout << "\n���-�� ��������� ������� = " << quantity << endl;
			}
			break;
		}
	} while (op != 0);
	system("pause");
}