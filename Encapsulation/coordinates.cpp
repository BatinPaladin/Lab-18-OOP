#include <iostream>
#include "coordinates.h"
using namespace std;
//���������� ������ ������������� ����� ���������
void coordinates::Init(double F, double S) {
	first = F;
	second = S;
}
//���������� ������ ��� ������ ��������� ����� ���������
void coordinates::Read() {
	cout << "\nx = "; cin >> first;
	cout << "y = "; cin >> second;
}
//���������� ������ ��� ������ �������� ����� ���������
void coordinates::Show() {
	cout << "\n����������: (" << first;
	cout << " ; " << second;
	cout << ")\n";
}
//���������� ������ ���������� ����������
double coordinates::distance() {
	return sqrt(pow(first, 2) + pow(second, 2));
}