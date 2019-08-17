// ������.cpp
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

long double fact(int n)					//������� ���������� ���������� 
{										//����� n.
	if (n < 0)							//����������� ��� ����� n	
		return 0;
	if (n == 0)							
		return 1;
	else
		return n * fact(n - 1);			//��������� ����� n �� ��������� (n-1)
}


int main()
{
	double x;
	double alpha;
	double an;
	double En;
	string yas_no;
	while (cout << "Continue? (Y/N)> ") {				//����������� ������ (��� ��������)
		cin >> yas_no;
		if (yas_no == "Y" || yas_no == "y") {
			cout << "Enter x: " << endl;				
			cin >> x;									//���� ����� "�"
			cout << "Enter alpha: " << endl;
			cin >> alpha;								//���� ����� "alpha"
			double Sn = 1;								//���������� �����, ���������� ������ 1
			if (alpha - (int)alpha == 0) {						//���� "alpha" - ����� �����, ��
				for (int n = 2; n <= alpha; ++n) {					//����������� ����� �� "n" �� "alpha"
					an = (pow(-1, n + 1) * (n - 1) * pow(x, n)) / fact(n);				//����������� "�", ��������� �� "n"
					Sn += an;															//����������� � ����� "�"
					double an1;
					an1 = (pow(-1, n + 2) * n * pow(x, n + 1)) / fact(n + 1);			//���������� ���������� ����� "�"
					En = abs(an1 / Sn);													//���������� �����������
					cout << "n = " << n << "   " << "an = " << an						//����� ��������
						 << "   " << "Sn = " << Sn << "   " << "En = " << En << endl;
				}
			}
			else {										//���� "alpha" - ������� �����, ��
				int n = 2;								//����������� ����� �� ��� ���, 
				do {									//���� ����������� �� ������ ������ "alpha"
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





