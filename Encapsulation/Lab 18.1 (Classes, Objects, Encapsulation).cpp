#include <iostream>
#include "coordinates.h"
using namespace std;
coordinates make_coordinates(double F, double S) {
	coordinates temp;
	temp.Init(F,S);
	return temp;
}
void main() {
	system("chcp 1251");
	//����� main
	coordinates A;
	coordinates B;
	cout << "\n����� �\nx = 4.5\ny = 3.6";
	A.Init(4.5, 3.6);
	cout << "\n\n����� �";
	A.Show();
	cout << "\n���������� �� ������ ��������� �� ����� � = " << A.distance() << endl;
	cout << "\n����� B";
	B.Read();
	cout << "\n����� B";
	B.Show();
	cout << "\n���������� �� ������ ��������� �� ����� B = " << B.distance() << endl;
	//���������
	coordinates* X = new coordinates;
	cout << "\n����� X\nx = 2.4\ny = 0.5";
	X->Init(2.4, 0.5);
	cout << "\n\n����� X";
	X->Show();
	cout << "\n���������� �� ������ ��������� �� ����� X = " << X->distance();
	delete X;
	//������
	coordinates mas[3];
	for (int i = 0; i < 3; i++) {
		cout << "\n\n����� C" << i + 1;
		mas[i].Read();
		cout << "\n����� C" << i + 1;
		mas[i].Show();
		cout << "\n���������� �� ������ ��������� �� ����� C" << i+1 << " = " << mas[i].distance();
	}
	//������������ ������
	coordinates* p_mas = new coordinates[3];
	for (int i = 0; i < 3; i++) {
		cout << "\n\n����� D" << i + 1;
		p_mas[i].Read();
		cout << "\n����� D" << i + 1;
		p_mas[i].Show();
		cout << "\n���������� �� ������ ��������� �� ����� D" << i + 1 << " = " << p_mas[i].distance();
	}
	delete[] p_mas;
	//����� ������� make_coordinates
	double x, y;
	cout << "\n\n����� F";
	cout << "\nx = "; cin >> x;
	cout << "y = "; cin >> y;
	coordinates F = make_coordinates(x, y);
	cout << "\n����� F";
	F.Show();
	cout << "\n���������� �� ������ ��������� �� ����� F = " << F.distance() << endl;
	system("pause");
}