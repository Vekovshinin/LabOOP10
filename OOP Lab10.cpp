#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#include"PairOfNumbers.h"
#include"functions.h"

using namespace std;


int main() {
	system("chcp 1251 > null");
	ofstream file_write;

	file_write.open("File.txt");
	cout << "Ввдеите количество объектов: ";
	int k; cin >> k;
	SetInfo(file_write, k);
	file_write.close();
	k = 0;
	while (k != 4) {
		system("cls");
		ShowInfo("File.txt"); cout << endl;
		cout << "Выберите пункт в меню: " << endl;
		cout << "1. Удалить все записи меньшие заданного значения\n";
		cout << "2. Увеличить все строки с заданным значением на число k\n";
		cout << "3. Добавить k записей после элемента с заданным номером\n";
		cout << "4. Выход\n";
		cin >> k;
		string value, Const, AddConst;
		int number, Count;
		system("cls");
		switch (k) {
		case 1:
			cout << "Введите значение: ";
			cin >> value;
			deleteValue("File.txt", value);
			break;
		case 2:
			cout << "Введите заданное значение: "; cin >> Const;
			cout << "Введите k: "; cin >> AddConst;
			addConst("File.txt", Const, AddConst);
		case 3:
			cout << "Введите k: "; cin >> Count;
			cout << "Введите номер элемента: "; cin >> number;
			addElements("File.txt", number, Count);
			break;
		case 4: k = 4; break;
		}
	}

}