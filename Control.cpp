#include"Control.h"

Control::Control()
{
	Id = 0;
}
Control::~Control()
{
	delete[]Id;
}

//void SetId(char* id);
void Control::Print()
{
	cout << Id;
}
void Control::PrintForHome()
{
	cout << "Error	Not Found!!!!!!!!" << endl;
}
void Control::AddPostToTimeline(Post* ptr)
{
	cout << "Error	Not Found!!!!!!!!" << endl;

}
char* Control::GetID() {
	return Id;
}
void Control::SetID(char* ptr) {
	Id = ptr;
