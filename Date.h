#pragma once
#ifndef DATE_H
#define DATE_H


#include<iostream>
#include <fstream>

class Date
{
	int day;
	int month;
	int year;

public:

	static Date CurrentDate;

	Date(int, int, int);
	Date();
	void ReadDataFromFile(std::ifstream& inp);
	bool compare(const Date& rhs, bool isMemory) const;
	static int YearDiff(const Date lhs, const Date rhs);
	void Print()const;
	void SetData(int d, int m, int y);

};


#endif
