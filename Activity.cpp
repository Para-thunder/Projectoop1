#include"Activity.h"

Activity::Activity()
{
	type = 0;
	value = 0;
}
Activity::~Activity()
{
	delete[]value;
}
void Activity::Print()
{
	if (type == 1)
	{
		cout << "feeling " << value;

	}

	else if (type == 2)
	{
		cout << "thinking about " << value;
	}
	else if (type == 3)
	{
		cout << "Making " << value;
	}
	else if (type == 4)
	{
		cout << "celebrating " << value;
	}
}

void Activity::ReadDataFromFile(ifstream& inp)
{
	char temp[100];
	inp >> type;
	inp.getline(temp, '100');
	Manager::GetString(temp, value);
}

void Activity::SetValue(char* text)
{
	Manager::GetString(text, value);
}