#pragma once
struct coordinates {
	double first;
	double second;
	void Init(double, double); //����� ������������� �����
	void Read(); //����� ������ �������� �����
	void Show(); //����� ������ �������� �����
	double distance(); //����� ���������� ����������
};
