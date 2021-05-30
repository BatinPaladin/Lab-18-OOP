#pragma once
#include <iostream>
#include "Object.h"
#include "Abiturient.h"
using namespace std;
struct Node {
	Object* data;
	Node* next;
	Node* prev;
};
class List {
public:
	List();
	~List();
	void Show();
	void Push_Front();
	void Push_Back();
	void Pop_Front();
	void Pop_Back();
	virtual void HandleEvent(const TEvent&);
protected:
	Node* head;
	Node* tail;
	int size;
};