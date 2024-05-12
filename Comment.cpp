#include"Comment.h"

Comment::Comment(Control* CurrentUser, char* txt)
{
	char* IdForNewComment = Manager::concate("c", TotalComments + 1);
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

void Comment::SetValues(char* idStr, char* textStr, Control* commentByPtr)
{
	CommentBy = commentByPtr;
	Manager::GetString(textStr, Text);
	Manager::GetString(idStr, Id);
	TotalComments++;
}

void Comment::Print()
{
	CommentBy->PrintForHome();
	cout << " wrote:" << Text << endl;
}


int Comment::TotalComments = 0;