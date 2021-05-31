#include <list>
#include <iostream>
using namespace std;
typedef list<double> List;
List make_list(int quantity) {
	List L;
	for (int i = 0; i < quantity; i++) {
		double number;
		cout << i + 1 << ") "; cin >> number;
		L.push_back(number);
	}
	return L;
}
void print_list(List L) {
	int lenght = L.size();
	cout << "\n������:\n";
	for (int i = 0; i < lenght; i++) {
		cout << L.front() << " ";
		L.pop_front();
	}
	cout << endl;
}
int find_element(List L, double element) {
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
void add_list(List& L, int pos, double element) {
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
double max_list(List L) {
	double max = L.front();
	int lenght = L.size();
	for (int i = 0; i < lenght - 1; i++) {
		L.pop_front();
		if (L.front() > max) {
			max = L.front();
		}
	}
	return max;
}
double min_list(List L) {
	double min = L.front();
	int lenght = L.size();
	for (int i = 0; i < lenght - 1; i++) {
		L.pop_front();
		if (L.front() < min) {
			min = L.front();
		}
	}
	return min;
}
void decrease_list(List& L, double value) {
	int lenght = L.size();
	List temp_L;
	for (int i = 0; i < lenght; i++) {
		double res = L.front() - value;
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
		cout << "\nC������� � ���������� ������\n\n���-�� ��������� � ������ > "; 
		do { 
			cin >> quantity; 
			if (quantity < 1) {
				cout << "\n������� ������������� ���-�� ��������� > ";
			}
		} while (quantity < 1);
		list = make_list(quantity);
		print_list(list);
		double key;
		cout << "\n���������� ������������� �������� ������\n\n������� ������� > "; cin >> key;
		int pos = find_element(list, key);
	try{
		if (pos == list.size() + 1) {
			cout << "\n������� � ������ �� ������!\n";
		}
		else {
			cout << "\n�������� � ������ ������!\n\n������� ������ �������� � ������ > "; cin >> pos;
			if (pos > list.size()) {
				throw 1.0;
			}
			add_list(list, pos, key);
		}
	}
	catch (double) {
		cout << "\n������ �������\n";
	}
	print_list(list);
	cout << "\n�������� ��������� �� ������\n\n������� ������� > "; cin >> key;
		pos = find_element(list, key);
		if (pos == list.size() + 1) {
			cout << "\n������� � ������ �� ������!\n";
		}
		else {
			cout << "\n�������� � ������ ������!\n";
			del_list(list, pos);
		}
		print_list(list);
		cout << "\n���������� ���� ���������� ������\n";
		double max = max_list(list), min = min_list(list), res = max - min;
		cout << "\nMax ������� ������ = " << max << "\nMin ������� ������ = " << min << "\n�������� Max � Min = " << res << endl;
		decrease_list(list, res);
		print_list(list);
	system("pause");
}