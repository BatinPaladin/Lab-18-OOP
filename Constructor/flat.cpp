#include <iostream>
#include <string>
#include "flat.h"
using namespace std;
Flat::Flat() {
	adress = " ";
	square = 0.0;
	rooms = 0;
	cout << "\n����������� ��� ���������� ��� ������� " << this << endl;
}
Flat::Flat(string A, double S, int R) {
	adress = A;
	square = S;
	rooms = R;
	cout << "\n����������� � ����������� ��� ������� " << this << endl;
}
Flat::Flat(const Flat &temp) {
	adress = temp.adress;
	square = temp.square;
	rooms = temp.rooms;
	cout << "\n����������� ����������� ��� ������� " << this << endl;
}
Flat::~Flat() {
	cout << "\n���������� " << this << endl;
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
	cout << "\n��������\n\n������: " << adress << endl;
	cout << "\n�������: " << square << endl;
	cout << "\n���-�� ������: " << rooms << endl;
}