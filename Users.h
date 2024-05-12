#pragma once
#ifndef USER_H
#define USER_H

#include"Control.h"
#include<fstream>
#include<iostream>
#include"Page.h"
using namespace std;


class Users :public Control
{
	char* Fname;
	char* Lname;
	string name;
	Pages** LikedPages;
	Users** FriendList;
	Post** timeline;

	int totalTimeline;
	int numPages;
	int numFriends;

public:
	Users();
	~Users();
	void ReadDataFromFile(ifstream& inp);
	void SetPage(Pages* ptr);
	void CheckDate(Date CurrentDate, bool isMemory);
	void LikePost(Post* post);
	void HomePage(Date currentDate);
	void ViewTimeline();
	void SeeMemory(Date currentDate);
	void PrintForHome();
	void SetFriend(Users* ptr);
	void AddPostToTimeline(Post* ptr);
	void ViewFriendList();
	void ViewLikedPages();
	void Print();
	char* GetId();

};

#endif