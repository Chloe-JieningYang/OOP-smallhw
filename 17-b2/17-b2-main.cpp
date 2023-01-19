/* 2050598 杨洁宁 通信 */
/*2051553 张天一 2152808 魏予涵 2051454 王逸菲*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "17-b2-datetime.h"
using namespace std;

#if defined(__linux) || defined(__linux__) //Linux
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void wait_for_enter()
{
	cout << endl << "按回车键继续";
	while (getchar() != '\n')
		;
	cout << endl << endl;
}

#else //VS+Dev
#include <Windows.h>
#include <conio.h>
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void wait_for_enter()
{
	cout << endl << "按回车键继续";
	while (_getch() != '\r')
		;
	cout << endl << endl;
}
#endif


int main()
{
	if (1)
	{
		DateTime dt1;
		DateTime dt2(2020, 1, 1, 1, 1, 1);
		cout << "测试初始化，完全正确的赋值" << endl;

		cout << "dt1应该是1900.1.1 00:00:00，    实际为：";
		dt1.show();
		cout << endl;

		cout << "dt2应该是2020.1.1 01:01:01，    实际为：";
		dt2.show();
		cout << endl;

		wait_for_enter();
	}

	if (1)
	{
		DateTime dt1(1830, 3, 3, 12, 12, 12); //1900.1.1 00:00:00
		DateTime dt2(2110, 4, 4, 12, 30, 59); //1900.1.1 00:00:00
		DateTime dt3(2007, 15, 1, 1, 5, 40);//1900.1.1 00:00:00
		DateTime dt4(2004, 1, 32, 4, 30, 20);//1900.1.1 00:00:00

		cout << "测试初始化，Date为非法赋值" << endl;

		cout << "dt1应该是1900.1.1 00:00:00，  实际为：";
		dt1.show();
		cout << endl;

		cout << "dt2应该是1900.1.1 00:00:00，  实际为：";
		dt2.show();
		cout << endl;

		cout << "dt3应该是1900.1.1 00:00:00，  实际为：";
		dt3.show();
		cout << endl;

		cout << "dt4应该是1900.1.1 00:00:00，  实际为：";
		dt4.show();
		cout << endl << endl;

		DateTime dt5(2001, 3, 3, 24, 12, 12); //1900.1.1 00:00:00
		DateTime dt6(2030, 4, 4, 13, -1, 59); //1900.1.1 00:00:00
		DateTime dt7(2007, 11, 1, 1, 5, 100);//1900.1.1 00:00:00
		DateTime dt8(2004, 1, 31, 4, 30, -20);//1900.1.1 00:00:00

		cout << "Time为非法赋值" << endl;

		cout << "dt5应该是1900.1.1 00:00:00，   实际为：";
		dt5.show();
		cout << endl;

		cout << "dt6应该是1900.1.1 00:00:00，   实际为：";
		dt6.show();
		cout << endl;

		cout << "dt7应该是1900.1.1 00:00:00，   实际为：";
		dt7.show();
		cout << endl;

		cout << "dt8应该是1900.1.1 00:00:00，   实际为：";
		dt8.show();
		cout << endl << endl;

		DateTime dt9(1830, 3, 3, 12, -5, 12); //1900.1.1 00:00:00
		DateTime dt10(2110, 4, 4, 12, 60, 5); //1900.1.1 00:00:00
		DateTime dt11(2007, 15, 1, -1, 30, 30);//1900.1.1 00:00:00
		DateTime dt12(2004, 1, 32, 4, 30, 60);//1900.1.1 00:00:00

		cout << "Date Time均为非法的赋值" << endl;

		cout << "dt9应该是1900.1.1 00:00:00，   实际为：";
		dt9.show();
		cout << endl;

		cout << "dt10应该是1900.1.1 00:00:00，  实际为：";
		dt10.show();
		cout << endl;

		cout << "dt11应该是1900.1.1 00:00:00，  实际为：";
		dt11.show();
		cout << endl;

		cout << "dt12应该是1900.1.1 00:00:00，  实际为：";
		dt12.show();
		cout << endl;

		wait_for_enter();
	}

	if (1)
	{
		DateTime dt1(2022, 2, 29, 23, 59, 59); //1900.1.1 23:59:59
		DateTime dt2(2020, 2, 29, 0, 0, 0); //2020.2.29 00:00:00

		cout << "测试初始化，闰年" << endl;

		cout << "dt1应该是1900.1.1 00:00:00， 实际为：";
		dt1.show();
		cout << endl;

		cout << "dt2应该是2020.2.29 00:00:00，实际为：";
		dt2.show();
		cout << endl;

		wait_for_enter();
	}

	if (1)
	{
		DateTime dt1, dt2, dt3, dt4, dt5, dt6;

		cout << "测试set，带缺省值" << endl;
		dt1.set(2000, 3, 4, 14, 6, 8); 
		dt2.set(2000, 3, 4, 14, 5);
		dt3.set(2004, 2, 14, 3);
		dt4.set(1978, 4, 25);
		dt5.set(1955, 5);
		dt6.set(2064);

		cout << "dt1应该是2000.3.4 14:06:08， 实际为：";
		dt1.show();
		cout << endl;

		cout << "dt2应该是2000.3.4 14:05:00， 实际为：";
		dt2.show();
		cout << endl;

		cout << "dt3应该是2004.2.14 03:00:00，实际为：";
		dt3.show();
		cout << endl;

		cout << "dt4应该是1978.4.25 00:00:00，实际为：";
		dt4.show();
		cout << endl;

		cout << "dt5应该是1955.5.1 00:00:00， 实际为：";
		dt5.show();
		cout << endl;

		cout << "dt6应该是2064.1.1 00:00:00， 实际为：";
		dt6.show();
		cout << endl;

		wait_for_enter();
	}

	if (1)
	{
		DateTime dt1, dt2, dt3, dt4, dt5, dt6;

		cout << "测试set，非法" << endl;

		dt1.set(1877, 2, 2, 1, 1, 1);
		dt2.set(1990, 14, 3, 1, 1, 1);
		dt3.set(1990, 4, 32, 1, 1, 1);
		dt4.set(1999, 5, 5, 25, 1, 1);
		dt5.set(1999, 5, 5, 5, 65, 1);
		dt6.set(1999, 5, 5, 7, 34, 69);

		cout << "dt1应该是1900.1.1 00:00:00， 实际为：";
		dt1.show();
		cout << endl;

		cout << "dt2应该是1900.1.1 00:00:00， 实际为：";
		dt2.show();
		cout << endl;

		cout << "dt3应该是1900.1.1 00:00:00， 实际为：";
		dt3.show();
		cout << endl;

		cout << "dt4应该是1900.1.1 00:00:00， 实际为：";
		dt4.show();
		cout << endl;

		cout << "dt5应该是1900.1.1 00:00:00， 实际为：";
		dt5.show();
		cout << endl;

		cout << "dt6应该是1900.1.1 00:00:00， 实际为：";
		dt6.show();
		cout << endl;

		wait_for_enter();
	}

	if (1)
	{
		DateTime dt1, dt2, dt3, dt4;
		cout << "测试set，错误+缺省" << endl;

		dt1.set(1877, 3, 5);
		dt2.set(1990, 14);
		dt3.set(1990, 4, 55, 1);
		dt4.set(1990, 4, 6, 34);

		cout << "dt1应该是1900.1.1 00:00:00， 实际为：";
		dt1.show();
		cout << endl;

		cout << "dt2应该是1900.1.1 00:00:00， 实际为：";
		dt2.show();
		cout << endl;

		cout << "dt3应该是1900.1.1 00:00:00， 实际为：";
		dt3.show();
		cout << endl;

		cout << "dt4应该是1900.1.1 00:00:00， 实际为：";
		dt4.show();
		cout << endl;

		wait_for_enter();
	}

	if (1)
	{
		DateTime dt1(2022, 12, 2, 18, 52, 34);
		int y, m, d, h, min, s;
		dt1.get(y, m, d, h, min, s);
		cout << "应该y=2022,m=12,d=2,h=18,min=52,s=34，实际为：";
		cout << "y=" << y << " m=" << m << " d=" << d << " h=" << h << " min=" << min << " s=" << s << endl;

		wait_for_enter();
	}

	if (1)
	{
		DateTime dt1(2022, 12, 2, 18, 52, 34);
		DateTime dt2;

		cout << "测试cout" << endl;
		cout << "dt1应该是2022.12.2 18:52:34， 实际为：" << dt1 << endl;
		cout << "dt2应该是1900.1.1 00:00:00，  实际为：" << dt2 << endl;

		wait_for_enter();
	}
	
	if (1)
	{
		DateTime dt1;

		cout << "测试cin/cout" << endl;

		cout << "请输入2022 12 3 19 01 40" << endl;
		cin >> dt1;
		cout << "dt1应该是2022.12.3 19:01:40，实际为：" << dt1 << endl;

		cout << "请输入2020 2 29 19 01 40" << endl;
		cin >> dt1;
		cout << "dt1应该是2020.2.29 19:01:40，实际为：" << dt1 << endl;

		cout << "请输入2022 2 29 19 01 40" << endl;
		cin >> dt1;
		cout << "dt1应该是1900.1.1 00:00:00，实际为：" << dt1 << endl;

		cout << "请输入1899 2 2 19 01 40" << endl;
		cin >> dt1;
		cout << "dt1应该是1900.1.1 00:00:00，实际为：" << dt1 << endl;

		cout << "请输入2000 11 31 19 01 40" << endl;
		cin >> dt1;
		cout << "dt1应该是1900.1.1 00:00:00，实际为：" << dt1 << endl;

		cout << "请输入2000 1 1 25 01 40" << endl;
		cin >> dt1;
		cout << "dt1应该是1900.1.1 00:00:00，实际为：" << dt1 << endl;

		cout << "请输入2000 1 1 4 60 40" << endl;
		cin >> dt1;
		cout << "dt1应该是1900.1.1 00:00:00，实际为：" << dt1 << endl;

		cout << "请输入2000 1 1 2 5 60" << endl;
		cin >> dt1;
		cout << "dt1应该是1900.1.1 00:00:00，实际为：" << dt1 << endl;

		cout << "请输入2112 1 32 2 5 60" << endl;
		cin >> dt1;
		cout << "dt1应该是1900.1.1 00:00:00，实际为：" << dt1 << endl;

		wait_for_enter();
	}
	
	if (1)
	{
		DateTime dt1(1);
		DateTime dt2(4678);//1900.1.1 01:17:58
		DateTime dt3(123456700);//1903.11.30 21:31:40
		DateTime dt4(-1);//2099.12.31 23:59:59
		DateTime dt5((long long)73049 * 24 * 60 * 60);//1900.1.1 00:00:00
		DateTime dt6((long long)73049 * 24 * 60 * 60 + 4678);//1900.1.1 01:17:58


		cout << "转换构造函数测试，包括合法及非法值" << endl;

		cout << "dt1应该是1900.1.1 00:00:01，     实际为：" << dt1 << endl;

		cout << "dt2应该是1900.1.1 01:17:58，     实际为：" << dt2 << endl;

		cout << "dt3应该是1903.11.30 21:31:40，   实际为：" << dt3 << endl;

		cout << "dt4应该是2099.12.31 23:59:59，   实际为：" << dt4 << endl;

		cout << "dt5应该是1900.1.1 00:00:00，     实际为：" << dt5 << endl;

		cout << "dt6应该是1900.1.1 01:17:58，     实际为：" << dt6 << endl;

		wait_for_enter();
		
	}

	if (1)
	{
		DateTime dt1(1900, 1, 1, 1, 17, 58);
		DateTime dt2(1903, 11, 30, 21, 31, 40);
		DateTime dt3(2099, 12, 31, 23, 59, 59);
		cout << "类型转换函数测试" << endl;

		cout << "dt1应该是4678，      实际为：" << (long long)dt1 << endl;
		cout << "dt2应该是123456700， 实际为：" << (long long)dt2 << endl;

		cout << "dt3应该是6311433599，实际为：" << (long long)dt3 << endl;

		wait_for_enter();

	}

	if (1)
	{
		DateTime dt1(2022, 12, 3, 21, 02, 23);
		DateTime dt2;
		cout << "测试+/- n" << endl;

		dt2 = dt1 + (long long)746;
		cout << "dt2应该是2022.12.3 21:14:49，   实际为：" << dt2 << endl;

		dt2 = (long long)746 + dt1;
		cout << "dt2应该是2022.12.3 21:14:49，   实际为：" << dt2 << endl;

		dt2 = dt1 + (long long)7654321;
		cout << "dt2应该是2023.3.2 11:14:24，    实际为：" << dt2 << endl;

		dt2 = dt1 - (long long)30;
		cout << "dt2应该是2022.12.3 21:01:53，   实际为：" << dt2 << endl;

		dt1.set(1900, 1, 1, 0, 0, 0);
		dt2 = dt1 - (long long)30;
		cout << "dt2应该是2099.12.31 23:59:30，  实际为：" << dt2 << endl;

		dt1.set(2099, 12, 31, 23, 59, 40);
		dt2 = dt1 + (long long)30;
		cout << "dt2应该是1900.1.1 00:00:10，    实际为：" << dt2 << endl;

		dt1.set(2022, 12, 3, 21, 40, 30);
		dt2.set(2022, 12, 3, 21, 39, 30);
		cout << "dt2-dt1应该是-60，              实际为：" << dt2 - dt1 << endl;

		cout << "dt1-dt2应该是60，               实际为：" << dt1 - dt2 << endl;

		dt2.set(1990, 4, 3, 22, 1, 34);
		cout << "dt1-dt2应该是1030923536，       实际为：" << dt1 - dt2 << endl;

		cout << "dt2-dt1应该是-1030923536，      实际为：" << dt2 - dt1 << endl;

		wait_for_enter();
	}

	if (1)
	{
		DateTime dt1, dt2;
		cout << "-datetime" << endl;

		dt1.set(2022, 12, 1, 22, 44, 2);
		dt2.set(2000, 3, 4, 2, 45, 3);
		cout << "dt2-dt1应该是-717796739，实际为：" << dt2 - dt1 << endl;

		dt1.set(1965, 12, 1, 22, 44, 2);
		dt2.set(2045, 3, 4, 2, 45, 3);
		cout << "dt2-dt1应该是2501035261，实际为：" << dt2 - dt1 << endl;

		wait_for_enter();
	}

	if (1)
	{
		DateTime dt1, dt2;
		cout << "测试++/--" << endl;

		dt1.set(2022, 11, 10, 12, 23, 34);
		dt2 = dt1++;
		cout << "dt1应该是2022.11.10 12:23:35，  实际为：" << dt1 << endl;
		cout << "dt2应该是2022.11.10 12:23:34，  实际为：" << dt2 << endl;

		dt1.set(2022, 11, 10, 12, 23, 59);
		dt2 = ++dt1;
		cout << "dt1应该是2022.11.10 12:24:00，  实际为：" << dt1 << endl;
		cout << "dt2应该是2022.11.10 12:24:00，  实际为：" << dt2 << endl;

		dt1.set(2022, 11, 10, 12, 23, 34);
		dt2 = dt1--;
		cout << "dt1应该是2022.11.10 12:23:33，  实际为：" << dt1 << endl;
		cout << "dt2应该是2022.11.10 12:23:34，  实际为：" << dt2 << endl;

		dt1.set(2022, 11, 10, 12, 23, 34);
		dt2 = --dt1;
		cout << "dt1应该是2022.11.10 12:23:33，  实际为：" << dt1 << endl;
		cout << "dt2应该是2022.11.10 12:23:33，  实际为：" << dt2 << endl;

		dt1.set(2020, 2, 29, 23, 59, 59);
		dt2 = ++dt1;
		cout << "dt1应该是2020.3.1 00:00:00，    实际为：" << dt1 << endl;
		cout << "dt2应该是2020.3.1 00:00:00，    实际为：" << dt2 << endl;

		dt1.set(1900, 1, 1, 0, 0, 0);
		dt2 = dt1--;
		cout << "dt1应该是2099.12.31 23:59:59，  实际为：" << dt1 << endl;
		cout << "dt2应该是1900.1.1 00:00:00，    实际为：" << dt2 << endl;

		dt1.set(2099, 12, 31, 23, 59, 59);
		dt2 = dt1++;
		cout << "dt1应该是1900.1.1 00:00:00，    实际为：" << dt1 << endl;
		cout << "dt2应该是2099.12.31 23:59:59，  实际为：" << dt2 << endl;

		wait_for_enter();
	}

	if (1)
	{
		/* 测试比较运算符 */
		DateTime dt1(2022, 2, 4, 5, 34, 6);
		DateTime dt2(2022, 2, 4, 5, 34, 6);
		DateTime dt3(2022, 2, 4, 5, 2, 55);

		cout << "测试比较运算符" << endl;

		cout << "比较结果应为0，实际为：" << (dt1 > dt2) << endl;
		cout << "比较结果应为1，实际为：" << (dt1 >= dt2) << endl;
		cout << "比较结果应为0，实际为：" << (dt1 < dt2) << endl;
		cout << "比较结果应为1，实际为：" << (dt1 <= dt2) << endl;
		cout << "比较结果应为1，实际为：" << (dt1 == dt2) << endl;
		cout << "比较结果应为0，实际为：" << (dt1 != dt2) << endl;

		cout << "比较结果应为1，实际为：" << (dt1 > dt3) << endl;
		cout << "比较结果应为1，实际为：" << (dt1 >= dt3) << endl;
		cout << "比较结果应为0，实际为：" << (dt1 < dt3) << endl;
		cout << "比较结果应为0，实际为：" << (dt1 <= dt3) << endl;
		cout << "比较结果应为0，实际为：" << (dt1 == dt3) << endl;
		cout << "比较结果应为1，实际为：" << (dt1 != dt3) << endl;

		wait_for_enter();
	}

	return 0;
}