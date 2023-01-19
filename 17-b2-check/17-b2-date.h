/* 2050598 杨洁宁 通信 */
#pragma once

#include <iostream>
using namespace std;

#define MAX_DAYS  73049

void JudgeLeap(int year, bool& leap);//判断是否是闰年

int GetDaysByYM(int year, int month);/*通过年月获取当月天数*/

class Date {
protected:
	int year;
	int month;
	int day;
public:
	Date();
	Date(int y, int m, int d);
	Date(const Date& d);
	Date(int days);//转换构造函数

	void show();//打印
	void set(int y = 1900, int m = 1, int d = 1);//重置年月日
	void get(int& y, int& m, int& d);//获取年月日

	Date& operator++();//前缀++
	Date& operator--();//前缀--
	Date operator++(int);//后缀++
	Date operator--(int);//后缀--

	bool operator==(const Date& d);//Date==Date ==重载
	bool operator!=(const Date& d);//Date!=Date !=重载
	bool operator>(const Date& d);//Date>Date >重载
	bool operator<(const Date& d);//Date<Date <重载
	bool operator>=(const Date& d);//>=
	bool operator<=(const Date& d);//<=

	friend ostream& operator << (ostream& out, const Date& date);//运算符<<的重载
	friend istream& operator >> (istream& in, Date& date);//运算符>>的重载

	operator int() const;//类型转换函数

	friend Date operator + (const Date& date, int days);// Date+int 运算符+重载
	friend Date operator + (int days, const Date& date);// int+Date 运算符+重载
	friend Date operator - (const Date& date, int days);// Date-int 运算符-重载
	friend int operator - (const Date& d1, const Date& d2);   //Date-Date 运算符-重载

};