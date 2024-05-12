#include"User.h"
#include"Manager.h"

Users::Users()
{
	Fname = 0;
	Lname = 0;

	LikedPages = nullptr;
	FriendList = nullptr;
	timeline = nullptr;
	totalTimeline = 0;
	numPages = 0;
	numFriends = 0;
}
Users::~Users()
{
	delete[] Fname;
	delete[] Lname;

	if (LikedPages != 0)
		delete[] LikedPages;
	if (FriendList != 0)
		delete[] FriendList;
	if (timeline != 0)
		delete[] timeline;
}


void Users::ReadDataFromFile(ifstream& inp)
{
	char temp[50];
	inp >> temp;
	char* ptr;
	Manager::GetString(temp, ptr);
	SetID(ptr);
	inp >> temp;
	Manager::GetString(temp, Fname);
	inp >> temp;
	Manager::GetString(temp, Lname);
}

void Users::SetPage(Pages* ptr)
{
	if (numPages == 0)
	{
		LikedPages = new Pages * [10];
		for (int i = 0; i < 10; i++)
		{
			LikedPages[i] = 0;
		}
	}
	LikedPages[numPages] = ptr;
	numPages++;
}

void Users::CheckDate(Date CurrentDate, bool isMemory)
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

void Users::LikePost(Post* post)
{
	post->SetLikedBy(this);
}

void Users::HomePage(Date currentDate)
{

	cout << "------------------------------------------------------------------------------" << endl;
	if (FriendList != 0)
	{
		for (int i = 0; i < numFriends; i++)
		{
			FriendList[i]->CheckDate(currentDate, false);
		}
	}

	if (LikedPages != 0)
	{
		for (int i = 0; i < numPages; i++)
		{
			LikedPages[i]->CheckDate(currentDate, false);
		}
	}
	cout << endl;
}

void Users::ViewTimeline()
{
	if (timeline != 0)
	{
		cout << "---------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < totalTimeline; i++)
		{
			if (timeline[i] != 0)
			{
				bool IsNewPost = false;
				timeline[i]->Print(IsNewPost);
				if (IsNewPost)
				{
					timeline[i]->Print();
				}
			}
		}
	}
}

void Users::SeeMemory(Date currentDate)
{
	bool temp = false;
	for (int i = 0; i < totalTimeline; i++)
	{
		if (timeline[i] != 0)
		{
			if (timeline[i]->CompareDate(currentDate, true))
			{
				timeline[i]->Print(temp);
			}
		}
	}
}

void Users::PrintForHome()
{
	cout << Fname << " " << Lname;
	//cout << name;
}

void Users::SetFriend(Users* ptr)
{
	if (numFriends == 0)
	{
		FriendList = new Users * [10];
		for (int i = 0; i < 10; i++)
		{
			FriendList[i] = 0;
		}
	}
	FriendList[numFriends] = ptr;
	numFriends++;
}

void Users::AddPostToTimeline(Post* ptr)
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

void Users::ViewFriendList()
{
	if (FriendList != 0)
	{
		cout << "---------------------------------- Friend List ----------------------------------" << endl;
		for (int i = 0; i < numFriends; i++)
		{
			cout << FriendList[i] << endl;
			FriendList[i]->Print();
		}
	}
}

void Users::ViewLikedPages()
{
	if (LikedPages != 0)
	{
		cout << "---------------------------------- Liked Pages ----------------------------------" << endl;
		for (int i = 0; i < numPages; i++)
		{
			LikedPages[i]->Print();
		}
	}
}

void Users::Print()
{
	cout << this->GetId() << "\t" << Fname << " " << Lname << endl;
	//cout << this->GetId() << "\t" << name << endl;
}

//getters
char* Users::GetId()
{
	return this->GetID();
}


