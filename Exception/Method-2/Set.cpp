#include "Set.h"
#include "Error.h"
#include <algorithm>
Set::Set() {
	size = 0;
	data = new int[MAX_SIZE];
}
Set::Set(Set& temp_Set) {
	size = temp_Set.size;
	delete[] data;
	data = new int[MAX_SIZE];
	for (int i = 0; i < size; i++) {
		data[i] = temp_Set.data[i];
	}
}
Set::~Set() {
	delete[] data;
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
		size++;
	}
}
int Set::get_size() {
	return size;
}
Set& Set::operator=(const Set& temp_Set) {
	if (*this == temp_Set) {
		return *this;
	}
	size = temp_Set.size;
	delete[] data;
	data = new int[MAX_SIZE];
	for (int i = 0; i < size; i++) {
		data[i] = temp_Set.data[i];
	}
	return *this;
}
int Set::operator[](int index) {
	if (size == 0) {
		throw Error("\n��������� ������� ��������� � ������� ���������\n");
	}
	if (index < 0) {
		throw Error("\n��������� ������� ��������� � �������� � ������������� ��������\n");
	}
	if (index >= size) {
		throw Error("\n��������� ������� ��������� � ��������, ������ �������� ������ ������������� �������\n");
	}
	cout << "\n���������� ������ ��������� � ������� " << index + 1 << " = ";
	return data[index];
}
bool Set::operator>(int value) {
	for (int i = 0; i < size; i++) {
		if (data[i] == value) {
			return true;
		}
	}
	return false;
}
bool Set::operator==(const Set& temp_Set) {
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
int Set::operator-(int shift) {
	if (size == 0) {
		throw Error("\n��������� ������� ��������� � ������� ���������");
	}
	if (shift > size) {
		throw Error("\n��������� ������� ������ ������� �� �������� ������� ����� ���������");
	}
	if (shift < 0) {
		throw Error("\n��������� ������� ������ ������� �� ������������� ��������");
	}
	cout << "\n���������� ������ ��������� � ������� " << size - shift + 1 << " = ";
	return data[size - shift];
}
ostream& operator << (ostream& out, const Set& temp_Set) {
	out << "\n{ ";
	for (int i = 0; i < temp_Set.size; i++) {
		out << temp_Set.data[i] << " ";
	}
	out << "}\n";
	return out;
}
istream& operator >> (istream& in, Set& temp_Set) {
	int number, quantity;
	cout << "\n���-�� �������� - "; in >> quantity;
	if (quantity > MAX_SIZE) {
		throw Error("\n��������� ������� �������� ���������, ���-�� ��������� �������� ������ ������������� ���-�� ���������");
	}
	if (quantity < 0) {
		throw Error("\n��������� ������� �������� ��������� � ������������� ���-��� ���������");
	}
	for (int i = 0; i < quantity; i++) {
		cout << i + 1 << ") ";
		in >> number;
		temp_Set.Insert(number);
	}
	return in;
}