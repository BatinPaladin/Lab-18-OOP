#include "List.h"
List::List() {
	head = nullptr;
	tail = nullptr;
	size = 0;
}
List::~List() {
	while (head != nullptr) {
		Pop_Front();
	}
}
void List::Show() {
	Node* temp = head;
	while (temp != nullptr) {
		temp->data->Show();
		temp = temp->next;
	}
}
void List::Push_Front() {
	cout << "\nКакой объект добавить\n1 - Person\n0 - Abiturient\n> ";
	int otvet;
	cin >> otvet;
	if (otvet == 1) {
		Person* a = new Person;
		a->Input();
		Node* temp = new Node;
		temp->data = a;
		if (size == 0) {
			temp->next = tail;
			temp->prev = head;
			tail = temp;
			head = temp;
		}
		else {
			head->prev = temp;
			temp->next = head;
			head = temp;
			head->prev = nullptr;
		}
		size++;
	}
	if (otvet == 0) {
		Abiturient* a = new Abiturient;
		a->Input();
		Node* temp = new Node;
		temp->data = a;
		if (size == 0) {
			temp->next = tail;
			temp->prev = head;
			tail = temp;
			head = temp;
		}
		else {
			head->prev = temp;
			temp->next = head;
			head = temp;
			head->prev = nullptr;
		}
		size++;
	}
}
void List::Push_Back() {
	cout << "\nКакой объект добавить\n1 - Person\n0 - Abiturient\n> ";
	int otvet;
	cin >> otvet;
	if (otvet == 1) {
		Person* a = new Person;
		a->Input();
		Node* temp = new Node;
		temp->data = a;
		if (size == 0) {
			temp->next = tail;
			temp->prev = head;
			tail = temp;
			head = temp;
		}
		else {
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
			tail->next = nullptr;
		}
		size++;
	}
	if (otvet == 0) {
		Abiturient* a = new Abiturient;
		a->Input();
		Node* temp = new Node;
		temp->data = a;
		if (size == 0) {
			temp->next = tail;
			temp->prev = head;
			tail = temp;
			head = temp;
		}
		else {
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
			tail->next = nullptr;
		}
		size++;
	}
}
void List::Pop_Front() {
	Node* temp = head;
	head = head->next;
	delete temp;
	size--;
}
void List::Pop_Back() {
	Node* temp = tail;
	tail = tail->prev;
	delete temp;
	tail->next = nullptr;
	size--;
}
void List::HandleEvent(const TEvent& event) {
	if (event.what == evMessage) {
		Object* object;
		int sum = 0;
		Node* temp = head;
		while (temp!=nullptr) {
			object = temp->data;
			sum += object->HandleEvent(event);
			temp = temp->next;
		}
		sum = sum / size;
		cout << "\nСредний возвраст = " << sum << "\n";
	}
}