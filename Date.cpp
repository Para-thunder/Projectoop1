#include"Date.h"


Date::Date(int x = 0, int y = 0, int z = 0)
{
	day = x;
	month = y;
	year = z;
}

void Date::ReadDataFromFile(ifstream& inp)
{
	inp >> day;
	inp >> month;
	inp >> year;
}

bool Date::compare(const Date& rhs, bool isMemory)
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

static int Date::YearDiff(Date lhs, Date rhs)
{
	int ans;
	ans = lhs.year - rhs.year;
	if (ans < 0)
	{
		ans = -ans;
	}
	return ans;
}

void Date::Print()
{
	cout << day << "/" << month << "/" << year;
}

void Date::SetData(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}