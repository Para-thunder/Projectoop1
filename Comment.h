#pragma once
#ifndef COMMENT_H
#define COMMENT_H

#include"Manager.h"
#include"Control.h"
#include<iostream>
using namespace std;

class Comment
{
	Control* CommentBy;
	char* Text;
	char* Id;

	static int TotalComments;
public:
	Comment(Control* CurrentUser, char* txt);
	Comment();
	~Comment();
	void SetValues(char* idStr, char* textStr, Control* commentByPtr);
	void Print();
};


#endif

