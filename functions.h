#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

using namespace std;

void ShowInfo(const char* path) { //����� ������ �� �����
	fstream file_read(path, fstream::in);
	string temp;
	while (!file_read.eof()) {
		temp = "";
		getline(file_read, temp);
		cout << temp << endl;
	}
}
void SetInfo(ofstream& write, int k) { //���� k ��������� ������
	PairOfNumbers a;
	for (int i = 0; i < k; ++i) {
		cout << "������� ������ ������� (����� ������): ";
		cin >> a;
		write << a;
		write << '\n';
	}
	cout << endl;
}
void deleteValue(const char* path, string value) { //������� ��� ������ ������ value
	fstream temp("temp", fstream::out); //������ �����
	fstream file_read(path, fstream::in); //������ �����
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
	temp.close(); file_read.close(); //������� �����
	remove(path); //������� ���� � ��������� path
	rename("temp", path); //������������� ��������� ���� � ����������� ��������
}
void addConst(const char* path, string key, string value) { //��������� value � ������ ������ key
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
void addElements(const char* path, int number, int k) { //���������� k ��������� ����� ���������� ������ 
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
				cout << "������� ������ ������� (����� ������): ";
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

