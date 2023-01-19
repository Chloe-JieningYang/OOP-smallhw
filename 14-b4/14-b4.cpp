/*2050598 杨洁宁 通信*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

#define     IP_ERROR     1
#define     IP_CORRECT   2
#define     PN_ERROR     3//para name出错
#define     APD_ERROR    4//没有附加参数
#define     NOT_VALID    5//不是以-开头的合法参数
#define     PARA_CORRECT 6//参数正确

#define     PARA_VALUE_END -999//结束标志

typedef struct parameter{
	const char name[3] = { '\0' };
	int append_num;//附加参数个数
	int append_para;//附加参数
	const int min;
	const int max;
}PARAMETER;

/***************************************************************************
  函数名称：
  功    能：判断一个字符串是否为ip
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int JudgeIP(char* ch)
{
	int mark1 = 0;
	int mark2 = 0;
	int mark3 = 0;//标记点的位置
	int i, j, k;
	for (i = 0; ch[i] != '\0'; i++)
	{
		if (ch[i] == '.')
		{
			mark1 = i;
			break;
		}
	}
	for (j = i + 1; ch[j] != '\0'; j++)
	{
		if (ch[j] == '.')
		{
			mark2 = j;
			break;
		}
	}
	for (k = j + 1; ch[k] != '\0'; k++)
	{
		if (ch[k] == '.')
		{
			mark3 = k;
			break;
		}
	}
	if (mark1 == 0 || mark2 == 0 || mark3 == 0 || mark1 + 1 == mark2 || mark2 + 1 == mark3
		|| mark1 > 4 || mark2 - mark1 > 4 || mark3 - mark2 > 4)
	{
		return IP_ERROR;
	}
	char num_ch[4][4] = { '\0' };
	for (i = 0; i < mark1; i++)
	{
		if (ch[i] >= '0' && ch[i] <= '9')
			num_ch[0][i] = ch[i];
		else
		{
			return IP_ERROR;
		}
	}

	j = 0;
	for (i = mark1 + 1; i < mark2; i++)
	{
		if (ch[i] >= '0' && ch[i] <= '9')
		{
			num_ch[1][j] = ch[i];
			j++;
		}
		else
		{
			return IP_ERROR;
		}
	}

	j = 0;
	for (i = mark2 + 1; i < mark3; i++)
	{
		if (ch[i] >= '0' && ch[i] <= '9')
		{
			num_ch[2][j] = ch[i];
			j++;
		}
		else
		{
			return IP_ERROR;
		}
	}

	j = 0;
	for (i = mark3 + 1; ch[i] != '\0'; i++)
	{
		if (ch[i] >= '0' && ch[i] <= '9')
		{
			num_ch[3][j] = ch[i];
			j++;
		}
		else
		{
			return IP_ERROR;
		}
	}

	int num[4];
	for (i = 0; i <= 3; i++)
	{
		num[i] = atoi(num_ch[i]);
		if (num[i] < 0 || num[i] > 255)
		{
			return IP_ERROR;
		}
	}

	return IP_CORRECT;
}

/***************************************************************************
  函数名称：
  功    能：判断参数类型
  输入参数：main的两个参数，参数列表
  返 回 值：
  说    明：c[arg-1]是IP地址
***************************************************************************/
int Judge(const int arg, char* c[], PARAMETER para[])
{
	int i = 1;
	int j;

	while (i < arg - 1)
	{
		if (c[i][0] == '-')//如果字符串以-开头
		{
			bool find = 0;
			for (j = 0; para[j].append_num != PARA_VALUE_END; j++)
			{
				if (!strcmp(c[i], para[j].name))//找是否有对应的参数
				{
					find = 1;
					break;
				}
			}
			if (find == 0)
			{
				cout << "参数" << c[i] << "不存在" << endl;
				return PN_ERROR;
			}
			if ( para[j].append_num == 0)//如果没有附加参数
			{
				para[j].append_para = 1;//出现了附加参数就是1
				i++;
			}
			else
			{
				if (c[i + 1][0] == '-'|| i + 1 == arg - 1)
				{
					cout << "参数" << c[i] << "没有后续参数" << endl;
					return APD_ERROR;
				}
				int n = atoi(c[i + 1]);
				if (n != 0 || (n == 0 && !strcmp(c[i + 1], "0")))//如果转换是有效的
				{
					if (n >= para[j].min && n <= para[j].max)
						para[j].append_para = n;
				}
				i += 1 + para[j].append_num;
			}
		}
		else
		{
			cout << "不是以-开头的合法参数" << endl;
			return NOT_VALID;
		}
	}
	return PARA_CORRECT;
}

//计算整数长度
int CountLength(int n)
{
	int length = 1;
	while (1)
	{
		n /= 10;
		if (n != 0)
			length++;
		else
			break;
	}
	return length;
}

void usage(PARAMETER para[], const char* const procname)
{
	cout << "Usage: " << procname << " [" << para[0].name << " 大小][" << para[1].name << " 数量][" << para[2].name << "] IP地址" << endl;
	cout << setw(7) << " ";
	cout << setw(34) << setfill('=') << "=" << endl;
	cout << setw(8) << setfill(' ') << " ";
	cout << "参数 附加参数 范围        默认值" << endl;
	for (int i = 0; para[i].append_num != PARA_VALUE_END; i++)
	{
		cout << setw(8) << setfill(' ') << " " << para[i].name << "   " << setiosflags(ios::left) << setw(9) << para[i].append_num << "[" << para[i].min << ".." << para[i].max << "]";
		if (4 + CountLength(para[i].min) + CountLength(para[i].max) < 12)
			cout << setfill(' ') << setw(8 - CountLength(para[i].min) - CountLength(para[i].max)) << " ";
		cout << para[i].append_para << endl;
	}
	cout << setfill(' ') << setw(7) << " ";
	cout << setw(34) << setfill('=') << "=" << endl;
}

int main(int argc, char* argv[])
{
	PARAMETER para[] = {
		{"-l",1,64,32,64000},
		{"-n",1,4,1,1024},
		{"-t",0,0,0,1},
		{"",PARA_VALUE_END,PARA_VALUE_END,PARA_VALUE_END,PARA_VALUE_END}//结尾
	};
	if (argc == 1)
	{
		usage(para, argv[0]);
		return 0;
	}
	if (JudgeIP(argv[argc - 1]) == IP_ERROR)
	{
		cout << "IP地址错误" << endl;
		return 0;
	}
	if (argc >= 3)
	{
		if (Judge(argc, argv, para) != PARA_CORRECT)
			return 0;
	}
	for (int i = 0; para[i].append_num != PARA_VALUE_END; i++)
		cout << para[i].name << " 参数：" << para[i].append_para << endl;
	cout << "IP地址：" << argv[argc - 1] << endl;
	return 0;
}