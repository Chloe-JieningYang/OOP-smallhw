/* 2050598 ����� ͨ�� */
#include <iostream>
#include "17-b2-date.h"
using namespace std;

/*���캯��*/
Date::Date()
{
	year = 1900;
	month = 1;
	day = 1;
}

Date::Date(int y, int m, int d)
{
	bool leap;//����
	if (y >= 1900 && y <= 2099)
		year = y;
	else
	{
		year = 1900;
		month = 1;
		day = 1;
		return;
	}
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))//�����ж�
		leap = 1;
	else
		leap = 0;
	int st[12] = { 31,28 + leap,31,30,31,30,31,31,30,31,30,31 };
	if (m >= 1 && m <= 12)
		month = m;
	else
	{
		year = 1900;
		month = 1;
		day = 1;
		return;
	}
	if (d >= 1 && d <= st[month - 1])
		day = d;
	else
	{
		year = 1900;
		month = 1;
		day = 1;
	}
}

Date::Date(const Date& d)
{
	year = d.year;
	month = d.month;
	day = d.day;
}

Date::Date(int days)
{
	year = 1900;
	month = 1;
	day = 1;
	if (days >= MAX_DAYS)
		days = days % MAX_DAYS;
	if (days < 0)
	{
		while (days < 0)
		{
			days += MAX_DAYS;
		}
	}
	bool leap;
	if (days >= 365)//�����ȳ���һ��
	{
		while (1)
		{
			JudgeLeap(year, leap);
			days -= 365 + leap;
			year++;
			JudgeLeap(year, leap);
			if (days < (365 + leap))//���daysʣ�಻��һ��
				break;
		}
	}

	/*��������ݣ������·�*/
	JudgeLeap(year, leap);
	int st[12] = { 31,28 + leap,31,30,31,30,31,31,30,31,30,31 };
	if (days >= 31)//�����ȳ�����һ���µ�����
	{
		while (1)
		{
			days -= st[month - 1];
			month++;
			if (days < st[month - 1])
				break;
		}
	}

	/*�������·ݣ���������*/
	day += days;
}

/*��ӡ*/
void Date::show()
{
	cout << year << "��" << month << "��" << day << "��" << endl;
}

/*����������*/
void Date::set(int y, int m, int d)
{
	if (y >= 1900 && y <= 2099)
		year = y;
	else
	{
		year = 1900;
		month = 1;
		day = 1;
		return;
	}
	bool leap;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))//�����ж�
		leap = 1;
	else
		leap = 0;
	int st[12] = { 31,28 + leap,31,30,31,30,31,31,30,31,30,31 };
	if (m >= 1 && m <= 12)
		month = m;
	else
	{
		year = 1900;
		month = 1;
		day = 1;
		return;
	}

	if (d >= 1 && d <= st[month - 1])
		day = d;
	else
	{
		year = 1900;
		month = 1;
		day = 1;
		return;
	}
}

void Date::get(int& y, int& m, int& d)
{
	y = year;
	m = month;
	d = day;
}

Date::operator int() const
{
	int days = 0;
	int y, m;
	bool leap;
	if (year > 1900)//���year����1900
	{
		for (y = 1900; y < year; y++)
		{
			JudgeLeap(y, leap);
			days += 365 + leap;
		}
	}

	JudgeLeap(year, leap);
	int st[12] = { 31,28 + leap,31,30,31,30,31,31,30,31,30,31 };
	if (month > 1)//���month����1
	{
		for (m = 1; m < month; m++)
		{
			days += st[m - 1];
		}
	}

	days += day - 1;

	return days;
}

/*ǰ׺++*/
Date& Date::operator++()
{
	*this = (*this) + 1;
	return *this;
}

/*ǰ׺--*/
Date& Date::operator--()
{
	*this = (*this) - 1;
	return *this;
}

/*��׺++*/
Date Date::operator++(int)
{
	Date temp(*this);
	*this = (*this) + 1;
	return temp;
}

/*��׺--*/
Date Date::operator--(int)
{
	Date temp(*this);
	*this = (*this) - 1;
	return temp;
}

/*Date==Date ==����*/
bool Date::operator==(const Date& d)
{
	if (year == d.year && month == d.month && day == d.day)
		return true;
	else
		return false;
}

/*Date!=Date !=����*/
bool Date::operator!=(const Date& d)
{
	if ((*this) == d)
		return false;
	else
		return true;
}

//Date>Date >����
bool Date::operator>(const Date& d)
{
	if (year > d.year || (year == d.year && month > d.month) || (year == d.year && month == d.month && day > d.day))
		return true;
	else
		return false;
}

//<����
bool Date::operator<(const Date& d)
{
	if (year < d.year || (year == d.year && month < d.month) || (year == d.year && month == d.month && day < d.day))
		return true;
	else
		return false;
}

bool Date::operator>=(const Date& d)
{
	return ((*this) == d || (*this) > d);
}

bool Date::operator<=(const Date& d)
{
	return ((*this) == d || (*this) < d);
}

/*��Ԫ����*/

/*�ж��Ƿ�����*/
void JudgeLeap(int year, bool& leap)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))//�����ж�
		leap = 1;
	else
		leap = 0;
}

/*ͨ�����»�ȡ��������*/
int GetDaysByYM(int year, int month)
{
	bool leap;
	JudgeLeap(year, leap);
	int st[12] = { 31,28 + leap,31,30,31,30,31,31,30,31,30,31 };
	return st[month - 1];
}

ostream& operator << (ostream& out, const Date& date)
{
	out << date.year << "��" << date.month << "��" << date.day << "��" << endl;
	return out;
}

istream& operator >> (istream& in, Date& date)
{
	in >> date.year >> date.month >> date.day;

	bool leap;//����
	if (date.year >= 1900 && date.year <= 2099)
		;
	else
	{
		date.year = 1900;
		date.month = 1;
		date.day = 1;
		return in;
	}
	if ((date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0))//�����ж�
		leap = 1;
	else
		leap = 0;
	int st[12] = { 31,28 + leap,31,30,31,30,31,31,30,31,30,31 };
	if (date.month >= 1 && date.month <= 12)
		;
	else
	{
		date.year = 1900;
		date.month = 1;
		date.day = 1;
		return in;
	}
	if (date.day >= 1 && date.day <= st[date.month - 1])
		;
	else
	{
		date.year = 1900;
		date.month = 1;
		date.day = 1;
		return in;
	}

	return in;
}

/* + */
Date operator + (const Date& date, int days)
{
	int total_days = (int)date + days;

	Date now(total_days);

	return now;
}

/* + */
Date operator + (int days, const Date& date)
{
	return date + days;
}

Date operator - (const Date& date, int days)
{
	int total_days = (int)date - days;
	if (total_days < 0)
	{
		while (total_days < 0)
		{
			total_days += MAX_DAYS;
		}
	}

	Date now(total_days);

	return now;
}

int operator - (const Date& d1, const Date& d2)
{
	int days = (int)d1 - (int)d2;
	return days;
}
