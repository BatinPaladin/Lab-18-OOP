#pragma once
#include <vector>
#include <iostream>
using namespace std;
template <class T>
class Vector {
private:
	vector <T> vec;
	int size;
public:
	Vector();
	Vector(int);
	~Vector();
	int Size();
	void Show();
	int Find(T);
	T Max();
	T Min();
	void Add(T, int);
	void Dell(int);
	void Decrease(T);
};
template <class T>
Vector <T>::Vector() {
	size = 0;
}
template <class T>
Vector <T>::~Vector() { }
template <class T>
Vector <T>::Vector(int quantity) {
	T value;
	for (int i = 0; i < quantity; i++) {
		cout << "\n" << i + 1 << ")\n";
		cin >> value;
		vec.push_back(value);
	}
	size = vec.size();
}
template <class T>
int Vector<T>::Size() {
	return size;
}
template <class T>
void Vector<T>::Show() {
	cout << "\nВектор:\n";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}
template <class T>
int Vector<T>::Find(T element) {
	int i = 0;
	bool flag = true;
	while (i < vec.size() && flag) {
		if (vec[i] == element) {
			flag = false;
		}
		i++;
		if (i == vec.size() && flag == true) {
			i++;
		}
	}
	return i;
}
template <class T>
void Vector<T>::Add(T element, int pos) {
	vec.insert(vec.begin() + pos, element);
	size++;
}
template <class T>
void Vector<T>::Dell(int pos) {
	vec.erase(vec.begin() + pos - 1);
	size--;
}
template <class T>
T Vector<T>::Max() {
	T max = vec[0];
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i] > max) {
			max = vec[i];
		}
	}
	return max;
}
template <class T>
T Vector<T>::Min() {
	T min = vec[0];
	for (int i = 1; i < size; i++) {
		if (vec[i] < min) {
			min = vec[i];
		}
	}
	return min;
}
template <class T>
void Vector<T>::Decrease(T value) {
	for (int i = 0; i < size; i++) {
		vec[i] - value;
	}
}