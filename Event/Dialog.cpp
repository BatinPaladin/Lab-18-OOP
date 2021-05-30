#include "Dialog.h"
Dialog::Dialog() : List() {
	EndState = 0;
}
Dialog::~Dialog() { }
void Dialog::GetEvent(TEvent& event) {
	string OpInt = "+-mszq";
	string s, param;
	char code;
	cout << "\nm - Создать список\ns - Показать список\n+ - Добавить объект в список\n- - Удалить объект из списка\nz - Узнать средний возраст группы\nq - Выход\n\n> ";
	cin >> s; 
	code = s[0];
	if (OpInt.find(code) >= 0) {
		event.what = evMessage;
		switch (code) {
		case 'm':
			event.command = cmMake;
			break;
		case '+':
			event.command = cmAdd;
			break;
		case '-':
			event.command = cmDel;
			break;
		case 's':
			event.command = cmShow;
			break;
		case 'z':
			event.command = cmGet;
			break;
		case 'q':
			event.command = cmQuit;
			break;
		}
		if (s.length() > 1) {
			param = s.substr(1, s.length() - 1);
			int A = atoi(param.c_str());
			event.a = A;
		}
	}
	else {
		event.what = evNothing;
	}
}
int Dialog::Execute() {
	TEvent event;
	do {
		EndState = 0;
		GetEvent(event);
		HandleEvent(event);
	} while (!Valid());
	return EndState;
}
int Dialog::Valid() {
	if (EndState == 0) {
		return 0;
	}
	else {
		return 1;
	}
}
void Dialog::ClearEvent(TEvent& event) {
	event.what = evNothing;
}
void Dialog::EndExec() {
	EndState = 1;
}
void Dialog::HandleEvent(TEvent& event) {
	if (event.what == evMessage) {
		switch (event.command)
		{
		case cmMake:
			int otvet;
			head = nullptr;
			tail = nullptr;
			for (int i = 0; i < event.a; i++) {
				Push_Back();
			}
			ClearEvent(event);
			break;
		case cmAdd:
			if (size == 0) {
				cout << "\nСписок не создан!\n";
			}
			else {
				cout << "\nДобавить объект в:\n1 - Конец списка\n0 - Начало списка\n> ";
				cin >> otvet;
				if (otvet == 1) {
					Push_Back();
				}
				if (otvet == 0) {
					Push_Front();
				}
			}
			ClearEvent(event);
			break;
		case cmDel:
			if (size == 0) {
				cout << "\nСписок пуст!\n";
			}
			else {
				cout << "\nУдалить объект из:\n1 - Конца списка\n0 - Начала списка\n> ";
				cin >> otvet;
				if (otvet == 1) {
					Pop_Back();
				}
				if (otvet == 0) {
					Pop_Front();
				}
			}
			ClearEvent(event);
			break;
		case cmShow:
			if (size == 0) {
				cout << "\nСписок пуст!\n";
			}
			else {
				Show();
			}
			ClearEvent(event);
			break;
		case cmQuit:
			EndExec();
			ClearEvent(event);
			break;
		default:
			if (size == 0) {
				cout << "\nСписок пуст!\n";
			}
			else {
				List::HandleEvent(event);
			}
		}
	}
}