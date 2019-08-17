#include <fstream>
#include <string>
#include <iostream>

using namespace std;

bool isdigit(char str) {
	return 0 <= str && str <= 9;
}

int main()
{
	setlocale(LC_ALL, "rus");	//��� ��������� ���������		
	string str;			//����� �������� ���� ��������� �� ���� ������
	string val;			//����� �������� ���� ����� 
	ifstream fin("����� ��� ��.txt");	//������ �����
	if (!fin.is_open()) {
		cout << "������ ����� �� ����������!\n";
		system("pause");
		return 1;
	}
	ofstream new_fout("�������� ������ ��.txt");	//������ ���� ��� ���������� ��� �����������
	while (getline(fin, str)) {		//������� ����� � ����� � str
		for (int i = 0; i < str.length(); ++i) {		//����������� �� ������� ������� ������
		//unsigned char ��������� ��� ���������� ���������, �.�. ��������� ������ �� ������� ����������
			if (isdigit((unsigned char)str[i])) {
				val += str[i];		//������� � ������ val ��������� �����
				str.erase(i, 1);	//������� ��� ����� �� str
				--i;	//�������� ������� �� 1, �.�. ������ str �����������
				if ((i != str.length() - 1) && !(isdigit((unsigned char)str[i + 1]))) {
					val += ',';		//���������� �������, ���� i - �� ��������� ������ � ���� ����. ������ �� �����
				}
			}
		}
		new_fout << str << '\n';		//������� � ���� ������ � ������ �� �����
	}
	new_fout << val;
	fin.close();		
	new_fout.close();
	return 0;
}
