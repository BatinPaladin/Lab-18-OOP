#include <iostream>
#include "Set.h"
#include "Money.h"
using namespace std;
void main() {
	system("chcp 1251");
	cout << "INT";
	Set<int> A, B;
	cout << "\nЗаполнение множества A\n"; cin >> A; cout << "\nМножество A " << A;
	B.Insert(12);
	B.Insert(4);
	B.Insert(10);
	B.Insert(0);
	cout << "\nМножество B " << B;
	system("pause");
	cout << "\nСравнение множеств\n";
	if (A == B) {
		cout << "\nМножества равны!\n";
	}
	else {
		cout << "\nМножества не равны!\n";
	}
	system("pause");
	int i_element;
	cout << "\nПоиск числа во множестве A\nЧисло\n> "; cin >> i_element;
	if (A > i_element) {
		cout << "\nЧисло во множестве есть!\n";
	}
	else {
		cout << "\nЧисла во множестве нет!\n";
	}
	system("pause");
	int number, size=A.get_size();
	cout << "\nДоступ к элементу множества A\n\nНомер элемента"; 
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
	cout << "\nA[" << number << "] = " << A[number - 1] << endl;
	system("pause");
	cout << "DOUBLE";
	Set<double> C, D;
	cout << "\nЗаполнение множества C\n"; cin >> C; cout << "\nМножество C " << C;
	D.Insert(1.75);
	D.Insert(4.21);
	D.Insert(1.405);
	D.Insert(0.0);
	cout << "\nМножество D " << D;
	system("pause");
	cout << "\nСравнение множеств\n";
	if (C == D) {
		cout << "\nМножества равны!\n";
	}
	else {
		cout << "\nМножества не равны!\n";
	}
	system("pause");
	double d_element;
	cout << "\nПоиск числа во множестве C\nЧисло\n> "; cin >> d_element;
	if (C > d_element) {
		cout << "\nЧисло во множестве есть!\n";
	}
	else {
		cout << "\nЧисла во множестве нет!\n";
	}
	system("pause");
	size = C.get_size();
	cout << "\nДоступ к элементу множества C\n\nНомер элемента"; 
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
	cout << "\nC[" << number << "] = " << C[number - 1] << endl;
	system("pause");
	cout << "CHAR";
	Set<char> E, F;
	cout << "\nЗаполнение множества E\n"; cin >> E; cout << "\nМножество E " << E;
	F.Insert('f');
	F.Insert('1');
	F.Insert('/');
	F.Insert('0');
	cout << "\nМножество F " << F;
	system("pause");
	cout << "\nСравнение множеств\n";
	if (E == F) {
		cout << "\nМножества равны!\n";
	}
	else {
		cout << "\nМножества не равны!\n";
	}
	system("pause");
	char c_element;
	cout << "\nПоиск символ во множестве E\nСимвол\n> "; cin >> c_element;
	if (E > c_element) {
		cout << "\nСимвол во множестве есть!\n";
	}
	else {
		cout << "\nСимвола во множестве нет!\n";
	}
	system("pause");
	size = E.get_size();
	cout << "\nДоступ к элементу множества E\n\nНомер элемента";
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
	cout << "\nE[" << number << "] = " << E[number - 1] << endl;
	system("pause");
	cout << "MONEY\nПростейшие методы с пользовательским типом";
	Money g;
	cout << "\nСумма \n"; cin >> g; cout << "\nСумма: " << g << endl;
	system("pause");
	int x;
	cout << "\nСколько копеек прибавить\n>"; cin >> x;
	g + x;
	cout << "\nСумма 1: " << g << endl;
	system("pause");
	Set<Money> G, H;
	cout << "\nЗаполнение множества G\n"; cin >> G; cout << "\nМножество G " << G;
	cout << "\nЗаполнение множества H\n"; cin >> H; cout << "\nМножество H " << H;
	system("pause");
	cout << "\nСравнение множеств\n";
	if (G == H) {
		cout << "\nМножества равны!\n";
	}
	else {
		cout << "\nМножества не равны!\n";
	}
	system("pause");
	Money m_element;
	cout << "\nПоиск суммы во множестве G\nСумма\n> "; cin >> m_element;
	if (G > m_element) {
		cout << "\nСумма во множестве есть!\n";
	}
	else {
		cout << "\nСуммы во множестве нет!\n";
	}
	system("pause");
	size = G.get_size();
	cout << "\nДоступ к элементу множества G\n\nНомер элемента";
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
	cout << "\nG[" << number << "] = " << G[number - 1] << endl;
	system("pause");
}