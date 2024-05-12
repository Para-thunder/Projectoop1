#include"Memory.h"

Memory::Memory()
{
	Original = 0;
}
Memory::~Memory()
{
	delete Original;
}

Memory::Memory(Post*& oldPost, const char* text, Control* userptr, Date currentDate) :Post(text, userptr, currentDate)
{
	Original = oldPost;
}
void Memory::Print(bool& flag)
{
	cout << "Shared a memory (" << Date::YearDiff(Original->GetSharedDate(), GetSharedDate()) << " years) ago" << endl;;
	Original->Print(flag);
	flag = true;
}

Post* Memory::GetOriginalPost()
{
	return Original;
}