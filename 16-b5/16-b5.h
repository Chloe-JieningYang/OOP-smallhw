/* 2050598 杨洁宁 通信 */

#pragma once

#include <iostream>
using namespace std;

/* 补全TString类的定义，所有成员函数均体外实现，不要在此处体内实现 */
class TString {
	private:
		char *content;
		int   len;
		/* 根据需要定义所需的数据成员、成员函数、友元函数等 */
	public:
		/* 根据需要定义所需的数据成员、成员函数、友元函数等 */
		
		TString(const char* temp = NULL);//转换构造函数--字符数组
		TString(const TString& s1);
		~TString();
		friend char* renew(int newlen, char* old, int& t_newlen);//申请新空间

		int length();
		const char* c_str()const;
		TString& operator =(const TString& s1);
		TString& operator =(const char* ch);
		TString& operator +=(const TString& s1);//+= TS
		TString& operator +=(const char* temp);//+= char*
		TString& operator +=(const char c);//+= char
		TString& operator -=(const TString& s1);//-= TS
		TString& operator -=(const char c);//-= char
		TString& operator *=(const int n);//*= n
		char& operator [](const int n);//[]重载

		friend ostream& operator << (ostream& out, const TString& s1);//运算符<<的重载
		friend istream& operator >> (istream& in, TString& s1);//运算符>>的重载
		friend TString operator +(const TString& s1, const TString& s2);//TS+TS重载
		friend TString operator +(const TString& s1, const char c);//TS+c
		friend TString operator +(const char c, const TString& s1);//TS+c
		friend TString operator -(const TString& s1, const TString& s2);//TS-TS重载
		friend TString operator -(const TString& s1, const char c);//TS-c
		friend TString operator *(const TString& s1, const int n);//TS*n重载
		friend TString operator !(const TString& s1);//! 反转
		friend int operator ==(const TString& s1, const TString& s2);//==
		friend int operator !=(const TString& s1, const TString& s2);//!=
		friend int operator >(const TString& s1, const TString& s2);//>
		friend int operator <(const TString& s1, const TString& s2);//<
		friend int operator >=(const TString& s1, const TString& s2);//>=
		friend int operator <=(const TString& s1, const TString& s2);//<=
		friend int TStringLen(const TString& s1);//求长度
};

/* 如果有其它全局函数需要声明，写于此处 */

void fail(const int size);//申请不成功提示
char* renew(int newlen, char* old, int& t_newlen);//申请新空间

/* 如果有需要的宏定义、只读全局变量等，写于此处 */
