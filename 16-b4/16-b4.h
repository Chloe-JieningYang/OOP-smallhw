/* 2050598 ����� ͨ�� */

#pragma once

#include <iostream>
using namespace std;

/* ���������ȫ�ֺ�����Ҫ������д�ڴ˴� */
void JudgeLeap(int year, bool& leap);//�ж��Ƿ�������

int GetDaysByYM(int year, int month);/*ͨ�����»�ȡ��������*/
/* �������Ҫ�ĺ궨�塢ֻ��ȫ�ֱ����ȣ�д�ڴ˴� */

/* ��ȫDate��Ķ��壬���г�Ա����������ʵ�֣���Ҫ�ڴ˴�����ʵ�� */
class Date {
private:
	int year;
	int month;
	int day;
	/* ������������ݳ�Ա */
public:
	/* ������Ҫ��������ĳ�Ա��������Ԫ������(������������ݳ�Ա) */
	Date();
	Date(int y, int m, int d);
	Date(const Date& d);
	Date(int days);//ת�����캯��
	void show();//��ӡ
	void set(int y = 2000, int m = 1, int d = 1);//����������
	void get(int& y, int& m, int& d);//��ȡ������
	friend ostream& operator << (ostream& out, const Date& date);//�����<<������
	friend istream& operator >> (istream& in, Date& date);//�����>>������
	operator int();//����ת������
	bool operator==(const Date& d);//Date==Date ==����
	bool operator!=(const Date& d);//Date!=Date !=����
	bool operator>(const Date& d);//Date>Date >����
	bool operator<(const Date& d);//Date<Date <����
	bool operator>=(const Date& d);//>=
	bool operator<=(const Date& d);//<=
	Date& operator++();//ǰ׺++
	Date& operator--();//ǰ׺--
	Date operator++(int);//��׺++
	Date operator--(int);//��׺--
	friend Date operator + (const Date& date, int days);// Date+int �����+����
	friend Date operator + (int days, const Date& date);// int+Date �����+����
	friend Date operator - (const Date& date, int days);// Date-int �����-����
	friend int operator - (const Date& d1, const Date& d2);   //Date-Date �����-����
};

