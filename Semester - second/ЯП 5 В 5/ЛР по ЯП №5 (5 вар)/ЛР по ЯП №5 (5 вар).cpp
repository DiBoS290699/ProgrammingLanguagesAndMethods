// ЛР по ЯП №5 (5 вар).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Date.h"
#include "Holiday.h"
using namespace std;

int main()
{
	Date x;
	cout << "--------DATE---------\n";
	cout << "\nTesting: >> and <<\n";
	cin >> x;
	cout << x;
	cout << "\nTesting: GetDay\n" << x.GetDay();
	cout << "\nTesting: GetMonth\n" << x.GetMonth();
	cout << "\nTesting: GetYear\n" << x.GetYear();
	cout << "\nTesting: GetLeapYear\n" << x.GetLeapYear();
	cout << "\nTesting: DayNumber\n" << x.DayNumber();
	cout << "\nTesting: y_m_d\n";
	x.y_m_d(cout);
	cout << "\nTesting: m_d_y\n";
	x.m_d_y(cout);
	cout << "\nTesting: <\n" << "x < 01.02.2018 -> " << (x < Date(1, Date::feb, 2018) ? "Yes" : "No");
	cout << "\nTesting: >\n" << "x > 01.02.2018 -> " << (x > Date(1, Date::feb, 2018) ? "Yes" : "No");
	cout << "\nTesting: ==\n" << "x == 23.02.2018 -> " << (x == Date(23, Date::feb, 2018) ? "Yes" : "No");
	cout << "\nTesting: !=\n" << "x != 23.02.2018 -> " << (x != Date(23, Date::feb, 2018) ? "Yes" : "No");
	cout << "\nTesting: <=\n" << "x <= 23.02.2018 -> " << (x <= Date(23, Date::feb, 2018) ? "Yes" : "No");
	cout << "\nTesting: >=\n" << "x >= 23.02.2018 -> " << (x >= Date(23, Date::feb, 2018) ? "Yes" : "No");
	Date x1 = x;
	cout << "\nTesting: =\n" << x1;
	cout << "\nTesting: +\n" << "x + 6 -> " << x + 6;
	cout << "\nTesting: +\n" << "x + 37 -> " << x + 37;
	cout << "\nTesting: -\n" << "x - 54 -> " << x - 54;
	x += 6;
	cout << "\nTesting: +=\n" << "x += 6 -> " << x;
	x -= 6;
	cout << "\nTesting: -=\n" << "x -= 6 -> " << x;
	cout << "\n--------HOLIDAY---------\n";
	Holiday y;
	cout << "\nTesting: Holiday()\n" << y;
	cout << "\nTesting: y.SGetHoliday()\n" << y << " -> " << y.SGetHoliday() << endl;
	Holiday y1(8, Holiday::mar, 2018);
	cout << "\nTesting: Holiday(int day, Month mon, int year)\n" << y1;
	cout << "\nTesting: y1.SGetHoliday()\n" << y1 << " -> " << y1.SGetHoliday() << endl;
	Holiday y2(x);
	cout << "\nTesting: Holiday(const Date& x)\n" << y2;
	cout << "\nTesting: y2.SGetHoliday()\n" << y2 << " -> " << y2.SGetHoliday() << endl;
	Holiday y3(y1);
	cout << "\nTesting: Holiday(const Holiday& x)\n" << y3;
	cout << "\nTesting: y3.SGetHoliday()\n" << y3 << " -> " << y3.SGetHoliday() << endl;
	system("pause");
    return 0;
}