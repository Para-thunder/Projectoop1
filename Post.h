#pragma once
#ifndef POST_H
#define POST_H

#include"User.h"
#include"Activity.h"
#include"Comment.h"
#include"Date.h"
#include"Memory.h"

class Post : public Object
{
	char* ID;
	char* Text;
	Date sharedDate;
	Activity* activity;
	Object* sharedBy;
	Object** LikedBy;
	Comment** comments;

	int totalLikedBy;
	int totalComment;

	static int TotalPosts;
public:
	~Post();
	Post(const char* txt, Object* SharedBy, Date currentDate);
	Post();
	void ReadDataFromFile(ifstream& inp);
	void SetSharedBy(Object* ptr);
	void SetLikedBy(Object* ptr);
	void AddComment(Comment* ptr);
	bool CompareDate(Date currentDate, bool isMemory);
	void ViewLikedList();
	virtual void Print(bool& flag);
	void Print();
	Date GetSharedDate();
	char* GetId();
};

#endif;