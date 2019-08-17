#ifndef Date_H
#define Date_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Date {	//Класс дата
public:
	enum Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
	int DaysInMonth()	//Определение количества дней в месяце
	{
		return IsLeapYear() ? DayCountLeap[m - 1] : DayCount[m - 1];
	}
	bool IsLeapYear()	//Проверка на високосный год
	{
		return ((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0);
	}
	Date(int day, Month mon, int year) : d(day), m(mon), y(year) { CheckDate(); }	//Конструктор инициализации
	Date() : d(1), m(jan), y(1) {}													//Конструктор по умолчанию
	Date(const Date& x) : d(x.d), m(x.m), y(x.y) {}									//Конструктор копирования
	~Date() = default;																//Деструктор
	int GetDay() { return d; }				//Получение дня в дате
	Month GetMonth() { return m; }			//Получение месяца в дате
	int GetYear() { return y; }				//Получение года в дате
	string GetLeapYear()		//Вывод текста об високосном году
	{
		if (IsLeapYear())
			return "Is Leap Year";
		else return "Is Not Leap Year";
	}			 
	int DayNumber()		//Определения номера дня в году
	{
		bool LeapYear = IsLeapYear();	
		switch (m) {										//Проверка на соответствие каждому месяцу 
		case jan: return d;									//и соответствующее прибавление константы ко дню
		case feb: return d + 31;
		case mar: return (LeapYear) ? d + 60 : d + 59;
		case apr: return (LeapYear) ? d + 91 : d + 90;
		case may: return (LeapYear) ? d + 121 : d + 120;
		case jun: return (LeapYear) ? d + 152 : d + 151;
		case jul: return (LeapYear) ? d + 182 : d + 181;
		case aug: return (LeapYear) ? d + 213 : d + 212;
		case sep: return (LeapYear) ? d + 243 : d + 242;
		case oct: return (LeapYear) ? d + 274 : d + 273;
		case nov: return (LeapYear) ? d + 304 : d + 303;
		case dec: return (LeapYear) ? d + 335 : d + 334;
		}
	}
	ostream& y_m_d(ostream& os)	//год.месяц.день
	{
		char old_fill = os.fill('0');
		return os << setw(4) << y << '.' << setw(2) << m << '.' << setw(2) << d << setfill(old_fill);
	}
	ostream& m_d_y(ostream& os)	//месяц.день.год
	{
		char old_fill = os.fill('0');
		return os << setw(2) << m << '.' << setw(2) << d << '.' << setw(4) << y << setfill(old_fill);
	}

	bool operator==(const Date& x)	//Перегрузка оператора ==
	{
		return y == x.y && m == x.m && d == x.d;
	}
	bool operator!=(const Date& x)	//Перегрузка оператора !=
	{
		return !(*this == x);
	}
	bool operator<(const Date& x)	//Перегрузка оператора <
	{
		if (y < x.y) { return true; }	//Если год меньше то true
		else if (y == x.y) {	//Если года одиннаковые, то проверяется месяц
			if (m < x.m) { return true; }	//Если месяц меньше, то true
			else if (m == x.m) {	//Если месяца одиннаковые, то проверяется день
				if (d < x.d) { return true; }
				else return false;	//иначе false
			}
			else return false;		//Если месяц больше, то false
		}
		else return false;		//Если год больше то false
	}
	bool operator>(const Date& x)	//Перегрузка оператора >
	{
		return !(*this < x) && *this != x;
	}
	bool operator<=(const Date& x)	//Перегрузка оператора <=
	{
		return *this < x || *this == x;
	}
	bool operator>=(const Date& x)	//Перегрузка оператора >=
	{
		return *this > x || *this == x;
	}
	Date& operator=(const Date& x)	//Перегрузка оператора =
	{
		if (*this != x) {
			d = x.d;
			m = x.m;
			y = x.y;
		}
		else return *this;
	}
	Date operator+(int x)	//Перегрузка оператора +
	{
		if (x < 0) {						//Если x отрицательно, то возвращается вычитание
			return *this - x;
		}
		Date tmp(*this);					//Создаётся копия
		int MaxDay = tmp.DaysInMonth();		//Вычисляется максимальное количество дней в данном месяце
		if (tmp.d + x > MaxDay) {			//Если после сложение мы выйдем за пределы месяца, то
			x -= MaxDay - tmp.d + 1;		//уменьшаем x и увеличиваем месяц на один, учитывая переход на новый год
			if (tmp.m + 1 > 12) {			
				tmp.m = Month(1);
				tmp.y += 1;
			}
			else tmp.m = Month(tmp.m + 1);
			MaxDay = tmp.DaysInMonth();		//Вычисляется максимальное количество дней в новом месяце
			while (x / MaxDay) {			//Пока x больше максимального числа дней в месяце
				x -= MaxDay;				//уменьшаем x и увеличиваем месяц на один, учитывая переход на новый год
				if (tmp.m + 1 > 12) {
					tmp.m = Month(1);
					tmp.y += 1;
				}
				else tmp.m = Month(tmp.m + 1);
				MaxDay = tmp.DaysInMonth();	//Вычисляется максимальное количество дней в новом месяце
			}
			tmp.d = 1;						//Дальше прибавляем оставшееся количество дней к 1
			if (x != 0)
				tmp.d += x;
		}
		else tmp.d += x;
		return tmp;							//Возвращается изменённая копия *this
	}
	Date operator-(int x)	//Перезрузка оператора -
	{
		if (x < 0) {
			return *this - x;
		}
		Date tmp (*this);
		int MaxDay = tmp.DaysInMonth();
		if (x > tmp.d) {
			x -= tmp.d;
			if (tmp.m - 1 < 1) {
				tmp.m = Month(12);
				tmp.y -= 1;
			}
			else tmp.m = Month(tmp.m - 1);
			MaxDay = tmp.DaysInMonth();
			while (x / MaxDay) {
				x -= MaxDay;
				if (tmp.m - 1 < 1) {
					tmp.m = Month(12);
					tmp.y -= 1;
				}
				else tmp.m = Month(tmp.m - 1);
				MaxDay = tmp.DaysInMonth();
			}
			tmp.d = MaxDay - x;
		}
		else if (x == tmp.d) {
			if (tmp.m - 1 < 1) {
				tmp.m = Month(12);
				tmp.y -= 1;
			}
			else tmp.m = Month(tmp.m - 1);
			MaxDay = tmp.DaysInMonth();
			tmp.d = MaxDay;
		}
		else tmp.d -= x;
		return tmp;
	}
	Date& operator+=(int x)	//Перегрузка оператора +=
	{
		return *this = *this + x;

	}
	Date& operator-=(int x)	//Перегрузка оператора -=
	{
		return *this = *this - x;
	}

protected:		//Отличие от private в том, что protected даёт допуск к своим данным дочерним классам
	const vector<int> DayCount = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	const vector<int> DayCountLeap = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	void CheckDate()
	{
		CheckYear();
		CheckMonth();
		CheckDay();
	}
	void CheckDay()
	{
		if ((d < 1) || (d > DaysInMonth())) {
			cerr << "incorrect day! ";
			system("pause");
			exit(0);
		}
	}
	void CheckMonth()
	{
		if ((m < 1) || (m > 12)) {
			cerr << "incorrect month! ";
			system("pause");
			exit(0);
		}
	}
	void CheckYear()
	{
		if (y < 1) {
			cerr << "incorrect year! ";
			system("pause");
			exit(0);
		}
	}
	int d;
	Month m;
	int y;
};

ostream& operator<<(ostream& os, Date& x)
{
	char old_fill = os.fill('0');
	return os << setw(2) << x.GetDay() << '.' << setw(2) << x.GetMonth() << '.' << setw(4) << x.GetYear() << setfill(old_fill);
}

istream& operator>>(istream& is, Date& x)
{
	int d1, m1, y1;
	is >> d1 >> m1 >> y1;
	if (!is)
		return is;
	try {
		x = Date(d1, Date::Month(m1), y1);
	}
	catch (...) {}
	return is;
}
#endif // !Date_H