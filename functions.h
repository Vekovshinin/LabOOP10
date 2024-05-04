#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

using namespace std;

void ShowInfo(const char* path) { //вывод потока на экран
	fstream file_read(path, fstream::in);
	string temp;
	while (!file_read.eof()) {
		temp = "";
		getline(file_read, temp);
		cout << temp << endl;
	}
}
void SetInfo(ofstream& write, int k) { //ввод k элементов потока
	PairOfNumbers a;
	for (int i = 0; i < k; ++i) {
		cout << "¬ведите данные объекта (через пробел): ";
		cin >> a;
		write << a;
		write << '\n';
	}
	cout << endl;
}
void deleteValue(const char* path, string value) { //удалить все строки меньше value
	fstream temp("temp", fstream::out); //запись файла
	fstream file_read(path, fstream::in); //чтение файла
	string tmp;
	while (!file_read.eof()) {
		tmp = "";
		getline(file_read, tmp);
		if (tmp == "") break;
		string num1 = "", num2 = "";
		int count = 0;
		for (int i = 0; tmp[i] != ' '; ++i) {
			num1 += tmp[i]; count += 1;
		}
		for (int i = count + 3; i < tmp.size(); ++i)
			num2 += tmp[i];

		if (num1 >= value  && num2 >= value) {
			temp << tmp << '\n';
		}
	}
	temp.close(); file_read.close(); //закрыть файлы
	remove(path); //удалить файл с названием path
	rename("temp", path); //переименовать временный файл в изначальное название
}
void addConst(const char* path, string key, string value) { //прибавить value к числам равным key
	fstream temp("temp", fstream::out);
	fstream file_read(path, fstream::in);
	string tmp;
	while (!file_read.eof()) {
		tmp = "";
		getline(file_read, tmp);
		if (tmp == "") break;
		string num1 = "", num2 = "";
		int count = 0;
		for (int i = 0; tmp[i] != ' '; ++i) {
			num1 += tmp[i]; count += 1;
		}
		for (int i = count + 3; i < tmp.size(); ++i)
			num2 += tmp[i];
		if (num1 == key || num2 == key) {
			temp << atof(num1.c_str()) + atof(value.c_str()) << " : " << atof(num2.c_str()) + atof(value.c_str()) << '\n';
		}
		else
			temp << num1 << " : " << num2 << '\n';
	}
	temp.close(); file_read.close();
	remove(path);
	rename("temp", path);
}
void addElements(const char* path, int number, int k) { //добавление k элементов после указанного номера 
	fstream temp("temp", fstream::out);
	fstream file_read(path, fstream::in);
	string tmp;
	int count = 0;
	while (!file_read.eof()) {
		tmp = "";
		getline(file_read, tmp);
		PairOfNumbers a;
		if (count == number) {
			for (int i = 0; i < k; ++i)
			{
				cout << "¬ведите данные объекта (через пробел): ";
				cin >> a;
				temp << a;
				temp << '\n';
			}
		}
		count += 1;
		temp << tmp << '\n';
	}
	temp.close(); file_read.close();
	remove(path);
	rename("temp", path);
}

