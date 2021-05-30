#include <iostream>
#include "Money.h"
#include "file_work.h"
#include <fstream>
#include <string>
using namespace std;
void main() {
	system("chcp 1251");
	int op, quantity;
	char file_name[30];
	do {
		cout << "\n===========================\n1 - Создать файл\n2 - Прочитать файл\n3 - Удалить записи из файла\n4 - Добаить записи в файл\n5 - Изменить запись в файле\n0 - Выход\n===========================\n\nВаша выбор > ";
		cin >> op;
		switch (op) {
		case 1:
			cout << "\nИмя файла > "; cin >> file_name;
			quantity = make_file(file_name);
			if (quantity < 0) {
				cout << "\nНевозможно создать файл!\n";
			}
			break;
		case 2:
			cout << "\nИмя файла > "; cin >> file_name;
			quantity = print_file(file_name);
			if (quantity == 0) {
				cout << "\nФайл пуст!\n";
			}
			if (quantity < 0) {
				cout << "\nНевозможно прочесть файл!\n";
			}
			break;
		case 3:
			cout << "\nИмя файла > "; cin >> file_name;
			quantity = delete_range(file_name);
			if (quantity < 0) {
				cout << "\nНевозможно прочесть файл!\n";
			}
			break;
		case 4:
			cout << "\nИмя файла > "; cin >> file_name;
			quantity = add_begin(file_name);
			if (quantity < 0) {
				cout << "\nНевозможно прочесть файл!\n";
			}
			break;
		case 5:
			cout << "\nИмя файла > "; cin >> file_name;
			quantity = change_file(file_name);
			if (quantity < 0) {
				cout << "\nНевозможно прочесть файл!\n";
			}
			if (quantity == 0) {
				cout << "\nЗапись в файле не найдена!\n";
			}
			if (quantity > 0) {
				cout << "\nКол-во измененых записей = " << quantity << endl;
			}
			break;
		}
	} while (op != 0);
	system("pause");
}