/* 2050598 杨洁宁 通信 */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double definite_integration(double(*p)(double), double a, double b,int n) 
{
	double s = 0;
	double x = a;
	double d = double(b - a) / n;
	for (int i = 1; i <= n; i++)
	{
		x += d;
		s += (*p)(x) * d;
	}
	return s;
}

int main()
{
	int n;
	double low, high, value;
	cout << "请输入sinxdx的下限、上限及区间划分数量" << endl;
	cin >> low >> high >> n;
	value = definite_integration(sin, low, high, n);
	cout << "sinxdx[" << low << "~" << high << "/n=" << n << "] : " << value << endl;
	cout << "请输入cosxdx的下限、上限及区间划分数量" << endl;
	cin >> low >> high >> n;
	value = definite_integration(cos, low, high, n);
	cout << "cosxdx[" << low << "~" << high << "/n=" << n << "] : " << value << endl;
	cout << "请输入e^xdx的下限、上限及区间划分数量" << endl;
	cin >> low >> high >> n;
	value = definite_integration(exp, low, high, n);
	cout << "e^xdx[" << low << "~" << high << "/n=" << n << "] : " << value << endl;
	return 0;
}