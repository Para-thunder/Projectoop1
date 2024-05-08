#include"Post.h"


Post::Post()
{
}
Post::Post(string postText, Object* shared_By)
{
	SharedBy = shared_By;
	Text = postText;
	SharedDate = Date::CurrentDate;
}
void Post::viewlikes()
{
	for (int i = 0; i < LikesCount; i++) {
		cout << LikedBy[i]->getId() << " - ";
		LikedBy[i]->printName();
		cout << endl;
	}
}
bool Post::dateCheck()
{
	if (SharedDate <= Date::CurrentDate) {
		return true;
	}
	else {
		return false;
	}
}
Comment** Post::getComments()
{
	return comments;
}
int Post::getCommentsCount()
{
	return commentsCount;
}
char* Post::getPostText()
{
	return Text;
}
Date Post::getSharedDate()
{
	return SharedDate;
}
Activity* Post::getActivity()
{
	return activity;
}
string Post::getPostId()
{
	return ID;
}
void Post::ReadDataFromFile(ifstream& fin)
{
	string id[10];
	string text[150];
	int activityCheck;
	fin >> activityCheck;
	fin >> id;
	ID = Helper::GetStringFromBuffer(id);
	SharedDate.ReadDataFromFile(fin);
	fin.getline(text, 150);
	if (text[0] == '\t' || text[0] == '\0') {
		fin.getline(text, 150);
	}
	Text = Helper::GetStringFromBuffer(text);
	if (activityCheck == 2) {
		activity = new Activity;
		activity->ReadDataFromFile(fin);
	}
}
void Post::viewPost(bool dateFlag, bool commentFlag)
{
	SharedBy->printName();
	if (activity) {
		activity->activityPrint();
	}
	else {
		cout << " shared ";
	}
	cout << Text;
	if (dateFlag == 1) {
		SharedDate.printDate();
	}
	else {
		cout << endl;
	}
	if (commentFlag == 1) {
		for (int i = 0; i < commentsCount; i++) {
			cout << "\t\t";
			comments[i]->viewCommentBy();
			comments[i]->viewCommentText();
		}
	}
}
void Post::AddComment(Comment* ptr)
{
	if (!comments) {
		//	comments = new Comment * [10];
	}
	//comments[commentsCount] = ptr;
	if (ptr != 0) {
		//commentsCount++;
	}
}
void Post::SetSharedBy(Object* ptr)
{
	SharedBy = ptr;
}
void Post::SetLikedBy(Object* ptr)
{
	if (!LikedBy) {
		LikedBy = new Object * [10];
	}
	LikedBy[LikesCount] = ptr;
	if (ptr != 0) {
		LikesCount++;
	}
}
void Post::dateDifference()
{
	if (SharedDate.memoryDateCheck() == 1) {
		cout << Date::CurrentDate.getDateYear() - SharedDate.getDateYear() << " Years Ago" << endl;
		viewPost(1, 0);
	}
}
Post::~Post()
{
	if (ID) {
		delete[] ID;
	}
	if (Text) {
		delete[] Text;
	}
	SharedBy = nullptr;
	if (activity) {
		delete activity;
	}
	if (LikedBy) {
		for (int i = 0; i < LikesCount; i++) {
			if (LikedBy[i])
				LikedBy[i] = nullptr;
		}
		delete[] LikedBy;
	}
	if (comments) {
		for (int i = 0; i < commentsCount; i++) {
			if (comments[i]) {
				delete comments[i];
			}
		}
		delete[] comments;
	}
}