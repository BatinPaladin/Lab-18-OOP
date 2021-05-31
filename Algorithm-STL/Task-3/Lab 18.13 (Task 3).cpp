#include <C:\Users\apicd\OneDrive\������� ����\Labs\Lab 18 (Class)\Lab 18.12 (Associative STL)\Lab 18.12 (Task 2)\Money.cpp>
#include <iostream>
#include <map>
using namespace std;
typedef multimap<int, Money> TMap;
TMap::iterator it;
Money res;

TMap make_map(int quantity) {
	TMap map;
	for (int i = 0; i < quantity; i++) {
		Money el;
		cout << endl << i + 1 << ")\n"; cin >> el;
		map.emplace(i+1, el);
	}
	return map;
}

void print_map(TMap map) {
	cout << "\n�������:\n";	cout << endl;
	it = map.begin();
	while(it != map.end()) {
		cout << it->first << " : " << it->second << " " << endl;
		it++;
	}
}

void add_map(TMap& map, const Money element) {
	bool flag = true;
	it = map.begin();
	if (it->second == element) {
		flag = false;
	}
	while (flag) {
		it++;
		if (it->second == element) {
			flag = false;
		}
	}
	if (it != map.end()) {
		int pos;
		cout << "\n�������� � ������� ������!\n\n������� ������ �������� � ������� > "; cin >> pos;
		try {
			if (pos > map.size()) {
				throw 1.0;
			}
			else {
				TMap temp_map;
				it = map.begin();
				for (int i = 0; i < pos - 1; i++) {
					temp_map.emplace(i+1, it->second);
					it++;
				}
				temp_map.emplace(pos - 1, element);
				for (int i = pos; i < map.size() + 1; i++) {
					temp_map.emplace(i+1, it->second);
					it++;
				}
				map.clear();
				map = temp_map;
				temp_map.clear();
			}
		}
		catch (double) {
			cout << "\n������ �������\n";
		}
		print_map(map);
	}
	else {
		cout << "\n������� � ������ �� ������!\n";
	}
}

void del_map(TMap& map, const Money element) {
	bool flag = true;
	it = map.begin();
	if (it->second == element) {
		flag = false;
	}
	while (flag) {
		it++;
		if (it->second == element) {
			flag = false;
		}
	}
	if (it != map.end()) {
		map.erase(it);
		print_map(map);
	}
	else {
		cout << "\n������� � ������ �� ������!\n";
	}
}

Money max_map(TMap map) {
	it = map.begin();
	Money max = (*it).second;
	while (it != map.end()) {
		if (max < (*it).second) {
			max = (*it).second;
		}
		it++;
	}
	return max;
}

Money min_map(TMap map) {
	it = map.begin();
	Money min = (*it).second;
	while (it != map.end()) {
		if (min > (*it).second) {
			min = (*it).second;
		}
		it++;
	}
	return min;
}

void decrease_map(TMap& map) {
	it = map.begin();
	while (it != map.end()) {
		(*it).second - res;
		it++;
	}
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
	TMap map;
	map = make_map(quantity);
	print_map(map);
	Money key;
	cout << "\n���������� ������������� �������� ������\n\n������� ������� >\n"; cin >> key;
	add_map(map, key);
	cout << "\n�������� ��������� �� ������\n\n������� ������� >\n"; cin >> key;
	del_map(map, key);
	cout << "\n���������� ���� ���������� ������\n";
	Money max = max_map(map), min = min_map(map);
	res = max;
	res - min;
	cout << "\nMax ������� ������ = " << max << "\nMin ������� ������ = " << min << "\n�������� Max � Min = " << res << endl;
	decrease_map(map);
	print_map(map);
	system("pause");
}