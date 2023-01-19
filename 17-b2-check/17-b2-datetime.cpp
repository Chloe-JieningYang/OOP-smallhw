/* 2050598 杨洁宁 通信 */
#include <iostream>
#include <climits>
#include "17-b2-datetime.h"
using namespace std;

DateTime::DateTime() :Date(), Time()
{
	return;
}

DateTime::DateTime(int y, int m, int d, int h, int min, int s)
{
	bool leap;//闰年
	if (y >= 1900 && y <= 2099)
		;
	else
	{
		Date::set(1900, 1, 1);
		Time::set(0, 0, 0);
		return;
	}

	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))//闰年判断
		leap = 1;
	else
		leap = 0;

	int st[12] = { 31,28 + leap,31,30,31,30,31,31,30,31,30,31 };
	if (m >= 1 && m <= 12)
		;
	else
	{
		Date::set(1900, 1, 1);
		Time::set(0, 0, 0);
		return;
	}

	if (d >= 1 && d <= st[m - 1])
		;
	else
	{
		Date::set(1900, 1, 1);
		Time::set(0, 0, 0);
		return;
	}

	if (h < 0 || h >= 24 || min < 0 || min >= 60 || s < 0 || s >= 60)
	{
		Date::set(1900, 1, 1);
		Time::set(0, 0, 0);
		return;
	}

	Date::set(y, m, d);
	Time::set(h, min, s);
}

DateTime::DateTime(const DateTime& dt)
{
	year = dt.year;
	month = dt.month;
	day = dt.day;
	hour = dt.hour;
	minute = dt.minute;
	second = dt.second;
}

DateTime::DateTime(long long seconds)
{
	int days = 0;
	
	while (seconds < 0)
	{
		seconds += (long long)MAX_DAYS * MAX_SECONDS;
	}
	while (seconds >= (long long)MAX_DAYS * MAX_SECONDS)
		seconds = seconds % ((long long)MAX_DAYS * MAX_SECONDS);
	while(seconds >= MAX_SECONDS)//秒数大于一天
	{
		seconds -= MAX_SECONDS;
		days++;
	}
	Date date(days);
	date.get(year, month, day);

	Time time((int)seconds);
	time.get(hour, minute, second);
}

void DateTime::show()
{
	cout << year << "年" << month << "月" << day << "日";
	Time::show();
	cout << endl;
}

void DateTime::set(int y, int m, int d, int h, int min, int s)
{
	bool leap;//闰年
	if (y >= 1900 && y <= 2099)
		;
	else
	{
		Date::set(1900, 1, 1);
		Time::set(0, 0, 0);
		return;
	}

	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))//闰年判断
		leap = 1;
	else
		leap = 0;

	int st[12] = { 31,28 + leap,31,30,31,30,31,31,30,31,30,31 };
	if (m >= 1 && m <= 12)
		;
	else
	{
		Date::set(1900, 1, 1);
		Time::set(0, 0, 0);
		return;
	}

	if (d >= 1 && d <= st[m - 1])
		;
	else
	{
		Date::set(1900, 1, 1);
		Time::set(0, 0, 0);
		return;
	}

	if (h < 0 || h >= 24 || min < 0 || min >= 60 || s < 0 || s >= 60)
	{
		Date::set(1900, 1, 1);
		Time::set(0, 0, 0);
		return;
	}

	Date::set(y, m, d);
	Time::set(h, min, s);
	
}

void DateTime::get(int& y, int& m, int& d, int& h, int& min, int& s)
{
	Date::get(y, m, d);
	Time::get(h, min, s);
}

DateTime:: operator long long() const
{
	Date date(year, month, day);
	int days = (int)date;
	long long seconds = (long long)days * 60 * 60 * 24;
	Time time(hour, minute, second);
	seconds += (long long)(int)time;
	return seconds;
}

DateTime& DateTime::operator++()//前缀++
{
	long long total_seconds = (long long)(*this) + 1;
	DateTime now(total_seconds);
	*this = now;
	return *this;
}

DateTime& DateTime::operator--()//前缀--
{
	long long total_seconds = (long long)(*this) - 1;
	DateTime now(total_seconds);
	*this = now;
	return *this;
}

DateTime DateTime::operator++(int)//后缀++
{
	DateTime temp = *this;
	long long total_seconds = (long long)(*this) + 1;
	DateTime now(total_seconds);
	*this = now;
	return temp;
}

DateTime DateTime::operator--(int)//后缀++
{
	DateTime temp = *this;
	long long total_seconds = (long long)(*this) - 1;
	DateTime now(total_seconds);
	*this = now;
	return temp;
}

bool DateTime::operator==(const DateTime& d)
{
	if (year == d.year &&
		month == d.month &&
		day == d.day &&
		hour == d.hour &&
		minute == d.minute &&
		second == d.second)
		return true;
	else
		return false;
}

bool DateTime::operator!=(const DateTime& d)
{
	if (*this == d)
		return false;
	else
		return true;
}

bool DateTime::operator>(const DateTime& d)
{
	if ((long long)(*this) > (long long)d)
		return true;
	else
		return false;
}

bool DateTime::operator<(const DateTime& d)
{
	if ((long long)(*this) < (long long)d)
		return true;
	else
		return false;
}

bool DateTime::operator>=(const DateTime& d)
{
	if (*this > d || *this == d)
		return true;
	else
		return false;
}

bool DateTime::operator<=(const DateTime& d)
{
	if (*this < d || *this == d)
		return true;
	else
		return false;
}

/*友元函数*/

ostream& operator << (ostream& out, const DateTime& dt)
{
	out << dt.year << "年" << dt.month << "月" << dt.day << "日";
	Time time(dt.hour, dt.minute, dt.second);
	out << time;
	out << endl;

	return out;
}

istream& operator >> (istream& in, DateTime& dt)
{
	int y, m, d, h, min, s;
	cin >> y >> m >> d >> h >> min >> s;
	dt.set(y, m, d, h, min, s);
	return in;
}

DateTime operator +(const DateTime& dt, long long seconds)
{
	long long total_seconds = (long long)dt + seconds;
	DateTime now(total_seconds);
	return now;
}

DateTime operator +(const DateTime& dt, int seconds)
{
	long long total_seconds = (long long)dt + seconds;
	DateTime now(total_seconds);
	return now;
}

DateTime operator +(long long seconds, const DateTime& dt)
{
	return dt + seconds;
}

DateTime operator +(int seconds, const DateTime& dt)
{
	return dt + seconds;
}

DateTime operator -(const DateTime& dt, long long seconds)
{
	long long total_seconds = (long long)dt - seconds;
	DateTime now(total_seconds);
	return now;
}

DateTime operator -(const DateTime& dt, int seconds)
{
	long long total_seconds = (long long)dt - seconds;
	DateTime now(total_seconds);
	return now;
}

long long operator -(const DateTime& dt1, const DateTime& dt2)
{
	return (long long)dt1 - (long long)dt2;
}

