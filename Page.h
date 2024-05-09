#pragma once
#ifndef PAGE_H
#define PAGE_H


#include"Post.h"
#include"Object.h"
#include<fstream>
#include<iostream>
using namespace std;

class Pages : public Object

{
	char* Title;
	Post** timeline;

	int totalTimeline;
public:
	Pages();
	~Pages();
	void ReadDataFromFile(ifstream& inp);
	void PrintForHome();
	void AddPostToTimeline(Post* ptr);
	void CheckDate(Date CurrentDate, bool isMemory);
	void Print();
	void ViewTimeline();
	char* GetId();///changed from GetId
	char* GetID();


};

#endif 
