#pragma once
#ifndef USERS_H
#define USERS_H

#include "Object.h"
#include"Users.cpp"
#include<iostream>
#include<fstream>


using namespace std;


class Users : public Object {

    string Fname;
    string Lname;
    Pages** LikedPages;
    Users** FriendList;
    Post** timeline;


    int totalTimeline;
    int numPages;
    int numFriends;

public:

    // Constructor
    Users();
    ~Users();
   
    void ReadDataFromFile(std::ifstream& inp); 
    void SetPage(Page* ptr);
   
    void CheckDate(Date CurrentDate, bool isMemory);

    void LikePost(Post* post);
   
    void HomePage(Date currentDate);
  
      
    void ViewTimeline();
   

    void SeeMemory(Date currentDate);
  
    void PrintForHome();

  

    void SetFriend(Users* otr);
   

    void AddPostToTimeline(Post* ptr);
   
    void ViewFriendList();
  

    void ViewLikedPages();
   

    void Print();
   

    //getters
    char* GetId();
   
};

#endif
