#include <iostream>
#include "Set.h"
using namespace std;
void main() {
	system("chcp 1251");
	Set a, b;
	int number, size_a;
	cout << "\nЗаполнение множества a\n"; cin >> a; cout << "\nМножество a " << a;
	b.Insert(12);
	b.Insert(4);
	b.Insert(10);
	b.Insert(0);
	system("pause");
	cout << "\nЭлемент\n> "; cin >> number;
	a.Insert(number);
	cout << "\nЭлемент " << number << " добавлен во множество a\n";
	system("pause");
	cout << "\nСравнение множеств\n\nМножество a " << a << "\nМножество b " << b;
	if (a == b) {
		cout << "\nМножества равны!\n";
	}
	else {
		cout << "\nМножества не равны!\n";
	}
	system("pause");
	cout << "\nПоиск числа во множестве a\nЧисло\n> "; cin >> number;
	if (a > number) {
		cout << "\nЧисло во множестве есть!\n";
	}
	else {
		cout << "\nЧисла во множестве нет!\n";
	}
	system("pause");
	int size = a.get_size();
	cout << "\nДоступ к элементу множества a\n\nНомер элемента"; 
	do {
		cout << "\n> ";
		cin >> number;
		if (number > size) {
			cout << "\nВведите индекс меньший длины множества\n";
		}
		if (number < 1) {
			cout << "\nВведите положительный индекс\n";
		}
	} while (number > size || number < 1);
	cout << "\na[" << number << "] = " << a[number-1] << endl;
	system("pause");
	cout << "\nМножество a\n\nПервый элемент множества - " << *(a.first()) << "\nПоследний элемент множества - " << *(a.last()) << endl;
	Iterator it = a.last();
	size_a = a.get_size();
	cout << "\nИтератор = " << *(it);
	cout << "\nДлина множества а = " << size_a << "\n\nНа сколько элементов сдвинуть итератор?\n";
	do {
		cout << "\nЧисло\n> "; cin >> number;
		if (number >= size_a) {
			cout << "\nВведите число меньше длины множества\n";
		}
		if (number < 0) {
			cout << "\nВведите положительное число\n";
		}
	} while (number >= size_a || number < 0);
	it - number;
	cout << "\nИтератор = " << *(it) << endl;
	system("pause");
}