#include <iostream>
#include "Container.h"
using namespace std;
void main() {
	system("chcp 1251");
	int quantity;
	cout << "\nC������� � ���������� �������\n\n���-�� ��������� � ������� > "; cin >> quantity;
	Container<Money> vec(quantity);
	vec.Print();
	system("pause");
	Money element;
	cout << "\n���������� ������������� �������� �������\n\n������� ������� >\n"; cin >> element;
	int pos = vec.Find(element);
	if (pos == vec.Size() + 1) {
		cout << "\n������� � ������� �� ������!\n";
	}
	else {
		cout << "\n�������� � ������� ������!\n\n������� ������ �������� � ������� > "; cin >> pos;
		try {
			if (pos > vec.Size()) {
				throw 1.0;
			}
			vec.Add(element, pos - 1);
			vec.Print();
		}
		catch (double) {
			cout << "\n������ �������\n";
		}
	}
	system("pause");
	cout << "\n�������� �������� �� �������\n\n������� ������� >\n"; cin >> element;
	pos = vec.Find(element);
	if (pos == vec.Size() + 1) {
		cout << "\n������� � ������� �� ������!\n";
	}
	else {
		cout << "\n�������� � ������� ������!\n";
		vec.Dell(pos-1);
		vec.Print();
	}
	system("pause");
	cout << "\n���������� ���� ���������� �������\n";
	Money max = vec.Max(), min = vec.Min(), res = max;
	res - min;
	cout << "\nMax ������� ������� = " << max << "\nMin ������� ������� = " << min << "\n�������� Max � Min = " << res << endl;
	vec.Decrease(res);
	vec.Print();
	system("pause");
}