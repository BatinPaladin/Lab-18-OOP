#pragma once
#include <iostream>
#include <string>
using namespace std;
class Flat {
	string adress;
	double square;
	int rooms;
public:
	Flat();//������������ ��� ����������
	Flat(string, double, int);//����������� � �����������
	Flat(const Flat&);//����������� �����������
	~Flat();//����������
	string get_adress();//��������
	void set_adress(string);//�����������
	double get_square();//��������
	void set_square(double);//�����������
	int get_rooms();//��������
	void set_rooms(int);//�����������
	void show();//�������� ���������
};