#include"Page.h"



Pages::Pages()
{
	Title = 0;
	timeline = 0;
	totalTimeline = 0;
}
Pages::~Pages()
{
	delete[] Title;
	if (timeline != 0)
		delete[] timeline;
}

void Pages::ReadDataFromFile(ifstream& inp)
{
	char temp[50];
	inp >> temp;
	char* ptr;
	Helper::GetStringFromBuffer(temp, ptr);
	SetID(ptr);
	inp.ignore();
	inp.getline(temp, 50, '\n');
	Helper::GetStringFromBuffer(temp, Title);
	//delete[]ptr;
	//ptr= 0;
}

void Pages::PrintForHome()
{
	cout << Title;
}

void Pages::AddPostToTimeline(Post* ptr)
{
	if (totalTimeline == 0)
	{
		timeline = new Post * [10];
		for (int i = 0; i < 10; i++)
		{
			timeline[i] = 0;
		}
		timeline[totalTimeline] = ptr;
		totalTimeline++;
	}
	else
	{
		timeline[totalTimeline] = ptr;
		totalTimeline++;
	}
}

void Pages::CheckDate(Date CurrentDate, bool isMemory)
{
	bool temp = false;
	for (int i = 0; i < totalTimeline; i++)
	{
		if (timeline[i]->CompareDate(CurrentDate, isMemory))
		{
			timeline[i]->Print(temp);
		}
	}
}

void Pages::Print()
{

	cout << this->GetID() << "\t" << Title << endl;
}

void Pages::ViewTimeline()
{
	bool temp = false;
	if (timeline != 0)
	{
		for (int i = 0; i < totalTimeline; i++)
		{
			timeline[i]->Print(temp);
		}
	}
}


char* Pages::GetId()///changed from GetId
{
	return this->GetID();
}
char* Pages::GetID()
{
	return Object::GetID();
}