/* 2050598 杨洁宁 通信 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include <cmath>
/* 如果有需要，此处可以添加头文件 */
#include <climits>

using namespace std;

/* 允许定义常变量/宏定义，但不允许定义全局变量 */
#define   CLUB    5
#define   DIAMOND 4
#define   HEART   3
#define   SPADE   6

/* 可以添加自己需要的函数 */

/***************************************************************************
  函数名称：
  功    能：给出牌的序号，打印出一张牌(两个字符）
  输入参数：
  返 回 值：
  说    明：
 ***************************************************************************/
void PrintOneCard(const int num)
{
	if (num > 54 || num < 1)
		return;
	if (num == 53)//小王
	{
		cout << "BJ ";
		return;
	}
	else if (num == 54)//大王
	{
		cout << "RJ ";
		return;
	}
	if (num % 4 == 1)
		#if defined(_WIN32)
			cout << char(CLUB);
		#elif defined(__linux__)
			cout << 'C';
		#endif
	else if(num%4==2)
		#if defined(_WIN32)
			cout << char(DIAMOND);
		#elif defined(__linux__)
			cout << 'D';
		#endif
	else if(num%4==3)
		#if defined(_WIN32)
			cout << char(HEART);
		#elif defined(__linux__)
			cout << 'H';
		#endif
	else if(num%4==0)
		#if defined(_WIN32)
			cout << char(SPADE);
		#elif defined(__linux__)
			cout << 'S';
		#endif
	if ((num - 1) / 4 <= 6)
		cout << (num - 1) / 4 + 3;
	else if ((num - 1) / 4 == 7)
		cout << "T";
	else if ((num - 1) / 4 == 8)
		cout << "J";
	else if ((num - 1) / 4 == 9)
		cout << "Q";
	else if ((num - 1) / 4 == 10)
		cout << "K";
	else if ((num - 1) / 4 == 11)
		cout << "A";
	else if ((num - 1) / 4 == 12)
		cout << "2";
	cout << " ";
	return;
}

/***************************************************************************
  函数名称：
  功    能：打印某个玩家的牌面信息，如果是地主，后面加标记
  输入参数：
  返 回 值：
  说    明：
 ***************************************************************************/
int print(const char *prompt, const bool landlord, const unsigned long long player)
{
	/* 只允许定义不超过三个基本类型的简单变量，不能定义数组变量、结构体、string等 */
	int i;
	cout << prompt;
	for (i = 1; i <= 54; i++)
	{
		int s = (int)(player / (unsigned long long)(pow(2, i - 1)) % 2);//0为不存在这张牌，1为存在
		if (s == 1)
			PrintOneCard(i);
	}
	if (landlord)
		cout << "(地主)";
	cout << endl;

	return 0;
}

/***************************************************************************
  函数名称：
  功    能：发牌（含键盘输入地主）
  输入参数：
  返 回 值：
  说    明：
 ***************************************************************************/
int deal(unsigned long long *player)
{
	/* 只允许定义不超过十个基本类型的简单变量，不能定义数组变量、结构体、string等 */
	srand(unsigned(time(NULL)));
	unsigned long long cards = ULLONG_MAX;//准备好一副牌
	int i;
	for (i = 1; i <= 17; i++)//一共发17轮
	{
		for (int person = 0; person <= 2; person++)//给三个人发牌
		{
			int card_num;
			while (1)
			{
				card_num = rand() % (54 - 1 + 1) + 1;//取1-54的数
				if (cards / (unsigned long long)(pow(2, card_num - 1)) % 2 == 1)//如果未发的牌中还有这张牌
					break;
			}
			unsigned long long change = ULLONG_MAX - (unsigned long long)(pow(2, card_num - 1));//只将选中的牌处置0，改变剩下的牌
			cards = cards & change;
			change = (unsigned long long)(pow(2, card_num - 1));//只将选中的牌置1，改变玩家的牌
			*(player + person) = *(player + person) | change;
		}
		cout << "第" << i << "轮结束：" << endl;
		print("甲的牌：", 0, *(player + 0));
		print("乙的牌：", 0, *(player + 1));
		print("丙的牌：", 0, *(player + 2));
	}
	int landlord;
	while (1)
	{
		cout << endl;
		cout << "请选择一个地主[0-2]:" << endl;
		cin >> landlord;
		if (cin.good() && landlord >= 0 && landlord <= 2)
			break;
	}
	*(player + landlord) = *(player + landlord) | cards;

	return landlord; //此处修改为选定的地主(0-2)
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数，不准修改
 ***************************************************************************/
int main()
{
	unsigned long long player[3] = { 0 }; //存放三个玩家的发牌信息
	int landlord; //返回0-2表示哪个玩家是地主

	cout << "按回车键开始发牌";
	while (getchar() != '\n')
		;

	landlord = deal(player);
	print("甲的牌：", (landlord == 0), player[0]);
	print("乙的牌：", (landlord == 1), player[1]);
	print("丙的牌：", (landlord == 2), player[2]);

	return 0;
}
