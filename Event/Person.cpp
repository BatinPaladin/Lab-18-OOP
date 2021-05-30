#include "Person.h"
Person::Person() {
	name = "";
	age = 0;
}
Person::Person(string temp_name, int temp_age) {
	name = temp_name;
	age = temp_age;
}
Person::Person(const Person& temp_Person) {
	name = temp_Person.name;
	age = temp_Person.age;
}
Person::~Person() { }
void Person::Show() {
	cout << "\nИмя - " << name;
	cout << "\nВозраст - " << age;
	cout << "\n";
}
void Person::Input() {
	cout << "\nИмя:\n> "; cin >> name;
	cout << "\nВозраст:\n> "; cin >> age;
}
string Person::get_name() {
	return name;
}
int Person::get_age() {
	return age;
}
void Person::set_name(string temp_name) {
	name = temp_name;
}
void Person::set_age(int temp_age) {
	age = temp_age;
}
Person& Person::operator=(const Person& temp_Person) {
	if (&temp_Person == this) {
		return *this;
	}
	name = temp_Person.name;
	age = temp_Person.age;
	return *this;
}
int Person::HandleEvent(const TEvent& event) {
	if (event.what == evMessage) {
		switch (event.command) {
		case cmGet:
			return get_age();
		}
	}
}
