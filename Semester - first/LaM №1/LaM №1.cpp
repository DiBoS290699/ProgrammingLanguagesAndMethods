#include <iostream> // ����������� ����������
using namespace std;

int main()

{
	const double m_per_sec_per_km_per_hour = 3.6; // �/� � ��/�
	double speed;
	char unit; //������� ���������
	cout << "Vvedite velichinu skorosti i edinicu izmereniya:\n";
	while (cin >> speed >> unit) // ���� ������
	   { // ���� ���������
		if (unit == 'm') // 'm' - ����� � �������
			cout << speed << "m_per_sec == " << speed * m_per_sec_per_km_per_hour << "km_per_hour\n";
		else (unit == 'k') // 'k' - �� � ���
			cout << speed << "km_per_hour == " << speed/m_per_sec_per_km_per_hour << "m_per_sec\n";
	   }
	return 0;
}
