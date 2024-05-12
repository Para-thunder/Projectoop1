#pragma once
#ifndef POST_H
#define POST_H

#include"Date.h"
#include"Control.h"
#include"Comment.h"
#include"Activity.h"
#include<iostream>
#include"Manager.h"
#include<fstream>

//using namespace std;

class Post
{
	char* Id;
	char* text;
	Date sharedDate;
	Control* sharedBy;
	Control** LikedBy;
	Comment** comments;
	Activity* activity;

	int totalLikedBy;
	int totalComment;

	static int TotalPosts;
public:

	~Post();
	Post(const char* txt, Control* SharedBy, Date currentDate);
	Post();
	void ReadDataFromFile(ifstream& inp);
	void SetSharedBy(Control* ptr);
	void SetLikedBy(Control* ptr);
	void AddComment(Comment* ptr);
	bool CompareDate(Date currentDate, bool isMemory);
	void ViewLikedList();
	virtual void Print(bool& flag);
	void Print();
	Date GetSharedDate();
	char* GetId();

};
#endif