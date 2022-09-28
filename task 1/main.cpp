#include <locale.h>
#include "functions.h"

int main() {
	setlocale(LC_ALL, "Rus");
	int switchNum;
	string name;
	cout << "������� ��� �����: ";
	cin >> name;
	name += ".txt";
	cout << "�������� ����� �������:\n"
		"1. ������� ����\n"
		"2. ������� ����\n"
		"3. �������� ����� ������ � ����� �����\n"
		"4. ��������� �������� ����� �� ������\n"
		"5. ���������� ���������� ����� � �����\n"
		"6. ������� �������� ������, ����� �������� ������ �����, �������� ������� � �������������� ������, ������ ��� ��� ���������� �����.\n"
		"0. ��� ���������� ������\n"
		"��� �����: ";
	while (true) {
		cin >> switchNum;
		switch (switchNum) {
		case 1:
			cout << "������� ���������� ����� �����, � ����� ���������� �����:\n";
			createFile(name);
			break;
		case 2:
			outputFile(name);
			break;
		case 3:
			cout << "������� ���������� ������:\n";
			addStr(name);
			break;
		case 4:
			int num;
			cout << "������� ����� �����: ";
			cin >> num;
			cout << "������� �����: " << getValueByNum(name, num) << '\n';
			break;
		case 5:
			cout << "���������� ����� � �����: " << getAmount(name) << '\n';
			break;
		case 6:
			cout << "������� ����� ������: ";
			personalTask(name);
			break;
		case 0:
			return 0;
		default:
			cout << "��� ������ ������!\n";
			break;
		}
		cout << "�������� ��������� �����: ";
	}
}
