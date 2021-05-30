#pragma once
#include <iostream>
#include <algorithm>
using namespace std;
const int Lenght = 10;
template <class T>
class Set
{
private:
	int size = 0;
	int max_size;
	T* data;
public:
	Set();
	Set(const Set<T>&);
	~Set();
	int get_size() {
		return size;
	}
	void Insert(T);
	Set<T>& operator = (const Set<T>&);
	T operator [] (int);
	bool operator == (const Set <T>&);
	bool operator > (T);
	friend istream& operator >> <>(istream&, Set<T>&);
	friend ostream& operator << <>(ostream&, const Set<T>&);
};
template <class T>
Set<T>::Set() {
	size = 0;
	max_size = Lenght;
	data = new T[max_size];
}
template <class T>
Set<T>::Set(const Set& temp_Set) {
	size = temp_Set.size;
	max_size = temp_Set.max_size;
	data = new T[max_size];
	for (int i = 0; i < size; i++) {
		data[i] = temp_Set.data[i];
	}
}
template <class T>
Set<T>::~Set() {
	delete[] data;
	data = 0;
}
template <class T>
void Set<T>::Insert(T value) {
	int i;
	for (i = 0; i < size; i++) {
		if (data[i] == value) {
			i = size;
		}
	}
	if (i != size + 1) {
		data[size] = value;
		if (i > 0) {
			sort(data, data + size + 1);
		}
		size++;
		if (size == max_size) {
			max_size += max_size;
			T* temp_data = new T [max_size];
			for (i = 0; i < size; i++) {
				temp_data[i] = data[i];
			}
			delete[] data;
			data = temp_data;
		}
	}
}
template<class T>
Set<T>& Set<T>::operator = (const Set<T>& temp_Set) {
	if (*this == temp_Set) {
		return *this;
	}
	size = temp_Set.size;
	max_size = temp_Set.max_size;
	delete[] data;
	data = temp_Set.data;
	return *this;
}
template<class T>
T Set<T>::operator [] (int index) {
		return data[index];
}
template<class T>
bool Set<T>::operator == (const Set<T>& temp_Set) {
	if (size == temp_Set.size) {
		int i;
		for (i = 0; i < size; i++) {
			if (data[i] != temp_Set.data[i]) {
				i = size;
			}
		}
		if (i == size) {
			return true;
		}
	}
	return false;
}
template<class T>
bool Set<T>::operator > (T value) {
	for (int i = 0; i < size; i++) {
		if (data[i] == value) {
			return true;
		}
	}
	return false;
}
template <class T>
istream& operator >> (istream& in, Set<T>& temp_Set) {
	T number;
	int quantity;
	cout << "\nКол-во элментов - "; in >> quantity;
	for (int i = 0; i < quantity; i++) {
		cout << i + 1 << ") ";
		in >> number;
		temp_Set.Insert(number);
	}
	return in;
}
template <class T>
ostream& operator << (ostream& out, const Set<T>& temp_Set) {
	out << "{ ";
	for (int i = 0; i < temp_Set.size; i++) {
		out << temp_Set.data[i] << " ";
	}
	out << "}\n";
	return out;
}