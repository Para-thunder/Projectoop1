#pragma once
#ifndef MEMORY_H
#define MEMORY_H

#include"Post.h"
#include<iostream>
using namespace std;

class Memory : public Post
{
	Post* Original;
public:
	Memory();
	~Memory();
	Memory(Post*& oldPost, const char* text, Control* userptr, Date currentDate);
	void Print(bool& flag);
	Post* GetOriginalPost();

};
#endif