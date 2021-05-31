#pragma once
#include <C:\Users\apicd\OneDrive\Рабочий стол\Labs\Lab 18 (Class)\Lab 18.12 (Associative STL)\Lab 18.12 (Task 2)\Money.cpp>
#include <iostream>
#include <map>
using namespace std;
template <class T>
class Container {
private:
	map<int, T> m;
	int lenght;
public:
	Container();
	Container(int n);
	int Find(T value);
	int Size();
	void Add(T value, int pos);
	void Dell(int pos);
	void Print();
	T Min();
	T Max();
	void Decrease(T value);
	~Container();
};
template <class T>
Container<T>::Container(){
	lenght = 0;
}
template <class T>
Container<T>::~Container() { }
template <class T>
Container<T>::Container(int quantity) {
	T el;
	for (int i = 0; i < quantity; i++) {
		cout << endl << i + 1 << ")\n"; cin >> el;
		m.insert(make_pair(i, el));
	}
	lenght = m.size();
}
template <class T>
void Container<T>::Print() {
	cout << "\nСловарь:\n";	cout << endl;
	for (int i = 0; i < m.size(); i++) {
		cout << i + 1 << " : " << m[i] << " " << endl;
	}
}
template <class T>
int Container<T>::Find(T value) {
	int i = 0;
	bool flag = true;
	while (i < m.size() && flag) {
		if (m[i] == value) {
			flag = false;
		}
		i++;
		if (i == m.size() && flag == true) {
			i++;
		}
	}
	return i;
}
template <class T>
int Container<T>::Size() {
	return lenght;
}
template <class T>
void Container<T>::Add(T value, int pos) {
	map<int, T> temp_map;
	for (int i = 0; i < pos; i++) {
		temp_map.insert(make_pair(i, m[i]));
	}
	temp_map.insert(make_pair(pos, value));
	for (int i = pos + 1; i < m.size() + 1; i++) {
		temp_map.insert(make_pair(i, m[i - 1]));
	}
	m.clear();
	m = temp_map;
	temp_map.clear();
}
template <class T>
void Container<T>::Dell(int pos) {
	map<int, T> temp_map;
	int lenght = m.size();
	for (int i = 0; i < pos; i++) {
		temp_map.insert(make_pair(i, m[i]));
	}
	for (int i = pos + 1; i < lenght; i++) {
		temp_map.insert(make_pair(i - 1, m[i]));
	}
	m.clear();
	m = temp_map;
	temp_map.clear();
}
template <class T>
T Container<T>::Min() {
	map<int, Money>::iterator it = m.begin();
	T min = (*it).second;
	while (it != m.end()) {
		if (min > (*it).second) {
			min = (*it).second;
		}
		it++;
	}
	return min;
}
template <class T>
T Container<T>::Max() {
	map<int, Money>::iterator it = m.begin();
	T max = (*it).second;
	while (it != m.end()) {
		if (max < (*it).second) {
			max = (*it).second;
		}
		it++;
	}
	return max;
}
template <class T>
void Container<T>::Decrease(T value) {
	for (int i = 0; i < lenght; i++) {
		m[i] - value;
	}
}