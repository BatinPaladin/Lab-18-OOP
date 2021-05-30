#include <iostream>
#include <string>
#include "flat.h"
using namespace std;
Flat::Flat() {
	adress = " ";
	square = 0.0;
	rooms = 0;
	cout << "\nКонструктор без параметров для обьекта " << this << endl;
}
Flat::Flat(string A, double S, int R) {
	adress = A;
	square = S;
	rooms = R;
	cout << "\nКонструктор с параметрами для обьекта " << this << endl;
}
Flat::Flat(const Flat &temp) {
	adress = temp.adress;
	square = temp.square;
	rooms = temp.rooms;
	cout << "\nКонструктор копирования для обьекта " << this << endl;
}
Flat::~Flat() {
	cout << "\nДеструктор " << this << endl;
}
string Flat::get_adress() {
	return adress;
}
double Flat::get_square() {
	return square;
}
int Flat::get_rooms() {
	return rooms;
}
void Flat::set_adress(string A) {
	adress = A;
}
void Flat::set_square(double S) {
	square = S;
}
void Flat::set_rooms(int R) {
	rooms = R;
}
void Flat::show() {
	cout << "\nКвартира\n\nАдресс: " << adress << endl;
	cout << "\nПлощадь: " << square << endl;
	cout << "\nКол-во комнат: " << rooms << endl;
}