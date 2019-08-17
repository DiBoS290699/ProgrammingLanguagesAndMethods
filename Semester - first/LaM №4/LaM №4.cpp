#include <fstream>
#include <string>
#include <iostream>

using namespace std;

bool isdigit(char str) {
	return 0 <= str && str <= 9;
}

int main()
{
	setlocale(LC_ALL, "rus");	//Для поддержки Кириллицы		
	string str;			//Будем заносить туда очищенную от цифр строку
	string val;			//Будем заносить туда числа 
	ifstream fin("Текст для ЛР.txt");	//Чтение файла
	if (!fin.is_open()) {
		cout << "Такого файла не существует!\n";
		system("pause");
		return 1;
	}
	ofstream new_fout("Выходные данные ЛР.txt");	//Создаём файл для сохранения там результатов
	while (getline(fin, str)) {		//Заносим текст с файла в str
		for (int i = 0; i < str.length(); ++i) {		//Пробегаемся по каждому символу текста
		//unsigned char необходим для считывания кириллицы, т.к. кириллица уходит за пределы считывания
			if (isdigit((unsigned char)str[i])) {
				val += str[i];		//заносим в строку val найденные цифры
				str.erase(i, 1);	//удаляем эту цифру из str
				--i;	//Опускаем счётчик на 1, т.к. размер str уменьшается
				if ((i != str.length() - 1) && !(isdigit((unsigned char)str[i + 1]))) {
					val += ',';		//Добавление запятой, если i - не последний индекс и если след. символ не цифра
				}
			}
		}
		new_fout << str << '\n';		//Заносим в файл строку и массив из чисел
	}
	new_fout << val;
	fin.close();		
	new_fout.close();
	return 0;
}
