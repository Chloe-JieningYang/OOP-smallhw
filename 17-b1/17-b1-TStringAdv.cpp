/* 2050598 ����� ͨ�� */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <climits>
#include "17-b1-TStringAdv.h"
using namespace std;

/*���캯��*/
TStringAdv::TStringAdv(const char* temp) :TString(temp)
{
	return;
}

TStringAdv::TStringAdv(const TStringAdv& s1) :TString(s1)
{
	return;
}

/*����ֵ*/
TStringAdv& TStringAdv::assign(const TStringAdv& ts2)
{
	len = ts2.len;
	if (ts2.content == NULL)
	{
		content = NULL;
		return *this;
	}
	content = new(nothrow)char[len + 1];
	if (content == NULL)
	{
		cout << "����" << len + 1 << "�ֽڿռ�ʧ��" << endl;
		len = 0;
		return *this;
	}
	strcpy(content, ts2.content);
	return *this;
}

/*����ֵ*/
TStringAdv& TStringAdv::assign(const char* s)
{
	if (s == NULL || strlen(s) == 0)
	{
		len = 0;
		content = NULL;
		return *this;
	}
	else
	{
		len = strlen(s);
		content = new(nothrow)char[len + 1];
		if (content == NULL)//���벻�ɹ�
		{
			cout << "����" << len + 1 << "�ֽڿռ�ʧ��" << endl;
			len = 0;
		}
		else//����ɹ�
		{
			strcpy(content, s);
		}
	}
	return *this;
}

/*׷��*/
TStringAdv& TStringAdv::append(const TStringAdv& ts2)
{
	if (ts2.content == NULL || ts2.len == 0)
	{
		return *this;
	}
	int newlen = len + ts2.len;
	if (content == NULL)//���ԭ��û�пռ�
	{
		content = new(nothrow)char[newlen + 1];
		if (content == NULL)
		{
			fail(newlen + 1);
			len = 0;
			return *this;
		}
		strcpy(content, ts2.content);
		len = newlen;
	}
	else//ԭ�����пռ�
	{
		content = renew(newlen, content, len);
		if (len == newlen)
			strcat(content, ts2.content);
	}
	return *this;
}

/*׷��*/
TStringAdv& TStringAdv::append(const char* s)
{
	if (s == NULL || strlen(s) == 0)
		return *this;
	int newlen = len + strlen(s);
	if (content == NULL)//�������û�пռ�
	{
		content = new(nothrow) char[newlen + 1];
		if (content == NULL)
		{
			fail(newlen + 1);
			len = 0;
			return *this;
		}
		strcpy(content, s);
		len = newlen;
	}
	else//��������пռ�
	{
		content = renew(newlen, content, len);
		if (len == newlen)
			strcat(content, s);
	}
	return *this;
}

TStringAdv& TStringAdv::append(const char& c)
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


/*����*/
TStringAdv& TStringAdv::insert(const TStringAdv& ts2, int pos)
{
	if (pos < 1 || pos > len + 1 || ts2.content == NULL || ts2.len == 0)//���posλ�÷Ƿ���ts2Ϊ��
		return *this;
	int newlen = len + ts2.len;
	if (content == NULL)
	{
		content = new(nothrow)char[newlen + 1];
		if (content == NULL)
		{
			fail(newlen + 1);
			len = 0;
			return *this;
		}
		strcpy(content, ts2.content);
		len = newlen;
	}
	else//�����пռ�
	{
		int oldlen = len;
		content = renew(newlen, content, len);
		if (len == newlen)
		{
			for (int k = oldlen - 1; k >= pos - 1; k--)//ԭ��λ���ϵ��ַ�������
				content[k + ts2.len] = content[k];
			memcpy(content + pos - 1, ts2.content, ts2.len);
		}
	}
	return *this;
}

/*����*/
TStringAdv& TStringAdv::insert(const char* s, int pos)
{
	int slen = strlen(s);
	if (pos < 1 || pos > len + 1 || s == NULL || slen == 0)//���posλ�÷Ƿ���ts2Ϊ��
		return *this;
	int newlen = len + slen;
	if (content == NULL)
	{
		content = new(nothrow)char[newlen + 1];
		if (content == NULL)
		{
			fail(newlen + 1);
			len = 0;
			return *this;
		}
		strcpy(content, s);
		len = newlen;
	}
	else
	{
		int oldlen = len;
		content = renew(newlen, content, len);
		if (len == newlen)
		{
			for (int k = oldlen - 1; k >= pos - 1; k--)//ԭ��λ���ϵ��ַ�������
				content[k + slen] = content[k];
			memcpy(content + pos - 1, s, slen);
		}
	}
	return *this;
}

/*����*/
TStringAdv& TStringAdv::insert(const char& c, int pos)
{
	if (pos < 1 || pos > len + 1)
		return *this;
	int newlen = len + 1;
	if (content == NULL)
	{
		content = new(nothrow)char[newlen + 1];
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
		int oldlen = len;
		content = renew(newlen, content, len);
		if (len == newlen)
		{
			for (int k = oldlen - 1; k >= pos - 1; k--)//ԭ��λ���ϵ��ַ�������
				content[k + 1] = content[k];
			content[pos - 1] = c;
		}
	}
	return *this;
}

/*ɾ��*/
TStringAdv& TStringAdv::erase(const TStringAdv& ts2)
{
	if (content == NULL || ts2.len == 0)
		return *this;
	char* pos = strstr(content, ts2.content);
	if (pos == NULL)
		return *this;
	int p = pos - content;
	int newlen = len - ts2.len;
	strcpy(content + p, content + p + ts2.len);
	content = renew(newlen, content, len);
	return *this;
}

/*ɾ��*/
TStringAdv& TStringAdv::erase(const char* s)
{
	if (content == NULL || strlen(s) == 0)
		return *this;
	char* pos = strstr(content, s);
	if (pos == NULL)
		return *this;
	int p = pos - content;
	int slen = strlen(s);
	int newlen = len - slen;
	strcpy(content + p, content + p + slen);
	content = renew(newlen, content, len);
	return *this;
}

/*ɾ��*/
TStringAdv& TStringAdv::erase(const char& c)
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

/*ȡ���Ӵ�*/
TStringAdv TStringAdv::substr(const int pos, const int len)
{
	TStringAdv res;
	if (pos<1 || pos>this->len || len <= 0)
		return res;
	int minlen;
	if (this->len - pos + 1 < len)
	{
		minlen = this->len - pos + 1;
	}
	else
		minlen = len;
	res.content = new(nothrow)char[minlen + 1];
	if (res.content == NULL)
	{
		fail(minlen + 1);
		res.len = 0;
		return res;
	}
	memcpy(res.content, content + pos - 1, minlen);
	res.content[minlen] = '\0';
	res.len = minlen;
	return res;
}

/*ȡ�ַ�*/
char& TStringAdv::at(const int n)
{
	return content[n];
}

/**************
    ��Ԫ����
***************/

/* + */
TStringAdv operator +(const TStringAdv& s1, const TStringAdv& s2)
{
	TStringAdv sum;
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

/* + */
TStringAdv operator +(const TStringAdv& s1, const char c)
{
	TStringAdv sum;
	char ch[2] = { c,'\0' };
	sum = s1 + ch;
	return sum;
}

/* + */
TStringAdv operator +(const char c, const TStringAdv& s1)
{
	TStringAdv sum;
	char ch[2] = { c,'\0' };
	sum = ch + s1;
	return sum;
}

/* - */
TStringAdv operator -(const TStringAdv& s1, const TStringAdv& s2)
{
	TStringAdv res(s1);
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

/* - */
TStringAdv operator -(const TStringAdv& s1, const char c)
{
	TStringAdv res(s1);
	char ch[2] = { c,'\0' };
	res = s1 - ch;
	return res;
}

/* �� */
TStringAdv operator *(const TStringAdv& s1, const int n)
{
	TStringAdv res(s1);
	if (n == 1 || s1.content == NULL)
		return res;
	res.content = renew(n * s1.len, res.content, res.len);
	for (int k = 1; k <= n - 1; k++)
		strcat(res.content, s1.content);
	return res;
}

/*��ת*/
TStringAdv operator !(const TStringAdv& s1)
{
	TStringAdv res(s1);
	if (s1.content == NULL)
		return res;
	for (int k = 0; k <= s1.len - 1; k++)
		res.content[k] = s1.content[s1.len - 1 - k];
	return res;
}