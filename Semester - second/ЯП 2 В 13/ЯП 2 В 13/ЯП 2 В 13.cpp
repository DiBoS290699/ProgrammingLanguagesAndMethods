#include "stdafx.h"
#include <iostream>		//Использование cin и cout
#include <fstream>		//Работа с файлами
#include <iomanip>		//Работа с форматированием вывода
using namespace std;

double function(double* A, const int& count){	//Данная функция заносит все числа в массив и одновременно с каждым занесением
	double p = 0, n = 0;						//если число больше нуля, то оно прибавляется к переменной p (positiv), 
	for (int i = 0; i < count; (A[i] > 0) ? p += A[i] : n += A[i], cout << A[i] << ' ', i++);	//иначе - к переменной n (negativ)
	cout << "\nСумма положительных чисел: " << p << "\nСумма отрицательных чисел: " << n << '\n';	//и выводится  на экран
	return p - n;								//Возвращение разности СПЧ и СОЧ
}

bool isdigit(char c) { return '0' <= c && c <= '9'; }	//Проверка символа на цифру

void check(double* A, int& count, ifstream& fin) {		//Проверка входных данных из файла
	for (; count < 100 && fin >> A[count]; count++);	//Функция заносит данные из файла и в какой-то момент 
	fin.clear();										//флаг потока переходит в false, после чего пока не будет найден
	while (!isdigit(fin.peek()) && fin.peek() != EOF) { fin.get(); }	//символ цифры или же EOF элементы потока удаляются.
	if (fin.peek() == EOF) return;						//Если будет найден EOF, значит все значения занесены в массив,
	check(A, count, fin);								//иначе мы рекурсивно заходим в эту же функцию.
}

int main()
{
	setlocale(LC_ALL, "rus");				//Включение символов кириллицы
	char input[50];							//Переменная с названием файла
	double A[100];							//Массив, максимально состоящий из ста символов
	cout << "Введите имя файла или введите quit: ";
	while (cin.getline(input, 50)) {		//Занесение имя файла в переменную input
		if (input[0] == 'q' && input[1] == 'u' && input[2] == 'i' && input[3] == 't' && input[4] == '\0') return 0;
		ifstream fin(input);				//Вызов файла для чтения
		if (!fin.is_open() || fin.peek() == EOF) {	//is_open() - возвращает true, если файл найден и открывается
			cout << "ОШИБКА: Файл входных данных не найден или он пуст!\n" << "Введите имя файла снова или введите quit: ";
			continue;
		}
		ofstream fout("OutputFile.txt");
		cout << setprecision(16);		//Задает точность для плавающей запятой для потока вывода
		fout << setprecision(16);		//и для потока файла
		int count = 0;					//Счётчик элементов в массиве
		check(A, count, fin);			//Функция проверки данных из файла
		double r = function(A, count);
		cout << "Разность СПЧ и СОЧ: " << r << '\n';
		fout << "Разность СПЧ и СОЧ: " << r;
		fin.close();					//Закрытие файла fin
		fout.close();					//Закрытие файла fout
		system("pause");
		return 0;
	}
}