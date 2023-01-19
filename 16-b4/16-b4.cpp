/* 2050598 ����� ͨ�� */
#include <iostream>
#include "16-b4.h"
using namespace std;

/* ���� Date ������г�Ա����������ʵ�� */
/*�޲ι��캯��*/
Date::Date()
{
	year = 2000;
	month = 1;
	day = 1;
}

/*�����������Ĺ��캯��*/
Date::Date(int y, int m, int d)
{
	bool leap;//����
	if (y >= 1900 && y <= 2099)
		year = y;
	else
		year = 2000;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))//�����ж�
		leap = 1;
	else
		leap = 0;
	int st[12] = { 31,28 + leap,31,30,31,30,31,31,30,31,30,31 };
	if (m >= 1 && m <= 12)
		month = m;
	else
		month = 1;
	if (d >= 1 && d <= st[month - 1])
		day = d;
	else
		day = 1;
}

/*int ת Date ��ת�����캯��*/
Date::Date(int days)
{
	year = 1900;
	month = 1;
	day = 1;
	if (days > 73049)
		days = 73049;
	if (days <= 0)
		days = 1;
	bool leap;
	if (days > 365)//�����ȳ���һ��
	{
		while (1)
		{
			JudgeLeap(year, leap);
			days -= 365 + leap;
			year++;
			JudgeLeap(year, leap);
			if (days <= (365 + leap))//���daysʣ�಻��һ��
				break;
		}
	}
	
	/*��������ݣ������·�*/
	JudgeLeap(year, leap);
	int st[12] = { 31,28 + leap,31,30,31,30,31,31,30,31,30,31 };
	if (days > 31)//�����ȳ���һ����
	{
		while (1)
		{
			days -= st[month - 1];
			month++;
			if (days <= st[month - 1])
				break;
		}
	}

	/*�������·ݣ���������*/
	day = days;
}

Date::Date(const Date& d)
{
	year = d.year;
	month = d.month;
	day = d.day;
}

/*��ӡ������*/
void Date::show()
{
	cout << year << "��" << month << "��" << day << "��" << endl;
}

/*����������*/
void Date::set(int y, int m, int d)
{
	bool leap;//����
	if (y >= 1900 && y <= 2099)
		year = y;
	else if (y != 0)
		year = 2000;
	
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))//�����ж�
		leap = 1;
	else
		leap = 0;
	int st[12] = { 31,28 + leap,31,30,31,30,31,31,30,31,30,31 };

	if (m >= 1 && m <= 12)
		month = m;
	else if (m != 0)
		month = 1;
	
	if (d >= 1 && d <= st[month - 1])
		day = d;
	else if (d == 0 && (day >= 1 && day <= st[month - 1]))
		;
	else
		day = 1;
	
}

/*��ȡ������*/
void Date::get(int& y, int& m, int& d)
{
	y = year;
	m = month;
	d = day;
}

/*Date ת int ����ת������*/
Date::operator int()
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

	days += day;

	return days;
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
	if (year != d.year || month != d.month || day != d.day)
		return true;
	else
		return false;
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

/*ǰ׺++*/
Date& Date:: operator++()
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
/*************************************************/
/* �������Ҫ������ȫ�ֺ�����ʵ�֣�����д�ڴ˴� */

/*�ж��Ƿ�����*/
void JudgeLeap(int year, bool& leap)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))//�����ж�
		leap = 1;
	else
		leap = 0;
}

/*<<������*/
ostream& operator << (ostream& out, const Date& date)
{
	out << date.year << "��" << date.month << "��" << date.day << "��";
	return out;
}

/*>>������*/
istream& operator >> (istream& in, Date& date)
{
	in >> date.year >> date.month >> date.day;
	
	bool leap;//����
	if (date.year >= 1900 && date.year <= 2099)
		;
	else
		date.year = 2000;
	if ((date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0))//�����ж�
		leap = 1;
	else
		leap = 0;
	int st[12] = { 31,28 + leap,31,30,31,30,31,31,30,31,30,31 };
	if (date.month >= 1 && date.month <= 12)
		;
	else
		date.month = 1;
	if (date.day >= 1 && date.day <= st[date.month - 1])
		;
	else
		date.day = 1;
		
	return in;
}

/*ͨ�����»�ȡ��������*/
int GetDaysByYM(int year, int month)
{
	bool leap;
	JudgeLeap(year, leap);
	int st[12] = { 31,28 + leap,31,30,31,30,31,31,30,31,30,31 };
	return st[month - 1];
}

/*Date+int �����+����*/
Date operator + (const Date& date, int days)
{
	Date now(date);
	if (days < 0)
		return now;
	
	now.day += days;
	while (now.day > GetDaysByYM(now.year, now.month))
	{
		now.day -= GetDaysByYM(now.year, now.month);
		now.month++;
		if (now.month > 12)
		{
			now.month = 1;
			++now.year;
		}
	}

	if (now.year > 2099)//Խ�紦��
		now.set(2099, 12, 31);
	return now;
}

/*int+Date �����+����*/
Date operator + (int days, const Date& date)
{
	Date now(date);
	if (days < 0)
		return now;

	now.day += days;
	while (now.day > GetDaysByYM(now.year, now.month))
	{
		now.day -= GetDaysByYM(now.year, now.month);
		++now.month;
		if (now.month > 12)
		{
			now.month = 1;
			++now.year;
		}
	}

	if (now.year > 2099)//Խ�紦��
		now.set(2099, 12, 31);

	return now;
}

/*Date-int �����-����*/
Date operator - (const Date& date, int days)
{
	Date now(date);
	if (days < 0)
		return now;

	now.day -= days;
	while (now.day <= 0)
	{
		now.month--;
		if (now.month < 1)
		{
			now.year--;
			now.month = 12;
		}
		now.day += GetDaysByYM(now.year, now.month);
	}

	if (now.year < 1900)
		now.set(1900, 1, 1);

	return now;
}

/*Date-Date �����-����*/
int operator - (const Date& d1, const Date& d2)
{
	int days = 0;
	Date big(d1), small(d2);
	int flag = 1;
	if (big < small)//����������Ǹ���
	{
		small = d1;
		big = d2;
		flag = -1;
	}
	while (small != big)
	{
		small = small + 1;
		days++;
	}

	return days * flag;
}