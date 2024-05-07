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
	string ID;
	string Text;
	Date sharedDate;
	Activity* activity;
	Object* sharedBy;
	Object** LikedBy;
	Comment** comments;

	int totalLikedBy;
	int totalComment;
public:
	Post();
	Post(char*, Object*);
	void SetSharedBy(Object*);
	void SetLikedBy(Object*);
	void ReadDataFromFile(ifstream&);
	void AddComment(Comment*);
	Comment** getComments();
	int getCommentsCount();
	char* getPostText();
	Date getSharedDate();
	char* getPostId();
	bool dateCheck();
	Activity* getActivity();
	void viewPost(bool, bool);
	void viewlikes();
	void dateDifference();
	~Post();
};

#endif;