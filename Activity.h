#pragma once
#ifndef ACTIVITY_H
#define ACTIVITY_H

#include"Manager.h"
#include<fstream>
#include<iostream>
using namespace std;

class Activity
{
	int type;
	char* value;
public:
	Activity();
	~Activity();
	void Print();
	void ReadDataFromFile(ifstream& inp);
	void SetValue(char* text);

};
#endif
