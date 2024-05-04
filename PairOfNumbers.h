#pragma once
#include<iostream>
#include<vector>
using namespace std;

class PairOfNumbers {
	int firstNumber;
	double secondNumber;
public:
	PairOfNumbers();
	PairOfNumbers(int firstNumber, double secondNumber);
	PairOfNumbers& operator -(PairOfNumbers& a);
	PairOfNumbers& operator+(int a);
	PairOfNumbers& operator+(double a);
	void GetInfo();
	friend ostream& operator << (ostream&, const PairOfNumbers&);
	friend istream& operator >> (istream&, PairOfNumbers&);
	friend void addConstStr(vector<PairOfNumbers>&, double, double);
	int getFirstNumber();
	double getSecondNumber();

};