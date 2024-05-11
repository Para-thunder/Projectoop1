#include"Comment.h"

Comment::Comment(Object* CurrentUser, char* txt)
{
	char* IdForNewComment = Helper::ConcateIntAndString("c", TotalComments + 1);
	Text = txt;
	CommentBy = CurrentUser;
	Id = IdForNewComment;
}

Comment::Comment()
{
	CommentBy = 0;
	Text = 0;
	Id = 0;
}
Comment::~Comment()
{
	delete CommentBy;
	delete[]Text;
	delete[]Id;
}

void Comment::SetValues(char* idStr, char* textStr, Object* commentByPtr)
{
	CommentBy = commentByPtr;
	Helper::GetStringFromBuffer(textStr, Text);
	Helper::GetStringFromBuffer(idStr, Id);
	TotalComments++;
}

void Comment::Print()
{
	CommentBy->PrintForHome();
	cout << " wrote:" << Text << endl;
}


int Comment::TotalComments = 0;
