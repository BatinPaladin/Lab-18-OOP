#include <C:\Users\apicd\OneDrive\Рабочий стол\Labs\Lab 18 (Class)\Lab 18.12 (Associative STL)\Lab 18.12 (Task 2)\Money.cpp>
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;
typedef list<Money> TList;
TList::iterator it;
Money res;

TList make_list(int quantity) {
	Money el;
	TList list;
	for (int i = 0; i < quantity; i++) {
		cout << i + 1 << ")\n"; cin >> el;
		list.push_back(el);
	}
	return list;
}

void print_list(TList list) {
	int lenght = list.size();
	cout << "\nСписок:\n";
	for (int i = 0; i < lenght; i++) {
		cout << list.front() << " ";
		list.pop_front();
	}
	cout << endl;
}

void add_list(TList& list, const Money element) {
	it = find(list.begin(), list.end(), element);
	if (it != list.end()) {
		int pos;
		cout << "\nЭлеменет в списке найден!\n\nПозиция нового элемента в списке > "; cin >> pos;
		try {
			if (pos > list.size()) {
				throw 1.0;
			}
			TList temp_list;
			int lenght = list.size();
			for (int i = 0; i < pos - 1; i++) {
				temp_list.push_back(list.front());
				list.pop_front();
			}
			temp_list.push_back(element);
			for (int i = pos; i < lenght + 1; i++) {
				temp_list.push_back(list.front());
				list.pop_front();
			}
			list.clear();
			list = temp_list;
			temp_list.clear();
		}
		catch (double) {
			cout << "\nОшибка индекса\n";
		}
		print_list(list);
	}
	else {
		cout << "\nЭлемент в списке не найден!\n";
	}
}

void del_list(TList& list, const Money element) {
	it = find(list.begin(), list.end(), element);
	if (it != list.end()) {
		list.erase(it);
		print_list(list);
	}
	else {
		cout << "\nЭлемент в списке не найден!\n";
	}
}

Money max_list(TList list) {
	it = list.begin();
	Money max = (*it);
	while (it != list.end()) {
		if (max < (*it)) {
			max = (*it);
		}
		it++;
	}
	return max;
}

Money min_list(TList list) {
	it = list.begin();
	Money min = (*it);
	while (it != list.end()) {
		if (min > (*it)) {
			min = (*it);
		}
		it++;
	}
	return min;
}

void decrease(Money& element) {
	element - res;
}

void main() {
	system("chcp 1251");
	int quantity;
	cout << "\nCоздание и заполнение списка\n\nКол-во элементов в списке > ";
	do {
		cin >> quantity;
		if (quantity < 1) {
			cout << "\nВведите положительное кол-во элемнетов > ";
		}
	} while (quantity < 1);
	TList list;
    list = make_list(quantity);
	print_list(list);
	Money key;
	cout << "\nДобавление существующего элемента списка\n\nИскомый элемент >\n"; cin >> key;
	add_list(list, key);
	cout << "\nУдаление элементов из списка\n\nИскомый элемент >\n"; cin >> key;
	del_list(list, key);
	cout << "\nУменьшение всех элеменетов списка\n";
	Money max = max_list(list), min = min_list(list);
	res = max;
	res - min;
	cout << "\nMax элемент списка = " << max << "\nMin элемент списка = " << min << "\nРазность Max и Min = " << res << endl;
	for_each(list.begin(), list.end(), decrease);
	print_list(list);
	system("pause");
}