/* 2050598 ����� ͨ�� */
#pragma once

#include <iostream>
using namespace std;

#define MAX_DAYS  73049

void JudgeLeap(int year, bool& leap);//�ж��Ƿ�������

int GetDaysByYM(int year, int month);/*ͨ�����»�ȡ��������*/

class Date {
protected:
	int year;
	int month;
	int day;
public:
	Date();
	Date(int y, int m, int d);
	Date(const Date& d);
	Date(int days);//ת�����캯��

	void show();//��ӡ
	void set(int y = 1900, int m = 1, int d = 1);//����������
	void get(int& y, int& m, int& d);//��ȡ������

	Date& operator++();//ǰ׺++
	Date& operator--();//ǰ׺--
	Date operator++(int);//��׺++
	Date operator--(int);//��׺--

	bool operator==(const Date& d);//Date==Date ==����
	bool operator!=(const Date& d);//Date!=Date !=����
	bool operator>(const Date& d);//Date>Date >����
	bool operator<(const Date& d);//Date<Date <����
	bool operator>=(const Date& d);//>=
	bool operator<=(const Date& d);//<=

	friend ostream& operator << (ostream& out, const Date& date);//�����<<������
	friend istream& operator >> (istream& in, Date& date);//�����>>������

	operator int() const;//����ת������

	friend Date operator + (const Date& date, int days);// Date+int �����+����
	friend Date operator + (int days, const Date& date);// int+Date �����+����
	friend Date operator - (const Date& date, int days);// Date-int �����-����
	friend int operator - (const Date& d1, const Date& d2);   //Date-Date �����-����

};