#include <C:\Users\apicd\OneDrive\������� ����\Labs\Lab 18 (Class)\Lab 18.11 (STL)\Lab 18.11 (Task 2)\Money.cpp>
#include <iostream>
#include "Vector.h"
using namespace std;
void main() {
	system("chcp 1251");
	Vector<Money> vec;
	int quantity;
	Money element;
	cout << "\nC������� � ���������� �������\n\n���-�� ��������� � ������ > "; cin >> quantity;
	for (int i = 0; i < quantity; i++) {
		cout << "\n" <<  i + 1 << ")\n"; cin >> element;
		vec.Add(element);
	}
	vec.Show();
	system("pause");
	cout << "\n���������� ������������� �������� �������\n\n������� ������� >\n"; cin >> element;
	int pos = vec.Find(element);
	if (pos == vec.Size() + 1) {
		cout << "\n������� � ������� �� ������!\n";
	}
	else {
		cout << "\n�������� � ������� ������!\n";
		vec.Add(element);
		vec.Show();
	}
	system("pause");
	cout << "\n�������� �������� �� �������\n\n������� ������� >\n"; cin >> element;
	pos = vec.Find(element);
	if (pos == vec.Size() + 1) {
		cout << "\n������� � ������� �� ������!\n";
	}
	else {
		cout << "\n�������� � ������� ������!\n";
		vec.Dell(pos);
		vec.Show();
	}
	system("pause");
	cout << "\n���������� ���� ���������� �������\n";
	Money max = vec.Max(), min = vec.Min(), res = max;
	res - min;
	cout << "\nMax ������� ������� = " << max << "\nMin ������� ������� = " << min << "\n�������� Max � Min = " << res << endl;
	vec.Decrease(res);
	vec.Show();
	system("pause");
}