#include "Money.h"
#include <iostream>
using namespace std;
void main() {
	system("chcp 1251");
	Money sum1, sum2, sum3;
	cout << "����� 1\n"; cin >> sum1; cout << "\n����� 1: " << sum1;
	cout << "\n\n����� 2\n"; cin >> sum2; cout << "\n����� 2: " << sum2 << "\n\n������� ������� ������ ���������: ";
	int x, op;
	cin >> x; cout << "\n� ����� ����� ��������� �������\n0 - ����� 1\n1 - ����� 2\n2 - � ����� ������\n��� �����: "; cin >> op;
	switch (op) {
	case(0): 
		sum1 + x;
		break;
	case(1):
		sum2 + x;
		break;
	case(2):
		sum1 + x;
		sum2 + x;
		break;
	default:
		cout << "\n��� ��������\n";
	}
	cout << "\n����� 1: " << sum1 << "\n\n����� 2: " << sum2 << endl;
	if (sum1 == sum2) {
		cout << "\n����� �����\n";
	}
	else if (sum1 > sum2) {
		sum3 = sum1;
		sum3 - sum2;
		cout << "\n����� 1 ������ ����� 2 �� " << sum3 << endl;
	}
	else if (sum1 < sum2) {
		sum3 = sum2;
		sum3 - sum1;
		cout << "\n����� 1 ������ ����� 2 �� " << sum3 << endl;
	}
	system("pause");
}