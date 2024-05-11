#pragma once
#ifndef COMMENT_H
#define COMMENT_H

#include"Helper.h"
#include"Object.h"
#include<iostream>
using namespace std;

class Comment
{
	Object* CommentBy;
	char* Text;
	char* Id;

	static int TotalComments;
public:
	Comment(Object* CurrentUser, char* txt);
	Comment();
	~Comment();
	void SetValues(char* idStr, char* textStr, Object* commentByPtr);
	void Print();
};


#endif

