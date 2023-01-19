/* 2050598 ����� ͨ�� */
#pragma once


#include "17-b1-TString.h"
using namespace std;


class TStringAdv :public TString
{
public:
	/*���캯��*/
	TStringAdv(const char* temp = NULL);
	TStringAdv(const TStringAdv& s1);

    //����ֵ
	TStringAdv& assign(const TStringAdv& ts2);
	TStringAdv& assign(const char* s);

	//׷��
	TStringAdv& append(const TStringAdv& ts2);
	TStringAdv& append(const char* s);
	TStringAdv& append(const char& c);

	//����
	TStringAdv& insert(const TStringAdv& ts2, int pos);
	TStringAdv& insert(const char* s, int pos);
	TStringAdv& insert(const char& c, int pos);

	//ɾ��
	TStringAdv& erase(const TStringAdv& ts2);
	TStringAdv& erase(const char* s);
	TStringAdv& erase(const char& c);

	//ȡ�Ӵ�
	TStringAdv substr(const int pos, const int len = INT_MAX);

	//ȡָ��λ���ַ�
	char& at(const int n);


	//friend ostream& operator << (ostream& out, const TStringAdv& s1);//�����<<������
	//friend istream& operator >> (istream& in, TStringAdv& s1);//�����>>������
	friend TStringAdv operator +(const TStringAdv& s1, const TStringAdv& s2);//TS+TS����
	friend TStringAdv operator +(const TStringAdv& s1, const char c);//TS+c
	friend TStringAdv operator +(const char c, const TStringAdv& s1);//TS+c
	friend TStringAdv operator -(const TStringAdv& s1, const TStringAdv& s2);//TS-TS����
	friend TStringAdv operator -(const TStringAdv& s1, const char c);//TS-c
	friend TStringAdv operator *(const TStringAdv& s1, const int n);//TS*n����
	friend TStringAdv operator !(const TStringAdv& s1);//! ��ת
	/*
	friend int operator ==(const TStringAdv& s1, const TStringAdv& s2);//==
	friend int operator !=(const TStringAdv& s1, const TStringAdv& s2);//!=
	friend int operator >(const TStringAdv& s1, const TStringAdv& s2);//>
	friend int operator <(const TStringAdv& s1, const TStringAdv& s2);//<
	friend int operator >=(const TStringAdv& s1, const TStringAdv& s2);//>=
	friend int operator <=(const TStringAdv& s1, const TStringAdv& s2);//<=
	friend int TStringLen(const TStringAdv& s1);//�󳤶�
	*/
};