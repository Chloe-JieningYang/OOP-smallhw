/* 2050598 杨洁宁 通信 */
#pragma once

#include "17-b2-date.h"
#include "17-b2-time.h"

#include <iostream>
using namespace std;

class DateTime :public Date, public Time {
public:
	DateTime();
	DateTime(int y, int m, int d, int h, int min, int s);
	DateTime(const DateTime& dt);
	DateTime(long long seconds);
	
	void show();//打印
	void set(int y = 1900, int m = 1, int d = 1, int h = 0, int min = 0, int s = 0);
	void get(int& y, int& m, int& d, int& h, int& min, int& s);//取值

	operator long long() const;//类型转换函数

	DateTime& operator++();//前缀++
	DateTime& operator--();//前缀--
	DateTime operator++(int);//后缀++
	DateTime operator--(int);//后缀--

	bool operator==(const DateTime& d);
	bool operator!=(const DateTime& d);
	bool operator>(const DateTime& d);
	bool operator<(const DateTime& d);
	bool operator>=(const DateTime& d);//>=
	bool operator<=(const DateTime& d);//<=

	friend ostream& operator << (ostream& out, const DateTime& dt);//运算符<<的重载
	friend istream& operator >> (istream& in, DateTime& dt);//运算符>>的重载

	friend DateTime operator +(const DateTime& dt, long long seconds);
	friend DateTime operator +(const DateTime& dt, int seconds);
	friend DateTime operator +(long long seconds, const DateTime& dt);
	friend DateTime operator +(int seconds, const DateTime& dt);
	friend DateTime operator -(const DateTime& dt, long long seconds);
	friend DateTime operator -(const DateTime& dt, int seconds);
	friend long long operator -(const DateTime& dt1, const DateTime& dt2);
};