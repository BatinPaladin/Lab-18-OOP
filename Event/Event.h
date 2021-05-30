#pragma once
const int evNothing = 0; //Пустое сообщение
const int evMessage = 100; //Непустое сообщение
const int cmAdd = 1; //Добавить объект в группу
const int cmDel = 2; //Удалить объект из группы
const int cmGet = 3; //Вывести средний возраст всех объектов
const int cmShow = 4; //Вывести всю группу
const int cmMake = 6; //Создать группу
const int cmQuit = 101; //Выход
struct TEvent {
	int what;
	union {
		int command;
		struct {
			int message;
			int a;
		};
	};
};