/* 通信 2050598 杨洁宁 */
#include <iostream>
using namespace std;

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void f_sub(int x)
{
	cout << "x = " << x << endl;
}

void(*(f0(const char* p)))(int x)//f指针数组中第一个函数
{
	cout << "str = " << p << endl;
	return f_sub;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	void(*(*f[3])(const char* p))(int x) = { f0 };
	f[0]("Hello")(2);
	f[0]("Tongji")(7);

	return 0;
}
