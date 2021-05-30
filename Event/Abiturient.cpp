#include "Abiturient.h"
Abiturient::Abiturient() :Person() {
	points = 0;
	special = "";
}
Abiturient::Abiturient(string temp_name, int temp_age, int temp_points, string temp_special) :Person(temp_name, temp_age) {
	points = temp_points;
	special = temp_special;
}
Abiturient::Abiturient(const Abiturient& temp_Abiturient) {
	name = temp_Abiturient.name;
	age = temp_Abiturient.age;
	points = temp_Abiturient.points;
    special = temp_Abiturient.special;
}
Abiturient::~Abiturient() { }
void Abiturient::Show() {
	cout << "\n��� - " << name;
	cout << "\n������� - " << age;
	cout << "\n���-�� ������ - " << points;
	cout << "\n������������� - " << special;
	cout << "\n";
}
void Abiturient::Input() {
	cout << "\n���:\n> "; cin >> name;
	cout << "\n�������:\n> "; cin >> age;
	cout << "\n���-�� ������:\n> "; cin >> points;
	cout << "\n�������������:\n> "; cin >> special;
}
int Abiturient::get_points() {
	return points;
}
string Abiturient::get_special() {
	return special;
}
void Abiturient::set_points(int temp_points) {
	points = temp_points;
}
void Abiturient::set_special(string temp_special) {
	special = temp_special;
}
Abiturient& Abiturient::operator=(const Abiturient& temp_Abiturient) {
	if (&temp_Abiturient == this) {
		return *this;
	}
	name = temp_Abiturient.name;
	age = temp_Abiturient.age;
	points = temp_Abiturient.points;
	special = temp_Abiturient.special;
	return *this;
}
