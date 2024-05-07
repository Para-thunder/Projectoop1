#pragma once

#pragma once
#ifndef DATE_H
#define DATE_H

#include"Date.cpp"
#include<fstream>
#include<iostream>
using namespace std;

class Date
{
	int day;
	int month;
	int year;

public:

	static Date CurrentDate;

	Date(int x = 0, int y = 0, int z = 0);
	void ReadDataFromFile(ifstream& inp);
	bool compare(const Date& rhs, bool isMemory);
	static int YearDiff(Date lhs, Date rhs);
	void Print();
	void SetData(int d, int m, int y);
};

Date Date::CurrentDate = 0;
#endif
