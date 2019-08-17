#include <iostream> // подключение библиотеки
using namespace std;

int main()

{
	const double m_per_sec_per_km_per_hour = 3.6; // м/с в км/ч
	double speed;
	char unit; //единица измерения
	cout << "Vvedite velichinu skorosti i edinicu izmereniya:\n";
	while (cin >> speed >> unit) // ввод данных
	   { // блок выражения
		if (unit == 'm') // 'm' - метры в секунду
			cout << speed << "m_per_sec == " << speed * m_per_sec_per_km_per_hour << "km_per_hour\n";
		else (unit == 'k') // 'k' - км в час
			cout << speed << "km_per_hour == " << speed/m_per_sec_per_km_per_hour << "m_per_sec\n";
	   }
	return 0;
}
