// ЛабаЯП.cpp
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

long double fact(int n)					//Функция вычисления факториала 
{										//числа n.
	if (n < 0)							//Ограничение для числа n	
		return 0;
	if (n == 0)							
		return 1;
	else
		return n * fact(n - 1);			//умножение числа n на факториал (n-1)
}


int main()
{
	double x;
	double alpha;
	double an;
	double En;
	string yas_no;
	while (cout << "Continue? (Y/N)> ") {				//Продолжение работы (для удобства)
		cin >> yas_no;
		if (yas_no == "Y" || yas_no == "y") {
			cout << "Enter x: " << endl;				
			cin >> x;									//Ввод числа "х"
			cout << "Enter alpha: " << endl;
			cin >> alpha;								//Ввод числа "alpha"
			double Sn = 1;								//Объявление суммы, изначально равной 1
			if (alpha - (int)alpha == 0) {						//Если "alpha" - целое число, то
				for (int n = 2; n <= alpha; ++n) {					//вычисляется сумма от "n" до "alpha"
					an = (pow(-1, n + 1) * (n - 1) * pow(x, n)) / fact(n);				//Вычисляется "а", зависящее от "n"
					Sn += an;															//Прибавление к сумме "а"
					double an1;
					an1 = (pow(-1, n + 2) * n * pow(x, n + 1)) / fact(n + 1);			//Вычисление следующего члена "а"
					En = abs(an1 / Sn);													//Вычисление погрешности
					cout << "n = " << n << "   " << "an = " << an						//Вывод значений
						 << "   " << "Sn = " << Sn << "   " << "En = " << En << endl;
				}
			}
			else {										//Если "alpha" - дробное число, то
				int n = 2;								//вычисляется сумма до тех пор, 
				do {									//пока погрешность не станет меньше "alpha"
					an = (pow(-1, n + 1) * (n - 1) * pow(x, n)) / fact(n);
					Sn += an;
					double an1;
					an1 = (pow(-1, n + 2) * n * pow(x, n + 1)) / fact(n + 1);
					En = abs(an1 / Sn);
					cout << "n = " << n << "   " << "an = " << an 
						 << "   " << "Sn = " << Sn << "   " << "En = " << En << endl;
					++n;
				} while (En > alpha);
			}
		}
		if (yas_no == "N" || yas_no == "n") {
			system("pause");
			return 0;
		}
	}
}





