#include <C:\Users\apicd\OneDrive\Рабочий стол\Labs\Lab 18 (Class)\Lab 18.11 (Sequential STL)\Lab 18.11 (Task 2)\Money.cpp>
#include <iostream>
#include "Vector.h"
using namespace std;
void main() {
	system("chcp 1251");
	Vector<Money> vec;
	int quantity;
	Money element;
	cout << "\nCоздание и заполнение вектора\n\nКол-во элементов в списке > "; cin >> quantity;
	for (int i = 0; i < quantity; i++) {
		cout << i + 1 << ")\n"; cin >> element;
		vec.Add(element, i);
	}
	vec.Show();
	system("pause");
	cout << "\nДобавление существующего элемента вектора\n\nИскомый элемент >\n"; cin >> element;
	int pos = vec.Find(element);
	if (pos == vec.Size() + 1) {
		cout << "\nЭлемент в векторе не найден!\n";
	}
	else {
		cout << "\nЭлеменет в векторе найден!\n\nПозиция нового элемента в векторе > "; cin >> pos;
		try {
			if (pos > vec.Size()) {
				throw 1.0;
		}
		vec.Add(element, pos - 1);
		vec.Show();
		}
		catch (double) {
			cout << "\nОшибка индекса\n";
		}
	}
	system("pause");
	cout << "\nУдаление элемента из вектора\n\nИскомый элемент >\n"; cin >> element;
	pos = vec.Find(element);
	if (pos == vec.Size() + 1) {
		cout << "\nЭлемент в векторе не найден!\n";
	}
	else {
		cout << "\nЭлеменет в векторе найден!\n";
		vec.Dell(pos);
		vec.Show();
	}
	system("pause");
	cout << "\nУменьшение всех элеменетов вектора\n";
	Money max = vec.Max(), min = vec.Min(), res = max;
	res - min;
	cout << "\nMax элемент вектора = " << max << "\nMin элемент вектора = " << min << "\nРазность Max и Min = " << res << endl;
	vec.Decrease(res);
	vec.Show();
	system("pause");
}