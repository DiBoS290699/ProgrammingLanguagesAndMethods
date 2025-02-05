// ЯП 4 В 6.cpp : Defines the entry point for the console application.

/*ofstream fout1("reversefile1000.txt");
ofstream fout2("reversefile5000.txt");
ofstream fout3("reversefile10000.txt");
for (int i = 1000; i != 0; --i) {
fout1 << i << ' ';
}
for (int i = 5000; i != 0; --i) {
fout2 << i << ' ';
}
for (int i = 10000; i != 0; --i) {
fout3 << i << ' ';
}
fout1.close();
fout2.close();
fout3.close(); */

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>               //необходим для подсчёта времени
using namespace std;            //подключение библиотек

double random(double min, double max)
{
	return (double)rand() / (double)RAND_MAX*(max - min) + min;
}

////////////////СОЗДАНИЕ СТРУКТУРЫ////////////////
struct OCL
{
	double val;
	OCL* ptr;
};
//--------------------------------------------------------------------

////////////////Инициализация////////////////
OCL *init(double a)		// а- значение первого узла
{
	OCL *lst;
						// выделение памяти под корень списка
	lst = (OCL*)malloc(sizeof(OCL));
	lst->val = a;
	lst->ptr = lst;			// указатель на сам корневой узел
	return(lst);
}
//--------------------------------------------------------------------

////////////////Функция поиска элемента списка по индексу////////////////
OCL *find(OCL *x, int size, int number) {
	if (number >= size) throw "Вызов несуществующего индекса";
	else if (number == 0) return x;		
	else {
		if (number == -1) number = size - 1;	//если поиск по -1 индексу, то возвращается последний узел
		OCL *temp = x;
		for (int i = 0; i < number; ++i) {
			temp = temp->ptr;
		}
		return temp;
	}
}
//-------------------------------------------------------------------- 

////////////////Деструктор ОЦС////////////////
void clearOCL(OCL *x)
{	//Проход по каждому узлу и очищение памяти в них
	for (OCL *z, *y = x->ptr; y != x;) {
		z = y->ptr;
		free(y);
		y = z;
	}
	free(x);
}
//--------------------------------------------------------------------

////////////////Функция вывода элементов ОЦС////////////////
void listprint(OCL *lst)
{
	OCL *p;
	p = lst;
	do {
		cout << p->val << "   "; // вывод значения узла p
		p = p->ptr; // переход к следующему узлу
	} while (p != lst); // условие окончания обхода
	cout << endl;
}
//--------------------------------------------------------------------

////////////////Функция заполнения данными из файла////////////////
OCL* push(int size, ifstream& fin)
{
	double t;
	fin >> t;
	OCL *x = init(t);	//Инициализация корневого элемента
	OCL *y = (OCL*)malloc(sizeof(OCL));
	for (int i = 0; i < size - 1; ++i) {
		OCL *z = (OCL*)malloc(sizeof(OCL));
		if (i == 0) {
			x->ptr = y;	//создание узла, следующего за корневым
		}
		if (i == size - 2) {
			fin >> t;	
			y->val = t;	//Присваивание последнему элементу значения
			y->ptr = x;	//и добавление ссылки на корневой узел
			break;
		}
		fin >> t;
		y->val = t;		//Присваивание узлу значения
		y->ptr = z;		//и добавление ссылки на след. узел
		y = y->ptr;		//
	}
	fin.close();
	return x;
}
//--------------------------------------------------------------------

////////////////Функция заполнения рандомными данными////////////////
OCL* randpush(int size)
{
	srand(time(0));                     //для различной генерации рандомных
	if (size == 1000) {
		ofstream fout1("randfile1000.txt");
		for (int i = 1000; i != 0; --i) {
			fout1 << random(0, 1000) << ' ';
		}
		fout1.close();
		ifstream fin1000("randfile1000.txt");
		return push(size, fin1000);
	}
	else if (size == 5000) {
		ofstream fout2("randfile5000.txt");
		for (int i = 5000; i != 0; --i) {
			fout2 << random(0, 5000) << ' ';
		}
		fout2.close();
		ifstream fin5000("randfile5000.txt");
		return push(size, fin5000);
	}
	else if (size == 10000) {
		ofstream fout3("randfile10000.txt");
		for (int i = 10000; i != 0; --i) {
			fout3 << random(0, 10000) << ' ';
		}
		fout3.close();
		ifstream fin10000("randfile10000.txt");
		return push(size, fin10000);
	}
}
//--------------------------------------------------------------------

////////////////Функция заполнения почти отсортированными данными////////////////
OCL* almostpush(int size)
{	
	//srand(time(0));                     //для различной генерации рандомных
	//ofstream fout1("almostfile1000.txt");
	//ofstream fout2("almostfile5000.txt");
	//ofstream fout3("almostfile10000.txt");
	//for (int i = 0; i < 1000; ++i) {
	//!(i % 10) ? fout1 << random(0,1000) << ' ' : fout1 << i << ' ';
	//}
	//for (int i = 0; i < 5000; ++i) {
	//!(i % 10) ? fout1 << random(0,5000) << ' ' : fout2 << i << ' ';
	//}
	//for (int i = 0; i < 10000; ++i) {
	//!(i % 10) ? fout1 << random(0,10000) << ' ' : fout3 << i << ' ';
	//}
	//fout1.close();
	//fout2.close();
	//fout3.close(); 
	if (size == 1000) {
		ifstream fin1000("almostfile1000.txt");
		if (!fin1000.is_open() || fin1000.peek() == EOF) throw "Некорректный файл!";
		return push(size, fin1000);
	}
	else if (size == 5000) {
		ifstream fin5000("almostfile5000.txt");
		if (!fin5000.is_open() || fin5000.peek() == EOF) throw "Некорректный файл!";
		return push(size, fin5000);
	}
	else if (size == 10000) {
		ifstream fin10000("almostfile10000.txt");
		if (!fin10000.is_open() || fin10000.peek() == EOF) throw "Некорректный файл!";
		return push(size, fin10000);
	}
}
//--------------------------------------------------------------------

////////////////Функция заполнения обратно отсортированными данными////////////////
OCL* reversepush(int size)
{
	if (size == 1000) {
		ifstream fin1000("reversefile1000.txt");
		if (!fin1000.is_open() || fin1000.peek() == EOF) throw "Некорректный файл!";
		return push(size, fin1000);
	}
	else if (size == 5000) {
		ifstream fin5000("reversefile5000.txt");
		if (!fin5000.is_open() || fin5000.peek() == EOF) throw "Некорректный файл!";
		return push(size, fin5000);
	}
	else if (size == 10000) {
		ifstream fin10000("reversefile10000.txt");
		if (!fin10000.is_open() || fin10000.peek() == EOF) throw "Некорректный файл!";
		return push(size, fin10000);
	}
}
//--------------------------------------------------------------------

////////////////Функция сортировки вставками////////////////
double insertion(OCL *x, int size)
{
	OCL *tmp1, *tmp2;	//Две локальные переменные
	double beg = clock();	//Начало отсчёта
	for (int i = 1; i < size; i++) {
		tmp1 = find(x, size, i - 1);
		tmp2 = tmp1->ptr;
		for (int j = i; j > 0 && tmp1->val > tmp2->val; j--) {	
			swap(tmp1->val, tmp2->val);	   // меняем местами значения узлов j и j-1
			tmp1 = find(x, size, j - 2);
			tmp2 = tmp1->ptr;
		}
	}
	double end = clock();
	return (end - beg)/CLOCKS_PER_SEC;
}
//--------------------------------------------------------------------


int main()
{
	setlocale(LC_CTYPE, "rus");		//функция, позволяющая выводить на экран буквы русского алфавита

	while (cout << "Продолжить? (Да (Y) | Нет (N))\n") {
		string y_n;
		cin >> y_n;
		if (y_n == "Y" || y_n == "y") {
			cout << "Введите количество данных для сортировки (1000/5000/10000): ";
			int size;				//Размер списка
			while (cin >> size) {
				if (size != 1000 && size != 5000 && size != 10000) {
					cout << "Некорректное количество данных. Введите его заново: ";
					continue;
				}
				
				OCL *x = randpush(size);
				double randtime = insertion(x, size);	//Время сортировки ранд. данных
				cout << "--------------------------------------------------------------------\n"
					<< "Сортировка рандомных данных:\n"
					<< "--------------------------------------------------------------------\n";
				listprint(x);		//Вывод на экран всех элементов
				clearOCL(x);		//Вызов деструктора для списка

				x = almostpush(size);
				double almosttime = insertion(x, size);	//Время сортировки почти отсорт. данных
				cout << "--------------------------------------------------------------------\n"
					<< "Сортировка почти отсортированных данных:\n"
					<< "--------------------------------------------------------------------\n";
				listprint(x);		//Вывод на экран всех элементов
				clearOCL(x);		//Вызов деструктора для списка

				x = reversepush(size);
				double reversetime = insertion(x, size);	//Время работы обр. отсорт. данных
				cout << "--------------------------------------------------------------------\n"
					<< "Сортировка обратно отсортированных данных:\n"
					<< "--------------------------------------------------------------------\n";
				listprint(x);		//Вывод на экран всех элементов
				clearOCL(x);		//Вызов деструктора для списка
				cout << "Время работы сортировки рандомных данных: " << randtime << " СЕКУНД" << endl;
				cout << "Время работы сортировки почти отсортированных данных: " << almosttime << " СЕКУНД" << endl;
				cout << "Время работы сортировки обратно отсортированных данных: " << reversetime << " СЕКУНД" << endl;
				break;
			}
		}
		//-----------------------------------------------------------------------------
		else if (y_n == "N" || y_n == "n") {
			return 0;
		}
		//-----------------------------------------------------------------------------
		else {
			cout << "Неправильный символ!\n";
			continue;
		}
	}
}