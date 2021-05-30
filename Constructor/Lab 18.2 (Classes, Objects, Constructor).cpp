#include <iostream>
#include <string>
#include "flat.h"
using namespace std;
Flat make_flat() {
	string s;
	cout << "\n������� ������ ��������: "; getline(cin,s);
	double d;
	cout << "\n������� ������� ��������: "; cin >> d;
	int i;
	cout << "\n����� ���-�� ������ � ��������: "; cin >> i;
	Flat temp(s, d, i);
	return temp;
}
void print_flat(Flat temp) {
	temp.show();
}
void main() {
	system("chcp 1251");
	//����������� ��� ����������
	cout << "\n1.\n";
	Flat apartment1;
	apartment1.show();
	//����������� � �����������
	cout << "\n2.\n";
	Flat apartment2 = {"������ 48", 20.0, 3};
	apartment2.show();
	//����������� �����������
	cout << "\n3.\n";
	Flat apartment3 = apartment2;
	apartment3.set_adress("������������� 28�");
	apartment3.set_square(14.23);
	apartment3.set_rooms(1);
	print_flat(apartment3);
	//����� ������� make_flat
	cout << "\n4.\n";
	apartment1 = make_flat();
	apartment1.show();
	//����� ���������
	cout << "\n5.\n";
	string s = apartment2.get_adress();
	double d = apartment2.get_square();
	int i = apartment2.get_rooms();
	cout << "\n��������\n\n������: " << s << endl;
	cout << "\n�������: " << d << endl;
	cout << "\n���-�� ������: " << i << endl;
	system("pause");
}