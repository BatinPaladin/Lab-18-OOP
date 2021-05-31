#include <iostream>
#include <map>
using namespace std;
typedef map<int, double> TMap;
typedef TMap::iterator it;

TMap make_map(int quantity) {
	TMap map;
	cout << endl;
	for (int i = 0; i < quantity; i++) {
		double el;
		cout << i + 1 << ") "; cin >> el;
		map.insert(make_pair(i, el));
	}
	return map;
}

void print_map(TMap map) {
	cout << "\nСловарь:\n";
	for (int i = 0; i < map.size(); i++) {
		cout << i + 1 << " : " << map[i] << " " << endl;
	}
	cout << endl;
}

int find_element(TMap map, double key) {
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

void add_element(TMap& map, int pos, double key) {
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
		temp_map.insert(make_pair(i-1, map[i]));
	}
	map.clear();
	map = temp_map;
	temp_map.clear();
}

double max_map(TMap map) {
	double max = map[0];
	int lenght = map.size();
	for (int i = 1; i < lenght; i++) {
		if (map[i] > max) {
			max = map[i];
		}
	}
	return max;
}

double min_map(TMap map) {
	double min = map[0];
	int lenght = map.size();
	for (int i = 1; i < lenght; i++) {
		if (map[i] < min) {
			min = map[i];
		}
	}
	return min;
}

void decrease_map(TMap& map, double value) {
	int lenght = map.size();
	TMap temp_map;
	for (int i = 0; i < lenght; i++) {
		double res = map[i] - value;
		temp_map[i] = res;
	}
	map.clear();
	map = temp_map;
	temp_map.clear();
}

void main() {
	system("chcp 1251");
	int quantity;
	cout << "\nCоздание и заполнение словаря\n\nКол-во элементов в словаре > ";
	do {
		cin >> quantity;
		if (quantity < 1) {
			cout << "\nВведите положительное кол-во элемнетов > ";
		}
	} while (quantity < 1);
	TMap map = make_map(quantity);
	print_map(map);
	double key;
	cout << "\nДобавление существующего элемента словаря\n\nИскомый элемент > "; cin >> key;
	int pos = find_element(map, key);
	try {
		if (pos == map.size() + 1) {
			cout << "\nЭлемент в словаре не найден!\n";
		}
		else {
			cout << "\nЭлеменет в словаре найден!\n\nПозиция нового элемента в словаре > "; cin >> pos;
			if (pos > map.size()) {
				throw 1.0;
			}
			add_element(map, pos - 1, key);
		}
	}
	catch (double) {
		cout << "\nОшибка индекса\n";
	}
	print_map(map);
	cout << "\nУдаление элементов из словаря\n\nИскомый элемент > "; cin >> key;
	pos = find_element(map, key);
	if (pos == map.size() + 1) {
		cout << "\nЭлемент в словаре не найден!\n";
	}
	else {
		cout << "\nЭлеменет в словаре найден!\n";
		del_element(map, pos - 1);
	}
	print_map(map);
	cout << "\nУменьшение всех элеменетов словаря\n";
	double max = max_map(map), min = min_map(map), res = max - min;
	cout << "\nMax элемент словаря = " << max << "\nMin элемент словаря = " << min << "\nРазность Max и Min = " << res << endl; 
	decrease_map(map, res);
	print_map(map);
	system("pause");
}