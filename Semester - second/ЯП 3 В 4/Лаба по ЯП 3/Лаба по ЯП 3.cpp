// Лаба по ЯП 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isempty(char c)		//Символы отделения слов
{
	return c == ' ' || c == '\n' || c == '\r' || c == '\t';
}

bool isdigit(char c)
{
	return c >= '0' && c <= '9';
}

string func(ifstream& fin)
{
	//Универсальный вариант чтения всего файла
	fin.seekg(0, ios::end);						//Перемещение указателя в конец
	int length = fin.tellg();					//Определение длины потока по номеру указателя
	char* text = new char[length + 1];
	fin.seekg(0, ios::beg);						//Перемещение указателя в начало
	fin.read(&text[0], length);					//Занесение в массив text файла длины length
	text[length] = '\0';
	string str;
	cout << "Вывожу на экран содержимое файла\n" << "------------------------------\n" 
		<< text << endl << "------------------------------\n";			//Вывод текста из файла на экран
	cout << "Вывожу подходящие под условие варианта слова\n" << "------------------------------\n";
	for (int pos = 0; text[pos] != '\0'; ++pos) {
		if (isempty(text[pos])) continue;		//Пропуск символов отделения
		int beg = pos;							//Начало слова
		bool corr, word;						//корректность и соответствие слову
		for (corr = false, word = true; !isempty(text[pos]) && text[pos] != '\0'; ++pos) {
			if (!isdigit(text[pos])) {		//Если будет найдена не цифра, то
				word = false;						//это не слово и пробегаемся до символа отделения
				continue;
			}
			if (!word || corr) continue;		//Если было найдено совпадение, то добегаем до символа отделения
			for (int i = pos + 1; !isempty(text[i]) && text[i] != '\0'; ++i) {
				if (text[pos] == text[i]) { corr = true; break; }
			}
		}
		if (corr && word) {						//Если последовательность является словом и удовлетворяет условию, то
			for (; !isempty(text[beg]) && text[beg] != '\0'; ++beg) 	//выводим его на экран
				str += text[beg];
			str += ' ';
		}
	}
	delete[] text;								//Очистка памяти для переменной text
	return str;
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Приветствую вас, пользователь! Начинаем работу.\n" << "Открываю файл....";
	ifstream fin("input.txt", ios::binary);
	if (!fin.is_open() || fin.peek() == EOF) {		//Проверка на открытие и на пустоту
		cout << " УПС! Файл не открывается или же он пустой. =(\n";
		system("pause");
		return 1;
	}
	cout << " Отлично! Файл открыт.\n";
	cout << func(fin);
	cout << endl << "------------------------------\n";
	cout << "Отлично поработали! =)\n";
	system("pause");
    return 0;
}