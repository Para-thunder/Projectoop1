#include"Post.h"

Post::~Post()
{
	delete[] Id;
	delete[] text;
	if (LikedBy != 0)
		delete[] LikedBy;
	if (comments != 0)
		delete[] comments;
	if (activity != 0)
		delete activity;
}
Post::Post()
{
	Id = 0;
	text = 0;
	sharedBy = 0;
	LikedBy = 0;
	comments = 0;
	activity = 0;
	totalComment = 0;
	totalLikedBy = 0;
}
Post::Post(const char* txt, Control* SharedBy, Date currentDate)
{

	activity = 0;
	char* IdForNewPost = Manager::concate("post", TotalPosts + 1);

	Manager::GetString(IdForNewPost, Id);
	Manager::GetString(txt, text);
	sharedBy = SharedBy;
	sharedDate = currentDate;
	totalComment = 0;
	totalLikedBy = 0;
}


void  Post::SetSharedBy(Control* ptr)
{
	sharedBy = ptr;
}
void Post::SetLikedBy(Control* ptr)
{
	if (totalLikedBy == 0)
	{
		LikedBy = new Control * [10];
		for (int i = 0; i < 10; i++)
		{
			LikedBy[i] = 0;
		}
		LikedBy[totalLikedBy] = ptr;
		totalLikedBy++;
	}
	else
	{
		LikedBy[totalLikedBy] = ptr;
		totalLikedBy++;
	}
}

void  Post::AddComment(Comment* ptr)
{

	if (totalComment == 0)
	{
		comments = new Comment * [10];
		for (int i = 0; i < 10; i++)
		{
			comments[i] = nullptr;
		}
		comments[totalComment] = ptr;
		totalComment++;
	}

	else
	{
		comments[totalComment] = ptr;
		totalComment++;
	}
}

bool  Post::CompareDate(Date currentDate, bool isMemory)
{
	if (currentDate.compare(sharedDate, isMemory))
	{
		return true;
	}
	else
		return false;
}

Date  Post::GetSharedDate()
{
	return sharedDate;
}

char* Post::GetId()
{
	return Id;
}

int Post::TotalPosts = 0;


void Post::ReadDataFromFile(ifstream& inp)
{
	int activityId = 0;
	inp >> activityId;
	char temp[100];
	inp >> temp;
	Manager::GetString(temp, Id);
	sharedDate.ReadDataFromFile(inp);
	inp.ignore();
	inp.getline(temp, 100, '\n');
	Manager::GetString(temp, text);
	if (activityId == 2)
	{
		activity = new Activity;
		activity->ReadDataFromFile(inp);
	}
	TotalPosts++;


}
void Post::Print(bool& flag)
{

	sharedBy->PrintForHome();
	cout << " ";
	if (activity != 0)
	{
		activity->Print();
	}
	cout << endl;
	cout << "\"" << text << "\"";
	cout << " (";
	sharedDate.Print();
	cout << ") " << endl << "\t";
	for (int i = 0; i < totalComment; i++)
	{
		comments[i]->Print();
		cout << "\t";
	}
	cout << endl;

}
void Post::Print()
{
	sharedBy->PrintForHome();
	cout << " ";
	if (activity != 0)
	{
		activity->Print();
	}
	cout << endl;
	cout << "\"" << text << "\"";
	cout << " (";
	cout << ") " << endl << "\t";
	for (int i = 0; i < totalComment; i++)
	{
		comments[i]->Print();
		cout << "\t";
	}
	cout << endl;
}
void Post::ViewLikedList()
{
	if (LikedBy != 0)
	{
		cout << "-----------------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < totalLikedBy; i++)
		{
			LikedBy[i]->Print();
			cout << endl;
		}
	}
}