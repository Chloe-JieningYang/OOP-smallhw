/* 2050598 ����� ͨ�� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

/* �Ӵ˴�������滻��֮�䣬����������Ķ��弰ʵ��
	1��������ȫ������������const��#define��
	2���������������ϵͳͷ�ļ�
*/ 
class integral {
protected:
	double a;
	double b;
	double n;
public:
	virtual int type();
	virtual char* value() = 0;//���麯��
	friend istream& operator >> (istream& in, integral& i);
};

int integral::type()
{
	return 0;//0Ϊ��������
}

istream& operator >> (istream& in, integral& i)
{
	if (i.type() == 1)
	{
		cout << "������sinxdx�����ޡ����޼����仮������" << endl;
	}
	else if (i.type() == 2)
	{
		cout << "������cosxdx�����ޡ����޼����仮������" << endl;
	}
	else if (i.type() == 3)
	{
		cout << "������e^xdx�����ޡ����޼����仮������" << endl;
	}

	in >> i.a >> i.b >> i.n;
	return in;
}

class integral_sin :public integral {
public:
	virtual char* value();
	virtual int type();
	friend istream& operator >> (istream& in, integral& inte);
};

int integral_sin::type()
{
	return 1;//1Ϊsin����
}


char* integral_sin::value()
{
	static char temp[100] = { 0 };
	double s = 0;
	double x = a;
	double d = double(b - a) / n;
	for (int i = 1; i <= n; i++)
	{
		x += d;
		s += sin(x) * d;
	}
	sprintf(temp, "sinxdx[%lf~%lf/n=%lf] : %lf\n%lf", a, b, n, s, s);
	return temp;
}

class integral_cos :public integral {
public:
	virtual int type();
	virtual char* value();
};

int integral_cos::type()
{
	return 2;
}

char* integral_cos::value()
{
	static char temp[100] = { 0 };
	double s = 0;
	double x = a;
	double d = double(b - a) / n;
	for (int i = 1; i <= n; i++)
	{
		x += d;
		s += cos(x) * d;
	}
	sprintf(temp, "cosxdx[%lf~%lf/n=%lf] : %lf\n%lf", a, b, n, s, s);
	return temp;
}

class integral_exp :public integral {
public:
	virtual int type();
	virtual char* value();
};

int integral_exp::type()
{
	return 3;
}

char* integral_exp::value()
{
	static char temp[100] = { 0 };
	double s = 0;
	double x = a;
	double d = double(b - a) / n;
	for (int i = 1; i <= n; i++)
	{
		x += d;
		s += exp(x) * d;
	}
	sprintf(temp, "e^xdx[%lf~%lf/n=%lf] : %lf\n%lf", a, b, n, s, s);
	return temp;
}

/* -- �滻����� -- ���в�Ҫ���κθĶ� -- ���в�Ҫɾ�� -- �ڱ��е����治Ҫ�����κ��Լ�����䣬��ҵ�ύ��ӱ��п�ʼ�ᱻ�滻 -- �滻����� -- */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����fun_integral��׼����˼��һ�£�integralӦ��ζ���
***************************************************************************/
void fun_integral(integral& fRef)
{
	cin >> fRef;	//���������ޡ�������
	cout << fRef.value() << endl;
	return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	integral_sin s1;
	integral_cos s2;
	integral_exp s3;

	fun_integral(s1); //����sinxdx��ֵ
	fun_integral(s2); //����cosxdx��ֵ
	fun_integral(s3); //����expxdx��ֵ

	return 0;
}

//ע�����μ���ȡ��ֵ�����Ϊ����double��ʽ

