#include <locale.h>
#include "functions.h"


int main() {
	setlocale(LC_ALL, "Rus");
	int switchNum, subsAmount = 0;
	ifstream textFileIf, binFileIf;
	ofstream binFileOf, textFileOf;
	string binFileName;
	cout << "Введите имя двоичного файла: ";
	getline(cin, binFileName);
	binFileName += ".dat";
	binFileOf.open(binFileName, ios::out | ios::binary);


	if (!binFileOf)
	{
		cout << "файл не открыт";
		return 1;
	}
	binFileOf.close();

	cout << "Выберите номер задания:\n"
		"1. Преобразовать тестовые данные из текстового файла в двоичный файл\n"
		"2. Преобразовать тестовые данные из двоичного файла в текстовый файл\n"
		"3. Вывести все записи двоичного файла\n"
		"4. Получить доступ к записи по ее порядковому номеру\n"
		"5. Удалить запись по ключу, заменив ее на последнюю запись\n"
		"6. Найти запись по ключу\n"
		"7. Удалить запись по ключу\n"
		"0. Для завершения работы\n"
		"Ваш выбор: ";
	while (true) {
		cin >> switchNum;
		switch (switchNum) {
		case 1:
			textFileIf.open("subs.txt", ios::out);
			binFileOf.open(binFileName, ios::out | ios::binary);
			if (!textFileIf || !binFileOf)
			{
				cout << "файл не открыт";
				return 1;
			}
			convertTxtToBin(textFileIf, binFileOf, subsAmount);
			cout << "Файл преобразован!\n";
			textFileIf.close();
			binFileOf.close();
			break;
		case 2:
			binFileIf.open(binFileName, ios::in | ios::binary);
			textFileOf.open("subs.txt");
			if (!binFileIf || !textFileOf)
			{
				cout << "файл не открыт";
				return 1;
			}
			convertBinToTxt(textFileOf, binFileIf);
			textFileOf.close();
			binFileIf.close();
			cout << "Файл преобразован!\n";
			break;
		case 3:
			binFileIf.open(binFileName, ios::in | ios::binary);
			if (!binFileIf)
			{
				cout << "файл не открыт";
				return 1;
			}
			outputBinFile(binFileIf);
			binFileIf.close();
			break;
		case 4:
			binFileIf.open(binFileName, ios::in | ios::binary);
			if (!binFileIf)
			{
				cout << "файл не открыт";
				return 1;
			}
			int num;
			cout << "Введите номер записи: ";
			cin >> num;
			if (num > subsAmount || num <= 0)
				cout << "Данного номера нет в файле\n";
			else {
				cout << getSubByNum(binFileIf, num) << '\n';
				binFileIf.close();
			}
			break;
		case 5:
			binFileIf.open(binFileName, ios::in | ios::binary);
			if (!binFileIf)
			{
				cout << "файл не открыт";
				return 1;
			}
			int key;
			cout << "Введите ключ: ";
			cin >> key;
			cout << delSubByKeyWithReplace(binFileIf, key, binFileName, subsAmount) << '\n';
			binFileIf.close();
			subsAmount -= 1;
			break;
		case 6:
			binFileIf.open(binFileName, ios::in | ios::binary);
			if (!binFileIf)
			{
				cout << "файл не открыт";
				return 1;
			}
			cout << "Введите ключ: ";
			cin >> key;
			cout << getSubByKey(binFileIf, key) << '\n';
			binFileIf.close();
			break;
		case 7:
			binFileIf.open(binFileName, ios::in | ios::binary);
			if (!binFileIf)
			{
				cout << "файл не открыт";
				return 1;
			}
			cout << "Введите ключ: ";
			cin >> key;
			cout << delSubByKey(binFileIf, key, binFileName) << '\n';
			binFileIf.close();
			subsAmount -= 1;
			break;
			break;
		case 0:
			return 0;
		default:
			cout << "Нет такого номера!\n";
			break;
		}
		cout << "\nВыберите следующий номер: ";
	}
}