/* 2050598 ����� ͨ�� */

/* ���������Ҫ��ͷ�ļ����궨��� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "16-b5.h"
using namespace std;

/* ���� TString ������г�Ա����������ʵ�� */




/*ת�����캯��--�ַ�����*/
TString::TString(const char *temp)
{
	if (temp == NULL || strlen(temp) == 0)
	{
		len = 0;
		content = NULL;
	}
	else
	{
		len = strlen(temp);
		content = new(nothrow)char[len + 1];
		if (content == NULL)//���벻�ɹ�
		{
			cout << "����" << len + 1 << "�ֽڿռ�ʧ��" << endl;
			len = 0;
		}
		else//����ɹ�
		{
			strcpy(content, temp);
		}
	}
}


/*���ƹ��캯��*/
TString::TString(const TString& s1)
{
	len = s1.len;
	if (s1.content == NULL)
	{
		content = NULL;
		return;
	}
	content = new(nothrow)char[len + 1];
	if (content == NULL)
	{
		cout << "����" << len + 1 << "�ֽڿռ�ʧ��" << endl;
		len = 0;
		return;
	}
	strcpy(content, s1.content);
}

/*��������*/
TString::~TString()
{
	if (content != NULL)
		delete[]content;
}

/*����length*/
int TString::length()
{
	return len;
}

const char* TString::c_str()const
{
	return (const char*)(content);
}

/*=������*/
TString& TString::operator =(const TString& s1)
{
	if (&s1 == this)//�����Լ����Լ���ֵ
		return *this;
	if (s1.len == 0)//���s1����Ϊ0
	{
		if (content != NULL)
			delete[]content;
		content = NULL;
		len = 0;
		return *this;
	}
	if (content == NULL)//�������û�пռ�
	{
		content = new(nothrow)char[s1.len + 1];
		if (content == NULL)
		{
			cout << "����" << s1.len + 1 << "�ֽ�ʧ��" << endl;
			len = 0;
			return *this;
		}
		strcpy(content, s1.content);
		len = s1.len;
	}
	else//����������пռ�
	{
		content = renew(s1.len, content, len);
		if (len == s1.len)
			strcpy(content, s1.content);
	}
	return *this;
}

/*=������ ����Ϊ�ַ�����*/
TString& TString::operator =(const char* ch)
{
	if (ch == NULL || strlen(ch) == 0)
	{
		if (content != NULL)
			delete[]content;
		content = NULL;
		len = 0;
		return *this;
	}

	int newlen = strlen(ch);
	if (content == NULL)//����û�пռ�
	{
		content = new(nothrow) char[newlen + 1];
		if (content == NULL)
		{
			cout << "����" << newlen + 1 << "�ֽڿռ�ʧ��" << endl;
			len = 0;
			return *this;
		}
		strcpy(content, ch);
		len = newlen;
	}
	else//�������пռ�
	{
		content = renew(newlen, content, len);
		if (len == newlen)
			strcpy(content, ch);
	}
	return *this;
}

/*+=������ �Լ�TS*/
TString& TString::operator +=(const TString& s1)
{
	if (s1.content == NULL || s1.len == 0)
	{
		return *this;
	}
	int newlen = len + s1.len;
	if (content == NULL)//���ԭ��û�пռ�
	{
		content = new(nothrow)char[newlen + 1];
		if (content == NULL)
		{
			fail(newlen + 1);
			len = 0;
			return *this;
		}
		strcpy(content, s1.content);
		len = newlen;
	}
	else//ԭ�����пռ�
	{
		content = renew(newlen, content, len);
		if (len == newlen)
			strcat(content, s1.content);
	}
	return *this;
}

/*+= �ַ���*/
TString& TString::operator +=(const char* temp)
{
	if (temp == NULL || strlen(temp) == 0)
		return *this;
	int newlen = len + strlen(temp);
	if (content == NULL)//�������û�пռ�
	{
		content = new(nothrow) char[newlen + 1];
		if (content == NULL)
		{
			fail(newlen + 1);
			len = 0;
			return *this;
		}
		strcpy(content, temp);
		len = newlen;
	}
	else//��������пռ�
	{
		content = renew(newlen, content, len);
		if (len == newlen)
			strcat(content, temp);
	}
	return *this;
}

/* += char */
TString& TString::operator +=(const char c)
{
	int newlen = len + 1;
	if (content == NULL)
	{
		content = new(nothrow)char[sizeof(c) + 1];
		if (content == NULL)
		{
			fail(newlen + 1);
			len = 0;
			return *this;
		}
		content[0] = c;
		content[1] = '\0';
		len = newlen;
	}
	else
	{
		char ch[2] = { c,'\0' };
		content = renew(newlen, content, len);
		if (len == newlen)
			strcat(content, ch);
	}
	return *this;
}

/*-= TS*/
TString& TString::operator -=(const TString& s1)
{
	if (content == NULL)
		return *this;
	char* pos = strstr(content, s1.content);
	if (pos == NULL)
		return *this;
	int p = pos - content;
	int newlen = len - s1.len;
	strcpy(content + p, content + p + s1.len);
	content = renew(newlen, content, len);
	return *this;
}

TString& TString::operator -=(const char c)
{
	char ch[2] = { c,'\0' };
	if (content == NULL)
		return *this;
	char* pos = strstr(content, ch);
	if (pos == NULL)
		return *this;
	int p = pos - content;
	int newlen = len - 1;
	strcpy(content + p, content + p + 1);
	content = renew(newlen, content, len);
	return *this;
}

/* ��= n*/
TString& TString::operator *=(const int n)
{
	if (n == 1 || content == NULL)
		return *this;
	int newlen = len * n;
	char* temp;
	temp = new(nothrow)char[len + 1];
	if (temp == NULL)
		return *this;
	strcpy(temp, content);
	content = renew(newlen, content, len);
	if (len == newlen)
	{
		for (int k = 1; k <= n - 1; k++)
			strcat(content, temp);
	}
	delete[]temp;
	return *this;
}

/* �������Ҫ������ȫ�ֺ�����ʵ�֣�����д�ڴ˴� */

void fail(const int size)
{
	cout << "����" << size << "�ֽڿռ䲻�ɹ�" << endl;
}

/*��������������*/
ostream& operator << (ostream& out, const TString& s1)
{
	if (s1.content == NULL)
		out << "<NULL>";
	else
		out << s1.content;
	return out;
}

/*���������������*/
istream& operator >> (istream& in, TString& s1)
{
	char ch[80] = { '\0' };
	in >> ch;
	int newlen = strlen(ch);
	if (s1.content != NULL)//����Ѿ�������õĿռ�
	{
		s1.content = renew(newlen, s1.content, s1.len);
		if (s1.len == newlen)
			strcpy(s1.content, ch);
	}
	else
	{
		s1.content = new(nothrow)char[newlen + 1];
		if (s1.content == NULL)
		{
			cout << "����" << newlen + 1 << "�ֽڿռ�ʧ�ܣ����벻�ɹ�" << endl;
			return in;
		}
		strcpy(s1.content, ch);
		s1.len = newlen;
	}
	return in;
}

/*�����µĿռ�*/
char* renew(int newlen, char* old, int& t_newlen)//�������ɹ�t_newlenΪnewlen
{
	char* pnew;
	pnew = new(nothrow) char[newlen + 1];
	if (pnew == NULL)
	{
		cout << "����" << newlen + 1 << "�ֽڿռ�ʧ��" << endl;
		return old;
	}
	strncpy(pnew, old, newlen);
	pnew[newlen] = '\0';
	delete[]old;
	old = pnew;
	t_newlen = newlen;
	return old;
}

/* TS+TS ����*/
TString operator +(const TString& s1, const TString& s2)
{
	TString sum;
	int newlen = s1.len + s2.len;
	if (s1.len + s2.len == 0)//�����������NULL
	{
		return sum;
	}
	sum.content = new(nothrow) char[newlen + 1];
	if (sum.content == NULL)
	{
		fail(newlen + 1);
		sum.len = 0;
		return sum;
	}
	if (s1.len != 0 && s1.content != NULL)//���s1���ǿ�
	{
		strcpy(sum.content, s1.content);
		if (s2.len != 0 && s2.content != NULL)
			strcat(sum.content, s2.content);
	}
	else
	{
		strcpy(sum.content, s2.content);
	}
	sum.len = newlen;
	return sum;
}

/* TS+c */
TString operator +(const TString& s1, const char c)
{
	TString sum;
	char ch[2] = { c,'\0' };
	sum = s1 + ch;
	return sum;
}

/* c+TS */
TString operator +( const char c,const TString& s1)
{
	TString sum;
	char ch[2] = { c,'\0' };
	sum = ch + s1;
	return sum;
}

/* TS-TS ����*/
TString operator -(const TString& s1, const TString& s2)
{
	TString res(s1);
	if (s1.content == NULL || s2.content == NULL || s2.len == 0)
		return res;
	char* pos = strstr(s1.content, s2.content);
	if (pos == NULL)//û�ҵ�
		return res;
	int newlen = s1.len - s2.len;
	int p = pos - s1.content;
	//strcpy(res.content + p, s1.content + p + s2.len);
	for (int k = p; res.content[k + s2.len] != '\0'; k++)
	{
		res.content[k] = res.content[k + s2.len];
	}
	res.content[newlen] = '\0';
	res.content = renew(newlen, res.content, res.len);
	return res;
}

/* TS-c */
TString operator -(const TString& s1, const char c)
{
	TString res(s1);
	char ch[2] = { c,'\0' };
	res = s1 - ch;
	return res;
}

/*TS��n����*/
TString operator *(const TString& s1, const int n)
{
	TString res(s1);
	if (n == 1 || s1.content == NULL)
		return res;
	res.content = renew(n * s1.len, res.content, res.len);
	for (int k = 1; k <= n - 1; k++)
		strcat(res.content, s1.content);
	return res;
}

/*!��ת*/
TString operator !(const TString& s1)
{
	TString res(s1);
	if (s1.content == NULL)
		return res;
	for (int k = 0; k <= s1.len - 1; k++)
		res.content[k] = s1.content[s1.len - 1 - k];
	return res;
}

/* == */
int operator ==(const TString& s1, const TString& s2)
{
	if (s1.content == NULL && s2.content == NULL)
		return 1;
	if (s1.content == NULL || s2.content == NULL)
		return 0;
	if (strcmp(s1.content, s2.content) == 0)
		return 1;
	else
		return 0;
}

/* != */
int operator !=(const TString& s1, const TString& s2)
{
	if (s1 == s2)
		return 0;
	else
		return 1;
}

/* > */
int operator >(const TString& s1, const TString& s2)
{
	if (s1.content == NULL && s2.content == NULL)
		return 0;
	if (s1.content == NULL)
		return 0;
	if (s2.content == NULL)
		return 1;
	if (strcmp(s1.content, s2.content) > 0)
		return 1;
	else
		return 0;
}

/* < */
int operator <(const TString& s1, const TString& s2)
{
	if (s1.content == NULL && s2.content == NULL)
		return 0;
	if (s1.content == NULL)
		return 1;
	if (s2.content == NULL)
		return 0;
	if (strcmp(s1.content, s2.content) < 0)
		return 1;
	else
		return 0;
}

/* >= */
int operator >=(const TString& s1, const TString& s2)
{
	if (s1 > s2 || s1 == s2)
		return 1;
	else
		return 0;
}

/* <= */
int operator <=(const TString& s1, const TString& s2)
{
	if (s1 < s2 || s1 == s2)
		return 1;
	else
		return 0;
}

/*�󳤶�*/
int TStringLen(const TString& s1)
{
	if (s1.content == NULL)
		return 0;
	int len = strlen(s1.content);
	return len;
}

/*[]������*/
char& TString::operator [](const int n)
{
	return content[n];
}