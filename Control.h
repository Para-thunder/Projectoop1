#pragma once
#ifndef CONTROL_H
#define CONTROL_H


#include<iostream>
using namespace std;
class Post;

class Control
{
	char* Id;

public:
	Control();

	virtual ~Control();

	char* GetID();
	void SetID(char* ptr);

	virtual void Print();

	virtual void PrintForHome();

	virtual void AddPostToTimeline(Post* ptr);


};


#endif
