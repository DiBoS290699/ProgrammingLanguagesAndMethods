// ЯП 1 В10.cpp : Вариант 10
//

#include "stdafx.h"
#include <iostream>		//Использование cin и cout
#include <fstream>		//Работа с файлами
#include <iomanip>		//Работа с форматированием вывода
using namespace std;

double eps = 1e-16;								//погрешность равная 10 в степени -16

bool CheckFile(ifstream& fin)					//Проверка на открытие и на пустоту файла
{
	if (fin.is_open() && fin.peek() != EOF) {	//is_open() - возвращает true, если файл найден и открывается
		return true;							//fin.peek() != EOF - проверка на пустоту файла
	}
	else return false;
}

double function(double a, double b)
{
	double x;
	if (abs(a - b) < eps) {				//Если разность меньше погрешности, то числа равны (a == b)
		cout << a << '=' << b << " => x = " << -25 << '\n';
		return -25;
	}
	else if (a > b) {					//В противном случае два числа просто сравниваются (a > b)
		x = a / b + 31;
		cout << a << '>' << b << " => x = " << x << '\n';
		return x;
	}
	else {								//Если не (a==b) и не (a > b), то (a < b)
		x = (5 * b - 1) / a;
		cout << a << '<' << b << " => x = " << x << '\n';
		return x;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");				//Включение символов кириллицы
	char input[50];							//Переменная с названием файла
	double a, b;
	cout << "Введите имя файла: ";
	while (cin.getline(input, 50)) {		//Занесение имя файла в переменную input
		ifstream fin(input);				//Вызов файла для чтения
		if (!CheckFile(fin)) {				//Проверка файла
			cout << "ОШИБКА: Файл входных данных не найден или он пуст!\n";
			cout << "Введите имя файла снова: ";
		}
		else {
			ofstream fout("OutputFile.txt");
			cout << setprecision(16);		//Задает точность для плавающей запятой для потока вывода
			fout << setprecision(16);		//и для потока файла
			while (fin >> a >> b) {
				if (a > b && b == 0 || a < b && a == 0) {	//Проверка деления на ноль
					cout << "ОШИБКА: Деление на ноль!\n";
				}
				else
					fout << function(a, b) << '\n';			//Помещение в файл результата function
			}
			fin.close();					//Закрытие файла fin
			fout.close();					//Закрытие файла fout
			system("pause");				
			return 0;
		}
	}
}