#include <iostream>
#include "Container.h"
using namespace std;
void main() {
	system("chcp 1251");
	int quantity;
	cout << "\nCоздание и заполнение словаря\n\nКол-во элементов в словаре > "; cin >> quantity;
	Container<Money> vec(quantity);
	vec.Print();
	system("pause");
	Money element;
	cout << "\nДобавление существующего элемента словаря\n\nИскомый элемент >\n"; cin >> element;
	int pos = vec.Find(element);
	if (pos == vec.Size() + 1) {
		cout << "\nЭлемент в словаре не найден!\n";
	}
	else {
		cout << "\nЭлеменет в слвоаре найден!\n\nПозиция нового элемента в словаре > "; cin >> pos;
		try {
			if (pos > vec.Size()) {
				throw 1.0;
			}
			vec.Add(element, pos - 1);
			vec.Print();
		}
		catch (double) {
			cout << "\nОшибка индекса\n";
		}
	}
	system("pause");
	cout << "\nУдаление элемента из словаря\n\nИскомый элемент >\n"; cin >> element;
	pos = vec.Find(element);
	if (pos == vec.Size() + 1) {
		cout << "\nЭлемент в словаре не найден!\n";
	}
	else {
		cout << "\nЭлеменет в словаре найден!\n";
		vec.Dell(pos-1);
		vec.Print();
	}
	system("pause");
	cout << "\nУменьшение всех элеменетов словаря\n";
	Money max = vec.Max(), min = vec.Min(), res = max;
	res - min;
	cout << "\nMax элемент словаря = " << max << "\nMin элемент словаря = " << min << "\nРазность Max и Min = " << res << endl;
	vec.Decrease(res);
	vec.Print();
	system("pause");
}