/* 2050598 杨洁宁 通信 */

/* 允许添加需要的头文件、宏定义等 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "16-b5.h"
using namespace std;

/* 给出 TString 类的所有成员函数的体外实现 */




/*转换构造函数--字符数组*/
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
		if (content == NULL)//申请不成功
		{
			cout << "申请" << len + 1 << "字节空间失败" << endl;
			len = 0;
		}
		else//申请成功
		{
			strcpy(content, temp);
		}
	}
}


/*复制构造函数*/
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
		cout << "申请" << len + 1 << "字节空间失败" << endl;
		len = 0;
		return;
	}
	strcpy(content, s1.content);
}

/*析构函数*/
TString::~TString()
{
	if (content != NULL)
		delete[]content;
}

/*返回length*/
int TString::length()
{
	return len;
}

const char* TString::c_str()const
{
	return (const char*)(content);
}

/*=的重载*/
TString& TString::operator =(const TString& s1)
{
	if (&s1 == this)//避免自己给自己赋值
		return *this;
	if (s1.len == 0)//如果s1长度为0
	{
		if (content != NULL)
			delete[]content;
		content = NULL;
		len = 0;
		return *this;
	}
	if (content == NULL)//如果本来没有空间
	{
		content = new(nothrow)char[s1.len + 1];
		if (content == NULL)
		{
			cout << "申请" << s1.len + 1 << "字节失败" << endl;
			len = 0;
			return *this;
		}
		strcpy(content, s1.content);
		len = s1.len;
	}
	else//如果本来就有空间
	{
		content = renew(s1.len, content, len);
		if (len == s1.len)
			strcpy(content, s1.content);
	}
	return *this;
}

/*=的重载 参数为字符数组*/
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
	if (content == NULL)//本来没有空间
	{
		content = new(nothrow) char[newlen + 1];
		if (content == NULL)
		{
			cout << "申请" << newlen + 1 << "字节空间失败" << endl;
			len = 0;
			return *this;
		}
		strcpy(content, ch);
		len = newlen;
	}
	else//本来就有空间
	{
		content = renew(newlen, content, len);
		if (len == newlen)
			strcpy(content, ch);
	}
	return *this;
}

/*+=的重载 自加TS*/
TString& TString::operator +=(const TString& s1)
{
	if (s1.content == NULL || s1.len == 0)
	{
		return *this;
	}
	int newlen = len + s1.len;
	if (content == NULL)//如果原来没有空间
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
	else//原来就有空间
	{
		content = renew(newlen, content, len);
		if (len == newlen)
			strcat(content, s1.content);
	}
	return *this;
}

/*+= 字符串*/
TString& TString::operator +=(const char* temp)
{
	if (temp == NULL || strlen(temp) == 0)
		return *this;
	int newlen = len + strlen(temp);
	if (content == NULL)//如果本来没有空间
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
	else//如果本来有空间
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

/* ×= n*/
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

/* 如果有需要的其它全局函数的实现，可以写于此处 */

void fail(const int size)
{
	cout << "申请" << size << "字节空间不成功" << endl;
}

/*输出运算符的重载*/
ostream& operator << (ostream& out, const TString& s1)
{
	if (s1.content == NULL)
		out << "<NULL>";
	else
		out << s1.content;
	return out;
}

/*输入运算符的重载*/
istream& operator >> (istream& in, TString& s1)
{
	char ch[80] = { '\0' };
	in >> ch;
	int newlen = strlen(ch);
	if (s1.content != NULL)//如果已经有申请好的空间
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
			cout << "申请" << newlen + 1 << "字节空间失败，输入不成功" << endl;
			return in;
		}
		strcpy(s1.content, ch);
		s1.len = newlen;
	}
	return in;
}

/*申请新的空间*/
char* renew(int newlen, char* old, int& t_newlen)//如果申请成功t_newlen为newlen
{
	char* pnew;
	pnew = new(nothrow) char[newlen + 1];
	if (pnew == NULL)
	{
		cout << "申请" << newlen + 1 << "字节空间失败" << endl;
		return old;
	}
	strncpy(pnew, old, newlen);
	pnew[newlen] = '\0';
	delete[]old;
	old = pnew;
	t_newlen = newlen;
	return old;
}

/* TS+TS 重载*/
TString operator +(const TString& s1, const TString& s2)
{
	TString sum;
	int newlen = s1.len + s2.len;
	if (s1.len + s2.len == 0)//如果两个都是NULL
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
	if (s1.len != 0 && s1.content != NULL)//如果s1不是空
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

/* TS-TS 重载*/
TString operator -(const TString& s1, const TString& s2)
{
	TString res(s1);
	if (s1.content == NULL || s2.content == NULL || s2.len == 0)
		return res;
	char* pos = strstr(s1.content, s2.content);
	if (pos == NULL)//没找到
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

/*TS×n重载*/
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

/*!反转*/
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

/*求长度*/
int TStringLen(const TString& s1)
{
	if (s1.content == NULL)
		return 0;
	int len = strlen(s1.content);
	return len;
}

/*[]的重载*/
char& TString::operator [](const int n)
{
	return content[n];
}