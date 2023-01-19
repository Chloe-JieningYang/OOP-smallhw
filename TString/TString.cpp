/* 2050598 ͨ�� ����� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

struct content//�����������ַ���
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
		if (head == NULL)//���벻�ɹ�
		{
			cout << "����" << len + 1 << "�ֽڿռ�ʧ��" << endl;
			len = 0;
		}
		else//����ɹ�
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
			delete[]temp->con;//���ͷ��ַ���
		delete temp;//���ͷŽ��
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
	/*�ҵ����һ�����*/
	while (1)
	{
		if (p->next != NULL)
			p = p->next;
		else
			break;
	}
	/*��ǰ��������Ƿ�Ϊ��*/
	content* last;
	if (p->con != NULL)
	{
		last = p;
		p = p->next;
		p = new(nothrow) content;
		if (p == NULL)
			return *this;
		last->next = p;//����
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