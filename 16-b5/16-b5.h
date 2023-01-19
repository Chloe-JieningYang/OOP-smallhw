/* 2050598 ����� ͨ�� */

#pragma once

#include <iostream>
using namespace std;

/* ��ȫTString��Ķ��壬���г�Ա����������ʵ�֣���Ҫ�ڴ˴�����ʵ�� */
class TString {
	private:
		char *content;
		int   len;
		/* ������Ҫ������������ݳ�Ա����Ա��������Ԫ������ */
	public:
		/* ������Ҫ������������ݳ�Ա����Ա��������Ԫ������ */
		
		TString(const char* temp = NULL);//ת�����캯��--�ַ�����
		TString(const TString& s1);
		~TString();
		friend char* renew(int newlen, char* old, int& t_newlen);//�����¿ռ�

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
		char& operator [](const int n);//[]����

		friend ostream& operator << (ostream& out, const TString& s1);//�����<<������
		friend istream& operator >> (istream& in, TString& s1);//�����>>������
		friend TString operator +(const TString& s1, const TString& s2);//TS+TS����
		friend TString operator +(const TString& s1, const char c);//TS+c
		friend TString operator +(const char c, const TString& s1);//TS+c
		friend TString operator -(const TString& s1, const TString& s2);//TS-TS����
		friend TString operator -(const TString& s1, const char c);//TS-c
		friend TString operator *(const TString& s1, const int n);//TS*n����
		friend TString operator !(const TString& s1);//! ��ת
		friend int operator ==(const TString& s1, const TString& s2);//==
		friend int operator !=(const TString& s1, const TString& s2);//!=
		friend int operator >(const TString& s1, const TString& s2);//>
		friend int operator <(const TString& s1, const TString& s2);//<
		friend int operator >=(const TString& s1, const TString& s2);//>=
		friend int operator <=(const TString& s1, const TString& s2);//<=
		friend int TStringLen(const TString& s1);//�󳤶�
};

/* ���������ȫ�ֺ�����Ҫ������д�ڴ˴� */

void fail(const int size);//���벻�ɹ���ʾ
char* renew(int newlen, char* old, int& t_newlen);//�����¿ռ�

/* �������Ҫ�ĺ궨�塢ֻ��ȫ�ֱ����ȣ�д�ڴ˴� */
