#pragma once
#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <iostream>
#include <fstream>
#include<string>

using namespace std;
class Activity {
	int type;
	string value;

public:
	Activity()
	{
		type = 0;
		value = "";
	}
	~Activity(){
		
	}
	void Print()
	{
		if (type == 1)
		{
			cout << " feeling " << endl;
		}
		else if (type == 2)
		{
			cout << " thinking about " << value;
		}
		else if (type == 3)
		{
			cout << "Making" << value;
		}

		else if (type == 4)
		{
			cout << " celebrating " << value;
		}
	}
	void ReadDataFromFile(ifstream& inp)
	{
		getline(inp, value);
	}
	void SetValue(string& text)
	{
		value = text;
	}
};


#endif
