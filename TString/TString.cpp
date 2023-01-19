/* 2050598 通信 杨洁宁 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

struct content//用链表连接字符串
{
	char* con;
	content* next;
};


class TString
{
private:
	content* head;
	int len;
public:
	TString(const char* temp = NULL);
	~TString();
	int length();
	
	TString& operator +=(const char* temp);

	friend int operator ==(const TString& s1, const char* temp);
	friend int operator !=(const TString& s1, const char* temp);
};

TString::TString(const char* temp)
{
	if (temp == NULL || strlen(temp) == 0)
	{
		len = 0;
		head = new(nothrow)content[1];
		if (head == NULL)
			return;
		head->con = NULL;
		head->next = NULL;
	}
	else
	{
		len = strlen(temp);
		head = new(nothrow)content[1];
		if (head == NULL)//申请不成功
		{
			cout << "申请" << len + 1 << "字节空间失败" << endl;
			len = 0;
		}
		else//申请成功
		{
			strcpy(head->con, temp);
			head->next = NULL;
		}
	}
}

TString::~TString()
{
	content* p = head;
	content* temp;
	while (p != NULL)
	{
		temp = p;
		p = p->next;
		if (temp->con != NULL)
			delete[]temp->con;//先释放字符串
		delete temp;//再释放结点
	}
}

int TString::length()
{
	return len;
}

TString& TString::operator +=(const char* temp)
{
	int lent = strlen(temp);
	content* p = head;
	/*找到最后一个结点*/
	while (1)
	{
		if (p->next != NULL)
			p = p->next;
		else
			break;
	}
	/*当前结点内容是否为空*/
	content* last;
	if (p->con != NULL)
	{
		last = p;
		p = p->next;
		p = new(nothrow) content;
		if (p == NULL)
			return *this;
		last->next = p;//连上
	}
	p->con = new(nothrow) char[lent + 1];
	if (p->con == NULL)
	{
		delete p;
		return *this;
	}
	p->next = NULL;
	memcpy(p->con, temp, lent + 1);
	len += lent;

	return *this;
}

int operator ==(const TString& s1, const char* temp)
{
	int lent = strlen(temp);
	if (s1.len != lent)
		return 0;
	content* p = s1.head;
	int count = 0;
	while (p != NULL)
	{
		if (p->con != NULL)
		{
			for (int k = 0; p->con[k] != '\0'; k++)
			{
				if (p->con[k] != temp[count])
					return 0;
				count++;
			}
		}
		else
			break;
		p = p->next;
	}
	return 1;
}

int operator !=(const TString& s1, const char* temp)
{
	if (s1 == temp)
		return 0;
	else
		return 1;
}