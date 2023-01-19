/*2050598 杨洁宁 通信*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <climits>

using namespace std;

#define ON        1
#define OFF       2
#define INVALID   3

int Judge(char on_off[])
{
	for (int i = 0; on_off[i] != '\0'; i++)
	{
		if (on_off[i] >= 'a' && on_off[i] <= 'z')//全转大写
			on_off[i] -= 32;
	}
	if (!strcmp(on_off, "ON"))
		return ON;
	else if (!strcmp(on_off, "OFF"))
		return OFF;
	else
		return INVALID;
}

int GetStatus(const char c, const short status)
{
	int s = status / int(pow(2, double(c - 'A')));
	int k = s % 2;
	return k;//k为0表示off，k为1表示on
}

void PrintStatus(const short status)
{
	cout << resetiosflags(ios::right);
	for (char c = 'A'; c <= 'J'; c++)
		cout << setiosflags(ios::left) << setfill(' ') << setw(4) << c;
	cout << endl;
	for (char c = 'A'; c <= 'J'; c++)
	{
		if (GetStatus(c, status) == 0)
			cout << setw(4) << "OFF";
		else
			cout << setw(4) << "ON";
	}
	cout << endl;
}

int main()
{
	short status = 0;
	short change = 0;
	cout << "初始状态：0x" << setfill('0') << setw(4) << hex << status << endl;
	PrintStatus(status);
	while (1)
	{
		cout << "请以(\"A On / J Off\"形式输入，输入\"Q on / off\"退出)" << endl;
		char name;
		char on_off[4] = { '\0' };
		cin >> name >> on_off;
		if (cin.fail())
			continue;
		if ((name >= 'a' && name <= 'j' )|| name == 'q')
			name -= 32;
		int judge = Judge(on_off);
		if (((name >= 'A' && name <= 'J' )|| name == 'Q') && judge != INVALID)
		{
			if (name == 'Q')
				break;
			if (judge == ON)
			{
				change = pow(2, double(name - 'A'));
				status = status | change;
			}
			else if (judge == OFF)
			{
				change = SHRT_MAX - pow(2, double(name - 'A'));
				status = status & change;
			}
		}
		else
			continue;
		cout << resetiosflags(ios::left);
		cout << "当前状态：0x" << setiosflags(ios::right) << setfill('0') << setw(4) << hex << status << endl;
		PrintStatus(status);
	}
	return 0;
}