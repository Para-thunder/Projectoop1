#pragma once
#ifndef USERS_H
#define USERS_H

#include "Object.h"
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
    Users()
    {
        Fname = "";
        Lname = "";
        LikedPages = 0;
        FriendList = 0;
        timeline = 0;
        totalTimeline = 0;
        numPages = 0;
        numFriends = 0;

    }
    ~Users()
    {
        if (LikedPages != 0)
        {
            delete[] LikedPages;
        }
        if (FriendList != 0)
        {
            delete[] FriendList;
        }
        if (timeline != 0)
        {
            delete[] timeline;
        }

    }
    void ReadDataFromFile(std::ifstream& inp) {
        std::string temp;
        inp >> temp;
        SetID(temp);

        inp >> temp;
        Fname = temp;

        inp >> temp;
        Lname = temp;
    }
    void SetPage(Page* ptr)
    {
        if (numPages == 0)
        {
            LikedPages = new Pages * [10];
            for (int i = 0; i < 10; i++)
            {
                LikedPages[i] = 0;
            }
        }
        LikedPages[numPages] = ptr;
        numPages++;
    }
    void CheckDate(Date CurrentDate, bool isMemory)
    {
        bool temp = false;
        for (int i = 0; i < totalTimeline; i++)
        {
            if (timeline[i]->CompareDate(CurrentDate, isMemory))
            {
                timeline->Print(temp);
            }
        }
    }
    void LikePost(Post* post)
    {
        post->SetLikedBy(this);
    }
    void HomePage(Date currentDate)
    {
        cout << "------------------------------------------------------------------------------" << endl;
        if (FriendList != 0)
        {
            for (int i = 0; i < numFriends; i++)
            {
                FriendList[i]->CheckDate(currentDate, false);
            }
        }

        if (LikedPages != 0)
        {
            for (int i = 0; i < numPages; i++)
            {
                LikedPages[i]->CheckDAte(currentDate, false);
            }
            cout << endl;
        }
    }
    void ViewTimeline()
    {
        if (timeline != 0)
        {
            cout << "---------------------------------------------------------------------------------" << endl;
            for (int i = 0; i < totalTimeline; i++)
            {
                if (timeline[i] != 0)
                {
                    bool IsNewPost = false;
                    timeline[i]->Print(IsNewPost);
                    if (IsNewPost)
                    {
                        timeline[i]->Print();
                    }
                }
            }
        }
    }

    void SeeMemory(Date currentDate)
    {
        bool temp = false;
        for (int i = 0; i < totalTimeline; i++)
        {
            if (timeline[i] != 0)
            {
                if (timeline[i]->CompareDate(currentDate, true))
                {
                    timeline[i]->Print();
                }
            }
        }
    }
    void PrintForHome()

    {
        cout << Fname << " " << Lname;
    }

    void SetFriend(Users* otr)
    {
        if (numFriends == 0)
        {
            FriendList = new Users * [10];
            for (int i = 0; i < 10; i++)
            {
                FriendList[i] = 0;
            }
        }
        FriendList[numFriends] = otr;
        numFriends++;
    }

    void AddPostToTimeline(Post* ptr)
    {
        if (totalTimeline == 0)
        {
            timeline = new Post * [10];
            for (int i = 0; i < 10; i++)
            {
                timeline[i] = 0;
            }
            timeline[totalTimeline] = ptr;
            totalTimeline++;
        }
        else
        {
            timeline[totalTimeline] = ptr;
            totalTimeline++;
        }
    }

    void ViewFriendList()
    {
        if (FriendList != 0)
        {
            cout << "---------------------------------- Friend List ----------------------------------" << endl;
            for (int i = 0; i < numFriends; i++)
            {
                cout << FriendList[i] << endl;
                FriendList[i]->Print();
            }
        }
    }

    void ViewLikedPages()
    {
        if (LikedPages != 0)
        {
            cout << "---------------------------------- Liked Pages ----------------------------------" << endl;
            for (int i = 0; i < numPages; i++)
            {
                LikedPages[i]->Print();
            }
        }
    }

    void Print()
    {
        cout << this->GetId() << "\t" << Fname << " " << Lname << endl;
        //cout << this->GetId() << "\t" << name << endl;
    }

    //getters
    char* GetId()
    {
        return this->GetID();
    }
};

#endif
