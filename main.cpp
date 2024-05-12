#include<iostream>
#include"Post.h"
#include"Page.h"
#include"Manager.h"
#include<fstream>
#include"Memory.h"
using namespace std;
#include"User.h"


class Post;
class Page;
class User;
class Object;
class Comment;
class Activity;
class Manager;
class Memory;
class Date;

class FaceBook
{
	Pages** pages;
	Users** users;
	Post** posts;
	Comment** comments;

	static int totalUsers;
	static int totalPages;
	static int totalPosts;
	static int totalComments;
public:

	FaceBook()
	{
		pages = 0;
		users = 0;
		posts = 0;
		comments = 0;
	}
	~FaceBook()
	{
		for (int i = 0; i < totalPages; i++)
		{
			if (pages[i] != 0)
				delete pages[i];
		}
		delete[]pages;

		for (int i = 0; i < totalUsers; i++)
		{
			if (users[i] != 0)
				delete users[i];
		}
		delete[]users;


		for (int i = 0; i < totalPosts; i++)
		{
			if (posts[i] != 0)
				delete posts[i];
		}
		delete[]posts;
	}

	void LoadPages(const char* filename)
	{
		ifstream inp;
		inp.open(filename);
		if (inp)
		{
			inp >> totalPages;


			pages = new Pages * [totalPages];
			for (int i = 0; i < totalPages; i++)
			{
				pages[i] = new Pages;
				pages[i]->ReadDataFromFile(inp);
			}

			inp.close();
		}
	}

	void LoadUsers(const char* filename)
	{
		ifstream inp;
		inp.open(filename);
		if (inp)
		{
			inp >> totalUsers;

			users = new Users * [totalUsers];
			char*** friendList = new char** [totalUsers];
			char temp[50];

			for (int i = 0; i < totalUsers; i++)
			{
				users[i] = new Users;
				users[i]->ReadDataFromFile(inp);
				friendList[i] = new char* [10];
				for (int h = 0; h < 10; h++)
				{
					friendList[i][h] = 0;
				}
				for (int j = 0; j < 10; j++)
				{
					inp >> temp;
					if (Manager::compareString(temp, "-1"))
					{
						break;
					}
					else
						Manager::GetString(temp, friendList[i][j]);
				}
				inp.ignore();

				Pages* pointer;
				for (int j = 0; j < 10; j++)
				{
					inp >> temp;
					if (Manager::compareString(temp, "-1"))
					{
						break;
					}
					else
					{
						pointer = GetPageFromId(temp);
						users[i]->SetPage(pointer);
					}
				}

			}

			//associate friends
			Users* ptr;
			for (int j = 0; j < totalUsers; j++)
			{
				for (int k = 0; k < 10; k++)
				{
					if (friendList[j][k] == 0)
					{
						break;
					}

					ptr = GetUserFromId(friendList[j][k]);
					users[j]->SetFriend(ptr);
				}
			}

			//deallocate the 3d pointer
			for (int h = 0; h < totalUsers; h++)
			{
				if (friendList[h])
				{
					for (int g = 0; g < 10; g++)
					{
						if (friendList[h][g])
							delete[]friendList[h][g];
					}
					delete[] friendList[h];
				}

			}

			inp.close();

			if (friendList)
			{
				delete[]friendList;
			}

		}


	}

	void PrintUser(const char* str)
	{
		cout << "Set Current User " << str << endl;
		Users* ptr = GetUserFromId(str);
		ptr->Print();
	}

	Users* GetUserFromId(const char* str)
	{
		for (int i = 0; i < totalUsers; i++)
		{
			if (Manager::compareString(str, users[i]->GetId()))
			{
				return users[i];
			}
		}
		return 0;
	}

	Pages* GetPageFromId(const char* str)
	{
		for (int i = 0; i < totalPages; i++)
		{
			if (Manager::compareString(str, pages[i]->GetId()))
			{
				return pages[i];
			}
		}
		return 0;
	}

	Control* GetObjectById(char* str)
	{
		if (str[0] == 'u')
		{
			return GetUserFromId(str);
		}
		else if (str[0] == 'p')
		{
			return GetPageFromId(str);
		}
		else
			return 0;
	}

	Post* GetPostById(const char* str)
	{
		for (int i = 0; i < totalPosts; i++)
		{
			if (Manager::compareString(str, posts[i]->GetId()))
			{
				return posts[i];
			}
		}

		return 0;
	}

	void LoadPosts(const char* filename)
	{
		ifstream inp;
		inp.open(filename);
		char temp[100];
		if (inp)
		{
			inp >> totalPosts;
			posts = new Post * [totalPosts];
			for (int i = 0; i < totalPosts; i++)
			{
				posts[i] = new Post;
				posts[i]->ReadDataFromFile(inp);
				inp >> temp;
				Control* sharedBy = GetObjectById(temp);
				posts[i]->SetSharedBy(sharedBy);
				sharedBy->AddPostToTimeline(posts[i]);
				inp >> temp;

				for (int j = 0; temp[0] != '-'; j++)
				{
					posts[i]->SetLikedBy(GetObjectById(temp));
					inp.ignore();
					inp >> temp;
				}
			}
		}
		inp.close();
	}

	void LoadComments(const char* filename)
	{
		ifstream inp;
		inp.open(filename);

		if (inp)
		{
			inp >> totalComments;

			char tempId[100], strText[100], temp[50], tempPost[50];
			Control* commentBy;

			comments = new Comment * [totalComments];

			for (int i = 0; i < totalComments; i++)
			{
				comments[i] = new Comment;
				inp >> tempId;
				inp.ignore();

				inp >> tempPost;


				inp >> temp;
				commentBy = GetObjectById(temp);
				inp.ignore();

				inp.getline(strText, 100);

				comments[i]->SetValues(tempId, strText, commentBy);

				Post* ptr = GetPostById(tempPost);
				ptr->AddComment(comments[i]);
			}
			inp.close();
		}
	}
	// 1
	void ViewFriendList(Users* currentUser)
	{
		cout << "________________________________________________________________________________________________" << endl;
		cout << "Command	ViewFriendList" << endl;
		cout << "________________________________________________________________________________________________" << endl;

		currentUser->ViewFriendList();
	}
	// 2
	void ViewLikedPages(Users* currentUser)
	{
		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "Command	ViewLikedPages" << endl;
		cout << "------------------------------------------------------------------------------------------------" << endl;

		currentUser->ViewLikedPages();
	}

	void ViewHome(Users* currentUser, Date currentDate)
	{
		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "Command	ViewHome" << endl;
		cout << "------------------------------------------------------------------------------------------------" << endl;

		currentUser->HomePage(currentDate);
	}

	void ViewTimeline(Users* currentUser)
	{
		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "Command	ViewTimeline" << endl;
		cout << "------------------------------------------------------------------------------------------------" << endl;

		currentUser->ViewTimeline();
	}

	void ViewLikedList(const char* str)
	{
		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "Command	ViewLikedList(" << str << ")" << endl;
		cout << "------------------------------------------------------------------------------------------------" << endl;

		Post* post = GetPostById(str);
		post->ViewLikedList();
	}

	void LikePost(Users* currentUser, const char* post)
	{
		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "Command	LikePost(" << post << ")" << endl;

		Post* postToLike = GetPostById(post);
		currentUser->LikePost(postToLike);
	}

	//void AddComment(Users* CurrentUser, const char* post, char* txt)
	//{
	//	cout << "------------------------------------------------------------------------------------------------" << endl;
	//	cout << "Command	PostComment(" << post << " , " << txt << ")" << endl;

	//	Post* currentPost = GetPostById(post);
	//	Comment* newComment = new Comment(CurrentUser, txt);
	//	currentPost->AddComment(newComment);
	//}


	void AddComment(Users* CurrentUser, const char* post, char* txt)
	{
		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "Command    PostComment(" << post << " , " << txt << ")" << endl;

		Post* currentPost = GetPostById(post);

		if (currentPost) {
			Comment* newComment = new Comment(CurrentUser, txt);
			currentPost->AddComment(newComment);
		}
		else {
			cout << "Error: Post not found." << endl;
		}
	}


	void ViewPost(const char* post)
	{
		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "Command	ViewPost(" << post << ")" << endl;
		cout << "------------------------------------------------------------------------------------------------" << endl;
		bool temp = false;
		Post* currentPost = GetPostById(post);
		currentPost->Print(temp);
	}

	void ViewMemory(Users* currentUser, Date CurrentDate)
	{
		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "Command	SeeYourMemory()" << endl;
		cout << "------------------------------------------------------------------------------------------------" << endl;

		currentUser->SeeMemory(CurrentDate);
	}

	void ShareMemory(Users* currentUSer, const  char* originalPostId, const char* txt, Date currentDate)
	{
		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "Command	ShareMemory(" << originalPostId << "," << "\"" << txt << "\")" << endl;

		Post* originalPost = GetPostById(originalPostId);
		Memory* newPostPtr = new Memory(originalPost, txt, currentUSer, currentDate);
		currentUSer->AddPostToTimeline(newPostPtr);
	}

	void ViewPage(const char* pageName)
	{
		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "Command	ViewPage(" << pageName << ")" << endl;
		cout << "------------------------------------------------------------------------------------------------" << endl;

		Pages* currentPage = GetPageFromId(pageName);
		currentPage->PrintForHome();
		cout << endl;
		currentPage->ViewTimeline();
	}

	void Load()
	{
		LoadPages("Pages.txt");
		LoadUsers("Users.txt");
		LoadPosts("Posts.txt");
		LoadComments("Comments.txt");
	}

	void Run(const char* str)
	{
		Load();
		Users* currentUser = GetUserFromId(str);
		Date::CurrentDate.SetData(15, 11, 2017);

		PrintUser(str);
		ViewFriendList(currentUser);
		ViewLikedPages(currentUser);



		ViewHome(currentUser, Date::CurrentDate);
		ViewTimeline(currentUser);
		ViewLikedList("post5");

		//command LikePost(Post5)

		LikePost(currentUser, "post5");
		ViewLikedList("post5");


		//command add comment
		ViewPost("post4");

		const char* src1 = "My Best Wishes.";
		size_t len1 = strlen(src1) + 1; // +1 to include null terminator

		char* txt1 = new char[len1];

		// Use strcpy_s to copy src to txt
		strcpy_s(txt1, len1, src1);
		AddComment(currentUser, "post4", txt1);
		ViewPost("post4");

		ViewPost("post8");

		const char* src = "Thanks for the wishes.";
		size_t len = strlen(src) + 1; // +1 to include null terminator

		char* txt = new char[len];

		// Use strcpy_s to copy src to txt
		strcpy_s(txt, len, src);
		AddComment(currentUser, "post8", txt);
		ViewPost("post8");

		//View memory
		ViewMemory(currentUser, Date::CurrentDate);

		ShareMemory(currentUser, "post10", "Never thought I will be specialist in this field�", Date::CurrentDate);
		ViewTimeline(currentUser);

		ViewPage("p1");


	}
};


int FaceBook::totalPages = 0;
int FaceBook::totalUsers = 0;
int FaceBook::totalPosts = 0;
int FaceBook::totalComments = 0;

int main()
{
	FaceBook obj;
	obj.Run("u7");

	return 0;
	//system("pause");
}