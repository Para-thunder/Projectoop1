#pragma once
#include<iostream>
using namespace std;

class Manager
{
public:

	static int StrLen(const char* str);
	static void GetString(const char* temp, char*& str);
	static bool compareString(const char* str, const char* str2);
	static char* concate(const char* str, int num);

};
