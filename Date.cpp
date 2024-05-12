#include"Date.h"


Date::Date() : day(0), month(0), year(0) {}

Date::Date(int x = 0, int y = 0, int z = 0)
{
	day = x;
	month = y;
	year = z;
}

void Date::ReadDataFromFile(std::ifstream& inp)
{
	inp >> day;
	inp >> month;
	inp >> year;
}




bool Date::compare(const Date& rhs, bool isMemory)const
{
	if (isMemory == false)
	{
		if (year != rhs.year)
		{
			return false;
		}

		else if (month == rhs.month)
		{
			if (day == rhs.day)
			{
				return true;
			}
			else if (day + 1 == rhs.day || day - 1 == rhs.day)
			{
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
	{
		if (year == rhs.year)
		{
			return false;
		}
		else
		{
			if (month == rhs.month)
			{
				if (day == rhs.day)
				{
					return true;
				}
				else if (day + 1 == rhs.day || day - 1 == rhs.day)
				{
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
	}
}

int Date::YearDiff(const Date lhs, const Date rhs)
{
	int ans;
	ans = lhs.year - rhs.year;
	if (ans < 0)
	{
		ans = -ans;
	}
	return ans;
}

void Date::Print()const
{
	std::cout << day << "/" << month << "/" << year;
}

void Date::SetData(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}
Date Date::CurrentDate = Date(0, 0, 0);