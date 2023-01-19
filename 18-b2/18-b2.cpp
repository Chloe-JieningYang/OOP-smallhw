/* 2050598 杨洁宁 通信 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

/* 从此处到标记替换行之间，给出各种类的定义及实现
	1、不允许全部变量（不含const和#define）
	2、不允许添加其它系统头文件
*/ 
class integral {
protected:
	double a;
	double b;
	double n;
public:
	virtual int type();
	virtual char* value() = 0;//纯虚函数
	friend istream& operator >> (istream& in, integral& i);
};

int integral::type()
{
	return 0;//0为抽象类标记
}

istream& operator >> (istream& in, integral& i)
{
	if (i.type() == 1)
	{
		cout << "请输入sinxdx的下限、上限及区间划分数量" << endl;
	}
	else if (i.type() == 2)
	{
		cout << "请输入cosxdx的下限、上限及区间划分数量" << endl;
	}
	else if (i.type() == 3)
	{
		cout << "请输入e^xdx的下限、上限及区间划分数量" << endl;
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
	return 1;//1为sin类型
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

/* -- 替换标记行 -- 本行不要做任何改动 -- 本行不要删除 -- 在本行的下面不要加入任何自己的语句，作业提交后从本行开始会被替换 -- 替换标记行 -- */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：fun_integral不准动，思考一下，integral应如何定义
***************************************************************************/
void fun_integral(integral& fRef)
{
	cin >> fRef;	//输入上下限、划分数
	cout << fRef.value() << endl;
	return;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	integral_sin s1;
	integral_cos s2;
	integral_exp s3;

	fun_integral(s1); //计算sinxdx的值
	fun_integral(s2); //计算cosxdx的值
	fun_integral(s3); //计算expxdx的值

	return 0;
}

//注：矩形计算取右值，输出为正常double格式

