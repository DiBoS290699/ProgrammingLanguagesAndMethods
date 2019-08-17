#ifndef Holiday_H
#define Holiday_H

#include "Date.h"
#include <string>
using namespace std;

class Holiday : public Date {	//Класс праздник
public:
	Holiday() : Date() {}	
	Holiday(int day, Month mon, int year) : Date(day, mon, year) {}
	Holiday(const Date& x) : Date(x) { }
	Holiday(const Holiday& x) : Date(x) { }
	~Holiday() = default;
	string SGetHoliday()	//Возвращение текста о соответствие празднику
	{
		return (IsHoliday) ? "This is a Holiday!" : "This is not a Holiday!";
	}
	bool BGetHoliday() { return IsHoliday; }
	
private:
	bool IsHoliday = CheckHoliday();
	bool CheckHoliday()
	{
		switch (d) {
		case 1:
			return (m == 1 || m == 5);		//1 января и 1 мая
		case 4: 
			return (m == 11);				//4 ноября
		case 7:
			return (m == 1);				//7 января
		case 8:
			return (m == 3);				//8 марта
		case 9:
			return (m == 5);				//9 мая
		case 12: 
			return (m == 6);				//12 июня
		case 23:
			return (m == 2);				//23 февраля
		default:
			return false;					//Не праздник
		}
	}
};
#endif // !Holiday_H
