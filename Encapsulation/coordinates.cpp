#include <iostream>
#include "coordinates.h"
using namespace std;
//Реализация метода инициализации полей структуры
void coordinates::Init(double F, double S) {
	first = F;
	second = S;
}
//Реализация метода для чтения значнений полей структуры
void coordinates::Read() {
	cout << "\nx = "; cin >> first;
	cout << "y = "; cin >> second;
}
//Реализация метода для вывода значений полей структуры
void coordinates::Show() {
	cout << "\nКоординаты: (" << first;
	cout << " ; " << second;
	cout << ")\n";
}
//Реализация метода нахождения расстояния
double coordinates::distance() {
	return sqrt(pow(first, 2) + pow(second, 2));
}