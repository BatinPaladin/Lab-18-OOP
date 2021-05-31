#pragma once
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
template <class T>
class Vector {
private:
	priority_queue <T> pque;
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
	void Add(T);
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
		pque.push(value);
	}
	size = pque.size();
}
template <class T>
int Vector<T>::Size() {
	return size;
}
template <class T>
void Vector<T>::Show() {
	priority_queue<T> temp_pque;
	cout << "\nВектор:\n";
	while (!pque.empty()) {
		cout << pque.top() << " ";
		temp_pque.push(pque.top());
		pque.pop();
	}
	while (!temp_pque.empty()) {
		pque.push(temp_pque.top());
		temp_pque.pop();
	}
	cout << endl;
}
template <class T>
int Vector<T>::Find(T element) {
	priority_queue<T> temp_pque;
	int i = 0;
	bool flag = true;
	while (!pque.empty() && flag) {
		if (pque.top() == element) {
			flag = false;
		}
		temp_pque.push(pque.top());
		pque.pop();
		i++;
		if (i == size && flag == true) {
			i++;
		}
	}
	while (!temp_pque.empty()) {
		pque.push(temp_pque.top());
		temp_pque.pop();
	}
	return i;
}
template <class T>
void Vector<T>::Add(T element) {
	pque.push(element);
	size++;
}
template <class T>
void Vector<T>::Dell(int pos) {
	priority_queue<T> temp_pque;
	int i = 0;
	while (!pque.empty()) {
		if (i == pos - 1) {
			pque.pop();
		}
		else {
			temp_pque.push(pque.top());
			pque.pop();
		}
		i++;
	}
	while (!temp_pque.empty()) {
		pque.push(temp_pque.top());
		temp_pque.pop();
	}
	size--;
}
template <class T>
T Vector<T>::Max() {
	return pque.top();
}
template <class T>
T Vector<T>::Min() {
	priority_queue<T> temp_pque;
	for (int i = 0; i < size - 1; i++) {
		temp_pque.push(pque.top());
		pque.pop();
	}
	T min = pque.top();
	temp_pque.push(pque.top());
	pque.pop();
	while (!temp_pque.empty()) {
		pque.push(temp_pque.top());
		temp_pque.pop();
	}
	return min;
}
template <class T>
void Vector<T>::Decrease(T value) {
	priority_queue<T> temp_pque;
	int i = 0;
	while (!pque.empty()) {
		T res = pque.top();
		res - value;
		temp_pque.push(res);
		pque.pop();
	}
	while (!temp_pque.empty()) {
		pque.push(temp_pque.top());
		temp_pque.pop();
	}
}