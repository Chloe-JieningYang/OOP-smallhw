/* 2050598 杨洁宁 通信 */
#pragma once

#include <iostream>
using namespace std;

#define MAX_SECONDS  60*60*24

class Time {
protected:
	int hour;
	int minute;
	int second;
public:
	Time();
	Time(int h, int m, int s);
	Time(const Time& t);
	Time(int seconds);

	void show();//打印
	void set(int h = 0, int m = 0, int s = 0);//重置
	void get(int& h, int& m, int& s);

	friend ostream& operator << (ostream& out, const Time& time);
	friend istream& operator >> (istream& in, Time& time);

	operator int() const;//类型转换函数

	Time& operator ++();//前缀++
	Time& operator --();//前缀--
	Time operator ++(int);//后缀++
	Time operator  --(int);//后缀--

	bool operator==(const Time& t);
	bool operator!=(const Time& t);
	bool operator>(const Time& t);
	bool operator<(const Time& t);
	bool operator>=(const Time& t);//>=
	bool operator<=(const Time& t);//<=

	friend Time operator +(const Time& t, int seconds);
	friend Time operator +(int seconds, const Time& t);
	friend Time operator -(const Time& t, int seconds);
	friend int operator -(const Time& t1, const Time& t2);
};