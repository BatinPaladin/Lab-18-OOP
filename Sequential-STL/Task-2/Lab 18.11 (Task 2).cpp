#include <list>
#include <iostream>
#include "Money.h"
using namespace std;
typedef list<Money> List;
List make_list(int quantity) {
	List L;
	for (int i = 0; i < quantity; i++) {
		Money number;
		cout << i + 1 << ")\n"; cin >> number;
		L.push_back(number);
	}
	return L;
}
void print_list(List L) {
	int lenght = L.size();
	cout << "\nСписок:\n";
	for (int i = 0; i < lenght; i++) {
		cout << L.front() << " ";
		L.pop_front();
	}
	cout << endl;
}
int find_element(List L, const Money element) {
	int lenght = L.size(), i = 0;
	bool flag = true;
	while (i < lenght && flag) {
		if (L.front() == element) {
			flag = false;
		}
		L.pop_front();
		i++;
		if (i == lenght && flag == true) {
			i++;
		}
	}
	return i;
}
void add_list(List& L, int pos, const Money element) {
	List::iterator it;
	it = L.begin();
	advance(it, pos - 1);
	L.insert(it, element);
}
void del_list(List& L, int pos) {
	List::iterator it;
	it = L.begin();
	advance(it, pos - 1);
	L.erase(it);
}
Money max_list(List L) {
	Money max = L.front();
	int lenght = L.size();
	for (int i = 0; i < lenght - 1; i++) {
		L.pop_front();
		if (L.front() > max) {
			max = L.front();
		}
	}
	return max;
}
Money min_list(List L) {
	Money min = L.front();
	int lenght = L.size();
	for (int i = 0; i < lenght - 1; i++) {
		L.pop_front();
		if (L.front() < min) {
			min = L.front();
		}
	}
	return min;
}
void decrease_list(List& L, Money value) {
	int lenght = L.size();
	List temp_L;
	for (int i = 0; i < lenght; i++) {
		Money res = L.front() - value;
		temp_L.push_back(res);
		L.pop_front();
	}
	L = temp_L;
}
void main() {
	system("chcp 1251");
	
		List list;
		List::iterator it_list = list.begin();
		int quantity;
		cout << "\nCоздание и заполнение списка\n\nКол-во элементов в списке > ";
		do {
			cin >> quantity;
			if (quantity < 1) {
				cout << "\nВведите положительное кол-во элемнетов > ";
			}
		} while (quantity < 1);
		list = make_list(quantity);
		print_list(list);
		Money key;
		cout << "\nДобавление существующего элемента списка\n\nИскомый элемент >\n"; cin >> key;
		int pos = find_element(list, key);
		try {
			if (pos == list.size() + 1) {
				cout << "\nЭлемент в списке не найден!\n";
			}
			else {
				cout << "\nЭлеменет в списке найден!\n\nПозиция нового элемента в списке > "; cin >> pos;
				if (pos > list.size()) {
					throw 1.0;
				}
				add_list(list, pos, key);
				print_list(list);
			}
		}
		catch (double) {
			cout << "\nОшибка индекса\n";
		}
		cout << "\nУдаление элементов из списка\n\nИскомый элемент >\n"; cin >> key;
		pos = find_element(list, key);
		if (pos == list.size() + 1) {
			cout << "\nЭлемент в списке не найден!\n";
		}
		else {
			cout << "\nЭлеменет в списке найден!\n";
			del_list(list, pos);
			print_list(list);
		}
		cout << "\nУменьшение всех элеменетов списка\n";
		Money max = max_list(list), min = min_list(list), res = max;
		res - min;
		cout << "\nMax элемент списка = " << max << "\nMin элемент списка = " << min << "\nРазность Max и Min = " << res << endl;
		decrease_list(list, res);
		print_list(list);
	system("pause");
}