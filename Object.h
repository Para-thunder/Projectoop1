#pragma once
#ifndef OBJECT_H
#define OBJECT_H


#include<iostream>
using namespace std;

class Object {
	string id;
public:
	Object()
	{
		id = "";
	}
	virtual ~Object()
	{
	
	}
	string GetID();
	void SetID(string ptr);

	virtual void Print()
	{
		cout << id;
	}
	virtual void PrintForHome()
	{
		cout << "Error Not Found!!!!!" << endl;
	}
	virtual void AddPostToTimeline(Post* ptr)
	{
		cout << "Error Not Found!!!!!" << endl;
	}
};
string Object::GetID()
{
	return id;
}
void Object::SetID(string ptr)
{
	id = ptr;
}
#endif;