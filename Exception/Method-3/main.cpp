#include <iostream>
#include "Set.h"
#include "Error.h"
using namespace std;
int main() {
	system("chcp 1251");
	Set A, B;
	try {
		cout << "\nЗаполнение множеста A:\n"; cin >> A;
	}
	catch (Error &e) {
		e.what();
	}
	try {
		cout << "\nЗаполнение множеста B:\n"; cin >> B;
	}
	catch (Error &e) {
		e.what();
	}
	cout << "\nСодержимое множества A: " << A;
	cout << "\nСодержимое множества B: " << B;
	if (A == B) {
		cout << "\nМножества равны\n";
	}
	else {
		cout << "\nМножества не равны\n";
	}
	int value;
	try {
		cout << "\nПроверка оператора '[]' на множестве А\nВведите индекс:\n> "; cin >> value; cout << A[value - 1] << endl;
	}
	catch (Error &e) {
		e.what();
	}
	cout << "\nПроверка оператора '>' на множестве А\nВведите элемент:\n> "; cin >> value;
	if (A > value) {
		cout << "\nЭлемент " << value << " во множестве есть!\n";
	}
	else {
		cout << "\nЭлемента " << value << " во множестве нет!\n";
	}
	try {
		int size; size = A.get_size();
		cout << "\nПроверка оператора '-' на множестве А\nВведите сдвиг:\n> "; cin >> value; 
		cout << A[size - 1] << endl << A - value << endl;
	}
	catch (Error &e) {
		e.what();
	}
	system("pause");
	return 0;
}