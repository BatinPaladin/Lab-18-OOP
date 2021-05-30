#pragma once
#include <iostream>
#include "Money.h"
#include <fstream>
#include <string>
using namespace std;
int make_file(const char* file_name) {
	fstream stream(file_name, ios::out | ios::trunc);
	if (!stream) {
		return -1;
	}
	Money M;
	int quantity;
	cout << "\nВведите кол-во сумм:\n> "; cin >> quantity;;
	for (int i = 0; i < quantity; i++) {
		cout << "\n" << i + 1 << ")";
		cin >> M;
		stream << M << "\n";
	}
	stream.close();
	return quantity;
}
int print_file(const char* file_name) {
	fstream stream(file_name, ios::in);
	if (!stream) {
		return -1;
	}
	Money M;
	int quantity = 0;
	cout << "\n~~~~~~~~~~~~~~~~~\nСодержимое файла:\n~~~~~~~~~~~~~~~~~\n";
	while (stream >> M) {
		cout << "\n" << M << "\n";
		quantity++;
	}
	stream.close();
	return quantity;
}
int delete_range(const char* file_name) {
	fstream temp("temp", ios::out);
	fstream stream (file_name, ios::in);
	if (!stream) {
		return -1;
	}
	Money M, k1, k2;
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~\nВведите диапозон [k1, k2]\n~~~~~~~~~~~~~~~~~~~~~~~~~\n"; 
	cout << "\nk1?"; cin >> k1; cout << "\nk2?"; cin >> k2;
	if (k1 > k2) {
		M = k1;
		k1 = k2;
		k2 = M;
	}
	int quantity = 0;
	while (stream >> M) {
		if (stream.eof()) {
			break;
		}
		if (M < k1 || M > k2) {
			temp << M << "\n";
		}
		quantity++;
	}
	stream.close(); temp.close();
	remove(file_name);
	rename("temp", file_name);
	return quantity;
}
int add_begin(const char* file_name) {
	fstream temp("temp", ios::out | ios::app);
	fstream stream(file_name, ios::in);
	if (!stream) {
		return -1;
	}
	Money M;
	int K;
	cout << "\nВведите кол-во новых сумм:\n> "; cin >> K;
	for (int i = 0; i < K; i++) {
		cout << "\n" << i+1 << ")";
		cin >> M;
		temp << M << "\n";
	}
	while (stream >> M) {
		temp << M << "\n";
	}
	stream.close(); temp.close();
	remove(file_name);
	rename("temp", file_name);
	return K;
}
int change_file(const char* file_name) {
	fstream temp("temp", ios::out);
	fstream stream(file_name, ios::in);
	if (!stream) {
		return -1;
	}
	Money M, Const;
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nКакую запись в файле изменить?\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"; cin >> Const;
	long int rubles, x;
	int penny, quantity = 0;
	rubles = Const.get_rubles();
	penny = Const.get_penny();
	x = rubles * 100 + penny;
	while (stream >> M) {
		if (M == Const) {
			M + x;
			quantity++;
		}
		temp << M << "\n";
	}
	stream.close(); temp.close();
	remove(file_name);
	rename("temp", file_name);
	return quantity;
}