#include <locale.h>
#include "functions.h"


int main() {
	setlocale(LC_ALL, "Rus");
	int switchNum, subsAmount = 0;
	ifstream textFileIf, binFileIf;
	ofstream binFileOf, textFileOf;
	string binFileName;
	cout << "������� ��� ��������� �����: ";
	getline(cin, binFileName);
	binFileName += ".dat";
	binFileOf.open(binFileName, ios::out | ios::binary);


	if (!binFileOf)
	{
		cout << "���� �� ������";
		return 1;
	}
	binFileOf.close();

	cout << "�������� ����� �������:\n"
		"1. ������������� �������� ������ �� ���������� ����� � �������� ����\n"
		"2. ������������� �������� ������ �� ��������� ����� � ��������� ����\n"
		"3. ������� ��� ������ ��������� �����\n"
		"4. �������� ������ � ������ �� �� ����������� ������\n"
		"5. ������� ������ �� �����, ������� �� �� ��������� ������\n"
		"6. ����� ������ �� �����\n"
		"7. ������� ������ �� �����\n"
		"0. ��� ���������� ������\n"
		"��� �����: ";
	while (true) {
		cin >> switchNum;
		switch (switchNum) {
		case 1:
			textFileIf.open("subs.txt", ios::out);
			binFileOf.open(binFileName, ios::out | ios::binary);
			if (!textFileIf || !binFileOf)
			{
				cout << "���� �� ������";
				return 1;
			}
			convertTxtToBin(textFileIf, binFileOf, subsAmount);
			cout << "���� ������������!\n";
			textFileIf.close();
			binFileOf.close();
			break;
		case 2:
			binFileIf.open(binFileName, ios::in | ios::binary);
			textFileOf.open("subs.txt");
			if (!binFileIf || !textFileOf)
			{
				cout << "���� �� ������";
				return 1;
			}
			convertBinToTxt(textFileOf, binFileIf);
			textFileOf.close();
			binFileIf.close();
			cout << "���� ������������!\n";
			break;
		case 3:
			binFileIf.open(binFileName, ios::in | ios::binary);
			if (!binFileIf)
			{
				cout << "���� �� ������";
				return 1;
			}
			outputBinFile(binFileIf);
			binFileIf.close();
			break;
		case 4:
			binFileIf.open(binFileName, ios::in | ios::binary);
			if (!binFileIf)
			{
				cout << "���� �� ������";
				return 1;
			}
			int num;
			cout << "������� ����� ������: ";
			cin >> num;
			if (num > subsAmount || num <= 0)
				cout << "������� ������ ��� � �����\n";
			else {
				cout << getSubByNum(binFileIf, num) << '\n';
				binFileIf.close();
			}
			break;
		case 5:
			binFileIf.open(binFileName, ios::in | ios::binary);
			if (!binFileIf)
			{
				cout << "���� �� ������";
				return 1;
			}
			int key;
			cout << "������� ����: ";
			cin >> key;
			cout << delSubByKeyWithReplace(binFileIf, key, binFileName, subsAmount) << '\n';
			binFileIf.close();
			subsAmount -= 1;
			break;
		case 6:
			binFileIf.open(binFileName, ios::in | ios::binary);
			if (!binFileIf)
			{
				cout << "���� �� ������";
				return 1;
			}
			cout << "������� ����: ";
			cin >> key;
			cout << getSubByKey(binFileIf, key) << '\n';
			binFileIf.close();
			break;
		case 7:
			binFileIf.open(binFileName, ios::in | ios::binary);
			if (!binFileIf)
			{
				cout << "���� �� ������";
				return 1;
			}
			cout << "������� ����: ";
			cin >> key;
			cout << delSubByKey(binFileIf, key, binFileName) << '\n';
			binFileIf.close();
			subsAmount -= 1;
			break;
			break;
		case 0:
			return 0;
		default:
			cout << "��� ������ ������!\n";
			break;
		}
		cout << "\n�������� ��������� �����: ";
	}
}