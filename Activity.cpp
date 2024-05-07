#include"Activity.h"



Activity::Activity()
{
	type = 0;
	value = "";
}
Activity::~Activity() {

}
void Activity::Print()
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
void Activity::ReadDataFromFile(ifstream& inp)
{
	getline(inp, value);
}
void Activity::SetValue(string& text)
{
	value = text;
}