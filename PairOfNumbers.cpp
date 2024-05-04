#pragma once
#include "PairOfNumbers.h"
#include<fstream>
PairOfNumbers::PairOfNumbers() {
	firstNumber = 0;
	secondNumber = 0;
}
PairOfNumbers::PairOfNumbers(int firstNumber, double secondNumber) {
	this->firstNumber = firstNumber;
	this->secondNumber = secondNumber;
}
PairOfNumbers& PairOfNumbers::operator -(PairOfNumbers& a) {
	PairOfNumbers temp;
	temp.firstNumber = this->firstNumber - a.firstNumber;
	temp.secondNumber = this->secondNumber - a.secondNumber;
	return temp;
}
PairOfNumbers& PairOfNumbers:: operator+(int a) {
	this->firstNumber += a;
	return *this;
}
PairOfNumbers& PairOfNumbers:: operator+(double a) {
	this->secondNumber += a;
	return *this;
}
void PairOfNumbers::GetInfo() {
	cout << firstNumber << " : " << secondNumber;
}
ostream& operator << (ostream& os, const PairOfNumbers & a) {
	os << a.firstNumber << " : " << a.secondNumber;
	return os;
}
istream& operator >> (istream& is, PairOfNumbers& a) {
	is >> a.firstNumber >> a.secondNumber;
	return is;
}
int PairOfNumbers::getFirstNumber() {
	return this->firstNumber;
}
double PairOfNumbers::getSecondNumber() {
	return this->secondNumber;
}