#include <iostream>		// Использование cout и cin
#include <fstream>		// Возможность работать с файлами
#include <string>		// Возможность работать с классом string
#include <vector>		// Возможность работать с контейнером vector

using namespace std;	// Подключение библиотек

//Объявление класса Speed 
class Speed
{
private:

	int num;
	double sp;
	string unit;

public:
	Speed()		// Создание пустого класса
	{
	};

	// Создание заполненного класса
	Speed(int n, double s, string un) : num(n), sp(s), unit(un) { }	

	// Операция копирования
	Speed(const Speed& s) : num(s.num), sp(s.sp), unit(s.unit) { }

	// Прочие перегрузки
	// Операция присваивания
	Speed operator = (const Speed& s)
	{
		num = s.num;
		sp = s.sp;
		unit = s.unit;
		return (*this);
	}

	// Арифметические операторы
	Speed operator += (const double& d)	// Оператор суммы 
	{
		return Speed(num, sp += d, unit);
	}
	Speed operator + (const double& d)	// Оператор суммы 
	{
		return Speed(num, sp + d, unit);
	}
	Speed operator -= (const double& d)	// Оператор разности 
	{
		return Speed(num, sp -= d, unit);
	}
	Speed operator - (const double& d)	// Оператор разности 
	{
		return Speed(num, sp - d, unit);
	}
	Speed operator * (const double& d)	// Оператор умножения 
	{
		return Speed(num, sp * d, unit);
	}
	Speed operator / (const double& d)	// Оператор деления 
	{							
		if (d != 0) { return Speed(num, sp / d, unit); }
		else return (*this);
	}

	// Операторы сравнения
	bool operator < (const Speed& s) 
	{
		if (unit == s.unit) { return sp < s.sp; }
		if (unit == "km/h" && s.unit == "m/s") { return sp < (s.sp * 3.6); }
		if (unit == "m/s" && s.unit == "km/h") { return (sp * 3.6) < s.sp; }
	}
	bool operator > (const Speed& s)
	{
		if (unit == s.unit) { return s.sp < sp; }
		if (unit == "km/h" && s.unit == "m/s") { return (s.sp * 3.6) < sp; }
		if (unit == "m/s" && s.unit == "km/h") { return s.sp < (sp * 3.6); }
	}
	bool operator == (const Speed& s)
	{
		if (unit == s.unit) { return !(sp < s.sp) && !(s.sp < sp); }
		if (unit == "km/h" && s.unit == "m/s") { return !(sp < (s.sp * 3.6)) && !((s.sp * 3.6) < sp); }
		if (unit == "m/s" && s.unit == "km/h") { return !((sp * 3.6) < s.sp) && !(s.sp < (sp * 3.6)); }
	}

	// Метод класса, переводящий скорость в другую единицу измерения
	Speed change()	//Изменение единицы измерения
	{
		const double con = 3.6;		//Константа перевода из м/с в км/ч
		if (unit == "km/h") { return Speed(num, sp / con, "m/s"); }
		if (unit == "m/s") { return Speed(num, sp * con, "km/h"); }
		else return (*this);
	}

	~Speed()	// Деструктор для удаления класса
	{
	}

	// friend позволяет этим функциям обращаться к приватным элементам класса
	friend ostream & operator<< (ostream &, const Speed &);
	friend istream & operator>> (istream &, Speed &);
	friend bool check_num(Speed& s);
	friend bool check_sp(Speed& s);
	friend bool check_unit(Speed& s);
};

// Проверки значений класса
bool check(Speed& s)
{
	return check_num(s) && check_sp(s) && check_unit(s);
}
bool check_num(Speed& s)
{
	if (s.num < 1) {
		cout << "Неправильный номер!\n";
		return false;
	}
	else return true;
}
bool check_sp(Speed& s)
{
	if (s.sp < 0) {
		cout << "Неправильная скорость!\n";
		return false;
	}
	else return true;
}
bool check_unit(Speed& s)
{
	if ((s.unit != "km/h") && (s.unit != "m/s")) {
		cout << "Неправильное измерение!\n";
		return false;
	}
	else return true;
}

// перегрузка оператора >>
istream& operator>> (istream& in, Speed& s)
{
	in >> s.num >> s.sp >> s.unit;
	return in;
}

// перегрузка оператора <<
ostream& operator<< (ostream &out, const Speed &s)
{
	out << "(" << s.num << ' ' << s.sp << ' ' << s.unit << ')';
	return out;
}

// Вывод двух массивов на консоль
void coutput(const vector<Speed>& sp1, const vector<Speed>& sp2)
{
	cout << "Старые значения: ";
	for (Speed i : sp1) { cout << i << '\t'; }
	cout << endl << "Новые значения: ";
	for (Speed i : sp2) { cout << i << '\t'; }
	cout << endl;
}

// Вывод двух массивов в файл
void foutput(const vector<Speed>& sp1, const vector<Speed>& sp2)
{
	ofstream fout("program result.txt");
	fout << "Старые значения: ";
	for (Speed i : sp1) { fout << i << '\t'; }
	fout << endl << "Новые значения: ";
	for (Speed i : sp2) { fout << i << '\t'; }
	cout << "Данные занесены в файл: program result.txt\n";
}

// Выбор размещения результатов
void output(const vector<Speed>& sp1, const vector<Speed>& sp2)
{
	string f_c;
	cout << "Выберите куда будет заноситься результат. (Console (с) или file (f))\n";
	while (getline(cin, f_c)) {
		if (f_c == "") { continue; }
		if (f_c == "console" || f_c == "Console" || f_c == "c" || f_c == "C") {
			coutput(sp1, sp2);
			return;
		}
		else if (f_c == "file" || f_c == "File" || f_c == "f" || f_c == "F") {
			foutput(sp1, sp2);
			return;
		}
		else cout << "Некорректный ответ! Введите его заново: ";
	}
}

// Предложение продолжить работу
bool cont() 
{
	string y_n;
	cout << "Желаете продолжить? (Y или N)\n";
	while (getline(cin, y_n)) {
		if (y_n == "") { continue; }
		if (y_n == "Y" || y_n == "y") { return true; }
		else if (y_n == "N" || y_n == "n") { return false; }
		else cout << "Некорректный ответ! Введите его заново: ";
	}
}

// Работа с консолью
void console(vector<Speed>& sp1, vector<Speed>& sp2) 
{
	int size;
	cout << "Введите количество замеров скорости: ";
	cin >> size;
	for (int i = 0; i < size; ++i) {
		Speed old;
		cout << "Введите номер, скорость и единицу измерения: ";
		cin >> old;
		if (!check(old)) {
			--i;
			continue;
		}
		sp1.push_back(old);
		sp2.push_back(old.change());
	}
	output(sp1, sp2);
	sp1.clear();
	sp2.clear();
	return;
}

// Работа с файлом
void file(vector<Speed>& sp1, vector<Speed>& sp2) 
{
	string file;
	cout << "Введите имя файла: ";
	while (getline(cin, file)) {
		ifstream fin(file);
		if (!fin.is_open()) { cout << "Файл не найден. Введите его имя заново: "; }
		else {
			Speed old;
			while (fin >> old) {
				if (check(old)) {
					sp1.push_back(old);
					sp2.push_back(old.change());
				}
				else cout << "Одно из значение некорректно!\n";
			}
			output(sp1, sp2);
			sp1.clear();
			sp2.clear();
			return;
		}
	}
}

// Сердце программы
int main()
{
	setlocale(LC_ALL, "rus");
	string c_f;
	vector<Speed> sp1;
	vector<Speed> sp2;
	cout << "Откуда брать значения? (Console (с) или file (f))\n";
	while (getline(cin, c_f)) {
		if (c_f == "") { continue; }
		if (c_f == "console" || c_f == "Console" || c_f == "c" || c_f == "C") {
			console(sp1, sp2);
			if (!cont()) { return 0; }
			else cout << "Откуда брать значения? (Console (с) или file (f))\n";
		}

		else if (c_f == "file" || c_f == "File" || c_f == "f" || c_f == "F") {
			file(sp1, sp2);
			if (!cont()) { return 0; }
			else cout << "Откуда брать значения? (Console (с) или file (f))\n";
		}
		else cout << "Некорректный ответ! Введите его заново: ";
	}
}
