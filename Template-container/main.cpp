#include <iostream>
#include "Set.h"
#include "Money.h"
using namespace std;
void main() {
	system("chcp 1251");
	cout << "INT";
	Set<int> A, B;
	cout << "\n���������� ��������� A\n"; cin >> A; cout << "\n��������� A " << A;
	B.Insert(12);
	B.Insert(4);
	B.Insert(10);
	B.Insert(0);
	cout << "\n��������� B " << B;
	system("pause");
	cout << "\n��������� ��������\n";
	if (A == B) {
		cout << "\n��������� �����!\n";
	}
	else {
		cout << "\n��������� �� �����!\n";
	}
	system("pause");
	int i_element;
	cout << "\n����� ����� �� ��������� A\n�����\n> "; cin >> i_element;
	if (A > i_element) {
		cout << "\n����� �� ��������� ����!\n";
	}
	else {
		cout << "\n����� �� ��������� ���!\n";
	}
	system("pause");
	int number, size=A.get_size();
	cout << "\n������ � �������� ��������� A\n\n����� ��������"; 
	do {
		cout << "\n> ";
		cin >> number;
		if (number > size) {
			cout << "\n������� ������ ������� ����� ���������\n";
		}
		if (number < 1) {
			cout << "\n������� ������������� ������\n";
		}
	} while (number > size || number < 1);
	cout << "\nA[" << number << "] = " << A[number - 1] << endl;
	system("pause");
	cout << "DOUBLE";
	Set<double> C, D;
	cout << "\n���������� ��������� C\n"; cin >> C; cout << "\n��������� C " << C;
	D.Insert(1.75);
	D.Insert(4.21);
	D.Insert(1.405);
	D.Insert(0.0);
	cout << "\n��������� D " << D;
	system("pause");
	cout << "\n��������� ��������\n";
	if (C == D) {
		cout << "\n��������� �����!\n";
	}
	else {
		cout << "\n��������� �� �����!\n";
	}
	system("pause");
	double d_element;
	cout << "\n����� ����� �� ��������� C\n�����\n> "; cin >> d_element;
	if (C > d_element) {
		cout << "\n����� �� ��������� ����!\n";
	}
	else {
		cout << "\n����� �� ��������� ���!\n";
	}
	system("pause");
	size = C.get_size();
	cout << "\n������ � �������� ��������� C\n\n����� ��������"; 
	do {
		cout << "\n> ";
		cin >> number;
		if (number > size) {
			cout << "\n������� ������ ������� ����� ���������\n";
		}
		if (number < 1) {
			cout << "\n������� ������������� ������\n";
		}
	} while (number > size || number < 1);
	cout << "\nC[" << number << "] = " << C[number - 1] << endl;
	system("pause");
	cout << "CHAR";
	Set<char> E, F;
	cout << "\n���������� ��������� E\n"; cin >> E; cout << "\n��������� E " << E;
	F.Insert('f');
	F.Insert('1');
	F.Insert('/');
	F.Insert('0');
	cout << "\n��������� F " << F;
	system("pause");
	cout << "\n��������� ��������\n";
	if (E == F) {
		cout << "\n��������� �����!\n";
	}
	else {
		cout << "\n��������� �� �����!\n";
	}
	system("pause");
	char c_element;
	cout << "\n����� ������ �� ��������� E\n������\n> "; cin >> c_element;
	if (E > c_element) {
		cout << "\n������ �� ��������� ����!\n";
	}
	else {
		cout << "\n������� �� ��������� ���!\n";
	}
	system("pause");
	size = E.get_size();
	cout << "\n������ � �������� ��������� E\n\n����� ��������";
	do {
		cout << "\n> ";
		cin >> number;
		if (number > size) {
			cout << "\n������� ������ ������� ����� ���������\n";
		}
		if (number < 1) {
			cout << "\n������� ������������� ������\n";
		}
	} while (number > size || number < 1);
	cout << "\nE[" << number << "] = " << E[number - 1] << endl;
	system("pause");
	cout << "MONEY\n���������� ������ � ���������������� �����";
	Money g;
	cout << "\n����� \n"; cin >> g; cout << "\n�����: " << g << endl;
	system("pause");
	int x;
	cout << "\n������� ������ ���������\n>"; cin >> x;
	g + x;
	cout << "\n����� 1: " << g << endl;
	system("pause");
	Set<Money> G, H;
	cout << "\n���������� ��������� G\n"; cin >> G; cout << "\n��������� G " << G;
	cout << "\n���������� ��������� H\n"; cin >> H; cout << "\n��������� H " << H;
	system("pause");
	cout << "\n��������� ��������\n";
	if (G == H) {
		cout << "\n��������� �����!\n";
	}
	else {
		cout << "\n��������� �� �����!\n";
	}
	system("pause");
	Money m_element;
	cout << "\n����� ����� �� ��������� G\n�����\n> "; cin >> m_element;
	if (G > m_element) {
		cout << "\n����� �� ��������� ����!\n";
	}
	else {
		cout << "\n����� �� ��������� ���!\n";
	}
	system("pause");
	size = G.get_size();
	cout << "\n������ � �������� ��������� G\n\n����� ��������";
	do {
		cout << "\n> ";
		cin >> number;
		if (number > size) {
			cout << "\n������� ������ ������� ����� ���������\n";
		}
		if (number < 1) {
			cout << "\n������� ������������� ������\n";
		}
	} while (number > size || number < 1);
	cout << "\nG[" << number << "] = " << G[number - 1] << endl;
	system("pause");
}