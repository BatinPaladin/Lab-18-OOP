#pragma once
struct coordinates {
	double first;
	double second;
	void Init(double, double); //Метод инициализации полей
	void Read(); //Метод чтения значений полей
	void Show(); //Метод вывода значений полей
	double distance(); //Метод вычисления расстояния
};
