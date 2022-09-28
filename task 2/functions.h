#pragma once
#include <iostream>
#include <locale.h>
#include <fstream>
#include <istream>
#include <string>

using namespace std;

struct readerSub {
	unsigned int number;
	char name[200];
	char address[200];
};

void convertTxtToBin(ifstream& textFile, ofstream& binFile, int &subsAmount) 
{
	subsAmount = 0;
	while (!textFile.eof()) {
		readerSub r;
		string name, address;
		textFile >> r.number;
		textFile.get();
		getline(textFile, name);
		getline(textFile, address);
		strcpy_s(r.name, name.c_str());
		strcpy_s(r.address, address.c_str());
		binFile.write((char*)&r, sizeof(readerSub));
		subsAmount += 1;
	}
	textFile.close();
	binFile.close();
}

void convertBinToTxt(ofstream& textFile, ifstream& binFile)
{
	readerSub r;
	binFile.read((char*)&r, sizeof(readerSub));
	while (binFile.good()) {
		textFile << r.number << '\n' << r.name << '\n' << r.address;
		binFile.read((char*)&r, sizeof(readerSub));
		if (!binFile.eof())
			textFile << '\n';
	}
}

void outputBinFile(ifstream& binFile)
{
	readerSub r;
	binFile.read((char*)&r, sizeof(readerSub));
	while (!binFile.eof()) {
		cout << r.number << " " << r.name << " " << r.address << '\n';
		binFile.read((char*)&r, sizeof(readerSub));
	}
}

string getSubByNum(ifstream& binFile, int num)
{
	readerSub r;
	string value = "";
	num -= 1;
	binFile.seekg(sizeof(r) * num, ios::beg);
	binFile.read((char*)&r, sizeof(readerSub));
	value += to_string(r.number) + " " + r.name + " " + r.address;
	return value;
}

string getSubByKey(ifstream& binFile, int key)
{
	readerSub r;
	string value;
	while (binFile.good()) {
		binFile.read((char*)&r, sizeof(readerSub));
		if (r.number == key)
		{
			value += to_string(r.number) + " " + r.name + " " + r.address;
			return value;
		}
	}
	return "Данного ключа нет в файле";
}

string delSubByKey(ifstream& binFile, int key, string binFileName)
{
	readerSub r;
	ofstream tempBinFile;
	bool check = false;
	tempBinFile.open("tempBin.dat", ios::out | ios::binary);
	binFile.read((char*)&r, sizeof(readerSub));
	while (binFile.good()) {
		if (r.number == key)
			check = true;
		else
			tempBinFile.write((char*)&r, sizeof(readerSub));
		binFile.read((char*)&r, sizeof(readerSub));
	}
	binFile.close();
	remove(binFileName.c_str());
	tempBinFile.close();
	rename("tempBin.dat", binFileName.c_str());
	if (check)
		return "Запись удалена";
	else
		return "Данного ключа нет в файле";
}

void delSubByNum(ifstream& binFile, int num, string binFileName)
{
	readerSub r;
	ofstream tempBinFile;
	int i = 1;
	tempBinFile.open("tempBin.dat", ios::out | ios::binary);
	binFile.read((char*)&r, sizeof(readerSub));
	while (binFile.good()) {
		if (i != num)
			tempBinFile.write((char*)&r, sizeof(readerSub));
		binFile.read((char*)&r, sizeof(readerSub));
		i++;
	}
	binFile.close();
	remove(binFileName.c_str());
	tempBinFile.close();
	rename("tempBin.dat", binFileName.c_str());
}

string delSubByKeyWithReplace(ifstream& binFile, int key, string binFileName, int subsAmount)
{
	readerSub r, r1;
	ofstream tempBinFile;
	bool check = false;
	tempBinFile.open("tempBin.dat", ios::out | ios::binary);
	binFile.seekg(sizeof(r) * (subsAmount - 1), ios::beg);
	binFile.read((char*)&r1, sizeof(readerSub));
	binFile.seekg(sizeof(r) * 0, ios::beg);
	binFile.read((char*)&r, sizeof(readerSub));
	while (binFile.good())
	{
		if (r.number == key)
		{
			check = true;
			tempBinFile.write((char*)&r1, sizeof(readerSub));
		}
		else
			tempBinFile.write((char*)&r, sizeof(readerSub));
		binFile.read((char*)&r, sizeof(readerSub));
	}
	binFile.close();
	remove(binFileName.c_str());
	tempBinFile.close();
	rename("tempBin.dat", binFileName.c_str());
	binFile.open(binFileName, ios::in | ios::binary);
	delSubByNum(binFile, subsAmount, binFileName);
	if (check)
		return "Запись удалена";
	else
		return "Данного ключа нет в файле";
}
