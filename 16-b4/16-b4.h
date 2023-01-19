/* 2050598 杨洁宁 通信 */

#pragma once

#include <iostream>
using namespace std;

/* 如果有其它全局函数需要声明，写于此处 */
void JudgeLeap(int year, bool& leap);//判断是否是闰年

int GetDaysByYM(int year, int month);/*通过年月获取当月天数*/
/* 如果有需要的宏定义、只读全局变量等，写于此处 */

/* 补全Date类的定义，所有成员函数均体外实现，不要在此处体内实现 */
class Date {
private:
	int year;
	int month;
	int day;
	/* 不允许添加数据成员 */
public:
	/* 根据需要定义所需的成员函数、友元函数等(不允许添加数据成员) */
	Date();
	Date(int y, int m, int d);
	Date(const Date& d);
	Date(int days);//转换构造函数
	void show();//打印
	void set(int y = 2000, int m = 1, int d = 1);//重置年月日
	void get(int& y, int& m, int& d);//获取年月日
	friend ostream& operator << (ostream& out, const Date& date);//运算符<<的重载
	friend istream& operator >> (istream& in, Date& date);//运算符>>的重载
	operator int();//类型转换函数
	bool operator==(const Date& d);//Date==Date ==重载
	bool operator!=(const Date& d);//Date!=Date !=重载
	bool operator>(const Date& d);//Date>Date >重载
	bool operator<(const Date& d);//Date<Date <重载
	bool operator>=(const Date& d);//>=
	bool operator<=(const Date& d);//<=
	Date& operator++();//前缀++
	Date& operator--();//前缀--
	Date operator++(int);//后缀++
	Date operator--(int);//后缀--
	friend Date operator + (const Date& date, int days);// Date+int 运算符+重载
	friend Date operator + (int days, const Date& date);// int+Date 运算符+重载
	friend Date operator - (const Date& date, int days);// Date-int 运算符-重载
	friend int operator - (const Date& d1, const Date& d2);   //Date-Date 运算符-重载
};

