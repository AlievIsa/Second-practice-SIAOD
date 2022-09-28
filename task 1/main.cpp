#include <locale.h>
#include "functions.h"

int main() {
	setlocale(LC_ALL, "Rus");
	int switchNum;
	string name;
	cout << "Введите имя файла: ";
	cin >> name;
	name += ".txt";
	cout << "Выберите номер задания:\n"
		"1. Создать файл\n"
		"2. Вывести файл\n"
		"3. Добавить новую строку в конец файла\n"
		"4. Прочитать значение числа по номеру\n"
		"5. Определить количество чисел в файле\n"
		"6. Удалить значение строки, путем создания нового файла, удаление старого и переименование нового, указав ему имя удаленного файла.\n"
		"0. Для завершения работы\n"
		"Ваш выбор: ";
	while (true) {
		cin >> switchNum;
		switch (switchNum) {
		case 1:
			cout << "Введите количество строк файла, а затем содержимое строк:\n";
			createFile(name);
			break;
		case 2:
			outputFile(name);
			break;
		case 3:
			cout << "Введите содержимое строки:\n";
			addStr(name);
			break;
		case 4:
			int num;
			cout << "Введите номер числа: ";
			cin >> num;
			cout << "Искомое число: " << getValueByNum(name, num) << '\n';
			break;
		case 5:
			cout << "Количество чисел в файле: " << getAmount(name) << '\n';
			break;
		case 6:
			cout << "Введите номер строки: ";
			personalTask(name);
			break;
		case 0:
			return 0;
		default:
			cout << "Нет такого номера!\n";
			break;
		}
		cout << "Выберите следующий номер: ";
	}
}
