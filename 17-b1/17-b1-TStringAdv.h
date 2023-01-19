/* 2050598 杨洁宁 通信 */
#pragma once


#include "17-b1-TString.h"
using namespace std;


class TStringAdv :public TString
{
public:
	/*构造函数*/
	TStringAdv(const char* temp = NULL);
	TStringAdv(const TStringAdv& s1);

    //赋新值
	TStringAdv& assign(const TStringAdv& ts2);
	TStringAdv& assign(const char* s);

	//追加
	TStringAdv& append(const TStringAdv& ts2);
	TStringAdv& append(const char* s);
	TStringAdv& append(const char& c);

	//插入
	TStringAdv& insert(const TStringAdv& ts2, int pos);
	TStringAdv& insert(const char* s, int pos);
	TStringAdv& insert(const char& c, int pos);

	//删除
	TStringAdv& erase(const TStringAdv& ts2);
	TStringAdv& erase(const char* s);
	TStringAdv& erase(const char& c);

	//取子串
	TStringAdv substr(const int pos, const int len = INT_MAX);

	//取指定位置字符
	char& at(const int n);


	//friend ostream& operator << (ostream& out, const TStringAdv& s1);//运算符<<的重载
	//friend istream& operator >> (istream& in, TStringAdv& s1);//运算符>>的重载
	friend TStringAdv operator +(const TStringAdv& s1, const TStringAdv& s2);//TS+TS重载
	friend TStringAdv operator +(const TStringAdv& s1, const char c);//TS+c
	friend TStringAdv operator +(const char c, const TStringAdv& s1);//TS+c
	friend TStringAdv operator -(const TStringAdv& s1, const TStringAdv& s2);//TS-TS重载
	friend TStringAdv operator -(const TStringAdv& s1, const char c);//TS-c
	friend TStringAdv operator *(const TStringAdv& s1, const int n);//TS*n重载
	friend TStringAdv operator !(const TStringAdv& s1);//! 反转
	/*
	friend int operator ==(const TStringAdv& s1, const TStringAdv& s2);//==
	friend int operator !=(const TStringAdv& s1, const TStringAdv& s2);//!=
	friend int operator >(const TStringAdv& s1, const TStringAdv& s2);//>
	friend int operator <(const TStringAdv& s1, const TStringAdv& s2);//<
	friend int operator >=(const TStringAdv& s1, const TStringAdv& s2);//>=
	friend int operator <=(const TStringAdv& s1, const TStringAdv& s2);//<=
	friend int TStringLen(const TStringAdv& s1);//求长度
	*/
};