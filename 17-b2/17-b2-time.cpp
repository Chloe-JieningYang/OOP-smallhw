/* 2050598 杨洁宁 通信 */
#include <iostream>
#include <iomanip>
#include "17-b2-time.h"
using namespace std;

Time::Time()
{
	hour = 0;
	minute = 0;
	second = 0;
}

Time::Time(int h,int m,int s)
{
	if (h < 0 || h>23)
	{
		hour = 0;
		minute = 0;
		second = 0;
		return;
	}
	hour = h;
	if (m < 0 || m>59)
	{
		hour = 0;
		minute = 0;
		second = 0;
		return;
	}
	minute = m;
	if (s < 0 || s>59)
	{
		hour = 0;
		minute = 0;
		second = 0;
		return;
	}
	second = s;
}

Time::Time(const Time& t)
{
	hour = t.hour;
	minute = t.minute;
	second = t.second;
}

Time::Time(int seconds)
{
	hour = 0;
	minute = 0;
	second = 0;
	if (seconds < 0)
	{
		while (seconds < 0)
			seconds += MAX_SECONDS;
	}
	if (seconds >= MAX_SECONDS)
		seconds = seconds % MAX_SECONDS;

	second += seconds;
	if (second > 59)
	{
		while (second > 59)
		{
			second -= 60;
			minute++;
		}
	}

	if (minute > 59)
	{
		while (minute > 59)
		{
			minute -= 60;
			hour++;
		}
	}
}

void Time::show()
{
	cout << setw(2) << setfill('0') << hour << ":" << setw(2) << minute << ":" << setw(2) << second;
}

void Time::set(int h, int m, int s)
{
	if (h < 0 || h>23)
	{
		hour = 0;
		minute = 0;
		second = 0;
		return;
	}
	hour = h;
	if (m < 0 || m>59)
	{
		hour = 0;
		minute = 0;
		second = 0;
		return;
	}
	minute = m;
	if (s < 0 || s>59)
	{
		hour = 0;
		minute = 0;
		second = 0;
		return;
	}
	second = s;
}

void Time:: get(int& h, int& m, int& s)
{
	h = hour;
	m = minute;
	s = second;
}

Time::operator int() const
{
	int seconds = 0;
	int h = hour, m = minute;
	if (h > 0)
	{
		for (; h > 0; h--)
		{
			seconds += 60 * 60;
		}
	}
	if (m > 0)
	{
		for (; m > 0; m--)
		{
			seconds += 60;
		}
	}
	seconds += second;
	return seconds;
}

Time& Time::operator ++()
{
	(*this) = (*this) + 1;
	return *this;
}

Time& Time::operator --()
{
	(*this) = (*this) - 1;
	return *this;
}

/*后缀++*/
Time Time::operator++(int)
{
	Time temp(*this);
	*this = (*this) + 1;
	return temp;
}

/*后缀--*/
Time Time::operator--(int)
{
	Time temp(*this);
	*this = (*this) - 1;
	return temp;
}

bool Time::operator==(const Time& t)
{
	if (hour == t.hour && minute == t.minute && second == t.second)
		return true;
	else
		return false;
}

bool Time::operator!=(const Time& t)
{
	if ((*this) == t)
		return false;
	else
		return true;
}

bool Time::operator>(const Time& t)
{
	if (hour > t.hour || (hour == t.hour && minute > t.minute) || (hour == t.hour && minute == t.minute && second > t.second))
		return true;
	else
		return false;
}

bool Time::operator<(const Time& t)
{
	if (hour < t.hour || (hour == t.hour && minute < t.minute) || (hour == t.hour && minute == t.minute && second < t.second))
		return true;
	else
		return false;
}

bool Time::operator>=(const Time& t)
{
	if ((*this) > t || (*this) == t)
		return true;
	else
		return false;
}

bool Time::operator<=(const Time& t)
{
	if ((*this) < t || (*this) == t)
		return true;
	else
		return false;
}

/*友元函数*/

ostream& operator << (ostream& out, const Time& time)
{
	cout << setw(2) << setfill('0') << time.hour << ":" << setw(2) << time.minute << ":" << setw(2) << time.second;
	return out;
}

istream& operator >>(istream& in, Time& time)
{
	int h, m, s;
	cin >> h >> m >> s;
	if (h < 0 || h>23)
	{
		time.hour = 0;
		time.minute = 0;
		time.second = 0;
		return in;
	}
	time.hour = h;
	if (m < 0 || m>59)
	{
		time.hour = 0;
		time.minute = 0;
		time.second = 0;
		return in;
	}
	time.minute = m;
	if (s < 0 || s>59)
	{
		time.hour = 0;
		time.minute = 0;
		time.second = 0;
		return in;
	}
	time.second = s;
	return in;
}

Time operator +(const Time& t, int seconds)
{
	int total_seconds = (int)t + seconds;
	Time now(total_seconds);
	return now;
}

Time operator +(int seconds, const Time& t)
{
	return t + seconds;
}

Time operator -(const Time& t, int seconds)
{
	int total_seconds = (int)t - seconds;
	Time now(total_seconds);
	return now;
}

int operator -(const Time& t1, const Time& t2)
{
	return (int)t1 - (int)t2;
}