#include <iostream>
#include <map>
#include "Money.h"
using namespace std;
typedef map<int, Money> TMap;
typedef TMap::iterator it;

TMap make_map(int quantity) {
	TMap map;
	for (int i = 0; i < quantity; i++) {
		Money el;
		cout << endl << i + 1 << ")\n"; cin >> el;
		map.insert(make_pair(i, el));
	}
	return map;
}

void print_map(TMap map) {
	cout << "\n�������:\n";	cout << endl;
	for (int i = 0; i < map.size(); i++) {
		cout << i + 1 << " : " << map[i] << " " << endl;
	}
}

int find_element(TMap map, Money key) {
	int i = 0;
	bool flag = true;
	while (i < map.size() && flag) {
		if (map[i] == key) {
			flag = false;
		}
		i++;
		if (i == map.size() && flag == true) {
			i++;
		}
	}
	return i;
}

void add_element(TMap& map, int pos, Money key) {
	TMap temp_map;
	for (int i = 0; i < pos; i++) {
		temp_map.insert(make_pair(i, map[i]));
	}
	temp_map.insert(make_pair(pos, key));
	for (int i = pos + 1; i < map.size() + 1; i++) {
		temp_map.insert(make_pair(i, map[i - 1]));
	}
	map.clear();
	map = temp_map;
	temp_map.clear();
}

void del_element(TMap& map, int pos) {
	TMap temp_map;
	int lenght = map.size();
	for (int i = 0; i < pos; i++) {
		temp_map.insert(make_pair(i, map[i]));
	}
	for (int i = pos + 1; i < lenght; i++) {
		temp_map.insert(make_pair(i - 1, map[i]));
	}
	map.clear();
	map = temp_map;
	temp_map.clear();
}

Money max_map(TMap map) {
	it id = map.begin();
	Money max = (*id).second;
	while (id != map.end()) {
		if (max < (*id).second) {
			max = (*id).second;
		}
		id++;
	}
	return max;
}

Money min_map(TMap map) {
	it id = map.begin();
	Money min = (*id).second;
	while (id != map.end()) {
		if (min > (*id).second) {
			min = (*id).second;
		}
		id++;
	}
	return min;
}

void decrease_map(TMap& map, Money value) {
	int lenght = map.size();
	TMap temp_map;
	for (int i = 0; i < lenght; i++) {
		Money res = map[i] - value;
		temp_map[i] = res;
	}
	map.clear();
	map = temp_map;
	temp_map.clear();
}

void main() {
	system("chcp 1251");
	int quantity;
	cout << "\nC������� � ���������� �������\n\n���-�� ��������� � ������� > ";
	do {
		cin >> quantity;
		if (quantity < 1) {
			cout << "\n������� ������������� ���-�� ��������� > ";
		}
	} while (quantity < 1);
	TMap map = make_map(quantity);
	print_map(map);
	Money key;
	cout << "\n���������� ������������� �������� �������\n\n������� ������� >\n"; cin >> key;
	int pos = find_element(map, key);
	try {
		if (pos == map.size() + 1) {
			cout << "\n������� � ������� �� ������!\n";
		}
		else {
			cout << "\n�������� � ������� ������!\n\n������� ������ �������� � ������� > "; cin >> pos;
			if (pos > map.size()) {
				throw 1.0;
			}
			add_element(map, pos - 1, key);
		}
	}
	catch (double) {
		cout << "\n������ �������\n";
	}
	print_map(map);
	cout << "\n�������� ��������� �� �������\n\n������� ������� >\n"; cin >> key;
	pos = find_element(map, key);
	if (pos == map.size() + 1) {
		cout << "\n������� � ������� �� ������!\n";
	}
	else {
		cout << "\n�������� � ������� ������!\n";
		del_element(map, pos - 1);
	}
	print_map(map);
	cout << "\n���������� ���� ���������� �������\n";
	Money max = max_map(map), min = min_map(map), res = max;
	res - min;
	cout << "\nMax ������� ������� = " << max << "\nMin ������� ������� = " << min << "\n�������� Max � Min = " << res << endl;
	decrease_map(map, res);
	print_map(map);
	system("pause");
}