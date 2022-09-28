#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createFile(string name)
{
	ofstream file;
	int k;
	string str;
	file.open(name);
	if (file.is_open()) {
		cin >> k;
		cin.ignore();
		for (int i = 0; i < k; i++) {
			getline(cin, str);
			file << str << '\n';
		}
		file.close();
	}
}

void outputFile(string name)
{
	ifstream file;
	char c;
	file.open(name);
	if (file.is_open()) {
		while (file.get(c)) {
			cout << c;
		}
		file.close();
	}
}

void addStr(string name)
{
	ofstream file;
	string str;
	file.open(name, ofstream::app);
	if (file.is_open()) {
		cin.ignore();
		getline(cin, str);
		file << str << '\n';
		file.close();
	}
}

int getValueByNum(string name, int num)
{
	ifstream file;
	int value;
	file.open(name);
	if (file.is_open()) {
		for (int i = 0; i < num; i++) {
			file >> value;
		}
		return value;
		file.close();
	}
}

int getAmount(string name)
{
	ifstream file;
	int value, amount = 0;
	file.open(name);
	if (file.is_open()) {
		while (file >> value) {
			amount++;
		}
		return amount;
	}
}

void personalTask(string name)
{
	string str;
	int num, i = 1;
	ifstream file;
	file.open(name);
	ofstream newFile;
	newFile.open("newText.txt");
	if (file.is_open() && newFile.is_open()) {
		cin >> num;
		while (getline(file, str)) {
			if (num == i)
				i++;
			else {
				newFile << str << '\n';
				i++;
			}
		}
		file.close();
		remove(name.c_str());
		newFile.close();
		rename("newText.txt", name.c_str());
	}
}