#include "Set.h"
#include <iostream>
#include <algorithm>
Set::Set() {
	size = 0;
	max_size = Lenght;
	data = new int [max_size];
	begin.element = &data[0];
	end.element = &data[size];
}
Set::Set(Set& temp_Set) {
	size = temp_Set.size;
	max_size = temp_Set.max_size;
	data = new int[max_size];
	for (int i = 0; i < size; i++) {
		data[i] = temp_Set.data[i];
	}
	begin = temp_Set.begin;
	end = temp_Set.end;
}
Set::~Set() {
	delete[] data;
}
Set& Set::operator = (const Set& temp_Set) {
	if (*this == temp_Set) {
		return *this;
	}
	size = temp_Set.size;
	delete[] data;
	data = temp_Set.data;
	begin = temp_Set.begin;
	end = temp_Set.end;
	return *this;
}
void Set::Insert(int value) {
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
		begin.element = &data[0];
		end.element = &data[size];
		size++;
		if (size == max_size) {
			max_size += max_size;
			int* temp_data = new int[max_size];
			for (i = 0; i < size; i++) {
				temp_data[i] = data[i];
			}
			delete[] data;
			data = temp_data;
		}
	}
}
int Set::operator [] (int index) {
	if (index < size && index >=0) {
		return data[index];
	}
	else {
		cout << "\nОшибка! Неизвестный индекс!\n";
		return -1;
	}
}
bool Set::operator == (const Set& temp_Set) {
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
bool Set::operator > (int value) {
	for (int i = 0; i < size; i++) {
		if (data[i] == value) {
			return true;
		}
	}
	return false;
}
istream& operator >> (istream& in, Set& temp_Set) {
	int number, quantity;
	cout << "\nКол-во элментов - "; in >> quantity;
	for (int i = 0; i < quantity; i++) {
		cout << i + 1 << ") ";
		in >> number;
		temp_Set.Insert(number);
	}
	return in;
}
ostream& operator << (ostream& out, const Set& temp_Set) {
	out << "{ ";
	for (int i = 0; i < temp_Set.size; i++) {
		out << temp_Set.data[i] << " ";
	}
	out << "}\n";
	return out;
}
