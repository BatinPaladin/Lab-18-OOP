#include "Money.h"
#include <iostream>
using namespace std;
void main() {
	system("chcp 1251");
	Money sum1, sum2, sum3;
	cout << "Сумма 1\n"; cin >> sum1; cout << "\nСумма 1: " << sum1;
	cout << "\n\nСумма 2\n"; cin >> sum2; cout << "\nСумма 2: " << sum2 << "\n\nВведите сколько копеек прибавить: ";
	int x, op;
	cin >> x; cout << "\nК какой сумме прибавить копейки\n0 - Сумма 1\n1 - Сумма 2\n2 - К обеим суммам\nВаш выбор: "; cin >> op;
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
		cout << "\nУпс ошибочка\n";
	}
	cout << "\nСумма 1: " << sum1 << "\n\nСумма 2: " << sum2 << endl;
	if (sum1 == sum2) {
		cout << "\nСуммы равны\n";
	}
	else if (sum1 > sum2) {
		sum3 = sum1;
		sum3 - sum2;
		cout << "\nСумма 1 больше Суммы 2 на " << sum3 << endl;
	}
	else if (sum1 < sum2) {
		sum3 = sum2;
		sum3 - sum1;
		cout << "\nСумма 1 меньше суммы 2 на " << sum3 << endl;
	}
	system("pause");
}