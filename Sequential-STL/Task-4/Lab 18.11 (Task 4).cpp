#include <C:\Users\apicd\OneDrive\Рабочий стол\Labs\Lab 18 (Class)\Lab 18.11 (Sequential STL)\Lab 18.11 (Task 2)\Money.cpp>
#include <iostream>
#include <queue>
using namespace std;
typedef priority_queue<Money, vector<Money>> Pque;
typedef vector<Money> Vec;
Pque make_pque(int quantity) {
	Pque p;
	Money m;
	for (int i = 0; i < quantity; i++) {
		cout << i + 1 << ")\n";
		cin >> m;
		p.push(m);
	}
	return p;
}
void print_pque(Pque p) {
	cout << "\nОчередь с приоритетом:\n";
	while (!p.empty()) {
		cout << p.top() << " ";
		p.pop();
	}
	cout << endl;
}
int find_element(Pque p, const Money element) {
	int lenght = p.size(), i = 0;
	bool flag = true;
	while (!p.empty() && flag) {
		if (p.top() == element) {
			flag = false;
		}
		p.pop();
		i++;
		if (i == lenght && flag == true) {
			i++;
		}
	}
	return i;
}
void delete_pque(Pque& p, int pos) {
	Vec vec;
	int i = 0;
	while (!p.empty()) {
		if (i == pos) {
			p.pop();
		}
		else {
			vec.push_back(p.top());
			p.pop();
		}
		i++;
	}
	for (i = 0; i < vec.size(); i++) {
		p.push(vec[i]);
	}
}
Money min_pque(Pque p) {
	int lenght = p.size();
	for (int i = 0; i < lenght - 1; i++) {
		p.pop();
	}
	return p.top();
}
void decrease_pque(Pque& p, Money value) {
	Vec vec;
	while (!p.empty()) {
		Money res = p.top();
		res - value;
		p.pop();
		vec.push_back(res);
	}
	for (int i = 0; i < vec.size(); i++) {
		p.push(vec[i]);
	}
}
void main() {
	system("chcp 1251"); 
	int quantity;
	cout << "\nCоздание и заполнение очереди\n\nКол-во элементов в очереди > "; cin >> quantity;
	Pque p;
	p = make_pque(quantity);
	print_pque(p);
	system("pause");
	Money key;
	cout << "\nДобавление существующего элемента очереди\n\nИскомый элемент >\n"; cin >> key;
	int pos = find_element(p, key);
	if (pos == p.size() + 1) {
		cout << "\nЭлемент в списке не найден!\n";
	}
	else {
		cout << "\nЭлеменет в списке найден!\n";
		p.push(key);
		print_pque(p);
	}
	system("pause"); 
	cout << "\nУдаление элементов из списка\n\nИскомый элемент >\n"; cin >> key;
	pos = find_element(p, key);
	if (pos == p.size() + 1) {
		cout << "\nЭлемент в списке не найден!\n";
	}
	else {
		cout << "\nЭлеменет в списке найден!\n";
		delete_pque(p, pos - 1);
		print_pque(p);
	}
	system("pause");
	cout << "\nУменьшение всех элеменетов списка\n";
	Money max = p.top(), min = min_pque(p), res = max;
	res - min;
	cout << "\nMax элемент списка = " << max << "\nMin элемент списка = " << min << "\nРазность Max и Min = " << res << endl;
	decrease_pque(p, res);
	print_pque(p);
	system("pause");
}